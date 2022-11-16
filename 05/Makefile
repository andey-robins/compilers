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

PARSER_DIR=parser/lib
AST_DIR=ast/lib

LEX=flex++
LEXFLAGS=--warn

BISON=bison
BISONFLAGS=-d

#########
# BUILD #
#########

program5: program5.cpp program5_lex.cpp *.cpp $(PARSER_DIR)/*.cpp $(AST_DIR)/*.cpp
	$(CXX) $(CXXFLAGS) *.cpp $(PARSER_DIR)/*.cpp $(AST_DIR)/*.cpp -o program5

program5_lex.cpp: program5.lpp program5.tab.cpp
	$(LEX) $(LEXFLAGS) program5.lpp

program5.tab.cpp: program5.ypp
	$(BISON) $(BISONFLAGS) program5.ypp

############
# COMMANDS #
############

bison:
	$(BISON) $(BISONFLAGS) -v program5.ypp

clean:
	/bin/rm -f program5 program5_lex.cpp program5.tab.*
	/bin/rm -f *.output
	/bin/rm -rf *.dSYM
	/bin/rm -f core.*
	/bin/rm -f boost_test
	/bin/rm -f program5.tgz

run: program5
	./program5 < testfiles/1_class.decaf

test: $(PARSER_DIR)/*.cpp $(AST_DIR)/*.cpp parser/tests/*.cpp  ast/tests/*.cpp ast/tests/integration/*.cpp program5_lex.cpp program5.tab.cpp
	$(CXX) $(CXXFLAGS_TESTING) -o boost_test parser/tests/*.cpp ast/tests/*.cpp $(PARSER_DIR)/*.cpp $(AST_DIR)/*.cpp ast/tests/integration/*.cpp program5.tab.cpp program5_lex.cpp
	./boost_test

tar: clean
	tar -zcf program5.tgz Makefile program5.cpp program5.hpp program5.lpp program5.ypp ast/lib/*.cpp ast/include/*.hpp parser/include/*.hpp parser/lib/*.cpp