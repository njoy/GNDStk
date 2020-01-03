
// -----------------------------------------------------------------------------
// Macros, variables
// -----------------------------------------------------------------------------

// printval
// printvar
// Are the same, so we don't need to remember the exact terminology
#define printval(var) std::cout << #var ": [" << var << "]" << std::endl
#define printvar(var) printval(var)

// indent
// Number of spaces of indentation you want, in the output of certain types
inline int indent = 3;

// verbose
// Flag: should debug() actually print anything?
inline bool verbose = false;



// -----------------------------------------------------------------------------
// Forward declarations: general
// -----------------------------------------------------------------------------

// fixme With some reorganization elsewhere, some of these may not be necessary

// Node, node
template<
   template<class...> class,
   template<class...> class
>
class Node;
using node = Node<std::vector,std::vector>;

// Tree, tree
template<
   template<class...> class,
   template<class...> class
>
class Tree;
using tree = Tree<std::vector,std::vector>;

// xml, json
class xml;
class json;

// tnode
template<
   template<class...> class MCON,
   template<class...> class CCON,
   class T
>
class tnode;



// -----------------------------------------------------------------------------
// Forward declarations: convert
// -----------------------------------------------------------------------------

// convert
// ...Tree to Tree
// ...Tree to xml
// ...Tree to json
// ...xml  to Tree
// ...xml  to xml
// ...xml  to json
// ...json to Tree
// ...json to xml
// ...json to json


// Tree to {Tree,xml,json}
template<
   template<class...> class MCONFROM,
   template<class...> class CCONFROM,
   template<class...> class MCONTO,
   template<class...> class CCONTO
>
bool convert(
   const gnds::Tree<MCONFROM,CCONFROM> &,
   gnds::Tree<MCONTO,CCONTO> &
);

template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool convert(
   const gnds::Tree<MCON,CCON> &,
   gnds::xml &
);

template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool convert(
   const gnds::Tree<MCON,CCON> &,
   gnds::json &
);


// xml to {Tree,xml,json}
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool convert(const gnds::xml &, gnds::Tree<MCON,CCON> &);

bool convert(const gnds::xml &, gnds::xml &);

bool convert(const gnds::xml &, gnds::json &);


// json to {Tree,xml,json}
template<
   template<class...> class MCON,
   template<class...> class CCON
>
bool convert(const gnds::json &, gnds::Tree<MCON,CCON> &);

bool convert(const gnds::json &, gnds::xml &);

bool convert(const gnds::json &, gnds::json &);



// -----------------------------------------------------------------------------
// Utility constructs
// The functions here could possibly go into the detail namespace, but could
// arguably be useful, in their own right, to users. So, I'll leave them out
// in the overall project namespace (which enclosed the #include of this file).
// -----------------------------------------------------------------------------

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

// typeof
template<class T>
inline void typeof(const T &)
{
   std::cout << boost::core::demangle(typeid(T).name()) << std::endl;
}
