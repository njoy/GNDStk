
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// XML literal
// -----------------------------------------------------------------------------

static const std::string string_real_xml =
R"***(<?xml version="1.0" encoding="UTF-8"?>
<covarianceSuite projectile="n" target="Tm170" evaluation="ENDF/B-8.0" format="1.9">
   <styles>
      <evaluated label="eval" date="2011-10-01" library="ENDF/B" version="8.0.1">
         <temperature value="0.0" unit="K" />
         <projectileEnergyDomain min="1e-05" max="30000000.0" unit="eV" />
      </evaluated>
   </styles>
   <externalFiles>
      <externalFile label="reactions" path="n-069_Tm_170.xml" />
   </externalFiles>
   <parameterCovariances>
      <parameterCovariance label="resolved resonances">
         <rowData href="$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']" />
         <parameterCovarianceMatrix label="eval" type="absolute">
            <parameters>
               <parameterLink label="resonanceParameters" href="$reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']/resonanceParameters/table" nParameters="78" />
            </parameters>
            <array shape="78,78" compression="diagonal">
               <values>0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012</values>
            </array>
         </parameterCovarianceMatrix>
      </parameterCovariance>
   </parameterCovariances>
</covarianceSuite>
)***";


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk XML") {

   // read an XML
   XML x("n-069_Tm_170-covar.xml");

   // construct a Tree from the XML
   Tree t(x);

   // the Tree should be non-empty
   CHECK(!t.empty());


   // ------------------------
   // clear
   // ------------------------

   WHEN("We clear() an XML, and convert() it to a Tree") {
      convert(x.clear(),t);
      THEN("The Tree should have only an empty declaration node") {
         CHECK(t.children.size() == 1);
         CHECK(t.has_decl());
         CHECK(t.decl().name == "xml");
         CHECK(t.decl().metadata.size() == 0);
         CHECK(t.decl().children.size() == 0);
      }
   }


   // ------------------------
   // empty
   // ------------------------

   WHEN("We call empty() on a clear()d XML") {
      x.clear();
      CHECK(x.empty());
   }


   // ------------------------
   // constructors
   // ------------------------

   // default
   WHEN("We call XML's default constructor") {
      const XML x;
      CHECK(x.empty());
   }

   // move
   WHEN("We call XML's move constructor") {
      const XML x(XML{"n-069_Tm_170-covar.xml"});
      CHECK(!x.empty());
      // and ensure it moved correctly
      std::ostringstream oss1; oss1 << XML{"n-069_Tm_170-covar.xml"};
      std::ostringstream oss2; oss2 << x;
      CHECK(oss1.str() == oss2.str());
   }

   // copy
   WHEN("We call XML's copy constructor") {
      const XML a("n-069_Tm_170-covar.xml");
      const XML x(a);
      CHECK(!x.empty());
      // and ensure it copied correctly
      std::ostringstream oss1; oss1 << a;
      std::ostringstream oss2; oss2 << x;
      CHECK(oss1.str() == oss2.str());
   }

   // from JSON
   WHEN("We construct an XML from a JSON") {
      const JSON j("n-069_Tm_170-covar.json");
      const XML x(j);
      THEN("They should produce equivalent Trees") {
         CHECK(!x.empty());
         CHECK(Tree(j) == Tree(x)); // == ignores declaration node
      }
   }

   // from Tree
   WHEN("We construct an XML from a Tree") {
      const Tree t("n-069_Tm_170-covar.json");
      const XML x(t);
      THEN("It should produce an equivalent Tree") {
         CHECK(!x.empty());
         CHECK(t == Tree(x)); // == ignores declaration node
      }
   }

   // from file
   // Note: Things like this are of course tested indirectly
   // all over the place.
   WHEN("We construct an XML from a file") {
      const XML x("n-069_Tm_170-covar.xml");
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!x.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.xml");
         std::ostringstream oss2; oss2 << Tree(x);
         CHECK(oss1.str() == oss2.str());
      }
   }

   // from istream
   WHEN("We construct an XML from an istream") {
      std::ifstream ifs("n-069_Tm_170-covar.xml");
      const XML x(ifs);
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!x.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.xml");
         std::ostringstream oss2; oss2 << Tree(x);
         CHECK(oss1.str() == oss2.str());
      }
   }


   // ------------------------
   // assignment
   // ------------------------

   // move
   WHEN("We call XML's move assignment") {
      XML x;
      x = XML{"n-069_Tm_170-covar.xml"};
      CHECK(!x.empty());
      // and ensure it moved correctly
      std::ostringstream oss1; oss1 << XML{"n-069_Tm_170-covar.xml"};
      std::ostringstream oss2; oss2 << x;
      CHECK(oss1.str() == oss2.str());
   }

   // copy
   WHEN("We call XML's copy assignment") {
      const XML a("n-069_Tm_170-covar.xml");
      XML x;
      x = a;
      CHECK(!x.empty());
      // and ensure it copied correctly
      std::ostringstream oss1; oss1 << a;
      std::ostringstream oss2; oss2 << x;
      CHECK(oss1.str() == oss2.str());
   }


   // ------------------------
   // read
   // ------------------------

   // from istream
   WHEN("We read an XML from an istream") {
      std::ifstream ifs("n-069_Tm_170-covar.xml");
      const XML x(ifs);
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!x.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.xml");
         std::ostringstream oss2; oss2 << Tree(x);
         CHECK(oss1.str() == oss2.str());
      }
   }

   // from file
   WHEN("We read an XML from a file") {
      const XML x("n-069_Tm_170-covar.xml");
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!x.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.xml");
         std::ostringstream oss2; oss2 << Tree(x);
         CHECK(oss1.str() == oss2.str());
      }
   }


   // ------------------------
   // write
   // ------------------------

   // to ostream
   WHEN("We write an XML to an ostream") {
      const XML x("n-069_Tm_170-covar.xml");
      std::ostringstream oss;
      x.write(oss);
      THEN("We can check that the result is what we expect") {
         CHECK(oss.str() == string_real_xml);
      }
   }


   // ------------------------
   // stream I/O
   // ------------------------

   // operator>>
   WHEN("We do istream >> XML") {
      std::ifstream ifs("n-069_Tm_170-covar.xml");
      XML x;
      ifs >> x;
      THEN("It should give what we expect") {
         // Well, we also end up testing << here, which we test
         // more directly in the next block, below
         std::ostringstream oss;
         oss << x;
         CHECK(oss.str() == string_real_xml);
      }
   }

   // operator<<
   WHEN("We do ostream << XML") {
      const XML x("n-069_Tm_170-covar.xml");
      std::ostringstream oss;
      oss << x;
      THEN("It should give what we expect") {
         CHECK(oss.str() == string_real_xml);
      }
   }
}
