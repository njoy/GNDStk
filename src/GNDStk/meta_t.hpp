
// -----------------------------------------------------------------------------
// meta_t
// -----------------------------------------------------------------------------

// <TYPE,CONVERTER>
template<
   class TYPE = void,
   class CONVERTER = typename detail::default_converter<TYPE>::type
>
class meta_t {
public:
   // name, converter
   const std::string name;
   const CONVERTER converter; // optional custom converter; needs operator()

   // ctor
   explicit meta_t(const std::string &n, const CONVERTER &c = CONVERTER{}) :
      name(n), converter(c)
   { }
};

// <void>
template<class CONVERTER>
class meta_t<void,CONVERTER> {
   static_assert(
      std::is_same<CONVERTER,void>::value,
     "Can't instantiate meta_t<void,CONVERTER> with non-default CONVERTER"
   );
public:
   // name
   const std::string name;

   // ctor
   explicit meta_t(const std::string &n) :
      name(n)
   { }
};


// -----------------------------------------------------------------------------
// Miscellaneous
// -----------------------------------------------------------------------------

// Macro
// For meta_t building. The macro doesn't handle the optional converter;
// for that, just construct such an object directly.
#define GNDSTK_MAKE_META(TYPE,name) \
   inline const meta_t<TYPE> name(#name)
// Note: we won't #undef this eventually, as we normally would,
// because it's a perfectly viable macro for users to invoke.

// Operators
#include "GNDStk/meta_t/src/operator.hpp"