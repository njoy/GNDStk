
namespace detail {

// node2Node: forward declaration
// This function is called by some of Node's assignment operators. We'd instead
// put this forward declaration into the file in which *those* are defined, but
// that file is #included inside class Node { ... }'s definition, where writing
// the forward declaration wouldn't make sense.
template<class NODEFROM, class NODETO>
void node2Node(const NODEFROM &, NODETO &);



// -----------------------------------------------------------------------------
// is_optional
// -----------------------------------------------------------------------------

// default
template<class T>
class is_optional {
public:
   static constexpr bool value = false;
};

// optional
template<class T>
class is_optional<std::optional<T>> {
public:
   static constexpr bool value = true;
};



// -----------------------------------------------------------------------------
// remove_optional
// -----------------------------------------------------------------------------

// default
template<class T>
class remove_optional {
public:
   using type = T;
};

// optional
template<class T>
class remove_optional<std::optional<T>> {
public:
   using type = T;
};



// -----------------------------------------------------------------------------
// keyname
// -----------------------------------------------------------------------------

// meta_t<TYPE>
template<class TYPE, class CONVERTER>
std::string keyname(
   const meta_t<TYPE,CONVERTER> &m
) {
   return "meta_t(\"" + m.name + "\")";
}

// meta_t<optional<TYPE>>
template<class TYPE, class CONVERTER>
std::string keyname(
   const meta_t<std::optional<TYPE>,CONVERTER> &m
) {
   return "optional meta_t(\"" + m.name + "\")";
}

// child_t<TYPE>
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
std::string keyname(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &c
) {
   return "child_t(\"" + c.name + "\")";
}

// child_t<optional<TYPE>>
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
std::string keyname(
   const child_t<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &c
) {
   return "optional child_t(\"" + c.name + "\")";
}

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



// -----------------------------------------------------------------------------
// call_operator_child_t
// -----------------------------------------------------------------------------

template<allow ALLOW>
class call_operator_child_t {
   // Here's what we really want the static_assert to say:
   //
   //    Misuse of child_t with <allow::many> in Node's call operator.
   //    Child_t with allow::many can only be used in Node's operator():
   //      - at the end; or
   //      - followed by a std::string or char* label; or
   //      - followed by a std::regex for match with label.
   //    Quick fix: downgrade to allow::one using predecrement: --child_t
   //
   // It seems that a static_assert string's formatting (say, with \n)
   // is not necessarily respected by the compiler. Under the cirsumstances,
   // we judge that a more-succint message is best.

   static_assert(
      ALLOW == allow::one,
     "Misuse of child_t with <allow::many> in Node's call operator"
   );
};



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

      // In node n, look for the value associated
      // with the metadata key called "label"
      const std::string &label = n.meta("label",found);

      // If it's found, AND has the value we want,
      // then return true; otherwise return false
      return found && label == want;
   }
};

// label_is_regex
// Like label_is, but with a regex match. A regex match is *not* our default
// behavior in the functions users will typically call for making queries
// like "find a node with label == something." We made this choice because
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
      // Here, "label" is the std::string metadatum we just found, and "want",
      // originally coming from a query of some kind, is the regular expression
      // against which to match the label.
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
// meta_ref
// For operator[](meta_t<TYPE>)
// Note: operator[](meta_t<void>) doesn't use meta_ref
// -----------------------------------------------------------------------------

/*
Note that these make use of a particular SFINAE variation as described here:

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
COULD be std::string, if, for whatever reason, you don't want to use <void> and
receive references to the raw internal strings. You might use <std::string>, for
example, if you wanted a custom std::string to/from std::string converter other
than the identity function.

Class meta_ref has assignment from TYPE and from std::string, and similarly for
conversion. When TYPE *is* std::string, we use SFINAE to disable the std::string
versions - which would have duplicate signatures to those of the TYPE versions
in that case. Thus, we cause the general TYPE versions to apply. The std::string
versions are disabled, not the TYPE versions, so that the converter is still
applied. (Especially considering that you'd likely be using meta_t<std::string>
over meta_t<void> precisely to get a non-identity string/string converter.)
*/

