#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <stack>
// #include "ITUGames.h"
#include "Engine.h"
#include "Player.h"
#include "Score.h"
#include "Mouse.h"
#include "SharedStructs.h"

#pragma region Engine State

//////////////////
////// GLOBAL DATA
//////////////////
Engine engine;
Player player;
Score score; 
Mouse mouse;
char userInput;
bool gameOver;


#pragma endregion // Engine State
#pragma region Game State
#pragma endregion // Game State

void LongComputation();
void ProcessEvents();
void Render(); 
void Update(std::chrono::time_point<std::chrono::steady_clock>);

void initAll() {
	player.Init(&mouse);
	engine.Init();
	mouse.Init();
	// score.init();
	gameOver = false;
}

int main() {
	// initialize random generator
	std::srand(std::time(nullptr)); 
	ITUGames::Console::InitScreenForRendering();
	
	initAll();
	
	ITUGames::Console::GotoCoords(0,0);
	// ITUGames::Console::GotoTop();
	while(!gameOver) {
		// ITUGames::Console::ClearScreen();
		engine.looptime_start = std::chrono::steady_clock::now();

		ProcessEvents();
		Update(engine.looptime_start);
		ITUGames::Console::InitScreenForRendering(); // TODO rm this
		Render();
	}
	return 0;
}

void ProcessEvents() {
	// check for user movement
	//engine.userInput = ITUGames::Console::GetCharacter(false);
	userInput = ITUGames::Console::GetCharacter(false);
	if (userInput == 'p') {
		while (ITUGames::Console::GetCharacter(false) != 'p') {

		}

	}
	engine.ProcessEvents(userInput);
	player.ProcessEvents(userInput);
	mouse.ProcessEvents(userInput);
	ITUGames::Console::GotoCoords(0,5);
	std::cout << "User input : " << userInput << std::endl;
}
void Update(std::chrono::time_point<std::chrono::steady_clock> looptime_start) {
	engine.Update(userInput);
	player.Update();
	// score.Update(userInput);
	mouse.Update(userInput);

	

    engine.frame++; 
	engine.looptime_end = std::chrono::steady_clock::now();
	engine.looptime_elapsed = engine.looptime_end - looptime_start;
	double elapsed_time = engine.looptime_elapsed.count();
	if (engine.looptime_elapsed.count() < engine.gameloopMinDuration) {
		double sleepDuration = engine.gameloopMinDuration - elapsed_time;
		ITUGames::Console::GotoCoords(0, 3);
		std::cout << "SLEEP FOR SEC " << sleepDuration << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(sleepDuration * 1000)));
		// ITUGames::Utils::PreciseSleep(std::chrono::duration<double>(sleepDuration));
	}
}

void Render() {
    ///// GAME INFO 
    ITUGames::Console::GotoCoords(0,0);
    std::cout << "Elapsed : " << engine.looptime_elapsed.count() << std::endl;
    std::cout << "FPS     : " << 1.0 / engine.looptime_elapsed.count() << std::endl;
    ITUGames::Console::GotoCoords(0,6);
    std::cout << "--------------------------------";

	engine.Render();
	player.Render();
	mouse.Render();
	// score.Render();

    std::cout << std::flush;
}

void LongComputation()
{
	// get a random number between 0.01 and 0.016
	double sleep_time = (10 + std::rand() % 6) / 1000.0;

	ITUGames::Utils::PreciseSleep(std::chrono::duration<double>(sleep_time));
}