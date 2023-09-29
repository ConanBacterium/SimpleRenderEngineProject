#pragma once

#include <list>
#include <memory>
#include <string>
#include <queue>

#include "sre/SpriteBatch.hpp"

namespace MyEngine {
	class Component;

	class GameObject {
		friend class Engine;

		// public API
	public:
		glm::vec2 position;
		float rotation;
		int radius;

		void Init();
		void Update(float);
		void Render(sre::SpriteBatch::SpriteBatchBuilder&);
		void KeyEvent(SDL_Event&);

		void AddChild(std::shared_ptr<GameObject>);
		void AddComponent(std::shared_ptr<Component>);

		std::string GetName();
		void SetName(std::string);

		std::queue<std::shared_ptr<GameObject>> _collisions; // this ought to be private ? doesn't matter now

	protected: 
		std::list<std::shared_ptr<GameObject>> _children = {}; // _root needs to go through all children do do collision detection... 

		// private fields
	private:
		std::weak_ptr<GameObject> _parent;
		std::weak_ptr<GameObject> _self;
		std::list< std::shared_ptr<Component>> _components = {};
		std::string _name;
	};
}