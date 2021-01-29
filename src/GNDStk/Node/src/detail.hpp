
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
// remove_opt_def
// -----------------------------------------------------------------------------

// default
template<class T>
class remove_opt_def {
public:
   using type = T;
};

// optional
template<class T>
class remove_opt_def<std::optional<T>> {
public:
   using type = T;
};

// Defaulted
template<class T>
class remove_opt_def<Defaulted<T>> {
public:
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

// Meta<optional<TYPE>>
template<class TYPE, class CONVERTER>
std::string keyname(
   const Meta<std::optional<TYPE>,CONVERTER> &m
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

// Child<optional<TYPE>>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::string keyname(
   const Child<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &c
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
// apply_converter
// -----------------------------------------------------------------------------

// apply_converter<TYPE>
template<class TYPE>
class apply_converter {
public:
   template<class KEYWORD, class NODE>
   void operator()(const KEYWORD &kwd, const NODE &node) const
   {
      TYPE obj = kwd.object;
      kwd.converter(node,obj);
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
// For operator[](Meta<TYPE>)
// Note: operator[](Meta<void>) doesn't use meta_ref
// -----------------------------------------------------------------------------

/*
These make use of SFINAE in three ways: (1) To handle constness, or lack of
constness, of the node that comes to the constructor. (2) To disable assignment
if the associated node is const. (3) To fold the two assignments (if applicable)
and the two conversions into one apiece, in the unusual but possible case that
the Meta's TYPE is std::string. (1) and (2) could have been achieved by having
two classes - say, meta_ref and meta_ref_const - but the SFINAE scheme reduces
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

Class meta_ref has assignment from TYPE and from std::string, and similarly for
conversion. When TYPE *is* std::string, we use SFINAE to disable the std::string
functions - which would otherwise have duplicate signatures to those of the TYPE
functions. Thus, we cause the general TYPE functions to apply. The std::string
functions are disabled, not the TYPE functions, so that the converter is still
applied. (Especially considering that you'd likely be using Meta<std::string>,
in place of Meta<void>, precisely so that you can use a non-identity string to
string conversion.)
*/

template<
   class NODE, bool CONST, // node type, and its constness status
   class TYPE, class CONVERTER // for the Meta
>
class meta_ref {

   const Meta<TYPE,CONVERTER> kwd;

   // [const] std::string reference to the actual, in-node metadatum value
   typename std::conditional<
      CONST,
      const std::string,
      std::string
   >::type &metaValueRef;

public:

   // ------------------------
   // constructor
   // ------------------------

   meta_ref(
      const Meta<TYPE,CONVERTER> &kwd,
      typename std::conditional<CONST, const NODE, NODE>::type &parent
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
   typename std::enable_if<
     !CONSTANT,
      meta_ref
   >::type &operator=(const TYPE &obj)
   {
      kwd.converter(obj,metaValueRef="");
      return *this;
   }

   // = std::string
   // if std::string != TYPE
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

   // to TYPE
   operator TYPE() const
   {
      TYPE obj{};
      kwd.converter(metaValueRef,obj);
      return obj;
   }

   // to std::string
   // if std::string != TYPE
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
// The default does nothing; see the Allow::one and Allow::many specializations.
// -----------------------------------------------------------------------------

template<
   class NODE, bool CONST,
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER
>
class child_ref {
   // nothing
};



// -----------------------------------------------------------------------------
// child_ref
// For operator[](Child<TYPE,one>)
// Note: operator[](Child<void,one>) doesn't use child_ref
// -----------------------------------------------------------------------------

template<
   class NODE, bool CONST, // node type, and its constness status
   class TYPE, class CONVERTER, class FILTER // for the Child
>
class child_ref<NODE,CONST,TYPE,Allow::one,CONVERTER,FILTER>
{
   const Child<TYPE,Allow::one,CONVERTER,FILTER> kwd;

   // [const] node reference to the actual node
   typename std::conditional<
      CONST,
      const NODE,
      NODE
   >::type &childNodeRef;

public:

   // ------------------------
   // constructor
   // ------------------------

   child_ref(
      const Child<TYPE,Allow::one,CONVERTER,FILTER> &kwd,
      typename std::conditional<CONST, const NODE, NODE>::type &parent
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
   typename std::enable_if<
     !CONSTANT,
      child_ref
   >::type &operator=(const TYPE &obj)
   {
      kwd.converter(obj,childNodeRef.clear());
      return *this;
   }

   // = NODE (as in child_ref's template argument called NODE)
   // if NODE != TYPE
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

   // to TYPE
   operator TYPE() const
   {
      TYPE obj{};
      kwd.converter(childNodeRef,obj);
      return obj;
   }

   // to NODE() (as in child_ref's template argument called NODE)
   // if NODE != TYPE
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
// For operator[](Child<TYPE,many>)
// Note: works - and indeed is used - when TYPE == void.
// -----------------------------------------------------------------------------

template<
   class NODE, bool CONST, // node type, and its constness status
   class TYPE, class CONVERTER, class FILTER // for the Child
>
class child_ref<NODE,CONST,TYPE,Allow::many,CONVERTER,FILTER>
{
   const Child<TYPE,Allow::many,CONVERTER,FILTER> kwd;

   // vector of [const] node pointers to the actual nodes
   std::vector<
      typename std::conditional<
         CONST,
         const NODE,
         NODE
      >::type *
   > childNodePtr;

public:

   // ------------------------
   // constructor
   // ------------------------

   child_ref(
      const Child<TYPE,Allow::many,CONVERTER,FILTER> &kwd,
      typename std::conditional<CONST, const NODE, NODE>::type &parent
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
         log::ctor("child_ref<Allow::many>" + detail::keyname(kwd));
         throw;
      }
   }

   // ------------------------
   // misc. functions
   // ------------------------

   // size
   std::size_t size() const
   {
      return childNodePtr.size();
   }

   // operator[]
   decltype(auto) operator[](const std::size_t n) const
   {
      if constexpr (std::is_same<TYPE,void>::value) {
         // For TYPE == void
         // Returns: [const] NODE &
         return *childNodePtr[n];
      } else {
         // For TYPE != void
         // Leverage the capabilities of the Allow::one child_ref
         return child_ref<NODE,CONST,TYPE,Allow::one,CONVERTER,FILTER>(
            // As always, -- downgrades many to one. The /"" changes the lookup
            // name to "", which means "use the current node" (in this case the
            // node *childNodePtr[n]), which is appropriate here because we're
            // not digging further into the tree; we're making the [n] element
            // of the current "smart object" usable as its own smart object.
            --kwd/"",
            *childNodePtr[n]
         );
      }
   }

   // ------------------------
   // assignment
   // ------------------------

   // child_ref for Allow::many Child objects, as opposed to child_ref for
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
   // Remember, NODE is the version of Node<> with which we instantiated
   // this child_ref.
   //
   // The case of TYPE == NODE is analogous to the case of TYPE == std::string
   // for the meta_ref class. See the discussion above the code for that class.

   // to vector<TYPE>
   template<class T = TYPE>
   operator std::vector<
      typename std::enable_if<
        !std::is_same<T,void>::value,
         TYPE
      >::type
   >() const
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
   template<class T = TYPE>
   operator std::vector<
      typename std::enable_if<
        !std::is_same<T,NODE>::value, // <== includes TYPE == void
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
