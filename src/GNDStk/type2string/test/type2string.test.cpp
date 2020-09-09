
#define CATCH_CONFIG_MAIN


// -----------------------------------------------------------------------------
// convert(pair<int,double>,ostream)
// To override GNDStk's general one:
// template<class T>
// void convert(const T &value, std::ostream &os)
// -----------------------------------------------------------------------------

#include <utility>
#include <iostream>

namespace njoy {
namespace GNDStk {
   inline void convert(
      const std::pair<int,double> &p,
      std::ostream &s
   ) {
      s << p.first << ' ' << p.second;
   }
}
}


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk convert(type,ostream|string)") {

   // ------------------------
   // convert(*,ostream)
   // ------------------------

   WHEN("We call convert(T,ostream) for some scalars T") {
      THEN("It works for T == int") {
         const int i = 1;
         std::ostringstream oss;
         convert(i,oss);
         CHECK(oss.str() == "1");
      }

      THEN("It works for T == float") {
         const float f = 2.3f;
         std::ostringstream oss;
         convert(f,oss);
         CHECK(oss.str() == "2.3");
      }

      THEN("It works for T == double") {
         const double d = 4.56;
         std::ostringstream oss;
         convert(d,oss);
         CHECK(oss.str() == "4.56");
      }
   }

   WHEN("We call convert(T,ostream) for some sequence containers T") {
      THEN("It works for T == deque") {
         const std::deque<int> container = { 10, 20, 30 };
         std::ostringstream oss;
         convert(container,oss);
         CHECK(oss.str() == "10 20 30");
      }

      THEN("It works for T == list") {
         const std::list<int> container = { 100, 200, 300 };
         std::ostringstream oss;
         convert(container,oss);
         CHECK(oss.str() == "100 200 300");
      }

      THEN("It works for T == vector") {
         const std::vector<int> container = { 1000, 2000, 3000 };
         std::ostringstream oss;
         convert(container,oss);
         CHECK(oss.str() == "1000 2000 3000");
      }
   }

   // ------------------------
   // convert(*,string)
   // ------------------------

   WHEN("We call convert(T,string) for pair T") {
      THEN("It ends up calling our custom convert(pair,ostream)") {
         const std::pair<int,double> p(12,3.45);
         std::string str;
         convert(p,str);
         CHECK(str == "12 3.45");
      }
   }

   WHEN("We call convert(T,string) for char *T") {
      // Note: see remark in type2string.hpp about why we deal
      // with char * at all (as opposed to just std::string)
      THEN("It just does a string = char * assignment in this case") {
         const char *const c = "abcdefg";
         std::string str;
         convert(c,str);
         CHECK(str == "abcdefg");
      }
   }

   WHEN("We call convert(T,string) for string T") {
      THEN("It just does a string assignment in this case") {
         const std::string s("abcdefg");
         std::string str;
         convert(s,str);
         CHECK(str == "abcdefg");
      }
   }

   WHEN("We call convert(T,string) for bool T") {
      THEN("It produces \"true\" or \"false\", per GNDS specs") {
         {
            const bool t = true;
            std::string tstr;
            convert(t,tstr);
            CHECK(tstr == "true");
         } {
            const bool f = false;
            std::string fstr;
            convert(f,fstr);
            CHECK(fstr == "false");
         }
      }
   }

   WHEN("We call convert(string,T) for some integral and floating-point Ts") {
      {
         const int val = -123;
         std::string str;
         convert(val,str);
         CHECK(str == "-123");
      } {
         const long val = -123;
         std::string str;
         convert(val,str);
         CHECK(str == "-123");
      } {
         const long long val = -123;
         std::string str;
         convert(val,str);
         CHECK(str == "-123");
      } {
         const unsigned val = 456;
         std::string str;
         convert(val,str);
         CHECK(str == "456");
      } {
         const unsigned long val = 456;
         std::string str;
         convert(val,str);
         CHECK(str == "456");
      } {
         const unsigned long long val = 456;
         std::string str;
         convert(val,str);
         CHECK(str == "456");
      } {
         const float val = 7.89f;
         std::string str;
         convert(val,str);
         CHECK(str == "7.89");
      } {
         const double val = 7.89;
         std::string str;
         convert(val,str);
         CHECK(str == "7.89");
      } {
         const long double val = 7.89L;
         std::string str;
         convert(val,str);
         CHECK(str == "7.89");
      }
   }
}
