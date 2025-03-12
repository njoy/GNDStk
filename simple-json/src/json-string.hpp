
// -----------------------------------------------------------------------------
// string
// In JSON: string, in double quotes.
// -----------------------------------------------------------------------------

// Capital S String. We'll use <true> for json::string, <false> for json::key.
// Most constructs involving String can be defined for generic <bool>, so that
// code isn't replicated. It's worthwhile, though, to distinguish strings for
// JSON purposes (i.e. string as one of the JSON types), and strings for key
// purposes. For example, class value's variant can hold a string, but not a
// key; and class object's vector is of key:value pairs, not string:value pairs.
// Also, consider our system for creating colorized JSON output, which allows
// each of string and key to have its own color. By having two distinct types,
// the correct color can be selected naturally, in a non-hacky manner.

template<bool>
class String : public std::string {
public:
   JSON_IO(String);

   // ------------------------
   // Construction
   // ------------------------

   // inherited
   using std::string::string;

   // from std::string (instance of base class)
   String(const std::string &base) : std::string(base) { }
   String(std::string &&base) : std::string(std::move(base)) { }

   // from char (exactly)
   template<class CHAR, class = require<same<CHAR,char>>>
   String(const CHAR &from) : std::string{from} { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class FROM, class = require<assignable<std::string, FROM &&>>>
   String &operator=(FROM &&from)
   {
      return std::string::operator=(std::forward<FROM>(from)), *this;
   }
};

using string = String<true>;
