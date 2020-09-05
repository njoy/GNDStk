
#define CATCH_CONFIG_MAIN


// -----------------------------------------------------------------------------
// convert(istream,pair<int,double>)
// To override GNDStk's general one:
// template<class T>
// void convert(std::istream &is, T &value)
// -----------------------------------------------------------------------------

#include <utility>
#include <iostream>

namespace njoy {
namespace GNDStk {
   inline void convert(
      std::istream &s,
      std::pair<int,double> &p
   ) {
      s >> p.first >> p.second;
   }
}
}


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

SCENARIO("Testing GNDStk convert(istream|string,type)") {

   // ------------------------
   // convert(istream,*)
   // ------------------------

   WHEN("We call convert(istream,T) for some scalars T") {
      THEN("It works for T == int") {
         std::istringstream iss("1");
         int i;
         convert(iss,i);
         CHECK(i == 1);
      }

      THEN("It works for T == float") {
         std::istringstream iss("2.3");
         float f;
         convert(iss,f);
         CHECK(f == 2.3f);
      }

      THEN("It works for T == double") {
         std::istringstream iss("4.56");
         double d;
         convert(iss,d);
         CHECK(d == 4.56);
      }
   }

   WHEN("We call convert(istream,T) for some sequence containers T") {
      THEN("It works for T == deque") {
         std::istringstream iss("1 2 3");
         std::deque<int> deq;
         convert(iss,deq);
         // For deque, I'll just check the size
         CHECK(deq.size() == 3);
      }

      THEN("It works for T == list") {
         std::istringstream iss("1 2 3");
         std::list<int> lis;
         convert(iss,lis);
         // For list, I'll just check the size
         CHECK(lis.size() == 3);
      }

      THEN("It works for T == vector") {
         std::istringstream iss("1 2 3");
         std::vector<int> vec;
         convert(iss,vec);
         CHECK(vec.size() == 3);
         CHECK(vec[0] == 1);
         CHECK(vec[1] == 2);
         CHECK(vec[2] == 3);
      }
   }

   // ------------------------
   // convert(string,*)
   // ------------------------

   WHEN("We call convert(string,T) for pair T") {
      THEN("It ends up calling our custom convert(istream,pair)") {
         const std::string str("12 3.45");
         std::pair<int,double> p;
         convert(str,p);
         CHECK(p.first == 12);
         CHECK(p.second == 3.45);
      }
   }

   WHEN("We call convert(string,T) for string T") {
      THEN("It just does a string assignment in this case") {
         const std::string str("abcdefg");
         std::string s;
         convert(str,s);
         CHECK(s == "abcdefg");
      }
   }

   WHEN("We call convert(string,T) for bool T") {
      THEN("It expects \"true\" or \"false\", per GNDS specs") {
         const std::string tstr("true");
         const std::string fstr("false");
         bool b;
         convert(tstr,b);
         CHECK(b == true);
         convert(fstr,b);
         CHECK(b == false);
      }
   }

   WHEN("We call convert(string,T) for some integral and floating-point Ts") {
      {
         const std::string str("-123");
         int val;
         convert(str,val);
         CHECK(val == -123);
      } {
         const std::string str("-123");
         long val;
         convert(str,val);
         CHECK(val == -123);
      } {
         const std::string str("-123");
         long long val;
         convert(str,val);
         CHECK(val == -123);
      } {
         const std::string str("456");
         unsigned val;
         convert(str,val);
         CHECK(val == 456);
      } {
         const std::string str("456");
         unsigned long val;
         convert(str,val);
         CHECK(val == 456);
      } {
         const std::string str("456");
         unsigned long long val;
         convert(str,val);
         CHECK(val == 456);
      } {
         const std::string str("7.89");
         float val;
         convert(str,val);
         CHECK(val == 7.89f);
      } {
         const std::string str("7.89");
         double val;
         convert(str,val);
         CHECK(val == 7.89);
      } {
         const std::string str("7.89");
         long double val;
         convert(str,val);
         CHECK(val == 7.89L);
      }
   }
}
