#include "ComponentController.h"


#include "Engine/MyEngine.h"

namespace ExampleGame {

	bool ObjectOut = false;


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

		parent->position = parent->position + movDirection * movAmount;
		//parent->position = basePos + movDirection * movAmount * glm::sin(movSpeed * engine->GetTime());
	}
}