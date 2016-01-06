#ifndef BOGBOARD_H
#define BOGBOARD_H

#include "BogWordList.h"
#include <vector>

// Class storing a Boggleboard
// Helps with modularity + code reuse

class BogBoard
{
public:
	BogBoard();
	~BogBoard();
	void setWidth(int width);
	void setHeight(int height);
	bool readIn();		// reads dimensions and board from cin
	BogLett atIndex(int i);
	int height();
	int width();
	
private:
	std::vector<BogLett> board;	// store BogLetts in a 1D vector
	int boardheight;
	int boardwidth;
	void addOneTile(char c, int row, int col); //adds a BogLett to the board
};

#endif
	
