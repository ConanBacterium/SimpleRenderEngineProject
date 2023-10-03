#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include <random>
#include <thread>
#include "Engine/MyEngine.h"

#include "Game/ComponentController.h"
#include "Game/LazerController.h"
#include "Game/ComponentRendererSprite.h"
#include "Game/PlayerController.h"
#include "Game/MeteoriteController.h"

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


	atlas = sre::SpriteAtlas::create("data/space_2.json", "data/space_2.png");
	auto startTime = std::chrono::high_resolution_clock::now();



	// METEOR 
	//auto meteor1 = engine.CreateGameObject("Meteor1", GENERIC);
	auto meteor1 = engine.CreateGameObject("Meteor1");
	auto meteor1Controller = std::shared_ptr<ExampleGame::MeteoriteController>(new ExampleGame::MeteoriteController());
	auto meteor1Renderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	meteor1->AddComponent(meteor1Controller);
	meteor1->AddComponent(meteor1Renderer);
	meteor1Renderer->sprite = atlas->get("meteorBrown_big1.png");
	meteor1->radius = 50;

	meteor1Controller->InitMeteor();

	// METEOR 
	//auto meteor1 = engine.CreateGameObject("Meteor1", GENERIC);
	auto meteor2 = engine.CreateGameObject("Meteor2");
	auto meteor2Controller = std::shared_ptr<ExampleGame::MeteoriteController>(new ExampleGame::MeteoriteController());
	auto meteor2Renderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	meteor2->AddComponent(meteor2Controller);
	meteor2->AddComponent(meteor2Renderer);
	meteor2Renderer->sprite = atlas->get("meteorBrown_big1.png");
	meteor2->radius = 50;

	meteor2Controller->InitMeteor();

	// METEOR 
//auto meteor1 = engine.CreateGameObject("Meteor1", GENERIC);
	auto meteor3 = engine.CreateGameObject("Meteor3");
	auto meteor3Controller = std::shared_ptr<ExampleGame::MeteoriteController>(new ExampleGame::MeteoriteController());
	auto meteor3Renderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	meteor3->AddComponent(meteor3Controller);
	meteor3->AddComponent(meteor3Renderer);
	meteor3Renderer->sprite = atlas->get("meteorBrown_big1.png");
	meteor3->radius = 50;

	meteor3Controller->InitMeteor();

	// METEOR 
//auto meteor1 = engine.CreateGameObject("Meteor1", GENERIC);
	auto meteor4 = engine.CreateGameObject("Meteor4");
	auto meteor4Controller = std::shared_ptr<ExampleGame::MeteoriteController>(new ExampleGame::MeteoriteController());
	auto meteor4Renderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	meteor4->AddComponent(meteor4Controller);
	meteor4->AddComponent(meteor4Renderer);
	meteor4Renderer->sprite = atlas->get("meteorBrown_big1.png");
	meteor4->radius = 50;

	meteor4Controller->InitMeteor();

	// METEOR 
//auto meteor1 = engine.CreateGameObject("Meteor1", GENERIC);
	auto meteor5 = engine.CreateGameObject("Meteor5");
	auto meteor5Controller = std::shared_ptr<ExampleGame::MeteoriteController>(new ExampleGame::MeteoriteController());
	auto meteor5Renderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	meteor5->AddComponent(meteor5Controller);
	meteor5->AddComponent(meteor5Renderer);
	meteor5Renderer->sprite = atlas->get("meteorBrown_big1.png");
	meteor5->radius = 50;

	meteor5Controller->InitMeteor();


	// LAZER
	auto lazer = engine.CreateGameObject("Lazer");
	auto lazerController = std::shared_ptr<ExampleGame::LazerController>(new ExampleGame::LazerController());
	auto lazerRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	lazer->AddComponent(lazerController);
	lazer->AddComponent(lazerRenderer);
	lazerRenderer->sprite = atlas->get("laserBlue01.png");
	lazer->radius = 50;


	// PLAYER 
	//auto player = engine.CreateGameObject("PlayerObject", PLAYER);
	auto player = engine.CreateGameObject("PlayerObject");
	auto playerController = std::shared_ptr<ExampleGame::PlayerController>(new ExampleGame::PlayerController());
	auto playerRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	player->AddComponent(playerController);
	player->AddComponent(playerRenderer);
	playerController->SetRotSpeed(0);
	playerRenderer->sprite = atlas->get("playerShip1_blue.png");
	player->radius = 50;
	

	engine.Init();
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