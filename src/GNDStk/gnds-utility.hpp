
// -----------------------------------------------------------------------------
// Macros, variables, enums
// -----------------------------------------------------------------------------

// printval
// printvar
// Are the same, so we don't need to remember the exact terminology
#define printval(var) std::cout << #var ": [" << var << "]" << std::endl
#define printvar(var) printval(var)

// indent
// Number of spaces of indentation you want, in the output of certain types
inline int indent = 3;

// format
enum class format {
   unspecified,
   xml,
   json,
   tree, Tree = tree
   // Both "tree" and "Tree" are allowed, to be consistent with the fact that
   // we have both classes: Tree (templated), and shorthand tree (is Tree<>).
};



// -----------------------------------------------------------------------------
// Forward declarations: general
// -----------------------------------------------------------------------------

// fixme Some reorg elsewhere may make some of these unnecessary

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
// Some string constants
// -----------------------------------------------------------------------------

// For pugi::xml_node_types { node_pcdata, node_cdata, node_comment }
inline const std::string keyword_pcdata  = "body";
inline const std::string keyword_cdata   = "text";
inline const std::string keyword_comment = "comment";

// Aliases
inline const std::string &keyword_body = keyword_pcdata;
inline const std::string &keyword_text = keyword_cdata;



// -----------------------------------------------------------------------------
// Utility constructs
// The functions here could possibly go into the detail namespace, but could
// arguably be useful, in their own right, to users. So, I'll leave them out
// in the overall project namespace (which enclosed the #include of this file).
// -----------------------------------------------------------------------------

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
