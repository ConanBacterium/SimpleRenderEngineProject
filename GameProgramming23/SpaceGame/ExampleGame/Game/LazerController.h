#pragma once

#include "PlayerController.h"

#include "Engine/Component.h"

namespace ExampleGame {

    class LazerController : public PlayerController {
    protected:
        float movSpeed = 5;
        float movAmount = 5;
        glm::vec2 movDirection = glm::vec2(1, 0);
        glm::vec2 basePos;
    public:
        virtual void Update(float deltaTime) override;
        virtual void InitLazer();
        // ... Any other member functions or data members specific to PlayerController ...
    };

}