#include "Board.h"
#include "Turn.h"
#include "GlobalDefines.h"

Board::Turn::Turn(std::string turn, Board* _board) {
	board = _board;
	if ((turn == "O-O") || (turn == "o-o") || (turn == "0-0")) castling = 1;
	else if ((turn == "O-O-O") || (turn == "o-o-o") || (turn == "0-0-0")) castling = 2;
	else {
		x_start = turn[0] - 'a';
		y_start = turn[1] - '1';
		x_finish = turn[2] - 'a';
		y_finish = turn[3] - '1';

		int color = (-board->color_turn + 1) / 2;
		for (int i = 0; i < NUMBER_OF_FIGURES; i++) {
			Figure *tmp = &board->figures[color][i];
			if ((tmp->x == x_start) && (tmp->y == y_start) && (tmp->enabled)) {
				moved_figure = tmp; break;
			}}

		moved_figure_id = board->board[(9 - y_start) * 12 + 2 + x_start];
		finish_id = board->board[(9 - y_finish) * 12 + 2 + x_finish];

		if(moved_figure->id == PAWN){
			if (((y_start == 1) && (y_finish == 3)) || ((y_start == 6) && (y_finish == 4))) { en_passant = x_finish; }
			else if ((y_finish == 0) || (y_finish == 7)) {
					switch (turn[4]) {
					case 'Q': promotion = QUEEN; break;
					case 'q': promotion = QUEEN; break;
					case 'R': promotion = ROOK; break;
					case 'r': promotion = ROOK; break;
					case 'B': promotion = BISHOP; break;
					case 'b': promotion = BISHOP; break;
					case 'N': promotion = KNIGHT; break;
					case 'n': promotion = KNIGHT; break;
					default: promotion = VOID;
					}
		}}

		eaten_figure = findEatenFigure(finish_id, x_finish, y_finish);

	}
}

Board::Turn::Turn(Figure* _moved_figure, char x_st, char y_st, char x_fn, char y_fn, Board* _board) {
	board = _board;
	moved_figure = _moved_figure;
	moved_figure_id = board->board[(9 - y_start) * 12 + 2 + x_start];
	x_start = x_st;
	y_start = y_st;
	x_finish = x_fn;
	y_finish = y_fn;

	finish_id = board->board[(9 - y_finish) * 12 + 2 + x_finish];

	if ((moved_figure->id == PAWN) && (((y_start == 1) && (y_finish == 3)) || ((y_start == 6) && (y_finish == 4)))) en_passant = x_finish;

	eaten_figure = findEatenFigure(finish_id, x_finish, y_finish);
}

Board::Turn::Turn(Figure* _moved_figure, char x_st, char y_st, char x_fn, char y_fn, char _promotion, Board* _board) {
	board = _board;
	moved_figure = _moved_figure;
	moved_figure_id = board->board[(9 - y_start) * 12 + 2 + x_start];
	x_start = x_st;
	y_start = y_st;
	x_finish = x_fn;
	y_finish = y_fn;
	promotion = _promotion;

	finish_id = board->board[(9 - y_finish) * 12 + 2 + x_finish];

	eaten_figure = findEatenFigure(finish_id, x_finish, y_finish);
}

Board::Turn::Turn(char _castling, Board* _board) {
	board = _board;
	castling = _castling;
}

Figure* Board::Turn::findEatenFigure(char id, char x, char y) {
	if (id != VOID) {
		for (int i = 0; i < NUMBER_OF_FIGURES; i++) {
			Figure* tmp = &board->figures[(board->color_turn + 1) / 2][i];
			if ((tmp->x == x_finish) && (tmp->y == y_finish) && (tmp->enabled)) {
				return tmp;
			}}
	} else if ((moved_figure->id == PAWN) && (x_start != x_finish)) {
		for (int i = 8; i < NUMBER_OF_FIGURES; i++) {
			Figure* tmp = &board->figures[(board->color_turn + 1) / 2][i];
			if ((x_finish == tmp->x) && ((y_finish - 1) == tmp->y) && (tmp->enabled)) {
				return tmp;
			}}
	}
	else { return NULL; }

	return NULL;
}

std::string Board::Turn::name() {
	std::string name = "";

	switch (castling) {
	case 1: name = "_O-O_"; break;
	case 2: name = "O-O-O"; break;
	default:
		switch (moved_figure->id) {
		case 1: name += "P"; break;
		case 2: name += "N"; break;
		case 3: name += "B"; break;
		case 4: name += "R"; break;
		case 5: name += "Q"; break;
		case 6: name += "K"; break;
		}

		name += (x_start + 'a');
		name += (y_start + '1');
		name += (x_finish + 'a');
		name += (y_finish + '1');
	}
	return name;
}