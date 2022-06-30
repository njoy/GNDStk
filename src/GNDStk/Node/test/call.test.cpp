
#include "catch.hpp"
#include "GNDStk.hpp"
#include "GNDStk/test/keys.hpp"
using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// reaction_t
// nonsense_t
// For use in some of the tests
// -----------------------------------------------------------------------------

struct reaction_t;
struct nonsense_t;

struct reaction_t {
   // For the purposes of our testing, let's just have label and ENDF_MT.
   // A real reaction_t structure would of course contain much more.
   std::string label;
   int ENDF_MT;
};

void convert(const Node &n, reaction_t &r);

struct nonsense_t {
};

void convert(const Node &n, nonsense_t &r);


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


// -----------------------------------------------------------------------------
// numeric_string
// -----------------------------------------------------------------------------

static const std::string numeric_string =
R"***(1e-05
1.1e+06
1.6505e+06
1.744e+06
1.9e+06
2.84e+06
3.209e+06
3.755e+06
4.45e+06
4.5935e+06
4.82e+06
5.35e+06
5.694e+06
6.0715e+06
6.378e+06
6.683e+06
7.42e+06
8.42e+06
9.675e+06
1.17e+07
1.389e+07
1.81e+07
2.65e+07
1.06e+08

1e-05
1.1e+06
1.6505e+06
1.744e+06
1.9e+06
2.84e+06
3.209e+06
3.755e+06
4.45e+06
4.5935e+06
4.82e+06
5.35e+06
5.694e+06
6.0715e+06
6.378e+06
6.683e+06
7.42e+06
8.42e+06
9.675e+06
1.17e+07
1.389e+07
1.81e+07
2.65e+07
1.06e+08

1e-05
1.1e+06
1.6505e+06
1.744e+06
1.9e+06
2.84e+06
3.209e+06
3.755e+06
4.45e+06
4.5935e+06
4.82e+06
5.35e+06
5.694e+06
6.0715e+06
6.378e+06
6.683e+06
7.42e+06
8.42e+06
9.675e+06
1.17e+07
1.389e+07
1.81e+07
2.65e+07
1.06e+08

1e-05
1.1e+06
1.6505e+06
1.744e+06
1.9e+06
2.84e+06
3.209e+06
3.755e+06
4.45e+06
4.5935e+06
4.82e+06
5.35e+06
5.694e+06
6.0715e+06
6.378e+06
6.683e+06
7.42e+06
8.42e+06
9.675e+06
1.17e+07
1.389e+07
1.81e+07
2.65e+07
1.06e+08

1e-05
1.1e+06
1.6505e+06
1.744e+06
1.9e+06
2.84e+06
3.209e+06
3.755e+06
4.45e+06
4.5935e+06
4.82e+06
5.35e+06
5.694e+06
6.0715e+06
6.378e+06
6.683e+06
7.42e+06
8.42e+06
9.675e+06
1.17e+07
1.389e+07
1.81e+07
2.65e+07
1.06e+08

1e-05
1.1e+06
1.6505e+06
1.744e+06
1.9e+06
2.84e+06
3.209e+06
3.755e+06
4.45e+06
4.5935e+06
4.82e+06
5.35e+06
5.694e+06
6.0715e+06
6.378e+06
6.683e+06
7.42e+06
8.42e+06
9.675e+06
1.17e+07
1.389e+07
1.81e+07
2.65e+07
1.06e+08

1e-05
1.1e+06
1.6505e+06
1.744e+06
1.9e+06
2.84e+06
3.209e+06
3.755e+06
4.45e+06
4.5935e+06
4.82e+06
5.35e+06
5.694e+06
6.0715e+06
6.378e+06
6.683e+06
7.42e+06
8.42e+06
9.675e+06
1.17e+07
1.389e+07
1.81e+07
2.65e+07
1.06e+08

1e-05, 3.7939
1.6505e+06, 8.9205
1.9e+06, 3.03608
3.209e+06, 2.80248
4.45e+06, 1.80596
4.82e+06, 1.52328
5.694e+06, 1.56097
6.378e+06, 1.26616
7.42e+06, 0.795699
9.675e+06, 0.721606
1.389e+07, 0.99579
2.65e+07, 1.02923
)***";


