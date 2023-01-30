
namespace detail {

// -----------------------------------------------------------------------------
// isOptional
// -----------------------------------------------------------------------------

// default
template<class T>
struct is_optional {
   static constexpr bool value = false;
};

// optional
template<class T>
struct is_optional<std::optional<T>> {
   static constexpr bool value = true;
};

// GNDStk::Optional
template<class T>
struct is_optional<GNDStk::Optional<T>> {
   static constexpr bool value = true;
};

template<class T>
inline constexpr bool isOptional = is_optional<std::decay_t<T>>::value;



// -----------------------------------------------------------------------------
// remove_opt_def
// -----------------------------------------------------------------------------

// default
template<class T>
struct remove_opt_def {
   using type = T;
};

// std::optional
template<class T>
struct remove_opt_def<std::optional<T>> {
   using type = T;
};

// GNDStk::Optional
template<class T>
struct remove_opt_def<GNDStk::Optional<T>> {
   using type = T;
};

// GNDStk::Defaulted
template<class T>
struct remove_opt_def<Defaulted<T>> {
   using type = T;
};



// -----------------------------------------------------------------------------
// keyname
// -----------------------------------------------------------------------------

// ------------------------
// For Meta
// ------------------------

// Meta<TYPE>
template<class TYPE, class CONVERTER>
std::string keyname(
   const Meta<TYPE,CONVERTER> &m
) {
   return "Meta(\"" + m.name + "\")";
}

// Meta<std::optional<TYPE>>
template<class TYPE, class CONVERTER>
std::string keyname(
   const Meta<std::optional<TYPE>,CONVERTER> &m
) {
   return "optional Meta(\"" + m.name + "\")";
}

// Meta<GNDStk::Optional<TYPE>>
template<class TYPE, class CONVERTER>
std::string keyname(
   const Meta<GNDStk::Optional<TYPE>,CONVERTER> &m
) {
   return "optional Meta(\"" + m.name + "\")";
}

// Meta<Defaulted<TYPE>>
template<class TYPE, class CONVERTER>
std::string keyname(
   const Meta<Defaulted<TYPE>,CONVERTER> &m
) {
   return "optional-with-default Meta(\"" + m.name + "\")";
}


// ------------------------
// For Child
// ------------------------

// Child<TYPE>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::string keyname(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &c
) {
   return "Child(\"" + c.name + "\")";
}

// Child<std::optional<TYPE>>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::string keyname(
   const Child<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &c
) {
   return "optional Child(\"" + c.name + "\")";
}

// Child<GNDStk::Optional<TYPE>>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::string keyname(
   const Child<GNDStk::Optional<TYPE>,ALLOW,CONVERTER,FILTER> &c
) {
   return "optional Child(\"" + c.name + "\")";
}

// Child<Defaulted<TYPE>>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::string keyname(
   const Child<Defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &c
) {
   return "optional-with-default Child(\"" + c.name + "\")";
}


// ------------------------
// For string, regex
// ------------------------

// string
inline std::string keyname(const std::string &s)
{
   return "string(\"" + s + "\")";
}

// regex
inline std::string keyname(const std::regex &)
{
   // regex generally doesn't keep the initialization string around
   return "regex";
}


// ------------------------
// For pair<Child,string/regex>
// ------------------------

// pair<Child,string>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::string keyname(
   const std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::string> &p
) {
   return "pair(" + keyname(p.first) + "," + keyname(p.second) + ")";
}

// pair<Child,regex>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::string keyname(
   const std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,std::regex> &p
) {
   return "pair(" + keyname(p.first) + "," + keyname(p.second) + ")";
}



// -----------------------------------------------------------------------------
// CallOpChildAssertion
// -----------------------------------------------------------------------------

template<Allow ALLOW>
class CallOpChildAssertion {
   // Here's what we really want the static_assert to say:
   //
   //    Misuse of Child with <Allow::many> in Node's call operator.
   //    A Child object with Allow::many can only be used in Node's operator():
   //      - at the end; or
   //      - followed by a std::string or char* label; or
   //      - followed by a std::regex for match with label.
   //    Quick fix: downgrade to Allow::one using predecrement: --Child
   //
   // It seems that a static_assert string's formatting (say, with \n)
   // is not necessarily respected by the compiler. Under the circumstances,
   // we judge that a brief message is best for now.

