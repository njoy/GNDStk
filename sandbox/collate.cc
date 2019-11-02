
#include "gnds.hpp"

inline const std::string META = "meta";
inline const std::string TYPE = "type";
inline const std::string SEP = " /// ";

inline void print_prefix(
   const std::string &label,
   const std::string &indentstr,
   const std::vector<std::string> &prefix,
   std::ostream &os
) {
   os << indentstr << label;
   for (auto &pre : prefix)
      os << SEP << pre;
   os << SEP;
}



// -----------------------------------------------------------------------------
// write (special-purpose)
// -----------------------------------------------------------------------------

// For gnds::[knoop|generic]::node
template<class NODE>
void write(
   const NODE &node,
   std::ostream &os,
   const int indentlevel,
   std::vector<std::string> &prefix
) {
   // indentation
   const std::string icurr(gnds::indent*indentlevel,' ');

   // name
   print_prefix(TYPE,icurr,prefix,os);
   os << node.name() << std::endl;

   // prefix
   prefix.push_back(node.name());

   // metadata
   for (const auto &m : node.metadata()) {
      print_prefix(META,icurr,prefix,os);
      os << m.first /*<< SEP << "(value)"*/ << std::endl;
   }

   // children
   for (const auto &cptr : node.children()) {
      assert(cptr != nullptr); // <== I don't think this ever happens
      if (cptr)
         write(*cptr, os, indentlevel+1, prefix);
   }

   prefix.pop_back();
}



// For gnds::[knoop|generic]
template<class T>
void write(const T &doc, std::ostream &os)
{
   std::vector<std::string> prefix;
   if (doc.root) write(*doc.root,os,0,prefix);
}



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char *const *const argv)
{
   gnds::indent = 0;

   for (int i = 1;  i < argc;  ++i) {
      const std::string filename = argv[i];

      // skip non-xml files for now
      if (!gnds::endsin(filename,".xml"))
         continue;

      // xml
      gnds::xml x(filename);

      // convert to generic
      gnds::generic g(x);
      write(g,std::cout);
   }
}



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#if 0
#if 0
#if 0
#if 0
#if 0

#include "gnds.hpp"

inline const std::string META = "meta";
inline const std::string TYPE = "type";
inline const std::string SEP = " /// ";

inline void print_prefix(
///   const std::string &label,
   const std::string &indentstr,
   const std::vector<std::string> &prefix,
   std::ostream &os
) {
   /*
   os << indentstr << label;
   for (auto &pre : prefix)
      os << SEP << pre;
   os << SEP;
   */

   if (prefix.size()) {
      os << indentstr;
      int pos = 0;
      for (auto &pre : prefix)
         os << (pos++ == 0 ? "" : SEP) << pre;
      os << SEP;
   }
}



// -----------------------------------------------------------------------------
// write (special-purpose)
// -----------------------------------------------------------------------------

// For gnds::[knoop|generic]::node
template<class NODE>
void write(
   const NODE &node,
   std::ostream &os,
   const int indentlevel,
   std::vector<std::string> &prefix
) {
   // indentation
   const std::string icurr(gnds::indent*indentlevel,' ');

   // name
   print_prefix(/*TYPE,*/icurr,prefix,os);
   os << node.name() << SEP << TYPE << std::endl;

   // prefix
   prefix.push_back(node.name());

   // metadata
   for (const auto &m : node.metadata()) {
      print_prefix(/*META,*/icurr,prefix,os);
      os << m.first << SEP << META << std::endl;
   }

   // children
   for (const auto &cptr : node.children()) {
      assert(cptr != nullptr); // <== I don't think this ever happens
      if (cptr)
         write(*cptr, os, indentlevel+1, prefix);
   }

   prefix.pop_back();
}



// For gnds::[knoop|generic]
template<class T>
void write(const T &doc, std::ostream &os)
{
   std::vector<std::string> prefix;
   if (doc.root) write(*doc.root,os,0,prefix);
}



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char *const *const argv)
{
   gnds::indent = 0;

   for (int i = 1;  i < argc;  ++i) {
      const std::string filename = argv[i];

      // skip non-xml files for now
      if (!gnds::endsin(filename,".xml"))
         continue;

      // xml
      gnds::xml x(filename);

      // convert to generic
      gnds::generic g(x);
      write(g,std::cout);
   }
}

#endif
#endif
#endif
#endif
#endif
