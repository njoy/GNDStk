
#include "gnds.hpp"

int main(const int argc, const char * const * const argv)
{
   (void)argc;
   (void)argv;

   pugi::xml_document px;
   nlohmann::json     nj;
   gnds::xml  x;
   gnds::json j;
   gnds::tree t;

   gnds::Tree<std::deque,        std::deque       > td;
   gnds::Tree<std::forward_list, std::forward_list> tf;
   gnds::Tree<std::list,         std::list        > tl;
   gnds::Tree<std::vector,       std::vector      > tv;

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

   // fixme Commented-out stuff involves forward_list, which doesn't
   // have size(), erase(), push_back(), or back(). Think about this.

   {
      gnds::xml  a;
      gnds::json b;
      gnds::tree c;
      gnds::Tree<std::deque,        std::deque       > d;
      gnds::Tree<std::forward_list, std::forward_list> e;
      gnds::Tree<std::list,         std::list        > f;
      gnds::Tree<std::vector,       std::vector      > g;

      // ------------------------
      // ...construct
      // ------------------------

      {
      const gnds::xml                                        a1(a);
      const gnds::json                                       b1(a);
      const gnds::tree                                       c1(a);
      const gnds::Tree<std::deque,        std::deque       > d1(a);
      ///const gnds::Tree<std::forward_list, std::forward_list> e1(a);
      const gnds::Tree<std::list,         std::list        > f1(a);
      const gnds::Tree<std::vector,       std::vector      > g1(a);
      const gnds::xml                                        a2(b);
      const gnds::json                                       b2(b);
      const gnds::tree                                       c2(b);
      const gnds::Tree<std::deque,        std::deque       > d2(b);
      ///const gnds::Tree<std::forward_list, std::forward_list> e2(b);
      const gnds::Tree<std::list,         std::list        > f2(b);
      const gnds::Tree<std::vector,       std::vector      > g2(b);
      const gnds::xml                                        a3(c);
      const gnds::json                                       b3(c);
      const gnds::tree                                       c3(c);
      const gnds::Tree<std::deque,        std::deque       > d3(c);
      ///const gnds::Tree<std::forward_list, std::forward_list> e3(c);
      const gnds::Tree<std::list,         std::list        > f3(c);
      const gnds::Tree<std::vector,       std::vector      > g3(c);
      const gnds::xml                                        a4(d);
      const gnds::json                                       b4(d);
      const gnds::tree                                       c4(d);
      const gnds::Tree<std::deque,        std::deque       > d4(d);
      ///const gnds::Tree<std::forward_list, std::forward_list> e4(d);
      const gnds::Tree<std::list,         std::list        > f4(d);
      const gnds::Tree<std::vector,       std::vector      > g4(d);
      ///const gnds::xml                                        a5(e);
      ///const gnds::json                                       b5(e);
      ///const gnds::tree                                       c5(e);
      ///const gnds::Tree<std::deque,        std::deque       > d5(e);
      ///const gnds::Tree<std::forward_list, std::forward_list> e5(e);
      ///const gnds::Tree<std::list,         std::list        > f5(e);
      ///const gnds::Tree<std::vector,       std::vector      > g5(e);
      const gnds::xml                                        a6(f);
      const gnds::json                                       b6(f);
      const gnds::tree                                       c6(f);
      const gnds::Tree<std::deque,        std::deque       > d6(f);
      ///const gnds::Tree<std::forward_list, std::forward_list> e6(f);
      const gnds::Tree<std::list,         std::list        > f6(f);
      const gnds::Tree<std::vector,       std::vector      > g6(f);
      const gnds::xml                                        a7(g);
      const gnds::json                                       b7(g);
      const gnds::tree                                       c7(g);
      const gnds::Tree<std::deque,        std::deque       > d7(g);
      ///const gnds::Tree<std::forward_list, std::forward_list> e7(g);
      const gnds::Tree<std::list,         std::list        > f7(g);
      const gnds::Tree<std::vector,       std::vector      > g7(g);
      }

      // ------------------------
      // ...convert
      // ------------------------

      gnds::convert(a,a);
      gnds::convert(a,b);
      gnds::convert(a,c);
      gnds::convert(a,d);
      ///gnds::convert(a,e);
      gnds::convert(a,f);
      gnds::convert(a,g);
      gnds::convert(b,a);
      gnds::convert(b,b);
      gnds::convert(b,c);
      gnds::convert(b,d);
      ///gnds::convert(b,e);
      gnds::convert(b,f);
      gnds::convert(b,g);
      gnds::convert(c,a);
      gnds::convert(c,b);
      gnds::convert(c,c);
      gnds::convert(c,d);
      ///gnds::convert(c,e);
      gnds::convert(c,f);
      gnds::convert(c,g);
      gnds::convert(d,a);
      gnds::convert(d,b);
      gnds::convert(d,c);
      gnds::convert(d,d);
      ///gnds::convert(d,e);
      gnds::convert(d,f);
      gnds::convert(d,g);
      ///gnds::convert(e,a);
      ///gnds::convert(e,b);
      ///gnds::convert(e,c);
      ///gnds::convert(e,d);
      ///gnds::convert(e,e);
      ///gnds::convert(e,f);
      ///gnds::convert(e,g);
      gnds::convert(f,a);
      gnds::convert(f,b);
      gnds::convert(f,c);
      gnds::convert(f,d);
      ///gnds::convert(f,e);
      gnds::convert(f,f);
      gnds::convert(f,g);
      gnds::convert(g,a);
      gnds::convert(g,b);
      gnds::convert(g,c);
      gnds::convert(g,d);
      ///gnds::convert(g,e);
      gnds::convert(g,f);
      gnds::convert(g,g);

      // ------------------------
      // ...assign
      // ------------------------

      // fixme Write these. (And the code for them!)
   }
}
