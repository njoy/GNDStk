
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// Some child_ts
// -----------------------------------------------------------------------------

// temperature_t
struct temperature_t {
   // just the metadata, for this example
   double value;
   std::string unit;
};

inline void convert(const Node<> &n, temperature_t &temp)
{
   temp.value = n(mixed::meta::dvalue);
   temp.unit  = n(mixed::meta::unit);
}

// isotope_t
struct isotope_t {
   std::string symbol;
   int A;
   const Node<> *nuclides;
};

inline void convert(const Node<> &n, isotope_t &iso)
{
   iso.symbol = n(mixed::meta::symbol);
   iso.A = n(mixed::meta::A);
   iso.nuclides = &n(mixed::child::nuclides);
}



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk Node operator()") {

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
         mixed::child::styles,   // from GNDStk
         mixed::child::evaluated, // from GNDStk
         temperature // ours, as set up earlier
      );
      CHECK(temp.value == 0.0);
      CHECK(temp.unit  == "K");

      auto &styles_const = ctop(styles);
      CHECK(styles_const.metadata.size() == 0);
      CHECK(styles_const.children.size() == 1);

      auto &styles_nonconst = top(styles);
      CHECK(styles_nonconst.metadata.size() == 0);
      CHECK(styles_nonconst.children.size() == 1);

      auto iso = top( // non-const
         mixed::child::PoPs,
         mixed::child::chemicalElements,
         mixed::child::chemicalElement
      )[0](
         mixed::child::isotopes,
         isotope
      );
      CHECK(iso.size() == 3);
      CHECK(iso[0].symbol == "H1");  CHECK(iso[0].A == 1);
      CHECK(iso[1].symbol == "H2");  CHECK(iso[1].A == 2);
      CHECK(iso[2].symbol == "H3");  CHECK(iso[2].A == 3);

      auto iso_node = ctop( // const
         mixed::child::PoPs,
         mixed::child::chemicalElements,
         mixed::child::chemicalElement
      )[0](
         mixed::child::isotopes,
         isotope_node
      );
      CHECK(iso_node.size() == 3);
      CHECK(iso_node[0].name == "isotope");
      CHECK(iso_node[1].name == "isotope");
      CHECK(iso_node[2].name == "isotope");

      const meta_t<char> projectile("projectile");
      CHECK(top(projectile) == 'n');
   }
}
