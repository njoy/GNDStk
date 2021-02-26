#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

int main()
{
   Tree pu239;
   pu239.read("n-094_Pu_239.xml");
   indent = 2; // <== not necessary; just for illustration
   pu239.write("pu239");
}
