#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class ComponentController : public MyEngine::Component {

	protected:
		float RotSpeed = 0;
		float MovSpeed = 0;
		float MovAmount = 0;
		glm::vec2 MovDirection = glm::vec2(1, 0);

	public:
		glm::vec2 position;
		float rotation;
		int moveSpeed;

		void Init() override;
		void Update(float) override;

		void SetSpeed(float speed) {
			MovSpeed = speed;
		};

		float GetSpeed() {
			return MovSpeed;
		};

		void SetRotSpeed(float rotspeed) {
			RotSpeed = rotspeed;
		};

		float GetRotSpeed() {
			return RotSpeed;
		};
	};

	
}