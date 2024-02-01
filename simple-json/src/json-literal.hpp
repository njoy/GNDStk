
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
   // Explicit, so that std::string prefers string's constructor, not literal's.
   // We want literal to be something we get only by specifically asking for it.
   // Note also that this constructor's being explicit lets us dispense with the
   // enable_if business that we spoke of above class null's definition.
   explicit literal(const std::string &from) :
      str(from)
   { }

   // ------------------------
   // Conversion
   // ------------------------

   // to std::string
   operator const std::string &() const { return str; }
   operator std::string &() { return str; }

   // ------------------------
   // read, write
   // ------------------------

   template<class T = void, class U = void>
   std::string read(std::istream &, const int = as_literal::none);

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
