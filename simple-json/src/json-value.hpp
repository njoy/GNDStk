
// -----------------------------------------------------------------------------
// value
// As in, the "value" of a JSON "key:value" pair. This will be an instance
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
   // from std::initializer_list<value> ==> array
   // from std::initializer_list<pair> ==> object
   value(const std::nullptr_t &from) : variant(null(from)) { }
   value(const bool &from) : variant(boolean(from)) { }
   value(const std::initializer_list<value> &from) : variant(array(from)) { }
   value(const std::initializer_list<pair> &from) : variant(object(from)) { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class T, class = require<assignable<variant, T &&>>>
   value &operator=(T &&from)
   {
      variant::operator=(std::forward<T>(from));
      return *this;
   }

   // ------------------------
   // Conversion
   // ------------------------

   // helper
   template<class T>
   using converts = require<
      allowed<T,value::variant> ||
      same<T,std::nullptr_t> ||
      same<T,bool> ||
      same<T,std::string>
   >;

   // to arithmetic T, excluding bool
   // Assumes number, and forwards to its conversion to arithmetic T.
   // Returns by value; so, const only.
   template<class T, class = require<arithmetic<T> && !same<T,bool>>>
   operator T() const
   {
      return T(get<number>());
   }

   // to specific Ts; const
   template<class T, class = converts<T>>
   operator const T &() const
   {
      if constexpr (allowed<T,value::variant>)
         return get<T>();
      else if constexpr (same<T,std::nullptr_t>)
         return get<null>();
      else if constexpr (same<T,bool>)
         return get<boolean>();
      else if (has<literal>())
         return get<literal>();
      else
         return get<string>();
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
   template<class T, class = require<integral<T> || constructible<key,T>>>
   const value &operator[](const T &key) const
   {
      if constexpr (integral<T>)
         return get<array >()[key];
      else
         return get<object>()[key];
   }

   // non-const
   template<class T, class = require<integral<T> || constructible<key,T>>>
   value &operator[](const T &key)
   {
      // I think we want this direct, as written below, instead of doing this:
      //    return const_cast<value &>(std::as_const(*this).operator[](key));
      // because of the subtle difference between object's const and non-const
      // versions. See the "feature, not defect" remark for object::operator[].
      if constexpr (integral<T>)
         return get<array >()[key];
      else
         return get<object>()[key];
   }

   // ------------------------
   // Other
   // ------------------------

   // items
   const std::vector<pair> &items() const { return get<object>(); }
         std::vector<pair> &items()       { return get<object>(); }

   // has alternative
   template<
      class T, class = require<allowed<T,variant> || allowed<T,number::variant>>
   >
   bool has() const
   {
      if constexpr (allowed<T,variant>)
         return std::holds_alternative<T>(*this);
      else
         return has<number>() && get<number>().has<T>();
   }

   // has key
   // Assumes this value is an object
   bool has(const key &key) const
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
