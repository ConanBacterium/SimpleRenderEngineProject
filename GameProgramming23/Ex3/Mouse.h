#pragma once
#include "SharedStructs.h"
#include <string>
#include <random>
#include "ITUGames.h"

class Mouse {
	// members are private by default... unless put in the public block
	coords mouse; 
	coords oldMouse; 
    bool eaten;
	
	public: 
		coords getNewMousePosition() {

			ITUGames::Console::GotoCoords(30, 0);
			std::cout << "SUCK";

			ITUGames::Console::GetTerminalWidth();
			ITUGames::Console::GetTerminalHeight();

			int miny = 7; // shouldn't spawn mouse above ... 
			int minx = 7; 
            // int maxwidth = ITUGames::Console::GetTerminalWidth();
            // int maxheight = ITUGames::Console::GetTerminalHeight();
			int maxwidth = 70;
			int maxheight = 30;

			int x = minx + (std::rand() % (maxwidth));
			int y = miny + (std::rand() % (maxheight));

            // DEBUGPRINT 
            ITUGames::Console::GotoCoords(20, 8);
			std::cout << "ha";
			ITUGames::Console::GotoCoords(20, 9);
			std::cout << maxwidth << "," << maxheight;
			
			// make sure it didn't spawn on player snakebody TODO 

			return {x, y};
		}

		void respawn() {
			mouse = getNewMousePosition();
		}

		void eatMe() {
			respawn();
			eaten = true;
		}

		coords getCoords() {
			return mouse;
		}

		void Init() {
			respawn();
            eaten = false; 
		}

		void ProcessEvents(char userInput) {
			
		}

		void Update(char userInput) {
            
		}

		void Render() {
            if (eaten) {
                ITUGames::Console::GotoCoords(oldMouse.x, oldMouse.y);
				std::cout << " ";
				eaten = !eaten;
            }
            ITUGames::Console::GotoCoords(mouse.x, mouse.y);
			std::cout << "*";

            
            // DEBUGPRINT 
            // ITUGames::Console::GotoCoords(20, 20);
			// std::cout << mouse.x << mouse.y << "..";
		}
	
	private: 
		

};