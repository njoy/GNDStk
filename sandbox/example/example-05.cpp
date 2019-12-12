
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   gnds::indent = 2; // <== to be consistent with the XMLs I have

   for (int a = 1;  a < argc;  ++a) {
      const std::string infile = argv[a];

      // xml
      if (gnds::endsin(infile,".xml")) {
         const std::string outfile = infile.substr(0,infile.size()-4)+".json";
         std::ofstream stream(outfile.c_str());
         stream << gnds::json(gnds::tree(infile)) << std::endl;
      }

      // json
      if (gnds::endsin(infile,".json")) {
         const std::string outfile = infile.substr(0,infile.size()-5)+".json2";
         std::ofstream stream(outfile.c_str());
         //stream << gnds::tree(infile) << std::endl;
         stream << gnds::json(gnds::tree(infile)) << std::endl;
      }
   }
}
