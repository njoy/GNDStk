
// -----------------------------------------------------------------------------
// Child
// -----------------------------------------------------------------------------

/*
// ------------------------
// Description
// ------------------------

TYPE

   The type to which GNDStk should convert a Node that's extracted, via our
   query system, with the Child object. If TYPE is void, then GNDStk uses
   type Node - the child node in its original form.

ALLOW

   A value, of enum class Allow, that indicates whether or not the kind of
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
   it affects the *type* that's extracted when the Child object is used for a
   query. For example,

      tree(...,axes,axis)

   gives back a container of axis objects, not a single axis object, because
   our Child axis object has ALLOW == Allow::many. Note that axes, not to be
   confused with axis, has ALLOW == Allow::one because it's expected just once.

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
   Allow ALLOW = Allow::one, // one, or any number allowed?
   class CONVERTER = detail::default_converter_t<TYPE>,
   class FILTER = detail::noFilter
>
class Child {
public:

   // ------------------------
   // data
   // ------------------------

   // name, converter, filter
   std::string name;
   CONVERTER converter; // optional custom converter; needs operator()
   FILTER filter; // optional custom filter; needs operator()

   // ------------------------
   // constructors
   // ------------------------

   // name
   // name, converter
   // name, converter, filter
   explicit Child(
      const std::string &n,
      const CONVERTER &c = detail::make_once<CONVERTER>(),
      const FILTER &f = detail::make_once<FILTER>()
   ) :
      name(n), converter(c), filter(f)
   { }

   // ------------------------
   // simple functions
   // ------------------------

   // basic()
   // Produce a similar but voidified Child
   // See remarks for Meta's basic(); similar remarks apply here
   auto basic() const
   {
      // converter isn't possible here
      return Child<void,ALLOW,void,FILTER>(name, filter);
   }

   // one()
   // Produce an equivalent Child, but formulated as Allow::one
   auto one() const
   {
      return Child<TYPE,Allow::one,CONVERTER,FILTER>(name, converter, filter);
   }

   // many()
   // Produce an equivalent Child, but formulated as Allow::many
   auto many() const
   {
      return Child<TYPE,Allow::many,CONVERTER,FILTER>(name, converter, filter);
   }
};


// -----------------------------------------------------------------------------
// void
// -----------------------------------------------------------------------------

template<Allow ALLOW, class CONVERTER, class FILTER>
class Child<void,ALLOW,CONVERTER,FILTER> {
   static_assert(
      detail::is_void_v<CONVERTER>,
     "Can't create Child<void,...> with non-default CONVERTER"
   );

public:

   // ------------------------
   // data
   // ------------------------

   // name, filter
   std::string name;
   FILTER filter; // optional custom filter; needs operator()

   // ------------------------
   // constructors
   // ------------------------

   // name
   // name, filter
   explicit Child(
      const std::string &n,
      const FILTER &f = detail::make_once<FILTER>()
   ) :
      name(n), filter(f)
   { }

   // ------------------------
   // simple functions
   // ------------------------

   // basic()
   // Produce a similar but voidified Child. In the present specialization,
   // we're already void; this is here for consistency with the general case.
   auto basic() const
   {
      return Child<void,ALLOW,void,FILTER>(name,filter);
   }

   // one()
   // Produce an equivalent Child, but formulated as Allow::one
   auto one() const
   {
      return Child<void,Allow::one,void,FILTER>(name,filter);
   }

   // many()
   // Produce an equivalent Child, but formulated as Allow::many
   auto many() const
   {
      return Child<void,Allow::many,void,FILTER>(name,filter);
   }
};


// -----------------------------------------------------------------------------
// Macro
// -----------------------------------------------------------------------------

// For Child building. This macro doesn't handle the converter or the filter;
// we don't believe those will be needed very often. If you do need to provide
// one or both, construct a Child in some other way than by using this macro.

#define NJOY_GNDSTK_MAKE_CHILD(TYPE,name,ALLOW) \
   inline const njoy::GNDStk::Child<TYPE,njoy::GNDStk::Allow::ALLOW> name(#name)

// Note: we don't #undef this after we use it within GNDStk, as we might
// normally do, because users might find it handy.


// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

#include "GNDStk/Child/src/operator.hpp"
