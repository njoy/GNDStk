
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// DerivedValue
// Has body text
// -----------------------------------------------------------------------------

namespace test {

// Helper
struct IndexStruct {
   struct {
      std::size_t index;
   } content;
   IndexStruct(const std::size_t i = 0) { content.index = i; }
   IndexStruct(const Node &) : IndexStruct(0) { }
};

inline bool operator==(const IndexStruct &one, const IndexStruct &two)
{
   return one.content.index == two.content.index;
}


// Some flags we'll use in order to ensure that certain construct()
// functions are being called, as we expect them to be.
inline bool construct1DerivedValue = false;
inline bool construct2DerivedValue = false;
inline bool construct3DerivedValue = false;
inline bool construct4DerivedValue = false;


// DerivedValue
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
         std::string{} / Meta<>("valueType") |
         std::optional<IndexStruct>{} / ++Child<>("indices")
      ;
   }

public:

   // content
   // Typically doesn't need to be public, but we make it public here because
   // one of the tests involves checking these
   struct {
      // Initialize these to specific values, so that we can ensure that
      // Component's finish() functions properly call body::pullFromDerived()
      int length = 11;
      int start = 3;
      std::string valueType = "foobar";

      // A vector of something that contains index, to ensure that the finish()
      // functions detect and sort it.
      std::optional<std::vector<IndexStruct>> indices =
         {{3,2,17,7,5,9,13,11}};
   } content;

private:

   // construct functions
   void construct()
   {
      construct1DerivedValue = true;
   }

   void construct(const DerivedValue &)
   {
      construct2DerivedValue = true;
   }

   void construct(const Node &)
   {
      construct3DerivedValue = true;
   }

   template<class T>
   void construct(const std::vector<T> &)
   {
      construct4DerivedValue = true;
   }

public:

   using Component::construct;

   // ctor: default
   DerivedValue() :
      Component(
         BodyText{},
         content.length, content.start, content.valueType, content.indices
      )
   {
      // finish()
      Component::finish();
   }

   // ctor: copy
   DerivedValue(const DerivedValue &other) :
      Component{
         other,
         content.length, content.start, content.valueType, content.indices
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
         content.length, content.start, content.valueType, content.indices
      }
   {
      // finish(node)
      Component::finish(node);
   }

   // ctor: vector
   DerivedValue(const std::vector<double> &vec) :
      Component{
         BodyText{},
         content.length, content.start, content.valueType, content.indices
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

// Helper
struct LabelStruct {
   struct {
      std::string label;
   } content;
   // apparently need a char* ctor for initializer-list initialization to work
   LabelStruct(const char *const str = "") { content.label = str; }
   LabelStruct(const Node &node)
   {
      content.label = node(std::string{}/Meta<>("label"));
   }
};

inline bool operator==(const LabelStruct &one, const LabelStruct &two)
{
   return one.content.label == two.content.label;
}


// Flags
inline bool construct1DerivedPlain = false;
inline bool construct2DerivedPlain = false;
inline bool construct3DerivedPlain = false;


// DerivedPlain
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
         double{} / Meta<>("bar") |
         std::optional<LabelStruct>{} / ++Child<>("labels")
      ;
   }

public:

   // content
   struct {
      int foo;
      double bar;

      // A vector of something that contains label, to ensure that the finish()
      // functions detect and sort it.
      std::optional<std::vector<LabelStruct>> labels =
         {{"bc","a","p","efg","d","hi","no","jklm"}};
   } content;

private:

   // construct functions
   void construct()
   {
      construct1DerivedPlain = true;
   }

   void construct(const DerivedPlain &)
   {
      construct2DerivedPlain = true;
   }

   void construct(const Node &)
   {
      construct3DerivedPlain = true;
   }

