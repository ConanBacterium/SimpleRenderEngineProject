#include "ComponentController.h"

#include "Engine/MyEngine.h"

namespace ExampleGame {
	void ComponentController::Init() {
	}

	void ComponentController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		glm::vec2 basePos = engine->GetScreenSize() / 2.f;

		parent->rotation += rotSpeed * deltaTime;
		parent->position = basePos + movDirection * movAmount;
		//parent->position = basePos + movDirection * movAmount * glm::sin(movSpeed * engine->GetTime());
	}
}