#include "PlayerController.h"
#include "sre/SDLRenderer.hpp"
#include "Engine/MyEngine.h"




namespace ExampleGame {

    void PlayerController::KeyEvent(SDL_Event& event) {
        // Implement your key event logic specific to PlayerController here

        // If you want to call the parent's KeyEvent function:
        // ComponentController::KeyEvent(e);


        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_a:
                printf("keypress a\n");
                ComponentController::SetRotSpeed(100);
                break;
            case SDLK_w:
                printf("keypress w\n");
                ComponentController::SetSpeed(100);
                break;
            case SDLK_s:
                printf("keypress s\n");
                break;
            case SDLK_d:
                printf("keypress d\n");
                ComponentController::SetRotSpeed(-100);
                break;
            default:
                break;
            }
        }
        else if (event.type == SDL_KEYUP) {
            ComponentController::SetRotSpeed(0);
            ComponentController::SetSpeed(0);

        }
    }


    void PlayerController::Update(float deltaTime) {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();


        float rotationRadians = glm::radians(parent->rotation + 90);

        // Convert rotation into a glm vector (unit vector)
        MovDirection.x = glm::cos(rotationRadians);
        MovDirection.y = glm::sin(rotationRadians);


        parent->rotation += RotSpeed * deltaTime;
        parent->position = parent->position + MovDirection * MovSpeed * deltaTime;


    }

}  // namespace ExampleGame