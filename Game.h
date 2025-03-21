#pragma once
#include "Board.h"
#include "Global-Defines.h"
#include <vector>

class Board;

class Game {
	friend int main();

	Board *__board__;

	Game() {
std::vector<char> start_board = {  
     
OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE, BLACK*ROOK_NM, BLACK*KNIGHT, BLACK*BISHOP, BLACK*QUEEN, BLACK*KING_NM, BLACK*BISHOP, BLACK*KNIGHT, BLACK*ROOK_NM, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE,    BLACK*PAWN,   BLACK*PAWN,   BLACK*PAWN,  BLACK*PAWN,    BLACK*PAWN,   BLACK*PAWN,   BLACK*PAWN,    BLACK*PAWN, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,         VOID,          VOID, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,         VOID,          VOID, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,         VOID,          VOID, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE,          VOID,         VOID,         VOID,        VOID,          VOID,         VOID,         VOID,          VOID, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE,    WHITE*PAWN,   WHITE*PAWN,   WHITE*PAWN,  WHITE*PAWN,    WHITE*PAWN,   WHITE*PAWN,   WHITE*PAWN,    WHITE*PAWN, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE, WHITE*ROOK_NM, WHITE*KNIGHT, WHITE*BISHOP, WHITE*QUEEN, WHITE*KING_NM, WHITE*BISHOP, WHITE*KNIGHT, WHITE*ROOK_NM, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
OUTSIDE,OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,     OUTSIDE,       OUTSIDE,      OUTSIDE,      OUTSIDE,       OUTSIDE, OUTSIDE,OUTSIDE,
};

std::vector<Chessman> white = {
	{KING, 4, 0 }, { QUEEN, 3, 0 }, { ROOK, 0, 0 }, { ROOK, 7, 0 },
	{BISHOP, 2, 0}, {BISHOP, 5, 0}, {KNIGHT, 1, 0}, {KNIGHT, 6, 0},
	{PAWN, 0, 1}, {PAWN, 1, 1}, {PAWN, 2, 1}, {PAWN, 3, 1},
	{PAWN, 4, 1}, {PAWN, 5, 1}, {PAWN, 6, 1}, {PAWN, 7, 1}
};
		std::vector<Chessman> black = {
	{KING, 4, 7}, {QUEEN, 3, 7}, {ROOK, 0, 7}, {ROOK, 7, 7},
	{BISHOP, 2, 7}, {BISHOP, 5, 7}, {KNIGHT, 1, 7}, {KNIGHT, 6, 7},
	{PAWN, 0, 6}, {PAWN, 1, 6}, {PAWN, 2, 6}, {PAWN, 3, 6},
	{PAWN, 4, 6}, {PAWN, 5, 6}, {PAWN, 6, 6}, {PAWN, 7, 6}
		};
		Board* ptr = new Board(start_board, white, black, WHITE);
		__board__ = ptr;
	}
};