
#include "alpha/v2.0.hpp"

using namespace alpha;
using namespace v2_0;

// process
template<class T>
void read(const Node &node)
{
   T obj;
   obj.read(node);
   //obj.print();
}

// main
int main(const int argc, const char *const *const argv)
{
   /*
   colors = true;
   shades = true;
   indent = 3;
   */
   colors = false;
   shades = false;
   indent = 1;

   for (int i = 1; i < argc; ++i) {
      const std::string file = argv[i];
      std::cout << "File: " << file << std::endl;

      try {
         // Read node from file.
         Node node;
         node.read(file);
         std::cout << "   " << node.name << std::endl;

         // Read object from node. We *can* read an object directly from a file,
         // not merely from a node, if we already know what kind of node is in
         // the file. Here, in the context of reading any GNDS 2.0 file, we must
         // examine the top-level node in order to determine what kind of object
         // we're dealing with.

         if (beginsin(file,"files/a-"))
            read<common::ReactionSuite>(node);
         else if (beginsin(file,"files/atom-"))
            read<atom::PoPs>(node);
         else if (beginsin(file,"files/d-"))
            read<common::ReactionSuite>(node);
         else if (beginsin(file,"files/dec-"))
            read<sfy::PoPs>(node);
         else if (beginsin(file,"files/e-"))
            read<common::ReactionSuite>(node);
         else if (beginsin(file,"files/g-"))
            read<common::ReactionSuite>(node);
         else if (beginsin(file,"files/h-"))
            read<common::ReactionSuite>(node);
         else if (beginsin(file,"files/n-")) {
            if (node.name == "reactionSuite")
               read<common::ReactionSuite>(node);
            else
               read<covariance::CovarianceSuite>(node);
         }
         else if (beginsin(file,"files/nfy-"))
            read<common::FissionFragmentData>(node);
         else if (beginsin(file,"files/p-"))
            read<common::ReactionSuite>(node);
         else if (beginsin(file,"files/photoat-"))
            read<common::ReactionSuite>(node);
         else if (beginsin(file,"files/sfy-"))
            read<sfy::PoPs>(node);
         else if (beginsin(file,"files/std-")) {
            if (node.name == "reactionSuite")
               read<common::ReactionSuite>(node);
            else if (node.name == "covarianceSuite")
               read<covariance::CovarianceSuite>(node);
            else if (node.name == "PoPs")
               read<sfy::PoPs>(node);
            else
               assert(false);
         }
         else if (beginsin(file,"files/t-"))
            read<common::ReactionSuite>(node);
         else if (beginsin(file,"files/tsl-"))
            read<common::ReactionSuite>(node);
         else
            assert(false);

      } catch (...) {
         if (i < argc-1)
            std::cout << "\nContinuing to the next file...\n" << std::endl;
      }
   }
}
