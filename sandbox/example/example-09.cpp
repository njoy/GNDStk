
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   gnds::indent = 3;

   for (int i = 1;  i < argc;  ++i) {
      const std::string infile = argv[i];
      if (gnds::endsin(infile,"n-092_U_235-covar.xml")) // xml perhaps invalid?
         continue;

      if (gnds::endsin(infile,".xml")) {
         gnds::Tree<std::vector,std::deque> t1(infile);
         gnds::Tree<std::list,std::vector> t2(t1);

         std::ostringstream oss1;
         std::ostringstream oss2;

         t1.write(oss1);
         t2.write(oss2);

         if (oss1.str() != oss2.str())
            std::cout << infile << std::endl;
      }
   }
}
