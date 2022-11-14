
// zzz
namespace detail {
   class dummy { };
}

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
   our Child axis object has ALLOW == Allow::any. Note that axes, not to be
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

   /*
   // ------------------------
   // data
   // ------------------------

   // name, object, converter, filter
   std::string name;
   TYPE &placeholder;
   CONVERTER converter; // optional custom converter; needs operator()
   FILTER filter; // optional custom filter; needs operator()

   // ------------------------
   // constructors
   // ------------------------

   /// Some work-in-progress material here...

   explicit Child(
      const std::string &name
   ) :
      name(name),
      placeholder(detail::make_once<TYPE>()),
      converter(detail::make_once<CONVERTER>()),
      filter(detail::make_once<FILTER>())
   { }

   explicit Child(
      const std::string &name,
      const TYPE &t,/// = detail::make_once<TYPE>(),
      const CONVERTER &c = detail::make_once<CONVERTER>(),
      const FILTER &f = detail::make_once<FILTER>()
   ) :
      name(name),
      placeholder(detail::make_once<TYPE>() = t),
      converter(c),
      filter(f)
   { }
   */

   // ------------------------
   // data
   // ------------------------

   static const bool defcon = std::is_default_constructible_v<TYPE>;
   using PLACEHOLDER = std::conditional_t<defcon,detail::dummy,TYPE>;

   // name, object, converter, filter
   std::string name;
   mutable PLACEHOLDER placeholder;
   CONVERTER converter; // optional custom converter; needs operator()
   FILTER filter; // optional custom filter; needs operator()

   // ------------------------
   // constructors
   // ------------------------

/*
zzz
Think about what we need...

------------------------
CASE 1
TYPE is default constructible
------------------------

In this case, store a dummy, not an instance of the object.

Allow construction with or without a caller-provided instance.
If caller-provided, ignore the argument! We're just making a dummy.

------------------------
CASE 2
TYPE is NOT default constructible
------------------------

In this case, we *must* store an instance of the object, for use elsewhere.

Require that the caller provide an instance of the object. Emphasis: required!
Copy that over to the stored instance.
*/

   // If TYPE is NOT default constructible, then we must provide an object
   // of type TYPE. So we have:
   //    name, type
   //    name, type, converter
   //    name, type, converter, filter
   // as available constructor arguments.
   template<
      class T = TYPE,
      class = std::enable_if_t<!std::is_default_constructible_v<T>>
   >
   explicit Child(
      const std::string &n,
      const TYPE &t,
      const CONVERTER &c = detail::make_once<CONVERTER>(),
      const FILTER &f = detail::make_once<FILTER>()
   ) :
      name(n), placeholder(t), converter(c), filter(f)
   { }

   // If TYPE is default constructible, then we're allowed to provide an object
   // of type TYPE, in order to be consistent with the above case, but any such
   // value is ignored, as we're not going to store it anyway. So we again have:
   //    name, type
   //    name, type, converter
   //    name, type, converter, filter
   // as available constructor arguments. We also allow the ignored argument to
   // be of type detail::dummy. This allows for more uniformity here and there,
   // for example in Child's one() and many() member functions.
   template<
      class FROM,
      class = std::enable_if_t<
         std::is_same_v<FROM,TYPE> ||
         std::is_same_v<FROM,detail::dummy>
      >,
      class T = TYPE,
      class = std::enable_if_t<std::is_default_constructible_v<T>>
   >
   explicit Child(
      const std::string &n,
      const FROM &,
      const CONVERTER &c = detail::make_once<CONVERTER>(),
      const FILTER &f = detail::make_once<FILTER>()
   ) :
      name(n), converter(c), filter(f)
   { }

   // If TYPE is default constructible, then we're allowed to forego the object
   // of type TYPE altogether. Here, then, we allow:
   //    name
   //    name, converter
   //    name, converter, filter
   // as available constructor arguments.
   template<
      class T = TYPE,
      class = std::enable_if_t<std::is_default_constructible_v<T>>
   >
   explicit Child(
      const std::string &n,
      const CONVERTER &c = detail::make_once<CONVERTER>(),
      const FILTER &f = detail::make_once<FILTER>()
   ) :
      name(n), converter(c), filter(f)
   { }

   /*
   // ------------------------
   // data
   // ------------------------

   static const bool defcon = std::is_default_constructible_v<TYPE>;
   using PLACEHOLDER = std::conditional_t<defcon,detail::dummy,TYPE>;

   // name, object, converter, filter
   std::string name;
   mutable PLACEHOLDER placeholder;
   CONVERTER converter; // optional custom converter; needs operator()
   FILTER filter; // optional custom filter; needs operator()

   // ------------------------
   // constructors
   // ------------------------

   // name
   // name, type
   // name, type, converter
   // name, type, converter, filter
   explicit Child(
      const std::string &n,
      const PLACEHOLDER &t = detail::make_once<TYPE>(),
      const CONVERTER &c = detail::make_once<CONVERTER>(),
      const FILTER &f = detail::make_once<FILTER>()
   ) :
      name(n), placeholder(t), converter(c), filter(f)
   { }

   // name, converter
   // name, converter, filter
   explicit Child(
      const std::string &n,
      ///const PLACEHOLDER &t = detail::make_once<TYPE>(),
      const CONVERTER &c = detail::make_once<CONVERTER>(),
      const FILTER &f = detail::make_once<FILTER>()
   ) :
      name(n), converter(c), filter(f)
   { }
   */

   // ------------------------
   // simple functions
   // ------------------------

   // basic()
   // Produce a similar but voidified Child
   // See remarks for Meta's basic(); similar remarks apply here
   auto basic() const
   {
      return Child<void,ALLOW,void,FILTER>(
         name, filter // converter not possible here
      );
   }

   // one()
   // Produce an equivalent Child, but formulated as Allow::one
   auto one() const
   {
      return Child<TYPE,Allow::one,CONVERTER,FILTER>(
         name, placeholder, converter, filter
      );
   }

   // many()
   // Produce an equivalent Child, but formulated as Allow::many
   auto many() const
   {
      return Child<TYPE,Allow::many,CONVERTER,FILTER>(
         name, placeholder, converter, filter
      );
   }
};



// -----------------------------------------------------------------------------
// void
// -----------------------------------------------------------------------------

template<Allow ALLOW, class CONVERTER, class FILTER>
class Child<void,ALLOW,CONVERTER,FILTER> {
   static_assert(
      std::is_same_v<CONVERTER,void>,
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

#define GNDSTK_MAKE_CHILD(TYPE,name,ALLOW) \
   inline const njoy::GNDStk::Child<TYPE,njoy::GNDStk::Allow::ALLOW> name(#name)

// Note: we don't #undef this after we use it within GNDStk, as we might
// normally do, because users might find it handy.



// -----------------------------------------------------------------------------
// Operators
// -----------------------------------------------------------------------------

#include "GNDStk/Child/src/operator.hpp"
