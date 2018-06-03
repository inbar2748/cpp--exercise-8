#include "Board.h"
#include "Cell.h"

#include <iostream>
using namespace std;


int main() {
	Board board;
	cin >> board;
	string filename = board.draw(600);
	cout << filename << endl;
	getchar();
}