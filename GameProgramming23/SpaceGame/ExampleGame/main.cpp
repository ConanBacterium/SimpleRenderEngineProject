#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

#include "Engine/MyEngine.h"

#include "Game/ComponentController.h"
#include "Game/ComponentRendererSprite.h"
#include "Game/PlayerController.h"
#include "Game/MeteoriteController.h"
#include "Game/LazerController.h"

//#include "../../ExampleGame/Game/enums.h"

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

	atlas = sre::SpriteAtlas::create("data/space_3.json", "data/space_3.png");

	// PLAYER 
	//auto player = engine.CreateGameObject("PlayerObject", PLAYER);
	auto player = engine.CreateGameObject("PlayerObject");
	auto playerController = std::shared_ptr<ExampleGame::PlayerController>(new ExampleGame::PlayerController());
	auto playerRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	player->AddComponent(playerController);
	player->AddComponent(playerRenderer);
	playerController->SetRotSpeed(0);
	playerRenderer->sprite = atlas->get("playerShip3_green.png");
	player->radius = 50;

	// METEOR 
	//auto meteor1 = engine.CreateGameObject("Meteor1", GENERIC);
	auto meteor1 = engine.CreateGameObject("Meteor1");
	auto meteor1Controller = std::shared_ptr<ExampleGame::MeteoriteController>(new ExampleGame::MeteoriteController());
	auto meteor1Renderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	meteor1->AddComponent(meteor1Controller);
	meteor1->AddComponent(meteor1Renderer);
	meteor1Renderer->sprite = atlas->get("meteorBrown_big1.png");
	meteor1->radius = 50;

	// LAZER
	
	auto lazer = engine.CreateGameObject("Lazer");
	auto lazerController = std::shared_ptr<ExampleGame::LazerController>(new ExampleGame::LazerController());
	auto lazerRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	lazer->AddComponent(lazerController);
	lazer->AddComponent(lazerRenderer);
	lazerRenderer->sprite = atlas->get("meteorBrown_small1.png");
	lazer->radius = 28;
	

	engine.Init();
	meteor1Controller->InitMeteor();
	renderer.startEventLoop();
}

void ProcessEvents(SDL_Event& event) {
	engine.ProcessEvents(event);
	
}

void Update(float deltaTime) {
	engine.Update(deltaTime);
}

void Render() {
	engine.Render();
}