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

	class MeteoriteController : public MyEngine::Component {
		float MovSpeed;
		float RotSpeed;
		float BasePos;

	public:

		float rotation;

		glm::vec2 position;
		glm::vec2 MovDirection = glm::vec2(1, 0);


		void Init() override;
		void Update(float) override;

		// -------------- SETTERS --------------

		void SetBasePos(float position) {
			BasePos = position;
		}

		void SetSpeed(float speed) {
			MovSpeed = speed;
		}

		// -------------- GETTERS --------------

		float GetBasePos() {
			return BasePos;
		}


		float GetMovSpeed() {
			return MovSpeed;
		}
	};


}