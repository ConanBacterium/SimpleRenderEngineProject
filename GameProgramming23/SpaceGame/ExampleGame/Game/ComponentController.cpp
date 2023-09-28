#include "ComponentController.h"


#include "Engine/MyEngine.h"

namespace ExampleGame {

	bool ObjectOut = false;


	void ComponentController::Init() {
	}

	void ComponentController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		glm::vec2 basePos = engine->GetScreenSize() / 2.f;

		parent->rotation += RotSpeed * deltaTime;
		parent->position = basePos + MovDirection * MovAmount;


	}

	void MeteoriteController::Init() {
	}

	void MeteoriteController::Update(float deltaTime) {

		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		// random numebr of seconds to wait for a new meteorite


		glm::vec2 basePos = engine->GetScreenSize() * BasePos;

		// Define the starting position (top of the screen)
		glm::vec2 startPos = glm::vec2(basePos.x, engine->GetScreenSize().y);

		// Define the ending position (bottom of the screen)
		glm::vec2 endPos = glm::vec2(basePos.x, -50.0f); // goes beyond the screen

		// Define the duration of the movement (adjust as needed for speed)
		float movementDuration = 8.0f; // Change this value to control the speed

		// Calculate the current position based on the elapsed time
		float elapsedTime = glm::min(engine->GetTime(), movementDuration); // Ensure it doesn't exceed the duration
		float t = elapsedTime / movementDuration; // Interpolation factor between 0 and 1

		// Use linear interpolation (lerp) to calculate the current position
		glm::vec2 currentPos = glm::mix(startPos, endPos, t);

		// Update the object's position
		parent->position = currentPos;

		float startRotation = 0.0f; // Starting rotation in degrees
		float endRotation = 2.0f; // Ending rotation in degrees

		// Calculate the current rotation based on the elapsed time
		float currentRotation = glm::mix(startRotation, endRotation, t);

		parent->rotation += currentRotation;


		if (currentPos == endPos && ObjectOut == false) {
			printf("Object has went out of the screen.");
			//call destroy function for meteorite
			//engine->DestroyGameObject();
			ObjectOut = true;




		}
	}
}