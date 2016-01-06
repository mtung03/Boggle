#include "BogSolver.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

BogSolver::BogSolver()
{
	foundWords = new BogWordList;
}

BogSolver::~BogSolver()
{
	delete foundWords;
}

bool BogSolver::readDict()
{
	string newWord;
	cin >> newWord;

	// reads dict from cin until '.'
	while (newWord != ".") {
		for (int i = 0; i < int(newWord.length()); i++) {
			newWord[i] = toupper(newWord[i]);
		}
		dict.insert(newWord);
		cin >> newWord;
	}

	return true;
}

bool BogSolver::readBoard()
{
	assert(board.readIn()); // make sure board is valid

	boardWidth = board.width();
	boardHeight = board.height();
	return true;
}

bool BogSolver::solve()
{
	// start at each letter and see if there are any words from there
	for (int i = 0; i < boardWidth*boardHeight; i++) {
		BogWord newWord;
		findWord(newWord, board.atIndex(i));
	}

	return true;
}

void BogSolver::findWord(BogWord current, BogLett next)
{
	current.push_back(next);
	string word = toString(current);
	int curr_pos = current.back().row*boardWidth+current.back().col;

	// check first base case: return if current is not the start of a word
	if (!dict.isPrefix(word)) return;
	// second base case: if the letter is already in the word
	for (size_t i = 0; i < current.size()-1; i++) {
		if (current[i].col == next.col && current[i].row == next.row) {
			return;
		}
	}
	// add if a word is found
	if (dict.isWord(word)) addWord(current);
	// recurse and check the adjacent cells
	if (!(current.back().row <= 0 || current.back().col <= 0))
		findWord(current, board.atIndex(curr_pos-boardWidth-1));
	if (!(current.back().row <= 0))
		findWord(current, board.atIndex(curr_pos-boardWidth));
	if (!(current.back().row <= 0 || current.back().col >= boardWidth-1))
		findWord(current, board.atIndex(curr_pos-boardWidth+1));
	if (!(current.back().col <= 0))
		findWord(current, board.atIndex(curr_pos-1));
	if (!(current.back().col >= boardWidth-1))
		findWord(current, board.atIndex(curr_pos+1));
	if (!(current.back().row >= boardHeight-1 || current.back().col <= 0))
		findWord(current, board.atIndex(curr_pos+boardWidth-1));
	if (!(current.back().row >= boardHeight-1))
		findWord(current, board.atIndex(curr_pos+boardWidth));
	if (!(current.back().row >= boardHeight-1 || current.back().col >= boardWidth-1))
		findWord(current, board.atIndex(curr_pos+boardWidth+1));
}

bool BogSolver::addWord(BogWord word)
{
	int wordSize = word.size();

	// add one to the size if there is a Q in the word (implied U)
	for (size_t i = 0; i < word.size(); i++) {
		if (word[i].c == 'Q') wordSize++;
	}

	// add word to storage if it is larger than length 2
	if (wordSize > 2) {
		foundWords->push_back(word);
		wordSet.insert(toString(word));
		return true;
	}
	else return false;
}

int BogSolver::numWords()
{
	return wordSet.size();
}

int BogSolver::numWords(int len)
{
	int num = 0;

	// how to iterate over a set was looked up on cplusplus.com
	for (set<string> ::iterator i = wordSet.begin(); i != wordSet.end(); i++) {
		if (int(i->length()) == len) num++;
	}
	return num;
}

BogWordList *BogSolver::getWords()
{
	BogWordList *clientlist = copyList(); // create a new list to pass
			       	  	      // to the client
	return clientlist;
}

BogWordList *BogSolver::getWords(int len)
{
	BogWordList *clientLenList = copyLenList(len);

	return clientLenList;
}

void BogSolver::printWords()
{
	for (size_t i = 0; i < foundWords->size(); i++) {
		printoneWord((*foundWords)[i]);
	}
	cout << "< >" << endl;
	// prints words in HBF
}

void BogSolver::printWords(int len)
{
	bool hasQ = false; // if a Q is in the word, account for the U in length

	for (size_t i = 0; i < foundWords->size(); i++) {
		hasQ = false;

		// looks for a q
		for (size_t j = 0; j < (*foundWords)[i].size();j++) {
			if ((*foundWords)[i][j].c == 'Q') hasQ = true;
		}

		// prints if length matches
		if (hasQ && int((*foundWords)[i].size() + 1) == len) {
			printoneWord((*foundWords)[i]);
		}
		else if (!hasQ && int((*foundWords)[i].size()) == len) {
			printoneWord((*foundWords)[i]);
		}
	}
	cout << "< >" << endl;
}

void BogSolver::printoneWord(BogWord word)
{
	cout << "< ";
	for (size_t i = 0; i < word.size(); i++) {
		cout << word[i].c;
		if (word[i].c == 'Q') cout << 'U';
		cout << " " << word[i].row << " ";
		cout << word[i].col << " ";
	}
	cout << ">" << endl;
}


void BogSolver::listWords()
{
	// plaintext print excluding duplicates
	// print from wordSet data member

	for (set<string> ::iterator i = wordSet.begin(); i != wordSet.end(); i++) {
		cout << *i << endl;
	}
}

void BogSolver::listWords(int len)
{
	// print words of length len without duplicates
	// use wordSet again

	for (set<string> ::iterator i = wordSet.begin(); i != wordSet.end(); i++) {
		if (int(i->length()) == len) cout << *i << endl;
	}
}

string BogSolver::toString(BogWord word)
{
	string toReturn = "";
	for (size_t i = 0; i < word.size(); i++) {
		toReturn += word[i].c;
		if (word[i].c == 'Q') toReturn += 'U';
	}
	return toReturn;
}

BogWordList *BogSolver::copyList()
{
	// creates new BogWordList in the heap to give client
	// CLIENT is responsible for freeing memory
	BogWordList *clientList = new BogWordList;

	// deep copy
	for (size_t i = 0; i < foundWords->size(); i++) {
		BogWord new_word;
		for (size_t j = 0; j < (*foundWords)[i].size(); j++) {
			new_word.push_back((*foundWords)[i][j]);
		}
		clientList->push_back(new_word);
	}

	return clientList;
}

BogWordList *BogSolver::copyLenList(int len)
{
	BogWordList *clientList = new BogWordList;

	for (size_t i = 0; i < foundWords->size(); i++) {
		size_t wordSize = (*foundWords)[i].size();

		// look for a q in the word
		for (size_t k = 0; k < (*foundWords)[i].size(); k++) {
			// add one the the size of the word if it has a Q
			if ((*foundWords)[i][k].c == 'Q') wordSize++;
		}
		if (wordSize == size_t(len)) {
			BogWord new_word;
			for (size_t j = 0; j < (*foundWords)[i].size(); j++) {
				new_word.push_back((*foundWords)[i][j]);
			}
			clientList->push_back(new_word);
		}
	}
	return clientList;
}
