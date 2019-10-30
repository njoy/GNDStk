
#include "gnds.hpp"

// helper: compare
void compare(const gnds::knoop &k, const gnds::generic &g)
{
   std::ostringstream strk;
   std::ostringstream strg;
   k.write(strk);
   g.write(strg);
   assert(strk.str() == strg.str());
}



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char * const * const argv)
{
   /*
   // xml
   gnds::xml x("19.xml" );
   {
      std::ostringstream strk;
      std::ostringstream strg;
      gnds::knoop  (x).write(strk); // xml  ==> knoop   ==> write
      gnds::generic(x).write(strg); // xml  ==> generic ==> write
      assert(strk.str() == strg.str()); // results should be the same
   }

   // json
   gnds::json j("19.json");
   {
      std::ostringstream strk;
      std::ostringstream strg;
      gnds::knoop  (j).write(strk); // json ==> knoop   ==> write
      gnds::generic(j).write(strg); // json ==> generic ==> write
      assert(strk.str() == strg.str()); // results should be the same
   }
   */

   // ------------------------
   // Stress test
   // ------------------------

   // for timing...
   const int ntiming = 10;

   // command-line arguments...
   for (int i = 1;  i < argc;  ++i) {
      // file
      const std::string filename = argv[i];

      // skip if above some arbitrary size
      if (gnds::filesize(filename) > 100000000) {
         std::cout
            << "Skipping file \"" << filename << "\" (too long)"
            << std::endl;
         continue;
      }

      // xml?
      if (gnds::endsin(argv[i],".xml")) {
         std::cout << "Loading XML file \"" << filename << "\"" << std::endl;
         gnds::xml x(filename);
         // convert to our knoop and generic types...
         for (int count = ntiming;  count-- ; ) {
            gnds::knoop   k(x);
            gnds::generic g(x);
            compare(k,g);
         }

      // json?
      } else if (gnds::endsin(argv[i],".json")) {
         std::cout << "Loading Json file \"" << filename << "\"" << std::endl;
         gnds::json j(filename);
         // convert to our knoop and generic types...
         for (int count = ntiming;  count-- ; ) {
            gnds::knoop   k(j);
            gnds::generic g(j);
            compare(k,g);
         }

      // unknown type
      } else {
         std::cout
            << "Skipping file \"" << filename << "\" (unknown type)"
            << std::endl;
      }
   }
}
