/*
 * parameters_test.cpp
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

BOOST_AUTO_TEST_CASE(param)
{
    NId *id = new NId("x");
    NSimpleType *st = new NSimpleType(id);
    NType *type = new NType(st);
    NParam *param = new NParam(type, id);

    std::stringstream s;
    param->print(&s);
    BOOST_CHECK(s.str() == "<param> --> <type> ID\n  <type> --> ID\n    ID --> x\n  ID --> x\n");
}

BOOST_AUTO_TEST_CASE(args)
{
    NExpNull *exp = new NExpNull();
    NArg *arg = new NArg(exp);
    std::stringstream s;
    arg->print(&s);
    BOOST_CHECK(s.str() == "<arg> --> <expression>\n  <exp> --> null\n");
}

BOOST_AUTO_TEST_CASE(bracks)
{
    NBracks *bracks = new NBracks(2);
    std::stringstream s;
    bracks->print(&s);
    BOOST_CHECK(s.str() == " [] []\n");
    BOOST_CHECK(bracks->getCount() == 2);
}

BOOST_AUTO_TEST_CASE(brackExps)
{
    NExpNull *exp = new NExpNull();
    NBrackExps *bes = new NBrackExps();
    std::stringstream s;
    bes->print(&s);
    BOOST_CHECK(s.str() == " [<exp>]");
}