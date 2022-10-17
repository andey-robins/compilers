#
# Makefile
# Andey Robins
# 10/1/22
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

program3: program3.cpp program3_lex.cpp *.cpp
	$(CXX) $(CXXFLAGS) *.cpp -o program3

program3_lex.cpp: program3.lpp program3.tab.cpp
	$(LEX) $(LEXFLAGS) program3.lpp

program3.tab.cpp: program3.ypp
	$(BISON) $(BISONFLAGS) program3.ypp

clean:
	/bin/rm -f program3 program3_lex.cpp core.* program3.tab.*
	/bin/rm -f program3.output 
	/bin/rm -rf *.dSYM
	/bin/rm -f program3.tgz

run: program3
	./program3

testexp: program3
	./program3 < test/exp.dcaf

testmisc: program3
	./program3 < test/misc.dcaf

testnew: program3
	./program3 < test/new.dcaf

testdec: program3
	./program3 < test/vdec.dcaf

tar: program3
	tar -zcf program3.tgz Makefile program3.cpp program3.hpp program3.lpp program3.ypp expressions.* leaves.* node.* nodes.hpp struct.* types.* vars.* wrapper.*