   static_assert(
      ALLOW == Allow::one,
     "Misuse of Child with <Allow::many> in Node's call operator"
   );
};



// -----------------------------------------------------------------------------
// instrument
// Sort of a hack, for some code instrumentation that can help someone with
// evaluating specs that they might write for the GNDStk Code Generator.
// -----------------------------------------------------------------------------

struct instrument {
#ifdef GNDSTK_INSTRUMENT
   static inline bool on = false;

   // for children
   template<class NODE>
   static void mark(const NODE &node)
   {
      if (on)
         node.marked = true;
   }

   // for metadata
   static void mark(const std::string &str)
   {
      if (on)
         const_cast<std::string &>(str) = "marked-" + str;
   }
#else
   static void mark(const Node &) { /* nothing */ }
   static void mark(const std::string &) { /* nothing */ }
#endif
};



// -----------------------------------------------------------------------------
// apply_converter
// -----------------------------------------------------------------------------

// apply_converter<TYPE>
template<class TYPE>
class apply_converter {
public:
   template<class KEYWORD>
   void operator()(const KEYWORD &kwd, const Node &node) const
   {
      // fixme 2022-10-27. I visited this function while looking at other
      // issues, but now wonder: what's the effect of this function supposed
      // to be? We create obj, then convert node ==> obj, then do nothing
      // with obj. Am I missing something, and/or not testing something that
      // should be tested? -MFS
      // Update, 2023-01-23. I again ran across this function, and the above
      // note, while working on something else. I think that the action here
      // is legit. We call here after tests like [if (kwd.name == "")]. That
      // empty string (I should probably include "#self" too, right?) is the
      // indicator that means, "stay at the current node." Where this is
      // called, we have [KEYWORDS &&...keywords] after the current thing
      // we're processing - the thing that had "" and sent us here. I think
      // the idea was to allow someone to create a side effect (e.g., printing
      // information like a "dictionary of the present node") by triggering
      // a call to some custom converter here. The custom converter would
      // be the function performing the side effect. So, this is all legit.
      // But I really should document it carefully and understandably here.
      // For #self, search for [kwd.name == ""] in general. Also // ""
      static TYPE obj;
      detail::instrument::mark(node);
      kwd.converter(node,obj);
   }
};

// apply_converter<void>
template<>
class apply_converter<void> {
public:
   template<class KEYWORD>
   void operator()(const KEYWORD &, const Node &) const
   {
      // no action
   }
};



// -----------------------------------------------------------------------------
// label_is*
// -----------------------------------------------------------------------------

// label_is
class label_is {
   std::string want;

public:
   explicit label_is(const std::string &str) : want(str) { }

   template<class NODE>
   bool operator()(const NODE &n) const
   {
      bool found;

      // In Node n, look for the value associated
      // with the metadata key called "label"
      const std::string &label = n.meta("label",found);

      // If label is found and has the value we want,
      // or label is not found but the value we want
      // is given as the empty string "", then return
      // true. Otherwise, return false.
      return found ? label == want : want == "";

      // Note: cases of label == "" actually happen.
      // Here's an example, from dec-094_Pu_235.xml:
      //    <double label="" value="5951400.0" unit="eV"/>
      // In this case, a query like:
      //    node(Double,"")
      // will thus succeed (found, and label == want).
      // It would also have succeeded if label wasn't
      // there (!found, but want == "").
   }
};

// label_is_regex
// Like label_is, but with a regex match. A regex match is *not* our default
// behavior in the functions users will typically call for making queries
// like "find a Node with label == something." We made this choice because
// we noticed that actual, specific GNDS labels - what users will usually
// want to provide - often contain characters like '+' that have a special
// meaning in regular expressions! Interpreted as regular expressions rather
// than as ordinary strings, such GNDS labels will most likely be ill-formed,
// and this can trigger exceptions in C++'s regex-related functions. We want
// to provide a regex capability, however, for users who really wish to use
// it. Hence this class, and the functions in which it's used.
class label_is_regex {
   std::regex want;

public:
   explicit label_is_regex(const std::regex &reg) : want(reg) { }

