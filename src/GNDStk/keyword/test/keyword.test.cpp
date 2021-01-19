
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;
using std::string;



// -----------------------------------------------------------------------------
// Custom types
// -----------------------------------------------------------------------------

// ------------------------
// version_t
// ------------------------

// class
struct version_t {
   int major = -1;
   int minor = -1;
   int patch = -1;
};

// operator>>
std::istream &operator>>(std::istream &s, version_t &obj)
{
   char ch; // '.'
   return s >> obj.major >> ch >> obj.minor >> ch >> obj.patch;
}

// ------------------------
// date_t
// ------------------------

// class
struct date_t {
   int year  = -1;
   int month = -1;
   int day   = -1;
};

// operator>>
std::istream &operator>>(std::istream &s, date_t &obj)
{
   char ch; // '-'
   return s >> obj.year >> ch >> obj.month >> ch >> obj.day;
}

// ------------------------
// shape_t
// ------------------------

// class
struct shape_t {
   // or maybe it should cols, rows; not important for this example
   int rows = -1;
   int cols = -1;
};

// operator>>
std::istream &operator>>(std::istream &s, shape_t &obj)
{
   char ch; // ','
   return s >> obj.rows >> ch >> obj.cols;
}

// ------------------------
// values_t
// ------------------------

// class
using values_t = std::vector<double>;

// ------------------------
// manifest_t
// ------------------------

// class
struct manifest_t {
   string information;
};

// convert
template<class NODE>
void convert(const NODE &node, manifest_t &man)
{
   std::ostringstream oss;

   // name
   oss << "node: \"" << node.name << '"' << std::endl;

   // metadata
   oss << "   metadata:" << std::endl;
   for (auto &m : node.metadata)
      oss << "      \"" << m.first << '"' << std::endl;

   // children
   oss << "   children:" << std::endl;
   for (auto &c : node.children)
      oss << "      \"" << c->name << '"' << std::endl;

   man.information = oss.str();
}



// -----------------------------------------------------------------------------
// Some literal strings representing correct values
// -----------------------------------------------------------------------------

static const std::string manifest_tree =
R"***(node: ""
   metadata:
   children:
      "xml"
      "covarianceSuite"
)***";

static const std::string manifest_covarianceSuite =
R"***(node: "covarianceSuite"
   metadata:
      "projectile"
      "target"
      "evaluation"
      "format"
   children:
      "styles"
      "externalFiles"
      "parameterCovariances"
)***";

