#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include <random>
#include <thread>


#include "Engine/MyEngine.h"

#include "Game/ComponentController.h"
#include "Game/ComponentRendererSprite.h"
#include "Game/PlayerController.h"



void InitGame();
void ProcessEvents(SDL_Event& event);
void Update(float deltaTime);
void Render();

MyEngine::Engine engine;

glm::vec2 window_size = glm::vec2(800, 600);
sre::SDLRenderer renderer;
sre::Camera camera;
std::shared_ptr<sre::SpriteAtlas> atlas;
std::chrono::steady_clock::time_point startTime;
std::chrono::steady_clock::time_point endTime;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distribution(3000, 5000); // Random time between 3 and 5 seconds in milliseconds


int main() {
	renderer.frameRender = Render;
	renderer.frameUpdate = Update;
	renderer.keyEvent = ProcessEvents;

	renderer.setWindowSize(window_size);
	renderer.init();
	camera.setWindowCoordinates();

	auto startTime = std::chrono::high_resolution_clock::now();


	atlas = sre::SpriteAtlas::create("data/space.json", "data/space.png");

	auto Player = engine.CreateGameObject("GameObject");
	auto PlayerController = std::shared_ptr<ExampleGame::PlayerController>(new ExampleGame::PlayerController());
	auto componentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	Player->AddComponent(PlayerController);
	Player->AddComponent(componentRenderer);

	componentRenderer->sprite = atlas->get("playerShip3_green.png");
	PlayerController->SetSpeed(20);

	engine.Init();


	//first
	auto Meteorite = engine.CreateGameObject("GameObject");
	auto MeteoriteCon = std::shared_ptr<ExampleGame::MeteoriteController>(new ExampleGame::MeteoriteController());
	auto MeteoriteRenderer = std::make_shared<ExampleGame::MeteoriteRendererSprite>();
	Meteorite->AddComponent(MeteoriteCon);
	Meteorite->AddComponent(MeteoriteRenderer);

	MeteoriteRenderer->sprite = atlas->get("meteorBrown_big1.png");
	MeteoriteCon->SetSpeed(20);
	MeteoriteCon->SetBasePos(0.5f);

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