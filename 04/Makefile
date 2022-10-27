#
# Makefile
# Andey Robins
# 10/20/22
# Compilers Program 4
#
# The makefile. It's a makefile.
#
# Primary target: make run
# Other targets: make tar
#

CXX=g++
CXXFLAGS=-ggdb -Wall -Wno-sign-compare

LEX=flex++
LEXFLAGS=--warn

BISON=bison
BISONFLAGS=-d

program4: program4.cpp program4_lex.cpp nodes/src/*.cpp
	$(CXX) $(CXXFLAGS) *.cpp nodes/src/*.cpp -o program4

program4_lex.cpp: program4.lpp program4.tab.cpp
	$(LEX) $(LEXFLAGS) program4.lpp

program4.tab.cpp: program4.ypp
	$(BISON) $(BISONFLAGS) program4.ypp

clean:
	/bin/rm -f program4 program4_lex.cpp program4.tab.*
	/bin/rm -f *.output
	/bin/rm -rf *.dSYM
	/bin/rm core.*
	/bin/rm -f program4.tgz

run: program4
	./program4

tar: program4
	tar -zcf program4.tgz Makefile program4.cpp program4.hpp program4.lpp program4.ypp nodes/*