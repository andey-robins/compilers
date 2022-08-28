#include "token.hpp"

#ifndef PROGRAM1_HPP
#define PROGRAM1_HPP

extern std::string type;
extern int token;

void printTokenLine(int line_no, int col_no, std::string type, int length, std::string token);
int getNextColumn(TOKEN token, std::string tok_str, int col_no);

#endif