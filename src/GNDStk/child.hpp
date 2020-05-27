
// -----------------------------------------------------------------------------
// child_t
// -----------------------------------------------------------------------------

/*
// ------------------------
// Description
// ------------------------

RESULT

   The type to which GNDStk should convert a Node<> that's extracted from
   a Tree<> with the child_t object. If RESULT is void, then GNDStk uses
   Node<*> (the child node, in its original form in the tree), where *
   is whatever template parameters are in play with the particular Tree<>
   being queried.

FIND

   A value, of enum class find, that indicates whether or not the kind of
   node in question is expected to appear one time, or any number of times.
   Consider, for example, that an XML-format GNDS might have:

      <axes>
         <axis> ... </axis>
         <axis> ... </axis>
         <axis> ... </axis>
         ...
      </axes>

   In other words: there are (or can be) any number of <axis> nodes within
   an enclosing context (here, <axes>). FIND is a template parameter because
   it affects the *type* that's pulled from the Tree when the child_t object
   is used for a query. For example,

      tree(...,axes,axis)

   gives back a container of axis objects, not a single axis object, because
   our child_t axis keyword has FIND == find::any. Note that axes, not to be
   confused with axis, has FIND == find::one because it's expected just once.

CONVERTER

   Custom conversion between RESULT and Node, if we wish to override the
   default of calling the overloaded function convert() to do the conversion.
*/

// ------------------------
// default
// ------------------------

template<
   class RESULT    = void,       // default means current Node type
   find  FIND      = find::one,  // one, or any number allowed?
   class CONVERTER = typename detail::default_converter<RESULT>::type
>
class child_t {
public:
   // name, converter, can be top level?
   const std::string name;
   const CONVERTER converter; // optional custom converter; needs operator()
   const bool canBeTopLevel;

   // ctor(name)
   // ctor(name,top)
   // ctor(name,top,converter)
   explicit child_t(
      const std::string &n,
      const bool top = false,
      const CONVERTER &c = CONVERTER{}
   ) :
      name(n), converter(c), canBeTopLevel(top)
   { }

   // ctor(name,converter)
   // ctor(name,converter,top)
   child_t(
      const std::string &n,
      const CONVERTER &c,
      const bool top = false
   ) :
      name(n), converter(c), canBeTopLevel(top)
   { }
};


// ------------------------
// void
// ------------------------

template<find FIND, class CONVERTER>
class child_t<void,FIND,CONVERTER> {
   static_assert(
      std::is_same<CONVERTER,void>::value,
     "Can't instantiate child_t<void,FIND,CONVERTER> "
     "with non-default CONVERTER"
   );
public:
   // name, can be top level?
   const std::string name;
   const bool canBeTopLevel;

   // ctor(name)
   // ctor(name,top)
   explicit child_t(
      const std::string &n,
      const bool top = false
   ) :
      name(n), canBeTopLevel(top)
   { }
};



// -----------------------------------------------------------------------------
// Miscellaneous
// -----------------------------------------------------------------------------

// Macros
// For child_t building. The macros don't handle the optional converter;
// for that, just construct such an object directly.

// void (unspecified) result type (so, Node<>)
#define GNDSTK_MAKE_CHILD_DEFAULT(name,FIND) \
   inline const child_t<void,FIND> name(#name)

// user-defined result type
#define GNDSTK_MAKE_CHILD(result,name,FIND) \
   inline const child_t<result,FIND> name(#name)

// Note: we won't #undef these eventually, as we normally would,
// because they're perfectly viable macros for users to invoke.

// Operators and built-in keywords
#include "GNDStk/child/src/operator.hpp"
#include "GNDStk/child/src/keyword.hpp"
