// #define BOOST_TEST_DYN_LINK only define once (in value_test.cpp)
#define BOOST_TEST_MODULE ClassSymbolTable
#include <boost/test/unit_test.hpp>
#include "../include/parser.hpp"

BOOST_AUTO_TEST_CASE(singleSymbolTable)
{
    // 0 makes this a root table
    SymbolTable *tab = new SymbolTable(0);
    Value *ten = new Value(10);
    tab->registerSymbolWithValue("x", ten);
    BOOST_CHECK(tab->lookupSymbol("x")->isInt());
    BOOST_CHECK(tab->lookupSymbol("x")->getInt() == 10);
    BOOST_CHECK(!tab->lookupSymbol("x")->isEpsilon());
    BOOST_CHECK(!tab->lookupSymbol("x")->isString());
}

BOOST_AUTO_TEST_CASE(singleOverwriteSymbolTable)
{
    // 0 makes this a root table
    SymbolTable *tab = new SymbolTable(0);
    Value *five = new Value(5);
    Value *ten = new Value(10);
    tab->registerSymbolWithValue("x", five);
    tab->registerSymbolWithValue("x", ten);
    BOOST_CHECK(tab->lookupSymbol("x")->isInt());
    BOOST_CHECK(tab->lookupSymbol("x")->getInt() == 10);
    BOOST_CHECK(!tab->lookupSymbol("x")->isEpsilon());
    BOOST_CHECK(!tab->lookupSymbol("x")->isString());
}

BOOST_AUTO_TEST_CASE(multipleSymbolTable)
{
    SymbolTable *root = new SymbolTable(0);
    Value *ten = new Value(10);
    root->registerSymbolWithValue("x", ten);
    SymbolTable *tab = new SymbolTable(root);
    BOOST_CHECK(tab->lookupSymbol("x")->isInt());
    BOOST_CHECK(tab->lookupSymbol("x")->getInt() == 10);
    BOOST_CHECK(!tab->lookupSymbol("x")->isEpsilon());
    BOOST_CHECK(!tab->lookupSymbol("x")->isString());
}

BOOST_AUTO_TEST_CASE(multipleOverwriteSymbolTable)
{
    SymbolTable *root = new SymbolTable(0);
    Value *five = new Value(5);
    Value *ten = new Value(10);
    root->registerSymbolWithValue("x", five);
    SymbolTable *tab = new SymbolTable(root);
    tab->registerSymbolWithValue("x", ten);
    BOOST_CHECK(tab->lookupSymbol("x")->isInt());
    BOOST_CHECK(tab->lookupSymbol("x")->getInt() == 10);
    BOOST_CHECK(!tab->lookupSymbol("x")->isEpsilon());
    BOOST_CHECK(!tab->lookupSymbol("x")->isString());
}