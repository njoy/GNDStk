
// -----------------------------------------------------------------------------
// null
// In JSON: lower-case null.
// -----------------------------------------------------------------------------

// Remark.
//
// In one of class null's constructors, and in some of the constructors in some
// of our other classes, we have what may seem at first glance to be unnecessary
// or even unwanted uses of std::enable_if_t. Below, for example, instead of:
//
//    template<class T, ...enabled only if T is std::nullptr_t...>
//    null(const T &) { }
//
// why not just have the following instead?
//
//    null(const std::nullptr_t &) { }
//
// We do this because the first form forces an initializer to have *exactly* the
// given type, not just to be convertible to that type. Why not convertibility?
// It turns out that our primary "JSON value" class, json::value, will make use
// of a std::variant to contain an object of any of our individual JSON types:
//
//    std::variant<null, boolean, number, ...>
//
// Construction would be ambiguous if the argument could be converted to what's
// needed in the constructor of more than one of the variant's alternatives. Our
// std::enable_if_t approach, by requiring an exact match, prevents ambiguities.

class null {
public:

   // ------------------------
   // Construction
   // ------------------------

   // default
   null() { }

   // from std::nullptr_t
   template<class T, class = std::enable_if_t<std::is_same_v<T,std::nullptr_t>>>
   null(const T &) { }

   // ------------------------
   // Conversion
   // ------------------------

   // to std::nullptr_t
   operator const std::nullptr_t &() const
   { static const std::nullptr_t ret = nullptr; return ret; }
   operator       std::nullptr_t &()
   { static       std::nullptr_t ret = nullptr; return ret; }

   // ------------------------
   // read, write
   // ------------------------

   template<class T = void, class U = void>
   std::string read(std::istream &, const int = as_literal::none);

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
