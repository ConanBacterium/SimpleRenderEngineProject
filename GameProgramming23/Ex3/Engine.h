#pragma once
#include "SharedStructs.h"
#include <string>
#include <random>

class Engine {
	// members are private by default... unless put in the public block
	public: 
		double gameloopMinDuration = 0.016; // 0.016
		int frame; 
		// char userInput;
		std::chrono::time_point<std::chrono::steady_clock>	looptime_start;
		std::chrono::time_point<std::chrono::steady_clock>	looptime_end;
		std::chrono::duration<double>						looptime_elapsed;


		void Init() {
			frame = 0;
		}

		void ProcessEvents(char userInput) {
			
		}

		void Update(char userInput) {

		}

		void Render() {

		}
	
	private: 
		

};