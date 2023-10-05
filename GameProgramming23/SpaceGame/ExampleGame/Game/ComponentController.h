#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class ComponentController : public MyEngine::Component {
		
	protected:
		float rotSpeed = 0;
		float movSpeed = 5;
		float movAmount = 0;
		glm::vec2 movDirection = glm::vec2(1, 0);
		glm::vec2 basePos;

	public:
		glm::vec2 position;
		float rotation;

		virtual void Init() override;
		virtual void Update(float) override;

		void SetRotSpeed(float speed) {
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