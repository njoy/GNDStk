
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;
using namespace misc;



// -----------------------------------------------------------------------------
// For some keyword tests
// -----------------------------------------------------------------------------

// ------------------------
// Custom type, function,
// and extraction keyword
// ------------------------

// type: xml_t
// Basically, users can write custom types like this.
class xml_t {
public:
   double version;
   std::string encoding;
};

// convert(): callback for GNDStk; converts a node to an xml_t.
// Given that Node is templated, it's easiest to write functions
// like this by using template<class NODE> as I do here...
template<class NODE>
inline void convert(const NODE &node, xml_t &out)
{
   out.version  = std::stod(node.meta(version));
   out.encoding = node.meta(encoding);
}

// keyword: my_xml_keyword
// Users can write custom child_t objects like this, and then use them in
// child() functions. Here, "xml" is what the keyword uses to look up nodes
// that can be converted to xml_t objects via the convert() function above.
inline const child_t<xml_t> my_xml_keyword("xml");



// ------------------------
// And another one, for
// testing child(variant)
// ------------------------

// type: covarianceSuite_type_1
// Basically made-up here, just for the sake of creating an example. In real
// life, this sort of type might be designed to hold whatever data (perhaps
// absolutely everything) from an entire covarianceSuite node.
class covarianceSuite_type_1 {
public:
   // just to illustrate that we can write whatever we want into these types
   int foo;
   int bar;
};

// type: covarianceSuite_type_2
// A bit more meaningful that the above goofy covarianceSuite type
class covarianceSuite_type_2 {
public:
   // more realistic, though we'd also probably want to extract more than
   // just the covarianceSuite node's *metadata*
   std::string projectile;
   std::string target;
   std::string evaluation;
   double format;
};

// From a node, build a covarianceSuite_type_1
template<class NODE>
inline void convert(const NODE &, covarianceSuite_type_1 &out)
{
   // some random nonsense, just for illustration
   out.foo = 123;
   out.bar = 456;
}

// From a node, build a covarianceSuite_type_2
template<class NODE>
inline void convert(const NODE &node, covarianceSuite_type_2 &out)
{
   // Here, let's take advantage of GNDStk's projectile, target, evaluation,
   // and format keyword - which return, respectively, string, string, string,
   // and double. I.e. just what we need in our own custom type.
   out.projectile = node.meta(misc::meta::projectile);
   out.target     = node.meta(misc::meta::target);
   out.evaluation = node.meta(misc::meta::evaluation);
   out.format     = node.meta(misc::meta::format);
}

// keyword: my_covarianceSuite_keyword
// Can extract objects of either of the types defined just above!
inline const child_t<
   std::variant<
      covarianceSuite_type_1,
      covarianceSuite_type_2
   >
> my_covarianceSuite_keyword("covarianceSuite");



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree child()") {

   GIVEN("A tree read from n-069_Tm_170-covar.xml") {
      // c: a const tree
      const Tree<> c("n-069_Tm_170-covar.xml");
      // t: a non-const tree
      Tree<> t = c;

      // Note: Tree's child() function can give back either the declaration
      // node, or the top-level GNDS node; we consider both of those to be
      // a Tree's children. If you dig further into the tree, you'll actually
      // be using Node's child() function, not Tree's.

      bool found;

      // ------------------------
      // child(child_t)
      // Smart keyword lookup
      // ------------------------

      // child::xml is the smart keyword for retrieving the xml node.
      // Note that we'll work with both const and non-const trees.

      WHEN("We call tree.child() to get the declaration node") {
         // NOTE FOR THE FUTURE, IF AN ERROR EVER HAPPENS BELOW:
         // Our built-in keyword child::xml is currently a child_t<void,...>.
         // It may someday change to child_t<something other than void,...>,
         // at which time the Node<> return PROBABLY WON'T WORK! void, in
         // this context, means that the "smart keyword" really just returns
         // a raw Node, even though in principle it could give us back
         // a custom type.
         found = false;
         const Node<> &cnode = c.child(misc::child::xml,found);
         CHECK(found == true);
         found = false;
         Node<> &tnode = t.child(misc::child::xml,found);
         CHECK(found == true);
      }

      WHEN("We call tree.child() to get the covarianceSuite node") {
         // IN CASE OF ERROR: Same note as immediately above.
         found = false; auto &cnode = c.child(covarianceSuite,found);
         CHECK(found == true);
         found = false; auto &tnode = t.child(covarianceSuite,found);
         CHECK(found == true);
      }

      // Let's try our own custom keyword, which was set up near the
      // beginning of this test file.
      WHEN("We try tree.child(a custom keyword)") {
         const xml_t x = c.child(my_xml_keyword);
         CHECK(x.version == 1.0);
         CHECK(x.encoding == "UTF-8");
      }

      // Another custom keyword, this one to test child() for std::variant.
      WHEN("We try tree.child<type>(a custom keyword using variant)") {
         // Here, the same keyword can extract objects of either of the two
         // types that we set it up to be able to extract...
         covarianceSuite_type_1 one =
            c.child<covarianceSuite_type_1>(my_covarianceSuite_keyword);
         covarianceSuite_type_2 two =
            c.child<covarianceSuite_type_2>(my_covarianceSuite_keyword);

         CHECK(one.foo == 123);
         CHECK(one.bar == 456);

         CHECK(two.projectile == "n");
         CHECK(two.target     == "Tm170");
         CHECK(two.evaluation == "ENDF/B-8.0");
         CHECK(two.format     == 1.9);
      }
   }
}
