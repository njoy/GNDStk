
#include "catch.hpp"
#include "GNDStk.hpp"
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

void convert(const node &n, reaction_t &r);

struct nonsense_t {
};

void convert(const node &n, nonsense_t &r);


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
// values_string
// -----------------------------------------------------------------------------

static const std::string values_string =
R"***(1e-05
460000
1.1e+06
1.45e+06
1.6505e+06
1.68916e+06
1.744e+06
1.833e+06
1.9e+06
2.26e+06
2.84e+06
2.985e+06
3.209e+06
3.4405e+06
3.755e+06
4.08e+06
4.45e+06
4.52e+06
4.5935e+06
4.626e+06
4.82e+06
5.119e+06
5.35e+06
5.57e+06
5.694e+06
5.976e+06
6.0715e+06
6.155e+06
6.378e+06
6.49e+06
6.683e+06
7.07e+06
7.42e+06
7.92e+06
8.42e+06
8.92e+06
9.675e+06
1.071e+07
1.17e+07
1.32e+07
1.389e+07
1.585e+07
1.81e+07
2.065e+07
2.65e+07
5.3e+07
1.06e+08

1e-05
460000
1.1e+06
1.45e+06
1.6505e+06
1.68916e+06
1.744e+06
1.833e+06
1.9e+06
2.26e+06
2.84e+06
2.985e+06
3.209e+06
3.4405e+06
3.755e+06
4.08e+06
4.45e+06
4.52e+06
4.5935e+06
4.626e+06
4.82e+06
5.119e+06
5.35e+06
5.57e+06
5.694e+06
5.976e+06
6.0715e+06
6.155e+06
6.378e+06
6.49e+06
6.683e+06
7.07e+06
7.42e+06
7.92e+06
8.42e+06
8.92e+06
9.675e+06
1.071e+07
1.17e+07
1.32e+07
1.389e+07
1.585e+07
1.81e+07
2.065e+07
2.65e+07
5.3e+07
1.06e+08

1e-05
460000
1.1e+06
1.45e+06
1.6505e+06
1.68916e+06
1.744e+06
1.833e+06
1.9e+06
2.26e+06
2.84e+06
2.985e+06
3.209e+06
3.4405e+06
3.755e+06
4.08e+06
4.45e+06
4.52e+06
4.5935e+06
4.626e+06
4.82e+06
5.119e+06
5.35e+06
5.57e+06
5.694e+06
5.976e+06
6.0715e+06
6.155e+06
6.378e+06
6.49e+06
6.683e+06
7.07e+06
7.42e+06
7.92e+06
8.42e+06
8.92e+06
9.675e+06
1.071e+07
1.17e+07
1.32e+07
1.389e+07
1.585e+07
1.81e+07
2.065e+07
2.65e+07
5.3e+07
1.06e+08

1e-05
460000
1.1e+06
1.45e+06
1.6505e+06
1.68916e+06
1.744e+06
1.833e+06
1.9e+06
2.26e+06
2.84e+06
2.985e+06
3.209e+06
3.4405e+06
3.755e+06
4.08e+06
4.45e+06
4.52e+06
4.5935e+06
4.626e+06
4.82e+06
5.119e+06
5.35e+06
5.57e+06
5.694e+06
5.976e+06
6.0715e+06
6.155e+06
6.378e+06
6.49e+06
6.683e+06
7.07e+06
7.42e+06
7.92e+06
8.42e+06
8.92e+06
9.675e+06
1.071e+07
1.17e+07
1.32e+07
1.389e+07
1.585e+07
1.81e+07
2.065e+07
2.65e+07
5.3e+07
1.06e+08