   template<class NODE>
   bool operator()(const NODE &n) const
   {
      bool found;
      const std::string &label = n.meta("label",found);
      return found && std::regex_match(label,want);
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
// MetaRef
// For operator[](Meta<TYPE>)
// Note: operator[](Meta<void>) doesn't use MetaRef
// -----------------------------------------------------------------------------

/*
These make use of SFINAE in three ways: (1) To handle constness, or lack of
constness, of the Node that comes to the constructor. (2) To disable assignment
if the associated Node is const. (3) To fold the two assignments (if applicable)
and the two conversions into one apiece, in the unusual but possible case that
the Meta's TYPE is std::string. (1) and (2) could have been achieved by having
two classes - say, MetaRef and MetaRefConst - but the SFINAE scheme reduces
code repetition.

Remark with regards to TYPE == std::string. Metadata are stored as std::strings
in our raw data structures. Normally, one uses Meta<TYPE = void> to retrieve
metadata in their raw form. In that case, our various accessors return const
or non-const std::string &. For types other than <void>, Meta converts the raw
string to the given type, and the accessors return by value. That non-void type
could, however, be std::string itself, if, for whatever reason, you don't want
to use <void> and receive references to the raw internal strings. You might use
std::string, for example, if you wished to use a custom std::string to/from
std::string converter other than the identity function.

Class MetaRef has assignment from TYPE and from std::string, and similarly for
conversion. When TYPE *is* std::string, we use SFINAE to disable the std::string
functions - which would otherwise have duplicate signatures to those of the TYPE
functions. Thus, we cause the general TYPE functions to apply. The std::string
functions are disabled, not the TYPE functions, so that the converter is still
applied. (Especially considering that you'd likely be using Meta<std::string>,
in place of Meta<void>, precisely so that you can use a non-identity string to
string conversion.)
*/

template<
   class NODE, bool CONST, // Node type, and its constness status
   class TYPE, class CONVERTER // for the Meta
>
class MetaRef {

   const Meta<TYPE,CONVERTER> kwd;

   // [const] std::string reference to the actual, in-Node metadatum value
   std::conditional_t<
      CONST,
      const std::string,
      std::string
   > &metaValueRef;

public:

   // ------------------------
   // constructor
   // ------------------------

   MetaRef(
      const Meta<TYPE,CONVERTER> &kwd,
      std::conditional_t<CONST, const NODE, NODE> &parent
   ) :
      kwd(kwd), // original Meta
      metaValueRef(parent(-kwd)) // -kwd so Meta<void>; reference to raw
   { }

   // ------------------------
   // assignment, except both
   // disabled if CONST==true
   // ------------------------

   // = TYPE
   template<bool CONSTANT = CONST>
   std::enable_if_t<
     !CONSTANT,
      MetaRef
   > &operator=(const TYPE &obj)
   {
      kwd.converter(obj,metaValueRef="");
      return *this;
   }

   // = std::string
   // if std::string != TYPE
   template<bool CONSTANT = CONST, class T = TYPE>
   std::enable_if_t<
     !CONSTANT && !std::is_same_v<T,std::string>,
      MetaRef
   > &operator=(const std::string &s)
   {
      metaValueRef = s;
      return *this;
   }

   // ------------------------
   // conversion
   // ------------------------

   // to TYPE
   operator TYPE() const
   {
      static TYPE obj{};
      kwd.converter(metaValueRef,obj);
      return obj;
   }

   // to std::string
   // if std::string != TYPE
   template<class T = TYPE>
   operator std::enable_if_t<
     !std::is_same_v<T,std::string>,
      std::string
   >() const
   {
      return metaValueRef;
   }
}; // class MetaRef



// -----------------------------------------------------------------------------
// ChildRef
// The default does nothing; see the Allow::one and Allow::many specializations.
// -----------------------------------------------------------------------------

template<
   class NODE, bool CONST,
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER
>
class ChildRef {
   // nothing
};



// -----------------------------------------------------------------------------
// ChildRef
// For operator[](Child<TYPE,one>)
// Note: operator[](Child<void,one>) doesn't use ChildRef
// -----------------------------------------------------------------------------

template<
   class NODE, bool CONST, // Node type, and its constness status
   class TYPE, class CONVERTER, class FILTER // for the Child
>
class ChildRef<NODE,CONST,TYPE,Allow::one,CONVERTER,FILTER>
{
   const Child<TYPE,Allow::one,CONVERTER,FILTER> kwd;

   // [const] Node reference to the actual Node
   std::conditional_t<
      CONST,
      const NODE,
      NODE
   > &childNodeRef;

public:

   // ------------------------
   // constructor
   // ------------------------

   ChildRef(
      const Child<TYPE,Allow::one,CONVERTER,FILTER> &kwd,
      std::conditional_t<CONST, const NODE, NODE> &parent
   ) :
      kwd(kwd), // original Child
      childNodeRef(parent(-kwd)) // -kwd so Child<void>; reference to raw
   { }

   // ------------------------
   // assignment; except both
   // disabled if CONST==true
   // ------------------------

   // = TYPE
   template<bool CONSTANT = CONST>
   std::enable_if_t<
     !CONSTANT,
      ChildRef
   > &operator=(const TYPE &obj)
   {
      kwd.converter(obj,childNodeRef.clear());
      return *this;
   }

   // = NODE (as in ChildRef's template argument called NODE)
   // if NODE != TYPE
   template<bool CONSTANT = CONST, class T = TYPE>
   std::enable_if_t<
     !CONSTANT && !std::is_same_v<T,NODE>,
      ChildRef
   > &operator=(const NODE &n)
   {
      childNodeRef = n;
      return *this;
   }

   // ------------------------
   // conversion
   // ------------------------

   // to TYPE
   operator TYPE() const
   {
      static TYPE obj{};
      kwd.converter(childNodeRef,obj);
      return obj;
   }

   // to NODE() (as in ChildRef's template argument called NODE)
   // if NODE != TYPE
   template<class T = TYPE>
   operator std::enable_if_t<
     !std::is_same_v<T,NODE>,
      NODE
   >() const
   {
      return childNodeRef;
   }
}; // class ChildRef



// -----------------------------------------------------------------------------
// ChildRef
// For operator[](Child<TYPE,many>)
// Note: works - and indeed is used - when TYPE == void.
// -----------------------------------------------------------------------------

template<
   class NODE, bool CONST, // Node type, and its constness status
   class TYPE, class CONVERTER, class FILTER // for the Child
>
class ChildRef<NODE,CONST,TYPE,Allow::many,CONVERTER,FILTER>
{
   const Child<TYPE,Allow::many,CONVERTER,FILTER> kwd;

   // vector of [const] Node pointers to the actual Nodes
   std::vector<
      std::conditional_t<
         CONST,
         const NODE,
         NODE
      > *
   > childNodePtr;

public:

   // ------------------------
   // constructor
   // ------------------------

   ChildRef(
      const Child<TYPE,Allow::many,CONVERTER,FILTER> &kwd,
      std::conditional_t<CONST, const NODE, NODE> &parent
   ) :
      kwd(kwd) // original Child
   {
      // resembles the Node.many() code, but
      // here we create a vector of pointers
      try {
         if (kwd.name == "")
            childNodePtr.push_back(&parent);
         else {
            const std::regex regex(kwd.name);
            for (auto &c : parent.children)
               if (std::regex_match(c->name, regex) && kwd.filter(*c))
                  childNodePtr.push_back(&(*c));
         }
      } catch (...) {
         log::ctor("ChildRef<Allow::many>" + detail::keyname(kwd));
         throw;
      }
   }

   // ------------------------
   // miscellaneous functions
   // ------------------------

   // size
   std::size_t size() const
   {
      return childNodePtr.size();
   }

   // operator[]
   decltype(auto) operator[](const std::size_t n) const
   {
      if constexpr (std::is_same_v<TYPE,void>) {
         // For TYPE == void
         // Returns: [const] NODE &
         return *childNodePtr[n];
      } else {
         // For TYPE != void
         // Leverage the capabilities of the Allow::one ChildRef
         return ChildRef<NODE,CONST,TYPE,Allow::one,CONVERTER,FILTER>(
            // As always, -- downgrades many to one. The /"" changes the lookup
            // name to "", which means "use the current Node" (in this case the
            // Node *childNodePtr[n]), which is appropriate here because we're
            // not digging further into the node; we're making the [n] element
            // of the current "smart object" usable as its own smart object.
            --kwd/"",
            *childNodePtr[n]
         );
      }
   }

   // ------------------------
   // assignment
   // ------------------------

   // ChildRef for Allow::many Child objects, as opposed to ChildRef for
   // Allow::one Child objects, has no assignment operators. Presumably,
   // an assignment operator's purpose in this case would be to allow someone
   // to remake the entire set of the (generally many) child nodes to which
   // we're pointing in our childNodePtr vector of pointers to nodes. Such an
   // action, however, should be done by others means, and through the parent
   // node (in which case the current class isn't involved anyway). Besides,
   // it isn't clear what sorts of "remake" we'd want to allow. Element-by-
   // element replacement of the pointed-to nodes with an equal number of new
   // ones? A different number of new ones? Something else?

   // ------------------------
   // conversion
   // ------------------------

   // The SFINAE is such that we'll have conversion operators as follows:
   //
   // if TYPE == most things:
   //    operator vector<NODE>()
   //    operator vector<TYPE>() (converter is applied)
   //
   // if TYPE == void:
   //    operator vector<NODE>()
   //
   // if TYPE == NODE:
   //    operator vector<TYPE>() (TYPE *is* NODE, but converter is applied)
   //
   // Remember, NODE is the version of Node with which we instantiated
   // this ChildRef.
   //
   // The case of TYPE == NODE is analogous to the case of TYPE == std::string
   // for the MetaRef class. See the discussion above the code for that class.

   // to vector<TYPE>
   template<class T = TYPE>
   operator std::vector<
      std::enable_if_t<
        !std::is_same_v<T,void>,
         TYPE
      >
   >() const
   {
      std::vector<TYPE> vec;
      vec.reserve(size());
      for (auto &elem : childNodePtr) {
         static TYPE obj{};
         kwd.converter(*elem,obj);
         vec.push_back(obj);
      }
      return vec;
   }

   // to vector<NODE>
   template<class T = TYPE>
   operator std::vector<
      std::enable_if_t<
        !std::is_same_v<T,NODE>, // <== includes TYPE == void
         NODE
      >
   >() const
   {
      std::vector<NODE> vec;
      vec.reserve(size());
      for (auto &elem : childNodePtr)
         vec.push_back(*elem);
      return vec;
   }
}; // class ChildRef



// -----------------------------------------------------------------------------
// Helpers for code related to Node I/O
// -----------------------------------------------------------------------------

// warning_io_name
inline void warning_io_name(
   const std::string &op,
   const std::string &fileformat,
   const std::string &filename,
   const std::string &name
) {
   log::warning(
      "Node.{}() called with format FileType::{} and filename \"{}\",\n"
      "but the filename extension does not appear to be one for {}",
      op, fileformat, filename, name
   );
}

// warning_io_data
inline void warning_io_data(
   const FileType f,
   const std::string &appears
) {
   log::warning(
      "Node.read() was called with {}, but the first character\n"
      "in the file suggests perhaps {}. Trying {} anyway...",
      printFormat(f), appears, printFormat(f)
   );
}

// error_format_read
inline const std::string error_format_read =
   "FileType::debug not allowed in Node.read(). "
   "Our \"debug\" file format is intended "
   "for debug writing, not for reading. "
   "Consider FileType:: xml, json, or hdf5"
;

// getDecl
template<class NODE>
bool getDecl(const NODE &node, const bool &decl)
{
   return sent(decl) ? decl : node.name == "/";
}



// -----------------------------------------------------------------------------
// name_split
// Helper for certain queries that involve std::variant
// -----------------------------------------------------------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto name_split(const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   // split kwd.name into whitespace-separated tokens
   std::string s;
   std::vector<std::string> names;
   std::istringstream iss(kwd.name);
   while (iss >> s)
      names.push_back(s);

   // consistency check: the number of extracted tokens
   // should equal the number of alternatives in the variant
   if (names.size() != std::variant_size_v<TYPE>) {
      log::error(
         "The number of tokens in the Child<std::variant<...>>'s name,\n"
         "   \"{}\"\n"
         "is {}, but the number of alternatives in the variant is {}.\n"
         "Those two numbers must equal one another.",
         kwd.name, names.size(), std::variant_size_v<TYPE>
      );
      throw std::exception{};
   }

   // done
   return names;
}



// -----------------------------------------------------------------------------
// keys2outputs
// -----------------------------------------------------------------------------

template<class NODE, class T>
struct keys2outputs;

template<class NODE, class... Ks>
struct keys2outputs<NODE,std::tuple<Ks...>>
{
   using type = std::tuple<
      decltype(NODE{}.operator()(std::declval<Ks>()))...
   >;
};

} // namespace detail
