
#include "catch.hpp"
#include "GNDStk.hpp"
#include "indexnlabel.hpp"

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// TestGetter
// For the tests in this file, we're using a Component-derived class mainly to
// facilitate access to the Component::getter() functions, which are otherwise
// private. We aren't doing much of what we could do with a Component-derived
// class, because we just don't need to for these tests.
// -----------------------------------------------------------------------------

class TestGetter : public Component<TestGetter>
{
   friend class Component;

   static auto NAMESPACE() { return ""; }
   static auto CLASS() { return "TestGetter"; }
   // static auto FIELD() - not actually needed here
   static auto KEYS()
   {
      return std::tuple<>{};
   }

   using INDEX_LABEL_INDEXLABEL = std::variant<
      Index,
      Label,
      IndexLabel
   >;

public:

   // ------------------------
   // data
   // ------------------------

   // See earlier remark. We don't bother linking these with GNDS fields, via
   // Component's capabilities and the KEYS() function, because doing so isn't
   // necessary for the present tests.

   // some vectors
   std::vector<Index> vecIndex;
   std::vector<Label> vecLabel;
   std::vector<IndexLabel> vecIndexLabel;

   // a couple variant objects
   std::variant<int,double> varA, varB;

   // a vector of variants
   std::vector<INDEX_LABEL_INDEXLABEL> vecVariant;

   // ------------------------
   // constructor: default
   // ------------------------

   TestGetter() : Component{ BlockData{} }
   {
      // Component::finish(); = not needed here
   }

   // ------------------------
   // test_vector
   // ------------------------

   // Tests Component::getter(vector<non-variant>)

   // const
   void test_vector() const
   {
      // re: vecIndex
      CHECK( getter(vecIndex,1,"vecIndex").index() == 1 );
      CHECK( getter(vecIndex,1,"vecIndex").value() == "one" );
      CHECK( getter(vecIndex,2,"vecIndex").index() == 2 );
      CHECK( getter(vecIndex,2,"vecIndex").value() == "two" );
      CHECK( getter(vecIndex,3,"vecIndex").index() == 3 );
      CHECK( getter(vecIndex,3,"vecIndex").value() == "three" );
      CHECK( getter(vecIndex,4,"vecIndex").index() == 4 );
      CHECK( getter(vecIndex,4,"vecIndex").value() == "four" );

      // re: vecLabel
      CHECK( getter(vecLabel,"3.1415927","vecLabel").label() == "3.1415927" );
      CHECK( getter(vecLabel,"3.1415927","vecLabel").value() == "pi" );
      CHECK( getter(vecLabel,"2.7182818","vecLabel").label() == "2.7182818" );
      CHECK( getter(vecLabel,"2.7182818","vecLabel").value() == "e" );

      // re: vecIndexLabel, lookup by index
      CHECK( getter(vecIndexLabel,5,"vecIndexLabel").index() == 5 );
      CHECK( getter(vecIndexLabel,5,"vecIndexLabel").label() == "five" );
      CHECK( getter(vecIndexLabel,5,"vecIndexLabel").value() == "5 (five)" );
      CHECK( getter(vecIndexLabel,6,"vecIndexLabel").index() == 6 );
      CHECK( getter(vecIndexLabel,6,"vecIndexLabel").label() == "six" );
      CHECK( getter(vecIndexLabel,6,"vecIndexLabel").value() == "6 (six)" );
      CHECK( getter(vecIndexLabel,7,"vecIndexLabel").index() == 7 );
      CHECK( getter(vecIndexLabel,7,"vecIndexLabel").label() == "seven" );
      CHECK( getter(vecIndexLabel,7,"vecIndexLabel").value() == "7 (seven)" );

      // re: vecIndexLabel, lookup by label
      CHECK( getter(vecIndexLabel,"five","vecIndexLabel").index()
             == 5 );
      CHECK( getter(vecIndexLabel,"five","vecIndexLabel").label()
             == "five" );
      CHECK( getter(vecIndexLabel,"five","vecIndexLabel").value()
             == "5 (five)" );
      CHECK( getter(vecIndexLabel,"six","vecIndexLabel").index()
             == 6 );
      CHECK( getter(vecIndexLabel,"six","vecIndexLabel").label()
             == "six" );
      CHECK( getter(vecIndexLabel,"six","vecIndexLabel").value()
             == "6 (six)" );
      CHECK( getter(vecIndexLabel,"seven","vecIndexLabel").index()
             == 7 );
      CHECK( getter(vecIndexLabel,"seven","vecIndexLabel").label()
             == "seven" );
      CHECK( getter(vecIndexLabel,"seven","vecIndexLabel").value()
             == "7 (seven)" );
   }

