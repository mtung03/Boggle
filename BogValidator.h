#ifndef BOGVALIDATOR_H
#define BOGVALIDATOR_H

#include <string>

#include "BogBoard.h"
#include "Dictionary.h"

class BogValidator
{
public:
        BogValidator();
        ~BogValidator();
        bool readDict();                // read in a dictionary
        bool readBoard();               // read in a board
        bool isValid(std::string s);    // validates one word
        void checkWords();              // validates cin.  Goes to EOF.

private:
        Dictionary dict;                // must use a Dictionary
        BogBoard board;			// uses BogBoard class
        std::vector<string> inputWords;

        // recursive function checking for one word
        bool checkWord(BogWord current, BogLett next, string final);

        // turns BogWord into a string
        string toString(BogWord word);
};

#endif

