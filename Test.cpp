#include "Board.h"
#include "Game.h"
#include "Turn.h"
#include <iostream>
#include <string>
#include <deque>
using namespace std;

void Board::printTest() {
	
	for(int i = 2; i<10; i++){
		for (int j = 2; j < 10; j++)
		{
			cout.width(3); cout << (int)board[i * 12 + j] << " ";
		}
		cout << endl;
	}
}

int main() {
	Game a;
	a.__board__->printTest();
	deque<Board::Turn> history;

	for (int i = 0; i < 6; i++) {
		string hod;
		cin >> hod;
		Board::Turn t(hod, a.__board__);
		t();
		history.push_front(t);
		a.__board__->printTest();
		cout << endl;
		cout << t.check() << endl;
	}

	for (auto i : history) {
		i.unmake();
		a.__board__->printTest();
		cout << endl;
	}

	return 0;
}