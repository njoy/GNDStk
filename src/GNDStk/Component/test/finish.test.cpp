
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// DerivedValue
// Has body text
// -----------------------------------------------------------------------------

namespace test {

class DerivedValue : public Component<DerivedValue,true>
{
   friend class Component;

   // names
   static auto namespaceName() { return "test"; }
   static auto className() { return "DerivedValue"; }
   static auto GNDSName() { return "value"; }

   // keys
   static auto keys()
   {
      return
         int{} / Meta<>("length") |
         int{} / Meta<>("start") |
         std::string{} / Meta<>("valueType")
      ;
   }

   // content
   struct {
      int length;
      int start;
      std::string valueType;
   } content;

public:

   using Component::construct;

   // ctor: default
   DerivedValue() :
      Component(
         BodyText{},
         content.length, content.start, content.valueType
      )
   {
      // finish()
      Component::finish();
   }

   // ctor: copy
   DerivedValue(const DerivedValue &other) :
      Component{
         other,
         content.length, content.start, content.valueType
      },
      content{other.content}
   {
      // finish(derived)
      Component::finish(other);
   }

   // ctor: node
   DerivedValue(const Node &node) :
      Component{
         BodyText{},
         content.length, content.start, content.valueType
      }
   {
      // finish(derived)
      Component::finish(node);
   }

   // ctor: vector
   DerivedValue(const std::vector<double> &vec) :
      Component{
         BodyText{},
         content.length, content.start, content.valueType
      }
   {
      // finish(vector)
      Component::finish(vec);
   }
};

} // namespace test



// -----------------------------------------------------------------------------
// DerivedPlain
// Does not have body text
// -----------------------------------------------------------------------------

namespace test {

class DerivedPlain : public Component<DerivedPlain,false>
{
   friend class Component;

   // names
   static auto namespaceName() { return "test"; }
   static auto className() { return "DerivedPlain"; }
   static auto GNDSName() { return "plain"; }

   // keys
   static auto keys()
   {
      return
         int   {} / Meta<>("foo") |
         double{} / Meta<>("bar")
      ;
   }

   // content
   struct {
      int foo;
      double bar;
   } content;

public:

   using Component::construct;

   // ctor: default
   DerivedPlain() :
      Component(
         BodyText{},
         content.foo, content.bar
      )
   {
      // finish()
      Component::finish();
   }

   // ctor: copy
   DerivedPlain(const DerivedPlain &other) :
      Component{
         other,
         content.foo, content.bar
      },
      content{other.content}
   {
      // finish(derived)
      Component::finish(other);
   }

   // ctor: node
   DerivedPlain(const Node &node) :
      Component{
         BodyText{},
         content.foo, content.bar
      }
   {
      // finish(derived)
      Component::finish(node);
   }

};

} // namespace test



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

// The main point of the tests here is to ensure that each of Component's
// finish() functions calls the other functions that it's supposed to call.
// Detailed tests of those other functions aren't done *here*.

SCENARIO("Component finish()") {
   GIVEN("A component-derived class that has body text") {
      test::DerivedValue d;
   } // GIVEN

   GIVEN("A component-derived class that does not have body text") {
      test::DerivedPlain d;
   } // GIVEN
} // SCENARIO
