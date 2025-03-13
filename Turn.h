#pragma once
#include "Board.h"

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
	char promotion = 0;

	Board* board = NULL;

	Figure* findEatenFigure(char id, char x, char y);

	

	Turn(Figure* _moved_figure, char x_st, char y_st, char x_fn, char y_fn, Board* _board);

	Turn(Figure* _moved_figure, char x_st, char y_st, char x_fn, char y_fn, char _promotion, Board* _board);

	Turn(char _castling, Board* _board);


	bool subcheck(char x, char y, char kings_x, char kings_y, Board* board);
public:
	Turn(std::string turn, Board* _board);

	void operator()();

	void unmake();

	bool check();

	std::string name(); 
};
