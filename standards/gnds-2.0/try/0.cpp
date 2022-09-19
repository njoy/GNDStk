
#include "test/v2.0.hpp"
using namespace njoy::GNDStk;
using namespace test::v2_0;

int main(const int argc, const char *const *const argv)
{
   // color, for diagnostics
   color = true;

   // usage
   if (argc < 2) {
      std::cout << "Usage: " << argv[0] << " file ..." << std::endl;
      exit(EXIT_FAILURE);
   }

   // files
   for (int n = 1; n < argc; ++n) {
      const std::string filename = argv[n];
      std::cout << "File: \"" << filename << '"' << std::endl;
      transport::ReactionSuite r;
      if (r.read(filename))
         std::cout << "   yes" << std::endl;
      else
         std::cout << "   no" << std::endl;
   }
}
