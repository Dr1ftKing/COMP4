// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr1) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(testStepInstr3) {
  FibLFSR l3("0000000000000000");
  BOOST_REQUIRE_EQUAL(l3.step(), 0);
  BOOST_REQUIRE_EQUAL(l3.step(), 0);
  BOOST_REQUIRE_EQUAL(l3.step(), 0);
  BOOST_REQUIRE_EQUAL(l3.step(), 0);
  BOOST_REQUIRE_EQUAL(l3.step(), 0);
  BOOST_REQUIRE_EQUAL(l3.step(), 0);
  BOOST_REQUIRE_EQUAL(l3.step(), 0);
  BOOST_REQUIRE_EQUAL(l3.step(), 0);
}
BOOST_AUTO_TEST_CASE(testStepInstr4) {
  FibLFSR l4("1011011000110110");
   BOOST_TEST(string("1011011000110110") == l4.getSeed());
}