#include "ComponentController.h"

#include "Engine/MyEngine.h"

namespace ExampleGame {
	void ComponentController::Init() {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		basePos = engine->GetScreenSize() / 2.f;

		MyEngine::GameObject* parent = GetGameObject();
		parent->position = basePos;
	}

	void ComponentController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		parent->rotation += rotSpeed * deltaTime;


		/*
		// rotation is in degrees, need to make it into a glm vector and set movDirection to it 
		// Convert rotation to radians
		float rotationRadians = glm::radians(parent->rotation);

		// Convert rotation into a glm vector (unit vector)
		movDirection.x = glm::cos(rotationRadians);
		movDirection.y = glm::sin(rotationRadians);
		*/

		parent->position = parent->position + movDirection * movAmount;
		//parent->position = basePos + movDirection * movAmount * glm::sin(movSpeed * engine->GetTime());
	}
}