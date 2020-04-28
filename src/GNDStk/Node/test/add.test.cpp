
// fixme
// This file tests all of Node's add() functions, but could use
// some reorganization in order to make it all much clearer.

#include "catch.hpp"
#include "GNDStk.hpp"
using namespace GNDStk;


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
   ///   dim2d() : rows(10), cols(10) { }
   dim2d(const int r, const int c) : rows(r), cols(c) { }
};

void type2node(const dim2d &d, Node<> &out)
{
   out.name = "unused";
   out.add("numberOfRows",d.rows);
   out.add("numberOfColumns",d.cols);
   out.add("firstExampleChild");
   out.add("secondExampleChild");
}


// ------------------------
// Scenario
// ------------------------

SCENARIO("Testing GNDStk Node add()") {

   Node<> n;
   n.name = "name";
   // debug = true;

   // metadata, string key, various value types
   n.add(std::make_pair("a","b"));
   n.add(std::string("one"), std::string("two"));
   n.add("1","2");
   auto &pair = n.add("foobar", "foo bar");
   CHECK(pair.second == "foo bar");
   n.add("3",3.1416);
   n.add("4",dimensions2d(12,34));

   // metadata, meta_t key
   auto v   = keyword.meta<void>("AStringViaVoid");
   auto str = keyword.meta<std::string>("AString");
   auto dbl = keyword.meta<double>("ADouble");
   auto dim = keyword.meta<dimensions2d>("Dimensions");
   n.add(v,"fred");
   n.add(str,"flintstone");
   n.add(dbl);
   n.add(dbl,1.23);
   n.add(dim);
   n.add(dim,{321,987});

   // children, empty / name / other node
   n.add(); // no name child
   n.add("Child 2");
   n.add(std::string("Child 3"));
   Node<> n1; n1.name = "Child 4";
   Node<std::deque,std::list> n2; n2.name = "Child 5";
   n.add(n1);
   n.add(n2);

   // ------------------------
   // ------------------------
   // ------------------------

   auto foo  = keyword.child<void,find::one>("foo");
   auto foos = keyword.child<std::vector<double>,find::one>("values");

   auto nrepeat = keyword.child<void,find::all>("repeated node");
   Node<> node1; node1.name = "aa11";
   Node<> node2; node2.name = "bb22";
   Node<> node3; node3.name = "cc33";
   Node<> node4; node4.name = "dd44";
   std::vector<Node<>> vec;
   // change the following, assuming we add back node's copy constructor...
   vec.emplace_back(node1.copy());
   vec.emplace_back(node2.copy());
   vec.emplace_back(node3.copy());
   vec.emplace_back(node4.copy());
   n.add(nrepeat,vec);

   auto drepeat = keyword.child<dim2d,find::all>("dimension");
   const dim2d a(1,2), b(3,4), c(5,6), d(7,8);
   n.add(drepeat,{a,b,c,d});

   Node<std::deque,std::list> n3; n3.name = "Child 6";
   n.add(foo,n3);
   n.add(foos,std::vector<double>{ 1.2, 3.4, 5.6, 7.8 });

   n.write(std::cout);
}
