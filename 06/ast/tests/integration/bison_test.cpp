/*
 * bison_test.cpp
 * Andey Robins
 * 11/14/22
 * Compilers Program 5
 *
 */

#ifndef BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK // only define once (in value_test.cpp)
#endif
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <boost/test/unit_test.hpp>
#include "../../../program5.hpp"
#include <iomanip>
#include <FlexLexer.h>
#include <typeinfo>
#include "../../../program5.tab.hpp"

yyFlexLexer lexer;
BaseNode *ast;
extern int indentation;

BOOST_AUTO_TEST_CASE(trivial)
{
    // std::ifstream codeFile("./ast/tests/integration/files/trivial.dcaf");
    // std::string trivialDcaf((std::istreambuf_iterator<char>(codeFile)),
    //                         (std::istreambuf_iterator<char>()));
    // std::ifstream treeFile("./ast/tests/integration/files/trivial.ast");
    // std::string trivialAst((std::istreambuf_iterator<char>(treeFile)),
    //                        (std::istreambuf_iterator<char>()));

    // std::stringstream s;
    // ast = 0;
    // yyparse();
    // ast->print(&s);
    // std::cout << s.str();
    // std::cout << trivialDcaf;
    // std::cout << trivialAst;
    // BOOST_CHECK(s.str() == trivialAst);
}