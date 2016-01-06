#ifndef BOGSCORER_H
#define BOGSCORER_H

#include <iostream>
using namespace std;

// Class for scoring the boggle game
//
//   Reads in from the validator's input from cin in the format:
//	[OK/NO] [WORD]
//
//   Output format:
//	[score] [OK/NO] [WORD]

class BogScorer
{
    public:
	BogScorer();
	~BogScorer();
	void scoreAnswers(); // reads from cin and prints scores
    private:
	static const string GOOD_WORD;
	static const string BAD_WORD;
	int score;
	int validWords;
	int findScore(int length);	// finds score for one word
};
#endif
