#include "ComponentController.h"

#include "glm/glm.hpp"
#include "SDL.h"

#include "Engine/Components/ComponentPhysicsBody.h"
#include "Engine/Components/ComponentRendererSprite.h"

std::weak_ptr<ComponentRendererSprite> _sprite;
float temp_vel = 0;


void ComponentController::Init(rapidjson::Value& serializedData) {
	auto gameObject = GetGameObject().lock();
	if (!gameObject)
		return;

	_sprite = gameObject->FindComponent<ComponentRendererSprite>();
	_body = gameObject->FindComponent<ComponentPhysicsBody>();



}

void ComponentController::Update(float deltaTime) {
	auto body = _body.lock();
	if (!body)
		return;


	auto sprite = _sprite.lock();


	auto linearVelocity = body->getLinearVelocity();
	linearVelocity.x = _mov.x * _movSpeed;
	body->setLinearVelocity(linearVelocity);


	if (_jump) {
		body->addImpulse(glm::vec2(0, _jumpStrength));
		_jump = false;
	}

	//std::cout << "Velocity x:" << body->getLinearVelocity().x << std::endl;
	std::cout << "Velocity y:" << body->getLinearVelocity().y << std::endl;
	
	auto Xvel = body->getLinearVelocity().x;
	auto Yvel = body->getLinearVelocity().y;

	if (Xvel > 0 && _grounded) {
		//walkign to the right
		sprite->SetSprite("platformer-art-deluxe", "20.png");
	}
	else if (Xvel < 0 && _grounded) {
		//walking left -- needs to be flipped
		sprite->SetSprite("platformer-art-deluxe", "21.png");
		sprite->Flip(true, false);
	}
	else if (Xvel == 0 && _grounded) {
		sprite->SetSprite("platformer-art-deluxe", "19.png");

	}

	//jumping
	if (Yvel > 0 && !_grounded) {
		//jumping up
		sprite->SetSprite("platformer-art-deluxe", "26.png");
	}
	else if (Yvel < 0 && !_grounded) {
		//jumping down
		sprite->SetSprite("platformer-art-deluxe", "28.png");

	}else if (Yvel == 0 && !_grounded){
		//fly state
		sprite->SetSprite("platformer-art-deluxe", "27.png");

	}

}

void ComponentController::KeyEvent(SDL_Event& event) {


	// movement
	switch (event.key.keysym.sym) {
		case SDLK_a: _mov.x = -(event.type == SDL_KEYDOWN); break;
		case SDLK_d: _mov.x = +(event.type == SDL_KEYDOWN); break;
	}

	// jump
	if (_grounded && event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
		_jump = true;

}

void ComponentController::OnCollisionStart(ComponentPhysicsBody* other, b2Manifold* manifold) {
	if (manifold->localNormal.y > .99)
		_grounded = true;
}

void ComponentController::OnCollisionEnd(ComponentPhysicsBody* other, b2Manifold* manifold) {
	if (manifold->localNormal.y > .99)
		_grounded = false;
}
