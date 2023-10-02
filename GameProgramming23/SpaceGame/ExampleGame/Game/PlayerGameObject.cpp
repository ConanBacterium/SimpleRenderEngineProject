#include "PlayerGameObject.h"
#include "GameObject.h"
#include "Engine/MyEngine.h"

namespace ExampleGame {

	void PlayerGameObject::Update(float deltaTime) {
		//printf("PlayerGameObject update");
		// CHECK IF _collisions !!! CUZ IF THERE ARE THEN GAMEOVER!
		if (_collisions.size() > 0) {
			printf("playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  playergameobject reset \n  !!");
			_self.reset();
		}
		MyEngine::GameObject::Update(deltaTime); // callign parent
	}
}