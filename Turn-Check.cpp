#include "Turn.h"
#include "Global-Defines.h"
#include "Check-Defines.h"
#include <algorithm>

bool Board::Turn::subcheck(char x, char y, char kings_x, char kings_y, const Board *board){
	char dx, dy;
	if (x != kings_x) { dx = (x - kings_x) / abs(x - kings_x); } else { dx = 0; }
	if (y != kings_y) { dy = (y - kings_y) / abs(y - kings_y); } else { dy = 0; }

	bool tmp = true;
	for (int i = 1; i < std::max(abs(x - kings_x), abs(y - kings_y)); i++){
		tmp = tmp && (board->board[coords(kings_x + i*dx, kings_y + i*dy)] == VOID);
		if (not(tmp)) return tmp;
	}

	return tmp;
}

bool Board::Turn::isCheck() {
	if (castling != 0) return false;

	char x = x_finish - board->figures[(board->color_turn + 1) / 2][0].x;
	char y = y_finish - board->figures[(board->color_turn + 1) / 2][0].y;

	switch (moved_figure->id) {

	case PAWN: if (board->color_turn == WHITE) {
		return white_pawn_check[check_coords(x, y)];}
	        else {
		      return black_pawn_check[check_coords(x, y)];}

	case KNIGHT: return knight_check[check_coords(x, y)];

	case BISHOP: if (bishop_check[check_coords(x, y)]) {
		char kings_x = board->figures[(board->color_turn + 1) / 2][0].x;
		char kings_y = board->figures[(board->color_turn + 1) / 2][0].y;
		return subcheck(x_finish, y_finish, kings_x, kings_y, board);
	}

	case ROOK: if (rook_check[check_coords(x, y)]) {
		char kings_x = board->figures[(board->color_turn + 1) / 2][0].x;
		char kings_y = board->figures[(board->color_turn + 1) / 2][0].y;
		return subcheck(x_finish, y_finish, kings_x, kings_y, board);
	}

	case QUEEN: if (queen_check[check_coords(x, y)]) {
		char kings_x = board->figures[(board->color_turn + 1) / 2][0].x;
		char kings_y = board->figures[(board->color_turn + 1) / 2][0].y;
		return subcheck(x_finish, y_finish, kings_x, kings_y, board);
	}

	case KING: return king_check[check_coords(x, y)];

	default: return false;
	}
}