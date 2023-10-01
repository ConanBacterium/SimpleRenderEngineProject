#include "MyEngine.h"

#include <random>

#include "sre/RenderPass.hpp"

namespace MyEngine {
	Engine* Engine::_instance = nullptr;

	Engine::Engine() {
		assert(_instance == nullptr && " Only one instance of MyEngine::Engine allowed!");
		_instance = this;

		_root = std::make_shared<GameObject>();
		_root->SetName("root");
	}

	glm::vec2 Engine::GetScreenSize() const
	{
		return WIN_SIZE;
	}

	void Engine::Init() {
		// initializes random generator
		std::srand(std::time(nullptr));

		_camera.setWindowCoordinates();

		_root->Init();
	}

	void Engine::ProcessEvents(SDL_Event& event) {
		_root->KeyEvent(event);
	}

	void Engine::DetectCollisions() {

		// CHAT GPT GENERATED OPTIMIZATION OF THE BELOW FLAWED VERSION 
		for (auto it1 = _root->_children.begin(); it1 != _root->_children.end(); ++it1) {
			auto it2 = it1;
			++it2;  // Start from the next element
			for (; it2 != _root->_children.end(); ++it2) {
				float dist = glm::distance((*it1)->position, (*it2)->position);
				if (dist <= (*it1)->radius + (*it2)->radius) {
					printf("COLLISION");
					(*it1)->_collisions.push(*it2);
					(*it2)->_collisions.push(*it1);
				}
			}
		}


		/*
		for (auto& child1 : _root->_children) {
			for (auto& child2 : _root->_children) {
				float dist = glm::distance(child1->position, child2->position); 
				if (dist <= child1->radius + child2->radius) {
					child1->_collisions.push(child2);
					child2->_collisions.push(child1);
				}
			}
		}
		*/
	}

	void Engine::Update(float deltaTime) {
		++frame;
		time += deltaTime;
		_root->Update(deltaTime);
		DetectCollisions();
	}

	void Engine::Render()
	{
		sre::RenderPass renderPass = sre::RenderPass::create()
			.withCamera(_camera)
			.withClearColor(true, { .3f, .3f, 1, 1 })
			.build();

		sre::SpriteBatch::SpriteBatchBuilder spriteBatchBuilder = sre::SpriteBatch::create();

		_root->Render(spriteBatchBuilder);

		auto spriteBatch = spriteBatchBuilder.build();
		renderPass.draw(spriteBatch);
	}

	GameObject* Engine::CreateGameObject(std::string name) {
		auto ret = std::make_shared<GameObject>();
		ret->_self = ret;
		//ret->_parent = _root;
		ret->SetName(name);
		_root->AddChild(ret);

		return ret.get();
	}
}
