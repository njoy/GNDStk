
#include "gnds.hpp"
#include <boost/algorithm/string/trim.hpp>
#include <iostream>
#include <sstream>



// -----------------------------------------------------------------------------
// For guessing the data type
// -----------------------------------------------------------------------------

// trim
std::string trim(std::string s)
{
   boost::algorithm::trim(s);
   return s;
}


// isvector
template<class T>
bool isvector(const std::string &s)
{
   std::istringstream iss(s);
   T value;
   int count = 0;
   while (iss >> value)
      if (++count > 1 && iss.eof() && !(iss.bad() || iss.fail()))
         return true;
   return false;
}


// isscalar
template<class T>
bool isscalar(const std::string &s)
{
   std::istringstream iss(s);
   T value;
   int count = 0;
   while (iss >> value)
      if (++count == 1 && iss.eof() && !(iss.bad() || iss.fail()))
         return true;
   return false;
}


// type
std::string type(std::string str)
{
   using string = std::string;
   const string s = trim(str);

   if (s == "") return "std::string";

   if (isvector<int   >(s)) return "std::vector<int>";
   if (isvector<long  >(s)) return "std::vector<long>";
   if (isvector<double>(s)) return "std::vector<double>";
   if (isvector<string>(s)) return "std::vector<std::string>";

   if (isscalar<int   >(s)) return "int";
   if (isscalar<long  >(s)) return "long";
   if (isscalar<double>(s)) return "double";
   if (isscalar<string>(s)) return "std::string";

   return "unknown";
}



// -----------------------------------------------------------------------------
// write
// Special-purpose; not the same as gnds.hpp's
// -----------------------------------------------------------------------------

// helper: prefix
void prefix(
   std::ostream &os,
   const std::string &indentstr,
   const std::vector<std::string> &pfx
) {
   os << indentstr;
   int count = 0;
   for (auto &pre : pfx) {
      os << (count++ == 0 ? "" : " ") << pre;
///      os << (count++ == 0 ? "" : " ") << pre << std::endl;
   }
///   os << separator;
}



// For gnds::[knoop|generic]::node
template<class NODE>
void write(
   std::ostream &os,
   const int indentlevel,
   const NODE &node,
   std::vector<std::string> &pfx,
   const bool asterisk
) {
   // indentation
   const std::string indentstr(gnds::indent*indentlevel,' ');

   // prefix
   pfx.push_back(node.name() + (asterisk ? "*" : "") + " ");

   // name
   prefix(os, indentstr, pfx);
   os << std::endl;

   // metadata
   for (const auto &m : node.metadata()) {
      prefix(os, indentstr, pfx);
      os << " ;" << type(m.second) << "/**/" << m.first << ";" << std::endl;
   }

   // children
   for (auto it = node.children().begin(); it != node.children().end(); ++it) {

      // better hack
      const std::string name = (*it)->name();
      bool ast = false;
      if (name.size() > 0) {
         if (it != node.children().begin() && name == (*(it-1))->name())
            ast = true;
         if (it+1 != node.children().end() && name == (*(it+1))->name())
            ast = true;
      }

      // pre-hack
      write(os, indentlevel+1, **it, pfx, ast);
   }

   pfx.pop_back();
}



// For gnds::[knoop|generic]
template<class TREE>
void write(std::ostream &os, const TREE &doc)
{
   std::vector<std::string> pfx;
   if (doc.root)
      write(os, 0, *doc.root, pfx, false);
}



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char *const *const argv)
{
   gnds::indent = 0;

   for (int i = 1;  i < argc;  ++i) {
      const std::string filename = argv[i];

      // xml only, for now
      if (!gnds::endsin(filename,".xml"))
         continue;
      gnds::xml x(filename);

      // write
      gnds::generic g(x);
      write(std::cout,g);
   }
}
