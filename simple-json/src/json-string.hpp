
// -----------------------------------------------------------------------------
// string
// In JSON: string, in double quotes.
// -----------------------------------------------------------------------------

class string : public std::string {
public:

   // ------------------------
   // Construction
   // ------------------------

   // inherited
   using std::string::string;

   // from instance of base class
   string(const std::string &from) : std::string(from) { }
   string(std::string &&from) : std::string(std::move(from)) { }

   // from char (exactly)
   template<class T, class = require<same<T,char>>>
   string(const T &from) : std::string{from} { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class T, class = require<assignable<std::string, T &&>>>
   string &operator=(T &&from)
   {
      std::string::operator=(std::forward<T>(from));
      return *this;
   }

   // ------------------------
   // read, write
   // ------------------------

   template<class T = void, class U = void>
   std::string read(std::istream &, const int = as_literal::none);

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
