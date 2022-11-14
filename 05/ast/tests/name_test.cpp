/*
 * name_test.cpp
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

BOOST_AUTO_TEST_CASE(nameThis)
{
    NNameThis *nameThis = new NNameThis();
    std::stringstream s;
    nameThis->print(&s);
    BOOST_CHECK(s.str() == "<name> --> THIS\n");
}

BOOST_AUTO_TEST_CASE(nameThisDot)
{
    NNameThis *nameThis = new NNameThis();
    NNameThisDot *dot = new NNameThisDot(nameThis);
    std::stringstream s;
    dot->print(&s);
    BOOST_CHECK(s.str() == "<name> --> THIS . <name>\n  <name> --> THIS\n");
}

BOOST_AUTO_TEST_CASE(nameId)
{
    NId *id = new NId("new");
    NExpNull *nullE = new NExpNull();
    NBrackExps *bes = new NBrackExps(nullE);
    NNameId *nameId = new NNameId(id);
    NNameId *nameIdExp = new NNameId(id, bes);

    std::stringstream s;
    nameId->print(&s);
    BOOST_CHECK(s.str() == "<name> --> ID\n  ID --> new\n");
    s.clear();
    s.str("");

    nameIdExp->print(&s);
    // TODO this test is a little off, not sure why we need two newlines at the end
    BOOST_CHECK(s.str() == "<name> --> ID\n  ID --> new [<exp>]\n    <exp> --> null\n\n");
}

BOOST_AUTO_TEST_CASE(nameDotId)
{
    NId *id = new NId("new");
    NNameThis *nThis = new NNameThis();
    NNameDotId *ndi = new NNameDotId(id, nThis);

    std::stringstream s;
    ndi->print(&s);
    // TODO this maybe seems out of order?
    BOOST_CHECK(s.str() == "<name> --> ID . <name>\n  ID --> new\n  <name> --> THIS\n");
}