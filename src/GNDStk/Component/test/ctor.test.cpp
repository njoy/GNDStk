
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;


// -----------------------------------------------------------------------------
// Sample classes that derive from Component.
//
// These illustrate the minimal functionality that Component requires of derived
// classes in order for them to be constructed at all. More than what appears
// below is needed in order to do interesting things with Component-derived
// objects, such as reading from a Node into them, or printing them to a stream.
// Such activities are tested in other test codes. Here, our intention is only
// to test Component's constructor (it has only one constructor) in the two
// situations mentioned below: a class with no fields, and a class with fields.
// We don't anticipate that people will need Component-derived classes that have
// no fields, but still illustrate such a beast, for completeness. Note that the
// keys() function should return a std::tuple<>{} in that situation.
// -----------------------------------------------------------------------------

// DerivedNothing
// A Component-derived class that has no fields of its own
class DerivedNothing : public Component<DerivedNothing>
{
   friend class Component;

   static auto keys()
   {
      return std::tuple<>{};
   }

public:

   DerivedNothing() : Component(BodyText{})
   {
      Component::finish();
   }
};


// DerivedSomething
// A Component-derived class that does have fields of its own
class DerivedSomething : public Component<DerivedSomething>
{
   friend class Component;

   static auto keys()
   {
      return
         int   {} / Meta<>("foo") |
         double{} / Meta<>("bar") ;
   }

   struct {
      int foo;
      double bar;
   } content;

public:

   DerivedSomething() :
      Component(
         BodyText{},
         content.foo,
         content.bar
      )
   {
      Component::finish();
   }
};



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Component constructor") {
   GIVEN("A Component-derived class that has no fields of its own") {
      DerivedNothing der;
   }

   GIVEN("A Component-derived class that has some fields") {
      DerivedSomething der;
   }
} // SCENARIO
