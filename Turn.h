#pragma once
#include "Board.h"

class Board::Turn {
private:
	char moved_chessman_id = 0;
	char x_start = 0;
	char y_start = 0;
	char x_finish = 0;
	char y_finish = 0;
	char finish_id = 0;

	Chessman* moved_chessman = nullptr;
	Chessman* eaten_chessman = nullptr;

	char castling = 0;
	char en_passant = 0;
	char promotion = 0;

	Board* board = nullptr;

	Chessman* findEatenChessman(char id, char x, char y);

	

	Turn(Chessman* _moved_figure, char x_st, char y_st, char x_fn, char y_fn, Board* _board);

	Turn(Chessman* _moved_figure, char x_st, char y_st, char x_fn, char y_fn, char _promotion, Board* _board);

	Turn(char _castling, Board* _board);

	

	bool subcheck(char x, char y, char kings_x, char kings_y, const Board* board);
public:
	Turn(std::string turn, Board* _board);

	void operator()();

	void unmake();

	bool isCheck();

	std::string name(); 
};
