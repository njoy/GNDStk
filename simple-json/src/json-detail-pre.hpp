
namespace detail {

// -----------------------------------------------------------------------------
// base
// -----------------------------------------------------------------------------

template<class T>
struct Base {
   using type = T;
};

#if defined(JSON_RAW) || defined(JSON_SHARED)
template<class T>
struct Base<atom<T>> {
   using type = T;
};
#endif

template<class T>
using base = typename Base<T>::type;


// -----------------------------------------------------------------------------
// inVariant
// count == number of times atom<T> is exactly the same as a type in the variant
// -----------------------------------------------------------------------------

template<class, class>
struct inVariant { };

template<class T, class... As>
struct inVariant<T,std::variant<As...>>
{
   static inline constexpr int count = (same<atom<T>,As> + ...);
};


// -----------------------------------------------------------------------------
// Re: printing
// -----------------------------------------------------------------------------

class SHAPE { }; // ==> print types only
class WRITE { }; // ==> print values; essentially regular JSON
class DEBUG { }; // ==> print both; probably for debugging

// Remark: We need detail:: in the macro; it's used outside of namespace detail.
#define JSON_IO(type) \
   template<class ACTION> \
   void print(std::ostream &os, const int level) const; \
   std::ostream &shape(std::ostream &os = std::cout) const \
      { return print<detail::SHAPE>(os,0), os; } \
   std::ostream &write(std::ostream &os = std::cout) const \
      { return print<detail::WRITE>(os,0), os; } \
   std::ostream &debug(std::ostream &os = std::cout) const \
      { return print<detail::DEBUG>(os,0), os; } \
   friend std::ostream &operator<<(std::ostream &os, const type &j) \
      { return j.write(os); } \
   template<class T = JSON_INTEGRAL, class U = JSON_FLOATING, \
            class = require<number::types<T,U>::compatible>> \
   literal read(std::istream &is, const unsigned flags = 0)

} // namespace detail
