#include "LazerController.h"
#include "Engine/MyEngine.h"
#include "sre/SDLRenderer.hpp"
#include "PlayerController.h"



namespace ExampleGame {

    void LazerController::KeyEvent(SDL_Event& event) {
        // Implement your key event logic specific to PlayerController here

        // If you want to call the parent's KeyEvent function:
        // ComponentController::KeyEvent(e);


        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_SPACE:
                // spawn the laser
                printf("Spawned laser");
                InitLazer();
                break;
            default:
                break;
            }
        }
    }

    void LazerController::Update(float deltaTime) {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

    }

    void LazerController::InitLazer() {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

        auto basePos = PlayerController::GetPosition();


        //get parent position
        printf("Init Lazer\n");
        printf((std::to_string(basePos.x)).c_str());
    }
}