CXX=g++ 
CXXFLAGS=-ggdb -Wall

LEX=flex++
LEXFLAGS=--warn

program2: program2.cpp program2_lex.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) program2.cpp program2_lex.cpp -o build/program2

program2_lex.cpp: program2.lpp
	$(LEX) $(LEXFLAGS) program2.lpp

clean:
	/bin/rm -f program2 program2_lex.cpp core.*
	/bin/rm -rf build
	/bin/rm -rf *.dSYM

run: program2
	./build/program2

tar: program2
	tar -zcf program2.tgz program2.cpp program2.hpp program2.lpp Makefile