public:

   using Component::construct;

   // ctor: default
   DerivedPlain() :
      Component(
         BodyText{},
         content.foo, content.bar, content.labels
      )
   {
      // finish()
      Component::finish();
   }

   // ctor: copy
   DerivedPlain(const DerivedPlain &other) :
      Component{
         other,
         content.foo, content.bar, content.labels
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
         content.foo, content.bar, content.labels
      }
   {
      // finish(node)
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
      const std::vector<test::IndexStruct> sorted =
         {{2,3,5,7,9,11,13,17}};

      // ctor: default
      WHEN("We call the default constructor") {
         CHECK(test::construct1DerivedValue == false);
         test::DerivedValue d;
         // Ensure that finish() called the construct() in the derived class...
         CHECK(test::construct1DerivedValue == true);

         // Ensure that finish() did a BodyText::pullFromDerived()
         CHECK(d.length() == 11);
         CHECK(d.start() == 3);
         CHECK(d.valueType() == "foobar");

         // Ensure that finish() did a sort()
         CHECK(d.content.indices.has_value() == true);
         CHECK(d.content.indices->size() == 8);
         CHECK(*d.content.indices == sorted);
      }

      // ctor: copy
      WHEN("We call the copy constructor") {
         CHECK(test::construct2DerivedValue == false);
         // Writing the following two lines in this manner appears to make
         // the copy constructor get called, as we want. I tried initializing
         // d2 in a couple of other ways, but apparently the copy constructor
         // call was optimized away in those cases, so that the test, which
         // assumes that the copy constructor is called, failed. If at some
         // point a test fails in the upcoming CHECK, it may mean that the
         // copy constructor call is still getting optimized away by a compiler.
         // The difference here between the copy constructor and the alternative
         // (default constructor) being called, in terms of the test we're
         // doing, is in which of DerivedValue's construct() functions will
         // end up being called by Component::finish(). A lesson, I suppose,
         // is that any construct() functions in real-world classes should
         // be designed to behave in such a way that compiler "optimizations"
         // won't affect a code's meaning. The code in this test file is
         // somewhat contrived, in order to test the finish() functions, and
         // the code's meaning clearly does change here depending on which
         // constructor actually gets called.
         test::DerivedValue dfrom;
         test::DerivedValue d(dfrom);
         CHECK(test::construct2DerivedValue == true);

         CHECK(d.length() == 11);
         CHECK(d.start() == 3);
         CHECK(d.valueType() == "foobar");

         // Ensure that finish() did a sort()
         CHECK(d.content.indices.has_value() == true);
         CHECK(d.content.indices->size() == 8);
         CHECK(*d.content.indices == sorted);
      }

      // ctor: from node
      WHEN("We call the constructor from Node") {
         const std::string valueString =
            "<value length=\"10\" start=\"2\" valueType=\"Float64\">"
            "1.2 3.4 5.6 7.8"
            "</value>";
         Node node;
         node << valueString;
         CHECK(test::construct3DerivedValue == false);
         test::DerivedValue d(node);
         CHECK(test::construct3DerivedValue == true);

         // Here, the following values in the underlying BodyText should
         // reflect those that were brought in through the above string.
         CHECK(d.length() == 10);
         CHECK(d.start() == 2);
         CHECK(d.valueType() == "Float64");

         CHECK(d.size() == 10);
         CHECK(d.get<double>(0) == 0);
         CHECK(d.get<double>(1) == 0);
         CHECK(d.get<double>(2) == 1.2);
         CHECK(d.get<double>(3) == 3.4);
         CHECK(d.get<double>(4) == 5.6);
         CHECK(d.get<double>(5) == 7.8);
         CHECK(d.get<double>(6) == 0);
         CHECK(d.get<double>(7) == 0);
         CHECK(d.get<double>(8) == 0);
         CHECK(d.get<double>(9) == 0);

         // The node from which we read had body text, not child nodes,
         // and thus would give us nothing for (std::optional) indices...
         CHECK(d.content.indices.has_value() == false);
      }

      // ctor: from vector
      WHEN("We call the constructor from vector") {
         std::vector<double> vec = {{3.14159, 2.71828, 1.41421}};
         CHECK(test::construct4DerivedValue == false);
         test::DerivedValue d(vec);
         CHECK(test::construct4DerivedValue == true);

         // Here, the finish(vector) function was called, which in turn called
         // BodyText's operator=(vector), which sets the following according
         // to what's actually in the vector
         CHECK(d.length() == 3);
         CHECK(d.start() == 0); // <== always the case in this context
         CHECK(d.valueType() == "Float64");

         // Of course we should have these too...
         CHECK(d.size() == 3);
         CHECK(Approx(d.get<double>(0)) == 3.14159);
         CHECK(Approx(d.get<double>(1)) == 2.71828);
         CHECK(Approx(d.get<double>(2)) == 1.41421);

         // And, BodyText's operator=(vector) as mentioned above should also
         // have changed the corresponding values back up in the derived class
         CHECK(d.content.length == 3);
         CHECK(d.content.start == 0);
         CHECK(d.content.valueType == "Float64");

         // Ensure that finish() did a sort()
         CHECK(d.content.indices.has_value() == true);
         CHECK(d.content.indices->size() == 8);
         CHECK(*d.content.indices == sorted);
      }

   } // GIVEN


   GIVEN("A component-derived class that does not have body text") {
      const std::vector<test::LabelStruct> sorted =
         {{"a","bc","d","efg","hi","jklm","no","p"}};

      // ctor: default
      WHEN("We call the default constructor") {
         CHECK(test::construct1DerivedPlain == false);
         test::DerivedPlain d;
         CHECK(test::construct1DerivedPlain == true);

         CHECK(d.content.labels.has_value() == true);
         CHECK(d.content.labels->size() == 8);
         CHECK(*d.content.labels == sorted);
      }

      // ctor: copy
      WHEN("We call the copy constructor") {
         CHECK(test::construct2DerivedPlain == false);
         // Comment as for the one regarding DerivedValue test
         test::DerivedPlain dfrom;
         test::DerivedPlain d(dfrom);
         CHECK(test::construct2DerivedPlain == true);

         CHECK(d.content.labels.has_value() == true);
         CHECK(d.content.labels->size() == 8);
         CHECK(*d.content.labels == sorted);
      }

      // ctor: from node, case 1
      WHEN("We call the constructor from Node; with no <labels> entries") {
         const std::string valueString =
            "<plain foo=\"12\" bar=\"34.56\">"
            "</plain>";
         Node node;
         node << valueString;
         CHECK(test::construct3DerivedPlain == false);
         test::DerivedPlain d(node);
         CHECK(test::construct3DerivedPlain == true);

         CHECK(d.content.labels.has_value() == false);
      }

      // ctor: from node, case 2
      WHEN("We call the constructor from Node; with some <labels> entries") {
         const std::string valueString =
            "<plain foo=\"12\" bar=\"34.56\">"
            "   <labels label=\"jkl\" />"
            "   <labels label=\"def\" />"
            "   <labels label=\"abc\" />"
            "   <labels label=\"ghi\" />"
            "</plain>";
         Node node;
         node << valueString;
         CHECK(test::construct3DerivedPlain == true); // still true, from above
         test::DerivedPlain d(node);
         CHECK(test::construct3DerivedPlain == true);

         CHECK(d.content.labels.has_value() == true);
         CHECK(d.content.labels->size() == 4);
         CHECK((
           *d.content.labels ==
            std::vector<test::LabelStruct>{{"abc","def","ghi","jkl"}}
         ));
      }

   } // GIVEN

} // SCENARIO
