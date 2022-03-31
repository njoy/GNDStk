
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;



// -----------------------------------------------------------------------------
// DerivedValue
// Has block data
// -----------------------------------------------------------------------------

namespace test {

// Helper
struct IndexStruct {
   struct {
      std::size_t index;
   } Content;
   const std::size_t &index() const { return Content.index; }
   std::size_t &index() { return Content.index; }

   IndexStruct(const std::size_t i = 0) { index() = i; }
   IndexStruct(const Node &) : IndexStruct(0) { }
};

inline bool operator==(const IndexStruct &one, const IndexStruct &two)
{
   return one.index() == two.index();
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
   static auto NAMESPACE() { return "test"; }
   static auto CLASS() { return "DerivedValue"; }
   static auto FIELD() { return "value"; }

   // keys
   static auto KEYS()
   {
      return
         int{} / Meta<>("length") |
         int{} / Meta<>("start") |
         std::string{} / Meta<>("valueType") |
         std::optional<IndexStruct>{} / ++Child<>("indices")
      ;
   }

public:

   // Content
   // Typically doesn't need to be public, but we make it public here because
   // one of the tests involves checking these
   struct {
      // Initialize these to specific values, so that we can ensure that
      // Component's finish() functions properly call
      // BLOCKDATA::pullFromDerived()
      int length = 11;
      int start = 3;
      std::string valueType = "foobar";

      // A vector of something that contains index, to ensure that the finish()
      // functions detect and sort it.
      std::optional<std::vector<IndexStruct>> indices =
         {{3,2,17,7,5,9,13,11}};
   } Content;

   const int &length() const { return Content.length; }
   int &length() { return Content.length; }

   const int &start() const { return Content.start; }
   int &start() { return Content.start; }

   const std::string &valueType() const { return Content.valueType; }
   std::string &valueType() { return Content.valueType; }

   const std::optional<std::vector<IndexStruct>> &indices() const
   { return Content.indices; }
   std::optional<std::vector<IndexStruct>> &indices()
   { return Content.indices; }

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
         BlockData{},
         length(), start(), valueType(), indices()
      )
   {
      // finish()
      Component::finish();
   }

   // ctor: copy
   DerivedValue(const DerivedValue &other) :
      Component{
         other,
         length(), start(), valueType(), indices()
      },
      Content{other.Content}
   {
      // finish(derived)
      Component::finish(other);
   }

   // ctor: node
   DerivedValue(const Node &node) :
      Component{
         BlockData{},
         length(), start(), valueType(), indices()
      }
   {
      // finish(node)
      Component::finish(node);
   }

   // ctor: vector
   DerivedValue(const std::vector<double> &vec) :
      Component{
         BlockData{},
         length(), start(), valueType(), indices()
      }
   {
      // finish(vector)
      Component::finish(vec);
   }
};

} // namespace test



// -----------------------------------------------------------------------------
// DerivedPlain
// Does not have block data
// -----------------------------------------------------------------------------

namespace test {

// Helper
struct LabelStruct {
   struct {
      std::string label;
   } Content;
   const std::string &label() const { return Content.label; }
   std::string &label() { return Content.label; }

   // apparently need a char* ctor for initializer-list initialization to work
   LabelStruct(const char *const str = "") { label() = str; }
   LabelStruct(const Node &node)
   {
      label() = node(std::string{}/Meta<>("label"));
   }
};

inline bool operator==(const LabelStruct &one, const LabelStruct &two)
{
   return one.label() == two.label();
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
   static auto NAMESPACE() { return "test"; }
   static auto CLASS() { return "DerivedPlain"; }
   static auto FIELD() { return "plain"; }

   // keys
   static auto KEYS()
   {
      return
         int   {} / Meta<>("foo") |
         double{} / Meta<>("bar") |
         std::optional<LabelStruct>{} / ++Child<>("labels")
      ;
   }

public:

   // Content
   struct {
      int foo;
      double bar;

      // A vector of something that contains label, to ensure that the finish()
      // functions detect and sort it.
      std::optional<std::vector<LabelStruct>> labels =
         {{"bc","a","p","efg","d","hi","no","jklm"}};
   } Content;

   const int &foo() const { return Content.foo; }
   int &foo() { return Content.foo; }

   const double &bar() const { return Content.bar; }
   double &bar() { return Content.bar; }

   const std::optional<std::vector<LabelStruct>> &labels() const
   { return Content.labels; }
   std::optional<std::vector<LabelStruct>> &labels()
   { return Content.labels; }

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
         BlockData{},
         foo(), bar(), labels()
      )
   {
      // finish()
      Component::finish();
   }

