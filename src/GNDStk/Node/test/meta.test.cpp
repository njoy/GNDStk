
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk Node meta()") {

   GIVEN("The top-level node from a tree object") {
      Tree<> tree("n-069_Tm_170-covar.xml");
      const Node<> &consttop = tree.top(); // top-level GNDS node
      Node<> &top = tree.top(); // top-level GNDS node

      CHECK(consttop.meta("projectile") == "n");
      CHECK(top.meta("target") == "Tm170");
      CHECK(consttop.meta("format") == "1.9");

      // get reference back; can set
      top.meta("format") = "1.99";
      CHECK(consttop.meta("format") == "1.99");

      auto format = keyword.meta<double>("format");
      double f = top.meta(format);
      CHECK(f == 1.99);

      // try something that doesn't work
      auto foobar = keyword.meta<double>("foobar");
      bool found = true;
      f = top.meta(foobar,found); // foobar isn't there
      CHECK(!found); // so it wasn't found

      // string and void meta_t ==> string
      auto sstring = keyword.meta<std::string>("evaluation");
      auto vstring = keyword.meta<void       >("evaluation");
      std::string sstr = top.meta(sstring);
      std::string vstr = top.meta(vstring);
      CHECK(sstr == "ENDF/B-8.0");
      CHECK(vstr == "ENDF/B-8.0");
      // meta<void> case should trigger a reference return...
      (void)&top.meta(vstring);

      auto var = keyword.meta<std::variant<std::string,double>>("format");
      auto s = top.meta<std::string>(var);
      auto d = top.meta<double     >(var);
      CHECK(s == "1.99");
      CHECK(d ==  1.99 );
   }

}
