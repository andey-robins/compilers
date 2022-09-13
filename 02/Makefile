CXX=g++ 
CXXFLAGS=-ggdb -Wall -Wno-sign-compare

LEX=flex++
LEXFLAGS=--warn

program2: program2.cpp program2_lex.cpp
	$(CXX) $(CXXFLAGS) program2.cpp program2_lex.cpp -o program2

program2_lex.cpp: program2.lpp
	$(LEX) $(LEXFLAGS) program2.lpp

clean:
	/bin/rm -f program2 program2_lex.cpp core.*
	/bin/rm -rf *.dSYM

run: program2
	./program2

tar: program2
	tar -zcf program2.tgz program2.cpp program2.hpp program2.lpp Makefile