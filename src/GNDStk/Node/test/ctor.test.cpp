
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
      Node n;
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
   {
      Node<> n;
      CHECK(n.empty());
   }

   // ------------------------
   // move
   // ------------------------
   {
      Node<> n(Node<>{});
      CHECK(n.empty());
   }

   // ------------------------
   // copy
   // ------------------------
   {
      Tree<> t("n-008_O_016.xml");
      Node<> n(t.top());
      std::ostringstream osst; osst << t.top();
      std::ostringstream ossn; ossn << n;
      CHECK(osst.str() == ossn.str());
   }

   // ------------------------
   // templated "copy"
   // ------------------------
   {
      Tree<std::vector,std::deque> t("n-008_O_016.xml");
      Node<std::deque,std::vector> n(t.top());
      std::ostringstream osst; osst << t.top();
      std::ostringstream ossn; ossn << n;
      CHECK(osst.str() == ossn.str());
   }

   // ------------------------
   // string (the node's name)
   // ------------------------
   {
      Node<> n("NodeName");
      CHECK(n.name == "NodeName");
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 0);
   }

   // ------------------------
   // child_t<*> (from which
   // we get the node's name
   // ------------------------
   {
      Node<> n(plain::child::reactionSuite);
      CHECK(n.name == "reactionSuite");
      CHECK(n.metadata.size() == 0);
      CHECK(n.children.size() == 0);
   }

   // ------------------------
   // child_t<void>, Node
   // ------------------------
   {
      // to be used...
      Node<> nv("one");
      nv.add("key1","value1");
      nv.add("key2","value2");
      nv.add("child1");
      Node<std::deque,std::deque> nd("two");
      nd.add("key1","value1");
      nd.add("child1");
      nd.add("child2");

      // child_t<void,one>
      {
         Node<> n(child_t<void,find::one>("ONE"),nv);
         CHECK(n.name == "ONE"); // name taken from the child_t, not from nv
         CHECK(n.metadata.size() == 2);
         CHECK(n.children.size() == 1);
      }

      // child_t<void,all>, just to be different from the <one> case above
      {
         Node<> n(child_t<void,find::all>("TWO"),nd);
         CHECK(n.name == "TWO"); // as above
         CHECK(n.metadata.size() == 1);
         CHECK(n.children.size() == 2);
      }

      // With a yyyymmdd, which can implcitly convert to a Node
      {
         Node<> n(child_t<void,find::all>("THREE"),yyyymmdd{1776,7,4});
         CHECK(n.name == "THREE");
         CHECK(n.metadata.size() == 3);
         CHECK(n.meta("Year" ) == "1776");
         CHECK(n.meta("Month") == "7");
         CHECK(n.meta("Day"  ) == "4");
         CHECK(n.children.size() == 0);
      }
   }

   // ------------------------
   // child_t<TYPE>, TYPE
   // ------------------------
   {
      const child_t<yyyymmdd,find::one> ymd("YearMonthDay");
      const child_t<mmddyyyy,find::one> mdy("MonthDayYear");

      {
         Node<> n(ymd,yyyymmdd{1776,7,4});
         CHECK(n.name == "YearMonthDay");
         CHECK(n.metadata.size() == 3);
         CHECK(n.meta("Year" ) == "1776");
         CHECK(n.meta("Month") == "7");
         CHECK(n.meta("Day"  ) == "4");
         CHECK(n.children.size() == 0);
      }

      {
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
      {
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