// -----------------------------------------------------------------------------
// Scenario
// Test operator() cases; except multi-queries are in another scenario.
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk::Node's operator()") {

   // tree
   Tree tree("n-008_O_016.xml");

   // Child objects with Allow::one
   auto temperature = Child<temperature_t,Allow::one>("temperature");
   auto styles = Child<void,Allow::one>("styles");

   // Child objects with Allow::many
   auto isotope = Child<isotope_t,Allow::many>("isotope");
   auto isotope_node = Child<void,Allow::many>("isotope");

   GIVEN("The top-level node from a tree object") {

      // top-level GNDS node, const and non-const
      const Node &ctop = tree.top();
      Node &top = tree.top();

      // Below, we'll exercise every variation of Node::operator()

      THEN("Node::operator() with no arguments returns *this") {
         CHECK(&top == &top());
         CHECK(&ctop == &ctop());
      }

      THEN("Calling Node.top(Child,Child,Meta) gives us a metadatum") {
         CHECK(top.has(
            misc::child::styles,
            --misc::child::evaluated,
            temperature
         ));

         auto temp = top(
            misc::child::styles,   // from GNDStk
            --misc::child::evaluated, // from GNDStk
            temperature // ours, as set up earlier
         );
         CHECK(temp.value == 0.0);
         CHECK(temp.unit  == "K");
      }

      THEN("Calling Node.top(Child,...,Child) gives us a child node") {
         auto &styles_const = ctop(styles);
         CHECK(styles_const.metadata.size() == 0);
         CHECK(styles_const.children.size() == 1);

         auto &styles_nonconst = top(styles);
         CHECK(styles_nonconst.metadata.size() == 0);
         CHECK(styles_nonconst.children.size() == 1);

         auto iso = top( // non-const
            misc::child::PoPs,
            misc::child::chemicalElements,
            misc::child::chemicalElement
         )[0](
            misc::child::isotopes,
            isotope
         );
         CHECK(iso.size() == 3);
         CHECK(iso[0].symbol == "H1");  CHECK(iso[0].A == 1);
         CHECK(iso[1].symbol == "H2");  CHECK(iso[1].A == 2);
         CHECK(iso[2].symbol == "H3");  CHECK(iso[2].A == 3);

         auto iso_node = ctop( // const
            misc::child::PoPs,
            misc::child::chemicalElements,
            misc::child::chemicalElement
         )[0](
            misc::child::isotopes,
            isotope_node
         );
         CHECK(iso_node.size() == 3);
         CHECK(iso_node[0].name == "isotope");
         CHECK(iso_node[1].name == "isotope");
         CHECK(iso_node[2].name == "isotope");
      }

      THEN("Calling Node.top(Meta) gives us a metadatum") {
         const Meta<char> projectile("projectile");
         CHECK(ctop(projectile) == 'n');

         // "projectile" is found
         bool found = false;
         ctop(projectile,found);
         CHECK(found);

         // "bar" is not found
         const Meta<char> foo("bar");
         found = true;
         ctop(foo,found);
         CHECK(!found);

         // should get a reference back for the non-const version
         // of the Node, when () is invoked with a <void> Meta
         const Meta<void> proj("projectile");
         top(proj) = "N"; // was "n"
         CHECK(ctop(projectile) == 'N');
      }
   }


   // ------------------------
   // Try various Node
   // operator() cases
   // ------------------------

   using misc::child::reactionSuite;
   using misc::child::reactions;
   using misc::meta::label;
   using misc::meta::ENDF_MT;

   const char *const twon = "2n + O15 + photon";

   // case: <void,one>
   GIVEN("Testing Node(Child<void,one>[,string][,found])") {
      // n: non-const <reactions> node
      Node &n = tree(reactionSuite,reactions);

      const Child<void,Allow::one> reaction("reaction");
      const Child<void,Allow::one> nonsense("nonsense");

      THEN("(Child) works") {
         // reference return; so, its address is available
         (void)&n(reaction);
         // Note: the n(reaction) instances below - not the further label or
         // ENDF_MT accesses - are really the tests. n(reaction) gives us a
         // non-const Node &, from which we should be able to do the rest
         CHECK(n(reaction)(label) == "n + O16");
         CHECK(n(reaction)(ENDF_MT) == 2);
         n(reaction)(-ENDF_MT) = "0"; // non-const; can set
         CHECK(n(reaction)(ENDF_MT) == 0);
         n(reaction)(-ENDF_MT) = "2"; // revert
         CHECK(n(reaction)(ENDF_MT) == 2);
      }

      THEN("(Child,found) works") {
         bool found = false;
         (void)&n(reaction,found);
         CHECK(found);
         found = false;
         CHECK((n(reaction,found)(label) == "n + O16" && found));
         found = false;
         CHECK((n(reaction,found)(ENDF_MT) == 2 && found));
         n(reaction,found)(-ENDF_MT) = "0";
         found = false;
         CHECK((n(reaction,found)(ENDF_MT) == 0 && found));
         n(reaction,found)(-ENDF_MT) = "2";
         found = false;
         CHECK((n(reaction,found)(ENDF_MT) == 2 && found));
         // <reaction> was found, above, but <nonsense> shouldn't be...
         found = true;
         (void)&n(nonsense,found);
         CHECK(!found);
      }

      THEN("(Child,string) works") {
         (void)&n(reaction,twon);
         CHECK(n(reaction,twon)(label) == "2n + O15 + photon");
         CHECK(n(reaction,twon)(ENDF_MT) == 16);
         n(reaction,twon)(-ENDF_MT) = "0";
         CHECK(n(reaction,twon)(ENDF_MT) == 0);
         n(reaction,twon)(-ENDF_MT) = "16";
         CHECK(n(reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(Child,string,found) works") {
         bool found = false;
         (void)&n(reaction,twon,found);
         CHECK(found);
         found = false;
         CHECK(n(reaction,twon,found)(label) == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((n(reaction,twon,found)(ENDF_MT) == 16 && found));
         n(reaction,twon,found)(-ENDF_MT) = "0";
         found = false;
         CHECK((n(reaction,twon,found)(ENDF_MT) == 0 && found));
         n(reaction,twon,found)(-ENDF_MT) = "16";
         found = false;
         CHECK((n(reaction,twon,found)(ENDF_MT) == 16 && found));
         found = true;
         (void)&n(nonsense,twon,found);
         CHECK(!found);
      }
   }

   // case: <void,one> const
   // Like the above, except this one is const
   GIVEN("Testing Node(Child<void,one>[,string][,found]) const") {
      // c: const <reactions> node
      const Node &c = tree(reactionSuite,reactions);

      const Child<void,Allow::one> reaction("reaction");
      const Child<void,Allow::one> nonsense("nonsense");

      THEN("(Child) const works") {
         (void)&c(reaction);
         CHECK(c(reaction)(label) == "n + O16");
         CHECK(c(reaction)(ENDF_MT) == 2);
      }

      THEN("(Child,found) const works") {
         bool found = false;
         (void)&c(reaction,found);
         CHECK(found);
         found = false;
         CHECK((c(reaction,found)(label) == "n + O16" && found));
         found = false;
         CHECK((c(reaction,found)(ENDF_MT) == 2 && found));
         found = true;
         (void)&c(nonsense,found);
         CHECK(!found);
      }

      THEN("(Child,string) const works") {
         (void)&c(reaction,twon);
         CHECK(c(reaction,twon)(label) == "2n + O15 + photon");
         CHECK(c(reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(Child,string,found) const works") {
         bool found = false;
         (void)&c(reaction,twon,found);
         CHECK(found);
         found = false;
         CHECK(c(reaction,twon,found)(label) == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(reaction,twon,found)(ENDF_MT) == 16 && found));
         found = true;
         (void)&c(nonsense,twon,found);
         CHECK(!found);
      }
   }

   // case: <void,many> const
   GIVEN("Testing Node(Child<void,many>[,string][,found]) const") {
      // c: const <reactions> node
      const Node &c = tree(reactionSuite,reactions);

      const Child<void,Allow::many> reaction("reaction");
      const Child<void,Allow::many> nonsense("nonsense");

      THEN("(Child) const works") {
         CHECK(c(reaction).size() == 60);
         CHECK(c(reaction)[0](label) == "n + O16");
         CHECK(c(reaction)[0](ENDF_MT) == 2);
      }

      THEN("(Child,found) const works") {
         bool found = false;
         CHECK((c(reaction,found).size() == 60 && found));
         found = false;
         CHECK((c(reaction,found)[0](label) == "n + O16" && found));
         found = false;
         CHECK((c(reaction,found)[0](ENDF_MT) == 2 && found));
         found = true;
         CHECK((c(nonsense,found).size() == 0 && !found));
      }

      THEN("(Child,string) const works") {
         CHECK(c(reaction,twon)(label) == "2n + O15 + photon");
         CHECK(c(reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(Child,string,found) const works") {
         bool found = false;
         CHECK(c(reaction,twon,found)(label) == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(reaction,twon,found)(ENDF_MT) == 16 && found));
         found = true;
         CHECK((c(nonsense,twon,found), !found));
      }
   }

   // case: <type,one> const
   GIVEN("Testing Node(Child<type,one>[,string][,found]) const") {
      // c: const <reactions> node
      const Node &c = tree(reactionSuite,reactions);

      const Child<reaction_t,Allow::one> reaction("reaction");
      const Child<nonsense_t,Allow::one> nonsense("nonsense");

      THEN("(Child) const works") {
         CHECK(c(reaction).label == "n + O16");
         CHECK(c(reaction).ENDF_MT == 2);
      }

      THEN("(Child,found) const works") {
         bool found = false;
         CHECK((c(reaction,found).label == "n + O16" && found));
         found = false;
         CHECK((c(reaction,found).ENDF_MT == 2 && found));
         found = true;
         c(nonsense,found);
         CHECK(!found);
      }

      THEN("(Child,string) const works") {
         CHECK(c(reaction,twon).label == "2n + O15 + photon");
         CHECK(c(reaction,twon).ENDF_MT == 16);
      }

      THEN("(Child,string,found) const works") {
         bool found = false;
         CHECK(c(reaction,twon,found).label == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(reaction,twon,found).ENDF_MT == 16 && found));
         found = true;
         c(nonsense,twon,found);
         CHECK(!found);
      }
   }

   // case: <type,many> const
   GIVEN("Testing Node(Child<type,many>[,string][,found]) const") {
      // c: const <reactions> node
      const Node &c = tree(reactionSuite,reactions);

      const Child<reaction_t,Allow::many> reaction("reaction");
      const Child<nonsense_t,Allow::many> nonsense("nonsense");

      THEN("child(Child) const works") {
         CHECK(c(reaction).size() == 60);
         CHECK(c(reaction)[0].label == "n + O16");
         CHECK(c(reaction)[0].ENDF_MT == 2);
      }

      THEN("child(Child,found) const works") {
         bool found = false;
         CHECK((c(reaction,found).size() == 60 && found));
         found = false;
         CHECK((c(reaction,found)[0].label == "n + O16" && found));
         found = false;
         CHECK((c(reaction,found)[0].ENDF_MT == 2 && found));
         found = true;
         c(nonsense,found)[0];
         CHECK(!found);
      }

      THEN("child(Child,string) const works") {
         CHECK(c(reaction,twon).label == "2n + O15 + photon");
         CHECK(c(reaction,twon).ENDF_MT == 16);
      }

      THEN("child(Child,string,found) const works") {
         bool found = false;
         CHECK(c(reaction,twon,found).label == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(reaction,twon,found).ENDF_MT == 16 && found));
         found = true;
         c(nonsense,twon,found);
         CHECK(!found);
      }
   }


   // ------------------------
   // Like the above, but with
   // prefixed (reactionSuite,
   // reactions,...), in order
   // to test multi-argument
   // operators()
   // ------------------------

   // for brevity
   auto suite = reactionSuite;

   // case: <void,one>
   GIVEN("Testing Node(Child<void,one>[,string][,found])") {
      // n: non-const <reactions> node
      Tree &n = tree;

      const Child<void,Allow::one> reaction("reaction");
      const Child<void,Allow::one> nonsense("nonsense");

      THEN("(Child) works") {
         (void)&n(suite,reactions,reaction);
         CHECK(n(suite,reactions,reaction)(label) == "n + O16");
         CHECK(n(suite,reactions,reaction)(ENDF_MT) == 2);
         n(suite,reactions,reaction)(-ENDF_MT) = "0"; // non-const; can set
         CHECK(n(suite,reactions,reaction)(ENDF_MT) == 0);
         n(suite,reactions,reaction)(-ENDF_MT) = "2"; // revert
         CHECK(n(suite,reactions,reaction)(ENDF_MT) == 2);
      }

      THEN("(Child,found) works") {
         bool found = false;
         (void)&n(suite,reactions,reaction,found);
         CHECK(found);
         found = false;
         CHECK((n(suite,reactions,reaction,found)(label) == "n + O16"
                && found));
         found = false;
         CHECK((n(suite,reactions,reaction,found)(ENDF_MT) == 2
                && found));
         n(suite,reactions,reaction,found)(-ENDF_MT) = "0";
         found = false;
         CHECK((n(suite,reactions,reaction,found)(ENDF_MT) == 0
                && found));
         n(suite,reactions,reaction,found)(-ENDF_MT) = "2";
         found = false;
         CHECK((n(suite,reactions,reaction,found)(ENDF_MT) == 2
                && found));
         // <reaction> was found, above, but <nonsense> shouldn't be...
         found = true;
         (void)&n(suite,reactions,nonsense,found);
         CHECK(!found);
      }

      THEN("(Child,string) works") {
         (void)&n(suite,reactions,reaction,twon);
         CHECK(n(suite,reactions,reaction,twon)(label) == "2n + O15 + photon");
         CHECK(n(suite,reactions,reaction,twon)(ENDF_MT) == 16);
         n(suite,reactions,reaction,twon)(-ENDF_MT) = "0";
         CHECK(n(suite,reactions,reaction,twon)(ENDF_MT) == 0);
         n(suite,reactions,reaction,twon)(-ENDF_MT) = "16";
         CHECK(n(suite,reactions,reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(Child,string,found) works") {
         bool found = false;
         (void)&n(suite,reactions,reaction,twon,found);
         CHECK(found);
         found = false;
         CHECK(n(suite,reactions,reaction,twon,found)(label)
               == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((n(suite,reactions,reaction,twon,found)(ENDF_MT) == 16
                && found));
         n(suite,reactions,reaction,twon,found)(-ENDF_MT) = "0";
         found = false;
         CHECK((n(suite,reactions,reaction,twon,found)(ENDF_MT) == 0
                && found));
         n(suite,reactions,reaction,twon,found)(-ENDF_MT) = "16";
         found = false;
         CHECK((n(suite,reactions,reaction,twon,found)(ENDF_MT) == 16
                && found));
         found = true;
         (void)&n(suite,reactions,nonsense,twon,found);
         CHECK(!found);
      }
   }

   // case: <void,one> const
   // Like the above, except this one is const
   GIVEN("Testing Node(Child<void,one>[,string][,found]) const") {
      // c: const <reactions> node
      const Tree &c = tree;

      const Child<void,Allow::one> reaction("reaction");
      const Child<void,Allow::one> nonsense("nonsense");

      THEN("(Child) const works") {
         (void)&c(suite,reactions,reaction);
         CHECK(c(suite,reactions,reaction)(label) == "n + O16");
         CHECK(c(suite,reactions,reaction)(ENDF_MT) == 2);
      }

      THEN("(Child,found) const works") {
         bool found = false;
         (void)&c(suite,reactions,reaction,found);
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,found)(label) == "n + O16"
                && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)(ENDF_MT) == 2
                && found));
         found = true;
         (void)&c(suite,reactions,nonsense,found);
         CHECK(!found);
      }

      THEN("(Child,string) const works") {
         (void)&c(suite,reactions,reaction,twon);
         CHECK(c(suite,reactions,reaction,twon)(label) == "2n + O15 + photon");
         CHECK(c(suite,reactions,reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(Child,string,found) const works") {
         bool found = false;
         (void)&c(suite,reactions,reaction,twon,found);
         CHECK(found);
         found = false;
         CHECK(c(suite,reactions,reaction,twon,found)(label)
               == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,twon,found)(ENDF_MT) == 16
                && found));
         found = true;
         (void)&c(suite,reactions,nonsense,twon,found);
         CHECK(!found);
      }
   }

   // case: <void,many> const
   GIVEN("Testing Node(Child<void,many>[,string][,found]) const") {
      // c: const <reactions> node
      const Tree &c = tree;

      const Child<void,Allow::many> reaction("reaction");
      const Child<void,Allow::many> nonsense("nonsense");

      THEN("(Child) const works") {
         CHECK(c(suite,reactions,reaction).size() == 60);
         CHECK(c(suite,reactions,reaction)[0](label) == "n + O16");
         CHECK(c(suite,reactions,reaction)[0](ENDF_MT) == 2);
      }

      THEN("(Child,found) const works") {
         bool found = false;
         CHECK((c(suite,reactions,reaction,found).size() == 60
                && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)[0](label) == "n + O16"
                && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)[0](ENDF_MT) == 2
                && found));
         found = true;
         CHECK((c(suite,reactions,nonsense,found).size() == 0
                && !found));
      }

      THEN("(Child,string) const works") {
         CHECK(c(suite,reactions,reaction,twon)(label) == "2n + O15 + photon");
         CHECK(c(suite,reactions,reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(Child,string,found) const works") {
         bool found = false;
         CHECK(c(suite,reactions,reaction,twon,found)(label)
               == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,twon,found)(ENDF_MT) == 16
                && found));
         found = true;
         CHECK((c(suite,reactions,nonsense,twon,found), !found));
      }
   }

   // case: <type,one> const
   GIVEN("Testing Node(Child<type,one>[,string][,found]) const") {
      // c: const <reactions> node
      const Tree &c = tree;

      const Child<reaction_t,Allow::one> reaction("reaction");
      const Child<nonsense_t,Allow::one> nonsense("nonsense");

      THEN("(Child) const works") {
         CHECK(c(suite,reactions,reaction).label == "n + O16");
         CHECK(c(suite,reactions,reaction).ENDF_MT == 2);
      }

      THEN("(Child,found) const works") {
         bool found = false;
         CHECK((c(suite,reactions,reaction,found).label == "n + O16" && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found).ENDF_MT == 2 && found));
         found = true;
         CHECK(!c.has(suite,reactions,nonsense));
         c(suite,reactions,nonsense,found);
         CHECK(!found);
      }

      THEN("(Child,string) const works") {
         CHECK(c(suite,reactions,reaction,twon).label == "2n + O15 + photon");
         CHECK(c(suite,reactions,reaction,twon).ENDF_MT == 16);
      }

      THEN("(Child,string,found) const works") {
         bool found = false;
         CHECK(c(suite,reactions,reaction,twon,found).label
               == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,twon,found).ENDF_MT == 16 && found));
         found = true;
         c(suite,reactions,nonsense,twon,found);
         CHECK(!found);
      }
   }

   // case: <type,many> const
   GIVEN("Testing Node(Child<type,many>[,string][,found]) const") {
      // c: const <reactions> node
      const Tree &c = tree;

      const Child<reaction_t,Allow::many> reaction("reaction");
      const Child<nonsense_t,Allow::many> nonsense("nonsense");

      THEN("child(Child) const works") {
         CHECK(c(suite,reactions,reaction).size() == 60);
         CHECK(c(suite,reactions,reaction)[0].label == "n + O16");
         CHECK(c(suite,reactions,reaction)[0].ENDF_MT == 2);
      }

      THEN("child(Child,found) const works") {
         bool found = false;
         CHECK((c(suite,reactions,reaction,found).size() == 60
                && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)[0].label == "n + O16"
                && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)[0].ENDF_MT == 2
                && found));
         found = true;
         c(suite,reactions,nonsense,found)[0];
         CHECK(!found);
      }

      THEN("child(Child,string) const works") {
         CHECK(c(suite,reactions,reaction,twon).label == "2n + O15 + photon");
         CHECK(c(suite,reactions,reaction,twon).ENDF_MT == 16);
      }

      THEN("child(Child,string,found) const works") {
         bool found = false;
         CHECK(c(suite,reactions,reaction,twon,found).label
               == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,twon,found).ENDF_MT == 16
                && found));
         found = true;
         c(suite,reactions,nonsense,twon,found);
         CHECK(!found);
      }
   }


   // ------------------------
   // Test our numeric<>
   // variable template
   // ------------------------

   GIVEN("Testing Node(numeric<*>) for various *") {
      const Node n = tree(
         basic::child::reactionSuite,
         basic::child::reactions,
         basic::child::reaction, "n + O16",
         basic::child::crossSection,
         basic::child::XYs1d, "eval",
       --basic::child::values
      );

      using misc::numeric;
      using misc::doubles;
      using misc::floats;
      std::ostringstream oss;

      // I'll only print every [stride] vector elements from the vectors
      // as extracted below, so as not to have a gigantic string to compare
      // with. There's nothing wrong with gigantic strings, except that I
      // don't want to hardcode, in this or any test file, a literal string
      // that's hundreds of pages long! :-)
      const int stride = 200;
      int count;

      // numeric<> ==> vector<double>
      count = 0;
      for (auto v : n(numeric<>))
         if (count++ % stride == 0) oss << v << std::endl;
      oss << std::endl;

      // numeric<double> ==> vector<double>
      count = 0;
      for (auto v : n(numeric<double>))
         if (count++ % stride == 0) oss << v << std::endl;
      oss << std::endl;

      // doubles: same as numeric<double>
      count = 0;
      for (auto v : n(doubles))
         if (count++ % stride == 0) oss << v << std::endl;
      oss << std::endl;

      // numeric<float> ==> vector<float>
      count = 0;
      for (auto v : n(numeric<float>))
         if (count++ % stride == 0) oss << v << std::endl;
      oss << std::endl;

      // floats: same as numeric<float>
      count = 0;
      for (auto v : n(floats))
         if (count++ % stride == 0) oss << v << std::endl;
      oss << std::endl;

      // numeric<vector<double>> ==> vector<double>
      count = 0;
      for (auto v : n(numeric<std::vector<double>>))
         if (count++ % stride == 0) oss << v << std::endl;
      oss << std::endl;

      // numeric<vector<float>> ==> vector<float>
      count = 0;
      for (auto v : n(numeric<std::vector<float>>))
         if (count++ % stride == 0) oss << v << std::endl;
      oss << std::endl;

      // numeric<vector<pair<double,double>>> ==> vector<pair<double,double>>
      count = 0;
      for (auto v : n(numeric<std::vector<std::pair<double,double>>>))
         if (count++ % stride == 0)
            oss << v.first << ", " << v.second << std::endl;

      CHECK(oss.str() == numeric_string);
   } // GIVEN
}


