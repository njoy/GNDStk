
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;


// ------------------------
// dimensions2d; example
// for metadata
// ------------------------

struct dimensions2d {
   int rows;
   int cols;
   dimensions2d() : rows(10), cols(10) { }
   dimensions2d(const int r, const int c) : rows(r), cols(c) { }
};

std::ostream &operator<<(std::ostream &s, const dimensions2d &dim)
{
   return s << dim.rows << ',' << dim.cols;
}


// ------------------------
// dim2d; example for
// nodes
// ------------------------

struct dim2d {
   int rows;
   int cols;
   dim2d(const int r, const int c) : rows(r), cols(c) { }
};

void convert(const dim2d &d, Node<> &out)
{
   out.name = "unused";
   out.add("numberOfRows",d.rows);
   out.add("numberOfColumns",d.cols);
   out.add("firstExampleSubNode");
   out.add("secondExampleSubNode");
}


// ------------------------
// Scenario
// ------------------------

SCENARIO("Testing GNDStk Node add()") {

   GIVEN("A default-constructed node") {
      Node<> n;
      n.name = "name";
      // debug = true;

      // metadata, string key, various value types
      WHEN("We add a metadata pair") {
         n.add(std::make_pair("a","b"));
         CHECK(n.metadata.size() == 1);
         CHECK(n.metadata[0].first == "a");
         CHECK(n.metadata[0].second == "b");
      }

      WHEN("We add another metadata pair") {
         n.add(std::string("one"), std::string("two"));
         n.add("1","2");
         THEN("node add() returns a reference to the pair") {
            auto &pair = n.add("foobar", "foo bar");
            CHECK(pair.first == "foobar");
            CHECK(pair.second == "foo bar");
         }
      }

      n.add("3",3.1416);
      n.add("4",dimensions2d(12,34));
      n.add(std::make_pair(std::string("5"),dimensions2d(56,78)));
      n.add(std::make_pair("6",9));

      // metadata, meta_t key
      auto v   = keyword.meta<void>("AStringViaVoid");
      auto str = keyword.meta<std::string>("AString");
      auto dbl = keyword.meta<double>("ADouble");
      auto dim = keyword.meta<dimensions2d>("Dimensions");
      n.add(v);
      n.add(v,"fred");
      n.add(str);
      n.add(str,"flintstone");
      n.add(dbl);
      n.add(dbl,1.23);
      n.add(dim);
      n.add(dim,{321,987});

      // children, empty / name / other node
      n.add(); // no name child
      n.add("SubNode 2");
      n.add(std::string("SubNode 3"));
      Node<> n1; n1.name = "SubNode 4";
      Node<std::deque,std::list> n2; n2.name = "SubNode 5";
      n.add(n1);
      n.add(n2);

      // ------------------------
      // ------------------------
      // ------------------------

      auto foo  = keyword.child<void,allow::one>("foo");
      auto foos = keyword.child<
         std::vector<double>,
         allow::one
      >("values",misc::child::convert_pcdata_text);

      auto nrepeat = keyword.child<void,allow::many>("repeated node");
      Node<> node1; node1.name = "aa11";
      Node<> node2; node2.name = "bb22";
      Node<> node3; node3.name = "cc33";
      Node<> node4; node4.name = "dd44";
      Node<> node5; node5.name = "ee55";
      std::vector<Node<>> vec;
      vec.push_back(node1);
      vec.push_back(node2);
      vec.push_back(node3);
      vec.push_back(node4);
      n.add(nrepeat,vec);
      n.add(nrepeat,node5);

      auto drepeat = keyword.child<dim2d,allow::many>("dimension");
      const dim2d a(1,2), b(3,4), c(5,6), d(7,8), e(9,10);
      n.add(drepeat,{a,b,c,d});
      n.add(drepeat,e);

      Node<std::deque,std::list> n3; n3.name = "SubNode 6";
      n.add(foo,n3);
      n.add(foos,std::vector<double>{ 1.2, 3.4, 5.6, 7.8 });

      n.write(std::cout);
   }
}
