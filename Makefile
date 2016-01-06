#
# Makefile for Boggle, hw6
#
CXX      = clang++
CXXFLAGS = -O0 -Wall -Wextra -g

all: scorerMain.cpp solverMain.cpp checkerMain.cpp  \
	BogScorer.cpp BogScorer.h                   \
	BogSolver.cpp BogSolver.h                   \
	BogValidator.cpp BogValidator.h             \
	Dictionary.h Dictionary.cpp Node.h Node.cpp \
	BogBoard.cpp BogBoard.h			    \

	${CXX} ${CXXFLAGS} -o bbscorer BogScorer.cpp scorerMain.cpp
	${CXX} ${CXXFLAGS} -o bbsolver BogSolver.cpp solverMain.cpp \
				Dictionary.cpp Node.cpp BogBoard.cpp
	${CXX} ${CXXFLAGS} -o bbchecker BogValidator.cpp checkerMain.cpp \
				Dictionary.cpp Node.cpp BogBoard.cpp

bbscorer: scorerMain.cpp BogScorer.cpp BogScorer.h 
	${CXX} ${CXXFLAGS} -o bbscorer BogScorer.cpp scorerMain.cpp

bbsolver: solverMain.cpp BogSolver.cpp BogSolver.h
	${CXX} ${CXXFLAGS} -o bbsolver BogSolver.cpp \
				Dictionary.cpp Node.cpp BogBoard.cpp solverMain.cpp\

bbchecker: checkerMain.cpp BogValidator.cpp BogValidator.h BogBoard.h BogBoard.cpp Dictionary.h Dictionary.cpp Node.h Node.cpp
	${CXX} ${CXXFLAGS} -o bbchecker BogValidator.cpp checkerMain.cpp BogBoard.cpp Dictionary.cpp Node.cpp

clean:
	rm -f bbscorer bbsolver bbchecker 

make provide:
	provide comp15 hw6 scorerMain.cpp solverMain.cpp checkerMain.cpp \
		BogScorer.cpp BogScorer.h \
		BogSolver.cpp BogSolver.h \
		BogValidator.cpp BogValidator.h \
		BogBoard.cpp BogBoard.h \
		Dictionary.h Dictionary.cpp Node.h Node.cpp \
		BogWordList.h \
	        ReadMe.md Makefile

