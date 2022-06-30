
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

// SCENARIO
SCENARIO("Testing HDF5 detail:: functionality") {

   using ulong = unsigned long;
   using detail::guessType;
   const std::string space = " ";

   // ------------------------
   // Empty or whitespace-only
   // ------------------------

   GIVEN("Inputs that are empty or whitespace-only") {
      WHEN("We call guessType()") {
         THEN("We get \"\" (meaning \"no value\")") {
            CHECK(guessType("") == "");
            CHECK(guessType(" ") == "");
            CHECK(guessType("  ") == "");
            CHECK(guessType("   ") == "");
         }
      }
   }

   // ------------------------
   // int[s]
   // ------------------------

   GIVEN("Inputs with one or more ints") {
      WHEN("We call guessType()") {
         THEN("We get \"int\" or \"ints\"") {

            CHECK(guessType("10") == "int");
            CHECK(guessType(" 10") == "int");
            CHECK(guessType("10 ") == "int");
            CHECK(guessType(" 10 ") == "int");
            CHECK(guessType("-10") == "int");
            CHECK(guessType(" -10") == "int");
            CHECK(guessType("-10 ") == "int");
            CHECK(guessType(" -10 ") == "int");

            CHECK(guessType("10 20") == "ints");
            CHECK(guessType(" 10 20") == "ints");
            CHECK(guessType("10 20 ") == "ints");
            CHECK(guessType(" 10 20 ") == "ints");
            CHECK(guessType("-10 -20") == "ints");
            CHECK(guessType(" -10 -20") == "ints");
            CHECK(guessType("-10 -20 ") == "ints");
            CHECK(guessType(" -10 -20 ") == "ints");
         }
      }
   }

   // ------------------------
   // unsigned[s]
   // ------------------------

   // Use unsigneds that aren't also ints.
   // Else we'll get "int" or "ints" as above.

   GIVEN("Inputs with one or more unsigneds") {
      WHEN("We call guessType()") {
         THEN("We get \"uint\" or \"uints\"") {

            const unsigned a = std::numeric_limits<unsigned>::max()-1;
            const unsigned b = a+1;
            const std::string astr = std::to_string(a);
            const std::string bstr = std::to_string(b);

            CHECK(guessType(space+astr+space) == "uint");
            CHECK(guessType(space+astr      ) == "uint");
            CHECK(guessType(      astr+space) == "uint");
            CHECK(guessType(      astr      ) == "uint");

            CHECK(guessType(space+astr+space+bstr+space) == "uints");
            CHECK(guessType(space+astr+space+bstr      ) == "uints");
            CHECK(guessType(      astr+space+bstr+space) == "uints");
            CHECK(guessType(      astr+space+bstr      ) == "uints");

            // Mix in a regular int; still needs unsigned overall...
            const std::string istr = std::to_string(123);
            CHECK(guessType(space+istr+space+bstr+space) == "uints");
            CHECK(guessType(space+istr+space+bstr      ) == "uints");
            CHECK(guessType(      istr+space+bstr+space) == "uints");
            CHECK(guessType(      istr+space+bstr      ) == "uints");
         }
      }
   }

   // ------------------------
   // long[s]
   // ------------------------

   // Use longs that aren't also ints or unsigneds.

   if (sizeof(long) > sizeof(int)) {
      GIVEN("Inputs with one or more longs") {
         WHEN("We call guessType()") {
            THEN("We get \"long\" or \"longs\"") {

               const long a = std::numeric_limits<long>::min(); // negative
               const long b = std::numeric_limits<long>::max(); // positive
               const std::string astr = std::to_string(a);
               const std::string bstr = std::to_string(b);

               CHECK(guessType(space+astr+space) == "long");
               CHECK(guessType(space+astr      ) == "long");
               CHECK(guessType(      astr+space) == "long");
               CHECK(guessType(      astr      ) == "long");

               CHECK(guessType(space+astr+space+bstr+space) == "longs");
               CHECK(guessType(space+astr+space+bstr      ) == "longs");
               CHECK(guessType(      astr+space+bstr+space) == "longs");
               CHECK(guessType(      astr+space+bstr      ) == "longs");

               // Mix in a regular int; still needs long overall...
               const std::string istr = std::to_string(123);
               CHECK(guessType(space+istr+space+bstr+space) == "longs");
               CHECK(guessType(space+istr+space+bstr      ) == "longs");
               CHECK(guessType(      istr+space+bstr+space) == "longs");
               CHECK(guessType(      istr+space+bstr      ) == "longs");

               // Mix in an unsigned; still needs long overall...
               const unsigned u = std::numeric_limits<unsigned>::max();
               const std::string ustr = std::to_string(u);
               CHECK(guessType(space+ustr+space+bstr+space) == "longs");
               CHECK(guessType(space+ustr+space+bstr      ) == "longs");
               CHECK(guessType(      ustr+space+bstr+space) == "longs");
               CHECK(guessType(      ustr+space+bstr      ) == "longs");
            }
         }
      }
   }

   // ------------------------
   // unsigned long[s]
   // ------------------------

   // Use unsigned longs that aren't also ints, unsigneds, or longs.

   if (sizeof(ulong) > sizeof(unsigned)) {
      GIVEN("Inputs with one or more unsigned longs") {
         WHEN("We call guessType()") {
            THEN("We get \"ulong\" or \"ulongs\"") {

               const ulong a = std::numeric_limits<ulong>::max()-1;
               const ulong b = a+1;
               const std::string astr = std::to_string(a);
               const std::string bstr = std::to_string(b);

               CHECK(guessType(space+astr+space) == "ulong");
               CHECK(guessType(space+astr      ) == "ulong");
               CHECK(guessType(      astr+space) == "ulong");
               CHECK(guessType(      astr      ) == "ulong");

               CHECK(guessType(space+astr+space+bstr+space) == "ulongs");
               CHECK(guessType(space+astr+space+bstr      ) == "ulongs");
               CHECK(guessType(      astr+space+bstr+space) == "ulongs");
               CHECK(guessType(      astr+space+bstr      ) == "ulongs");

               // Mix in a regular int; still needs long overall...
               const std::string istr = std::to_string(123);
               CHECK(guessType(space+istr+space+bstr+space) == "ulongs");
               CHECK(guessType(space+istr+space+bstr      ) == "ulongs");
               CHECK(guessType(      istr+space+bstr+space) == "ulongs");
               CHECK(guessType(      istr+space+bstr      ) == "ulongs");

               // Mix in an unsigned; still needs unsigned long overall...
               const unsigned u = std::numeric_limits<unsigned>::max();
               const std::string ustr = std::to_string(u);
               CHECK(guessType(space+ustr+space+bstr+space) == "ulongs");
               CHECK(guessType(space+ustr+space+bstr      ) == "ulongs");
               CHECK(guessType(      ustr+space+bstr+space) == "ulongs");
               CHECK(guessType(      ustr+space+bstr      ) == "ulongs");

               // Mix in a long; still needs unsigned long overall...
               const long l = std::numeric_limits<long>::max();
               const std::string lstr = std::to_string(l);
               CHECK(guessType(space+lstr+space+bstr+space) == "ulongs");
               CHECK(guessType(space+lstr+space+bstr      ) == "ulongs");
               CHECK(guessType(      lstr+space+bstr+space) == "ulongs");
               CHECK(guessType(      lstr+space+bstr      ) == "ulongs");
            }
         }
      }
   }

   // ------------------------
   // For use in double[s]
   // and string[s] cases
   // ------------------------

   const std::string
      imin  = std::to_string(std::numeric_limits<int     >::min()),
      imax  = std::to_string(std::numeric_limits<int     >::max()),
      umin  = std::to_string(std::numeric_limits<unsigned>::min()),
      umax  = std::to_string(std::numeric_limits<unsigned>::max()),
      lmin  = std::to_string(std::numeric_limits<long    >::min()),
      lmax  = std::to_string(std::numeric_limits<long    >::max()),
      ulmin = std::to_string(std::numeric_limits<ulong   >::min()),
      ulmax = std::to_string(std::numeric_limits<ulong   >::max()),
      dmin  = std::to_string(std::numeric_limits<double  >::min()),
      dmax  = std::to_string(std::numeric_limits<double  >::max());

   // ------------------------
   // double[s]
   // ------------------------

   GIVEN("Inputs with one or more doubles") {
      WHEN("We call guessType()") {
         THEN("We get \"double\" or \"doubles\"") {

            CHECK(guessType("1.23") == "double");
            CHECK(guessType(" 1.23") == "double");
            CHECK(guessType("1.23 ") == "double");
            CHECK(guessType(" 1.23 ") == "double");
            CHECK(guessType("-1.23") == "double");
            CHECK(guessType(" -1.23") == "double");
            CHECK(guessType("-1.23 ") == "double");
            CHECK(guessType(" -1.23 ") == "double");

            CHECK(guessType("1.23 4.56") == "doubles");
            CHECK(guessType(" 1.23 4.56") == "doubles");
            CHECK(guessType("1.23 4.56 ") == "doubles");
            CHECK(guessType(" 1.23 4.56 ") == "doubles");
            CHECK(guessType("-1.23 -4.56") == "doubles");
            CHECK(guessType(" -1.23 -4.56") == "doubles");
            CHECK(guessType("-1.23 -4.56 ") == "doubles");
            CHECK(guessType(" -1.23 -4.56 ") == "doubles");

            // Make sure that beginning with any "lesser" type doesn't
            // prevent later values from forcing double-ness...
            CHECK(guessType( imin+space+"1.23") == "doubles");
            CHECK(guessType( imax+space+"1.23") == "doubles");
            CHECK(guessType( umin+space+"1.23") == "doubles");
            CHECK(guessType( umax+space+"1.23") == "doubles");
            CHECK(guessType( lmin+space+"1.23") == "doubles");
            CHECK(guessType( lmax+space+"1.23") == "doubles");
            CHECK(guessType(ulmin+space+"1.23") == "doubles");
            CHECK(guessType(ulmax+space+"1.23") == "doubles");

            CHECK(guessType( imin+space+"1.23 4.56") == "doubles");
            CHECK(guessType( imax+space+"1.23 4.56") == "doubles");
            CHECK(guessType( umin+space+"1.23 4.56") == "doubles");
            CHECK(guessType( umax+space+"1.23 4.56") == "doubles");
            CHECK(guessType( lmin+space+"1.23 4.56") == "doubles");
            CHECK(guessType( lmax+space+"1.23 4.56") == "doubles");
            CHECK(guessType(ulmin+space+"1.23 4.56") == "doubles");
            CHECK(guessType(ulmax+space+"1.23 4.56") == "doubles");
         }
      }
   }

   // ------------------------
   // string[s]
   // ------------------------

   GIVEN("Inputs with one or more strings") {
      WHEN("We call guessType()") {
         THEN("We get \"string\" or \"strings\"") {

            CHECK(guessType("abc") == "string");
            CHECK(guessType(" abc") == "string");
            CHECK(guessType("abc ") == "string");
            CHECK(guessType(" abc ") == "string");
            CHECK(guessType("-abc") == "string");
            CHECK(guessType(" -abc") == "string");
            CHECK(guessType("-abc ") == "string");
            CHECK(guessType(" -abc ") == "string");

            CHECK(guessType("abc def") == "strings");
            CHECK(guessType(" abc def") == "strings");
            CHECK(guessType("abc def ") == "strings");
            CHECK(guessType(" abc def ") == "strings");
            CHECK(guessType("-abc -def") == "strings");
            CHECK(guessType(" -abc -def") == "strings");
            CHECK(guessType("-abc -def ") == "strings");
            CHECK(guessType(" -abc -def ") == "strings");

            // Make sure that beginning with any "lesser" type doesn't
            // prevent later values from forcing string-ness...
            CHECK(guessType( imin+space+"abc") == "strings");
            CHECK(guessType( imax+space+"abc") == "strings");
            CHECK(guessType( umin+space+"abc") == "strings");
            CHECK(guessType( umax+space+"abc") == "strings");
            CHECK(guessType( lmin+space+"abc") == "strings");
            CHECK(guessType( lmax+space+"abc") == "strings");
            CHECK(guessType(ulmin+space+"abc") == "strings");
            CHECK(guessType(ulmax+space+"abc") == "strings");
            CHECK(guessType( dmin+space+"abc") == "strings");
            CHECK(guessType( dmax+space+"abc") == "strings");

            CHECK(guessType( imin+space+"abc def") == "strings");
            CHECK(guessType( imax+space+"abc def") == "strings");
            CHECK(guessType( umin+space+"abc def") == "strings");
            CHECK(guessType( umax+space+"abc def") == "strings");
            CHECK(guessType( lmin+space+"abc def") == "strings");
            CHECK(guessType( lmax+space+"abc def") == "strings");
            CHECK(guessType(ulmin+space+"abc def") == "strings");
            CHECK(guessType(ulmax+space+"abc def") == "strings");
            CHECK(guessType( dmin+space+"abc def") == "strings");
            CHECK(guessType( dmax+space+"abc def") == "strings");
         }
      }
   }

} // SCENARIO
