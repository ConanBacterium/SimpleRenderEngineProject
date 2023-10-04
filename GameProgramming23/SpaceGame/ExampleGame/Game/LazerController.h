#pragma once

#include "PlayerController.h"

#include "Engine/Component.h"

namespace ExampleGame {

    class LazerController : public ComponentController {
    protected:
        float movSpeed = 5;
        float movAmount = 5;
        glm::vec2 movDirection = glm::vec2(1, 0);

    public:

        virtual void Update(float deltaTime) override;
        virtual void KeyEvent(SDL_Event& e) override;
        virtual void InitLazer();


        // ... Any other member functions or data members specific to PlayerController ...
    };

}