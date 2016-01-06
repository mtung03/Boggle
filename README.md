# Boggle
Solving and Scoring a Boggle game

This Repo contatains the functions written as part of my Data Structures course
to solve a Boggle game, as well as check and score user inputs. Specific 
information regarding board and dictionary inputs can be found in the documentation
of the header files for the relevant classes. Currently my functions run on the 
back-end behind the interface built by the course administrators at this website:
https://www.cs.tufts.edu/~mtung01/bog15/

<h5>Purpose:</h5> To create a fully-functioning, playable Boggle game that properly 
	 integrates with the website interface provided for us.

<h5>Brief listing of files:</h5>
  Makefile 		      ReadMe.md 
	solverMain.cpp		checkerMain.cpp 	scorerMain.cpp
	BogSolver.h		    BogSolver.cpp
	BogValidator.h		BogValidator.cpp
	BogScorer.h		    BogScorer.cpp
	BogBoard.h		    BogBoard.cpp
	Dictionary.h		  Dictionary.cpp		Node.h    Node.cpp
	BogWordList.h

<h5>Detailed list of relevant files and classes:</h5>

solverMain.cpp, checkerMain.cpp, scorerMain.cpp: 
<p> 	- Contains "client code" that runs the core functions in the classes</p>
	
//************** BogSolver class (BogSolver.h, BogSolver.cpp) ****************//
<p>	- Class' primary function is to read in a dictionary of words and a 
	  Boggle board, and find all the possible words in the board </p>
<p>	- Uses an instance of the Dictionary class to store the dictionary</p>
<p>	- Uses an instance of the BogBoard class to store the board</p>
<p>	- Stores the found words in a heap-allocate instance of a BogWordList</p>
<p>	- Stores the found words without duplicates in a set of strings</p>
<p>	- The core function in this class is the solve() function, which calls
	  the private recursive function findWord(). This function gets passed 
	  a BogWord and the next letter to be added; it then checks if it has 
	  created word and if it is a prefix of a word before recursively calling
	  itself for all adjacent cells.</p>
<p>	- The callstack created by the recursion in the findWord function allows
	  for easy backtracking when a word is no longer possible with the 
	  letters at that time</p>
	  
<p>Notes on some choices made in this class:</p>
<p>	- When reading in the board, the BogBoard class returns false if the 
	  dimensions of the board are illegal or the board does not match. In 
	  the BogSolver class, the choice was made to use an assertion (as 
	  opposed to throwing an exception or letting the program segfault) to 
	  check these properties of the board.</p>
<p>	- For the getWords() function(s), the heap-allocated BogWordList that 
	  was passed back includes BogWords that have the same chars but with 
	  different paths. While the assignment document dictates that thesse 
	  should exclude duplicates, I interpreted BogWords with the same word
	  but different paths as different BogWords instead of duplicates </p>

<p>//******** BogValidator class (BogValidator.h, BogValidator.cpp) *************//</p>
<p>	- Class' general purpose is to read in a dictionary, Boggle board, and
	  a list of user inputs, and to determine which of the user inputs are 
	  valid.</p>
<p>	- Instance of Dictionary class used for the dictionary of valid words</p>
<p>	- Instance of BogBoard class used to store Boggle Board</p>
<p>	- Vector of strings used to store the user's inputted words</p>
<p>	- CheckWords() function loops through the list of user words and calls 
	  isValid() for each one</p>
<p>	- isValid uses a similar recursive algorithm as used in the BogSolver 
	  class, but checks if an individual word is possible instead of looking
	  for all words. Additionally, isValid must check if that word is also
	  in the dictionary.</p>
<p>Other notes:</p>
<p>	- Allows for first instance of a word, but reads any subsequent 
	  duplicate as invalid</p>
	  
<p>//************** BogScorer class (BogScorer.h, BogScorer.cpp) ****************//</p>
<p>	- Class reads in the output from the BogValidator class and adds up the 
	  scores from each word.</p>
<p>	- Scoring rubric from Boggle wikipedia page is as follows:
		Letters  |  Score
		  0-2	      0
		  3-4	      1
		   5	      2
		   6	      3
		   7 	      5
		   8+	      11</p>
<p>	- Also prints number of words found</p>
	
<p>//************** BogBoard class (BogBoard.h, BogBoard.cpp) ****************//</p>
<p>	- Class that stores a Boggle Board of any (positive integer) dimensions</p>
<p>	- Created to help with code re-use between the solver and validator 
	  classes</p>
<p>	- Stores the board in a 1D vector of BogLetts</p>
	
<p>//************** Dictionary class (Dictionary.h, Dictionary.cpp) ****************//</p>
<p>	- Dictionary class provided to us stores a dictionary of words in a trie</p>
<p>	- Uses the Node class for each node in the trie</p>
<p>	- Interface includes insert(), isPrefix(), and isWord() functions</p>
	
<p>//********************* Node class (Node.h, Node.cpp) *************************//</p>
<p>	- Contains a standard trie node</p>
<p>	- Code provided for us by instructors</p>
	
<p>//*************************** BogWordList.h ***********************************//</p>
<p>	- Code provided to us</p>
<p>	- Defines three useful types
<p>		- Struct BogLett, containing a char and ints for its coordinates
		- BogWord, vector of BogLetts
		- BogWordList, vector of BogWords
		</p>
		
		
<p>Program compiles together or in separate parts using the included Makefile</p>
