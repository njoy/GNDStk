
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
   null, // default, automagick, etc.
   tree, // our own simple text format
   xml,
   json,
   hdf5
};

// dummy
// Empty class. We use this here and there, in places where a class is needed
// but isn't relevant in and of itself. E.g., we have a function, and in order
// for it to work properly in a header-only library, it must be either inline
// or templated. If, for whatever reason, we don't want to make it inline,
// then we can make it a function template, and use <dummy>. We could use,
// say, <char> instead, but <dummy> may help us identify these use cases.
class dummy { };



// -----------------------------------------------------------------------------
// Forward declarations: general
// -----------------------------------------------------------------------------

// fixme Some reorganization elsewhere may make some of these unnecessary

// Node, node
template<
   template<class...> class,
   template<class...> class
>
class Node;
using node = Node<std::vector,std::vector>;

// Tree, tree
template<
   template<class...> class = std::vector,
   template<class...> class = std::vector
>
class Tree;
using tree = Tree<>;

// xml, json
class xml;
class json;

// tnode
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER,
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
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
bool convert(
   const gnds::Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &,
   gnds::Tree<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO> &
);

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const gnds::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &,
   gnds::xml &
);

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const gnds::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &,
   gnds::json &
);


// xml to {Tree,xml,json}
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const gnds::xml &,
   gnds::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &
);
bool convert(const gnds::xml &, gnds::xml &);
bool convert(const gnds::xml &, gnds::json &);


// json to {Tree,xml,json}
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const gnds::json &,
   gnds::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &
);
bool convert(const gnds::json &, gnds::xml &);
bool convert(const gnds::json &, gnds::json &);



// -----------------------------------------------------------------------------
// Some string constants
// -----------------------------------------------------------------------------

namespace detail {

// For pugi::xml_node_types { node_pcdata, node_cdata, node_comment }
inline const std::string keyword_pcdata  = "body";
inline const std::string keyword_cdata   = "text";
inline const std::string keyword_comment = "comment";

// Aliases
inline const std::string &keyword_body = keyword_pcdata;
inline const std::string &keyword_text = keyword_cdata;

} // namespace detail



// -----------------------------------------------------------------------------
// Utility constructs
// The functions here could possibly go into the detail namespace, but could
// arguably be useful, in their own right, to users. So, I'll leave them out
// in the overall project namespace (which enclosed the #include of this file).
// -----------------------------------------------------------------------------

// filesize(string)
inline std::ifstream::pos_type filesize(const std::string &file)
{
   std::ifstream ifs(file.c_str(), std::ifstream::ate | std::ifstream::binary);
   return ifs.tellg();
}

// endsin
// C++20 will have an ends_with(); for now we'll have this
inline bool endsin(const std::string &str, const std::string &end)
{
   return str.size() >= end.size() and &str[str.size()-end.size()] == end;
}



// -----------------------------------------------------------------------------
// Re: file extensions
// -----------------------------------------------------------------------------

// xml
inline bool endsin_xml(const std::string &str)
{
   return
      endsin(str,".xml" ) or
      endsin(str,".XML" );
}

// json
inline bool endsin_json(const std::string &str)
{
   return
      endsin(str,".json") or
      endsin(str,".JSON");
}

// hdf5
inline bool endsin_hdf5(const std::string &str)
{
   return
      endsin(str,".hdf" ) or
      endsin(str,".HDF" ) or
      endsin(str,".h5"  ) or
      endsin(str,".H5"  ) or
      endsin(str,".hdf5") or
      endsin(str,".HDF5") or
      endsin(str,".he5" ) or
      endsin(str,".HE5" );
}

// has filename extension?
inline bool has_extension(const std::string &str)
{
   return str.find('.') != std::string::npos;
}
