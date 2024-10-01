
// -----------------------------------------------------------------------------
// literal
// String content to be printed exactly as-is, without quotes or any processing.
// Special type for our API.
// -----------------------------------------------------------------------------

class literal {
   std::string str;

public:

   // ------------------------
   // Construction
   // ------------------------

   // default
   literal() { }

   // from std::string
   // Explicit, so that std::string prefers json::string's constructor, not
   // json::literal's. We want json::literal to be something we get only by
   // specifically asking for it.
   explicit literal(const std::string &from) : str(from) { }

   // ------------------------
   // Assignment
   // ------------------------

   template<
      class T,
      class = std::enable_if_t<std::is_assignable_v<std::string, T &&>>>
   literal &operator=(T &&from)
   {
      str = from;
      return *this;
   }

   // ------------------------
   // Conversion
   // ------------------------

   // to std::string
   operator const std::string &() const { return str; }
   operator       std::string &()       { return str; }

   // ------------------------
   // read, write
   // ------------------------

   template<class T = void, class U = void>
   std::string read(std::istream &, const int = as_literal::none);

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
