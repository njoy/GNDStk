
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
   using variant::variant;
   using variant::operator=;
   value(const variant &from) : variant(from) { }
   value(variant &&from) : variant(std::move(from)) { }

   // ------------------------
   // Constructors
   // ------------------------

   value() : variant(object()) { }
   value(const std::initializer_list<value> &from) : variant(array(from)) { }
   value(const std::initializer_list<pair> &from) : variant(object(from)) { }

   // ------------------------
   // Assignment operators
   // ------------------------

   // assignment: from T convertible to anything in the variant
   template<class T, class = std::enable_if_t<detail::tovar<T,variant>>>
   value &operator=(const T &from)
   {
      return static_cast<variant &>(*this) = from, *this;
   }

   // zzz Is this necessary?
   // assignment: from std::vector<T convertible to anything in the variant>
   template<class T>
   value &operator=(const std::vector<T> &from)
   {
      return static_cast<variant &>(*this) = array(from), *this;
   }

   // assignment: from std::initializer_list<value>
   value &operator=(const std::initializer_list<value> &from)
   {
      return static_cast<variant &>(*this) = array(from), *this;
   }

   // assignment: from std::initializer_list<pair>
   value &operator=(const std::initializer_list<pair> &from)
   {
      return static_cast<variant &>(*this) = object(from), *this;
   }

   // ------------------------
   // Miscellaneous
   // ------------------------

   // read, write
   template<class T = void, class U = void>
   auto read(std::istream &is, const int = as_literal::none)
      -> decltype(number().read<T,U>(is,0)); // SFINAE: need number::read<T,U>
   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;

   // has
   template<class T>
   bool has() const { return std::holds_alternative<T>(*this); }

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

   // contains
   bool contains(const string &key) const
   { return has<object>() && get<object>().contains(key); }

   // operator[]
   value &operator[](const string &key)
   { return get<object>()[key]; }
   const value &operator[](const string &key) const
   { return get<object>()[key]; }

   // items
   const std::vector<pair> &items() const { return get<object>().items(); }
   std::vector<pair> &items() { return get<object>().items(); }
};
