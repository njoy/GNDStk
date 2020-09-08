
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// correct_tree
// -----------------------------------------------------------------------------

static const std::string correct_tree =
R"***(covarianceSuite:
   evaluation: ENDF/B-8.0
   format: 1.9
   projectile: n
   target: Tm170
   externalFiles:
      externalFile:
         label: reactions
         path: n-069_Tm_170.xml
   parameterCovariances:
      parameterCovariance:
         label: resolved resonances
         parameterCovarianceMatrix:
            label: eval
            type: absolute
            array:
               compression: diagonal
               shape: 78,78
               values:
                  pcdata:
                     text: 0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012
            parameters:
               parameterLink:
                  href: $reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']/resonanceParameters/table
                  label: resonanceParameters
                  nParameters: 78
         rowData:
            href: $reactions#/reactionSuite/resonances/resolved/BreitWigner[@label='eval']
   styles:
      evaluated:
         date: 2011-10-01
         label: eval
         library: ENDF/B
         version: 8.0.1
         projectileEnergyDomain:
            max: 30000000.0
            min: 1e-05
            unit: eV
         temperature:
            unit: K
            value: 0.0
)***";

bool compare(Tree<> &t)
{
   std::ostringstream oss;
   t.sort().write(oss);
   return oss.str() == correct_tree;
}


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree read() and operator>>") {
   Tree<> t1, t2, t3, t4;

   GIVEN("Some trees") {

      // ------------------------
      // XML
      // ------------------------

      WHEN("We read() one from an xml file") {
         const std::string filename = "n-069_Tm_170-covar.xml";
         t1.read(filename);
         CHECK(compare(t1));
      }

      WHEN("We read() one from an xml istream, specifically an ifstream") {
         std::ifstream ifs("n-069_Tm_170-covar.xml");
         t2.read(ifs);
         CHECK(compare(t2));
      }

      WHEN("We read() one from an xml istream, specifically a stringstream") {
         std::ifstream ifs("n-069_Tm_170-covar.xml");
         std::stringstream sstr;
         sstr << ifs.rdbuf();
         t3.read(sstr);
         CHECK(compare(t3));
      }

      WHEN("We stream-input one, specifically from an xml ifstream") {
         std::ifstream ifs("n-069_Tm_170-covar.xml");
         ifs >> t4;
         CHECK(compare(t4));
      }

      // ------------------------
      // JSON
      // ------------------------

      WHEN("We read() one from a json file") {
         const std::string filename = "n-069_Tm_170-covar.json";
         t1.read(filename);
         CHECK(compare(t1));
      }

      WHEN("We read() one from a json istream, specifically an ifstream") {
         std::ifstream ifs("n-069_Tm_170-covar.json");
         t2.read(ifs);
         CHECK(compare(t2));
      }

      WHEN("We read() one from a json istream, specifically a stringstream") {
         std::ifstream ifs("n-069_Tm_170-covar.json");
         std::stringstream sstr;
         sstr << ifs.rdbuf();
         t3.read(sstr);
         CHECK(compare(t3));
      }

      WHEN("We stream-input one, specifically from a json ifstream") {
         std::ifstream ifs("n-069_Tm_170-covar.json");
         ifs >> t4;
         CHECK(compare(t4));
      }
   }

   // Why not...
   GIVEN("Several trees, read differently, but ultimately from the same file") {
      // While the present test file is about tree's read(), not about its
      // write(), let's nevertheless do a simple write(), to tree's basic
      // text-output format, from each of the trees read in different ways
      // above, and be sure there are absolutely no differences between them.
      // In effect, this helps test the read(), because it gives confidence
      // that our various ways of reading the same files give the same results.
      std::ostringstream oss1; t1.write(oss1);
      std::ostringstream oss2; t2.write(oss2);
      std::ostringstream oss3; t3.write(oss3);
      std::ostringstream oss4; t4.write(oss4);

      CHECK(oss1.str() == oss2.str());
      CHECK(oss1.str() == oss3.str());
      CHECK(oss1.str() == oss4.str());
   }

   GIVEN("Some trees") {
      using namespace njoy::GNDStk;
      Tree<> tree;

      const std::string xfilename = "n-069_Tm_170-covar.xml";
      const std::string jfilename = "n-069_Tm_170-covar.json";
      std::ifstream xifs("n-069_Tm_170-covar.xml");
      std::ifstream jifs("n-069_Tm_170-covar.json");

      WHEN("We test read(filename,format") {
         // xml
         tree.read(xfilename,format::null); CHECK(compare(tree));
         tree.read(xfilename,format::xml ); CHECK(compare(tree));
         // json
         tree.read(jfilename,format::null); CHECK(compare(tree));
         tree.read(jfilename,format::json); CHECK(compare(tree));
      }

      WHEN("We test read(filename,string") {
         // xml
         tree.read(xfilename,""    ); CHECK(compare(tree));
         tree.read(xfilename,"null"); CHECK(compare(tree));
         tree.read(xfilename,"xml" ); CHECK(compare(tree));
         // json
         tree.read(jfilename,""    ); CHECK(compare(tree));
         tree.read(jfilename,"null"); CHECK(compare(tree));
         tree.read(jfilename,"json"); CHECK(compare(tree));
      }

      WHEN("We test read(istream,format") {
         // xml
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,format::null); CHECK(compare(tree));
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,format::xml ); CHECK(compare(tree));
         // json
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,format::null); CHECK(compare(tree));
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,format::json); CHECK(compare(tree));
      }

      WHEN("We test read(istream,string") {
         // xml
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,""    ); CHECK(compare(tree));
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,"null"); CHECK(compare(tree));
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,"xml" ); CHECK(compare(tree));
         // json
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,""    ); CHECK(compare(tree));
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,"null"); CHECK(compare(tree));
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,"json"); CHECK(compare(tree));
      }
   }
}
