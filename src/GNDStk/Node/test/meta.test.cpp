
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace GNDStk;

SCENARIO("Testing GNDStk Node meta()") {

   GIVEN("The top-level node from a tree object") {
      Tree<> tree("n-069_Tm_170-covar.xml");
      const Node<> &consttop = tree.top(); // top-level GNDS node
      Node<> &top = tree.top(); // top-level GNDS node

      REQUIRE(consttop.meta("projectile") == "n");
      REQUIRE(top.meta("target") == "Tm170");
      REQUIRE(consttop.meta("format") == "1.9");

      // get reference back; can set
      top.meta("format") = "1.99";
      REQUIRE(consttop.meta("format") == "1.99");

      auto format = keyword.meta<double>("format");
      double f = top.meta(format);
      REQUIRE(f == 1.99);

      // try something that doesn't work
      auto foobar = keyword.meta<double>("foobar");
      bool found = true;
      f = top.meta(foobar,found); // foobar isn't there
      REQUIRE(!found); // so it wasn't found

      // string and void meta_t ==> string
      auto sstring = keyword.meta<std::string>("evaluation");
      auto vstring = keyword.meta<void       >("evaluation");
      std::string sstr = top.meta(sstring);
      std::string vstr = top.meta(vstring);
      REQUIRE(sstr == "ENDF/B-8.0");
      REQUIRE(vstr == "ENDF/B-8.0");

      auto var = keyword.meta<std::variant<std::string,double>>("format");
      auto s = top.meta<std::string>(var);
      auto d = top.meta<double     >(var);
      REQUIRE(s == "1.99");
      REQUIRE(d ==  1.99 );
   }

}
