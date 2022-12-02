/*
 * declaration_test.cpp
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

BOOST_AUTO_TEST_CASE(classDecl)
{
    NId *id = new NId("foo");
    NId *x = new NId("x");
    NId *y = new NId("y");
    NSimpleType *st = new NSimpleType(x);
    NType *type = new NType(st);
    NVarDecl *decl = new NVarDecl(type, y);
    NClassBody *body = new NClassBody(decl);
    NClassDecl *classDecl = new NClassDecl(id, body);

    std::stringstream s;
    classDecl->print(&s);
    BOOST_CHECK(s.str() == "<classdec> --> CLASS ID <classbody>\n  ID --> foo\n  <classbody> --> { <vardecs> <consdecs> <methdecs> }\n    <vardecs> --> <vardecs> <vardec>\n      <vardec> --> <type> ID SEMI\n        <type> --> ID\n          ID --> x\n        ID --> y\n");
}

BOOST_AUTO_TEST_CASE(classBody)
{
    NId *x = new NId("x");
    NId *y = new NId("y");
    NSimpleType *st = new NSimpleType(x);
    NType *type = new NType(st);
    NVarDecl *decl = new NVarDecl(type, y);
    NClassBody *body = new NClassBody(decl);

    std::stringstream s;
    body->print(&s);
    BOOST_CHECK(s.str() == "<classbody> --> { <vardecs> <consdecs> <methdecs> }\n  <vardecs> --> <vardecs> <vardec>\n    <vardec> --> <type> ID SEMI\n      <type> --> ID\n        ID --> x\n      ID --> y\n");
}

BOOST_AUTO_TEST_CASE(constDecl)
{
    NId *foo = new NId("foo");
    NSimpleType *st = new NSimpleType(foo);
    NType *type = new NType(st);
    NParam *param = new NParam(type, foo);
    NOptExp *opt = new NOptExp();
    NStateReturn *ret = new NStateReturn(opt);
    NBlock *block = new NBlock(ret);
    NConstDecl *decl = new NConstDecl(foo, param, block);

    std::stringstream s;
    decl->print(&s);
    BOOST_CHECK(s.str() == "<consdecs> --> <consdecs> <consdec>\n  <consdec> --> ID ( <params> ) <block>\n    ID --> foo\n    <paramlist> --> <param>\n      <param> --> <type> ID\n        <type> --> ID\n          ID --> foo\n        ID --> foo\n    <block> --> { <localvardecs>* <statements>* }\n      <statement> --> RETURN\n");
}

BOOST_AUTO_TEST_CASE(methDecl)
{
    // TODO: Circle back to this
}