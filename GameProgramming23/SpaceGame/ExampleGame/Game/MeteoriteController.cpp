#include "MeteoriteController.h"
#include "Engine/MyEngine.h"
#include "sre/SDLRenderer.hpp"

namespace ExampleGame {

    void MeteoriteController::Update(float deltaTime) {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

       
        parent->rotation += rotSpeed * deltaTime;
        parent->position = parent->position + movDirection * movAmount * deltaTime;
    }

    void MeteoriteController::InitMeteor() {
        printf("InitMeteor");

        // NEED CONSTRAINT ONLY GO DOWN 
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

        const float HEIGHT = engine->GetScreenSize().y;
        const float WIDTH = engine->GetScreenSize().x;


        ComponentController::rotSpeed = static_cast<float>(rand()) / RAND_MAX * 360.0f;
        ComponentController::movSpeed = 1.0f + static_cast<float>(rand()) / RAND_MAX * 9.0f;
        ComponentController::movAmount = 1.0f + static_cast<float>(rand()) / RAND_MAX * 99.0f;

        //get me highest y point and generate random x number within the screen range
        float randomX_start = static_cast<float>(rand()) / RAND_MAX * WIDTH;
        glm::vec2 startPos = glm::vec2(randomX_start, HEIGHT);

        printf("Start pos: x: %f,y: %f \n", randomX_start, HEIGHT);

        //get me the lowest point and get me a random x number within the screen range
        float randomX_endPos = static_cast<float>(rand()) / RAND_MAX * WIDTH;
        glm::vec2  endPos = glm::vec2(randomX_endPos, 0.0f);
        //connect these 2 generated points for a movind direction of an object

        printf("End pos: x: %f,y: %f ", randomX_endPos, 0.0);


        ComponentController::movDirection = glm::normalize(endPos - startPos);


        ComponentController::basePos = startPos;

        parent->position = basePos;


    }


}  // namespace ExampleGame
