#pragma once

class Chessman {
private:
	char id;
	char x;
	char y;

	bool enabled = true;

	friend class Board;
	friend int main();
public:
	Chessman(char _id, char _x, char _y) {
		id = _id;
		x = _x;
		y = _y;
	}
};