
// -----------------------------------------------------------------------------
// string
// In JSON: string, in double quotes.
// -----------------------------------------------------------------------------

// Capital S String. We'll use <true> for string, <false> for key.
// Most constructs involving String can be defined for generic <bool>, so that
// code isn't replicated. It's worthwhile, though, to distinguish strings for
// JSON purposes (i.e. string as one of the JSON types {null, boolean, number,
// string, array, object}), and strings for key purposes. For example, class
// value's variant can hold a string, but not a key; and class object's vector
// is of key:value pairs, not of string:value pairs. Also, consider our system
// for creating colorized JSON output, which allows each of string and key to
// have its own color. By having two distinct types, the correct color can be
// selected naturally, in a non-hacky manner.

template<bool>
class String : public std::string {
public:
   JSON_IO(String);

   // ------------------------
   // Construction
   // ------------------------

   // inherited
   using std::string::string;

   // from instance of base class
   String(const std::string &from) : std::string(from) { }
   String(std::string &&from) : std::string(std::move(from)) { }

   // from char (exactly)
   template<class T, class = require<same<T,char>>>
   String(const T &from) : std::string{from} { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class T, class = require<assignable<std::string, T &&>>>
   String &operator=(T &&from)
   {
      return std::string::operator=(std::forward<T>(from)), *this;
   }
};

using string = String<true>;
