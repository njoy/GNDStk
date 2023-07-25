
#include "gnds/v2.0.hpp"
using namespace gnds;
using namespace v2_0;

// Run this code with any or all GNDS 2.0 files as command-line arguments
int main(const int argc, const char *const *const argv)
{
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
         if (node.name == "reactionSuite") {
            top::ReactionSuite obj;
            obj.read(node);
         } else if (node.name == "covarianceSuite") {
            top::CovarianceSuite obj;
            obj.read(node);
         } else if (node.name == "PoPs") {
            top::PoPs obj;
            obj.read(node);
         } else if (node.name == "fissionFragmentData") {
            top::FissionFragmentData obj;
            obj.read(node);
         } else {
            std::cout << "This shouldn't happen" << std::endl;
         }
      } catch (...) {
         if (i < argc-1)
            std::cout << "\nContinuing to the next file...\n" << std::endl;
      }
   }
}
