#pragma once

#ifndef BOARD_BOARD_HPP
#define BOARD_BOARD_HPP
#include <iostream>
#include <istream>
#include <initializer_list>
#include <string>
#include "Cell.h"
#include "MyException.h"
#include <fstream>



class Board {

	int i, j;

	int sizeOfBoard;

	Cell **b;



public:

	Board(int n);
	Board();
	Board(const Board& _board);
	~Board();
	

	int size_()const {
		return sizeOfBoard;
	}

	friend std::ostream&operator<<(std::ostream& os, const Board& b);
	friend std::istream & operator>>(std::istream & is, Board & b);
	Cell& operator[](std::initializer_list<int> list);

	void setX(int i) { this->i = i; }

	void setY(int j) { this->j = j; }

	Board&operator=(char c);

	Board&operator=(const Board&another);



};


#endif 


