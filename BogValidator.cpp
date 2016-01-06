#include "BogValidator.h"
#include <iostream>
#include <cassert>
using namespace std;

BogValidator::BogValidator()
{
	// constructs
}

BogValidator::~BogValidator()
{
	// destructs
}

bool BogValidator::readDict()
{
	// reads in a dictionary
	string newWord;
	cin >> newWord;
	while (newWord != ".") {
		for (int i = 0; i < int(newWord.length()); i++) {
			newWord[i] = toupper(newWord[i]);
		}
		dict.insert(newWord);
		cin >> newWord;
	}
	return true;
}

bool BogValidator::readBoard()
{
	// reads board
	assert(board.readIn());
	return true;
}

bool BogValidator::isValid( string word )
{
	// checks one word

	// must be more than length 2
	if (word.length() < 3) return false;

	bool found = false;
	// start at every letter, check if there is a word from there
	for (int i = 0; i < (board.width()*board.height()); i++) {
		BogWord newWord;
		if (checkWord(newWord, board.atIndex(i), word)) {
			found = true;
			break;
		}
	}

	// word must be found in the board and be in the dictionary
	return found && dict.isWord(word);
}

BogWord addU(BogWord q_word);

bool BogValidator::checkWord(BogWord current,BogLett next, string final)
{
	current.push_back(next);

	// check if letter is already in the word
	for (size_t i = 0; i < current.size()-1; i++) {
		if (current[i].col == next.col && current[i].row == next.row) {
			return false;
		}
	}
	// add a U with the same coords if the last letter is a Q
	if (next.c == 'Q') current = addU(current);

	// base cases
	if (toString(current) == final) return true;
	if (current.back().c != final[current.size()-1]) return false;

	int w = board.width(); int h = board.height();
	int curr_pos = current.back().row*w + current.back().col;
	// recursively check adjacent cells
	if (!(current.back().row <= 0 || current.back().col <= 0))
		if (checkWord(current, board.atIndex(curr_pos-w-1), final))
			return true;
	if (!(current.back().row <= 0))
		if (checkWord(current, board.atIndex(curr_pos-w), final))
			return true;
	if (!(current.back().row <= 0 || current.back().col >= w-1))
		if (checkWord(current, board.atIndex(curr_pos-w+1), final))
			return true;
	if (!(current.back().col <= 0))
		if (checkWord(current, board.atIndex(curr_pos-1), final))
			return true;
	if (!(current.back().col >= w-1))
		if (checkWord(current, board.atIndex(curr_pos+1), final))
			return true;
	if (!(current.back().row >= h-1 || current.back().col <= 0))
		if (checkWord(current, board.atIndex(curr_pos+w-1), final))
			return true;
	if (!(current.back().row >= h-1))
		if (checkWord(current, board.atIndex(curr_pos+w), final))
			return true;
	if (!(current.back().row >= h-1 || current.back().col >= w-1))
		if (checkWord(current, board.atIndex(curr_pos+w+1), final))
			return true;
	return false;
}

// function automatically adds a U with the same coordinates after a Q in a word
BogWord addU(BogWord q_word)
{
	BogLett tempU;

	tempU.c = 'U';
	tempU.col = q_word.back().col;
	tempU.row = q_word.back().row;
	q_word.push_back(tempU);

	return q_word;
}

void BogValidator::checkWords()
{
	string word;

	// store input in inputWords vector
	while (cin >> word) {
		for (size_t i = 0; i < word.length(); i++) {
			word[i] = toupper(word[i]);
		}
		inputWords.push_back(word);
	}

	// check words in inputWords
	for (size_t i = 0; i < inputWords.size(); i++) {
		bool duplicate = false;

		// check if the word has already been submitted
		for (size_t j = 0; j < i; j++) {
			if (inputWords[i] == inputWords[j]) duplicate = true;
		}
		if (duplicate || !isValid(inputWords[i])) cout << "NO ";
		else cout << "OK ";
		cout << inputWords[i] << endl;
	}
}

std::string BogValidator::toString(BogWord word)
{
	string newWord = "";
	for (size_t i = 0; i < word.size(); i++) {
		newWord += word[i].c;
	}
	return newWord;
}
