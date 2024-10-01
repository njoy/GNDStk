
// -----------------------------------------------------------------------------
// value
// As in, the "value" of a JSON "key:value pair". This will be an instance
// of a JSON standard type, or of our special literal type.
// -----------------------------------------------------------------------------

class value
 : public std::variant<
      // JSON standard types
      null, boolean, number, string, array, object,
      // our type
      literal
   >
{
#include "json-value-helper.hpp"

public:

   // ------------------------
   // Construction
   // ------------------------

   // inherited
   using variant::variant;

   // default (override inherited because we want to select object)
   value() : variant(object()) { }

   // from instance of base class
   value(const variant &from) : variant(from) { }
   value(variant &&from) : variant(std::move(from)) { }

   // from std::nullptr_t
   // from bool
   // from std::initializer_list<value> ==> json::array
   // from std::initializer_list<pair> ==> json::object
   value(const std::nullptr_t &from) : variant(json::null(from)) { }
   value(const bool &from) : variant(json::boolean(from)) { }
   value(const std::initializer_list<value> &from) : variant(array(from)) { }
   value(const std::initializer_list<pair> &from) : variant(object(from)) { }

   // ------------------------
   // Assignment
   // ------------------------

   template<
      class T,
      class = std::enable_if_t<std::is_assignable_v<variant, T &&>>>
   value &operator=(T &&from)
   {
      variant::operator=(std::forward<T>(from));
      return *this;
   }

   // ------------------------
   // Conversion
   // ------------------------

   template<class T>
   using converts = std::enable_if_t<
      detail::invar<T,value::variant> ||
      std::is_same_v<T,std::nullptr_t> ||
      std::is_same_v<T,std::string>
   >;

   // to arithmetic T
   // Assumes json::number, and forwards to its conversion to arithmetic T.
   // Returns by value; so, const only.
   template<class T, class = std::enable_if_t<std::is_arithmetic_v<T>>>
   operator T() const
   {
      return T(get<number>());
   }

   // to specific Ts; const
   template<class T, class = converts<T>>
   operator const T &() const
   {
      if constexpr (detail::invar<T,value::variant>)
         return get<T>();
      else if constexpr (std::is_same_v<T,std::nullptr_t>)
         return get<null>();
      else if (has<json::literal>())
         return get<json::literal>();
      else
         return get<json::string>();
   }

   // to specific Ts; non-const
   template<class T, class = converts<T>>
   operator T &()
   {
      return const_cast<T &>((const T &)(std::as_const(*this)));
   }

   // ------------------------
   // operator[]
   // ------------------------

   // const
   template<
      class T,
      class = std::enable_if_t<
         detail::isintegral<T> || std::is_constructible_v<string,T>
      >
   >
   const value &operator[](const T &key) const
   {
      if constexpr (detail::isintegral<T>)
         return get<array >()[key];
      else
         return get<object>()[key];
   }

   // non-const
   template<
      class T,
      class = std::enable_if_t<
         detail::isintegral<T> || std::is_constructible_v<string,T>
      >
   >
   value &operator[](const T &key)
   {
      return const_cast<value &>(std::as_const(*this).operator[](key));
   }

   // ------------------------
   // Other
   // ------------------------

   // items
   const std::vector<pair> &items() const { return get<object>(); }
         std::vector<pair> &items()       { return get<object>(); }

   // has alternative
   template<
      class T,
      class = std::enable_if_t<
         detail::invar<T,variant> ||
         detail::invar<T,number::variant>
      >
   >
   bool has() const
   {
      if constexpr (detail::invar<T,variant>)
         return std::holds_alternative<T>(*this);
      else
         return has<number>() && get<number>().has<T>();
   }

   // has key
   // Assumes this value is an object
   bool has(const string &key) const
   {
      return get<object>().has(key);
   }

   // get<T>
   #include "json-value-get.hpp"

   // is_*
   #include "json-value-is.hpp"

   // dump
   std::string dump() const
   {
      std::ostringstream oss;
      return write(oss), oss.str();
   }

   // ------------------------
   // read, write
   // ------------------------

   template<class T = void, class U = void>
   auto read(std::istream &is, const int = as_literal::none)
      -> decltype(number().read<T,U>(is,0)); // SFINAE: need number::read<T,U>

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
