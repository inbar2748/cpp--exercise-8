#include "Board.h"
using namespace std;
#include <iostream>
#include <istream>
#include <initializer_list>
#include <string>
#include <fstream>

Board::Board() {

}
Board::Board(const Board& _board) {
	sizeOfBoard = _board.sizeOfBoard;
	b = new Cell*[sizeOfBoard];
	for (int i = 0; i < sizeOfBoard; i++)
		b[i] = new Cell[sizeOfBoard];

	for (int i = 0; i < sizeOfBoard; i++) {
		for (int j = 0; j < sizeOfBoard; j++) {
			b[i][j] = _board.b[i][j];
		}
	}
}
Board::Board(int s) {

	this->sizeOfBoard = s;

	b = new Cell*[size_()];

	int i, j;

	for (i = 0; i < size_(); ++i) {

		this->b[i] = new Cell[size_()];

	}

	for (i = 0; i < size_(); ++i) {

		for (j = 0; j <size_(); j++) {

			this->b[i][j].setCell('.');

		}

	}

}



Board::~Board() {

	for (int i = 0; i < size_(); i++) {

		delete[] b[i];
	}
	delete[] b;

}



std::ostream &operator<<(std::ostream &os, const Board &another) {

	for (int i = 0; i < another.size_(); ++i) {

		for (int j = 0; j < another.size_(); ++j) {

			os << another.b[i][j].getCell();

		}

		os << "\n";

	}

	return os;

}







Cell& Board::operator[](std::initializer_list<int> list) {

	int rows = *list.begin();

	int colms = *(list.begin() + 1);

	setX(rows);

	setY(colms);

	if (rows >= (*this).size_() || rows < 0 || colms >= (*this).size_() || colms < 0) {

		IllegalCoordinateException ex;

		ex.set(rows, colms);

		throw ex;

	}





	return this->b[rows][colms];

}







Board &Board::operator=(char p) {

	if (p == 'X' || p == 'O') {

		int i, j;

		for (i = 0; i < size_(); ++i) {

			for (j = 0; j <size_(); j++) {

				b[i][j] = p;

			}

		}

		return *this;

	}

	else if (p == '.') {

		int i, j;

		for (i = 0; i < size_(); ++i) {

			for (j = 0; j <size_(); j++) {

				b[i][j] = '.';

			}

		}

		return *this;

	}





	else {

		IllegalCharException ex;

		ex.setChar(p);

		throw ex;

	}

}



Board &Board::operator=(const Board &another) {

	if ((*this).b == another.b)return (*this);



	if ((*this).size_() != another.size_()) {

		for (int i = 0; i <this->size_(); ++i) {

			delete[] this->b[i];

		}

		delete[] this->b;



		this->sizeOfBoard = another.size_();

		this->b = new Cell*[this->size_()];

		for (int j = 0; j < size_(); ++j) {

			this->b[j] = new Cell[size_()];

		}



		for (int x = 0; x < (*this).size_(); ++x) {

			for (int i = 0; i < (*this).size_(); ++i) {

				this->b[x][i] = another.b[x][i];

			}

		}

	}

	return (*this);





}
std::istream& operator>> (std::istream& is, Board& b) {
	string line;
	is >> line;
	int len = line.length();
	int i = 0;
	Board temp{ (int)line.length() };
	b = temp;
	while (is) {
		cout << i << endl;
		for (int j = 0; j<line.length(); j++) {
			b.b[i][j] = line.at(j);
		}
		i++;
		is >> line;
	}

	return is;

}
