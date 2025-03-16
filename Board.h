#pragma once
#include <vector>
#include <deque>
#include <string>
#include "Chessman.h"
#include "ZObrist-Defines.h"

class Board {
private:
	std::vector<char> board; //board[144]

	std::vector<Chessman> chessmen[2];

	unsigned __int64 zobrist = rand64();
	std::deque<unsigned __int64> history;
	char color_turn;

	Board(std::vector<char> _board, std::vector<Chessman> white, std::vector<Chessman> black, char color);

public:
	void printTest();

	class Turn;

	friend class Game;
	friend int main();
};