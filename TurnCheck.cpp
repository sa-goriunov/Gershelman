#include "Turn.h"
#include "GlobalDefines.h"
#include "CheckDefines.h"

bool subcheck_bishop(char x, char y, char kings_x, char kings_y, Board *board){
	return false;
}

bool subcheck_rook(char x, char y, char kings_x, char kings_y, Board* board) {
	return false;
}

bool Board::Turn::check() {

	char x = x_finish - board->figures[(-board->color_turn + 1) / 2][0].x;
	char y = y_finish - board->figures[(-board->color_turn + 1) / 2][0].y;

	switch (moved_figure->id) {

	case PAWN: if (-board->color_turn == WHITE) {
		      return white_pawn_check[KING_POSITION + x - y*15];}
	        else {
		      return black_pawn_check[KING_POSITION + x - y * 15];}

	case KNIGHT: return knight_check[KING_POSITION + x - y * 15];

	case BISHOP: if (bishop_check[KING_POSITION + x - y * 15]) {
		char kings_x = board->figures[(-board->color_turn + 1) / 2][0].x;
		char kings_y = board->figures[(-board->color_turn + 1) / 2][0].y;
		return subcheck_bishop(x_finish, y_finish, kings_x, kings_y, board);
	}

	case ROOK: if (rook_check[KING_POSITION + x - y * 15]) {
		char kings_x = board->figures[(-board->color_turn + 1) / 2][0].x;
		char kings_y = board->figures[(-board->color_turn + 1) / 2][0].y;
		return subcheck_rook(x_finish, y_finish, kings_x, kings_y, board);
	}

	case QUEEN: if (queen_check[KING_POSITION + x - y * 15]) {
		char kings_x = board->figures[(-board->color_turn + 1) / 2][0].x;
		char kings_y = board->figures[(-board->color_turn + 1) / 2][0].y;
		return (subcheck_bishop(x_finish, y_finish, kings_x, kings_y, board)) 
			or (subcheck_rook(x_finish, y_finish, kings_x, kings_y, board));
	}

	case KING: return king_check[KING_POSITION + x - y * 15];

	default: return false;
	}
}