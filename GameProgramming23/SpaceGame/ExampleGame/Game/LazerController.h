#pragma once

#include "PlayerController.h"

#include "Engine/Component.h"

namespace ExampleGame {

    class LazerController : public ComponentController {
    protected:
        float movSpeed = 5;
        float movAmount = 10;
        glm::vec2 movDirection = glm::vec2(1, 0);
        glm::vec2 basePos;
    public:
        virtual void Update(float deltaTime) override;
        virtual void InitLazer(glm::vec2 shipPos, glm::vec2 shipDirection);
        virtual void ShootLazer();
        // ... Any other member functions or data members specific to PlayerController ...
    };

}