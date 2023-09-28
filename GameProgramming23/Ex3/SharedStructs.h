#pragma once 
struct coords {
	int x;
	int y;

	bool operator==(const coords& other) const {
        return x == other.x && y == other.y;
    }
};