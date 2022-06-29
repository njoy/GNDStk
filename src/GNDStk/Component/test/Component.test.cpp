
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// Sample classes that derive from Component
// -----------------------------------------------------------------------------

// DerivedT
class DerivedT : public Component<DerivedT,true>
{
public:
   friend class Component<DerivedT,true>;
   static inline helpMap help = {
      { "", "class DerivedT" },
      { "foo", "Help for foo" }
   };
   static auto namespaceName() { return "hello"; }
   static auto className() { return "DerivedT"; }
   static auto GNDSName() { return "none"; }
   static auto keys() { return std::tuple<>{}; }
   DerivedT() : Component(BlockData{}) { }
};


// DerivedF
class DerivedF : public Component<DerivedF,false>
{
public:
   friend class Component<DerivedF,false>;
   static inline helpMap help = {
      { "", "class DerivedF" },
      { "bar", "Help for bar" }
   };
   static auto namespaceName() { return "world"; }
   static auto className() { return "DerivedF"; }
   static auto GNDSName() { return "none"; }
   static auto keys() { return std::tuple<>{}; }
   DerivedF() : Component(BlockData{}) { }
};


// DerivedData
// A Component-derived class with some data in it.
// Note that this class doesn't have help or namespaceName(); so we'll also use
// this class to test that Component's functionality that uses those still works
// properly, as it should in that case.
class DerivedData : public Component<DerivedData>
{
public:
   friend class Component<DerivedData>;
   static auto className() { return "DerivedData"; }
   static auto GNDSName() { return "data"; }

   static auto keys()
   {
      return
         int   {} / Meta<>("foo") |
         double{} / Meta<>("bar")
      ;
   }

   struct {
      int foo;
      double bar;
   } content;

   DerivedData() :
      Component(
         BlockData{},
         content.foo,
         content.bar
      )
   {
   }

   DerivedData(const Node &node) :
      Component(
         BlockData{},
         content.foo,
         content.bar
      )
   {
      Component::finish(node);
   }
};



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk Component") {
   // Most Component functionality is tested in the individual test files.
   // There are just a few things we'll do here.

   // Ensure that we can make const and non-const <DERIVED,true>
   // and <DERIVED,false> Component objects. This must be done through
   // the constructor of a derived class, as Component's constructor is
   // intentionally private.

   const DerivedT der1;
   const DerivedF der2;
   DerivedT der3;
   DerivedF der4;

   // Now, test the handful of constructs that are written directly in the
   // Component.hpp file (as opposed to being in separate #include'd files)

   GIVEN("A Component") {
      // derived()
      WHEN("We test derived()") {
         CHECK(&der1.derived() == &der1);
         CHECK(&der2.derived() == &der2);
         CHECK(&der3.derived() == &der3);
         CHECK(&der4.derived() == &der4);
      }

      // documentation()
      WHEN("We test documentation()") {
         CHECK(der1.documentation("") == "class DerivedT");
         CHECK(der1.documentation("foo") == "Help for foo");
         CHECK(der1.documentation("bar") == "No help information is available");
         CHECK(der2.documentation("") == "class DerivedF");
         CHECK(der2.documentation("foo") == "No help information is available");
         CHECK(der2.documentation("bar") == "Help for bar");

         // Test a derived class that doesn't have a "help" member at all;
         // the base Component class should still handle this correctly
         DerivedData der;
         CHECK(der.documentation(""   ) == "No help information is available");
         CHECK(der.documentation("foo") == "No help information is available");
         CHECK(der.documentation("bar") == "No help information is available");
      }

      // namespaceName()
      WHEN("We test namespaceName()") {
         // For these two we need the std::string() only because the functions
         // were written (above, in the class definitions) with an auto return
         // of a plain character string. Where Component needs namespaceName(),
         // it converts to std::string, so it's fine to write it that way. Here,
         // though, in this test file, it means we need the std::string().
         CHECK(der1.namespaceName() == std::string("hello"));
         CHECK(der2.namespaceName() == std::string("world"));
         DerivedData der;
         CHECK(der.namespaceName() == "");
      }

      // Component << string
      // ostream << Component
      //
      // Don't confuse the above two. Component << string reads from an XML
      // or JSON snippet into an object of the class that's derived from
      // Component. ostream << Component writes (to the ostream) the object.
      WHEN("We test (Component << string) and (ostream << Component)") {
         DerivedData der;
         color = false; // avoid cluttering the checked output below

         const std::string expected =
            "DerivedData {\n"
            "   foo : 12\n"
            "   bar : 34.56\n"
            "} // DerivedData"
            ;

         // from XML
         WHEN("We read a Component-derived object << XML text") {
            der << "<data foo=\"12\" bar=\"34.56\"></data>";

            // write & check
            THEN("The result is as expected") {
               std::ostringstream oss;
               oss << der;
               CHECK(oss.str() == expected);
            }
         }

         // from JSON
         WHEN("We read a Component-derived object << JSON text") {
            der <<
               "{"
               "   \"data\": {"
               "      \"attributes\": {"
               "         \"foo\": \"12\","
               "         \"bar\": \"34.56\""
               "      }"
               "   }"
               "}";

            // write & check
            THEN("The result is as expected") {
               std::ostringstream oss;
               oss << der;
               CHECK(oss.str() == expected);
            }
         }
      }
   }
}
