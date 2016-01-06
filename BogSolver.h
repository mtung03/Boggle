#ifndef BOGSOLVER_H
#define BOGSOLVER_H

#include "BogWordList.h"
#include "BogBoard.h"
#include "Dictionary.h"
#include <set>

//
// A class to solve boggle puzzles
//  The class reads in a dictionary and a board
//  Then solves it.
//  Once it has solved it, the solver can be
//  asked for the words it found, can be asked to print the words
//  with their locations, and to print the words just as strings
//

class BogSolver
{
    public:
        BogSolver();
        ~BogSolver();
        bool readDict();
        bool readBoard();
        bool solve();                   // search board for words in dict
        int  numWords();                // returns number of words found
        int  numWords(int len);         // number of words of length len

        // These two functions create new heap-allocated BogWordLists
        // which MUST be dealt with and properly freed by the CLIENT
        BogWordList *getWords();        // returns all words found
        BogWordList *getWords(int len); // returns words of length len

        void printWords();              // print all words in HBF
        void printWords(int len);       // print len-length words in HBF
        void listWords();               // print just the text, no coords
        void listWords(int len);        // just the text, no coords

   private:
        Dictionary dict;                // must use a Dictionary
        BogBoard board;			// array storing the boggle board
        int boardWidth;
        int boardHeight;
        BogWordList *foundWords;	// valid words found in the board
        set<string> wordSet;		// valid words without duplicates

        void findWord(BogWord current, BogLett next);// recursive function that
        					     // searches the  board for
        					     // words and calls addWord

        bool addWord(BogWord word);	    // add word to foundWords


        void printoneWord(BogWord word);    // print bogword using HBF
        std::string toString(BogWord word); // function that converts a bogword
        				    // to a string

        // deep copies of BogWordLists
        BogWordList *copyList();
        BogWordList *copyLenList(int len);
};
#endif
