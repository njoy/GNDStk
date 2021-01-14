
// -----------------------------------------------------------------------------
// meta_t
// -----------------------------------------------------------------------------

// ------------------------
// meta_t<TYPE,CONVERTER>
// ------------------------

template<
   class TYPE = void,
   class CONVERTER = typename detail::default_converter<TYPE>::type
>
class meta_t {
public:
   // name, object, converter
   std::string name;
   const TYPE object;
   CONVERTER converter; // optional custom converter; needs operator()

   // ctor
   explicit meta_t(
      const std::string &n,
      const TYPE &t = TYPE{},
      const CONVERTER &c = CONVERTER{}
   ) :
      name(n),
      object(t),
      converter(c)
   { }

   // basic()
   // Produce a similar but voidified meta_t: with the TYPE template argument
   // set to void. Used in a query, the new meta_t will produce a "basic"
   // metadatum - one in its raw form in the GNDS tree, not converted to TYPE.
   // The converter is necessarily discarded; meta_t<void,...> doesn't have it.
   auto basic() const
   {
      return meta_t<void>(name);
   }
};


// ------------------------
// meta_t<void>
// ------------------------

template<class CONVERTER>
class meta_t<void,CONVERTER> {
   static_assert(
      std::is_same<CONVERTER,void>::value,
     "Can't create meta_t<void,CONVERTER> with non-default CONVERTER"
   );

public:
   // name
   std::string name;

   // ctor
   explicit meta_t(const std::string &n) :
      name(n)
   { }

   // basic()
   // Produce a similar but voidified meta_t. In the present specialization,
   // we're already void; this is here for consistency with the general case.
   auto basic() const
   {
      return meta_t<void>(name);
   }
};


// -----------------------------------------------------------------------------
// Miscellaneous
// -----------------------------------------------------------------------------

// Macro
// For meta_t building.
// This macro doesn't allow for the (optional) TYPE object or the converter.
// For those, construct a meta_t directly.
#define GNDSTK_MAKE_META(TYPE,name) \
   inline const meta_t<TYPE> name(#name)
// Note: we won't #undef this eventually, as we normally would,
// because it's a perfectly viable macro for users to invoke.

// Operators
#include "GNDStk/meta_t/src/operator.hpp"
