#pragma once
#include "Board.h"
#include "Figure.h"

class Board::Turn {
private:
	char moved_figure_id = 0;
	char x_start = 0;
	char y_start = 0;
	char x_finish = 0;
	char y_finish = 0;
	char finish_id = 0;

	Figure* moved_figure = NULL;
	Figure* eaten_figure = NULL;

	char castling = 0;
	char en_passant = 0;

	Board* board = NULL;

	Figure* findEatenFigure(char id, char x, char y);
public:
	Turn(std::string turn, Board* _board);

	Turn(Figure* _moved_figure, char x_st, char y_st, char x_fn, char y_fn, Board* _board);

	Turn(char _castling, Board* _board);

	void operator()();

	bool check();

	void unmake();

	std::string name(); 
};
