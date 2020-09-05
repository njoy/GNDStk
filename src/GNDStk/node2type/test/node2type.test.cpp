
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk convert(node,type)") {

   WHEN("We make nodes foo and bar") {
      Node<> foo("foo");
      Node<> bar("bar");

      foo.add("meta1","value1");

      auto &child1 = foo.add("child1");
      child1.add("meta1","value1");
      child1.add("meta2","value2");

      auto &child2 = foo.add("child2");
      child1.add("meta1","value1");
      child1.add("meta2","value2");
      child1.add("meta3","value3");

      auto &child3 = foo.add("child3");
      child1.add("meta1","value1");
      child1.add("meta2","value2");
      child1.add("meta3","value3");
      child1.add("meta4","value4");

      THEN("convert(foo,bar) makes bar identical to foo") {
         convert(foo,bar);
         std::ostringstream oss1; oss1 << foo;
         std::ostringstream oss2; oss2 << bar;
         CHECK(oss1.str() == oss2.str());
      }
   }

   WHEN("We make a node foo with particular content") {
      Node<> foo("foo");
      // If a node has a child named "pcdata", which in turn has a metadatum
      // named "text", then the convert(node,container) function, where
      // container is something like vector<T>, will attempt to fill the
      // vector with the contents of the "text" metadatum's value.
      foo.add("pcdata").add("text","12 34 56 78 90");

      // Let's try it
      THEN("convert(foo,vector) extracts the content correctly") {
         std::vector<int> vec;
         convert(foo,vec);
         CHECK(vec.size() == 5);
         CHECK(vec[0] == 12);
         CHECK(vec[1] == 34);
         CHECK(vec[2] == 56);
         CHECK(vec[3] == 78);
         CHECK(vec[4] == 90);
      }
   }
}
