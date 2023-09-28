#pragma once 


#pragma once
#include "SharedStructs.h"
#include <string>
#include <random>

class Score {
	int eatenCounter; 
	int wins; 
	int losses;
	// members are private by default... unless put in the public block
	public: 
		double gameloopMinDuration = 0.016; // 0.016
		int frame; 
		// char userInput;
		std::chrono::time_point<std::chrono::steady_clock>	looptime_start;
		std::chrono::time_point<std::chrono::steady_clock>	looptime_end;
		std::chrono::duration<double>						looptime_elapsed;


		void Init() {
			eatenCounter = 0;
			wins = 0;
			losses = 0;
		}

		void ProcessEvents() {
			
		}

		void Update() {

		}

		void Render() {

		}
	
	private: 
		

};