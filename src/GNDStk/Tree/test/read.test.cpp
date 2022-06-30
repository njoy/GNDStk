
#include "catch.hpp"
#include "GNDStk.hpp"
#include "GNDStk/test/keys.hpp"
using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// correct_tree
// -----------------------------------------------------------------------------

static const std::string correct_tree =
R"***(
   covarianceSuite:
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
                     #pcdata:
                        #text: 0.015 0 0 0 4.5e-5 0.015 3e-2 0 0 0 1.35e-4 0.015 2e-2 0 0 0 1.5e-3 0.012 5e-2 0 0 0 1.875e-3 6e-2 5e-2 0 0 0 1.05e-4 0.015 0.1 0 0 0 6e-4 0.012 0.1 0 0 0 2.25e-4 0.012 0.2 0 0 0 5.25e-3 0.012 0.2 0 0 0 3.45e-3 0.012 0.3 0 0 0 4.5e-4 0.012 0.3 0 0 0 3e-3 0.012 0.4 0 0 0 9e-3 0.012 0.4 0 0 0 1.425e-3 0.012
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
               value: 0.0)***";

static const std::string decl_xml =
R"***(/:
   #xml:
      encoding: UTF-8
      version: 1.0)***";

static const std::string decl_json =
R"***(/:
   #json:)***";

void compare(Tree &t, const std::string &correct)
{
   std::ostringstream oss;
   t.sort().write(oss);
   CHECK(oss.str() == correct);
}


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk tree read() and operator>>") {
   Tree t1, t2, t3, t4;

   GIVEN("Some trees") {

      // ------------------------
      // XML
      // ------------------------

      WHEN("We read() one from an xml file") {
         const std::string filename = "n-069_Tm_170-covar.xml";
         t1.read(filename);
         compare(t1, decl_xml + correct_tree);
      }

      WHEN("We read() one from an xml istream, specifically an ifstream") {
         std::ifstream ifs("n-069_Tm_170-covar.xml");
         t2.read(ifs);
         compare(t2, decl_xml + correct_tree);
      }

      WHEN("We read() one from an xml istream, specifically a stringstream") {
         std::ifstream ifs("n-069_Tm_170-covar.xml");
         std::stringstream sstr;
         sstr << ifs.rdbuf();
         t3.read(sstr);
         compare(t3, decl_xml + correct_tree);
      }

      WHEN("We stream-input one, specifically from an xml ifstream") {
         std::ifstream ifs("n-069_Tm_170-covar.xml");
         ifs >> t4;
         compare(t4, decl_xml + correct_tree);
      }

      // ------------------------
      // JSON
      // ------------------------

      WHEN("We read() one from a json file") {
         const std::string filename = "n-069_Tm_170-covar.json";
         t1.read(filename);
         compare(t1, decl_json + correct_tree);
      }

      WHEN("We read() one from a json istream, specifically an ifstream") {
         std::ifstream ifs("n-069_Tm_170-covar.json");
         t2.read(ifs);
         compare(t2, decl_json + correct_tree);
      }

      WHEN("We read() one from a json istream, specifically a stringstream") {
         std::ifstream ifs("n-069_Tm_170-covar.json");
         std::stringstream sstr;
         sstr << ifs.rdbuf();
         t3.read(sstr);
         compare(t3, decl_json + correct_tree);
      }

      WHEN("We stream-input one, specifically from a json ifstream") {
         std::ifstream ifs("n-069_Tm_170-covar.json");
         ifs >> t4;
         compare(t4, decl_json + correct_tree);
      }
   }

   // Why not...
   GIVEN("Several trees, read differently, but ultimately from the same file") {
      // While the present test file is about tree's read(), not its write(),
      // let's nevertheless do a simple write(), in our debug output-file
      // format, from each of the trees that were read in different ways
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
      Tree tree;

      const std::string xfilename = "n-069_Tm_170-covar.xml";
      const std::string jfilename = "n-069_Tm_170-covar.json";
      std::ifstream xifs("n-069_Tm_170-covar.xml");
      std::ifstream jifs("n-069_Tm_170-covar.json");

      WHEN("We test read(filename, file format") {
         // xml
         tree.read(xfilename,FileType::guess);
         compare(tree, decl_xml + correct_tree);
         tree.read(xfilename,FileType::xml);
         compare(tree, decl_xml + correct_tree);

         // json
         tree.read(jfilename,FileType::guess);
         compare(tree, decl_json + correct_tree);
         tree.read(jfilename,FileType::json);
         compare(tree, decl_json + correct_tree);
      }

      WHEN("We test read(filename, string") {
         // xml
         tree.read(xfilename,"");
         compare(tree, decl_xml + correct_tree);
         tree.read(xfilename,"guess");
         compare(tree, decl_xml + correct_tree);
         tree.read(xfilename,"xml");
         compare(tree, decl_xml + correct_tree);

         // json
         tree.read(jfilename,"");
         compare(tree, decl_json + correct_tree);
         tree.read(jfilename,"guess");
         compare(tree, decl_json + correct_tree);
         tree.read(jfilename,"json");
         compare(tree, decl_json + correct_tree);
      }

      WHEN("We test read(istream, file format") {
         // xml
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,FileType::guess);
         compare(tree, decl_xml + correct_tree);
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,FileType::xml);
         compare(tree, decl_xml + correct_tree);

         // json
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,FileType::guess);
         compare(tree, decl_json + correct_tree);
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,FileType::json);
         compare(tree, decl_json + correct_tree);
      }

      WHEN("We test read(istream, string") {
         // xml
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,"");
         compare(tree, decl_xml + correct_tree);
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,"guess");
         compare(tree, decl_xml + correct_tree);
         xifs.seekg (0,std::ios::beg);
         tree.read(xifs,"xml");
         compare(tree, decl_xml + correct_tree);

         // json
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,"");
         compare(tree, decl_json + correct_tree);
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,"guess");
         compare(tree, decl_json + correct_tree);
         jifs.seekg (0,std::ios::beg);
         tree.read(jifs,"json");
         compare(tree, decl_json + correct_tree);
      }
   }
}
