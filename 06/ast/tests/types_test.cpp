/*
 * types_test.cpp
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

BOOST_AUTO_TEST_CASE(simpleTypes)
{
    NKeyword *key = new NKeyword("int");
    NId *id = new NId("x");

    NSimpleType *keyType = new NSimpleType(key);
    NSimpleType *idType = new NSimpleType(id);

    std::stringstream s;
    keyType->print(&s);
    BOOST_CHECK(s.str() == "<type> --> INT\n");
    BOOST_CHECK(keyType->getType() == "int");
    s.clear();
    s.str("");

    idType->print(&s);
    BOOST_CHECK(s.str() == "<type> --> ID\n  ID --> x");
    BOOST_CHECK(idType->getType() == "ID");
    s.clear();
    s.str("");
}

BOOST_AUTO_TEST_CASE(types)
{
    NId *id = new NId("x");
    NSimpleType *simple = new NSimpleType(id);
    NType *typeSt = new NType(simple);

    std::stringstream s;
    typeSt->print(&s);
    BOOST_CHECK(s.str() == "<type> --> ID\n  ID --> x");
    BOOST_CHECK(typeSt->getBracks() == 0);
    s.clear();
    s.str("");

    NType *wBracks = new NType(typeSt, 2);
    wBracks->print(&s);
    BOOST_CHECK(wBracks->getBracks() == 2);
}

BOOST_AUTO_TEST_CASE(resultType)
{
    NKeyword *intKey = new NKeyword("int");
    NResultType *intRes = new NResultType(intKey);
    NId *id = new NId("x");
    NSimpleType *st = new NSimpleType(id);
    NType *type = new NType(st);
    NResultType *xRes = new NResultType(type);

    std::stringstream s;
    intRes->print(&s);
    BOOST_CHECK(s.str() == "<resulttype> --> int\n");
    s.clear();
    s.str("");

    xRes->print(&s);
    BOOST_CHECK(s.str() == "<resulttype> --> <type>\n  <type> --> ID\n    ID --> x");
}

BOOST_AUTO_TEST_CASE(epsilonType)
{
    NEpsilon *epsilon = new NEpsilon();
    std::stringstream s;
    epsilon->print(&s);
    BOOST_CHECK(s.str() == "");
}