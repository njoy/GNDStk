
#include "code/v2.0.hpp"

using namespace njoy::GNDStk;
using namespace code::v2_0;

void print()
{
   std::cout << std::endl;
}

template<class T>
void print(const T &value)
{
   std::cout << value << std::endl;
}

// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char *const *const argv)
{
   print();

   // for printing
   color = true;
   comments = false;

   // documentation: default construction
   print("1");
   gnds::Documentation d;
   print("2");

   // usage
   if (argc < 2) {
      std::cout << "Usage: " << argv[0] << " file ..." << std::endl;
      exit(EXIT_FAILURE);
   }

   // speed test: read
   for (int n = 1; n < argc; ++n) {
      const std::string filename = argv[n];
      std::cout << "\nFile: \"" << filename << '"' << std::endl;
      print();

      gnds::PoPs pops;
      pops.read(filename);
      ///pops.print(); // Component's prettyprinting
      ///pops.write(); // Internal debug format :-/
      pops.xml();
      print();
   }

#if 0
   // speed test: construct from node
   for (int n = 1; n < argc; ++n) {
      const std::string filename = argv[n];
      std::cout << "\nFile: \"" << filename << '"' << std::endl;

      Node node;
      node.read(filename);
      for (int n = 0; n < 100000; ++n)
         gnds::PoPs pops(node);
   }
#endif

#if 0
   // files
   for (int n = 1; n < argc; ++n) {
      const std::string filename = argv[n];
      std::cout << "\nFile: \"" << filename << '"' << std::endl;

      // The following doesn't do what we might intend. Rather, it calls
      // PoPs' default constructor. Think about this...it could prove to
      // be something that confuses users.
      //    gnds::PoPs p(filename);
      // CORRECT WAY:
      print("1");
      gnds::PoPs p;
      print("2");

      print();

      print("read begin");
      p.read(filename);
      print("read end");

      print();
      p.print();
      print();
   }
#endif
}
