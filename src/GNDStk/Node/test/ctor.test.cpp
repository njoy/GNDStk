
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;


// ------------------------
// yyyymmdd
// ------------------------

struct yyyymmdd;
void convert(const yyyymmdd &from, Node<> &to);

struct yyyymmdd {
   int year, month, day;
   yyyymmdd(const int year, const int month, const int day) :
      year(year), month(month), day(day)
   { }

   // implicit conversion to Node
   operator Node<>() const
   {
      Node<> n;
      convert(*this,n);
      return n;
   }
};

// convert() yyyymmdd to a Node. Sort of contrived - it just makes a Node
// with these as metadata. Used later, to exercise certain constructors.
void convert(const yyyymmdd &from, Node<> &to)
{
   CHECK(to.empty()); // it *should* come here this way
   to.add("Year", from.year );
   to.add("Month",from.month);
   to.add("Day",  from.day  );
};


// ------------------------
// mmddyyyy
// ------------------------

struct mmddyyyy {
   int month, day, year;
   mmddyyyy(const int month, const int day, const int year) :
      month(month), day(day), year(year)
   { }

   // implicit conversion to yyyymmdd
   operator yyyymmdd() const
   {
      return yyyymmdd(year,month,day);
   }
};

// convert() mmddyyyy to a Node.
void convert(const mmddyyyy &from, Node<> &to)
{
   CHECK(to.empty()); // it *should* come here this way
   to.add("Month",from.month);
   to.add("Day",  from.day  );
   to.add("Year", from.year );
};


// ------------------------
// Scenario
// ------------------------

SCENARIO("Testing GNDStk Node constructors") {

   // ------------------------
   // default
   // ------------------------
   WHEN("A Node is default constructed") {
      Node<> n;
      CHECK(n.empty());
   }

   // ------------------------
   // move
   // ------------------------
   WHEN("A default Node is move constructed") {
      Node<> n(Node<>{});
      CHECK(n.empty());
   }

   // ------------------------
   // copy
   // ------------------------
   WHEN("A tree's top-level Node is copy constructed") {
      Tree<> t("n-008_O_016.xml");
      Node<> n(t.top());
      std::ostringstream osst; osst << t.top();
      std::ostringstream ossn; ossn << n;
      CHECK(osst.str() == ossn.str());
   }

   // ------------------------
   // templated "copy"
   // ------------------------
   WHEN("A tree's top Node is constructed into a different-typed Node") {
      Tree<std::vector,std::deque> t("n-008_O_016.xml");
      Node<std::deque,std::vector> n(t.top());
      std::ostringstream osst; osst << t.top();
      std::ostringstream ossn; ossn << n;
      CHECK(osst.str() == ossn.str());
   }

   // ------------------------
   // string (the Node's name)
   // ------------------------
   WHEN("A Node is constructed from just a name (no metadata/children)") {
      Node<> n("NodeName");
      CHECK(n.name == "NodeName");
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 0);
   }

   // ------------------------
   // Child<*> (from which
   // we get the Node's name
   // ------------------------
   WHEN("A Node is constructed from a Child") {
      Node<> n(basic::child::reactionSuite);
      CHECK(n.name == "reactionSuite");
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 0);
   }

   // ------------------------
   // Child<void>, Node
   // ------------------------
   GIVEN ("A Node with some metadata and children") {
      // to be used...
      Node<> nv("one");
      nv.add("key1","value1");
      nv.add("key2","value2");
      nv.add("child1");
      Node<std::deque,std::deque> nd("two");
      nd.add("key1","value1");
      nd.add("child1");
      nd.add("child2");

      // Child<void,one>
      WHEN("Another Node is constructed from (Child<one>,Node)") {
         Node<> n(Child<void,Allow::one>("ONE"),nv);
         CHECK(n.name == "ONE"); // name taken from the Child, not from nv
         CHECK(n.metadata.size() == 2);
         CHECK(n.children.size() == 1);
      }

      // Child<void,many>, just to be different from the <one> case above
      WHEN("Another Node is constructed from (Child<many>,Node)") {
         Node<> n(Child<void,Allow::many>("TWO"),nd);
         CHECK(n.name == "TWO"); // as above
         CHECK(n.metadata.size() == 1);
         CHECK(n.children.size() == 2);
      }

      // With a yyyymmdd, which can implcitly convert to a Node
      WHEN("Another Node is constructed from (Child<many>,type)") {
         Node<> n(Child<void,Allow::many>("THREE"),yyyymmdd{1776,7,4});
         CHECK(n.name == "THREE");
         CHECK(n.metadata.size() == 3);
         CHECK(n.meta("Year" ) == "1776");
         CHECK(n.meta("Month") == "7");
         CHECK(n.meta("Day"  ) == "4");
         CHECK(n.children.size() == 0);
      }
   }

   // ------------------------
   // Child<TYPE>, TYPE
   // ------------------------
   GIVEN("Some Child<type> objects") {
      const Child<yyyymmdd,Allow::one> ymd("YearMonthDay",yyyymmdd{0,0,0});
      const Child<mmddyyyy,Allow::one> mdy("MonthDayYear",mmddyyyy{0,0,0});

      WHEN("A Node is constructed with (Child<type>,type)") {
         Node<> n(ymd,yyyymmdd{1776,7,4});
         CHECK(n.name == "YearMonthDay");
         CHECK(n.metadata.size() == 3);
         CHECK(n.meta("Year" ) == "1776");
         CHECK(n.meta("Month") == "7");
         CHECK(n.meta("Day"  ) == "4");
         CHECK(n.children.size() == 0);
      }

      WHEN("A Node is constructed with (Child<type>,type)") {
         Node<> n(mdy,mmddyyyy{6,21,1788});
         CHECK(n.name == "MonthDayYear");
         CHECK(n.metadata.size() == 3);
         CHECK(n.meta("Year" ) == "1788");
         CHECK(n.meta("Month") == "6");
         CHECK(n.meta("Day"  ) == "21");
         CHECK(n.children.size() == 0);
      }

      // mix things up a bit, considering that
      // mmddyyyy has a conversion to yyyymmdd
      WHEN("Same, with (Child<type>, other type convertible to type)") {
         Node<> n(ymd,mmddyyyy{6,21,1788});
         CHECK(n.name == "YearMonthDay");
         CHECK(n.metadata.size() == 3);
         CHECK(n.meta("Year" ) == "1788");
         CHECK(n.meta("Month") == "6");
         CHECK(n.meta("Day"  ) == "21");
         CHECK(n.children.size() == 0);
      }
   }
}
