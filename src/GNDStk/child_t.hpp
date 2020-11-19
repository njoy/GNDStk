
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

FILTER

   Custom filter, for deciding whether or not a Node satisfies some condition.
*/



// -----------------------------------------------------------------------------
// default
// -----------------------------------------------------------------------------

template<
   class TYPE = void, // default means current Node type
   allow ALLOW = allow::one, // one, or any number allowed?
   class CONVERTER = typename detail::default_converter<TYPE>::type,
   class FILTER = detail::noFilter
>
class child_t {
public:

   // ------------------------
   // data
   // ------------------------

   // name, converter, filter, can be top level?
   std::string name;
   CONVERTER converter; // optional custom converter; needs operator()
   FILTER filter; // optional custom filter; needs operator()
   bool canBeTopLevel;

   // ------------------------
   // constructors
   // ------------------------

   // ctor(name)
   // ctor(name,top)
   // ctor(name,top,converter)
   // ctor(name,top,converter,filter)
   explicit child_t(
      const std::string &n,
      const bool top = false,
      const CONVERTER &c = CONVERTER{},
      const FILTER &f = FILTER{}
   ) :
      name(n), converter(c), filter(f), canBeTopLevel(top)
   {
      if (top) detail::AllowedTop.insert(name);
   }

   // ctor(name,converter)
   // ctor(name,converter,top)
   // ctor(name,converter,top,filter)
   child_t(
      const std::string &n,
      const CONVERTER &c,
      const bool top = false,
      const FILTER &f = FILTER{}
   ) :
      name(n), converter(c), filter(f), canBeTopLevel(top)
   {
      if (top) detail::AllowedTop.insert(name);
   }

   // ctor(name,converter,filter)
   // ctor(name,converter,filter,top)
   child_t(
      const std::string &n,
      const CONVERTER &c,
      const FILTER &f,
      const bool top = false
   ) :
      name(n), converter(c), filter(f), canBeTopLevel(top)
   {
      if (top) detail::AllowedTop.insert(name);
   }

   // ------------------------
   // Simple functions
   // ------------------------

   // basic()
   // Produce a similar but voidified child_t
   // See remarks for meta_t's basic(); similar remarks apply here
   auto basic() const
   {
      return child_t<void,ALLOW,void,FILTER>(
         name, filter, canBeTopLevel // converter not possible here
      );
   }

   // one()
   // Produce an equivalent child_t, but formulated as allow::one
   auto one() const
   {
      return child_t<TYPE,allow::one,CONVERTER,FILTER>(
         name, converter, filter, canBeTopLevel
      );
   }

   // many()
   // Produce an equivalent child_t, but formulated as allow::many
   auto many() const
   {
      return child_t<TYPE,allow::many,CONVERTER,FILTER>(
         name, converter, filter, canBeTopLevel
      );
   }
};



// -----------------------------------------------------------------------------
// void
// -----------------------------------------------------------------------------

template<allow ALLOW, class CONVERTER, class FILTER>
class child_t<void,ALLOW,CONVERTER,FILTER> {
   static_assert(
      std::is_same<CONVERTER,void>::value,
     "Can't create child_t<void,...> with non-default CONVERTER"
   );

public:

   // ------------------------
   // data
   // ------------------------

   // name, filter, can be top level?
   std::string name;
   FILTER filter; // optional custom filter; needs operator()
   bool canBeTopLevel;

   // ------------------------
   // constructors
   // ------------------------

   // ctor(name)
   // ctor(name,top)
   // ctor(name,top,filter)
   explicit child_t(
      const std::string &n,
      const bool top = false,
      const FILTER &f = FILTER{}
   ) :
      name(n), filter(f), canBeTopLevel(top)
   {
      if (top) detail::AllowedTop.insert(name);
   }

   // ctor(name,filter)
   // ctor(name,filter,top)
   explicit child_t(
      const std::string &n,
      const FILTER &f,
      const bool top = false
   ) :
      name(n), filter(f), canBeTopLevel(top)
   {
      if (top) detail::AllowedTop.insert(name);
   }

   // ------------------------
   // Simple functions
   // ------------------------

   // basic()
   // Produce a similar but voidified child_t. In the present specialization,
   // we're already void; this is here for consistency with the general case.
   auto basic() const
   {
      return child_t<void,ALLOW,void,FILTER>(name,filter,canBeTopLevel);
   }

   // one()
   // Produce an equivalent child_t, but formulated as allow::one
   auto one() const
   {
      return child_t<void,allow::one,void,FILTER>(name,filter,canBeTopLevel);
   }

   // many()
   // Produce an equivalent child_t, but formulated as allow::many
   auto many() const
   {
      return child_t<void,allow::many,void,FILTER>(name,filter,canBeTopLevel);
   }
};



// -----------------------------------------------------------------------------
// Macro
// -----------------------------------------------------------------------------

// For child_t building. This macro doesn't handle the optional "top level"
// flag, the converter, or the filter; we don't believe those will be needed
// very often. If you do need to provide one or both, construct a child_t
// in some other way than by using this macro.

#define GNDSTK_MAKE_CHILD(type,name,ALLOW) \
   inline const child_t<type,ALLOW> name(#name)

// Note: we don't #undef this after we use it within GNDStk, as we might
// normally do, because users might find it handy.



// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

#include "GNDStk/child_t/src/operator.hpp"
