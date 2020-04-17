
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace GNDStk;


// -----------------------------------------------------------------------------
// Some child_ts
// -----------------------------------------------------------------------------

// temperature_t
struct temperature_t {
   // just the metadata, for this example
   double value;
   std::string unit;
};

inline void node2type(const Node<> &n, temperature_t &temp)
{
   temp.value = n(meta::dvalue);
   temp.unit  = n(meta::unit);
}

// isotope_t
struct isotope_t {
   std::string symbol;
   int A;
   const Node<> *nuclides;
};

inline void node2type(const Node<> &n, isotope_t &iso)
{
   iso.symbol = n(meta::symbol);
   iso.A = n(meta::A);
   iso.nuclides = &n(child::nuclides);
}



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk Node operator()") {

   // If I put these outside SCENARIO, the build system claims that they're
   // multiply defined with respect to the definitions in child.test.cpp.
   // Why on earth does the build system cram together that file and this one?
   // Oh, but if I leave them out (because, apparently, the build system tries
   // to bring them in from child.test.cpp!), then it complains that they aren't
   // defined at all! OK, maybe putting them here, locally, will work. Hooray
   // for confounding, convoluted and Byzantine building and testing systems
   // that invariably make compiling and testing more complicated than they'd
   // be if we had no such systems at all.

   // keywords with find::one
   auto temperature =
      keyword.child<temperature_t,find::one>("temperature");
   auto styles =
      keyword.child<void,find::one>("styles");

   // keywords with find::all
   auto isotope =
      keyword.child<isotope_t,find::all>("isotope");
   auto isotope_node =
      keyword.child<void,find::all>("isotope");

   GIVEN("The top-level node from a tree object") {

      // tree
      Tree<> tree("n-008_O_016.xml");

      // top-level GNDS node, const and non-const
      const Node<> &ctop = tree.top();
      Node<> &top = tree.top();

      // Below, we'll exercise every variation of node::operator()

      auto temp = top(
         child::styles,   // from GNDStk
         child::evaluated, // from GNDStk
         temperature // ours, as set up earlier
      );
      REQUIRE(temp.value == 0.0);
      REQUIRE(temp.unit  == "K");

      auto &styles_const = ctop(styles);
      REQUIRE(styles_const.metadata.size() == 0);
      REQUIRE(styles_const.children.size() == 1);

      auto &styles_nonconst = top(styles);
      REQUIRE(styles_nonconst.metadata.size() == 0);
      REQUIRE(styles_nonconst.children.size() == 1);

      auto iso = top( // non-const
         child::PoPs,
         child::chemicalElements,
         child::chemicalElement
      )[0](
         child::isotopes,
         isotope
      );
      REQUIRE(iso.size() == 3);
      REQUIRE(iso[0].symbol == "H1");  REQUIRE(iso[0].A == 1);
      REQUIRE(iso[1].symbol == "H2");  REQUIRE(iso[1].A == 2);
      REQUIRE(iso[2].symbol == "H3");  REQUIRE(iso[2].A == 3);

      auto iso_node = ctop( // const
         child::PoPs,
         child::chemicalElements,
         child::chemicalElement
      )[0](
         child::isotopes,
         isotope_node
      );
      REQUIRE(iso_node.size() == 3);
      REQUIRE(iso_node[0].name == "isotope");
      REQUIRE(iso_node[1].name == "isotope");
      REQUIRE(iso_node[2].name == "isotope");

      const meta_t<char> projectile("projectile");
      REQUIRE(top(projectile) == 'n');
   }
}
