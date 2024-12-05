
namespace detail {

// inVariant
// count == number of times T is exactly the same as a type in the variant
template<class, class>
struct inVariant { };

template<class T, class... As>
struct inVariant<T,std::variant<As...>>
{
   static inline constexpr int count = (same<T,As> + ...);
};

// Re: printing
class SHAPE { }; // ==> print types only
class WRITE { }; // ==> print values; essentially regular JSON
class DEBUG { }; // ==> print both; probably for debugging

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
