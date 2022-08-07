
#include "NDILite/v3.hpp"
using namespace NDILite::v3;

int main()
{
   // Make some elements. We can make elements ("outer
   // objects") first, then add isotopes ("inner objects").
   Element H ("H", 1);
   Element He("He",2);
   Element Li("Li",3);
   Element Be("Be",4);

   // Add some isotopes. With this short notation, we
   // get vector push_back()s into an Element's vector
   // of Isotopes.
   H += Isotope(1);
   H += Isotope(2);
   H += Isotope(3);

   He += Isotope(3);
   He += Isotope(4);
   // ...

   // for fun...
   He.isotope.replace(mass_number(4),Isotope(4));
   He.        replace(mass_number(4),Isotope(4));

   He.foobar = Foobar{};

   // Make a couple of libraries. Here, we'll give them
   // (vectors of) elements immediately. (Alternatively,
   // those could have been added later, like we did for
   // adding isotopes above.)
   Library first("first library", {H,He});
   Library second("second library", {Li,Be});

   // Make a multigroup object.
   Multigroup multi("projectile name", {first,second});

   // Example: use a basic getter to get the vector of
   // elements from the second library. Getters are
   // flexible (the good) but mean we have to require
   // the "()" syntax (the ugly). :-/
   std::vector<Element> elems = second.element();
   assert(elems[0].symbol() == "Li");
   assert(elems[1].symbol() == "Be");

   // Example: look stuff up by metadatum value.
   Isotope deu = H.isotope(mass_number(2));
   Isotope tri = H.isotope(mass_number(3));

   // If we instead write isotope() with no arguments
   // to the getter, we get a vector of Isotope objects.
   std::vector<Isotope> iso = H.isotope();

   // Slightly fancier lookup, starting all the way up
   // at the Multigroup object.
   Isotope i =
      multi.library(name("first library"))
           .element(symbol("He"))
           .isotope(mass_number(3));

   // Write as XML, JSON, and HDF5.
   multi.write("file.xml");
   multi.write("file.json");
   multi.write("file.h5");

   // Prettyprint.
   color = true;
   multi.print();
}
