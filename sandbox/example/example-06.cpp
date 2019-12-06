
#include "gnds.hpp"
using namespace gnds;
using namespace gnds::child;
using namespace gnds::meta;

int main(const int argc, const char * const * const argv)
{
   // read file into tree
   assert(argc == 2);
   const tree doc(argv[1]);

   // ------------------------
   // examples of data access
   // ------------------------

   std::cout << doc(reactionSuite, styles, evaluated, date) << std::endl;

   std::cout << doc(reactionSuite, PoPs, chemicalElements, chemicalElement,
                    isotopes, isotope, nuclides, nuclide, mass, Double, label)
             << std::endl;

   std::cout << doc(reactionSuite, PoPs, chemicalElements,  chemicalElement,
                    isotopes, isotope, nuclides, nuclide, mass, Double
                   ).meta(label)
             << std::endl;

   // value can be any of a few types...
   std::cout << doc(
      reactionSuite,
      PoPs,
      chemicalElements,
      chemicalElement,
      isotopes,
      isotope,
      nuclides,
      nuclide,
      mass,
      Double
   ).meta<double>(value) << std::endl;
}
