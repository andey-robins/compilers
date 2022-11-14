/*
 * expressions_test  .cpp
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

BOOST_AUTO_TEST_CASE(newExpIdArgs)
{
    NId *id = new NId("new");
    NExpNull *e = new NExpNull();
    NArg *arg = new NArg(e);
    NNewExpIdArgs *newExp = new NNewExpIdArgs(id, arg);
    std::stringstream s;
    newExp->print(&s);
    BOOST_CHECK(s.str() == "<newexp> --> NEW ID ( <arglist> )\n  ID --> new\n  <arg> --> <expression>\n    <exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(newExpType)
{
    NId *id = new NId("x");
    NSimpleType *st = new NSimpleType(id);
    NExpNull *e = new NExpNull();
    NBrackExps *bes = new NBrackExps(e);
    NBracks *bs = new NBracks(2);
    NNewExpType *exp1 = new NNewExpType(st, bes, bs);
    NNewExpType *exp2 = new NNewExpType(st, bes);
    NNewExpType *exp3 = new NNewExpType(st, bs);
    NNewExpType *exp4 = new NNewExpType(st);

    std::stringstream s;
    exp1->print(&s);
    BOOST_CHECK(s.str() == "<newexp> --> NEW <type>\n  <type> --> ID [<exp>] [] []\n    ID --> x\n    <exp> --> null\n");
    s.clear();
    s.str("");

    exp2->print(&s);
    BOOST_CHECK(s.str() == "<newexp> --> NEW <type>\n  <type> --> ID [<exp>]\n    ID --> x\n    <exp> --> null\n");
    s.clear();
    s.str("");

    exp3->print(&s);
    BOOST_CHECK(s.str() == "<newexp> --> NEW <type>\n  <type> --> ID [] []\n    ID --> x\n");
    s.clear();
    s.str("");

    exp4->print(&s);
    BOOST_CHECK(s.str() == "<newexp> --> NEW <type>\n  <type> --> ID\n    ID --> x\n");
}

BOOST_AUTO_TEST_CASE(optExp)
{
    NExpNull *nullExp = new NExpNull();
    NOptExp *empty = new NOptExp();
    NOptExp *notEmpty = new NOptExp(nullExp);
    std::stringstream s;
    empty->print(&s);
    BOOST_CHECK(s.str() == "");
    notEmpty->print(&s);
    BOOST_CHECK(s.str() == "<exp> --> null\n");
    BOOST_CHECK(!empty->maybe());
    BOOST_CHECK(notEmpty->maybe());
}

// BOOST_AUTO_TEST_CASE(expName)
// {
//     NNameThis *nThis = new NNameThis();
//     NExpName *exp = new NExpName(nThis);
//     std::stringstream s;
//     exp->print(&s);
//     BOOST_CHECK(s.str() == "<exp> --> <name>\n  <name> --> THIS\n");
// }

// BOOST_AUTO_TEST_CASE(expNumber)
// {
// }

BOOST_AUTO_TEST_CASE(expNull)
{
    NExpNull *nullExp = new NExpNull();
    std::stringstream s;
    nullExp->print(&s);
    BOOST_CHECK(s.str() == "<exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(expCall)
{
    NNameThis *nThis = new NNameThis();
    NExpNull *e = new NExpNull();
    NArg *arg = new NArg(e);
    NExpCall *call = new NExpCall(nThis, arg);
    std::stringstream s;
    call->print(&s);
    BOOST_CHECK(s.str() == "<exp> --> <name> ( <exp> )\n  <name> --> THIS\n  <arg> --> <expression>\n    <exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(expRead)
{
    NExpRead *read = new NExpRead();
    std::stringstream s;
    read->print(&s);
    BOOST_CHECK(s.str() == "<exp> --> READ\n");
}

BOOST_AUTO_TEST_CASE(expNewExp)
{
    NId *id = new NId("x");
    NSimpleType *st = new NSimpleType(id);
    NNewExp *newExp = new NNewExpType(st);
    NExpNewExp *expNewExp = new NExpNewExp(newExp);

    std::stringstream s;
    expNewExp->print(&s);
    BOOST_CHECK(s.str() == "<exp> --> <newexp>\n  <newexp> --> NEW <type>\n    <type> --> ID\n      ID --> x\n");
}

BOOST_AUTO_TEST_CASE(prefixExp)
{
    NExpNull *nullExp = new NExpNull();
    NOperator *op = new NOperator("+");
    NPrefixExp *infix = new NPrefixExp(op, nullExp);

    std::stringstream s;
    infix->print(&s);
    BOOST_CHECK(s.str() == "<exp> --> + <exp>\n  <exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(infixExp)
{
    NExpNull *nullExp = new NExpNull();
    NOperator *op = new NOperator("+");
    NInfixExp *infix = new NInfixExp(op, nullExp, nullExp);

    std::stringstream s;
    infix->print(&s);
    BOOST_CHECK(s.str() == "<exp> --> <exp> + <exp>\n  <exp> --> null\n  <exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(parenExp)
{
    NExpNull *nullExp = new NExpNull();
    NParenExp *parens = new NParenExp(nullExp);

    std::stringstream s;
    parens->print(&s);
    BOOST_CHECK(s.str() == "<exp> --> ( <exp> )\n  <exp> --> null\n");
}

// BOOST_AUTO_TEST_CASE(nameExp)
// {
//     NExpNull *nullExp = new NExpNull();
//     NNameThis *name = new NNameThis();
//     NNameExp *nameExp = new NNameExp(name, nullExp);

//     std::stringstream s;
//     nameExp->print(&s);
//     cout << s.str();
//     BOOST_CHECK("<exp> --> <>")
// }