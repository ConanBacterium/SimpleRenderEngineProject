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
        // NEED CONSTRAINT ONLY GO DOWN 
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

        ComponentController::rotSpeed = static_cast<float>(rand()) / RAND_MAX * 360.0f;
        ComponentController::movSpeed = 1.0f + static_cast<float>(rand()) / RAND_MAX * 9.0f;
        ComponentController::movAmount = 1.0f + static_cast<float>(rand()) / RAND_MAX * 99.0f;

        float dirX = 2.0f * (static_cast<float>(rand()) / RAND_MAX) - 1.0f;
        float dirY = -static_cast<float>(rand()) / RAND_MAX;
        ComponentController::movDirection = glm::normalize(glm::vec2(dirX, dirY));

        float posX = static_cast<float>(rand()) / RAND_MAX * 1000.0f;
        float posY = static_cast<float>(rand()) / RAND_MAX * 1000.0f;
        ComponentController::basePos = glm::vec2(posX,  engine->GetScreenSize().y);

        parent->position = basePos;
    }


}