#include "LazerController.h"
#include "Engine/MyEngine.h"
#include "sre/SDLRenderer.hpp"


namespace ExampleGame {

    void LazerController::Update(float deltaTime) {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

        parent->position = parent->position + movDirection * movAmount * deltaTime;
    }

    void LazerController::Init(glm::vec2 shipPos, glm::vec2 shipDirection) {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();

        basePos = shipPos + shipDirection * movAmount;

        MyEngine::GameObject* parent = GetGameObject();
        //printf(*parent->getName);
        parent->position = basePos;


    }

    void LazerController::ShootLazer() {
        
    }


}