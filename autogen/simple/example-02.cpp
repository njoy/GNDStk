
#include "multi/v1.hpp"
using namespace multi::v1;

int main()
{
   colors = true;

   // Try a Foobar all by itself
   {
      Foobar f(std::vector<double>{ 1, 2, 3, 4, 5 });
      f.write("foobar.xml");
      f.write("foobar.json");
      f.write("foobar.h5");
      f.print();

      // read from xml
      std::cout << "\nTrying to read XML:" << std::endl;
      f.read("foobar.xml");
      std::cout << "Back from XML:" << std::endl;
      f.print();

      // read from json
      std::cout << "\nTrying to read JSON:" << std::endl;
      f.read("foobar.json");
      std::cout << "Back from JSON:" << std::endl;
      f.print();

      // read from h5
      std::cout << "\nTrying to read H5:" << std::endl;
      f.read("foobar.h5");
      std::cout << "Back from H5:" << std::endl;
      f.print();
   }
}
