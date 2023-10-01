#pragma once

#include "ComponentController.h"
#include "Engine/Component.h"

namespace ExampleGame {

    class PlayerController : public ComponentController {
    public:
        virtual void KeyEvent(SDL_Event& e) override;
        virtual void Update(float deltaTime) override;
        // ... Any other member functions or data members specific to PlayerController ...
    };
}  // namespace ExampleGame