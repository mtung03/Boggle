#include <iostream>

#include "BogValidator.h"
#include "BogBoard.h"

using namespace std;

int main()
{
        BogValidator v;

        v.readDict();
        v.readBoard();
        v.checkWords();

        return 0;
}
