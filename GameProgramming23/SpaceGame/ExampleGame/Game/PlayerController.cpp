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
                    ComponentController::SetMovAmount(100);
                    break;
                case SDLK_d:
                    ComponentController::SetRotSpeed(-100.0);
                    break;
                default:
                    break;
            }
        }
        if (event.type == SDL_KEYUP) {

            switch (event.key.keysym.sym) {
            case SDLK_a:
                ComponentController:SetRotSpeed(0.0);
                break;
            case SDLK_w:
                //ComponentController::SetMovAmount();
                for (float i = 100.0; i > 0.0; i= i - 0.5) { //kinda smoother stop
                    ComponentController::SetMovAmount(i);
                }
                break;
            case SDLK_s:
                break;
            case SDLK_d:
                ComponentController::SetRotSpeed(0.0);
                break;
            default:
                break;
            }
            
        }
    }

    glm::vec2 PlayerController::GetPosition(float set_x, float set_y) {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

        x = set_x;
        y = set_y;

        return glm::vec2(x, y);
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
        basePos = parent->position;
        PlayerController::GetPosition(parent->position.x, parent->position.y);
    }


    /* 
    glm::vec2 PlayerController::GetPosition() {

        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();
        printf("Getting Position X: ");
        printf(std::to_string(x).c_str());

        printf("Getting Position Y: ");
        printf(std::to_string(y).c_str());

        auto pos = glm::vec2(x, y);

        return pos;
    }
    */

}  // namespace ExampleGame
