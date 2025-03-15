#pragma once

constexpr auto WHITE = (char)1;
constexpr auto BLACK = (char)-1;

constexpr auto KING = (char)6;
constexpr auto QUEEN = (char)5;
constexpr auto ROOK = (char)4;
constexpr auto BISHOP = (char)3;
constexpr auto KNIGHT = (char)2;
constexpr auto PAWN = (char)1;
constexpr auto VOID = (char)0;
constexpr auto KING_NM = (char)16; //not moved;
constexpr auto ROOK_NM = (char)14; //not moved;
constexpr auto OUTSIDE = (char)42;

constexpr auto SHORT_CASTLING = 1;
constexpr auto LONG_CASTLING = 2;

constexpr auto NUMBER_OF_FIGURES = 16;

//#define coords(x, y) ((9 - y) * 12 + x + 2)

inline int coords(char x, char y){
	return (9 - (int)y) * 12 + (int)x + 2;
}