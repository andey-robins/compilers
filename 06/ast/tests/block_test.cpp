/*
 * block_test.cpp
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
#include <boost/test/unit_test.hpp>
#include "../include/nodes.hpp"

BOOST_AUTO_TEST_CASE(varDecl)
{
    NId *x = new NId("x");
    NId *y = new NId("y");
    NSimpleType *st = new NSimpleType(x);
    NType *type = new NType(st);
    NVarDecl *decl = new NVarDecl(type, y);

    std::stringstream s;
    decl->print(&s);
    BOOST_CHECK(s.str() == "<vardecs> --> <vardecs> <vardec>\n  <vardec> --> <type> ID SEMI\n    <type> --> ID\n      ID --> x\n    ID --> y\n");
}

BOOST_AUTO_TEST_CASE(localVarDecl)
{
    NId *x = new NId("x");
    NId *y = new NId("y");
    NSimpleType *st = new NSimpleType(x);
    NType *type = new NType(st);
    NVarDecl *decl = new NVarDecl(type, y);
    NLocalVarDecl *local = new NLocalVarDecl(decl);

    std::stringstream s;
    local->print(&s);
    BOOST_CHECK(s.str() == "<localvardec> --> <vardec>\n  <vardecs> --> <vardecs> <vardec>\n    <vardec> --> <type> ID SEMI\n      <type> --> ID\n        ID --> x\n      ID --> y\n");
}

BOOST_AUTO_TEST_CASE(block)
{
    NOptExp *opt = new NOptExp();
    NStateReturn *ret = new NStateReturn(opt);
    NBlock *block = new NBlock(ret);

    std::stringstream s;
    block->print(&s);
    BOOST_CHECK(s.str() == "<block> --> { <localvardecs>* <statements>* }\n  <statement> --> RETURN\n");
}