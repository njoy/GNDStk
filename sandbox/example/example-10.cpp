
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   gnds::indent = 2;

   for (int i = 1;  i < argc;  ++i) {
      const std::string infile = argv[i];
      if (gnds::endsin(infile,"n-092_U_235-covar.xml")) // xml perhaps invalid?
         continue;

      gnds::tree t(infile);

      // std::cout << t << std::endl;
      gnds::xml x(t);
      // std::cout << x << std::endl;

      /*
fixme
the following isn't what we want;
we should read directly into an xml, then convert to tree, back to xml,
and then compare those two xmls;
whitespace may be treated differently?

      gnds::xml x1(t);
      gnds::xml x2(t);
      std::ostringstream oss1;
      std::ostringstream oss2;
      x1.write(oss1);
      x2.write(oss2);

      if (oss1.str() != oss2.str())
         std::cout << infile << std::endl;
      */
   }
}
