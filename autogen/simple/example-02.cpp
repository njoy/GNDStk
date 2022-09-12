
#include "multi/v1.hpp"
using namespace multi::v1;

int main()
{
   color = true;

   // Try a Foobar all by itself. Note that class Foobar has only data,
   // no metadata or child nodes.
   {
      Foobar f(std::vector<double>{ 1, 2, 3, 4, 5 });
      f.write("foobar.json");
      f.read ("foobar.json");
   }
}
