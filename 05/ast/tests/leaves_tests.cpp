#ifndef BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK // only define once (in value_test.cpp)
#endif
#include <iostream>
#include <sstream>
#include <boost/test/unit_test.hpp>
#include "../include/nodes.hpp"

BOOST_AUTO_TEST_CASE(leafOutput)
{
    NId *idNode = new NId("keyword");
    NKeyword *keyNode = new NKeyword("void");
    NNumber *numNode = new NNumber(12);
    NOperator *opNode = new NOperator("+");

    std::stringstream s;
    idNode->print(&s);
    BOOST_CHECK(s.str() == "ID --> keyword");
    s.clear();
    s.str("");

    keyNode->print(&s);
    BOOST_CHECK(s.str() == "void\n");
    s.clear();
    s.str("");

    numNode->print(&s);
    BOOST_CHECK(s.str() == "NUMBER --> 12\n");
    BOOST_CHECK(numNode->getVal() == 12);
    s.clear();
    s.str("");

    opNode->print(&s);
    BOOST_CHECK(s.str() == "+");
    BOOST_CHECK(opNode->getOp() == "+");
}