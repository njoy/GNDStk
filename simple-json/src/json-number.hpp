
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

   // ------------------------
   // Construction
   // ------------------------

   // default
   number() :
      variant(0)
   { }

   // from variant
   number(const variant &from) :
      variant(from)
   { }
   number(variant &&from) :
      variant(std::move(from))
   { }

   // from T in the variant
   template<class T, class = std::enable_if_t<detail::invar<T,variant>>>
   number(const T &from) :
      variant(from)
   { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class T, class = std::enable_if_t<std::is_assignable_v<variant,T>>>
   number &operator=(const T &from)
   { variant::operator=(from); return *this; }

   template<class T, class = std::enable_if_t<std::is_assignable_v<variant,T>>>
   number &operator=(T &&from)
   { variant::operator=(std::move(from)); return *this; }

   // ------------------------
   // Conversion
   // ------------------------

   // to T
   template<class T, class = std::enable_if_t<std::is_arithmetic_v<T>>>
   operator T() const
   {
      return std::visit(
         [](const auto &alt)
         {
            return T(alt);
         },
         static_cast<const variant &>(*this)
      );
   }

   // ------------------------
   // Other
   // ------------------------

   // has<T>
   template<class T, class = std::enable_if_t<detail::invar<T,variant>>>
   bool has() const { return std::holds_alternative<T>(*this); }

   // get<T>
   template<class T, class = std::enable_if_t<detail::invar<T,variant>>>
   const T &get() const { return std::get<T>(*this); }
   template<class T, class = std::enable_if_t<detail::invar<T,variant>>>
   T &get() { return std::get<T>(*this); }

   // ------------------------
   // read, write
   // ------------------------

   template<
      class T = void, class U = void,
      class = std::enable_if_t<types<T,U>::compatible>
   >
   std::string read(std::istream &, const int = as_literal::none);

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
