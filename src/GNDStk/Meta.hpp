
#include "GNDStk/Meta/src/detail.hpp"

// -----------------------------------------------------------------------------
// Meta
// -----------------------------------------------------------------------------

// ------------------------
// Meta<TYPE,CONVERTER>
// ------------------------

template<
   class TYPE = void,
   class CONVERTER = detail::default_converter_t<TYPE>
>
class Meta {
public:
   // name, object, converter
   std::string name;
   CONVERTER converter; // optional custom converter; needs operator()

   // ctor
   explicit Meta(
      const std::string &n,
      const CONVERTER &c = detail::make_once<CONVERTER>()
   ) :
      name(n),
      converter(c)
   { }

   // basic()
   // Produce a similar but voidified Meta: with the TYPE template argument
   // set to void. Used in a query, the new Meta will produce a "basic"
   // metadatum - one in its raw form in the GNDS tree, not converted to TYPE.
   // The converter is necessarily discarded; Meta<void,...> doesn't have it.
   auto basic() const
   {
      return Meta<void>(name);
   }
};


// ------------------------
// Meta<void>
// ------------------------

template<class CONVERTER>
class Meta<void,CONVERTER> {
   static_assert(
      detail::is_void_v<CONVERTER>,
     "Can't create Meta<void,CONVERTER> with non-default CONVERTER"
   );

public:
   // name
   std::string name;

   // ctor
   explicit Meta(const std::string &n) :
      name(n)
   { }

   // basic()
   // Produce a similar but voidified Meta. In the present specialization,
   // we're already void; this is here for consistency with the general case.
   auto basic() const
   {
      return Meta<void>(name);
   }
};


// -----------------------------------------------------------------------------
// Miscellaneous
// -----------------------------------------------------------------------------

// Macro
// For Meta building.
// This macro doesn't allow a custom converter to be given.
// If you need a custom converter, construct a Meta directly.
#define NJOY_GNDSTK_MAKE_META(TYPE,name) \
   inline const njoy::GNDStk::Meta<TYPE> name(#name)
// Note: we won't #undef this eventually, as we normally would,
// because it's a perfectly viable macro for users to invoke.

// Operators
#include "GNDStk/Meta/src/operator.hpp"
