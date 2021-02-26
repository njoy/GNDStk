#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;

int main()
{
   // Read from XML
   Tree FromXML;
   FromXML.read("n-094_Pu_239.xml");

   // Write to JSON
   FromXML.write("test.json");

   // Read back from JSON
   Tree FromJSON;
   FromJSON.read("test.json");

   // Compare
   assert(FromXML == FromJSON);
}
