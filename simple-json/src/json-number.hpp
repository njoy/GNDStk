
// -----------------------------------------------------------------------------
// number
// In JSON: integral or floating point number.
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

   // inherited
   using variant::variant;

   // default (override inherited because we want to select int)
   number() : variant(0) { }

   // from instance of base class
   number(const variant &from) : variant(from) { }
   number(variant &&from) : variant(std::move(from)) { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class T, class = require<assignable<variant, T &&>>>
   number &operator=(T &&from)
   {
      variant::operator=(std::forward<T>(from));
      return *this;
   }

   // ------------------------
   // Conversion
   // ------------------------

   // to arithmetic T
   // Returns by value, so that we need not assume that the underlying
   // variant holds exactly a T. Also, then, we need only a const version.
   template<class T, class = require<arithmetic<T>>>
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
   template<class T, class = require<allowed<T,variant>>>
   bool has() const { return std::holds_alternative<T>(*this); }

   // get<T>
   template<class T, class = require<allowed<T,variant>>>
   const T &get() const { return std::get<T>(*this); }
   template<class T, class = require<allowed<T,variant>>>
         T &get()       { return std::get<T>(*this); }

   // ------------------------
   // read, write
   // ------------------------

   template<
      class T = void, class U = void,
      class = require<types<T,U>::compatible>
   >
   std::string read(std::istream &, const int = as_literal::none);

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
