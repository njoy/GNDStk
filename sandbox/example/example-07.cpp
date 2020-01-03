
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   assert(argc == 2);
   gnds::indent = 2;

   // xml, read directly
   gnds::xml x(argv[1]);

   // tree, read directly (actually goes through xml internally
   gnds::tree t(argv[1]);

   // tree, constructed from xml
   gnds::tree t2(x);

   // tree results should be identical
   {
      std::ostringstream one, two;
      one << t;
      two << t2;
      assert(one.str() == two.str());
   }

   // construct json from tree
   gnds::json j(t);

   // write json
   std::ofstream ofsj("file.json");
   ofsj << j << std::endl;

   // write tree
   std::ofstream ofst("file.tree");
   ofst << t << std::endl;
}
