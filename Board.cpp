#include "Global-Defines.h"
#include "Board.h"
#include "ZObrist-Defines.h"

Board::Board(std::vector<char> _board, std::vector<Chessman> white, std::vector<Chessman> black, char color) {
	board = _board;
	chessmen[0] = white;
	chessmen[1] = black;
	color_turn = color;

	for (const auto i : chessmen[0]) {
		zobrist = zobrist xor RANDOM_SET[i.id][WHITE][i.x][i.y];
	}

	for (const auto i : chessmen[1]) {
		zobrist = zobrist xor RANDOM_SET[i.id][BLACK][i.x][i.y];
	}
}