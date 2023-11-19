#include "ComponentSpline.h"

bool bez;
std::vector<std::array<double, 3>> curvePoints; // To store points on the Bézier curve

// Calculate a point on the cubic Bézier curve
std::array<double, 3> calculateBezierPoint(double t, const std::vector<std::array<double, 3>>& points) {
    double mt = 1 - t;
    std::array<double, 3> result = {
        mt * mt * mt * points[0][0] + 3 * t * mt * mt * points[1][0] + 3 * t * t * mt * points[2][0] + t * t * t * points[3][0],
        mt * mt * mt * points[0][1] + 3 * t * mt * mt * points[1][1] + 3 * t * t * mt * points[2][1] + t * t * t * points[3][1],
        mt * mt * mt * points[0][2] + 3 * t * mt * mt * points[1][2] + 3 * t * t * mt * points[2][2] + t * t * t * points[3][2]
    };
    return result;
}

void ComponentSpline::Init(rapidjson::Value& serializedData) {
    auto gameObject = GetGameObject().lock();
    if (!gameObject)
        return;
    auto pos = gameObject->GetPosition();

    _speed = serializedData["speed"].GetFloat();
    _bezier = serializedData["bezier"].GetBool();
    bez = _bezier;

    if (_bezier) {
        std::vector<std::array<double, 3>> controlPoints;
        for (int i = 0; i < serializedData["points"].Size(); ++i) {
            auto p = MyEngine::GameObject::DeserializeVector(serializedData["points"][i]);
            controlPoints.emplace_back(std::array<double, 3>{p.x + pos.x, p.y + pos.y, p.z + pos.z});
        }

        // Calculate points on the Bézier curve and store them
        for (int i = 0; i <= 100; ++i) {
            double t = static_cast<double>(i) / 100.0;
            std::array<double, 3> point = calculateBezierPoint(t, controlPoints);
            curvePoints.push_back(point);
        }
    }
    else {
        for (int i = 0; i < serializedData["points"].Size(); ++i)
            _points.emplace_back(MyEngine::GameObject::DeserializeVector(serializedData["points"][i]) + pos);

        for (int i = 0; i < _points.size() - 1; ++i)
            _pairs.emplace_back(std::vector<glm::vec3> { _points[i], _points[i + 1]});
    }
}

void ComponentSpline::Update(float delta) {
    auto gameObject = GetGameObject().lock();
    if (!gameObject)
        return;
    _t += delta * _speed * 10 ;

    if (bez) {
        int segment = static_cast<int>(fmod(_t, curvePoints.size() - 1));
        float t = fmod(_t, 1.0f);

        // Update object position using Bézier curve points
        gameObject->SetPosition(glm::vec3(curvePoints[segment][0], curvePoints[segment][1], curvePoints[segment][2]));
    }
    else {
        int segment = static_cast<int>(fmod(_t, _points.size() - 1));
        float t = fmod(_t, 1.0f);

        gameObject->SetPosition(glm::mix(_points[segment], _points[segment + 1], t));
    }
}

void ComponentSpline::Render(sre::RenderPass& renderPass) {
        for (auto& pair : _pairs)
            renderPass.drawLines(pair);
   
}