static const std::string manifest_parameterCovariances =
R"***(node: "parameterCovariance"
   metadata:
      "label"
   children:
      "rowData"
      "parameterCovarianceMatrix"
)***";



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk keyword") {

   using namespace misc;

   // tree
   const njoy::GNDStk::tree tree("n-069_Tm_170-covar.xml");

   // ------------------------
   // exercise some built-ins
   // ------------------------

   WHEN("We access a tree using some built-in child_t and meta_t objects") {
      CHECK(tree(xml).metadata.size() == 2);
      CHECK(tree(xml).children.size() == 0);
      CHECK(tree(xml,version) == "1.0");
      CHECK(tree(xml,encoding) == "UTF-8");
      CHECK(tree(covarianceSuite).metadata.size() == 4);
      CHECK(tree(covarianceSuite).children.size() == 3);
      CHECK(tree(covarianceSuite,projectile) == "n");
      CHECK(tree(covarianceSuite,target) == "Tm170");
      CHECK(tree(covarianceSuite,evaluation) == "ENDF/B-8.0");
      CHECK(tree(covarianceSuite,format) == 1.9);
      CHECK(tree(covarianceSuite,styles).metadata.size() == 0);
      CHECK(tree(covarianceSuite,styles).children.size() == 1);
      CHECK(tree(covarianceSuite,styles,--evaluated).metadata.size() == 4);
      CHECK(tree(covarianceSuite,styles,--evaluated).children.size() == 2);
      CHECK(tree(covarianceSuite,styles,--evaluated,misc::meta::label) == "eval");
   } // WHEN


   // ------------------------
   // make our own
   // ------------------------

   // for metadata
   auto myversion = keyword.meta<version_t>("version");
   auto mydate    = keyword.meta<date_t,detail::convert_t>("date");
   auto myshape   = keyword.meta<shape_t>("shape",shape_t{},detail::convert_t{});

   // for children
   // The following is just like GNDStk::common::numeric<double>,
   // or equivalently, GNDStk::[basic or core]::numeric<double>.
   auto mynumbers = keyword.child<values_t,allow::one>
      ("pcdata",values_t{},detail::convert_pcdata_text_t{});

   // In the following, a name of "" means to stay at the current node
   auto mymanifest = keyword.child<manifest_t,allow::one>("");

   auto vers = tree(xml,myversion);


   // ------------------------
   // use them
   // ------------------------

   WHEN("We build our own child_t and meta_t objects, using keyword_t") {

      THEN("Try extracting xml version") {
         // Extract <xml> version into *our* version type
         // Specifically: myversion keyword ==> version_t
         CHECK(vers.major == 1);
         CHECK(vers.minor == 0);
      }

      THEN("Try extracting covarianceSuite/styles/evaluated/version") {
         // Now extract <evaluated> version
         vers = tree(covarianceSuite,styles,--evaluated,myversion);
         CHECK(vers.major == 8);
         CHECK(vers.minor == 0);
         CHECK(vers.patch == 1);
      }

      // For brevity, let's make a shortcut to <evaluated>
      auto &eval = tree(covarianceSuite,styles,--evaluated);

      THEN("Try extracting covarianceSuite/styles/evaluated/date") {
         // Extract date in <evaluated>, via the shortcut
         // Specifically: mydate keyword ==> date_t
         auto date = eval(mydate);
         CHECK(date.year  == 2011);
         CHECK(date.month == 10);
         CHECK(date.day   == 1);
      }

      // Pull out <array>, to make some upcoming queries shorter
      auto &arr = tree(
         covarianceSuite, parameterCovariances, --parameterCovariance,
         --parameterCovarianceMatrix, array);

      THEN("Try extracting .../array/shape") {
         // Extract <array> shape into our shape type
         // Specifically: myshape keyword ==> shape_t
         auto shape = arr(myshape);
         CHECK(shape.rows == 78);
         CHECK(shape.cols == 78);
      }

      THEN("Try extracting .../array/values") {
         // Extract <array> values into our values_t type,
         // which is vector<double>.
         // Specifically: myshape keyword ==> shape_t
         auto val = arr(--child::values,mynumbers);
         CHECK(val[0] == 0.015);
         CHECK(val[1] == 0);
         CHECK(val[2] == 0);
         CHECK(val[3] == 0);
         CHECK(val[4] == 4.5e-5);
      }

   } // WHEN


   // ------------------------
   // Special keyword
   // with lookup ""
   // ------------------------

   // Special keyword: mymanifest, a child keyword with lookup key "".
   // Meaning: for the currently active Node, print its name, the names
   // of its metadata, and the names of its children. This demonstrates
   // how we could build various "x-ray" or "dictionary" type tools.
   // See how manifest_t is set up, earlier in this file.

   // Examine the tree itself
   WHEN("We use a special \"\"-named keyword to examine tree") {
      auto man = tree(mymanifest);
      CHECK(man.information == manifest_tree);
   }

   // Let's look at what's in the top-level GNDS node. Note that top()
   // gets us the top-level node here, from which we call (manifest);
   // we do *not* write tree.top(manifest), which wouldn't make sense.
   WHEN("We use a special \"\"-named keyword to examine tree.top()") {
      auto man = tree.top()(mymanifest);
      CHECK(man.information == manifest_covarianceSuite);
   }

   // Of course we can do this as well, knowing that covarianceSuite
   // is the top-level node
   WHEN("We use a special \"\"-named keyword to examine <covarianceSuite>") {
      auto man = tree(covarianceSuite, mymanifest);
      CHECK(man.information == manifest_covarianceSuite);
   }

   // And let's dig further:
   WHEN("We use a special \"\"-named keyword to examine "
        ".../<parameterCovariance>") {
      auto man = tree(
         covarianceSuite, parameterCovariances,
         --parameterCovariance, mymanifest
      );
      CHECK(man.information == manifest_parameterCovariances);
   }


   // ------------------------
   // Exercise keyword
   // builder...
   // ------------------------

   // To properly test this, we should really have something like the Boost
   // demangle library, to print a representation of the *type* that's being
   // created. For now, let's just make sure that the expressions are valid.

   // ------------------------
   // ...metadata, type
   // ------------------------

   {
      { auto m = keyword.meta                        ("m"                        ); }
      { auto m = keyword.meta                        ("m", 0                     ); }
      { auto m = keyword.meta                        ("m", 0, detail::convert_t{}); }
      { auto m = keyword.meta<                     > ("m"                        ); }
      { auto m = keyword.meta<                     > ("m", 0                     ); }
      { auto m = keyword.meta<                     > ("m", 0, detail::convert_t{}); }
      { auto m = keyword.meta<int                  > ("m"                        ); }
      { auto m = keyword.meta<int                  > ("m", 0                     ); }
      { auto m = keyword.meta<int                  > ("m", 0, detail::convert_t{}); }
      { auto m = keyword.meta<int,detail::convert_t> ("m"                        ); }
      { auto m = keyword.meta<int,detail::convert_t> ("m", 0                     ); }
      { auto m = keyword.meta<int,detail::convert_t> ("m", 0, detail::convert_t{}); }
   }

   // ------------------------
   // ...metadata, void
   // ------------------------

   {
      { auto m = keyword.meta       ("m"); }
      { auto m = keyword.meta<    > ("m"); }
      { auto m = keyword.meta<void> ("m"); }
   }

   // ------------------------
   // ...children, type
   // ------------------------

   // The commented-out cases are ambiguous:
   // TYPE for <non-void>, or FILTER for <void>?
   {
      { auto c = keyword.child                                                    ("c"                                                   ); }
   // { auto c = keyword.child                                                    ("c", 0                                                ); }
      { auto c = keyword.child                                                    ("c", 0, detail::convert_t{}                           ); }
      { auto c = keyword.child                                                    ("c", 0, detail::convert_t{}, detail::noFilter{}       ); }
      { auto c = keyword.child                                                    ("c", 0, detail::convert_t{}, detail::noFilter{}, false); }
      { auto c = keyword.child<                                                 > ("c"                                                   ); }
   // { auto c = keyword.child<                                                 > ("c", 0                                                ); }
      { auto c = keyword.child<                                                 > ("c", 0, detail::convert_t{}                           ); }
      { auto c = keyword.child<                                                 > ("c", 0, detail::convert_t{}, detail::noFilter{}       ); }
      { auto c = keyword.child<                                                 > ("c", 0, detail::convert_t{}, detail::noFilter{}, false); }
      { auto c = keyword.child<int                                              > ("c"                                                   ); }
      { auto c = keyword.child<int                                              > ("c", 0                                                ); }
      { auto c = keyword.child<int                                              > ("c", 0, detail::convert_t{}                           ); }
      { auto c = keyword.child<int                                              > ("c", 0, detail::convert_t{}, detail::noFilter{}       ); }
      { auto c = keyword.child<int                                              > ("c", 0, detail::convert_t{}, detail::noFilter{}, false); }
      { auto c = keyword.child<int,allow::one                                   > ("c"                                                   ); }
      { auto c = keyword.child<int,allow::one                                   > ("c", 0                                                ); }
      { auto c = keyword.child<int,allow::one                                   > ("c", 0, detail::convert_t{}                           ); }
      { auto c = keyword.child<int,allow::one                                   > ("c", 0, detail::convert_t{}, detail::noFilter{}       ); }
      { auto c = keyword.child<int,allow::one                                   > ("c", 0, detail::convert_t{}, detail::noFilter{}, false); }
      { auto c = keyword.child<int,allow::one,detail::convert_t                 > ("c"                                                   ); }
      { auto c = keyword.child<int,allow::one,detail::convert_t                 > ("c", 0                                                ); }
      { auto c = keyword.child<int,allow::one,detail::convert_t                 > ("c", 0, detail::convert_t{}                           ); }
      { auto c = keyword.child<int,allow::one,detail::convert_t                 > ("c", 0, detail::convert_t{}, detail::noFilter{}       ); }
      { auto c = keyword.child<int,allow::one,detail::convert_t                 > ("c", 0, detail::convert_t{}, detail::noFilter{}, false); }
      { auto c = keyword.child<int,allow::one,detail::convert_t,detail::noFilter> ("c"                                                   ); }
      { auto c = keyword.child<int,allow::one,detail::convert_t,detail::noFilter> ("c", 0                                                ); }
      { auto c = keyword.child<int,allow::one,detail::convert_t,detail::noFilter> ("c", 0, detail::convert_t{}                           ); }
      { auto c = keyword.child<int,allow::one,detail::convert_t,detail::noFilter> ("c", 0, detail::convert_t{}, detail::noFilter{}       ); }
      { auto c = keyword.child<int,allow::one,detail::convert_t,detail::noFilter> ("c", 0, detail::convert_t{}, detail::noFilter{}, false); }
   }

   // ------------------------
   // ...children, void
   // ------------------------

   // The commented-out cases are ambiguous, as above.
   {
      { auto c = keyword.child                                   ("c"                           ); }
   // { auto c = keyword.child                                   ("c", detail::noFilter{}       ); }
      { auto c = keyword.child                                   ("c", detail::noFilter{}, false); }
      { auto c = keyword.child<                                > ("c"                           ); }
   // { auto c = keyword.child<                                > ("c", detail::noFilter{}       ); }
      { auto c = keyword.child<                                > ("c", detail::noFilter{}, false); }
      { auto c = keyword.child<void                            > ("c"                           ); }
      { auto c = keyword.child<void                            > ("c", detail::noFilter{}       ); }
      { auto c = keyword.child<void                            > ("c", detail::noFilter{}, false); }
      { auto c = keyword.child<void,allow::one                 > ("c"                           ); }
      { auto c = keyword.child<void,allow::one                 > ("c", detail::noFilter{}       ); }
      { auto c = keyword.child<void,allow::one                 > ("c", detail::noFilter{}, false); }
      { auto c = keyword.child<void,allow::one,detail::noFilter> ("c"                           ); }
      { auto c = keyword.child<void,allow::one,detail::noFilter> ("c", detail::noFilter{}       ); }
      { auto c = keyword.child<void,allow::one,detail::noFilter> ("c", detail::noFilter{}, false); }
   }
}
