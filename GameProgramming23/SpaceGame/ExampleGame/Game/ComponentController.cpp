#include "ComponentController.h"


#include "Engine/MyEngine.h"

namespace ExampleGame {

	bool ObjectOut = false;


	void ComponentController::Init() {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		glm::vec2 basePos = engine->GetScreenSize() / 2.f;

		parent->position = basePos;

	}

	void ComponentController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		glm::vec2 basePos = engine->GetScreenSize() / 2.f;

		parent->rotation += RotSpeed;
		parent->position = basePos + MovDirection;


	


	}
}