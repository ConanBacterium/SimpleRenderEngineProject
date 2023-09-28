#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

#include "Engine/MyEngine.h"

#include "Game/ComponentController.h"
#include "Game/ComponentRendererSprite.h"

#include <thread>


void InitGame();
void ProcessEvents(SDL_Event& event);
void Update(float deltaTime);
void Render();

MyEngine::Engine engine;

glm::vec2 window_size = glm::vec2(800, 600);
sre::SDLRenderer renderer;
sre::Camera camera;
std::shared_ptr<sre::SpriteAtlas> atlas;

int main() {
	renderer.frameRender = Render;
	renderer.frameUpdate = Update;
	renderer.keyEvent = ProcessEvents;

	renderer.setWindowSize(window_size);
	renderer.init();
	camera.setWindowCoordinates();

	atlas = sre::SpriteAtlas::create("data/space.json", "data/space.png");

	// PLAYER 
	auto player = engine.CreateGameObject("PlayerObject");
	auto playerController = std::shared_ptr<ExampleGame::ComponentController>(new ExampleGame::ComponentController());
	auto playerRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	player->AddComponent(playerController);
	player->AddComponent(playerRenderer);
	playerController->SetRotSpeed(0);
	playerRenderer->sprite = atlas->get("playerShip1_blue.png");

	// METEOR 
	auto meteor1 = engine.CreateGameObject("Meteor1");
	auto meteor1Controller = std::shared_ptr<ExampleGame::ComponentController>(new ExampleGame::ComponentController());
	auto meteor1Renderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	meteor1->AddComponent(meteor1Controller);
	meteor1->AddComponent(meteor1Renderer);
	meteor1Controller->SetRotSpeed(10);
	meteor1Controller->SetMovAmount(1);
	meteor1Renderer->sprite = atlas->get("meteorGrey_big1.png");

	engine.Init();
	renderer.startEventLoop();
}

void ProcessEvents(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		printf("keydown\n");
		if (event.key.keysym.sym == SDLK_a) {
			
		}

	}
}

void Update(float deltaTime) {
	engine.Update(deltaTime);
}

void Render() {
	engine.Render();
}