
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk tree read() and operator>>") {
   Tree<> t1, t2, t3, t4;

   GIVEN("Some trees") {
      WHEN("We read() one from a file") {
         const std::string filename = "n-008_O_016.xml";
         t1.read(filename);
         CHECK(!t1.empty()); // we get something
      }

      WHEN("We read() one from an istream, specifically an ifstream") {
         std::ifstream ifs("n-008_O_016.xml");
         t2.read(ifs);
         CHECK(!t2.empty()); // we get something
      }

      WHEN("We read() one from an istream, specifically a stringstream") {
         std::ifstream ifs("n-008_O_016.xml");
         std::stringstream sstr;
         sstr << ifs.rdbuf();
         t3.read(sstr);
         CHECK(!t3.empty()); // we get something
      }

      WHEN("We stream-input one, specifically from an ifstream") {
         std::ifstream ifs("n-008_O_016.xml");
         ifs >> t4;
         CHECK(!t4.empty()); // we get something
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

   // fixme There's actually somewhat more we can test, with regards to tree's
   // read(). Above, we're just dealing with an XML file, not a JSON (for which
   // we don't yet have an official GNDS file) or an HDF (ditto, and for which
   // we don't have read/write capabilities yet either).

   GIVEN("Some trees") {
      using namespace njoy::GNDStk;
      Tree<> tree;

      const std::string filename = "n-008_O_016.xml";
      std::ifstream ifs("n-008_O_016.xml");

      WHEN("We test read(filename,format") {
         tree.read(filename,format::null);
         CHECK(!tree.empty());

         tree.read(filename,format::xml);
         CHECK(!tree.empty());
      }

      WHEN("We test read(filename,string") {
         tree.read(filename,"");
         CHECK(!tree.empty());

         tree.read(filename,"null");
         CHECK(!tree.empty());

         tree.read(filename,"xml");
         CHECK(!tree.empty());
      }

      WHEN("We test read(istream,format") {
         ifs.seekg (0,std::ios::beg);
         tree.read(ifs,format::null);
         CHECK(!tree.empty());

         ifs.seekg (0,std::ios::beg);
         tree.read(ifs,format::xml);
         CHECK(!tree.empty());
      }

      WHEN("We test read(istream,string") {
         ifs.seekg (0,std::ios::beg);
         tree.read(ifs,"");
         CHECK(!tree.empty());

         ifs.seekg (0,std::ios::beg);
         tree.read(ifs,"null");
         CHECK(!tree.empty());

         ifs.seekg (0,std::ios::beg);
         tree.read(ifs,"xml");
         CHECK(!tree.empty());
      }
   }
}
