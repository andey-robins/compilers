/*
 * value_test.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 */

#ifndef BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK // only define once (in value_test.cpp)
#endif
#define BOOST_TEST_MODULE "Parser Tests"
#include <boost/test/unit_test.hpp>
#include "../include/parser.hpp"

BOOST_AUTO_TEST_CASE(stringValue)
{
    string hello = "Hello!";
    Value *first = new Value(&hello);
    if (first->isString())
    {
        string *val = first->getString();
        BOOST_CHECK(*val == hello);
        return;
    }

    BOOST_FAIL("Value did not hold a string when it was supposed to.");
}

BOOST_AUTO_TEST_CASE(intValue)
{
    int x = 10;
    Value *first = new Value(x);
    if (first->isInt())
    {
        BOOST_CHECK(first->getInt() == x);
        return;
    }

    BOOST_FAIL("Value did not hold an int when it was supposed to.");
}

BOOST_AUTO_TEST_CASE(epsilonValue)
{
    Value *first = new Value();
    if (!first->isEpsilon())
    {
        BOOST_FAIL("Value was not an epsilon when it was supposed to be.");
    }
}