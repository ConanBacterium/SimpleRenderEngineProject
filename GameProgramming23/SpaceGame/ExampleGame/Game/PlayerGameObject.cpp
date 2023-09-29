#include "PlayerGameObject.h"
#include "GameObject.h"
#include "Engine/MyEngine.h"

namespace ExampleGame {

	void PlayerGameObject::Update(float deltaTime) {
		// CHECK IF _collisions !!! CUZ IF THERE ARE THEN GAMEOVER!
		MyEngine::GameObject::Update(deltaTime); // callign parent
	}
}