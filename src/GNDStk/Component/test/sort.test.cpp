
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

// In this file, we'll also test the detail:: functions on which Component's
// sort() function is based. Those tests could have gone into detail.test.cpp,
// but that file was excessively long already, and the tests seems like they
// really belong here anyway.



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing Component detail:: sort() and related functions") {

   /*
A or B
neither, index, label, both
optional or not
for optional: has value or not

A has...
   1.  neither index nor label
   2.  index plain
   3a. index optional w/value
   3b. index optional null
   4.  label plain
   5a. label optional w/value
   5b. label optional null
   6.  index plain             , label plain
   7a. index plain             , label optional w/value
   7b. index plain             , label optional null
   8a. index optional w/value  , label plain
   8b. index optional null     , label plain
   9a. index optional w/value  , label optional w/value
   9b. index optional w/value  , label optional null
   9c. index optional null     , label optional w/value
   9d. index optional null     , label optional null

[i|l][none|have|opty|optn]

This is going to be a bear to test all this.
Combinatorics is our enemy here.

// IndexLabel
struct IndexLabel {
   struct {
      int index;
      std::string label;
   } content;
   std::string value;

   const std::size_t &index() const { return content.index; };
   std::size_t &index() { return content.index; };
   const std::string &label() const { return content.label; };
   std::string &label() { return content.label; };

   IndexLabel(
      const int index = 0,
      const std::string &label = "",
      const std::string &value = ""
   ) :
      value(value)
   {
      this->index() = index;
      this->label() = label;
   }
};
   */

   GIVEN("Testing compareRegular()") {
   } // GIVEN

   GIVEN("Testing compareVariant()") {
   } // GIVEN

   GIVEN("Testing sort(general T)() (does nothing)") {
   } // GIVEN

   GIVEN("Testing sort(vector<general T>)()") {
   } // GIVEN

   GIVEN("Testing sort(vector<variant>)()") {
   } // GIVEN

}



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Component sort()") {
} // SCENARIO
