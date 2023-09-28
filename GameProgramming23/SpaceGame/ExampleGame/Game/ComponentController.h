#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class ComponentController : public MyEngine::Component {
		float rotSpeed = 50;
		float movSpeed = 5;
		float movAmount = 0;
		glm::vec2 movDirection = glm::vec2(1, 0);
		glm::vec2 basePos;

	public:
		glm::vec2 position;
		float rotaiton;

		void Init() override;
		void Update(float) override;

		void SetRotSpeed(int speed) {
			rotSpeed = speed;
		}
		int GetRotSpeed() {
			return rotSpeed;
		}
		void SetMovAmount(int amount) {
			movAmount = amount;
		}
		void SetMovDirection(glm::vec2 direction) {
			movDirection = direction;
		}

		//void 
	};
}