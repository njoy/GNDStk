
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   gnds::indent = 3;

   for (int i = 1;  i < argc;  ++i) {
      const std::string infile = argv[i];
      if (gnds::endsin(infile,"n-092_U_235-covar.xml")) // xml perhaps invalid?
         continue;

      if (gnds::endsin(infile,".xml")) {
         gnds::xml x1(infile);
         gnds::xml x2(x1);

         std::ostringstream oss1;
         std::ostringstream oss2;

         x1.write(oss1);
         x2.write(oss2);

         /*
         std::cout << infile << std::endl;
         std::cout << "   " << oss1.str().size() << std::endl;
         std::cout << "   " << oss2.str().size() << std::endl;
         */

         if (oss1.str() != oss2.str())
            std::cout << infile << std::endl;
      }
   }
}
