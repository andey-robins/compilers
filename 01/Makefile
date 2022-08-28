CXX=g++ 
CXXFLAGS=-ggdb -Wall

LEX=flex++
LEXFLAGS=--warn


program1: program1.cpp token.cpp program1_lex.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) program1.cpp token.cpp program1_lex.cpp -o build/program1

program1_lex.cpp: program1.lpp
	$(LEX) $(LEXFLAGS) program1.lpp

clean: 
	/bin/rm -f program1 program1_lex.cpp core.* 
	/bin/rm -rf build
	/bin/rm -rf *.dSYM

run: program1
	./build/program1

test: program1
	cat tests/test1.txt | ./build/program1
	cat tests/test2.txt | ./build/program1