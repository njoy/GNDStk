
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

// foo_t, bar_t
struct foo_t { std::string foo_id; };
struct bar_t { std::string bar_id; };

inline void convert(const Node<> &n, foo_t &foo)
   { bool found; foo.foo_id = n(mixed::meta::id,found); }
inline void convert(const Node<> &n, bar_t &bar)
   { bool found; bar.bar_id = n(mixed::meta::id,found); }

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

// keywords with find::one
auto temperature =
   keyword.child<temperature_t,find::one>("temperature");
auto styles =
   keyword.child<void,find::one>("styles");
auto documentations =
   keyword.child<std::variant<foo_t,bar_t>,find::one>("documentations");

// keywords with find::all
auto isotope =
   keyword.child<isotope_t,find::all>("isotope");
auto isotope_node =
   keyword.child<void,find::all>("isotope");
auto nuclide_foo_or_bar_node =
   keyword.child<std::variant<foo_t,bar_t>,find::all>("nuclide");



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk Node child()") {
   GIVEN("The top-level node from a tree object") {

      // tree
      Tree<> tree("n-008_O_016.xml");

      // top-level GNDS node, const and non-const
      const Node<> &ctop = tree.top();
      Node<> &top = tree.top();

      // below, we'll exercise every variation of node::child()
      auto temp = top(
         mixed::child::styles,   // from GNDStk
         mixed::child::evaluated // from GNDStk
      ).child(
         temperature // ours, as set up earlier
      );
      CHECK(temp.value == 0.0);
      CHECK(temp.unit  == "K");

      auto &styles_const = ctop.child(styles);
      CHECK(styles_const.metadata.size() == 0);
      CHECK(styles_const.children.size() == 1);

      auto &styles_nonconst = top.child(styles);
      CHECK(styles_nonconst.metadata.size() == 0);
      CHECK(styles_nonconst.children.size() == 1);

      auto foodoc = top.child<foo_t>(documentations);
      (void)foodoc.foo_id; // foodoc should be of type foo_t;
      auto bardoc = top.child<bar_t>(documentations);
      (void)bardoc.bar_id; // bardoc should be of type bar_t;

      auto iso = top(
         mixed::child::PoPs,
         mixed::child::chemicalElements,
         mixed::child::chemicalElement
      )[0](
         mixed::child::isotopes
      ).child(isotope);
      CHECK(iso.size() == 3);
      CHECK(iso[0].symbol == "H1");  CHECK(iso[0].A == 1);
      CHECK(iso[1].symbol == "H2");  CHECK(iso[1].A == 2);
      CHECK(iso[2].symbol == "H3");  CHECK(iso[2].A == 3);

      auto iso_node = top(
         mixed::child::PoPs,
         mixed::child::chemicalElements,
         mixed::child::chemicalElement
      )[0](
         mixed::child::isotopes
      ).child(isotope_node);
      CHECK(iso_node.size() == 3);
      CHECK(iso_node[0].name == "isotope");
      CHECK(iso_node[1].name == "isotope");
      CHECK(iso_node[2].name == "isotope");

      auto iso_foo_node = top(
         mixed::child::PoPs,
         mixed::child::chemicalElements,
         mixed::child::chemicalElement
      )[0](
         mixed::child::isotopes,
         mixed::child::isotope
      )[0](mixed::child::nuclides).child<foo_t>(nuclide_foo_or_bar_node);

      CHECK(iso_foo_node.size() == 1);
      CHECK(iso_foo_node[0].foo_id == "H1");

      auto iso_bar_node = top(
         mixed::child::PoPs,
         mixed::child::chemicalElements,
         mixed::child::chemicalElement
      )[0](
         mixed::child::isotopes,
         mixed::child::isotope
      )[1](mixed::child::nuclides).child<bar_t>(nuclide_foo_or_bar_node);

      CHECK(iso_bar_node.size() == 1);
      CHECK(iso_bar_node[0].bar_id == "H2");
   }
}
