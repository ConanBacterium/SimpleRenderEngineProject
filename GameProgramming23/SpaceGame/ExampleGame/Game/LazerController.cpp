#include "LazerController.h"
#include "Engine/MyEngine.h"
#include "sre/SDLRenderer.hpp"


namespace ExampleGame {

    void LazerController::Update(float deltaTime) {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

        parent->position = parent->position + movDirection * movAmount * deltaTime;
    }

    void LazerController::InitLazer() {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

     

        parent->position = basePos;
    }


}