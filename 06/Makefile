#
# Makefile
# Andey Robins
# 12/2/22
# Compilers Program 6
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
BISONFLAGS=-d -v

#########
# BUILD #
#########

program6: program6.cpp program6_lex.cpp *.cpp $(PARSER_DIR)/*.cpp $(AST_DIR)/*.cpp
	$(CXX) $(CXXFLAGS) *.cpp $(PARSER_DIR)/*.cpp $(AST_DIR)/*.cpp -o program6

program6_lex.cpp: program6.lpp program6.tab.cpp
	$(LEX) $(LEXFLAGS) program6.lpp

program6.tab.cpp: program6.ypp
	$(BISON) $(BISONFLAGS) program6.ypp

############
# COMMANDS #
############

bison:
	$(BISON) $(BISONFLAGS) -v program6.ypp

clean:
	/bin/rm -f program6 program6_lex.cpp program6.tab.*
	/bin/rm -f *.output
	/bin/rm -rf *.dSYM
	/bin/rm -f core.*
	/bin/rm -f boost_test
	/bin/rm -f program6.tgz

test: $(PARSER_DIR)/*.cpp $(AST_DIR)/*.cpp parser/tests/*.cpp  ast/tests/*.cpp ast/tests/integration/*.cpp program6_lex.cpp program6.tab.cpp
	$(CXX) $(CXXFLAGS_TESTING) -o boost_test parser/tests/*.cpp ast/tests/*.cpp $(PARSER_DIR)/*.cpp $(AST_DIR)/*.cpp ast/tests/integration/*.cpp program6.tab.cpp program6_lex.cpp
	./boost_test

build: clean
	mkdir build
	cp program6.* build/
	cp Makefile build/
	cp ast/lib/*.cpp build/
	cp ast/include/*.hpp build/
	cp parser/include/*.hpp build/
	cp parser/lib/*.cpp build/

tar:
	tar -zcf program6.tgz *.cpp *.lpp *.ypp *.hpp