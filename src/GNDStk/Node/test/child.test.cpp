
#include "catch.hpp"
#include "GNDStk.hpp"
#include <cstring>

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// reaction_t
// nonsense_t
// For use in some of the tests
// -----------------------------------------------------------------------------

struct reaction_t {
   // For the purposes of our testing, let's just have label and ENDF_MT.
   // A real reaction_t structure would of course contain much more.
   std::string label;
   int ENDF_MT;
};

void convert(const Node &n, reaction_t &r)
{
   r.label = n(basic::meta::label);
   r.ENDF_MT = n(misc::meta::ENDF_MT);
}

struct nonsense_t {
};

void convert(const Node &n, nonsense_t &r)
{
}


// -----------------------------------------------------------------------------
// Some Child objects
// -----------------------------------------------------------------------------

// temperature_t
struct temperature_t {
   // just the metadata, for this example
   double value;
   std::string unit;
};

inline void convert(const Node &n, temperature_t &temp)
{
   temp.value = n(misc::meta::dvalue);
   temp.unit  = n(misc::meta::unit);
}

// foo_t, bar_t
struct foo_t { std::string foo_id; };
struct bar_t { std::string bar_id; };

inline void convert(const Node &n, foo_t &foo)
   { bool found; foo.foo_id = n(misc::meta::id,found); }
inline void convert(const Node &n, bar_t &bar)
   { bool found; bar.bar_id = n(misc::meta::id,found); }

// isotope_t
struct isotope_t {
   std::string symbol;
   int A;
   const Node *nuclides;
};

inline void convert(const Node &n, isotope_t &iso)
{
   iso.symbol = n(misc::meta::symbol);
   iso.A = n(misc::meta::A);
   iso.nuclides = &n(misc::child::nuclides);
}

// Child objects with Allow::one
auto temperature =
   keyword.child<temperature_t,Allow::one>("temperature");
auto styles =
   keyword.child<void,Allow::one>("styles");
auto documentations =
   keyword.child<std::variant<foo_t,bar_t>,Allow::one>("documentations");

// Child objects with Allow::many
auto isotope =
   keyword.child<isotope_t,Allow::many>("isotope");
auto isotope_node =
   keyword.child<void,Allow::many>("isotope");
auto nuclide_foo_or_bar_node =
   keyword.child<std::variant<foo_t,bar_t>,Allow::many>("nuclide");


// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk Node child()") {

   // tree
   Tree tree("n-008_O_016.xml");

   GIVEN("The top-level node from a tree object") {
      // top-level GNDS node, const and non-const
      const Node &ctop = tree.top();
      Node &top = tree.top();

      WHEN("We use Node.child() to extract a child node") {
         // below, we'll exercise every variation of Node::child()
         auto temp = top(
            misc::child::styles,   // from GNDStk
            --misc::child::evaluated // from GNDStk
         ).child(
            temperature // ours, as set up earlier
         );
         CHECK(temp.value == 0.0);
         CHECK(temp.unit  == "K");

         CHECK(ctop.has_child(styles));
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
            misc::child::PoPs,
            misc::child::chemicalElements,
            misc::child::chemicalElement
         )[0](
            misc::child::isotopes
         ).child(isotope);
         CHECK(iso.size() == 3);
         CHECK(iso[0].symbol == "H1");  CHECK(iso[0].A == 1);
         CHECK(iso[1].symbol == "H2");  CHECK(iso[1].A == 2);
         CHECK(iso[2].symbol == "H3");  CHECK(iso[2].A == 3);

         auto iso_node = top(
            misc::child::PoPs,
            misc::child::chemicalElements,
            misc::child::chemicalElement
         )[0](
            misc::child::isotopes
         ).child(isotope_node);
         CHECK(iso_node.size() == 3);
         CHECK(iso_node[0].name == "isotope");
         CHECK(iso_node[1].name == "isotope");
         CHECK(iso_node[2].name == "isotope");

         auto iso_foo_node = top(
            misc::child::PoPs,
            misc::child::chemicalElements,
            misc::child::chemicalElement
         )[0](
            misc::child::isotopes,
            misc::child::isotope
         )[0](misc::child::nuclides).child<foo_t>(nuclide_foo_or_bar_node);

         CHECK(iso_foo_node.size() == 1);
         CHECK(iso_foo_node[0].foo_id == "H1");

         auto iso_bar_node = top(
            misc::child::PoPs,
            misc::child::chemicalElements,
            misc::child::chemicalElement
         )[0](
            misc::child::isotopes,
            misc::child::isotope
         )[1](misc::child::nuclides).child<bar_t>(nuclide_foo_or_bar_node);

         CHECK(iso_bar_node.size() == 1);
         CHECK(iso_bar_node[0].bar_id == "H2");
      } // WHEN
   } // GIVEN


   // ------------------------
   // Test the cdata keyword
   // ------------------------

   // By extension, this tests detail::text_metadatum_to_string()
   GIVEN("A tree object") {
      // top-level GNDS node, const and non-const
      const Node &ctop = tree.top();
      Node &top = tree.top();

      WHEN("We extract the CDATA description") {
         auto descr = tree(
            basic::child::reactionSuite,
            basic::child::documentations,
            basic::child::documentation,
            misc::child::cdata
         );
         CHECK(0 == strncmp(descr.c_str(), "\n  8-O - 16 LANL", 16));
      }
   }


   // ------------------------
   // Mechanically try every
   // Node.child() case
   // ------------------------

   using misc::meta::label;
   using misc::meta::ENDF_MT;

   // filter for nodes that have label="2n + *"
   // Remark, 2020-12-01. We removed the Node::child(Child,filter) overloads,
   // because allowing for an explicit second filter argument isn't really
   // necessary; one can just roll it into the Child's own filter. Below, we
   // replaced "(Child,filter)" cases with "(Child+filter)" instead, which
   // places the filter into the Child directly. (Replacing it, not adding
   // to it; which is fine in these cases because the old filter in those
   // Child objects was the default of "no filter".) These aren't really
   // the same tests any longer, but we're leaving them in for good measure.
   auto twon = [](const Node &n)
      { return 0 == strncmp(n(label).c_str(), "2n + ", 5); };

   // case: <void,one>
   GIVEN("Testing Node.child(Child<void,one>[+filter][,found])") {
      // n: non-const <reactions> node
      Node &n = tree(misc::child::reactionSuite,misc::child::reactions);

      const Child<void,Allow::one> reaction("reaction");
      const Child<void,Allow::one> nonsense("nonsense");

      THEN("child(Child) works") {
         // reference return; so, its address is available
         (void)&n.child(reaction);
         // Note: the n.child(reaction) instances below - not the further label
         // or ENDF_MT accesses - are really the tests. n.child(reaction) gives
         // us a non-const Node &, from which we should be able to do the rest
         CHECK(n.child(reaction)(label) == "n + O16");
         CHECK(n.child(reaction)(ENDF_MT) == 2);
         n.child(reaction)(-ENDF_MT) = "0"; // non-const; can set
         CHECK(n.child(reaction)(ENDF_MT) == 0);
         n.child(reaction)(-ENDF_MT) = "2"; // revert
         CHECK(n.child(reaction)(ENDF_MT) == 2);
      }

      THEN("child(Child,found) works") {
         bool found = false;
         (void)&n.child(reaction,found);
         CHECK(found);
         found = false;
         CHECK((n.child(reaction,found)(label) == "n + O16" && found));
         found = false;
         CHECK((n.child(reaction,found)(ENDF_MT) == 2 && found));
         n.child(reaction,found)(-ENDF_MT) = "0";
         found = false;
         CHECK((n.child(reaction,found)(ENDF_MT) == 0 && found));
         n.child(reaction,found)(-ENDF_MT) = "2";
         found = false;
         CHECK((n.child(reaction,found)(ENDF_MT) == 2 && found));
         // <reaction> was found, above, but <nonsense> shouldn't be...
         found = true;
         CHECK(!n.has_child(nonsense));
         (void)&n.child(nonsense,found);
         CHECK(!found);
      }

      THEN("child(Child+filter) works") {
         (void)&n.child(reaction+twon);
         CHECK(n.child(reaction+twon)(label) == "2n + O15 + photon");
         CHECK(n.child(reaction+twon)(ENDF_MT) == 16);
         n.child(reaction+twon)(-ENDF_MT) = "0";
         CHECK(n.child(reaction+twon)(ENDF_MT) == 0);
         n.child(reaction+twon)(-ENDF_MT) = "16";
         CHECK(n.child(reaction+twon)(ENDF_MT) == 16);
      }

      THEN("child(Child+filter,found) works") {
         bool found = false;
         (void)&n.child(reaction+twon,found);
         CHECK(found);
         found = false;
         CHECK(n.child(reaction+twon,found)(label) == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((n.child(reaction+twon,found)(ENDF_MT) == 16 && found));
         n.child(reaction+twon,found)(-ENDF_MT) = "0";
         found = false;
         CHECK((n.child(reaction+twon,found)(ENDF_MT) == 0 && found));
         n.child(reaction+twon,found)(-ENDF_MT) = "16";
         found = false;
         CHECK((n.child(reaction+twon,found)(ENDF_MT) == 16 && found));
         found = true;
         (void)&n.child(nonsense+twon,found);
         CHECK(!found);
      }
   }

   // case: <void,one> const
   // Like the above, except this one is const
   GIVEN("Testing Node.child(Child<void,one>[+filter][,found]) const") {
      // c: const <reactions> node
      const Node &c = tree(misc::child::reactionSuite,misc::child::reactions);

      const Child<void,Allow::one> reaction("reaction");
      const Child<void,Allow::one> nonsense("nonsense");

      THEN("child(Child) const works") {
         (void)&c.child(reaction);
         CHECK(c.child(reaction)(label) == "n + O16");
         CHECK(c.child(reaction)(ENDF_MT) == 2);
      }

      THEN("child(Child,found) const works") {
         bool found = false;
         (void)&c.child(reaction,found);
         CHECK(found);
         found = false;
         CHECK((c.child(reaction,found)(label) == "n + O16" && found));
         found = false;
         CHECK((c.child(reaction,found)(ENDF_MT) == 2 && found));
         found = true;
         (void)&c.child(nonsense,found);
         CHECK(!found);
      }

      THEN("child(Child+filter) const works") {
         (void)&c.child(reaction+twon);
         CHECK(c.child(reaction+twon)(label) == "2n + O15 + photon");
         CHECK(c.child(reaction+twon)(ENDF_MT) == 16);
      }

      THEN("child(Child+filter,found) const works") {
         bool found = false;
         (void)&c.child(reaction+twon,found);
         CHECK(found);
         found = false;
         CHECK(c.child(reaction+twon,found)(label) == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c.child(reaction+twon,found)(ENDF_MT) == 16 && found));
         found = true;
         (void)&c.child(nonsense+twon,found);
         CHECK(!found);
      }
   }

   // case: <void,many> const
   GIVEN("Testing Node.child(Child<void,many>[+filter][,found]) const") {
      // c: const <reactions> node
      const Node &c = tree(misc::child::reactionSuite,misc::child::reactions);

      const Child<void,Allow::many> reaction("reaction");
      const Child<void,Allow::many> nonsense("nonsense");

      THEN("child(Child) const works") {
         CHECK(c.child(reaction).size() == 60);
         CHECK(c.child(reaction)[0](label) == "n + O16");
         CHECK(c.child(reaction)[0](ENDF_MT) == 2);
      }

      THEN("child(Child,found) const works") {
         bool found = false;
         CHECK((c.child(reaction,found).size() == 60 && found));
         found = false;
         CHECK((c.child(reaction,found)[0](label) == "n + O16" && found));
         found = false;
         CHECK((c.child(reaction,found)[0](ENDF_MT) == 2 && found));
         found = true;
         CHECK((c.child(nonsense,found).size() == 0 && !found));
      }

      THEN("child(Child+filter) const works") {
         CHECK(c.child(reaction+twon).size() == 2);
         CHECK(c.child(reaction+twon)[0](label) == "2n + O15 + photon");
         CHECK(c.child(reaction+twon)[0](ENDF_MT) == 16);
         CHECK(c.child(reaction+twon)[1](label) == "2n + H1 + N14 + photon");
         CHECK(c.child(reaction+twon)[1](ENDF_MT) == 41);
      }

      THEN("child(Child+filter,found) const works") {
         bool found = false;
         CHECK((c.child(reaction+twon,found).size() == 2 && found));
         found = false;
         CHECK(c.child(reaction+twon,found)[0](label) == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c.child(reaction+twon,found)[0](ENDF_MT) == 16 && found));
         found = true;
         CHECK((c.child(nonsense+twon,found).size() == 0 && !found));
      }
   }

   // case: <type,one> const
   GIVEN("Testing Node.child(Child<type,one>[+filter][,found]) const") {
      // c: const <reactions> node
      const Node &c = tree(misc::child::reactionSuite,misc::child::reactions);

      const Child<reaction_t,Allow::one> reaction("reaction");
      const Child<nonsense_t,Allow::one> nonsense("nonsense");

      THEN("child(Child) const works") {
         CHECK(c.child(reaction).label == "n + O16");
         CHECK(c.child(reaction).ENDF_MT == 2);
      }

      THEN("child(Child,found) const works") {
         bool found = false;
         CHECK((c.child(reaction,found).label == "n + O16" && found));
         found = false;
         CHECK((c.child(reaction,found).ENDF_MT == 2 && found));
         found = true;
         c.child(nonsense,found);
         CHECK(!found);
      }

      THEN("child(Child+filter) const works") {
         CHECK(c.child(reaction+twon).label == "2n + O15 + photon");
         CHECK(c.child(reaction+twon).ENDF_MT == 16);
      }

      THEN("child(Child+filter,found) const works") {
         bool found = false;
         CHECK(c.child(reaction+twon,found).label == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c.child(reaction+twon,found).ENDF_MT == 16 && found));
         found = true;
         c.child(nonsense+twon,found);
         CHECK(!found);
      }
   }

   // case: <variant,one> const
   GIVEN("Testing Node.child(Child<variant,one>[+filter][,found]) const") {
      // c: const <reactions> node
      const Node &c = tree(misc::child::reactionSuite,misc::child::reactions);

      const Child<std::variant<int,reaction_t,double>,Allow::one>
         reaction("reaction");
      const Child<std::variant<double,nonsense_t,int>,Allow::one>
         nonsense("nonsense");

      // For brevity
      using R = reaction_t;
      using N = nonsense_t;

      THEN("child(Child) const works") {
         CHECK(c.child<R>(reaction).label == "n + O16");
         CHECK(c.child<R>(reaction).ENDF_MT == 2);
      }

      THEN("child(Child,found) const works") {
         bool found = false;
         CHECK((c.child<R>(reaction,found).label == "n + O16" && found));
         found = false;
         CHECK((c.child<R>(reaction,found).ENDF_MT == 2 && found));
         found = true;
         c.child<N>(nonsense,found);
         CHECK(!found);
      }

      THEN("child(Child+filter) const works") {
         CHECK(c.child<R>(reaction+twon).label == "2n + O15 + photon");
         CHECK(c.child<R>(reaction+twon).ENDF_MT == 16);
      }

      THEN("child(Child+filter,found) const works") {
         bool found = false;
         CHECK(c.child<R>(reaction+twon,found).label == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c.child<R>(reaction+twon,found).ENDF_MT == 16 && found));
         found = true;
         c.child<N>(nonsense+twon,found);
         CHECK(!found);
      }
   }

   // case: <type,many> const
   GIVEN("Testing Node.child(Child<type,many>[+filter][,found]) const") {
      // c: const <reactions> node
      const Node &c = tree(misc::child::reactionSuite,misc::child::reactions);

      const Child<reaction_t,Allow::many> reaction("reaction");
      const Child<nonsense_t,Allow::many> nonsense("nonsense");

      THEN("child(Child) const works") {
         CHECK(c.child(reaction).size() == 60);
         CHECK(c.child(reaction)[0].label == "n + O16");
         CHECK(c.child(reaction)[0].ENDF_MT == 2);
      }

      THEN("child(Child,found) const works") {
         bool found = false;
         CHECK((c.child(reaction,found).size() == 60 && found));
         found = false;
         CHECK((c.child(reaction,found)[0].label == "n + O16" && found));
         found = false;
         CHECK((c.child(reaction,found)[0].ENDF_MT == 2 && found));
         found = true;
         c.child(nonsense,found)[0];
         CHECK(!found);
      }

      THEN("child(Child+filter) const works") {
         CHECK(c.child(reaction+twon).size() == 2);
         CHECK(c.child(reaction+twon)[0].label == "2n + O15 + photon");
         CHECK(c.child(reaction+twon)[0].ENDF_MT == 16);
         CHECK(c.child(reaction+twon)[1].label == "2n + H1 + N14 + photon");
         CHECK(c.child(reaction+twon)[1].ENDF_MT == 41);
      }

      THEN("child(Child+filter,found) const works") {
         bool found = false;
         CHECK((c.child(reaction+twon,found).size() == 2 && found));
         found = false;
         CHECK(c.child(reaction+twon,found)[0].label == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c.child(reaction+twon,found)[0].ENDF_MT == 16 && found));
         found = true;
         c.child(nonsense+twon,found);
         CHECK(!found);
      }
   }

   // case: <variant,many> const
   GIVEN("Testing Node.child(Child<variant,many>[+filter][,found]) const") {

      // c: const <reactions> node
      const Node &c = tree(misc::child::reactionSuite,misc::child::reactions);

      const Child<std::variant<int,reaction_t,double>,Allow::many>
         reaction("reaction");
      const Child<std::variant<double,nonsense_t,int>,Allow::many>
         nonsense("nonsense");

      // For brevity
      using R = reaction_t;
      using N = nonsense_t;

      THEN("child(Child) const works") {
         CHECK(c.child<R>(reaction).size() == 60);
         CHECK(c.child<R>(reaction)[0].label == "n + O16");
         CHECK(c.child<R>(reaction)[0].ENDF_MT == 2);
      }

      THEN("child(Child,found) const works") {
         bool found = false;
         CHECK((c.child<R>(reaction,found).size() == 60 && found));
         found = false;
         CHECK((c.child<R>(reaction,found)[0].label == "n + O16" && found));
         found = false;
         CHECK((c.child<R>(reaction,found)[0].ENDF_MT == 2 && found));
         found = true;
         c.child<N>(nonsense,found)[0];
         CHECK(!found);
      }

      THEN("child(Child+filter) const works") {
         CHECK(c.child<R>(reaction+twon).size() == 2);
         CHECK(c.child<R>(reaction+twon)[0].label == "2n + O15 + photon");
         CHECK(c.child<R>(reaction+twon)[0].ENDF_MT == 16);
         CHECK(c.child<R>(reaction+twon)[1].label == "2n + H1 + N14 + photon");
         CHECK(c.child<R>(reaction+twon)[1].ENDF_MT == 41);
      }

      THEN("child(Child+filter,found) const works") {
         bool found = false;
         CHECK((c.child<R>(reaction+twon,found).size() == 2 && found));
         found = false;
         CHECK(c.child<R>(reaction+twon,found)[0].label == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c.child<R>(reaction+twon,found)[0].ENDF_MT == 16 && found));
         found = true;
         c.child<N>(nonsense+twon,found);
         CHECK(!found);
      }
   }
}
