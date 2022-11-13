#
# Makefile
# Andey Robins
# 10/20/22
# Compilers Program 4
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
	/bin/rm -rf core.*
	/bin/rm -f program4.tgz

run: program4
	./program4

test: program4
	./program4 < testing/simple.dcaf

tar: clean
	tar -zcf program4.tgz Makefile program4.cpp program4.hpp program4.lpp program4.ypp block.* declarations.* expressions.* leaves.* name.* node-base.* nodes.hpp parameters.* statements.* struct.* type.hpp types.cpp