/*
 * statements_test.cpp
 * Andey Robins
 * 11/13/22
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

BOOST_AUTO_TEST_CASE(stateAssign)
{
    NNameThis *name = new NNameThis();
    NExpNull *nullExp = new NExpNull();
    NStateAssign *state = new NStateAssign(name, nullExp);

    std::stringstream s;
    state->print(&s);
    BOOST_CHECK(s.str() == "<statement> --> <name> = <expression> SEMI\n  <name> --> THIS\n  <exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(stateCall)
{
    NNameThis *name = new NNameThis();
    NExpNull *e = new NExpNull();
    NArg *arg = new NArg(e);
    NStateCall *call = new NStateCall(name, arg);

    std::stringstream s;
    call->print(&s);
    BOOST_CHECK(s.str() == "<statement> --> <name> ( <argList> ) SEMI\n  <name> --> THIS\n  <arg> --> <expression>\n    <exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(stateWhile)
{
    NExpNull *e = new NExpNull();
    NNameThis *name = new NNameThis();
    NExpNull *nullExp = new NExpNull();
    NStateAssign *state = new NStateAssign(name, nullExp);
    NStateWhile *whileStmt = new NStateWhile(e, state);
    
    std::stringstream s;
    whileStmt->print(&s);
    BOOST_CHECK(s.str() == "<statement> --> WHILE ( <exp> ) <statement>\n  <exp> --> null\n  <statement> --> <name> = <expression> SEMI\n    <name> --> THIS\n    <exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(stateReturn)
{
    NExpNull *e = new NExpNull();
    NOptExp *opt = new NOptExp(e);
    NStateReturn *ret = new NStateReturn(opt);

    std::stringstream s;
    ret->print(&s);
    BOOST_CHECK(s.str() == "<statement> --> RETURN <exp>\n  <exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(stateBlock)
{
    // TODO after fixing block
}

BOOST_AUTO_TEST_CASE(condition)
{
    NExpNull *e = new NExpNull();
    NOptExp *opt = new NOptExp(e);
    NOptExp *epsilon = new NOptExp();
    NStateReturn *ret = new NStateReturn(opt);
    NStateReturn *retTwo = new NStateReturn(epsilon);
    NCondition *ifCond = new NCondition(e, ret);
    NCondition *elseCond = new NCondition(e, ret, retTwo);

    std::stringstream s;
    ifCond->print(&s);
    BOOST_CHECK(s.str() == "<condition> --> IF ( <exp> ) <statement>\n  <exp> --> null\n  <statement> --> RETURN <exp>\n    <exp> --> null\n");
    s.clear();
    s.str("");

    elseCond->print(&s);
    BOOST_CHECK(s.str() == "<condition> --> IF ( <exp> ) <statement> ELSE <statement>\n  <exp> --> null\n  <statement> --> RETURN <exp>\n    <exp> --> null\n  <statement> --> RETURN\n");
}

BOOST_AUTO_TEST_CASE(stateCond)
{
    NExpNull *e = new NExpNull();
    NOptExp *opt = new NOptExp(e);
    NStateReturn *ret = new NStateReturn(opt);
    NCondition *ifCond = new NCondition(e, ret);
    NStateCond *ifStmt = new NStateCond(ifCond);
    
    std::stringstream s;
    ifStmt->print(&s);
    BOOST_CHECK(s.str() == "<statement> --> <condition>\n  <condition> --> IF ( <exp> ) <statement>\n    <exp> --> null\n    <statement> --> RETURN <exp>\n      <exp> --> null\n");
}