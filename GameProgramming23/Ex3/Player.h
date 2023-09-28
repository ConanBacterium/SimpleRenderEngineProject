#pragma once 
#include <tuple>
#include <vector>
#include "SharedStructs.h"
#include "Mouse.h"
class SnakeBody {
	// vector of coordinates, idx -1 is head 0 is tail
	private:
		std::vector<coords> bodyparts;
		int moves;

	public:
		void init(coords head) {
			bodyparts.clear();
			bodyparts.push_back(head);
			moves = 0;
		}

		std::vector<coords> getBodyparts() {
			return bodyparts; // returns copy
		}

		std::tuple<coords, coords> moveforward(char direction, bool isGrowing) {
			moves++;
			//returns tuple of new head and the old tail so caller can check for collision 

			coords tail = *bodyparts.begin(); // dereferences the pointer (begin() returns an iterator, kinda like a pointer), so this is a copy of the first element of bodyparts
			// coords tail = *tail; 
			coords currentHead = bodyparts.back(); // gives copy
			///// TODO WHY IS ONE OF THEM DEREFERENCED AND THE OTHER ISNT !?!?!

			coords newHead = currentHead;
			if (direction == ITUGames::Console:: KEY_A) { 
				newHead.x--;
			}
			else if (direction == ITUGames::Console:: KEY_W) {
				newHead.y--;
			}
			else if (direction == ITUGames::Console:: KEY_S) {
				newHead.y++;
			}
			else if (direction == ITUGames::Console:: KEY_D) {
				newHead.x++;
			}
			bodyparts.push_back(newHead);	
			
			if (!isGrowing) {
				bodyparts.erase(bodyparts.begin()); 
			}

			return std::make_tuple(newHead, tail);
		}

		bool didSelfCollide() {
			coords head = bodyparts.back(); 
			int c =0;
			for (coords bodypart : bodyparts) {
				if (c++ == bodyparts.size()-1) continue;

				if (bodypart == head) {
					ITUGames::Console::GotoCoords(bodypart.x, bodypart.y);
					std::cout << head.x << "=" << bodypart.x << " and " << head.y << "=" << bodypart.y;
					return true;
				}
			}
			return false;
		}
};


class Player {
	// members are private by default... unless put in the public block
	
	private: 
		Mouse* mouse; 
		SnakeBody* body =  new SnakeBody(); // pointer to the object body of class SnakeBody
		coords tail = {0,0};
		bool isGrowing;
		char direction; 
		char characterSprites[2] = {'0', 'K'};
		double characterToggleTimeMs = 0.5;
		bool playerSpriteIdx;
		double secondsPerMove = 0.15;
		std::chrono::time_point<std::chrono::steady_clock> lastCharacterSpriteToggle;
		std::chrono::time_point<std::chrono::steady_clock> lastSnakeMove;

		char userInput;

		void DrawCharacter() {
			std::vector<coords> bodyparts = body->getBodyparts();
			for (coords bodypart : bodyparts){
				ITUGames::Console::GotoCoords(bodypart.x, bodypart.y);
				std::cout << characterSprites[playerSpriteIdx];
			}
		}

	public: 
		void Init(Mouse* mouse_) {
			mouse = mouse_;
			body->init({10,9});
			playerSpriteIdx = 0;
			userInput = 0;
			// coords tail;
			isGrowing = false;
			char direction = ITUGames::Console::KEY_D; 
			lastSnakeMove = std::chrono::steady_clock::now();
		}

		void ProcessEvents(char input) {
			userInput = input;

			if (userInput == ITUGames::Console::KEY_D || userInput == ITUGames::Console::KEY_A || userInput == ITUGames::Console::KEY_W || userInput == ITUGames::Console::KEY_S) {
				direction = userInput;
			}
		}

		void Update() {
			// find out if charactersprite should change 
			std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
			std::chrono::duration<double> dt = now - lastCharacterSpriteToggle;
			double secondsSinceLastCharacterToggle = dt.count();
			ITUGames::Console::GotoCoords(0, 4);
			std::cout << "Time since last change of sprite char : " << secondsSinceLastCharacterToggle << std::endl;
			if (dt.count() > characterToggleTimeMs) {
				playerSpriteIdx = !playerSpriteIdx;
				lastCharacterSpriteToggle = now;
			}

			std::chrono::duration<double> dt1 = now - lastSnakeMove;
			double secondsSincelastSnakeMove = dt1.count();
			// move snake 
			if (secondsSincelastSnakeMove > secondsPerMove) {
				ITUGames::Console::GotoCoords(0, 18);
				// std::cout << "Time since last snake move : " << secondsSincelastSnakeMove << " / " << secondsPerMove << std::endl;
				std::tuple<coords, coords> headTail = body->moveforward(direction, isGrowing);
				isGrowing = false; 
				lastSnakeMove = std::chrono::steady_clock::now();
				coords head = std::get<0>(headTail);
				tail = std::get<1>(headTail);

				// TODO CHECK HEAD FOR COLLISION WITH ITSELF 
				if (body->didSelfCollide()) {
					// GAME OVER 
					for (int i; i < 20; i++) {
						ITUGames::Console::GotoCoords(15, 5+i);
						std::cout << "GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER";
					}
					while (true) {

						}
				}


				// TODO CHECK FOR MOUSE COLLISION 
				coords mouseCoords = mouse->getCoords();
				ITUGames::Console::GotoCoords(0, 20);
				std::cout << mouseCoords.x << ","<< mouseCoords.y;
				std::cout <<"-"<<head.x<<","<<head.y;
				if (head == mouseCoords) {
					// TODO score ++ 
					mouse->eatMe();
					isGrowing = true;
					secondsPerMove *= 0.9; // make faster 
				}
			}
			
		}

		void Render() {
			if(!isGrowing && (tail.y != 0)) {
				ITUGames::Console::GotoCoords(tail.x, tail.y);
				std::cout << " ";
			}
			DrawCharacter();
		}
};