#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include <random>
#include <thread>


#include "Engine/MyEngine.h"

#include "Game/ComponentController.h"
#include "Game/ComponentRendererSprite.h"

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
	auto componentController = std::shared_ptr<ExampleGame::ComponentController>(new ExampleGame::ComponentController());
	auto componentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
	Player->AddComponent(componentController);
	Player->AddComponent(componentRenderer);

	componentRenderer->sprite = atlas->get("playerShip2_orange.png");
	componentController->SetSpeed(20);

	engine.Init();


	//first
	auto Meteorite = engine.CreateGameObject("GameObject");
	auto MeteoriteController = std::shared_ptr<ExampleGame::MeteoriteController>(new ExampleGame::MeteoriteController());
	auto MeteoriteRenderer = std::make_shared<ExampleGame::MeteoriteRendererSprite>();
	Meteorite->AddComponent(MeteoriteController);
	Meteorite->AddComponent(MeteoriteRenderer);

	MeteoriteRenderer->sprite = atlas->get("meteorBrown_big4.png");
	MeteoriteController->SetSpeed(20);
	MeteoriteController->SetBasePos(0.5f);

	//second
	auto Meteorite2 = engine.CreateGameObject("GameObject");
	auto MeteoriteController2 = std::shared_ptr<ExampleGame::MeteoriteController>(new ExampleGame::MeteoriteController());
	auto MeteoriteRenderer2 = std::make_shared<ExampleGame::MeteoriteRendererSprite>();

	Meteorite2->AddComponent(MeteoriteController2);
	Meteorite2->AddComponent(MeteoriteRenderer2);


	MeteoriteRenderer2->sprite = atlas->get("meteorBrown_big4.png");
	MeteoriteController2->SetSpeed(20);
	MeteoriteController2->SetBasePos(0.2f);


	engine.Init();
	renderer.startEventLoop();
}

void ProcessEvents(SDL_Event& event) {
	// Check the type of the event
	if (event.type == SDL_QUIT) {
		// The user closed the window
		// Handle window close event
	}
	else if (event.type == SDL_KEYDOWN) {
		// A key was pressed
		// Check the specific key
		if (event.key.keysym.sym == SDLK_SPACE) {
			printf("I pressed space\n");
		}

		if (event.key.keysym.sym == SDLK_w) {
			printf("Pressed w \n");

		}

		if (event.key.keysym.sym == SDLK_d) {
			printf("Pressed w \n");
		}

		if (event.key.keysym.sym == SDLK_a) {
			printf("Pressed w \n");
		}

		if (event.key.keysym.sym == SDLK_s) {
			printf("Pressed w \n");
		}
		// Add more key checks as needed for other keys
	}
	// Add more event types as needed (e.g., SDL_MOUSEBUTTONDOWN)
}

void Update(float deltaTime) {
	engine.Update(deltaTime);

}

void Render() {
	engine.Render();


}