
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace GNDStk;
using namespace GNDStk::child;

/*
The file we'll be examining:

<?xml version="1.0" encoding="UTF-8"?>
<covarianceSuite projectile="n" target="Tm170" evaluation="ENDF/B-8.0" format="1.9">
  <styles>
    <evaluated label="eval" date="2011-10-01" library="ENDF/B" version="8.0.1">
      <temperature value="0.0" unit="K"/>
      <projectileEnergyDomain min="1e-05" max="30000000.0" unit="eV"/>
    </evaluated>
  </styles>
  <externalFiles>
    <externalFile label="reactions" path="n-069_Tm_170.xml"/>
  </externalFiles>
  <parameterCovariances>
    <parameterCovariance label="resolved resonances">
      <rowData href="$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']"/>
      <parameterCovarianceMatrix label="eval" type="absolute">
        <parameters>
          <parameterLink label="resonanceParameters" href="$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']/resonanceParameters/table" nParameters="78"/>
        </parameters>
        <array shape="78,78" compression="diagonal">
          <values>0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012</values>
        </array>
      </parameterCovarianceMatrix>
    </parameterCovariance>
  </parameterCovariances>
</covarianceSuite>
*/



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

// node2type(): callback for GNDStk; converts a node to an xml_t.
// Given that GNDStk::Node is templated, it's easiest to write functions
// like this by using template<class NODE> as I do here...
template<class NODE>
inline void node2type(const NODE &node, xml_t &out)
{
   out.version = std::stod(node.meta("version").c_str());
   out.encoding = node.meta("encoding");
}

// keyword: my_xml_keyword
// Users can write custom child_t values like this, and then use them in
// child() functions. Here, "xml" is what the keyword uses to look up nodes
// that can be converted to xml_t objects via the node2type() function above.
inline child_t<xml_t> my_xml_keyword("xml");



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
inline void node2type(const NODE &, covarianceSuite_type_1 &out)
{
   // some random nonsense, just for illustration
   out.foo = 123;
   out.bar = 456;
}

// From a node, build a covarianceSuite_type_2
template<class NODE>
inline void node2type(const NODE &node, covarianceSuite_type_2 &out)
{
   // Here, let's take advantage of GNDStk's projectile, target, evaluation,
   // and format keyword - which return, respectively, string, string, string,
   // and double. I.e. just what we need in our own custom type.
   out.projectile = node.meta(meta::projectile);
   out.target     = node.meta(meta::target);
   out.evaluation = node.meta(meta::evaluation);
   out.format     = node.meta(meta::format);
}

// keyword: my_covarianceSuite_keyword
// Can extract objects of either of the types defined just above!
inline child_t<
   std::variant<
      covarianceSuite_type_1,
      covarianceSuite_type_1
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
      // child(string)
      // Dumb string lookup
      // ------------------------

      {
         // Declaration node...

         // const
         found = false;
         auto &cnode = c.child("xml",found);
         REQUIRE(found == true);
         REQUIRE(cnode.name == "xml");
         REQUIRE(cnode.meta("version") == "1.0");

         // non-const
         found = false;
         auto &tnode = t.child("xml",found);
         REQUIRE(found == true);
         REQUIRE(tnode.name == "xml");
         REQUIRE(tnode.meta("encoding") == "UTF-8");

      } {
         // Top-level GNDS node...

         // const
         found = false;
         auto &cnode = c.child("covarianceSuite",found);
         REQUIRE(found == true);
         REQUIRE(cnode.name == "covarianceSuite");
         REQUIRE(cnode.meta("target") == "Tm170");

         // non-const
         found = false;
         auto &tnode = t.child("covarianceSuite",found);
         REQUIRE(found == true);
         REQUIRE(tnode.name == "covarianceSuite");
         REQUIRE(tnode.meta("evaluation") == "ENDF/B-8.0");

      } {
         // Non-existent child of the Tree...

         // const
         found = true;
         auto &cnode = c.child("foo",found);
         REQUIRE(found == false);

         // non-const
         found = true;
         auto &tnode = t.child("bar",found);
         REQUIRE(found == false);
      }

      // Illustrate that Tree's child(string) functions return references,
      // even when the child isn't found...
      (void)&c.child("xml");
      (void)&c.child("covarianceSuite");
      (void)&c.child("foo");

      (void)&t.child("xml");
      (void)&t.child("covarianceSuite");
      (void)&t.child("bar");


      // ------------------------
      // child(child_t)
      // Smart keyword lookup
      // ------------------------

      // child::xml is the smart keyword for retrieving the xml node.
      // We need the child:: prefix to disambiguate from GNDStk::xml,
      // our wrapper class around pugi::xml_document. Note that both
      // blocks below test with both const and non-const trees. The
      // relevant child() functions actually only have const versions,
      // because they return by value; so it isn't really necessary
      // to try both const and non-const trees below.
      {
         // NOTE FOR THE FUTURE, IF AN ERROR EVER HAPPENS BELOW:
         // Our built-in keyword child::xml is currently a child_t<void,...>.
         // It may someday change to child_t<something other than void,...>,
         // at which time the Node<> return PROBABLY WON'T WORK! void, in
         // this context, means that the "smart keyword" really just returns
         // a plain old Node, even though in principle it could give us back
         // a custom type.
         found = false;
         Node<> cnode = c.child(child::xml,found);
         REQUIRE(found == true);
         found = false;
         Node<> tnode = t.child(child::xml,found);
         REQUIRE(found == true);
      } {
         // IN CASE OF ERROR: Same note as immediately above.
         found = false; auto cnode = c.child(covarianceSuite,found);
         REQUIRE(found == true);
         found = false; auto tnode = t.child(covarianceSuite,found);
         REQUIRE(found == true);
      }

      // Let's try our own custom keyword, which was set up near the
      // beginning of this test file.
      {
         const xml_t x = c.child(my_xml_keyword);
         REQUIRE(x.version == 1.0);
         REQUIRE(x.encoding == "UTF-8");
      }

      // Another custom keyword, this one to test child() for std::variant.
      {
         // Here, the same keyword can extract objects of either of the two
         // types that we set it up to be able to extract...
         covarianceSuite_type_1 one =
            c.child<covarianceSuite_type_1>(my_covarianceSuite_keyword);
         covarianceSuite_type_2 two =
            c.child<covarianceSuite_type_2>(my_covarianceSuite_keyword);

         REQUIRE(one.foo == 123);
         REQUIRE(one.bar == 456);

         REQUIRE(two.projectile == "n");
         REQUIRE(two.target     == "Tm170");
         REQUIRE(two.evaluation == "ENDF/B-8.0");
         REQUIRE(two.format     == 1.9);
      }
   }
}
