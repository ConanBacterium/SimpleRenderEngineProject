#include "PlayerController.h"
#include "Engine/MyEngine.h"
#include "sre/SDLRenderer.hpp"

namespace ExampleGame {

    void PlayerController::KeyEvent(SDL_Event& event) {
        // Implement your key event logic specific to PlayerController here

        // If you want to call the parent's KeyEvent function:
        // ComponentController::KeyEvent(e);


        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    ComponentController::SetRotSpeed(100.0);
                    break;
                case SDLK_w: 
                    //ComponentController::SetMovAmount();
                    ComponentController::SetMovAmount(100);
                    break;
                case SDLK_s:
                    printf("keypress s\n");
                    break;
                case SDLK_d:
                    printf("keypress d\n");
                    ComponentController::SetRotSpeed(-100.0);
                    break;
                default:
                    break;
            }
        }
        if (event.type == SDL_KEYUP) {
            ComponentController:SetRotSpeed(0.0);
            ComponentController::SetMovAmount(0);
            
        }
    }

    void PlayerController::Update(float deltaTime) {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

        // rotation is in degrees, need to make it into a glm vector and set movDirection to it 
        // Convert rotation to radians
        float rotationRadians = glm::radians(parent->rotation + 90);

        // Convert rotation into a glm vector (unit vector)
        movDirection.x = glm::cos(rotationRadians);
        movDirection.y = glm::sin(rotationRadians);


        parent->rotation += rotSpeed * deltaTime;
        parent->position = parent->position + movDirection * movAmount*deltaTime;
    }

}  // namespace ExampleGame
