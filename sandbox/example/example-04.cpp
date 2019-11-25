
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   // file
   assert(argc == 2);
   gnds::tree doc(argv[1]);

   // has the keywords we use below
   using namespace gnds::key;

   // access data...
   std::cout << doc(
      reactionSuite,
      styles,
      evaluated,
      label
   ) << std::endl;

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
      Double,
      label
   ) << std::endl;

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
   ).meta(label) << std::endl;

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