   // non-const
   void test_vector()
   {
      // ------------------------
      // re: vecIndex
      // ------------------------

      // verify an existing value
      CHECK( getter(vecIndex,1,"vecIndex").index() == 1 );
      CHECK( getter(vecIndex,1,"vecIndex").value() == "one" );

      // change
      getter(vecIndex,1,"vecIndex") = Index{ 100, "one hundred" };

      // verify the new value
      CHECK( getter(vecIndex,100,"vecIndex").index() == 100 );
      CHECK( getter(vecIndex,100,"vecIndex").value() == "one hundred" );

      // ------------------------
      // re: vecLabel
      // ------------------------

      // verify an existing value
      CHECK( getter(vecLabel,"3.1415927","vecLabel").label() == "3.1415927" );
      CHECK( getter(vecLabel,"3.1415927","vecLabel").value() == "pi" );

      // change
      getter(vecLabel,"3.1415927","vecLabel") = Label{ "1.4142136", "sqrt(2)" };

      // verify the new value
      CHECK( getter(vecLabel,"1.4142136","vecLabel").label() == "1.4142136" );
      CHECK( getter(vecLabel,"1.4142136","vecLabel").value() == "sqrt(2)" );

      // ------------------------
      // re: vecIndexLabel, lookup by index
      // ------------------------

      // verify an existing value
      CHECK( getter(vecIndexLabel,5,"vecIndexLabel").index() == 5 );
      CHECK( getter(vecIndexLabel,5,"vecIndexLabel").label() == "five" );
      CHECK( getter(vecIndexLabel,5,"vecIndexLabel").value() == "5 (five)" );

      // change
      getter(vecIndexLabel,5,"vecIndexLabel") =
         IndexLabel{ 11, "eleven",  "11 (eleven)" };

      // verify the new value
      CHECK( getter(vecIndexLabel,11,"vecIndexLabel").index()
             == 11 );
      CHECK( getter(vecIndexLabel,11,"vecIndexLabel").label()
             == "eleven" );
      CHECK( getter(vecIndexLabel,11,"vecIndexLabel").value()
             == "11 (eleven)" );

      // ------------------------
      // re: vecIndexLabel, lookup by label
      // ------------------------

      // verify an existing value
      CHECK( getter(vecIndexLabel,"six","vecIndexLabel").index()
             == 6 );
      CHECK( getter(vecIndexLabel,"six","vecIndexLabel").label()
             == "six" );
      CHECK( getter(vecIndexLabel,"six","vecIndexLabel").value()
             == "6 (six)" );

      // change
      getter(vecIndexLabel,"six","vecIndexLabel") =
         IndexLabel{ 13, "thirteen",  "13 (thirteen)" };

      // verify new value
      CHECK( getter(vecIndexLabel,"thirteen","vecIndexLabel").index()
             == 13);
      CHECK( getter(vecIndexLabel,"thirteen","vecIndexLabel").label()
             == "thirteen" );
      CHECK( getter(vecIndexLabel,"thirteen","vecIndexLabel").value()
             == "13 (thirteen)" );
   }

   // ------------------------
   // test_variant
   // ------------------------

   // Tests Component::getter(variant)

   // const
   void test_variant() const
   {
      CHECK( *getter<int   >(varA,"varA") == 12 );
      CHECK( *getter<double>(varB,"varB") == 34.56 );
   }

   // non-const
   void test_variant()
   {
      CHECK( *getter<int   >(varA,"varA") == 12 );
      CHECK( *getter<double>(varB,"varB") == 34.56 );

      *getter<int   >(varA,"varA") = 314;
      *getter<double>(varB,"varB") = 2.72;

      CHECK( *getter<int   >(varA,"varA") == 314);
      CHECK( *getter<double>(varB,"varB") == 2.72);
   }

   // ------------------------
   // test_vector_of_variant
   // ------------------------

   // Tests Component::getter(vector<variant>)

   // const
   void test_vector_of_variant() const
   {
      // Index
      CHECK( getter<Index>(vecVariant,8,"vecVariant")->index() == 8);
      CHECK( getter<Index>(vecVariant,8,"vecVariant")->value() == "eight");

      // Label
      CHECK( getter<Label>(vecVariant,"foo","vecVariant")->label() == "foo");
      CHECK( getter<Label>(vecVariant,"foo","vecVariant")->value() == "bar");

      // IndexLabel, lookup by index
      CHECK( getter<IndexLabel>(vecVariant,10,"vecVariant")->index()
             == 10);
      CHECK( getter<IndexLabel>(vecVariant,10,"vecVariant")->label()
             == "ten");
      CHECK( getter<IndexLabel>(vecVariant,10,"vecVariant")->value()
             == "10 (ten)");

      // IndexLabel, lookup by label
      CHECK( getter<IndexLabel>(vecVariant,"ten","vecVariant")->index()
             == 10);
      CHECK( getter<IndexLabel>(vecVariant,"ten","vecVariant")->label()
             == "ten");
      CHECK( getter<IndexLabel>(vecVariant,"ten","vecVariant")->value()
             == "10 (ten)");
   }

