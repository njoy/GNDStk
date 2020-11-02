
// -----------------------------------------------------------------------------
// child_t
// -----------------------------------------------------------------------------

/*
// ------------------------
// Description
// ------------------------

TYPE

   The type to which GNDStk should convert a Node<> that's extracted from
   a Tree<> with the child_t object. If TYPE is void, then GNDStk uses
   Node<*> (the child node, in its original form in the tree), where *
   is whatever template parameters are in play with the particular Tree<>
   being queried.

ALLOW

   A value, of enum class allow, that indicates whether or not the kind of
   node in question is expected to appear one time, or any number of times.
   Consider, for example, that an XML-format GNDS might have:

      <axes>
         <axis> ... </axis>
         <axis> ... </axis>
         <axis> ... </axis>
         ...
      </axes>

   In other words: there are (or can be) any number of <axis> nodes within
   an enclosing context (here, <axes>). ALLOW is a template parameter because
   it affects the *type* that's pulled from the Tree when the child_t object
   is used for a query. For example,

      tree(...,axes,axis)

   gives back a container of axis objects, not a single axis object, because
   our child_t axis keyword has ALLOW == allow::any. Note that axes, not to be
   confused with axis, has ALLOW == allow::one because it's expected just once.

CONVERTER

   Custom conversion between TYPE and Node, if we wish to override the
   default of calling the overloaded function convert() to do the conversion.
*/

// ------------------------
// default
// ------------------------

template<
   class TYPE = void, // default means current Node type
   allow ALLOW = allow::one, // one, or any number allowed?
   class CONVERTER = typename detail::default_converter<TYPE>::type
>
class child_t {
public:

   // ------------------------
   // data
   // ------------------------

   // name, converter, can be top level?
   std::string name;
   CONVERTER converter; // optional custom converter; needs operator()
   bool canBeTopLevel;

   // ------------------------
   // constructors
   // ------------------------

   // ctor(name)
   // ctor(name,top)
   // ctor(name,top,converter)
   explicit child_t(
      const std::string &n,
      const bool top = false,
      const CONVERTER &c = CONVERTER{}
   ) :
      name(n), converter(c), canBeTopLevel(top)
   {
      if (top) detail::AllowedTop.insert(name);
   }

   // ctor(name,converter)
   // ctor(name,converter,top)
   child_t(
      const std::string &n,
      const CONVERTER &c,
      const bool top = false
   ) :
      name(n), converter(c), canBeTopLevel(top)
   {
      if (top) detail::AllowedTop.insert(name);
   }
};


// ------------------------
// void
// ------------------------

template<allow ALLOW, class CONVERTER>
class child_t<void,ALLOW,CONVERTER> {
   static_assert(
      std::is_same<CONVERTER,void>::value,
     "Can't create child_t<void,ALLOW,CONVERTER> with non-default CONVERTER"
   );

public:

   // ------------------------
   // data
   // ------------------------

   // name, can be top level?
   std::string name;
   bool canBeTopLevel;

   // ------------------------
   // constructors
   // ------------------------

   // ctor(name)
   // ctor(name,top)
   explicit child_t(
      const std::string &n,
      const bool top = false
   ) :
      name(n), canBeTopLevel(top)
   {
      if (top) detail::AllowedTop.insert(name);
   }
};



// -----------------------------------------------------------------------------
// Macro
// -----------------------------------------------------------------------------

// For child_t building. This macro doesn't handle the optional "top level"
// flag or the converter, which we don't believe are needed very often. If
// you do need to provide one or both, construct a child_t directly.

#define GNDSTK_MAKE_CHILD(type,name,ALLOW) \
   inline const child_t<type,ALLOW> name(#name)

// Note: we don't #undef this after we use it within GNDStk, as we might
// normally do, because users might find it handy.



// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

#include "GNDStk/child_t/src/operator.hpp"
