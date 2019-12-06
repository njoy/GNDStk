
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   assert(argc == 2);

   // automatically determines xml or json...
   gnds::tree doc(argv[1]);

   // these have keywords we'll use below
   using namespace gnds::child;
   using namespace gnds::meta;

   // access data...
   std::cout << doc(
      reactionSuite,
      styles,
      evaluated,
      date
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

   // same as above, different form...
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

   // "value" could be any of a few types, depending on context,
   // so we say <double> below. I plan to come up with something
   // that tracks context and uses it to determine type, so users
   // won't need to do it.
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
