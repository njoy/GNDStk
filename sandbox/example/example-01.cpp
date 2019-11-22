
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   assert(argc == 2);

   const char *const file = argv[1];
   std::ifstream ifs(file);

   // CONSTRUCTION: 3 forms
   gnds::xml a(file); // from char * file
   gnds::xml b{std::string(file)}; // from string file (NB: not string stream)
   gnds::xml c(ifs); // from istream

   // READ: 4 forms
   a.read(file); // from char * file
   a.read(std::string(file)); // from string file
   ifs.clear(); ifs.seekg(0, std::ios::beg);
   a.read(ifs); // from istream
   ifs.clear(); ifs.seekg(0, std::ios::beg);
   ifs >> a; // with operator>>

   // WRITE: 4 forms
   a.write("out.xml"); // to char * file
   a.write(std::string("out.xml")); // to string file
   {
      std::ofstream ofs("out.xml");
      a.write(ofs); // to ostream
   }
   {
      std::ofstream ofs("out.xml");
      ofs << a << std::endl; // with operator<<
      // Remark: It looks like there is, in my opinion, a tiny flaw in
      // pugixml's output (which we wrap with our write() and stream output
      // functionality). It puts a newline after the last non-whitespace
      // character at the very end. That means that our own use of std::endl
      // creates *another* blank line. Output, even of multi-line objects,
      // should avoid placing a newline at the very end. That way, a user's
      // direct use of newlines is entirely consistent (read: predictable)
      // with respect to the use of newlines for simple types. -MFS
   }
}
