
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

static const std::string correct_node =
R"***(values:
   pcdata:
      text: 1 2.3 4.56
)***";

SCENARIO("Testing GNDStk convert(type,node)") {

   // When type *is* node, we have convert(node,node) - which we already
   // tested in the node2type.test.cpp file. No need to repeat it here.
   // So, we'll just have type be the sequence containers in our built-in
   // convert(type,node) function.

   // Update, 2020-10-19. The relevant convert() functionality has been
   // reformulated into the detail::convert_pcdata_text_t callable object,
   // so we'll reformulate with that. Ultimately, due to the location of
   // the new code, we should probably put this test material elsewhere.

   WHEN("type is vector") {
      std::vector<double> container = { 1, 2.3, 4.56 };
      node n("old name");
      // convert(container,n);
      detail::convert_pcdata_text_t{}(container,n);

      // one way to check the node
      CHECK(n.name == "values");
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 1);
      CHECK(n.children[0]->name == "pcdata");
      CHECK(n.one("pcdata").metadata.size() == 1);
      CHECK(n.one("pcdata").children.size() == 0);
      CHECK(n.one("pcdata").metadata[0].first == "text");
      CHECK(n.one("pcdata").metadata[0].second == "1 2.3 4.56");

      // a shorter way
      std::ostringstream oss; oss << n;
      CHECK(oss.str() == correct_node);
   }

   WHEN("type is deque") {
      std::deque<double> container = { 1, 2.3, 4.56 };
      node n("old name");
      // convert(container,n);
      detail::convert_pcdata_text_t{}(container,n);
      std::ostringstream oss; oss << n;
      CHECK(oss.str() == correct_node);
   }

   WHEN("type is list") {
      std::list<double> container = { 1, 2.3, 4.56 };
      node n("old name");
      // convert(container,n);
      detail::convert_pcdata_text_t{}(container,n);
      std::ostringstream oss; oss << n;
      CHECK(oss.str() == correct_node);
   }
}
