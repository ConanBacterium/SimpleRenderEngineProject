#pragma once

#include "ComponentController.h"
#include "Engine/Component.h"

namespace ExampleGame {

    class MeteoriteController : public ComponentController {
    public:
        virtual void Update(float deltaTime) override;
        virtual void InitMeteor();
        // ... Any other member functions or data members specific to PlayerController ...
    };

}  // namespace ExampleGame
