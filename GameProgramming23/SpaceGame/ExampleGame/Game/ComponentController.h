#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class ComponentController : public MyEngine::Component {
		
	protected:
		float rotSpeed = 0;
		float movSpeed = 5;
		float movAmount = 0;
		glm::vec2 movDirection = glm::vec2(1, 0);
		//glm::vec2 basePos = glm::vec2(200,100);
		//std::chrono::high_resolution_clock start;


	public:
		glm::vec2 position;
		float rotation;

		void Init() override;
		void Update(float) override;

		void SetRotSpeed(float speed) {
			rotSpeed = speed;
		}
		int GetRotSpeed() {
			return rotSpeed;
		}
		void SetMovAmount(float amount) {
			movAmount = amount;
		}
		void SetMovDirection(glm::vec2 direction) {
			movDirection = direction;
		}
	};
}