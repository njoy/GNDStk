
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
   std::istringstream iss(trim(s));
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
   std::istringstream iss(trim(s));
   T value;
   int count = 0;
   while (iss >> value)
      if (++count == 1 && iss.eof() && !(iss.bad() || iss.fail()))
         return true;
   return false;
}


// type
std::string type(const std::string &s)
{
   using string = std::string;

   if (trim(s) == "") return "empty";

   if (isvector<int   >(s)) return "vector<int>";
   if (isvector<long  >(s)) return "vector<long>";
   if (isvector<double>(s)) return "vector<double>";
   if (isvector<string>(s)) return "vector<string>";

   if (isscalar<int   >(s)) return "int";
   if (isscalar<long  >(s)) return "long";
   if (isscalar<double>(s)) return "double";
   if (isscalar<string>(s)) return "string";

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
   const std::string &label,
   const std::vector<std::string> &pfx
) {
   static const std::string separator = " /// ";
   os << indentstr << label;
   for (auto &pre : pfx)
      os << separator << pre;
   os << separator;
}


// For gnds::[knoop|generic]::node
template<class NODE>
void write(
   std::ostream &os,
   const int indentlevel,
   const NODE &node,
   std::vector<std::string> &pfx
) {
   // indentation
   const std::string indentstr(gnds::indent*indentlevel,' ');

   // name
   prefix(os, indentstr, "type", pfx);
   os << node.name() << std::endl;

   // prefix
   pfx.push_back(node.name());

   // metadata
   for (const auto &m : node.metadata()) {
      prefix(os, indentstr, "meta", pfx);
      os << m.first << " [" << type(m.second) << "]" << std::endl;
   }

   // children
   for (const auto &cptr : node.children()) {
      assert(cptr != nullptr);
      write(os, indentlevel+1, *cptr, pfx);
   }

   pfx.pop_back();
}


// For gnds::[knoop|generic]
template<class TREE>
void write(std::ostream &os, const TREE &doc)
{
   std::vector<std::string> pfx;
   if (doc.root)
      write(os, 0, *doc.root, pfx);
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
