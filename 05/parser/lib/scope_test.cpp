/*
 * scope_test.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 */

#ifndef BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK // only define once (in value_test.cpp)
#endif
#include <boost/test/unit_test.hpp>
#include "../include/parser.hpp"

BOOST_AUTO_TEST_CASE(singleTableInScope)
{
    // 0 makes this a root table
    SymbolTable *tab = new SymbolTable(0);
    Value *ten = new Value(10);
    Scope *scope = new Scope(tab);
    scope->registerSymbolWithValue("x", ten);
    BOOST_CHECK(tab->lookupSymbol("x")->isInt());
    BOOST_CHECK(tab->lookupSymbol("x")->getInt() == 10);
    BOOST_CHECK(!tab->lookupSymbol("x")->isEpsilon());
    BOOST_CHECK(!tab->lookupSymbol("x")->isString());
}

BOOST_AUTO_TEST_CASE(multipleTableInScopeAndRedefinitions)
{
    // 0 makes this a root table
    SymbolTable *tab = new SymbolTable(0);
    SymbolTable *tabTwo = new SymbolTable(tab);
    Value *five = new Value(5);
    Value *ten = new Value(10);
    Scope *scope = new Scope(tab);
    scope->registerSymbolWithValue("x", ten);
    scope->push(tabTwo);
    scope->registerSymbolWithValue("x", five);
    BOOST_CHECK(scope->lookupSymbol("x")->isInt());
    BOOST_CHECK(scope->lookupSymbol("x")->getInt() == 5);
    BOOST_CHECK(!scope->lookupSymbol("x")->isEpsilon());
    BOOST_CHECK(!scope->lookupSymbol("x")->isString());
    scope->pop();
    BOOST_CHECK(scope->lookupSymbol("x")->isInt());
    BOOST_CHECK(scope->lookupSymbol("x")->getInt() == 10);
    BOOST_CHECK(!scope->lookupSymbol("x")->isEpsilon());
    BOOST_CHECK(!scope->lookupSymbol("x")->isString());
}