template<
   class NODE, bool CONST,
   class TYPE, class CONVERTER
>
class meta_ref {

   const meta_t<TYPE,CONVERTER> kwd;

   // [const] std::string reference to the actual, in-node value
   typename std::conditional<
      CONST,
      const std::string,
      std::string
   >::type &metaValueRef;

public:

   // constructor
   meta_ref(
      const meta_t<TYPE,CONVERTER> &kwd,
      typename std::conditional<CONST, const NODE, NODE>::type &parent
   ) :
      kwd(kwd), // original meta_t
      metaValueRef(parent(-kwd)) // -kwd so meta_t<void> ==> reference to raw
   { }

   // ------------------------
   // assignment, except both
   // disabled if CONST==true
   // ------------------------

   // = TYPE
   template<bool CONSTANT = CONST>
   typename std::enable_if<
     !CONSTANT,
      meta_ref
   >::type &operator=(const TYPE &obj)
   {
      kwd.converter(obj,metaValueRef="");
      return *this;
   }

   // = std::string
   // if std::string is different from TYPE
   template<bool CONSTANT = CONST, class T = TYPE>
   typename std::enable_if<
     !CONSTANT && !std::is_same<T,std::string>::value,
      meta_ref
   >::type &operator=(const std::string &s)
   {
      metaValueRef = s;
      return *this;
   }

   // ------------------------
   // conversion
   // ------------------------

   // to TYPE()
   operator TYPE() const
   {
      TYPE obj{};
      kwd.converter(metaValueRef,obj);
      return obj;
   }

   // to std::string()
   // if std::string is different from TYPE
   template<class T = TYPE>
   operator typename std::enable_if<
     !std::is_same<T,std::string>::value,
      std::string
   >::type() const
   {
      return metaValueRef;
   }
};



// -----------------------------------------------------------------------------
// child_ref
// For operator[](child_t<TYPE,one>)
// Note: operator[](child_t<void,one>) doesn't use child_ref
// -----------------------------------------------------------------------------

// fixme Some consolidation of the child_ref variations may be possible,
// although they're a bit structurally different from one another. Using,
// e.g., an "if constexpr" may make things shorter, but the result may
// or may not be clearer. For now, I'll make this available, and will
// look into the consolidation question another time.

// Default == this case; we'll specialize for others
template<
   class NODE, bool CONST,
   class TYPE, allow ALLOW, class CONVERTER, class FILTER
>
class child_ref {

   const child_t<TYPE,allow::one,CONVERTER,FILTER> kwd;

   // [const] node reference to the actual node
   typename std::conditional<
      CONST,
      const NODE,
      NODE
   >::type &childNodeRef;

public:

   // constructor
   child_ref(
      const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd,
      typename std::conditional<CONST, const NODE, NODE>::type &parent
   ) :
      kwd(kwd), // original child_t
      childNodeRef(parent(-kwd)) // -kwd so child_t<void> ==> reference to raw
   { }

   // ------------------------
   // assignment; except both
   // disabled if CONST==true
   // ------------------------

   // = TYPE
   template<bool CONSTANT = CONST>
   typename std::enable_if<
     !CONSTANT,
      child_ref
   >::type &operator=(const TYPE &obj)
   {
      kwd.converter(obj,childNodeRef.clear());
      return *this;
   }

   // = NODE (as in child_ref's template argument called NODE)
   // if NODE is different from TYPE
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

   // to TYPE()
   operator TYPE() const
   {
      TYPE obj{};
      kwd.converter(childNodeRef,obj);
      return obj;
   }

