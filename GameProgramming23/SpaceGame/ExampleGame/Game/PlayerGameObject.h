#pragma once

#include "GameObject.h"
#include "Engine/Component.h"

namespace ExampleGame {

    class GameObject;

    class PlayerGameObject : public MyEngine::GameObject {
    public:
        void Update(float deltaTime) override;
    };

}  // namespace ExampleGame
