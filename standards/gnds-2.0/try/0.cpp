
#include "test/v2.0.hpp"

using namespace njoy::GNDStk;
using namespace test::v2_0;

int main(const int argc, const char *const *const argv)
{
   // color for diagnostics
   colors = true;

   // usage
   if (argc < 2) {
      std::cout << "Usage: " << argv[0] << " file ..." << std::endl;
      exit(EXIT_FAILURE);
   }

   // double
   containers::Double d;
   d << "<double label=\"eval\" value=\"4.00260328327\" unit=\"amu\"/>";
   std::cout << d << std::endl;

   // files
   for (int n = 1; n < argc; ++n) {
      const std::string filename = argv[n];
      std::cout << "File: \"" << filename << '"' << std::endl;

      std::cout << "ReactionSuite begin" << std::endl;
      transport::ReactionSuite r;
      std::cout << "ReactionSuite end" << std::endl;

      try {
         if (r.read(filename))
            std::cout << "   yes" << std::endl;
         else
            std::cout << "   no" << std::endl;
      } catch (...) {
         r.print();
      }
   }
}
