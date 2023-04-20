
#include "catch.hpp"
#include "GNDStk.hpp"
#include "prototype.hpp"

using namespace njoy::GNDStk;
using detail::getter;



// -----------------------------------------------------------------------------
// Classes for testing the hasPrint*() functions
// -----------------------------------------------------------------------------

struct Neither {
   // has neither of the print()s seen in the upcoming classes
};

struct One {
   // (ostream) only
   std::ostream &print(std::ostream &os) const
   {
      return os;
   }
};

struct Two {
   // (ostream,int) only
   std::ostream &print(std::ostream &os, const int) const
   {
      return os;
   }
};

struct Both {
   // (ostream)
   std::ostream &print(std::ostream &os) const
   {
      return os;
   }
   // (ostream,int)
   std::ostream &print(std::ostream &os, const int) const
   {
      return os;
   }
};



// -----------------------------------------------------------------------------
// Classes for testing hasIndex and hasLabel,
// and for use in the getter() tests
// -----------------------------------------------------------------------------

#include "indexnlabel.hpp"

// FooBar
struct FooBar {
   struct {
      int foo;
      double bar;
   } Content;

   const int &foo() const { return Content.foo; }
   int &foo() { return Content.foo; }
   const double &bar() const { return Content.bar; }
   double &bar() { return Content.bar; }
};



// -----------------------------------------------------------------------------
// class Derived
// Is derived from Component
// Used in the tests of printComponentPart()
// -----------------------------------------------------------------------------

class Derived : public Component<Derived> {
public:
   friend class Component<Derived>;

   static auto NAMESPACE() { return ""; }
   static auto CLASS() { return "Derived"; }
   static auto NODENAME() { return "none"; }

   static auto KEYS()
   {
      return
         // metadata
         int{}    / Meta<>("foo") |
         double{} / Meta<>("bar")
      ;
   }

   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "foo",
         "bar"
      };
      return names;
   }

   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "foo",
         "bar"
      };
      return names;
   }

   int foo = 56;
   double bar = 7.8;

   Derived() : Component(BlockData{},foo,bar) { }
};



// -----------------------------------------------------------------------------
// class NonDerived
// Is not derived from Component
// -----------------------------------------------------------------------------

class NonDerived {
public:
   int foo = 12;
   double bar = 3.4;
};

// Needs << in order to participate in printComponentPart() - which it does,
// because we're using it as a test subject there.

