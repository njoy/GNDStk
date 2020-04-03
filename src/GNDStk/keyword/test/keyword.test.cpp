
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace GNDStk;
using std::string;



// -----------------------------------------------------------------------------
// Custom types
// -----------------------------------------------------------------------------

// version_t
struct version_t {
   int major = -1;
   int minor = -1;
   int patch = -1;
};

std::istream &operator>>(std::istream &s, version_t &obj)
{
   char ch; // '.'
   return s >> obj.major >> ch >> obj.minor >> ch >> obj.patch;
}

// date_t
struct date_t {
   int year  = -1;
   int month = -1;
   int day   = -1;
};

std::istream &operator>>(std::istream &s, date_t &obj)
{
   char ch; // '-'
   return s >> obj.year >> ch >> obj.month >> ch >> obj.day;
}

// shape_t
struct shape_t {
   // or maybe it should cols, rows; not important for this example
   int rows = -1;
   int cols = -1;
};

std::istream &operator>>(std::istream &s, shape_t &obj)
{
   char ch; // ','
   return s >> obj.rows >> ch >> obj.cols;
}

// values_t
using values_t = std::vector<double>;

// manifest_t
struct manifest_t {
   string information;
};

template<class NODE>
void node2type(const NODE &node, manifest_t &man)
{
   std::ostringstream oss;

   // name
   oss << "node: " << node.name << std::endl;

   // metadata
   oss << "   metadata:" << std::endl;
   for (auto &m : node.metadata)
      oss << "      " << m.first << std::endl;

   // children
   oss << "   children:" << std::endl;
   for (auto &c : node.children) oss << "      " << c->name << std::endl;

   man.information = oss.str();
}



// -----------------------------------------------------------------------------
// Some literal strings we'll use for testing
// -----------------------------------------------------------------------------

static const std::string manifest_tree =
R"***(node: xml
   metadata:
      version
      encoding
   children:
      covarianceSuite
)***";

static const std::string manifest_covarianceSuite =
R"***(node: covarianceSuite
   metadata:
      projectile
      target
      evaluation
      format
   children:
      styles
      externalFiles
      parameterCovariances
)***";