   // non-const
   void test_vector_of_variant()
   {
      // ------------------------
      // Index
      // ------------------------

      // verify an existing value
      CHECK( getter<Index>(vecVariant,8,"vecVariant")->index() == 8);
      CHECK( getter<Index>(vecVariant,8,"vecVariant")->value() == "eight");

      // change
      *getter<Index>(vecVariant,8,"vecVariant") =
         Index{ 80, "eighty"  };

      // verify the new value
      CHECK( getter<Index>(vecVariant,80,"vecVariant")->index() == 80);
      CHECK( getter<Index>(vecVariant,80,"vecVariant")->value() == "eighty");

      // ------------------------
      // Label
      // ------------------------

      // verify an existing value
      CHECK( getter<Label>(vecVariant,"foo","vecVariant")->label() == "foo");
      CHECK( getter<Label>(vecVariant,"foo","vecVariant")->value() == "bar");

      // change
      *getter<Label>(vecVariant,"foo","vecVariant") =
         Label{ "Foo", "Bar"  };

      // verify the new value
      CHECK( getter<Label>(vecVariant,"Foo","vecVariant")->label() == "Foo");
      CHECK( getter<Label>(vecVariant,"Foo","vecVariant")->value() == "Bar");

      // ------------------------
      // IndexLabel, lookup by index
      // ------------------------

      // verify an existing value
      CHECK( getter<IndexLabel>(vecVariant,10,"vecVariant")->index()
             == 10);
      CHECK( getter<IndexLabel>(vecVariant,10,"vecVariant")->label()
             == "ten");
      CHECK( getter<IndexLabel>(vecVariant,10,"vecVariant")->value()
             == "10 (ten)");

      // change
      *getter<IndexLabel>(vecVariant,10,"vecVariant") =
         IndexLabel{ 100, "a hundred",  "10*10" };

      // verify the new value
      CHECK( getter<IndexLabel>(vecVariant,100,"vecVariant")->index()
             == 100);
      CHECK( getter<IndexLabel>(vecVariant,100,"vecVariant")->label()
             == "a hundred");
      CHECK( getter<IndexLabel>(vecVariant,100,"vecVariant")->value()
             == "10*10");

      // ------------------------
      // IndexLabel, lookup by label
      // ------------------------

      // verify an existing value
      CHECK( getter<IndexLabel>(vecVariant,"twelve","vecVariant")->index()
             == 12);
      CHECK( getter<IndexLabel>(vecVariant,"twelve","vecVariant")->label()
             == "twelve");
      CHECK( getter<IndexLabel>(vecVariant,"twelve","vecVariant")->value()
             == "12 (twelve)");

      // change
      *getter<IndexLabel>(vecVariant,"twelve","vecVariant") =
         IndexLabel{ 1000, "a thousand",  "10*10*10" };

      // verify the new value
      CHECK( getter<IndexLabel>(vecVariant,"a thousand","vecVariant")->index()
             == 1000);
      CHECK( getter<IndexLabel>(vecVariant,"a thousand","vecVariant")->label()
             == "a thousand");
      CHECK( getter<IndexLabel>(vecVariant,"a thousand","vecVariant")->value()
             == "10*10*10");
   }

}; // class TestGetter



// -----------------------------------------------------------------------------
// Scenario
// -----------------------------------------------------------------------------

SCENARIO("Component getter()") {

   GIVEN("A class with some vector, variant, and vector<variant> members") {

      TestGetter t;
      const auto &c = t;

      // ------------------------
      // Initialize
      // ------------------------

      // vector
      t.vecIndex.push_back( Index{ 1, "one"   } );
      t.vecIndex.push_back( Index{ 2, "two"   } );
      t.vecIndex.push_back( Index{ 3, "three" } );
      t.vecIndex.push_back( Index{ 4, "four"  } );

      t.vecLabel.push_back( Label{ "3.1415927", "pi" } );
      t.vecLabel.push_back( Label{ "2.7182818", "e"  } );

      t.vecIndexLabel.push_back( IndexLabel{ 5, "five",  "5 (five)" } );
      t.vecIndexLabel.push_back( IndexLabel{ 6, "six",   "6 (six)"  } );
      t.vecIndexLabel.push_back( IndexLabel{ 7, "seven", "7 (seven)"} );

      // variant
      t.varA = 12;
      t.varB = 34.56;

      // vector<variant>
      t.vecVariant.push_back( Index{ 8, "eight" } );
      t.vecVariant.push_back( Label{ "foo", "bar" } );
      t.vecVariant.push_back( IndexLabel{ 10, "ten",  "10 (ten)" } );
      t.vecVariant.push_back( IndexLabel{ 12, "twelve",  "12 (twelve)" } );

      // ------------------------
      // Run various tests
      // ------------------------

      WHEN("We test Component::getter() for vector") {
         THEN("It works on a const object") {
            c.test_vector();
         }
         THEN("It works on a non-const object") {
            t.test_vector();
         }
      } // WHEN

      WHEN("We test Component::getter() for variant") {
         THEN("It works on a const object") {
            c.test_variant();
         }
         THEN("It works on a non-const object") {
            t.test_variant();
         }
      } // WHEN

      WHEN("We test Component::getter() for vector<variant>") {
         THEN("It works on a const object") {
            c.test_vector_of_variant();
         }
         THEN("It works on a non-const object") {
            t.test_vector_of_variant();
         }
      } // WHEN

   } // GIVEN

} // SCENARIO
