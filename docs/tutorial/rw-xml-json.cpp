#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

int main()
{
   Tree pu239;
   pu239.read("n-094_Pu_239.xml");
   pu239.write("n-094_Pu_239.json");
}
