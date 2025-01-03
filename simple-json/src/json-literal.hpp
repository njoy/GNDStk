
// -----------------------------------------------------------------------------
// literal
// Content to be printed exactly as-is, without quotes or any processing.
// Special type for our API.
// -----------------------------------------------------------------------------

class literal {
   std::string str;

public:
   JSON_IO(literal);

   // ------------------------
   // Flags
   // ------------------------

   // See the read() functions in various classes. The following allow for
   // specification of which standard JSON types should be read as literals.
   // A flag to indicate the present (literal) class itself is excluded; it
   // isn't meaningful for these purposes. Note that these are given directly
   // as unsigned ints (not, say, as enumerator values); their expected use is
   // in bitwise operations. Remark: These are not, in any particular respect,
   // tightly associated with the functionality of this literal class. Their
   // purpose, however, like that of this class, is to support our ability to
   // handle literal JSON content. Placing them here (not, say, in a namespace
   // with a similar but different name) helps us to avoid name clutter.
   static inline constexpr unsigned
      // standard JSON types
      null    = 0b0000001,
      boolean = 0b0000010,
      number  = 0b0000100,
      string  = 0b0001000,
      array   = 0b0010000,
      object  = 0b0100000,
      // none/all of the above
      none    = 0b0000000,
      all     = 0b0111111,
      // self
      self    = 0b1000000;

   // ------------------------
   // Construction
   // ------------------------

   // default
   literal() { }

   // from std::string
   // Explicit, so that std::string prefers json::string's constructor, not
   // json::literal's. We want to get literal only when it's explicitly wanted.
   explicit literal(const std::string &s) : str(s) { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class FROM, class = require<assignable<std::string, FROM &&>>>
   literal &operator=(FROM &&from)
   {
      return str = from, *this;
   }

   // ------------------------
   // Conversion
   // ------------------------

   // to std::string
   operator const std::string &() const { return str; }
   operator std::string &() { return str; }
};
