#include "ComponentController.h"

#include "Engine/MyEngine.h"
#include <chrono>


namespace ExampleGame {
	void ComponentController::Init() {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();

		//basePos = engine->GetScreenSize() / 2.f;
		//start timer
		auto start = std::chrono::high_resolution_clock::now();

		
		MyEngine::GameObject* parent = GetGameObject();
		//parent->position = basePos;
	}

	void ComponentController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();


		parent->rotation += rotSpeed * deltaTime;

		parent->position = parent->position + movDirection * movAmount;
		//parent->position = basePos + movDirection * movAmount * glm::sin(movSpeed * engine->GetTime());
	}
}