   // to NODE() (as in child_ref's template argument called NODE)
   // if NODE is different from TYPE
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
// For operator[](child_t<void,many>)
// -----------------------------------------------------------------------------

template<
   class NODE, bool CONST,
   class FILTER
>
class child_ref<
   NODE, CONST,
   void, allow::many, void, FILTER
> {

   // Note: for now (and perhaps forever), we're not providing direct access
   // to our (private) childNodePtr vector. Given the purpose of the present
   // class - the return from Node's operator[](child_t<void,many,...>) - we
   // don't think anyone should be messing with it. Someone who wants to change
   // the number of such child nodes, for example, should do so by other means,
   // and via the parent node.

   // vector of [const] node pointers to the actual nodes
   std::vector<
      typename std::conditional<CONST, const NODE *, NODE *>::type
   > childNodePtr;

public:

   // constructor
   child_ref(
      const child_t<void,allow::many,void,FILTER> &kwd,
      typename std::conditional<CONST, const NODE, NODE>::type &parent
   ) {
      // similar to Node.many(), except here we create a vector of pointers
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
         log::ctor("child_ref<...,void,many,...>" + detail::keyname(kwd));
         throw;
      }
   }

   // size
   std::size_t size() const
   {
      return childNodePtr.size();
   }

   // operator[]
   auto &operator[](const std::size_t n) const
   {
      return *childNodePtr[n];
   }

   // ------------------------
   // conversion
   // ------------------------

   // to vector<NODE>
   operator std::vector<NODE>() const
   {
      std::vector<NODE> vec;
      vec.reserve(size());
      for (auto &elem : childNodePtr)
         vec.push_back(*elem);
      return vec;
   }
};



// -----------------------------------------------------------------------------
// child_ref
// For operator[](child_t<TYPE,many>)
// -----------------------------------------------------------------------------

template<
   class NODE, bool CONST,
   class TYPE, class CONVERTER, class FILTER
>
class child_ref<
   NODE, CONST,
   TYPE, allow::many, CONVERTER, FILTER
> {

   const child_t<TYPE,allow::many,CONVERTER,FILTER> kwd;

   // vector of [const] node pointers to the actual nodes
   std::vector<
      typename std::conditional<CONST, const NODE *, NODE *>::type
   > childNodePtr;

public:

   // constructor
   child_ref(
      const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd,
      typename std::conditional<CONST, const NODE, NODE>::type &parent
   ) :
      kwd(kwd) // original child_t
   {
      // similar to Node.many(), except here we create a vector of pointers
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
         log::ctor("child_ref<...,void,many,...>" + detail::keyname(kwd));
         throw;
      }
   }

   // size
   std::size_t size() const
   {
      return childNodePtr.size();
   }

   // operator[]
   auto operator[](const std::size_t n) const
   {
      // leverage the capabilities of the allow::one child_ref
      return child_ref<
         NODE, CONST,
         TYPE, allow::one, CONVERTER, FILTER
      >(
         // As always, -- downgrades many to one. The /"" changes the lookup
         // name to "", which means "use the current node" (in this case the
         // node *childNodePtr[n]), which is appropriate here because we're
         // not digging further into the tree; we're making the [n] element
         // of the current "smart object" usable as its own smart object.
         --kwd/"",
         *childNodePtr[n]
      );
   }

   // ------------------------
   // conversion
   // ------------------------

   // to vector<TYPE>
   operator std::vector<TYPE>() const
   {
      std::vector<TYPE> vec;
      vec.reserve(size());
      for (auto &elem : childNodePtr) {
         TYPE obj{};
         kwd.converter(*elem,obj);
         vec.push_back(obj);
      }
      return vec;
   }

   // to vector<NODE>
   // if NODE is different from TYPE
   template<class T = TYPE>
   operator std::vector<
      typename std::enable_if<
        !std::is_same<T,NODE>::value,
         NODE
      >::type
   >() const
   {
      std::vector<NODE> vec;
      vec.reserve(size());
      for (auto &elem : childNodePtr)
         vec.push_back(*elem);
      return vec;
   }
};

} // namespace detail
