
#include "alpha/v2.0.hpp"

using namespace alpha;
using namespace v2_0;

// process
template<class T>
void read(const Node &node)
{
   T obj;
   obj.read(node);
   // obj.print();
}

// main
int main(const int argc, const char *const *const argv)
{
   colors = false;
   shades = false;
   indent = 1;
   // Consider these instead if you use print() above:
   // colors = true;
   // shades = true;
   // indent = 3;

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

         if (beginsin(file,"files/a-") ||
             beginsin(file,"files/d-") ||
             beginsin(file,"files/e-") ||
             beginsin(file,"files/g-") ||
             beginsin(file,"files/h-") ||
             beginsin(file,"files/p-") ||
             beginsin(file,"files/photoat-") ||
             beginsin(file,"files/t-") ||
             beginsin(file,"files/tsl-")) {
            // is ReactionSuite
            read<top::ReactionSuite>(node);
         } else if (beginsin(file,"files/atom-") ||
                    beginsin(file,"files/dec-") ||
                    beginsin(file,"files/sfy-")) {
            // is PoPs
            read<top::PoPs>(node);
         } else if (beginsin(file,"files/nfy-")) {
            // is FissionFragmentData
            read<top::FissionFragmentData>(node);
         } else if (beginsin(file,"files/n-")) {
            // can be either of two things...
            node.name == "reactionSuite"
          ? read<top::ReactionSuite>(node)
          : read<top::CovarianceSuite>(node);
         }
         else if (beginsin(file,"files/std-")) {
            // can be any of three things...
            node.name == "reactionSuite"
          ? read<top::ReactionSuite>(node)
          : node.name == "covarianceSuite"
          ? read<top::CovarianceSuite>(node)
          : read<top::PoPs>(node);
         }
         else {
            // oops, should have done *something* above
            assert(false);
         }

      } catch (...) {
         if (i < argc-1)
            std::cout << "\nContinuing to the next file...\n" << std::endl;
      }
   }
}
