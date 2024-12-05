
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
   // ------------------------
   // Helper constructs
   // ------------------------

   // read
   template<class T, class U, class JCLASS>
   literal read(
      std::istream &is, const unsigned flags, const unsigned lit
   ) {
      std::string text;
      if (flags & lit) {
         // This value <== a literal representation of JCLASS
         JCLASS tmp;
        *this = literal(text = tmp.template read<T,U>(is, literal::self));
      } else {
         // This value <== a JCLASS
         // read variant (= JCLASS()) in-place for efficiency
         text = (*this=JCLASS(), get<JCLASS>()).template read<T,U>(is,flags);
      }
      return literal(flags & literal::self ? text : "");
   }

   // converts
   template<class T>
   static inline constexpr bool converts =
      invar<T,variant> ||
      same<T,std::nullptr_t> || same<T,bool> || same<T,std::string> ||
      same<T,std::vector<value>> || same<T,std::vector<pair>>;

public:
   JSON_IO(value);

   // ------------------------
   // Construction
   // ------------------------

   // inherited
   using variant::variant;

   // default (override inherited, because we want to select object)
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
      return variant::operator=(std::forward<T>(from)), *this;
   }

   // ------------------------
   // Conversion
   // ------------------------

   // Remark: A question arises about how to handle conversion of json::value
   // to bool (not to json::boolean, that is, but to C++ bool.) I.e., what do
   // we do with bool(v), for a json::value v? If we assume *this is a number,
   // we can use number's conversion operator. It returns by value, for maximum
   // usability. If we assume *this is a boolean, we can return a const or non-
   // const reference to the boolean's underlying bool. We could determine at
   // run time if *this contains a number or a boolean, but then must restrict
   // ourselves to return by value either way, because return type is fixed at
   // compile time. We decided to interpret bool(v) as meaning we'll need *this
   // to be a json::boolean. A const or non-const reference is then returned,
   // consistent with the return when T underlies other alternatives json::value
   // can take - std::nullptr_t within null, array's base of std::vector<value>,
   // etc. We think this is the best choice, overall. It does mean that if *this
   // contains a number that you want to make into bool (think 0=false, 1=true),
   // then you'll need to write something like bool(int(v)), not bool(v).

   // to T in number's variant
   // Assumes number, and forwards to number's conversion.
   // Returns by value; so, const only.
   template<class T, class = require<invar<T,number::variant>>>
   operator T() const
   {
      return T(get<number>());
   }

   // to various specific Ts: const
   // T is std::nullptr_t, bool, std::string, std::vector<json::value> (json::
   // array's base), or std::vector<json::pair> (json::object's base), or else
   // is one of the alternatives in json::value's variant.
   template<class T, class = require<converts<T>>>
   operator const T &() const
   {
      if constexpr (same<T,std::nullptr_t>)
         return get<null>();    // then our null ==> C++ std::nullptr_t (T)
      else if constexpr (same<T,bool>)
         return get<boolean>(); // then our boolean ==> C++ bool (T)
      else if constexpr (same<T,std::vector<value>>)
         return get<array>();   // then our array ==> C++ std::vector<value> (T)
      else if constexpr (same<T,std::vector<pair>>)
         return get<object>();  // then our object ==> C++ std::vector<pair> (T)
      else if constexpr (invar<T,variant>)
         return get<T>();       // T as-is
      // T is std::string henceforth, by process of elimination...
      else if (holds<string>())
         return get<string>();  // then our string ==> C++ std::string (T)
      else
         return get<literal>(); // then our literal ==> C++ std::string (T)
   }

   // to various specific Ts: non-const
   template<class T, class = require<converts<T>>>
   operator T &()
   {
      return const_cast<T &>((const T &)(std::as_const(*this)));
   }

   // ------------------------
   // operator[]
   // ------------------------

   // Remark: json::array, json::object, and json::value (the present class)
   // all have operator[]s:
   //    - array has [index] through its vector<value> base.
   //    - object has [index] through its vector<key:value pair> base,
   //         but also has [key] to support lookup by key.
   //    - value allows [index] or [key], as defined below.
   // Consider the relevant return types for array and object's operator[]s:
   //    array [index] ==> value
   //    object[index] ==> key:value pair
   //    object[key  ] ==> value
   // What happens, below, if somebody sends an index (the integral<T> option
   // in the SFINAE requirement), not a key? In principle, an index is usable
   // in two places: array (returning a value), and object (returning a pair).
   // We'll only know at run time whether *this value is an array, an object,
   // or perhaps neither (in the "neither" case, these shouldn't be called!),
   // but the return type must be determined at compile time. With the [index]
   // case arguably being ambiguous (return array value, or object pair?), we
   // could simply disallow it, and only support [key]. However, we believe
   // that a flexible operator[] is convenient to have, and decided to do the
   // following. If [index], decide at run time if *this is array or an object.
   // If it's an array, then return "array[index]" - a value. If it's an object,
   // then return "object[index].second" - also a value (the second part of the
   // key:value pair). If it's a [key], then handle it in the only way possible:
   // assume *this is an object, and return "object[key]", which itself finds
   // the key:value pair for that key and returns its .second - a value. In all
   // of these cases, then, the following operator[]s return [const] value &.

   // const
   template<class T, class = require<integral<T> || constructible<key,T>>>
   const value &operator[](const T &t) const
   {
      if constexpr (integral<T>)
         return holds<array>() ? get<array>()[t] : get<object>()[t].second;
      else
         return get<object>()[t];
   }

   // non-const
   template<class T, class = require<integral<T> || constructible<key,T>>>
   value &operator[](const T &t)
   {
      // We define this directly, as written below, instead of doing:
      //    return const_cast<value &>(std::as_const(*this).operator[](t));
      // because of the subtle difference between object's const and non-const
      // versions. See the "feature, not defect" remark for object::operator[].
      if constexpr (integral<T>)
         return holds<array>() ? get<array>()[t] : get<object>()[t].second;
      else
         return get<object>()[t];
   }

   // ------------------------
   // Other
   // ------------------------

   // values; assumes this value is an array
   // pairs (key:value pairs); assumes this value is an object
   const std::vector<value> &values() const { return get<array>(); }
   std::vector<value> &values() { return get<array>(); }
   const std::vector<pair> &pairs() const { return get<object>(); }
   std::vector<pair> &pairs() { return get<object>(); }

   // has key
   // Assumes this value is an object
   bool has(const key &key) const
   {
      return get<object>().has(key);
   }

   // holds<T>
   template<class T>
   require<invar<T,variant> || invar<T,number::variant>, bool> holds() const
   {
      if constexpr (invar<T,variant>)
         return std::holds_alternative<T>(*this);
      else
         return holds<number>() && get<number>().holds<T>();
   }

   // get<T>: const
   template<class T>
   require<invar<T,variant> || invar<T,number::variant>, const T &> get() const
   {
      if constexpr (invar<T,variant>)
         return std::get<T>(*this);
      else
         return get<number>().get<T>();
   }

   // get<T>: non-const
   template<class T>
   require<invar<T,variant> || invar<T,number::variant>, T &> get()
   {
      return const_cast<T &>(std::as_const(*this).template get<T>());
   }

   // make
   template<class T, class = require<invar<T,number::variant> || converts<T>>>
   bool make(T &, const bool = true) const;
};
