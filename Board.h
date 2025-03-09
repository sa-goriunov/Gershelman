#pragma once
#include <vector>
#include <string>
#include "Figure.h"

class Game; class Figure;

class Board {
private:
	std::vector<char> board; //board[144]

	std::vector<Figure> figures[2];

	int64_t zobrist = 0;
	char color_turn;

	Board(std::vector<char> _board, std::vector<Figure> white, std::vector<Figure> black, char color) {
		board = _board;
		figures[0] = white;
		figures[1] = black;
		color_turn = color;
	}

public:
	void printTest();

	class Turn;

	friend Game;
	friend int main();
};