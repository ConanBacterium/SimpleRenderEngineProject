#pragma once

#include "ComponentController.h"

namespace ExampleGame {

    class MeteoriteController : public ComponentController {
    public:
        virtual void Update(float deltaTime) override;
    };

}  // namespace ExampleGame