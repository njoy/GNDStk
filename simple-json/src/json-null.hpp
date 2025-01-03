
// -----------------------------------------------------------------------------
// null
// In JSON: lower-case null.
// -----------------------------------------------------------------------------

// Remark:
//
// In one of class null's constructors, and in some of the constructors in some
// of our other classes, we have what may seem at first to be an unnecessary or
// even unwanted use of require<>. Below, for example, instead of:
//
//    template<class T, ...require that T == std::nullptr_t...>
//    null(const T &) { }
//
// why not just have the following instead?
//
//    null(const std::nullptr_t &) { }
//
// We do this because the first form forces an initializer to have *exactly* the
// given type, not just to be convertible to that type. Why not convertibility?
// It turns out that our primary "JSON value" class, json::value, will make use
// of a std::variant to contain an instance of any of our individual JSON types.
// Construction would be ambiguous if a parameter could be converted to what is
// needed in the constructor of more than one of the variant's alternatives. By
// requiring an exact match in selected cases, we prevent such ambiguities.

class null {
public:
   JSON_IO(null);

   // ------------------------
   // Construction
   // ------------------------

   // default
   null() { }

   // from std::nullptr_t (exactly)
   template<class NULLPTR, class = require<same<NULLPTR,std::nullptr_t>>>
   null(const NULLPTR &) { }

   // ------------------------
   // Conversion
   // ------------------------

   // to std::nullptr_t
   operator const std::nullptr_t &() const
      { static constexpr std::nullptr_t ret = nullptr; return ret; }
   operator std::nullptr_t &()
      { static std::nullptr_t ret = nullptr; return ret; }
};
