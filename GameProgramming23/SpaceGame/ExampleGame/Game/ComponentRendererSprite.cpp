#include "ComponentRendererSprite.h"

namespace ExampleGame {
	void ComponentRendererSprite::Render(sre::SpriteBatch::SpriteBatchBuilder& builder) {
		MyEngine::GameObject* parent = GetGameObject();

		sprite.setPosition(parent->position);
		sprite.setRotation(parent->rotation);

		builder.addSprite(sprite);
	}

	void MeteoriteRendererSprite::Render(sre::SpriteBatch::SpriteBatchBuilder& builder) {
		MyEngine::GameObject* parent = GetGameObject();

		sprite.setPosition(parent->position);
		sprite.setRotation(parent->rotation);

		builder.addSprite(sprite);
	}
}