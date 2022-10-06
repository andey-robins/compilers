#
# Makefile
# Andey Robins
# 10/5/22
# Compilers Program 3
#
# This is the makefile for program 3
#

CXX=g++
CXXFLAGS=-ggdb -Wall

LEX=flex++
LEXFLAGS=--warn

program3: program3.cpp program3_lex.cpp
	$(CXX) $(CXXFLAGS) program3.cpp program3_lex.cpp -o program3

program3_lex.cpp: program3.lpp
	$(LEX) $(LEXFLAGS) program3.lpp

clean:
	/bin/rm -f program3 program3_lex.cpp core.*
	/bin/rm -rf *.dSYM
	/bin/rm program3.tgz

run: program3
	./program3

tar: program3
	tar -zcf program3.tgz program3.cpp program3.hpp program3.lpp program3.y