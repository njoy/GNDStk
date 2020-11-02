
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

   using namespace misc::meta;
   using namespace misc::child;

   // tree
   const njoy::GNDStk::tree tree("n-069_Tm_170-covar.xml");

   // ------------------------
   // exercise some built-ins
   // ------------------------

   WHEN("We access a tree using some built-in child_t and meta_t objects") {
      // child::xml disambiguates vs. class xml
      // meta::format disambiguates vs. enum class format

      CHECK(tree(misc::child::xml).metadata.size() == 2);
      CHECK(tree(misc::child::xml).children.size() == 0);
      CHECK(tree(misc::child::xml,version) == "1.0");
      CHECK(tree(misc::child::xml,encoding) == "UTF-8");
      CHECK(tree(covarianceSuite).metadata.size() == 4);
      CHECK(tree(covarianceSuite).children.size() == 3);
      CHECK(tree(covarianceSuite,projectile) == "n");
      CHECK(tree(covarianceSuite,target) == "Tm170");
      CHECK(tree(covarianceSuite,evaluation) == "ENDF/B-8.0");
      CHECK(tree(covarianceSuite,misc::meta::format) == 1.9);
      CHECK(tree(covarianceSuite,styles).metadata.size() == 0);
      CHECK(tree(covarianceSuite,styles).children.size() == 1);
      CHECK(tree(covarianceSuite,styles,evaluated).metadata.size() == 4);
      CHECK(tree(covarianceSuite,styles,evaluated).children.size() == 2);
      CHECK(tree(covarianceSuite,styles,evaluated,misc::meta::label) == "eval");
   } // WHEN


   // ------------------------
   // make our own
   // ------------------------

   // for metadata
   auto myversion = keyword.meta<version_t>("version");
   auto mydate    = keyword.meta<date_t   >("date"   );
   auto myshape   = keyword.meta<shape_t  >("shape"  );

   // for children
   auto myvalues =
      keyword.child<values_t,allow::one>("values",convert_pcdata_text);
   // In the following, a name of "" means to stay at the current node
   auto mymanifest = keyword.child<manifest_t,allow::one>("");

   auto vers = tree(misc::child::xml,myversion);


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
         vers = tree(covarianceSuite,styles,evaluated,myversion);
         CHECK(vers.major == 8);
         CHECK(vers.minor == 0);
         CHECK(vers.patch == 1);
      }

      // For brevity, let's make a shortcut to <evaluated>
      auto &eval = tree(covarianceSuite,styles,evaluated);

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
         covarianceSuite, parameterCovariances, parameterCovariance,
         parameterCovarianceMatrix, array);

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
         auto val = arr(myvalues);
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
         parameterCovariance, mymanifest
      );
      CHECK(man.information == manifest_parameterCovariances);
   }


   // ------------------------
   // Exercise keyword builder
   // ------------------------

   // To properly test this, we should really have something like the Boost
   // demangle library, to print a representation of the *type* that's being
   // created. For now, let's just make sure that the expressions are valid.

   // metadata
   auto m01 = keyword.meta<         >("m01");
   auto m02 = keyword.meta<char     >("m02");
   auto m03 = keyword.meta<int      >("m03");
   auto m04 = keyword.meta<float    >("m04");
   auto m05 = keyword.meta<double   >("m05");
   auto m06 = keyword.meta<version_t>("m06");
   auto m07 = keyword.meta<date_t   >("m07");
   auto m08 = keyword.meta<shape_t  >("m08");

   // basic children, no metadata/children requirements
   auto c01 = keyword.child<                >("c01");
   auto c02 = keyword.child<                >("c02",true );
   auto c03 = keyword.child<                >("c03",false);
   auto c04 = keyword.child<void            >("c04");
   auto c05 = keyword.child<void            >("c05",true );
   auto c06 = keyword.child<void            >("c06",false);
   auto c07 = keyword.child<void,allow::many>("c07");
   auto c08 = keyword.child<void,allow::many>("c08",true );
   auto c09 = keyword.child<void,allow::many>("c09",false);
   auto c10 = keyword.child<void,allow::one >("c10");
   auto c11 = keyword.child<void,allow::one >("c11",true );
   auto c12 = keyword.child<void,allow::one >("c12",false);
   auto c13 = keyword.child<int             >("c13");
   auto c14 = keyword.child<int             >("c14",true );
   auto c15 = keyword.child<int             >("c15",false);
   auto c16 = keyword.child<int, allow::many>("c16");
   auto c17 = keyword.child<int, allow::many>("c17",true );
   auto c18 = keyword.child<int, allow::many>("c18",false);
   auto c19 = keyword.child<int, allow::one >("c19");
   auto c20 = keyword.child<int, allow::one >("c20",true );
   auto c21 = keyword.child<int, allow::one >("c21",false);
}