inline std::ostream &operator<<(std::ostream &s, const NonDerived &obj)
{
   return s << '{' << obj.foo << ',' << obj.bar << '}';
}



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing Component detail:: miscellaneous functions") {

   // getName
   GIVEN("Function: getName()") {
      WHEN("Called with a Meta object") {
         THEN("It extracts the name properly") {
            Meta<> m("foo");
            CHECK(detail::getName(m) == "foo");
         }
      }
      WHEN("Called with a Child object") {
         THEN("It extracts the name properly") {
            Child<> c("bar");
            CHECK(detail::getName(c) == "bar");
         }
      }
      WHEN("Called with a pair<Child,string>") {
         THEN("It extracts the name properly") {
            std::pair<Child<>,std::string> p(Child<>("one"),"abc");
            CHECK(detail::getName(p) == "one");
         }
      }
      WHEN("Called with a pair<Child,regex>") {
         THEN("It extracts the name properly") {
            std::pair<Child<>,std::regex> p(Child<>("two"),"def");
            CHECK(detail::getName(p) == "two");
         }
      }
   } // GIVEN

   // colorize
   GIVEN("Function: colorize()") {
      WHEN("Called with GNDStk::colors == true and color == \"\"") {
         THEN("It returns the expected result") {
            njoy::GNDStk::colors = true;
            // coloring is on, but we don't provide a color,
            // and the default label color is set to ""
            color::label = "";
            CHECK(detail::colorize("one","") == "one");
         }
      }

      WHEN("Called with GNDStk::colors == true and color != \"\"") {
         THEN("It returns the expected result") {
            njoy::GNDStk::colors = true;
            // coloring is on, and we provide a color
            CHECK(detail::colorize("two","[color]") == "[color]two\033[0m");
         }
      }

      WHEN("Called with GNDStk::colors == false and color == \"\"") {
         THEN("It returns the expected result") {
            njoy::GNDStk::colors = false;
            // coloring is off, and we don't provide a color anyway
            CHECK(detail::colorize("three","") == "three");
         }
      }

      WHEN("Called with GNDStk::colors == false and color != \"\"") {
         THEN("It returns the expected result") {
            njoy::GNDStk::colors = false;
            // coloring is off, and we provide a color (but it isn't used,
            // because coloring is off)
            CHECK(detail::colorize("four","[color]") == "four");
         }
      }
   } // GIVEN

   // fullName
   GIVEN("Function: fullName()") {
      // with namespace
      WHEN("A namespace is given") {
         THEN("It returns the expected result") {
            CHECK(detail::fullName("someNamespace","SomeClass") ==
                  "someNamespace::SomeClass");
         }
      }

      // without namespace
      WHEN("No namespace is given") {
         THEN("It returns the expected result") {
            CHECK(detail::fullName("","SomeClass") == "SomeClass");
            CHECK(detail::fullName("","SomeClass") != "::SomeClass");
         }
      }
   } // GIVEN

   GIVEN("Function: indentString()") {
      // Quickly check a few variations
      std::ostringstream oss;
      int level;
      using detail::indentString;

      indent = 0; level = 0; oss.str(""); indentString(oss,level,"foo");
      CHECK(oss.str() == "foo");
      indent = 0; level = 1; oss.str(""); indentString(oss,level,"foo");
      CHECK(oss.str() == "foo");
      indent = 0; level = 2; oss.str(""); indentString(oss,level,"foo");
      CHECK(oss.str() == "foo");
      indent = 2; level = 0; oss.str(""); indentString(oss,level,"foo");
      CHECK(oss.str() == "foo");
      indent = 2; level = 1; oss.str(""); indentString(oss,level,"foo");
      CHECK(oss.str() == "  foo");
      indent = 2; level = 2; oss.str(""); indentString(oss,level,"foo");
      CHECK(oss.str() == "    foo");
      indent = 3; level = 0; oss.str(""); indentString(oss,level,"foo");
      CHECK(oss.str() == "foo");
      indent = 3; level = 1; oss.str(""); indentString(oss,level,"foo");
      CHECK(oss.str() == "   foo");
      indent = 3; level = 2; oss.str(""); indentString(oss,level,"foo");
      CHECK(oss.str() == "      foo");
   } // GIVEN

   // hasPrint*
   // Test some SFINAE constructs
   GIVEN("Functions: hasPrintOneArg(), hasPrintTwoArg()") {
      CHECK(detail::hasPrintOneArg<Neither> == false);
      CHECK(detail::hasPrintTwoArg<Neither> == false);

      CHECK(detail::hasPrintOneArg<One> == true);
      CHECK(detail::hasPrintTwoArg<One> == false);

      CHECK(detail::hasPrintOneArg<Two> == false);
      CHECK(detail::hasPrintTwoArg<Two> == true);

      CHECK(detail::hasPrintOneArg<Both> == true);
      CHECK(detail::hasPrintTwoArg<Both> == true);
   } // GIVEN
}



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

// Cases:
//    ostream, level, string,    label, maxlen, color = ""
//    ostream, level, T,         label, maxlen, color = ""
//    ostream, level, optional,  label, maxlen
//    ostream, level, Defaulted, label, maxlen
//    ostream, level, variant,   label, maxlen
//    ostream, level, vector,    label, maxlen, color = ""
// All return bool.

