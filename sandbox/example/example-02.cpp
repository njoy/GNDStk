
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   assert(argc == 2);

   const char *const file = argv[1];
   std::ifstream ifs(file);

   // CONSTRUCTION: 3 forms
   gnds::json a(file); // from char * file
   gnds::json b{std::string(file)}; // from string file (NB: not string stream)
   gnds::json c(ifs); // from istream

   // READ: 4 forms
   a.read(file); // from char * file
   a.read(std::string(file)); // from string file
   ifs.clear(); ifs.seekg(0, std::ios::beg);
   a.read(ifs); // from istream
   ifs.clear(); ifs.seekg(0, std::ios::beg);
   ifs >> a; // with operator>>

   // WRITE: 4 forms
   a.write("out.json"); // to char * file
   a.write(std::string("out.json")); // to string file
   {
      std::ofstream ofs("out.json");
      a.write(ofs); // to ostream
   }
   {
      std::ofstream ofs("out.json");
      ofs << a << std::endl; // with operator<<
   }
}
