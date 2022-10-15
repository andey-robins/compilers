#
# Makefile
# Andey Robins
# 10/5/22
# Compilers Program 3
#
# This is the makefile for program 3
#

CXX=g++
CXXFLAGS=-ggdb -Wall -Wno-sign-compare

LEX=flex++
LEXFLAGS=--warn

BISON=bison
BISONFLAGS=-d

program3: program3.cpp program3_lex.cpp nodes/src/*.cpp
	$(CXX) $(CXXFLAGS) program3.cpp program3_lex.cpp program3.tab.cpp nodes/src/*.cpp -o program3

program3_lex.cpp: program3.lpp program3.tab.cpp
	$(LEX) $(LEXFLAGS) program3.lpp

program3.tab.cpp: program3.ypp
	$(BISON) $(BISONFLAGS) program3.ypp

clean:
	/bin/rm -f program3 program3_lex.cpp core.* program3.tab.*
	/bin/rm program3.output 
	/bin/rm -rf *.dSYM
	/bin/rm -f program3.tgz

run: program3
	./program3 < test/test.dcaf

tar: program3
	tar -zcf program3.tgz program3.cpp program3.hpp program3.lpp program3.y