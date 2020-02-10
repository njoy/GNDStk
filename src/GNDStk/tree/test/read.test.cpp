
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree read() and operator>>") {
   gnds::Tree<> t1, t2, t3, t4, t5;

   GIVEN("Some trees") {
      // Note: there's no super compelling reason that our library actually
      // has a direct (char *) version, as opposed to having only the string
      // version and then relying on implicit conversion from char * to string.
      // In fact, our library's (string) version just uses .c_str() and forwards
      // to the (char *) version! In principle, we could make our (char *)
      // version very slightly more efficient, by having it avoid conversions
      // to string entirely. It doesn't do that right now, however, and, really,
      // this is hardly an area in which we'd be concerned about performance.
      // If our directly writing (char *) and (string) versions bothers anyone,
      // we can easily chuck the (char *) variant.

      WHEN("We read one from a char * filename") {
         t1.read("n-008_O_016.xml");
         REQUIRE(!t1.empty()); // we get something
      }

      WHEN("We read one from a string filename") {
         const std::string filename = "n-008_O_016.xml";
         t2.read(filename);
         REQUIRE(!t2.empty()); // we get something
      }

      WHEN("We read one from an istream, specifically an ifstream") {
         std::ifstream ifs("n-008_O_016.xml");
         t3.read(ifs);
         REQUIRE(!t3.empty()); // we get something
      }

      WHEN("We read one from an istream, specifically a stringstream") {
         std::ifstream ifs("n-008_O_016.xml");
         std::stringstream sstr;
         sstr << ifs.rdbuf();
         t4.read(sstr);
         REQUIRE(!t4.empty()); // we get something
      }

      WHEN("We stream-input one, specifically from an ifstream") {
         std::ifstream ifs("n-008_O_016.xml");
         ifs >> t5;
         REQUIRE(!t5.empty()); // we get something
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
      std::ostringstream oss5; t5.write(oss5);

      REQUIRE(oss1.str() == oss2.str());
      REQUIRE(oss1.str() == oss3.str());
      REQUIRE(oss1.str() == oss4.str());
      REQUIRE(oss1.str() == oss5.str());
   }

   // fixme There's actually somewhat more we can test, with regards to tree's
   // read(). Above, we're just dealing with an XML file, not a Json (for which
   // we don't yet have an official GNDS file) or an HDF (ditto, and for which
   // we don't have read/write capabilities yet either). Also, we allow for a
   // direct user-stipulated format (xml, json, hdf5) in our read()s, for which
   // warnings might be issued if the file extension and/or the file's first
   // byte appear to be inconsistent with the user-stipulated format. Another
   // thing we could test would be ensuring that read() works correctly with
   // different valid templatizations of gnds::Tree<>.
}
