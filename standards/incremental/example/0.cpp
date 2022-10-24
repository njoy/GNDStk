
#include "code/v2.0.hpp"

using namespace njoy::GNDStk;
using namespace code::v2_0;

int main(const int argc, const char *const *const argv)
{
   // for printing
   color = true;
   comments = false;

   /*
   // usage
   if (argc < 2) {
      std::cout << "Usage: " << argv[0] << " file ..." << std::endl;
      exit(EXIT_FAILURE);
   }
   */

   std::cout << "1" << std::endl;
   gnds::Documentation d;
   std::cout << "2" << std::endl;

   // files
   for (int n = 1; n < argc; ++n) {
      const std::string filename = argv[n];
      std::cout << "File: \"" << filename << '"' << std::endl;

      /*
      // The following doesn't do what we might intend. Rather, it calls
      // PoPs' default constructor. Think about this...it could prove to
      // be something that could trip up our users.
      // gnds::PoPs p(filename);

      // The CORRECT way to do this:
      for (int n = 0; n < 10; ++n) {
         static gnds::PoPs p;
         p.read(filename);
         p.print();
      }
      */

      /*
      std::cout << "1" << std::endl;
      gnds::Documentation d;
      std::cout << "2" << std::endl;
      d.read(filename);
      std::cout << "3" << std::endl;
      d.print();
      std::cout << "4" << std::endl;
      */
   }
}
