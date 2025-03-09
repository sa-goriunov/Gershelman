#include "Board.h"
#include "Turn.h"
#include "Defines.h"

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

		if ((moved_figure->id == 1) && (((y_start == 1) && (y_finish == 3)) || ((y_start == 6) && (y_finish == 4)))) en_passant = x_finish;

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
	} else if ((moved_figure->id == PAWN) && (x_start != x_finish) && (finish_id == VOID)) {
		for (int i = 8; i < NUMBER_OF_FIGURES; i++) {
			Figure* tmp = &board->figures[(board->color_turn + 1) / 2][i];
			if ((x_finish == tmp->x) && ((y_finish - 1) == tmp->y) && (tmp->enabled)) {
				return tmp;
			}}
	}
	else { return NULL; }

	return NULL;
}

void Board::Turn::operator()() {
	switch (castling) {
	case 1: if (board->color_turn == WHITE) {
		board->board[114] = VOID;
		board->board[116] = KING;
		board->board[117] = VOID;
		board->board[115] = ROOK;
		board->figures[0][0].x += 2;
		board->figures[0][3].x -= 2;
	}
		  else {
		board->board[30] = VOID;
		board->board[32] = BLACK*KING;
		board->board[33] = VOID;
		board->board[31] = BLACK*ROOK;
		board->figures[1][0].x += 2;
		board->figures[1][3].x -= 2;
	}
		  break;
	case 2: if (board->color_turn == WHITE) {
		board->board[114] = VOID;
		board->board[112] = KING;
		board->board[110] = VOID;
		board->board[113] = ROOK;
		board->figures[0][0].x -= 2;
		board->figures[0][2].x += 3;
	}
		  else {
		board->board[30] = VOID;
		board->board[28] = BLACK*KING;
		board->board[26] = VOID;
		board->board[29] = BLACK*KING;
		board->figures[1][0].x -= 2;
		board->figures[1][2].x += 3;
	}
		  break;
	default:

		board->board[(9 - y_start) * 12 + 2 + x_start] = VOID;
		moved_figure->x = x_finish; moved_figure->y = y_finish;
		if (eaten_figure != NULL) {
			board->board[(9 - eaten_figure->y) * 12 + 2 + eaten_figure->x] = VOID;
			eaten_figure->enabled = false;
		}
		board->board[(9 - y_finish) * 12 + 2 + x_finish] = (board->color_turn * moved_figure->id);
	}

	board->color_turn *= (-1);
}

void Board::Turn::unmake() {
	board->color_turn *= (char)(-1);

	switch (castling) {
	case 1: if (board->color_turn == WHITE) {
		board->board[117] = ROOK_NM;
		board->board[116] = VOID;
		board->board[114] = KING_NM;
		board->board[115] = VOID;
		board->figures[0][0].x -= 2;
		board->figures[0][3].x += 2;
	}
		  else {
		board->board[33] = BLACK*ROOK_NM;
		board->board[32] = VOID;
		board->board[30] = BLACK*KING_NM;
		board->board[31] = VOID;
		board->figures[1][0].x -= 2;
		board->figures[1][3].x += 2;
	}
		  break;
	case 2: if (board->color_turn == WHITE) {
		board->board[114] = KING_NM;
		board->board[112] = VOID;
		board->board[110] = ROOK_NM;
		board->board[113] = VOID;
		board->figures[0][0].x += 2;
		board->figures[0][2].x -= 3;
	}
		  else {
		board->board[30] = BLACK*KING_NM;
		board->board[28] = VOID;
		board->board[26] = BLACK*ROOK_NM;
		board->board[29] = VOID;
		board->figures[1][0].x += 2;
		board->figures[1][2].x -= 3;
	}
		  break;
	default:

		board->board[(9 - y_start) * 12 + 2 + x_start] = moved_figure_id;
		moved_figure->x = x_start; moved_figure->y = y_start;
		if (eaten_figure != NULL) {
			board->board[(9 - eaten_figure->y) * 12 + 2 + eaten_figure->x] = (char)(-board->color_turn * eaten_figure->id);
			eaten_figure->enabled = true;
		}
		board->board[(9 - y_finish) * 12 + 2 + x_finish] = finish_id;
	}
}

bool Board::Turn::check() {
	return false;
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