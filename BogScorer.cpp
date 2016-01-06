#include "BogScorer.h"
#include <iostream>
#include <string>
using namespace std;

// Use constants for checking validator output
const string BogScorer::GOOD_WORD = "OK";
const string BogScorer::BAD_WORD = "NO";

BogScorer::BogScorer()
{
	score = 0;
	validWords = 0;

}

BogScorer::~BogScorer()
{

}

void BogScorer::scoreAnswers()
{
	// reads answers
	string valid, word;
	while (cin >> valid >> word) {
		if (valid == GOOD_WORD) {
			// uses standard boggle scoring
			int wordScore = findScore(int(word.length()));
			cout << wordScore << " " << GOOD_WORD;
			score += wordScore;
			validWords++;
		}
		else {
			cout << 0 << " " << BAD_WORD;
		}
		cout << " " << word << endl;
	}

	// display totals
	cout << validWords << " words " << score << " points" << endl;
}

int BogScorer::findScore(int length)
{
	// Uses standard Boggle scoring rubric as dictated by Wikipedia
	if (length < 5) return 1;
	else if (length < 6) return 2;
	else if (length < 7) return 3;
	else if (length < 8) return 5;
	else return 11;
}
