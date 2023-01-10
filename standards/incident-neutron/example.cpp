
#include "IncidentNeutron/v2.0.hpp"

using namespace IncidentNeutron;
using namespace v2_0;
using namespace IncidentNeutronMeanValues;

int main(const int argc, const char *const *const argv)
{
   // In case we do an r.print() below
   colors = true;
   shades = true;

   // Read from files specified on the command line
   IncidentNeutronMeanValues::ReactionSuite r;
   for (int i = 1; i < argc; ++i) {
      std::cout << "File: " << argv[i] << std::endl;
      try {
         r.read(argv[i]);
      } catch (...) {
         if (i < argc-1)
            std::cout << "Continuing to the next file...\n" << std::endl;
      }
   }
}
