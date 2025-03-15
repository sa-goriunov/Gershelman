#include "Turn.h"
#include "Global-Defines.h"

void Board::Turn::operator()() {
	switch (castling) {
	case SHORT_CASTLING: 
		if (board->color_turn == WHITE) {
			board->board[114] = VOID;
			board->board[116] = KING;
			board->board[117] = VOID;
			board->board[115] = ROOK;
			board->chessmen[0][0].x += 2;
			board->chessmen[0][3].x -= 2;
		}
		else {
			board->board[30] = VOID;
			board->board[32] = BLACK * KING;
			board->board[33] = VOID;
			board->board[31] = BLACK * ROOK;
			board->chessmen[1][0].x += 2;
			board->chessmen[1][3].x -= 2;
		}
		break;
	case LONG_CASTLING: 
		if (board->color_turn == WHITE) {
			board->board[114] = VOID;
			board->board[112] = KING;
			board->board[110] = VOID;
			board->board[113] = ROOK;
			board->chessmen[0][0].x -= 2;
			board->chessmen[0][2].x += 3;
		}
		else {
			board->board[30] = VOID;
			board->board[28] = BLACK * KING;
			board->board[26] = VOID;
			board->board[29] = BLACK * KING;
			board->chessmen[1][0].x -= 2;
			board->chessmen[1][2].x += 3;
		}
		break;
	default:

		board->board[coords(x_start, y_start)] = VOID;
		moved_chessman->x = x_finish; moved_chessman->y = y_finish;
		if (promotion != 0) {
			moved_chessman->id = promotion;
		}
		if (eaten_chessman != nullptr) {
			board->board[coords(eaten_chessman->x, eaten_chessman->y)] = VOID;
			eaten_chessman->enabled = false;
		}
		board->board[coords(x_finish, y_finish)] = (board->color_turn * moved_chessman->id);
	}

	board->color_turn *= (-1);
}

void Board::Turn::unmake() {
	board->color_turn *= (char)(-1);

	switch (castling) {
	case SHORT_CASTLING: 
		if (board->color_turn == WHITE) {
			board->board[117] = ROOK_NM;
			board->board[116] = VOID;
			board->board[114] = KING_NM;
			board->board[115] = VOID;
			board->chessmen[0][0].x -= 2;
			board->chessmen[0][3].x += 2;
		}
		else {
			board->board[33] = BLACK * ROOK_NM;
			board->board[32] = VOID;
			board->board[30] = BLACK * KING_NM;
			board->board[31] = VOID;
			board->chessmen[1][0].x -= 2;
			board->chessmen[1][3].x += 2;
		}
		break;
	case LONG_CASTLING: 
		if (board->color_turn == WHITE) {
			board->board[114] = KING_NM;
			board->board[112] = VOID;
			board->board[110] = ROOK_NM;
			board->board[113] = VOID;
			board->chessmen[0][0].x += 2;
			board->chessmen[0][2].x -= 3;
		}
		else {
			board->board[30] = BLACK * KING_NM;
			board->board[28] = VOID;
			board->board[26] = BLACK * ROOK_NM;
			board->board[29] = VOID;
			board->chessmen[1][0].x += 2;
			board->chessmen[1][2].x -= 3;
		}
		break;
	default:

		if (promotion != 0) {
			moved_chessman->id = PAWN;
		}
		board->board[coords(x_start, y_start)] = moved_chessman_id;
		moved_chessman->x = x_start; moved_chessman->y = y_start;
		if (eaten_chessman != nullptr) {
			board->board[coords(eaten_chessman->x, eaten_chessman->y)] = (char)(-board->color_turn * eaten_chessman->id);
			eaten_chessman->enabled = true;
		}
		board->board[coords(x_finish, y_finish)] = finish_id;
	}
}