CXX=g++ 
CXXFLAGS=-ggdb -Wall

LEX=flex++
LEXFLAGS=--warn


program1: program1.cpp program1_lex.cpp
	$(CXX) $(CXXFLAGS) program1.cpp program1_lex.cpp -o sample

program1_lex.cpp: program1.lpp
	$(LEX) $(LEXFLAGS) program1.lpp

clean: 
	/bin/rm -f sample sample_lex.cpp core.* 
