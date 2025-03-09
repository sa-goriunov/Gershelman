#pragma once
#include "Board.h"

class Figure {
private:
	char id;
	char x;
	char y;

	bool enabled = true;

	friend class Board;
	friend int main();
public:
	Figure(char _id, char _x, char _y) {
		id = _id;
		x = _x;
		y = _y;
	}
};