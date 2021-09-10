
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk::core;
#include "precision.test.hpp"



// -----------------------------------------------------------------------------
// Description
// -----------------------------------------------------------------------------

/*
GNDStk::metadata
   inline Precision<PrecisionContext::metadata, float      > floats;
   inline Precision<PrecisionContext::metadata, double     > doubles;
   inline Precision<PrecisionContext::metadata, long double> longdoubles;
   inline Precision<PrecisionContext::metadata, void       > reals;

GNDStk::data
   inline Precision<PrecisionContext::data, float      > floats;
   inline Precision<PrecisionContext::data, double     > doubles;
   inline Precision<PrecisionContext::data, long double> longdoubles;
   inline Precision<PrecisionContext::data, void       > reals;

GNDStk::
   inline Precision<PrecisionContext::general, float      > floats;
   inline Precision<PrecisionContext::general, double     > doubles;
   inline Precision<PrecisionContext::general, long double> longdoubles;
   inline Precision<PrecisionContext::general, void       > reals;

--------
--------

I/O processes that use Precision<>...

( ) 1. src/GNDStk/string2type.hpp
    read : void convert(std::istream &is, T &value)
    convert(istream,real)

( ) 2. src/GNDStk/type2string.hpp
    write: void convert(const T &value, std::ostream &os)
    convert(real,ostream)

( ) 3. src/GNDStk/BodyText/src/detail.hpp
    read,  in element2element
       element2element, called only in body-get.hh
    write, in element2element
      element2element, called only in body-get.hh

( ) 4. src/GNDStk/BodyText/src/get.hpp
    body::get(), read from raw string to numbers
       raw string ==> reals: Precision<>
       reworking the vector: element2element

( ) 5. src/GNDStk/BodyText/src/toNode.hpp
    body::toNode(), write to text that will go into a Node
    write: BodyText::toNode()'s reals to text for Node "body text"

( ) 6. src/GNDStk/BodyText/src/write.hpp
    body::write(), our high-level class prettyprinter, printing data block
    write: BodyText::write()'s  reals to prettyprinted data block

( ) 7. src/GNDStk/Component/src/detail.hpp
    writeComponentPart, the prettyprinter printing one value
    write: Component::write()'s real to prettyprinted value w/writeComponentPart

( ) For read, Component::fromNode() uses multi-query (so, convert(istream,real))
*/


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

const std::string input =
R"***(
<numbers
   afloat  = "3.141592653589793238462643383279502884197169399375"
   adouble = "2.718281828459045235360287471352662497757247093700"
   aquad   = "1.414213562373095048801688724209698078569671875377">
  <floats>    </floats>
  <doubles>   </doubles>
  <quads>     </quads>
  <varfloats> </varfloats>
  <vardoubles></vardoubles>
  <varquads>  </varquads>
</numbers>
)***";



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Precision capability") {
   Node node;
   node << input;
   precision::Numbers num(node);

   const std::vector<float > fvec = {{ 1.2, 3.4, 5.6, 7.8, 9.0 }};
   const std::vector<double> dvec = {{ 1.23, 4.56, 7.89 }};
   num.floats() = fvec;
   num.floats() = dvec;
   num.floats(fvec);
   num.floats(dvec);

   // PRINT
   std::cout << num << std::endl;
}



// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing some GNDStk convert() functionality") {

   // todo These relate to some recently-added material,
   // but really belong elsewhere

   // ------------------------
   // string ==> pair
   // ------------------------

   {
      const std::string str = "12,34";
      std::istringstream iss(str);
      std::pair<int,long> p;
      njoy::GNDStk::convert(iss,p);
      CHECK(p.first  == 12);
      CHECK(p.second == 34);
   }

   {
      const std::string str = "56 78";
      std::istringstream iss(str);
      std::pair<int,long> p;
      njoy::GNDStk::convert(iss,p);
      CHECK(p.first  == 56);
      CHECK(p.second == 78);
   }

   // ------------------------
   // pair ==> string
   // ------------------------

   {
      const std::pair<int,long> p(12,34);
      std::ostringstream oss;
      njoy::GNDStk::convert(p,oss);
      const std::string str = oss.str();
      CHECK(str == "12 34");
   }

   {
      njoy::GNDStk::comma = true; // says we want a comma in the output...
      const std::pair<int,long> p(56,78);
      std::ostringstream oss;
      njoy::GNDStk::convert(p,oss);
      const std::string str = oss.str();
      CHECK(str == "56,78"); // ...so there it is
   }
}
