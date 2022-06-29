
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

static const std::string correct_node =
R"***(#pcdata:
   #text: 1 2.3 4.56)***";

SCENARIO("Testing GNDStk convert(type,Node)") {

   // When type *is* Node, we have convert(Node,Node) - which we already
   // tested in the node2type.test.cpp file. No need to repeat it here.
   // So, we'll just have type be the sequence containers in our built-in
   // convert(type,Node) function.

   // Update, 2020-10-19. The relevant convert() functionality has been
   // reformulated into the detail::convert_pcdata_text_t callable object,
   // so we'll reformulate with that. Ultimately, due to the location of
   // the new code, we should probably put this test material elsewhere.

   WHEN("type is vector") {
      std::vector<double> container = { 1, 2.3, 4.56 };
      Node n("old name");
      detail::convert_pcdata_text_t{}(container,n);

      // one way to check the Node
      CHECK(n.name == "#pcdata");
      CHECK(n.metadata.size() == 1);
      CHECK(n.children.size() == 0);
      CHECK(n.metadata[0].first == "#text");
      CHECK(n.metadata[0].second == "1 2.3 4.56");

      // a shorter way
      std::ostringstream oss; oss << n;
      CHECK(oss.str() == correct_node);
   }

   WHEN("type is deque") {
      std::deque<double> container = { 1, 2.3, 4.56 };
      Node n("old name");
      detail::convert_pcdata_text_t{}(container,n);
      std::ostringstream oss; oss << n;
      CHECK(oss.str() == correct_node);
   }

   WHEN("type is list") {
      std::list<double> container = { 1, 2.3, 4.56 };
      Node n("old name");
      detail::convert_pcdata_text_t{}(container,n);
      std::ostringstream oss; oss << n;
      CHECK(oss.str() == correct_node);
   }
}