static const std::string manifest_parameterCovariances =
R"***(node: parameterCovariance
   metadata:
      label
   children:
      rowData
      parameterCovarianceMatrix
)***";



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk keyword") {

   using GNDStk::keyword;
   using namespace GNDStk::meta;
   using namespace GNDStk::child;

   // tree
   const GNDStk::tree tree("n-069_Tm_170-covar.xml");

   // ------------------------
   // exercise some built-ins
   // ------------------------

   {
      // child::xml disambiguates vs. class xml
      // meta::format disambiguates vs. enum class format

      REQUIRE(tree(child::xml).metadata.size() == 2);
      REQUIRE(tree(child::xml).children.size() == 1);
      REQUIRE(tree(child::xml,version) == "1.0");
      REQUIRE(tree(child::xml,encoding) == "UTF-8");
      REQUIRE(tree(covarianceSuite).metadata.size() == 4);
      REQUIRE(tree(covarianceSuite).children.size() == 3);
      REQUIRE(tree(covarianceSuite,projectile) == "n");
      REQUIRE(tree(covarianceSuite,target) == "Tm170");
      REQUIRE(tree(covarianceSuite,evaluation) == "ENDF/B-8.0");
      REQUIRE(tree(covarianceSuite,meta::format) == 1.9); // double, not string
      REQUIRE(tree(covarianceSuite,styles).metadata.size() == 0);
      REQUIRE(tree(covarianceSuite,styles).children.size() == 1);
      REQUIRE(tree(covarianceSuite,styles,evaluated).metadata.size() == 4);
      REQUIRE(tree(covarianceSuite,styles,evaluated).children.size() == 2);
      REQUIRE(tree(covarianceSuite,styles,evaluated,label) == "eval");
   }

   // ------------------------
   // make and use our own
   // ------------------------

   // for metadata
   auto myversion = keyword.meta<version_t>("version");
   auto mydate    = keyword.meta<date_t   >("date"   );
   auto myshape   = keyword.meta<shape_t  >("shape"  );

   // for children
   auto myvalues   = keyword.child<values_t,  false>("values");
   auto mymanifest = keyword.child<manifest_t,false>(""); // "": current node

   // Extract <xml> version into *our* version type
   // Specifically: myversion keyword ==> version_t
   auto vers = tree(child::xml,myversion);
   REQUIRE(vers.major == 1);
   REQUIRE(vers.minor == 0);

   // Now extract <evaluated> version
   vers = tree(covarianceSuite,styles,evaluated,myversion);
   REQUIRE(vers.major == 8);
   REQUIRE(vers.minor == 0);
   REQUIRE(vers.patch == 1);

   // For brevity, let's make a shortcut to <evaluated>
   auto eval = tree(covarianceSuite,styles,evaluated);

   // Extract date in <evaluated>, via the shortcut
   // Specifically: mydate keyword ==> date_t
   auto date = eval(mydate);
   REQUIRE(date.year  == 2011);
   REQUIRE(date.month == 10);
   REQUIRE(date.day   == 1);

   // Pull out <array>, to make some upcoming queries shorter
   auto arr = tree(
      covarianceSuite, parameterCovariances, parameterCovariance,
      parameterCovarianceMatrix, array);

   // Extract <array> shape into our shape type
   // Specifically: myshape keyword ==> shape_t
   auto shape = arr(myshape);
   REQUIRE(shape.rows == 78);
   REQUIRE(shape.cols == 78);

   // Extract <array> values into our values type, which is vector<double>
   // Specifically: myshape keyword ==> shape_t
   auto val = arr(myvalues);
   REQUIRE(val[0] == 0.015);
   REQUIRE(val[1] == 0);
   REQUIRE(val[2] == 0);
   REQUIRE(val[3] == 0);
   REQUIRE(val[4] == 4.5e-5);

   // ------------------------
   // Special keyword
   // with lookup ""
   // ------------------------

   // Special keyword: mymanifest, a child keyword with lookup key "".
   // Meaning: for the currently active Node, print its name, the names
   // of its metadata, and the names of its children. This demonstrates
   // how we could build various "x-ray" or "dictionary" type tools.
   // See how manifest_t is set up, earlier in this file.

   // Examine the tree itself, which really means the declaration node
   {
      auto man = tree(mymanifest);
      REQUIRE(man.information == manifest_tree);
   }

   // Let's look at what's in the top-level GNDS node. Note that top()
   // gets us the top-level node here, from which we call (manifest);
   // we do *not* write tree.top(manifest), which wouldn't make sense.
   {
      auto man = tree.top()(mymanifest);
      REQUIRE(man.information == manifest_covarianceSuite);
   }

   // Of course we can do this as well, knowing that covarianceSuite
   // is the top-level node
   {
      auto man = tree(covarianceSuite, mymanifest);
      REQUIRE(man.information == manifest_covarianceSuite);
   }

   // And let's dig further:
   {
      auto man = tree(
         covarianceSuite, parameterCovariances,
         parameterCovariance, mymanifest
      );
      REQUIRE(man.information == manifest_parameterCovariances);
   }

   // ------------------------
   // Exercise keyword builder
   // ------------------------

   // fixme To properly test this, we should really have something like
   // the Boost demangle library. For now, let's just make sure that the
   // compiler doesn't go nuts.

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
   auto c01 = keyword.child<          >("c01");
   auto c02 = keyword.child<          >("c02",true );
   auto c03 = keyword.child<          >("c03",false);
   auto c04 = keyword.child<void      >("c04");
   auto c05 = keyword.child<void      >("c05",true );
   auto c06 = keyword.child<void      >("c06",false);
   auto c07 = keyword.child<void,true >("c07");
   auto c08 = keyword.child<void,true >("c08",true );
   auto c09 = keyword.child<void,true >("c09",false);
   auto c10 = keyword.child<void,false>("c10");
   auto c11 = keyword.child<void,false>("c11",true );
   auto c12 = keyword.child<void,false>("c12",false);
   auto c13 = keyword.child<int       >("c13");
   auto c14 = keyword.child<int       >("c14",true );
   auto c15 = keyword.child<int       >("c15",false);
   auto c16 = keyword.child<int, true >("c16");
   auto c17 = keyword.child<int, true >("c17",true );
   auto c18 = keyword.child<int, true >("c18",false);
   auto c19 = keyword.child<int, false>("c19");
   auto c20 = keyword.child<int, false>("c20",true );
   auto c21 = keyword.child<int, false>("c21",false);

   // for now, make sure some template metaprogramming material is working
   auto c22 = keyword.child<          >("c22"      ,m04,c08,m06,c17);
   auto c23 = keyword.child<          >("c23",true ,c21,c05,c08,c11);
   auto c24 = keyword.child<          >("c24",false,c09,c17,c20,c04);
   auto c25 = keyword.child<void      >("c25"      ,c04,c01,c13,c12);
   auto c26 = keyword.child<void      >("c26",true ,c17,c10,c13,m01);
   auto c27 = keyword.child<void      >("c27",false,m06,c18,m08,c11);
   auto c28 = keyword.child<void,true >("c28"      ,c19,m04,c11,c15);
   auto c29 = keyword.child<void,true >("c29",true ,m02,c01,m06,m08,c11);
   auto c30 = keyword.child<void,true >("c30",false,c06,c03,c09,m06,c14);
   auto c31 = keyword.child<void,false>("c31"      ,c13,m03,c18,m08,c09);
   auto c32 = keyword.child<void,false>("c32",true ,m07,c07,c08,c20,c10);
   auto c33 = keyword.child<void,false>("c33",false,m01,m04,c15,m08,c18);
   auto c34 = keyword.child<int       >("c34"      ,m07,m04,m05,c04,m02);
   auto c35 = keyword.child<int       >("c35",true ,c14,c18,c01,m05,c15);
   auto c36 = keyword.child<int       >("c36",false,c01,m07,c19,c11,c20,c12);
   auto c37 = keyword.child<int, true >("c37"      ,c09,c11,c19,m08,m05,c08);
   auto c38 = keyword.child<int, true >("c38",true ,c09,c07,c21,c14,c13,c08);
   auto c39 = keyword.child<int, true >("c39",false,c16,m08,c10,c18,c07,c08);
   auto c40 = keyword.child<int, false>("c40"      ,m02,c08,c03,m05,c09,c18);
   auto c41 = keyword.child<int, false>("c41",true ,c06,m06,c21,c10,c12,m02);
   auto c42 = keyword.child<int, false>("c42",false,c09,c10,c07,m05,c08,m02);
}