SCENARIO("Testing Component detail:: printComponentPart()") {
   // for clarity below
   int level;
   size_t maxlen;
   std::ostringstream oss;
   indent = 2;
   using detail::printComponentPart;

   // For string
   GIVEN("printComponentPart() for string") {
      oss.str("");
      printComponentPart(oss, level=2, maxlen= 0, "label", "foo\nbar");
      CHECK(oss.str() ==
            "    label : foo\n"
            "    bar");

      oss.str("");
      printComponentPart(oss, level=2, maxlen=10, "label", "foo\nbar");
      CHECK(oss.str() ==
            "    label      : foo\n"
            "    bar");

      oss.str("");
      printComponentPart(oss, level=2, maxlen= 0, "", "foo\nbar");
      CHECK(oss.str() ==
            "    foo\n"
            "    bar");

      oss.str("");
      printComponentPart(oss, level=2, maxlen=10, "", "foo\nbar");
      CHECK(oss.str() ==
            "    foo\n"
            "    bar");
   } // GIVEN

   // For general types T
   GIVEN("printComponentPart() for T") {

      // For double
      WHEN("T is double") {
         double value = 1.234;

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "label", value);
         CHECK(oss.str() == "    label : 1.234");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "label", value);
         CHECK(oss.str() == "    label      : 1.234");

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "", value);
         CHECK(oss.str() == "    1.234");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "", value);
         CHECK(oss.str() == "    1.234");
      }

      // printComponentPart() for general T has an if-constexpr that
      // distinguished classes that *are* derived from Component from
      // those that aren't, so we'll test both cases. (double, above,
      // in fact falls into the latter category.) ...

      // For "Derived"
      WHEN("T is a class that derives from Component") {
         Derived value;

         // label and maxlen don't get used in this case.
         // The Component-derived nature of the class causes
         // value.print(stream,level) to be called instead.
         // So we get the same result from each call.
         const std::string expected1 =
            "    label {\n"
            "      foo : 56\n"
            "      bar : 7.8\n"
            "    } // label";
         const std::string expected2 =
            "    {\n"
            "      foo : 56\n"
            "      bar : 7.8\n"
            "    }";

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "label", value);
         CHECK(oss.str() == expected1);

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "label", value);
         CHECK(oss.str() == expected1);

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "", value);
         CHECK(oss.str() == expected2);

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "", value);
         CHECK(oss.str() == expected2);
      }

      // For "NonDerived"
      WHEN("T is a class that does not derive from Component") {
         NonDerived value;

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "label", value);
         CHECK(oss.str() == "    label : {12,3.4}");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "label", value);
         CHECK(oss.str() == "    label      : {12,3.4}");

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "", value);
         CHECK(oss.str() == "    {12,3.4}");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "", value);
         CHECK(oss.str() == "    {12,3.4}");
      }
   } // GIVEN

   // For optional
   GIVEN("printComponentPart() for optional") {
      WHEN("The optional has a value") {
         std::optional<double> opt = 1.234;

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "label", opt);
         CHECK(oss.str() == "    label : 1.234");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "label", opt);
         CHECK(oss.str() == "    label      : 1.234");

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "", opt);
         CHECK(oss.str() == "    1.234");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "", opt);
         CHECK(oss.str() == "    1.234");
      }

      WHEN("The optional does not have a value, and comments == false") {
         std::optional<double> opt;
         CHECK(opt.has_value() == false);
         comments = false;

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "label", opt);
         CHECK(oss.str() == "");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "label", opt);
         CHECK(oss.str() == "");

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "", opt);
         CHECK(oss.str() == "");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "", opt);
         CHECK(oss.str() == "");
      }

      WHEN("The optional does not have a value, and comments == true") {
         std::optional<double> opt;
         CHECK(opt.has_value() == false);
         comments = true;

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "label", opt);
         CHECK(oss.str() == "");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "label", opt);
         CHECK(oss.str() == "");

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "", opt);
         CHECK(oss.str() == "");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "", opt);
         CHECK(oss.str() == "");
      }
   } // GIVEN

   // For Defaulted
   GIVEN("printComponentPart() for Defaulted") {
      WHEN("The Defaulted has an explicitly provided value") {
         // For the following:
         //    5.6 is the default
         //    7.8 is an explicitly provided value
         Defaulted<double> def(5.6,7.8);

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "label", def);
         CHECK(oss.str() == "    label : 7.8 // its default");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "label", def);
         CHECK(oss.str() == "    label      : 7.8 // its default");

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "", def);
         CHECK(oss.str() == "    7.8 // its default");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "", def);
         CHECK(oss.str() == "    7.8 // its default");
      }

      WHEN("The Defaulted has its default, and comments == false") {
         Defaulted<double> def(3.14);
         CHECK(def.has_value() == false);
         comments = false;

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "label", def);
         CHECK(oss.str() == "    label : 3.14");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "label", def);
         CHECK(oss.str() == "    label      : 3.14");

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "", def);
         CHECK(oss.str() == "    3.14");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "", def);
         CHECK(oss.str() == "    3.14");
      }

      WHEN("The Defaulted has its default, and comments == true") {
         Defaulted<double> def(2.72);
         CHECK(def.has_value() == false);
         comments = true;

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "label", def);
         CHECK(oss.str() ==
               "    label : 2.72 // its default");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "label", def);
         CHECK(oss.str() ==
               "    label      : 2.72 // its default");

         oss.str("");
         printComponentPart(oss, level=2, maxlen= 0, "", def);
         CHECK(oss.str() == "    2.72 // its default");

         oss.str("");
         printComponentPart(oss, level=2, maxlen=10, "", def);
         CHECK(oss.str() == "    2.72 // its default");
      }
   } // GIVEN

   // For variant
   GIVEN("printComponentPart() for variant") {
      oss.str("");
      std::variant<int,double> var(9.87);

      oss.str("");
      printComponentPart(oss, level=2, maxlen= 0, "label", var);
      CHECK(oss.str() == "    label : 9.87");

      oss.str("");
      printComponentPart(oss, level=2, maxlen=10, "label", var);
      CHECK(oss.str() == "    label      : 9.87");

      oss.str("");
      printComponentPart(oss, level=2, maxlen= 0, "", var);
      CHECK(oss.str() == "    9.87");

      oss.str("");
      printComponentPart(oss, level=2, maxlen=10, "", var);
      CHECK(oss.str() == "    9.87");
   } // GIVEN

   // For vector
   GIVEN("printComponentPart() for vector") {
      oss.str("");
      const std::vector<std::string> vec{{"a","b","c","d","e"}};
      comments = false;

      const std::string expected =
         "    label [\n"
         "      a\n"
         "      b\n"
         "      c\n"
         "      d\n"
         "      e\n"
         "    ]";

      oss.str("");
      printComponentPart(oss, level=2, maxlen= 0, "label", vec);
      CHECK(oss.str() == expected);

      oss.str("");
      printComponentPart(oss, level=2, maxlen=10, "label", vec);
      CHECK(oss.str() == expected);
   } // GIVEN
}



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing Component detail:: classes for SFINAE") {

   // hasIndex
   CHECK((detail::hasIndex<Empty     > == false));
   CHECK((detail::hasIndex<FooBar    > == false));
   CHECK((detail::hasIndex<Index     > == true));
   CHECK((detail::hasIndex<Label     > == false));
   CHECK((detail::hasIndex<IndexLabel> == true));

   CHECK((detail::hasIndex<std::variant<Empty     ,Empty     >> == false));
   CHECK((detail::hasIndex<std::variant<Empty     ,FooBar    >> == false));
   CHECK((detail::hasIndex<std::variant<Empty     ,Index     >> == true));
   CHECK((detail::hasIndex<std::variant<Empty     ,Label     >> == false));
   CHECK((detail::hasIndex<std::variant<Empty     ,IndexLabel>> == true));
   CHECK((detail::hasIndex<std::variant<FooBar    ,Empty     >> == false));
   CHECK((detail::hasIndex<std::variant<FooBar    ,FooBar    >> == false));
   CHECK((detail::hasIndex<std::variant<FooBar    ,Index     >> == true));
   CHECK((detail::hasIndex<std::variant<FooBar    ,Label     >> == false));
   CHECK((detail::hasIndex<std::variant<FooBar    ,IndexLabel>> == true));
   CHECK((detail::hasIndex<std::variant<Index     ,Empty     >> == true));
   CHECK((detail::hasIndex<std::variant<Index     ,FooBar    >> == true));
   CHECK((detail::hasIndex<std::variant<Index     ,Index     >> == true));
   CHECK((detail::hasIndex<std::variant<Index     ,Label     >> == true));
   CHECK((detail::hasIndex<std::variant<Index     ,IndexLabel>> == true));
   CHECK((detail::hasIndex<std::variant<Label     ,Empty     >> == false));
   CHECK((detail::hasIndex<std::variant<Label     ,FooBar    >> == false));
   CHECK((detail::hasIndex<std::variant<Label     ,Index     >> == true));
   CHECK((detail::hasIndex<std::variant<Label     ,Label     >> == false));
   CHECK((detail::hasIndex<std::variant<Label     ,IndexLabel>> == true));
   CHECK((detail::hasIndex<std::variant<IndexLabel,Empty     >> == true));
   CHECK((detail::hasIndex<std::variant<IndexLabel,FooBar    >> == true));
   CHECK((detail::hasIndex<std::variant<IndexLabel,Index     >> == true));
   CHECK((detail::hasIndex<std::variant<IndexLabel,Label     >> == true));
   CHECK((detail::hasIndex<std::variant<IndexLabel,IndexLabel>> == true));

   // hasLabel
   CHECK((detail::hasLabel<Empty     > == false));
   CHECK((detail::hasLabel<FooBar    > == false));
   CHECK((detail::hasLabel<Index     > == false));
   CHECK((detail::hasLabel<Label     > == true));
   CHECK((detail::hasLabel<IndexLabel> == true));

   CHECK((detail::hasLabel<std::variant<Empty     ,Empty     >> == false));
   CHECK((detail::hasLabel<std::variant<Empty     ,FooBar    >> == false));
   CHECK((detail::hasLabel<std::variant<Empty     ,Index     >> == false));
   CHECK((detail::hasLabel<std::variant<Empty     ,Label     >> == true));
   CHECK((detail::hasLabel<std::variant<Empty     ,IndexLabel>> == true));
   CHECK((detail::hasLabel<std::variant<FooBar    ,Empty     >> == false));
   CHECK((detail::hasLabel<std::variant<FooBar    ,FooBar    >> == false));
   CHECK((detail::hasLabel<std::variant<FooBar    ,Index     >> == false));
   CHECK((detail::hasLabel<std::variant<FooBar    ,Label     >> == true));
   CHECK((detail::hasLabel<std::variant<FooBar    ,IndexLabel>> == true));
   CHECK((detail::hasLabel<std::variant<Index     ,Empty     >> == false));
   CHECK((detail::hasLabel<std::variant<Index     ,FooBar    >> == false));
   CHECK((detail::hasLabel<std::variant<Index     ,Index     >> == false));
   CHECK((detail::hasLabel<std::variant<Index     ,Label     >> == true));
   CHECK((detail::hasLabel<std::variant<Index     ,IndexLabel>> == true));
   CHECK((detail::hasLabel<std::variant<Label     ,Empty     >> == true));
   CHECK((detail::hasLabel<std::variant<Label     ,FooBar    >> == true));
   CHECK((detail::hasLabel<std::variant<Label     ,Index     >> == true));
   CHECK((detail::hasLabel<std::variant<Label     ,Label     >> == true));
   CHECK((detail::hasLabel<std::variant<Label     ,IndexLabel>> == true));
   CHECK((detail::hasLabel<std::variant<IndexLabel,Empty     >> == true));
   CHECK((detail::hasLabel<std::variant<IndexLabel,FooBar    >> == true));
   CHECK((detail::hasLabel<std::variant<IndexLabel,Index     >> == true));
   CHECK((detail::hasLabel<std::variant<IndexLabel,Label     >> == true));
   CHECK((detail::hasLabel<std::variant<IndexLabel,IndexLabel>> == true));
}



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Testing Component detail:: getter() functions") {
   std::vector<IndexLabel> vec = {
      { 0, "a", "0a" },
      { 4, "e", "4e" },
      { 1, "b", "1b" },
      { 2, "c", "2c" },
      { 3, "d", "3d" }
   };

   using GNDStk::proto::index;
   using GNDStk::proto::label;

   // ------------------------
   // vector
   // ------------------------

   GIVEN("A vector of objects that have both index and label") {
      // look for specific index
      THEN("getter() based on index works properly") {
         CHECK((getter(vec, index(0), "name", "class", "field").value() == "0a"));
         CHECK((getter(vec, index(1), "name", "class", "field").value() == "1b"));
         CHECK((getter(vec, index(2), "name", "class", "field").value() == "2c"));
         CHECK((getter(vec, index(3), "name", "class", "field").value() == "3d"));
         CHECK((getter(vec, index(4), "name", "class", "field").value() == "4e"));
         try {
            getter(vec, index(100), "name", "class", "field");
            // the above should throw, so we shouldn't get here...
            CHECK(false);
         } catch (...) {
         }
      }

      // look for specific label
      THEN("getter() based on label works properly") {
         CHECK((getter(vec, label("a"), "name", "class", "field").value() == "0a"));
         CHECK((getter(vec, label("b"), "name", "class", "field").value() == "1b"));
         CHECK((getter(vec, label("c"), "name", "class", "field").value() == "2c"));
         CHECK((getter(vec, label("d"), "name", "class", "field").value() == "3d"));
         CHECK((getter(vec, label("e"), "name", "class", "field").value() == "4e"));
         try {
            getter(vec, label("z"), "name", "class", "field");
            // the above should throw, so we shouldn't get here...
            CHECK(false);
         } catch (...) {
         }
      }
   } // GIVEN

   // ------------------------
   // optional vector,
   // with value
   // ------------------------

   GIVEN("An optional (with value) vector of objects with index and label") {
      std::optional<std::vector<IndexLabel>> opt = vec;

      // look for specific index
      THEN("getter() based on index works properly") {
         CHECK((getter(opt, index(0UL), "name", "class", "field").value() == "0a"));
         CHECK((getter(opt, index(1UL), "name", "class", "field").value() == "1b"));
         CHECK((getter(opt, index(2UL), "name", "class", "field").value() == "2c"));
         CHECK((getter(opt, index(3UL), "name", "class", "field").value() == "3d"));
         CHECK((getter(opt, index(4UL), "name", "class", "field").value() == "4e"));
         try {
            getter(opt, index(100UL), "name", "class", "field");
            // the above should throw, so we shouldn't get here...
            CHECK(false);
         } catch (...) {
         }
      }

      // look for specific label
      THEN("getter() based on label works properly") {
         CHECK((getter(opt, label("a"), "name", "class", "field").value() == "0a"));
         CHECK((getter(opt, label("b"), "name", "class", "field").value() == "1b"));
         CHECK((getter(opt, label("c"), "name", "class", "field").value() == "2c"));
         CHECK((getter(opt, label("d"), "name", "class", "field").value() == "3d"));
         CHECK((getter(opt, label("e"), "name", "class", "field").value() == "4e"));
         try {
            getter(opt, label("z"), "name", "class", "field");
            // the above should throw, so we shouldn't get here...
            CHECK(false);
         } catch (...) {
         }
      }
   } // GIVEN

   // ------------------------
   // optional vector,
   // without value
   // ------------------------

   GIVEN("An optional (without value) vector of objects with index and label") {
      std::optional<std::vector<IndexLabel>> opt;

      // look for specific index
      THEN("getter() based on index works properly") {
         try {
            getter(opt, index(0), "name", "class", "field");
            // the above should throw, so we shouldn't get here...
            CHECK(false);
         } catch (...) {
         }
      }

      // look for specific label
      THEN("getter() based on label works properly") {
         try {
            getter(opt, label("a"), "name", "class", "field");
            // the above should throw, so we shouldn't get here...
            CHECK(false);
         } catch (...) {
         }
      }
   } // GIVEN

   // ------------------------
   // variant
   // ------------------------

   GIVEN("A variant of objects that may or may not have index and/or label") {
      std::variant<Index,Label,IndexLabel> var;

      // Note that these don't involve index or label fields

      var = Index(0,"zero");
      CHECK((getter<Index>(var,"name","class","field")->value() == "zero"));

      var = Label("hello","world");
      CHECK((getter<Label>(var,"name","class","field")->value() == "world"));

      var = IndexLabel(10,"ten","TEN");
      CHECK((getter<IndexLabel>(var,"name","class","field")->value() == "TEN"));
   } // GIVEN

   // ------------------------
   // vector<variant>
   // ------------------------

   GIVEN("A vector<variant>; elements may or may not have index and/or label") {
      std::vector<std::variant<Empty,FooBar,Index,Label,IndexLabel>> vec = {{
         Empty{},
         FooBar{},
         Index{0,"zero"},
         Label{"hello","world"},
         FooBar{},
         IndexLabel{10,"ten","TEN"},
         Empty{},
         IndexLabel{11,"eleven","ELEVEN"},
         Label{"2","two"},
         Index{1,"one"},
         Empty{},
      }};

      CHECK((getter<Index     >(vec,index(0),      "name","class","field")
             ->value() == "zero"));
      CHECK((getter<Label     >(vec,label("hello"),"name","class","field")
             ->value() == "world"));
      CHECK((getter<IndexLabel>(vec,index(10),     "name","class","field")
             ->value() == "TEN"));
      CHECK((getter<IndexLabel>(vec,index(11),     "name","class","field")
             ->value() == "ELEVEN"));
      CHECK((getter<Label     >(vec,label("2"),    "name","class","field")
             ->value() == "two"));
      CHECK((getter<Index     >(vec,index(1),      "name","class","field")
             ->value() == "one"));
   } // GIVEN
}
