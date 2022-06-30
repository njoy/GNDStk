
namespace detail {

// -----------------------------------------------------------------------------
// convert_t
// Serves as a default "function object" in places where a function object
// can be (optionally) user-provided for converting *from* something, *to*
// something else.
// -----------------------------------------------------------------------------

class convert_t {
public:
   template<class FROM, class TO>
   void operator()(const FROM &from, TO &to) const
   {
      if constexpr (
         std::is_constructible_v<TO,FROM> ||
         std::is_convertible_v<FROM,TO>
      ) {
         to = TO(from);
      } else if constexpr (isVariant<FROM>::value) {
         std::visit([&to](auto &&alt) { convert_t{}(alt,to); }, from);
      } else {
         convert(from,to);
      }
   }
};


// -----------------------------------------------------------------------------
// default_converter
// default_converter_t
// Used for selecting the CONVERTER template argument of the Meta and Child
// classes. Usually gives convert_t, but gives void (which in turn won't, and
// shouldn't, be used as a converter) for Meta<void> and Child<void>, for which
// the concept of a converter is not applicable.
// -----------------------------------------------------------------------------

template<class TYPE>
class default_converter {
public:
   using type = convert_t;
};

template<>
class default_converter<void> {
public:
   using type = void;
};

template<class TYPE>
using default_converter_t = typename default_converter<TYPE>::type;


// -----------------------------------------------------------------------------
// static_const
// Used in certain places in which default initializations of class T objects
// may be needed, but might be expensive.
// -----------------------------------------------------------------------------

template<class T>
inline const T &static_const()
{
   static const T value{};
   return value;
}

} // namespace detail