1e-05
460000
1.1e+06
1.45e+06
1.6505e+06
1.68916e+06
1.744e+06
1.833e+06
1.9e+06
2.26e+06
2.84e+06
2.985e+06
3.209e+06
3.4405e+06
3.755e+06
4.08e+06
4.45e+06
4.52e+06
4.5935e+06
4.626e+06
4.82e+06
5.119e+06
5.35e+06
5.57e+06
5.694e+06
5.976e+06
6.0715e+06
6.155e+06
6.378e+06
6.49e+06
6.683e+06
7.07e+06
7.42e+06
7.92e+06
8.42e+06
8.92e+06
9.675e+06
1.071e+07
1.17e+07
1.32e+07
1.389e+07
1.585e+07
1.81e+07
2.065e+07
2.65e+07
5.3e+07
1.06e+08

1e-05, 3.7939
1.1e+06, 3.52665
1.6505e+06, 8.9205
1.744e+06, 1.67805
1.9e+06, 3.03608
2.84e+06, 1.09835
3.209e+06, 2.80248
3.755e+06, 3.89727
4.45e+06, 1.80596
4.5935e+06, 1.74252
4.82e+06, 1.52328
5.35e+06, 0.995682
5.694e+06, 1.56097
6.0715e+06, 1.31116
6.378e+06, 1.26616
6.683e+06, 0.825407
7.42e+06, 0.795699
8.42e+06, 0.618634
9.675e+06, 0.721606
1.17e+07, 1.0017
1.389e+07, 0.99579
1.81e+07, 1.03393
2.65e+07, 1.02923
1.06e+08, 0.301421
)***";


// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk Node operator()") {

   // tree
   Tree<> tree("n-008_O_016.xml");

   // keywords with find::one
   auto temperature = keyword.child<temperature_t,find::one>("temperature");
   auto styles = keyword.child<void,find::one>("styles");

   // keywords with find::all
   auto isotope = keyword.child<isotope_t,find::all>("isotope");
   auto isotope_node = keyword.child<void,find::all>("isotope");

   GIVEN("The top-level node from a tree object") {

      // top-level GNDS node, const and non-const
      const Node<> &ctop = tree.top();
      Node<> &top = tree.top();

      // Below, we'll exercise every variation of node::operator()

      THEN("Calling node.top(child_t,child_t,meta_t) gives us a metadatum") {
         auto temp = top(
            mixed::child::styles,   // from GNDStk
            mixed::child::evaluated, // from GNDStk
            temperature // ours, as set up earlier
            );
         CHECK(temp.value == 0.0);
         CHECK(temp.unit  == "K");
      }

      THEN("Calling node.top(child_t,...,child_t) gives us a child node") {
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
      }

      THEN("Calling node.top(meta_t) gives us a metadatum") {
         const meta_t<char> projectile("projectile");
         CHECK(ctop(projectile) == 'n');

         // "projectile" is found
         bool found = false;
         ctop(projectile,found);
         CHECK(found == true);

         // "bar" is not found
         const meta_t<char> foo("bar");
         found = true;
         ctop(foo,found);
         CHECK(found == false);

         // should get a reference back for the non-const version
         // of the node, when () is invoked with a <void> meta_t
         const meta_t<void> proj("projectile");
         top(proj) = "N"; // was "n"
         CHECK(ctop(projectile) == 'N');
      }
   }


   // ------------------------
   // Try various node
   // operator() cases
   // ------------------------

   using mixed::child::reactionSuite;
   using mixed::child::reactions;
   using mixed::meta::label;
   using mixed::meta::ENDF_MT;

   const char *const twon = "2n + O15 + photon";

   // case: <void,one>
   GIVEN("Testing node(child_t<void,one>[,string][,found])") {
      // n: non-const <reactions> node
      node &n = tree(reactionSuite,reactions);

      const child_t<void,find::one> reaction("reaction");
      const child_t<void,find::one> nonsense("nonsense");

      THEN("(child_t) works") {
         // reference return; so, its address is available
         (void)&n(reaction);
         // Note: the n(reaction) instances below - not the further label or
         // ENDF_MT accesses - are really the tests. n(reaction) gives us a
         // non-const node &, from which we should be able to do the rest
         CHECK(n(reaction)(label) == "n + O16");
         CHECK(n(reaction)(ENDF_MT) == 2);
         n(reaction)(-ENDF_MT) = "0"; // non-const; can set
         CHECK(n(reaction)(ENDF_MT) == 0);
         n(reaction)(-ENDF_MT) = "2"; // revert
         CHECK(n(reaction)(ENDF_MT) == 2);
      }

      THEN("(child_t,found) works") {
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

      THEN("(child_t,string) works") {
         (void)&n(reaction,twon);
         CHECK(n(reaction,twon)(label) == "2n + O15 + photon");
         CHECK(n(reaction,twon)(ENDF_MT) == 16);
         n(reaction,twon)(-ENDF_MT) = "0";
         CHECK(n(reaction,twon)(ENDF_MT) == 0);
         n(reaction,twon)(-ENDF_MT) = "16";
         CHECK(n(reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(child_t,string,found) works") {
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
   GIVEN("Testing node(child_t<void,one>[,string][,found]) const") {
      // c: const <reactions> node
      const node &c = tree(reactionSuite,reactions);

      const child_t<void,find::one> reaction("reaction");
      const child_t<void,find::one> nonsense("nonsense");

      THEN("(child_t) const works") {
         (void)&c(reaction);
         CHECK(c(reaction)(label) == "n + O16");
         CHECK(c(reaction)(ENDF_MT) == 2);
      }

      THEN("(child_t,found) const works") {
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

      THEN("(child_t,string) const works") {
         (void)&c(reaction,twon);
         CHECK(c(reaction,twon)(label) == "2n + O15 + photon");
         CHECK(c(reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(child_t,string,found) const works") {
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

   // case: <void,all> const
   GIVEN("Testing node(child_t<void,all>[,string][,found]) const") {
      // c: const <reactions> node
      const node &c = tree(reactionSuite,reactions);

      const child_t<void,find::all> reaction("reaction");
      const child_t<void,find::all> nonsense("nonsense");

      THEN("(child_t) const works") {
         CHECK(c(reaction).size() == 60);
         CHECK(c(reaction)[0](label) == "n + O16");
         CHECK(c(reaction)[0](ENDF_MT) == 2);
      }

      THEN("(child_t,found) const works") {
         bool found = false;
         CHECK((c(reaction,found).size() == 60 && found));
         found = false;
         CHECK((c(reaction,found)[0](label) == "n + O16" && found));
         found = false;
         CHECK((c(reaction,found)[0](ENDF_MT) == 2 && found));
         found = true;
         CHECK((c(nonsense,found).size() == 0 && !found));
      }

      THEN("(child_t,string) const works") {
         CHECK(c(reaction,twon)(label) == "2n + O15 + photon");
         CHECK(c(reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(child_t,string,found) const works") {
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
   GIVEN("Testing node(child_t<type,one>[,string][,found]) const") {
      // c: const <reactions> node
      const node &c = tree(reactionSuite,reactions);

      const child_t<reaction_t,find::one> reaction("reaction");
      const child_t<nonsense_t,find::one> nonsense("nonsense");

      THEN("(child_t) const works") {
         CHECK(c(reaction).label == "n + O16");
         CHECK(c(reaction).ENDF_MT == 2);
      }

      THEN("(child_t,found) const works") {
         bool found = false;
         CHECK((c(reaction,found).label == "n + O16" && found));
         found = false;
         CHECK((c(reaction,found).ENDF_MT == 2 && found));
         found = true;
         c(nonsense,found);
         CHECK(!found);
      }

      THEN("(child_t,string) const works") {
         CHECK(c(reaction,twon).label == "2n + O15 + photon");
         CHECK(c(reaction,twon).ENDF_MT == 16);
      }

      THEN("(child_t,string,found) const works") {
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

   // case: <type,all> const
   GIVEN("Testing node(child_t<type,all>[,string][,found]) const") {
      // c: const <reactions> node
      const node &c = tree(reactionSuite,reactions);

      const child_t<reaction_t,find::all> reaction("reaction");
      const child_t<nonsense_t,find::all> nonsense("nonsense");

      THEN("child(child_t) const works") {
         CHECK(c(reaction).size() == 60);
         CHECK(c(reaction)[0].label == "n + O16");
         CHECK(c(reaction)[0].ENDF_MT == 2);
      }

      THEN("child(child_t,found) const works") {
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

      THEN("child(child_t,string) const works") {
         CHECK(c(reaction,twon).label == "2n + O15 + photon");
         CHECK(c(reaction,twon).ENDF_MT == 16);
      }

      THEN("child(child_t,string,found) const works") {
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
   GIVEN("Testing node(child_t<void,one>[,string][,found])") {
      // n: non-const <reactions> node
      Tree<> &n = tree;

      const child_t<void,find::one> reaction("reaction");
      const child_t<void,find::one> nonsense("nonsense");

      THEN("(child_t) works") {
         (void)&n(suite,reactions,reaction);
         CHECK(n(suite,reactions,reaction)(label) == "n + O16");
         CHECK(n(suite,reactions,reaction)(ENDF_MT) == 2);
         n(suite,reactions,reaction)(-ENDF_MT) = "0"; // non-const; can set
         CHECK(n(suite,reactions,reaction)(ENDF_MT) == 0);
         n(suite,reactions,reaction)(-ENDF_MT) = "2"; // revert
         CHECK(n(suite,reactions,reaction)(ENDF_MT) == 2);
      }

      THEN("(child_t,found) works") {
         bool found = false;
         (void)&n(suite,reactions,reaction,found);
         CHECK(found);
         found = false;
         CHECK((n(suite,reactions,reaction,found)(label) == "n + O16" && found));
         found = false;
         CHECK((n(suite,reactions,reaction,found)(ENDF_MT) == 2 && found));
         n(suite,reactions,reaction,found)(-ENDF_MT) = "0";
         found = false;
         CHECK((n(suite,reactions,reaction,found)(ENDF_MT) == 0 && found));
         n(suite,reactions,reaction,found)(-ENDF_MT) = "2";
         found = false;
         CHECK((n(suite,reactions,reaction,found)(ENDF_MT) == 2 && found));
         // <reaction> was found, above, but <nonsense> shouldn't be...
         found = true;
         (void)&n(suite,reactions,nonsense,found);
         CHECK(!found);
      }

      THEN("(child_t,string) works") {
         (void)&n(suite,reactions,reaction,twon);
         CHECK(n(suite,reactions,reaction,twon)(label) == "2n + O15 + photon");
         CHECK(n(suite,reactions,reaction,twon)(ENDF_MT) == 16);
         n(suite,reactions,reaction,twon)(-ENDF_MT) = "0";
         CHECK(n(suite,reactions,reaction,twon)(ENDF_MT) == 0);
         n(suite,reactions,reaction,twon)(-ENDF_MT) = "16";
         CHECK(n(suite,reactions,reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(child_t,string,found) works") {
         bool found = false;
         (void)&n(suite,reactions,reaction,twon,found);
         CHECK(found);
         found = false;
         CHECK(n(suite,reactions,reaction,twon,found)(label) == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((n(suite,reactions,reaction,twon,found)(ENDF_MT) == 16 && found));
         n(suite,reactions,reaction,twon,found)(-ENDF_MT) = "0";
         found = false;
         CHECK((n(suite,reactions,reaction,twon,found)(ENDF_MT) == 0 && found));
         n(suite,reactions,reaction,twon,found)(-ENDF_MT) = "16";
         found = false;
         CHECK((n(suite,reactions,reaction,twon,found)(ENDF_MT) == 16 && found));
         found = true;
         (void)&n(suite,reactions,nonsense,twon,found);
         CHECK(!found);
      }
   }

   // case: <void,one> const
   // Like the above, except this one is const
   GIVEN("Testing node(child_t<void,one>[,string][,found]) const") {
      // c: const <reactions> node
      const Tree<> &c = tree;

      const child_t<void,find::one> reaction("reaction");
      const child_t<void,find::one> nonsense("nonsense");

      THEN("(child_t) const works") {
         (void)&c(suite,reactions,reaction);
         CHECK(c(suite,reactions,reaction)(label) == "n + O16");
         CHECK(c(suite,reactions,reaction)(ENDF_MT) == 2);
      }

      THEN("(child_t,found) const works") {
         bool found = false;
         (void)&c(suite,reactions,reaction,found);
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,found)(label) == "n + O16" && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)(ENDF_MT) == 2 && found));
         found = true;
         (void)&c(suite,reactions,nonsense,found);
         CHECK(!found);
      }

      THEN("(child_t,string) const works") {
         (void)&c(suite,reactions,reaction,twon);
         CHECK(c(suite,reactions,reaction,twon)(label) == "2n + O15 + photon");
         CHECK(c(suite,reactions,reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(child_t,string,found) const works") {
         bool found = false;
         (void)&c(suite,reactions,reaction,twon,found);
         CHECK(found);
         found = false;
         CHECK(c(suite,reactions,reaction,twon,found)(label) == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,twon,found)(ENDF_MT) == 16 && found));
         found = true;
         (void)&c(suite,reactions,nonsense,twon,found);
         CHECK(!found);
      }
   }

   // case: <void,all> const
   GIVEN("Testing node(child_t<void,all>[,string][,found]) const") {
      // c: const <reactions> node
      const Tree<> &c = tree;

      const child_t<void,find::all> reaction("reaction");
      const child_t<void,find::all> nonsense("nonsense");

      THEN("(child_t) const works") {
         CHECK(c(suite,reactions,reaction).size() == 60);
         CHECK(c(suite,reactions,reaction)[0](label) == "n + O16");
         CHECK(c(suite,reactions,reaction)[0](ENDF_MT) == 2);
      }

      THEN("(child_t,found) const works") {
         bool found = false;
         CHECK((c(suite,reactions,reaction,found).size() == 60 && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)[0](label) == "n + O16" && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)[0](ENDF_MT) == 2 && found));
         found = true;
         CHECK((c(suite,reactions,nonsense,found).size() == 0 && !found));
      }

      THEN("(child_t,string) const works") {
         CHECK(c(suite,reactions,reaction,twon)(label) == "2n + O15 + photon");
         CHECK(c(suite,reactions,reaction,twon)(ENDF_MT) == 16);
      }

      THEN("(child_t,string,found) const works") {
         bool found = false;
         CHECK(c(suite,reactions,reaction,twon,found)(label) == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,twon,found)(ENDF_MT) == 16 && found));
         found = true;
         CHECK((c(suite,reactions,nonsense,twon,found), !found));
      }
   }

   // case: <type,one> const
   GIVEN("Testing node(child_t<type,one>[,string][,found]) const") {
      // c: const <reactions> node
      const Tree<> &c = tree;

      const child_t<reaction_t,find::one> reaction("reaction");
      const child_t<nonsense_t,find::one> nonsense("nonsense");

      THEN("(child_t) const works") {
         CHECK(c(suite,reactions,reaction).label == "n + O16");
         CHECK(c(suite,reactions,reaction).ENDF_MT == 2);
      }

      THEN("(child_t,found) const works") {
         bool found = false;
         CHECK((c(suite,reactions,reaction,found).label == "n + O16" && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found).ENDF_MT == 2 && found));
         found = true;
         c(suite,reactions,nonsense,found);
         CHECK(!found);
      }

      THEN("(child_t,string) const works") {
         CHECK(c(suite,reactions,reaction,twon).label == "2n + O15 + photon");
         CHECK(c(suite,reactions,reaction,twon).ENDF_MT == 16);
      }

      THEN("(child_t,string,found) const works") {
         bool found = false;
         CHECK(c(suite,reactions,reaction,twon,found).label == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,twon,found).ENDF_MT == 16 && found));
         found = true;
         c(suite,reactions,nonsense,twon,found);
         CHECK(!found);
      }
   }

   // case: <type,all> const
   GIVEN("Testing node(child_t<type,all>[,string][,found]) const") {
      // c: const <reactions> node
      const Tree<> &c = tree;

      const child_t<reaction_t,find::all> reaction("reaction");
      const child_t<nonsense_t,find::all> nonsense("nonsense");

      THEN("child(child_t) const works") {
         CHECK(c(suite,reactions,reaction).size() == 60);
         CHECK(c(suite,reactions,reaction)[0].label == "n + O16");
         CHECK(c(suite,reactions,reaction)[0].ENDF_MT == 2);
      }

      THEN("child(child_t,found) const works") {
         bool found = false;
         CHECK((c(suite,reactions,reaction,found).size() == 60 && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)[0].label == "n + O16" && found));
         found = false;
         CHECK((c(suite,reactions,reaction,found)[0].ENDF_MT == 2 && found));
         found = true;
         c(suite,reactions,nonsense,found)[0];
         CHECK(!found);
      }

      THEN("child(child_t,string) const works") {
         CHECK(c(suite,reactions,reaction,twon).label == "2n + O15 + photon");
         CHECK(c(suite,reactions,reaction,twon).ENDF_MT == 16);
      }

      THEN("child(child_t,string,found) const works") {
         bool found = false;
         CHECK(c(suite,reactions,reaction,twon,found).label == "2n + O15 + photon");
         CHECK(found);
         found = false;
         CHECK((c(suite,reactions,reaction,twon,found).ENDF_MT == 16 && found));
         found = true;
         c(suite,reactions,nonsense,twon,found);
         CHECK(!found);
      }
   }


   // ------------------------
   // Test our values<>
   // variable template
   // ------------------------

   GIVEN("Testing node(values<*>) for various *") {
      const node n = tree(
         plain::child::reactionSuite,
         plain::child::reactions,
         plain::child::reaction, "n + O16",
         plain::child::crossSection,
         plain::child::XYs1d, "eval"
      );

      using mixed::child::values;
      std::ostringstream oss;

      // I'll only print every [stride] vector elements from the vectors
      // as extracted below, so as not to have a gigantic string to compare
      // with. There's nothing wrong with gigantic strings, except that I
      // don't want to hardcode, in this or any test file, a literal string
      // that's hundreds of pages long! :-)
      const int stride = 100;
      int count;

      // values<void> ==> node (that is, generic node in original form)
      auto vnode = n(values<void>);
      CHECK(vnode.metadata.size() == 0);
      CHECK(vnode.children.size() == 1);

      // values<> ==> vector<double>
      count = 0;
      for (auto v : n(values<>))
         if (count++ % stride == 0)
            oss << v << std::endl;
      oss << std::endl;

      // values<double> ==> vector<double>
      count = 0;
      for (auto v : n(values<double>))
         if (count++ % stride == 0)
            oss << v << std::endl;
      oss << std::endl;

      // values<float> ==> vector<float>
      count = 0;
      for (auto v : n(values<float>))
         if (count++ % stride == 0)
            oss << v << std::endl;
      oss << std::endl;

      // values<vector<double>> ==> vector<double>
      count = 0;
      for (auto v : n(values<std::vector<double>>))
         if (count++ % stride == 0)
            oss << v << std::endl;
      oss << std::endl;

      // values<vector<float>> ==> vector<float>
      count = 0;
      for (auto v : n(values<std::vector<float>>))
         if (count++ % stride == 0)
            oss << v << std::endl;
      oss << std::endl;

      // values<vector<pair<double,double>>> ==> vector<pair<double,double>>
      count = 0;
      for (auto v : n(values<std::vector<std::pair<double,double>>>))
         if (count++ % stride == 0)
            oss << v.first << ", " << v.second << std::endl;

      CHECK(oss.str() == values_string);
   } // GIVEN
}
