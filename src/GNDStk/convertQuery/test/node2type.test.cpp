
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk convert(Node,type)") {

   WHEN("We make Nodes foo and bar") {
      Node foo("foo");
      Node bar("bar");

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

   WHEN("We make a Node foo with particular content") {
      Node foo("foo");
      // If a Node has a "#text" metadatum, then the convert(Node,container)
      // function, where container is e.g. vector<T>, will attempt to fill
      // the container with the contents of the "#text" metadatum's value.
      foo.add("#text","12 34 56 78 90");

      // Update, 2020-10-19. The relevant convert() functionality has been
      // reformulated into the detail::convert_pcdata_text_t callable object,
      // so we'll reformulate with that. Ultimately, due to the location of
      // the new code, we should probably put this test material elsewhere.

      THEN("convert(foo,deque) extracts the content correctly") {
         std::deque<int> container;
         detail::convert_pcdata_text_t{}(foo,container);
         CHECK(container.size() == 5);
         CHECK(container[0] == 12);
         CHECK(container[1] == 34);
         CHECK(container[2] == 56);
         CHECK(container[3] == 78);
         CHECK(container[4] == 90);
      }

      THEN("convert(foo,list) extracts the content correctly") {
         std::list<int> container;
         detail::convert_pcdata_text_t{}(foo,container);
         CHECK(container.size() == 5);
         auto iter = container.begin();
         CHECK(*iter++ == 12);
         CHECK(*iter++ == 34);
         CHECK(*iter++ == 56);
         CHECK(*iter++ == 78);
         CHECK(*iter++ == 90);
      }

      THEN("convert(foo,vector) extracts the content correctly") {
         std::vector<int> container;
         detail::convert_pcdata_text_t{}(foo,container);
         CHECK(container.size() == 5);
         CHECK(container[0] == 12);
         CHECK(container[1] == 34);
         CHECK(container[2] == 56);
         CHECK(container[3] == 78);
         CHECK(container[4] == 90);
      }

   }
}
