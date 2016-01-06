#include "BogBoard.h"
#include <iostream>
using namespace std;

BogBoard::BogBoard()
{
	boardheight = 0;
	boardwidth = 0;
}

BogBoard::~BogBoard()
{

}

void BogBoard::setWidth(int w)
{
	boardwidth = w;
}

void BogBoard::setHeight(int h)
{
	boardheight = h;
}

bool BogBoard::readIn()
{
	// read and check dimensions
	cin >> boardheight >> boardwidth;

	if (boardheight < 0 || boardwidth < 0) {
		cerr << "Bad dimensions. Please fix." << endl;
		return false;
	}

	string newRow;
	getline(cin,newRow);

	// store board in a vector of BogLetts
	for (int i = 0; i < boardheight; i++) {
		getline(cin, newRow);
		// check row length
		if (boardwidth != int(newRow.length())) {
			cerr << "Bad board. Please fix." << endl;
			return false;
		}
		// add each BogLett to board
		for (int j = 0; j < boardwidth; j++) {
			addOneTile(newRow[j], i , j);
		}
	}
	return true;
}

void BogBoard::addOneTile(char c, int row, int col)
{
	BogLett newTile;
	newTile.c = toupper(c);
	newTile.row = row;
	newTile.col = col;

	board.push_back(newTile);
}

BogLett BogBoard::atIndex(int i)
{
	return board[i];
}

int BogBoard::height()
{
	return boardheight;
}

int BogBoard::width()
{
	return boardwidth;
}