// -----------------------------------------------------------------------------
// Scenario
// Test multi-query operator().
// -----------------------------------------------------------------------------

// test string
static const std::string xmlstring =
R"***(
<foo a="123" b="4.56">
   <bar label="xyz" x="one"   y="two"  z="1"  ></bar>
   <bar label="zyx" x="three" y="four" z="2"  ></bar>
   <baz label="ijk" i="eye"   j="jay"  k="kay"></baz>
   <baz label="lmn" l="ell"   m="m"    n="n"  ></baz>
   <boo label="jane" a="321"/>
   <boo label="john" b="6.54"/>
</foo>
)***";

// SCENARIO
SCENARIO("Testing GNDStk::Node's operator() for multi-queries") {

   // A Node
   Node node;
   node << xmlstring;
   std::cout << node << std::endl;

   // Meta objects
   const Meta<int> a("a");
   const Meta<double> b("b");
   const Meta<std::string> label("label");
   const Meta<std::string> x("x");
   const Meta<std::string> y("y");
   const Meta<int> z("z");
   const Meta<std::string> i("i");
   const Meta<std::string> j("j");
   const Meta<std::string> k("k");
   const Meta<std::string> l("l");
   const Meta<char> m("m");
   const Meta<char> n("n");

   // Child objects
   const Child<> bar("bar");
   const Child<> baz("baz");
   const Child<> boo("boo");

   /*
   ------------------------------------+------------------------------------
   Meta/Child | Meta/Child             |
   a. Meta  | Meta                     |  KeyTuple<Meta,Meta>
   b. Meta  | Child                    |  KeyTuple<Meta,Child>
   c. Child | Meta                     |  KeyTuple<Child,Meta>
   d. Child | Child                    |  KeyTuple<Child,Child>
   ------------------------------------+------------------------------------
   Child | string/regex                |
   a. Child | string                   |  KeyTuple<pair<Child,string>>
   b. Child | char *                   |  KeyTuple<pair<Child,string>>
   c. Child | regex                    |  KeyTuple<pair<Child,regex>>
   ------------------------------------+------------------------------------
   KeyTuple<...> | Meta/Child          |
   a. KeyTuple<...> | Meta             |  KeyTuple<...,Meta>
   b. KeyTuple<...> | Child            |  KeyTuple<...,Child>
   ------------------------------------+------------------------------------
   KeyTuple<...,Child> | string/regex  |
   a. KeyTuple<...,Child> | string     |  KeyTuple<...,pair<Child,string>>
   b. KeyTuple<...,Child> | char *     |  KeyTuple<...,pair<Child,string>>
   c. KeyTuple<...,Child> | regex      |  KeyTuple<...,pair<Child,regex>>
   ------------------------------------+------------------------------------
   */

   // ------------------------
   // or.hpp operator|, case 1
   // ------------------------

   GIVEN("Meta | Meta")
   {
      const auto tup = node(a | b);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup) == 123);
      CHECK(std::get<1>(tup) == 4.56);
   }

   GIVEN("Meta | Child")
   {
      const auto tup = node(a | bar);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup) == 123);
      CHECK(std::get<1>(tup).name == "bar");
   }

   GIVEN("Child | Meta")
   {
      const auto tup = node(bar | a);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "bar");
      CHECK(std::get<1>(tup) == 123);
   }

   GIVEN("Child | Child")
   {
      const auto tup = node(bar | baz);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "bar");
      CHECK(std::get<1>(tup).name == "baz");
   }

   // ------------------------
   // or.hpp operator|, case 2
   // ------------------------

   GIVEN("Child | string")
   {
      const auto tup = node(bar | std::string("xyz"));
      CHECK(std::tuple_size<decltype(tup)>{} == 1);
      CHECK(std::get<0>(tup).name == "bar");
      CHECK(std::get<0>(tup)(label) == "xyz");
   }

   GIVEN("Child | char *")
   {
      const auto tup = node(baz | "lmn");
      CHECK(std::tuple_size<decltype(tup)>{} == 1);
      CHECK(std::get<0>(tup).name == "baz");
      CHECK(std::get<0>(tup)(label) == "lmn");
   }

   GIVEN("Child | regex")
   {
      const auto tup = node(boo | std::regex("j[au]ne"));
      CHECK(std::tuple_size<decltype(tup)>{} == 1);
      CHECK(std::get<0>(tup).name == "boo");
      CHECK(std::get<0>(tup)(label) == "jane");
   }

   // ------------------------
   // or.hpp operator|, case 3
   // ------------------------

   GIVEN("KeyTuple<...> | Meta")
   {
      const auto tup = node(a | b | a);
      CHECK(std::tuple_size<decltype(tup)>{} == 3);
      CHECK(std::get<0>(tup) == 123);
      CHECK(std::get<1>(tup) == 4.56);
      CHECK(std::get<2>(tup) == 123);
   }

   GIVEN("KeyTuple<...> | Child")
   {
      const auto tup = node(a | b | bar);
      CHECK(std::tuple_size<decltype(tup)>{} == 3);
      CHECK(std::get<0>(tup) == 123);
      CHECK(std::get<1>(tup) == 4.56);
      CHECK(std::get<2>(tup).name == "bar");
   }

   GIVEN("KeyTuple<...,pair<Child,string>> | Meta")
   {
      const auto tup = node(baz | std::string("ijk") | a);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "baz");
      CHECK(std::get<0>(tup)(label) == "ijk");
      CHECK(std::get<1>(tup) == 123);
   }

   GIVEN("KeyTuple<...,pair<Child,char *>> | Meta")
   {
      const auto tup = node(baz | "lmn" | a);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "baz");
      CHECK(std::get<0>(tup)(label) == "lmn");
      CHECK(std::get<0>(tup)(m) == 'm');
      CHECK(std::get<0>(tup)(n) == 'n');
      CHECK(std::get<1>(tup) == 123);
   }

   GIVEN("KeyTuple<...,pair<Child,regex>> | Meta")
   {
      const auto tup = node(baz | std::regex("[kji]+") | a);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "baz");
      CHECK(std::get<0>(tup)(label) == "ijk");
      CHECK(std::get<1>(tup) == 123);
   }

   GIVEN("KeyTuple<...,pair<Child,string>> | Child")
   {
      const auto tup = node(baz | std::string("ijk") | bar);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "baz");
      CHECK(std::get<0>(tup)(label) == "ijk");
      CHECK(std::get<1>(tup).name == "bar");
   }

   GIVEN("KeyTuple<...,pair<Child,char *>> | Child")
   {
      const auto tup = node(baz | "lmn" | bar);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "baz");
      CHECK(std::get<0>(tup)(label) == "lmn");
      CHECK(std::get<1>(tup).name == "bar");
   }

   GIVEN("KeyTuple<...,pair<Child,regex>> | Child")
   {
      const auto tup = node(baz | std::regex("[kji]+") | bar);
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "baz");
      CHECK(std::get<0>(tup)(label) == "ijk");
      CHECK(std::get<1>(tup).name == "bar");
   }

   // ------------------------
   // or.hpp operator|, case 4
   // ------------------------

   GIVEN("KeyTuple<...,Child> | string")
   {
      const auto tup = node(bar | baz | std::string("ijk"));
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "bar");
      CHECK(std::get<1>(tup).name == "baz");
      CHECK(std::get<1>(tup)(label) == "ijk");
   }

   GIVEN("KeyTuple<...,Child> | char *")
   {
      const auto tup = node(bar | baz | "lmn");
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "bar");
      CHECK(std::get<1>(tup).name == "baz");
      CHECK(std::get<1>(tup)(label) == "lmn");
   }

   GIVEN("KeyTuple<...,Child> | regex")
   {
      const auto tup = node(bar | baz | std::regex("[kji]+"));
      CHECK(std::tuple_size<decltype(tup)>{} == 2);
      CHECK(std::get<0>(tup).name == "bar");
      CHECK(std::get<1>(tup).name == "baz");
      CHECK(std::get<1>(tup)(label) == "ijk");
   }

   // ------------------------
   // Miscellaneous fun stuff
   // ------------------------

   GIVEN("Various multi-queries")
   {
      {
         const auto tup = node(a | b | bar | baz | boo);
         CHECK(std::tuple_size<decltype(tup)>{} == 5);
         CHECK(std::get<0>(tup) == 123);
         CHECK(std::get<1>(tup) == 4.56);
         CHECK(std::get<2>(tup).name == "bar");
         CHECK(std::get<3>(tup).name == "baz");
         CHECK(std::get<4>(tup).name == "boo");
      }
      {
         const auto tup = node(bar,"xyz")(label | x | y | z);
         CHECK(std::tuple_size<decltype(tup)>{} == 4);
         CHECK(std::get<0>(tup) == "xyz");
         CHECK(std::get<1>(tup) == "one");
         CHECK(std::get<2>(tup) == "two");
         CHECK(std::get<3>(tup) == 1);
      }
      {
         const auto tup = node(bar,"zyx")(label | x | y | z);
         CHECK(std::tuple_size<decltype(tup)>{} == 4);
         CHECK(std::get<0>(tup) == "zyx");
         CHECK(std::get<1>(tup) == "three");
         CHECK(std::get<2>(tup) == "four");
         CHECK(std::get<3>(tup) == 2);
      }
      {
         const auto tup = node(baz,"ijk")(label | i | j | k);
         CHECK(std::tuple_size<decltype(tup)>{} == 4);
         CHECK(std::get<0>(tup) == "ijk");
         CHECK(std::get<1>(tup) == "eye");
         CHECK(std::get<2>(tup) == "jay");
         CHECK(std::get<3>(tup) == "kay");
      }
      {
         const auto tup = node(baz,"lmn")(label | l | m | n);
         CHECK(std::tuple_size<decltype(tup)>{} == 4);
         CHECK(std::get<0>(tup) == "lmn");
         CHECK(std::get<1>(tup) == "ell");
         CHECK(std::get<2>(tup) == 'm');
         CHECK(std::get<3>(tup) == 'n');
      }
      {
         const auto tup = node(boo,"jane")(label | a);
         CHECK(std::tuple_size<decltype(tup)>{} == 2);
         CHECK(std::get<0>(tup) == "jane");
         CHECK(std::get<1>(tup) == 321);
      }
      {
         const auto tup = node(boo,"john")(label | b);
         CHECK(std::tuple_size<decltype(tup)>{} == 2);
         CHECK(std::get<0>(tup) == "john");
         CHECK(std::get<1>(tup) == 6.54);
      }
   }
}
