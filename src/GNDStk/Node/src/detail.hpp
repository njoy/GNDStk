
namespace detail {

// node2Node: forward declaration
// This function is called by some of Node's assignment operators. We'd instead
// put this forward declaration into the file in which *those* are defined, but
// that file is #included inside class Node { ... }'s definition, where writing
// the forward declaration wouldn't make sense.
template<class NODEFROM, class NODETO>
void node2Node(const NODEFROM &, NODETO &);



// -----------------------------------------------------------------------------
// apply_converter
// -----------------------------------------------------------------------------

// apply_converter<TYPE>
template<class TYPE>
class apply_converter {
public:
   template<class KEYWORD, class NODE>
   void operator()(const KEYWORD &kwd, const NODE &node) const
   {
      TYPE type{};
      kwd.converter(node,type);
   }
};

// apply_converter<void>
template<>
class apply_converter<void> {
public:
   template<class KEYWORD, class NODE>
   void operator()(const KEYWORD &, const NODE &) const
   {
      // no action
   }
};



// -----------------------------------------------------------------------------
// label_is
// -----------------------------------------------------------------------------

class label_is {
   std::string want;

public:
   explicit label_is(const std::string &str) : want(str) { }

   template<class NODE>
   bool operator()(const NODE &n) const
   {
      bool found;

      // In node n, look for the value associated
      // with the metadata key called "label"
      const std::string &label = n.meta("label",found);

      // If it's found, AND has the value we want,
      // then return true; otherwise return false
      return found && label == want;
   }
};



// -----------------------------------------------------------------------------
// extract_found
// -----------------------------------------------------------------------------

inline bool &extract_found(bool &found)
{
   return found;
}

template<class T>
inline bool &extract_found(const T &)
{
   return default_bool;
}

template<class T, class... ARGS>
inline bool &extract_found(const T &, ARGS &&...args)
{
   return extract_found(std::forward<ARGS>(args)...);
}



// -----------------------------------------------------------------------------
// meta_ref
// -----------------------------------------------------------------------------

/*
Note that these make use of SFINAE as described here:

   https://stackoverflow.com/questions/27433093

in three ways. (1) To handle const-ness or lack thereof of the node that comes
to the constructor. (2) To disable the assignment operators if the associated
node is const. (3) To fold the two assignments (if applicable re: const) and
the two conversions into one apiece, in the unusual but possible case of the
meta_t's TYPE being std::string. (1) and (2), at least, could have been achieved
by having two classes - say, meta_ref and meta_ref_const - but the SFINAE scheme
reduces code repetition, if perhaps at the cost of some slight obfuscation.

Remark with regards to TYPE == std::string. Metadata are stored as std::strings
in our raw data structures. Normally, one uses meta_t<TYPE = void> to retrieve
metadata in their raw form; in that case, our various accessors return const or
non-const std::string &. For types other than <void>, meta_t converts the raw
string to the given type, and the accessors return by value. That non-void type
COULD by std::string, if, for whatever reason, you don't want to use <void> and
receive references to the raw internal strings. You might use <std::string>, for
example, if you wanted a custom std::string to/from std::string converter other
than the identity function.

Class meta_ref has assignment from TYPE and from std::string, and similarly for
conversion. When TYPE *is* std::string, we use SFINAE to disable the std::string
versions - which would have duplicate signatures to those of the TYPE versions
in that case, and thus cause the general TYPE versions to apply. The std::string
versions are disabled, not the TYPE versions, so that the converter is still
applied. (Especially considering that you'd likely be using meta_t<std::string>
over meta_t<void> precisely to get a non-identity string/string converter.)
*/

template<
   class NODE, bool CONST,
   class TYPE, class CONVERTER
>
class meta_ref {

   // data
   const meta_t<TYPE,CONVERTER> kwd;
   typename std::conditional<
      CONST,
      const std::string,
      std::string
   >::type &metaValueString;

public:

   // constructor
   meta_ref(
      const meta_t<TYPE,CONVERTER> &kwd,
      typename std::conditional<CONST, const NODE, NODE>::type &node
   ) :
      kwd(kwd), metaValueString(node(-kwd))
   { }

   // ------------------------
   // assignment, except both
   // disabled if CONST==true
   // ------------------------

   template<bool CONSTANT = CONST>
   typename std::enable_if<
     !CONSTANT,
      meta_ref
   >::type &operator=(const TYPE &obj)
   {
      kwd.converter(obj,metaValueString);
      return *this;
   }

   // if TYPE != std::string
   template<bool CONSTANT = CONST, class T = TYPE>
   typename std::enable_if<
     !CONSTANT && !std::is_same<T,std::string>::value,
      meta_ref
   >::type &operator=(const std::string &s)
   {
      metaValueString = s;
      return *this;
   }

   // ------------------------
   // conversion
   // ------------------------

   operator TYPE() const
   {
      TYPE obj;
      kwd.converter(metaValueString,obj);
      return obj;
   }

   // if  TYPE != std::string
   template<class T = TYPE>
   operator typename std::enable_if<
     !std::is_same<T,std::string>::value,
      std::string
   >::type() const
   {
      return metaValueString;
   }
};



// -----------------------------------------------------------------------------
// child_ref
// allow::one
// -----------------------------------------------------------------------------

// Similar comments apply to those regarding meta_ref.

// Default == the allow::one case; we'll specialize for allow::many
template<
   class NODE, bool CONST,
   class TYPE, allow ALLOW, class CONVERTER, class FILTER
>
class child_ref {

   // data
   const child_t<TYPE,allow::one,CONVERTER,FILTER> kwd;
   typename std::conditional<
      CONST,
      const NODE,
      NODE
   >::type &childNodeRef;

public:

   // constructor
   child_ref(
      const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd,
      typename std::conditional<CONST, const NODE, NODE>::type &node
   ) :
      kwd(kwd), childNodeRef(node(-kwd))
   { }

   // ------------------------
   // assignment; except both
   // disabled if CONST==true
   // ------------------------

   template<bool CONSTANT = CONST>
   typename std::enable_if<
     !CONSTANT,
      child_ref
   >::type &operator=(const TYPE &obj)
   {
      kwd.converter(obj,childNodeRef);
      return *this;
   }

   // if TYPE != NODE
   template<bool CONSTANT = CONST, class T = TYPE>
   typename std::enable_if<
     !CONSTANT && !std::is_same<T,NODE>::value,
      child_ref
   >::type &operator=(const NODE &n)
   {
      childNodeRef = n;
      return *this;
   }

   // ------------------------
   // conversion
   // ------------------------

   operator TYPE() const
   {
      TYPE obj;
      kwd.converter(childNodeRef,obj);
      return obj;
   }

   // if TYPE != NODE
   template<class T = TYPE>
   operator typename std::enable_if<
     !std::is_same<T,NODE>::value,
      NODE
   >::type() const
   {
      return childNodeRef;
   }
};



// -----------------------------------------------------------------------------
// child_ref
// allow::many
// -----------------------------------------------------------------------------

template<
   class NODE, bool CONST,
   class TYPE, class CONVERTER, class FILTER
>
class child_ref<NODE,CONST,TYPE,allow::many,CONVERTER,FILTER> {
   // Unused for now
};

} // namespace detail