   // ctor: copy
   DerivedPlain(const DerivedPlain &other) :
      Component{
         other,
         foo(), bar(), labels()
      },
      Content{other.Content}
   {
      // finish(derived)
      Component::finish(other);
   }

   // ctor: node
   DerivedPlain(const Node &node) :
      Component{
         BlockData{},
         foo(), bar(), labels()
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

   GIVEN("A component-derived class that has block data") {
      const std::vector<test::IndexStruct> sorted =
         {{2,3,5,7,9,11,13,17}};

      // ctor: default
      WHEN("We call the default constructor") {
         CHECK(test::construct1DerivedValue == false);
         test::DerivedValue d;
         // Ensure that finish() called the construct() in the derived class...
         CHECK(test::construct1DerivedValue == true);

         // Ensure that finish() did a BlockData::pullFromDerived()
         CHECK(d.length() == 11);
         CHECK(d.start() == 3);
         CHECK(d.valueType() == "foobar");

         // Ensure that finish() did a sort()
         CHECK(d.indices().has_value() == true);
         CHECK(d.indices()->size() == 8);
         CHECK(*d.indices() == sorted);
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
         CHECK(d.indices().has_value() == true);
         CHECK(d.indices()->size() == 8);
         CHECK(*d.indices() == sorted);
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

         // Here, the following values in the underlying BlockData should
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

         // The node from which we read had block data, not child nodes,
         // and thus would give us nothing for (std::optional) indices...
         CHECK(d.indices().has_value() == false);
      }

      // ctor: from vector
      WHEN("We call the constructor from vector") {
         std::vector<double> vec = {{3.14159, 2.71828, 1.41421}};
         CHECK(test::construct4DerivedValue == false);
         test::DerivedValue d(vec);
         CHECK(test::construct4DerivedValue == true);

         // Here, the finish(vector) function was called, which in turn called
         // BlockData's operator=(vector), which sets the following according
         // to what's actually in the vector
         CHECK(d.length() == 3);
         CHECK(d.start() == 0); // <== always the case in this context
         CHECK(d.valueType() == "Float64");

         // Of course we should have these too...
         CHECK(d.size() == 3);
         CHECK(Approx(d.get<double>(0)) == 3.14159);
         CHECK(Approx(d.get<double>(1)) == 2.71828);
         CHECK(Approx(d.get<double>(2)) == 1.41421);

         // And, BlockData's operator=(vector) as mentioned above should also
         // have changed the corresponding values back up in the derived class
         CHECK(d.length() == 3);
         CHECK(d.start() == 0);
         CHECK(d.valueType() == "Float64");

         // Ensure that finish() did a sort()
         CHECK(d.indices().has_value() == true);
         CHECK(d.indices()->size() == 8);
         CHECK(*d.indices() == sorted);
      }

   } // GIVEN


   GIVEN("A component-derived class that does not have block data") {
      const std::vector<test::LabelStruct> sorted =
         {{"a","bc","d","efg","hi","jklm","no","p"}};

      // ctor: default
      WHEN("We call the default constructor") {
         CHECK(test::construct1DerivedPlain == false);
         test::DerivedPlain d;
         CHECK(test::construct1DerivedPlain == true);

         CHECK(d.labels().has_value() == true);
         CHECK(d.labels()->size() == 8);
         CHECK(*d.labels() == sorted);
      }

      // ctor: copy
      WHEN("We call the copy constructor") {
         CHECK(test::construct2DerivedPlain == false);
         // Comment as for the one regarding DerivedValue test
         test::DerivedPlain dfrom;
         test::DerivedPlain d(dfrom);
         CHECK(test::construct2DerivedPlain == true);

         CHECK(d.labels().has_value() == true);
         CHECK(d.labels()->size() == 8);
         CHECK(*d.labels() == sorted);
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

         CHECK(d.labels().has_value() == false);
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

         CHECK(d.labels().has_value() == true);
         CHECK(d.labels()->size() == 4);
         CHECK((
            *d.labels() ==
            std::vector<test::LabelStruct>{{"abc","def","ghi","jkl"}}
         ));
      }

   } // GIVEN

} // SCENARIO
