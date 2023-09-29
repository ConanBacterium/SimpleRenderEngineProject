#include "PlayerController.h"
#include "sre/SDLRenderer.hpp"

namespace ExampleGame {

    void PlayerController::KeyEvent(SDL_Event& event) {
        // Implement your key event logic specific to PlayerController here

        // If you want to call the parent's KeyEvent function:
        // ComponentController::KeyEvent(e);


        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    printf("keypress a\n");
                    break;
                case SDLK_w: 
                    printf("keypress w\n");
                    break;
                case SDLK_s:
                    printf("keypress s\n");
                    break;
                case SDLK_d:
                    printf("keypress d\n");
                    break;
                default:
                    break;
            }
        }
    }

}  // namespace ExampleGame
