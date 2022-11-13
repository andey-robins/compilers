#
# Makefile
# Andey Robins
# 11/7/22
# Compilers Program 5
#
# The makefile. It's a makefile.
#
# Primary target: make run
# Other targets: make tar
#

CXX=g++
CXXFLAGS=-ggdb -Wall -Wno-sign-compare
CXXFLAGS_TESTING= -ggdb -Wall -Wno-sign-compare -lboost_unit_test_framework

LEX=flex++
LEXFLAGS=--warn

BISON=bison
BISONFLAGS=-d

#########
# BUILD #
#########

program4: program4.cpp program4_lex.cpp *.cpp
	$(CXX) $(CXXFLAGS) *.cpp -o program4

program4_lex.cpp: program4.lpp program4.tab.cpp
	$(LEX) $(LEXFLAGS) program4.lpp

program4.tab.cpp: program4.ypp
	$(BISON) $(BISONFLAGS) program4.ypp

############
# COMMANDS #
############

bison:
	$(BISON) $(BISONFLAGS) -v program4.ypp

clean:
	/bin/rm -f program4 program4_lex.cpp program4.tab.*
	/bin/rm -f *.output
	/bin/rm -rf *.dSYM
	/bin/rm -f core.*
	/bin/rm -f boost_test
	/bin/rm -f program4.tgz

run: program4
	./program4

test: parser/lib/*.cpp
	$(CXX) $(CXXFLAGS_TESTING) -o boost_test parser/lib/*.cpp
	./boost_test

tar: clean
	tar -zcf program4.tgz Makefile program4.cpp program4.hpp program4.lpp program4.ypp block.* declarations.* expressions.* leaves.* name.* node-base.* nodes.hpp parameters.* statements.* struct.* type.hpp types.cpp