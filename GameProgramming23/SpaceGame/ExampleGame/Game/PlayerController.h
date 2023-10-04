#pragma once

#include "ComponentController.h"
#include "Engine/Component.h"

namespace ExampleGame {

    class PlayerController : public ComponentController {
    public:

        glm::vec2 basePos = glm::vec2(200, 100);
        float x, y;

        virtual void KeyEvent(SDL_Event& e) override;
        virtual void Update(float deltaTime) override;

        virtual glm::vec2 GetPosition(float x, float y);


    };

}  // namespace ExampleGame
