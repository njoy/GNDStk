
// printval
// printvar
// Macros. Are the same, so we don't need to remember the exact terminology
#define printval(var) std::cout << #var ": [" << var << "]" << std::endl
#define printvar(var) printval(var)

// Forward declarations
class xml;
class json;
class node;
class tree;
bool convert(const xml  &from, tree &to);
bool convert(const json &from, tree &to);
bool convert(const tree &from, xml  &to);
bool convert(const tree &from, json &to);



// -----------------------------------------------------------------------------
// Utility constructs
// -----------------------------------------------------------------------------

// indent
// Number of spaces of indentation you want, in the output of certain types
inline int indent = 3;


// verbose
// Flag: should debug() actually print anything?
inline bool verbose = false;

// debug
inline void debug(const std::string &str)
{
   if (verbose)
      std::cout << "debug: " << str << std::endl;
}


// filesize(char *)
inline std::ifstream::pos_type filesize(const char * const file)
{
   std::ifstream ifs(file, std::ifstream::ate | std::ifstream::binary);
   return ifs.tellg();
}

// filesize(string)
inline std::ifstream::pos_type filesize(const std::string &file)
{
   return filesize(file.c_str());
}


// endsin
// C++20 will have an ends_with(); for now we'll have this
inline bool endsin(const std::string &str, const std::string &end)
{
   return str.size() >= end.size() && &str[str.size()-end.size()] == end;
}



// -----------------------------------------------------------------------------
// write(node)
// Helper for writing certain "tree node" types that we'll define elsewhere.
// Works for any sufficiently equipped node type.
// -----------------------------------------------------------------------------

namespace detail {

template<class NODE>
std::ostream &write(const NODE &node, std::ostream &os, const int level)
{
   // indentation
   const std::string icurr(indent* level   ,' ');
   const std::string inext(indent*(level+1),' ');

   // write name
   os << icurr << node.name() << ":" << std::endl;

   // write metadata
   for (const auto &meta : node.metadata())
      os << inext << meta.first << ": " << meta.second << std::endl;

   // write children
   for (const auto &cptr : node.children())
      if (cptr)
         write(*cptr, os, level+1);

   // done
   return os;
}

} // namespace detail
