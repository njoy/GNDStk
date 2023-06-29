
// -----------------------------------------------------------------------------
// number
// In JSON: integral or floating-point number.
// -----------------------------------------------------------------------------

class number
 : public std::variant<
      // unsigned integers
      unsigned char,
      unsigned short,
      unsigned int,
      unsigned long,
      unsigned long long,
      // integers
      signed char,
      signed short,
      signed int,
      signed long,
      signed long long,
      // floating points
      double,
      long double,
      float
   >
{
#include "json-number-helper.hpp"

public:
   using variant::operator=;
   number(const variant &from) : variant(from) { }
   number(variant &&from) : variant(std::move(from)) { }

   // constructor: default
   number() : variant(0) { }

   // constructor: from T in the variant
   template<class T, class = std::enable_if_t<detail::invar<T,variant>>>
   number(const T &from) : variant(from) { }

   // read, write
   template<
      class T = void, class U = void,
      class = std::enable_if_t<types<T,U>::compatible>
   >
   std::string read(std::istream &, const int = as_literal::none);
   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;

   // has
   template<class T>
   bool has() const { return std::holds_alternative<T>(*this); }

   // get<T>
   template<class T, class = std::enable_if_t<detail::invar<T,variant>>>
   const T &get() const { return std::get<T>(*this); }
   template<class T, class = std::enable_if_t<detail::invar<T,variant>>>
   T &get() { return std::get<T>(*this); }
};
