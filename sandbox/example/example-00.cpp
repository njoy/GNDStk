
#include "gnds.hpp"

int main(const int, const char * const * const)
{
   pugi::xml_document px;
   nlohmann::json     nj;
   gnds::xml  x;
   gnds::json j;
   gnds::tree t;

   gnds::Tree<std::deque,  std::deque > td;
   gnds::Tree<std::list,   std::list  > tl;
   gnds::Tree<std::vector, std::vector> tv;

   ///pugi::xml_document px2 = px;
   nlohmann::json     nj2 = nj;
   gnds::xml  x2 = x;
   gnds::json j2 = j;
   gnds::tree t2 = t; /// but want deep-copy semantics
   /// Also: allow Tree<blah> to Tree<different blah> construct/convert

   gnds::convert(j,j2);
   gnds::convert(x,x2);

   // ------------------------
   // Combos...
   // ------------------------

   {
      gnds::xml  a;
      gnds::json b;
      gnds::tree c;
      gnds::Tree<std::deque,  std::deque > d;
      gnds::Tree<std::list,   std::list  > e;
      gnds::Tree<std::vector, std::vector> f;

      // ------------------------
      // ...construct
      // ------------------------

      {
      const gnds::xml                                        a1(a);
      const gnds::json                                       b1(a);
      const gnds::tree                                       c1(a);
      const gnds::Tree<std::deque,        std::deque       > d1(a);
      const gnds::Tree<std::list,         std::list        > e1(a);
      const gnds::Tree<std::vector,       std::vector      > f1(a);

      const gnds::xml                                        a2(b);
      const gnds::json                                       b2(b);
      const gnds::tree                                       c2(b);
      const gnds::Tree<std::deque,        std::deque       > d2(b);
      const gnds::Tree<std::list,         std::list        > e2(b);
      const gnds::Tree<std::vector,       std::vector      > f2(b);

      const gnds::xml                                        a3(c);
      const gnds::json                                       b3(c);
      const gnds::tree                                       c3(c);
      const gnds::Tree<std::deque,        std::deque       > d3(c);
      const gnds::Tree<std::list,         std::list        > e3(c);
      const gnds::Tree<std::vector,       std::vector      > f3(c);

      const gnds::xml                                        a4(d);
      const gnds::json                                       b4(d);
      const gnds::tree                                       c4(d);
      const gnds::Tree<std::deque,        std::deque       > d4(d);
      const gnds::Tree<std::list,         std::list        > e4(d);
      const gnds::Tree<std::vector,       std::vector      > f4(d);

      const gnds::xml                                        a6(e);
      const gnds::json                                       b6(e);
      const gnds::tree                                       c6(e);
      const gnds::Tree<std::deque,        std::deque       > d6(e);
      const gnds::Tree<std::list,         std::list        > e6(e);
      const gnds::Tree<std::vector,       std::vector      > f6(e);

      const gnds::xml                                        a7(f);
      const gnds::json                                       b7(f);
      const gnds::tree                                       c7(f);
      const gnds::Tree<std::deque,        std::deque       > d7(f);
      const gnds::Tree<std::list,         std::list        > e7(f);
      const gnds::Tree<std::vector,       std::vector      > f7(f);
      }

      // ------------------------
      // ...convert
      // ------------------------

      gnds::convert(a,a);
      gnds::convert(a,b);
      gnds::convert(a,c);
      gnds::convert(a,d);
      gnds::convert(a,e);
      gnds::convert(a,f);

      gnds::convert(b,a);
      gnds::convert(b,b);
      gnds::convert(b,c);
      gnds::convert(b,d);
      gnds::convert(b,e);
      gnds::convert(b,f);

      gnds::convert(c,a);
      gnds::convert(c,b);
      gnds::convert(c,c);
      gnds::convert(c,d);
      gnds::convert(c,e);
      gnds::convert(c,f);

      gnds::convert(d,a);
      gnds::convert(d,b);
      gnds::convert(d,c);
      gnds::convert(d,d);
      gnds::convert(d,e);
      gnds::convert(d,f);

      gnds::convert(e,a);
      gnds::convert(e,b);
      gnds::convert(e,c);
      gnds::convert(e,d);
      gnds::convert(e,e);
      gnds::convert(e,f);

      gnds::convert(f,a);
      gnds::convert(f,b);
      gnds::convert(f,c);
      gnds::convert(f,d);
      gnds::convert(f,e);
      gnds::convert(f,f);

      // ------------------------
      // ...assign
      // ------------------------

      // fixme Write these. (And the code for them!)
   }
}
