
// -----------------------------------------------------------------------------
// Miscellaneous macros, variables, enums, etc.
// -----------------------------------------------------------------------------

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

// find
enum class find {
   one,
   all
};

// default_*
// fixme Describe what these are about
namespace detail {
   // bool
   inline bool default_bool = false;
   inline bool sent(const bool &found)
   {
      return &found != &default_bool;
   }

   // string
   inline std::string default_string = "";
   inline bool sent(const std::string &string)
   {
      return &string != &default_string;
   }
}



// -----------------------------------------------------------------------------
// Forward declarations: some classes
// These are needed for the upcoming forward declarations of convert().
// -----------------------------------------------------------------------------

#define GNDSTK_DEFAULT_CONTAINER std::vector

// Node, node
template<
   template<class...> class = GNDSTK_DEFAULT_CONTAINER,
   template<class...> class = GNDSTK_DEFAULT_CONTAINER
>
class Node;
using node = Node<>;

// Tree, tree
template<
   template<class...> class = GNDSTK_DEFAULT_CONTAINER,
   template<class...> class = GNDSTK_DEFAULT_CONTAINER
>
class Tree;
using tree = Tree<>;

// XML, JSON
class XML;
class JSON;



// -----------------------------------------------------------------------------
// Forward declarations: convert
// We're not fans of having lots of forward declarations, but these are here
// because (1) the relevant classes (Tree, XML, JSON) use these functions in,
// e.g., their constructors, which are defined in-class; and (2) the convert()
// functions in turn work with the classes and thus need the class definitions
// to be available. The alternative would be to mostly define the classes, but
// only declare their constructors; then define the convert()s; then finally
// define the constructors. We think the forward declarations are clearer.
// -----------------------------------------------------------------------------

// convert
//
// ...Tree to Tree
// ...Tree to XML
// ...Tree to JSON
//
// ...XML  to Tree
// ...XML  to XML
// ...XML  to JSON
//
// ...JSON to Tree
// ...JSON to XML
// ...JSON to JSON


// Tree to {Tree,XML,JSON}
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &,
   GNDStk::Tree<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO> &
);

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &,
   GNDStk::XML &
);

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &,
   GNDStk::JSON &
);


// XML to {Tree,XML,JSON}
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::XML &,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &
);
bool convert(const GNDStk::XML &, GNDStk::XML &);
bool convert(const GNDStk::XML &, GNDStk::JSON &);


// JSON to {Tree,XML,JSON}
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::JSON &,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &
);
bool convert(const GNDStk::JSON &, GNDStk::XML &);
bool convert(const GNDStk::JSON &, GNDStk::JSON &);



// -----------------------------------------------------------------------------
// Some string constants
// -----------------------------------------------------------------------------

namespace detail {

// These correspond to the enum pugi::xml_node_type
// values { node_cdata, node_pcdata, node_comment }
inline const std::string keyword_cdata   = "cdata";
inline const std::string keyword_pcdata  = "pcdata";
inline const std::string keyword_comment = "comment";

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

// nocasecmp
// Case-insensitive string comparison.
// The old C-language strcasecmp() is nonstandard. A modern, true caseless
// string comparison is actually a tougher nut to crack than meets the eye,
// but the following will suffice for our English-language purposes.
inline bool nocasecmp(const std::string &one, const std::string &two)
{
   return std::equal(
      one.begin(), one.end(),
      two.begin(), two.end(),
      [](const char a, const char b) { return tolower(a) == tolower(b); }
   );
}



// -----------------------------------------------------------------------------
// Re: file extensions
// -----------------------------------------------------------------------------

// has filename extension?
inline bool has_extension(const std::string &str)
{
   return str.find('.') != std::string::npos;
}

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



// -----------------------------------------------------------------------------
// Re: file type indicators
// These are used in places where we're allowing a user to give a string,
// e.g. "xml", in place of a format specifier ala enum class format.
// -----------------------------------------------------------------------------

// null
// Goofy, perhaps, but we'd like to be consistent with enum class format
inline bool eq_null(const std::string &str)
{
   return
      nocasecmp(str,"null") or
      str == "";
}

// tree
inline bool eq_tree(const std::string &str)
{
   return
      nocasecmp(str,"tree");
}

// xml
inline bool eq_xml(const std::string &str)
{
   return
      nocasecmp(str,"xml");
}

// json
inline bool eq_json(const std::string &str)
{
   return
      nocasecmp(str,"json");
}

// hdf5
inline bool eq_hdf5(const std::string &str)
{
   return
      nocasecmp(str,"hdf" ) or
      nocasecmp(str,"h5"  ) or
      nocasecmp(str,"hdf5") or
      nocasecmp(str,"he5" );
}
