
// -----------------------------------------------------------------------------
// object
// In JSON: {...}, with zero or more comma-separated key:value pairs.
// -----------------------------------------------------------------------------

class object : public std::vector<pair> {
public:

   // ------------------------
   // Construction
   // ------------------------

   // inherited
   using vector::vector;

   // from instance of base class
   object(const vector &from) : vector(from) { }
   object(vector &&from) : vector(std::move(from)) { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class T, class = require<assignable<vector, T &&>>>
   object &operator=(T &&from)
   {
      vector::operator=(std::forward<T>(from));
      return *this;
   }

   // ------------------------
   // operator[]
   // ------------------------

   // Provided directly - not inherited - because we want certain behavior
   // that std::vector's operator[] doesn't have.
   const value &operator[](const key &) const;
         value &operator[](const key &);

   // ------------------------
   // Other
   // ------------------------

   // has key
   bool has(const key &) const;

   // ------------------------
   // read, write
   // ------------------------

   template<class T = void, class U = void>
   auto /* std::string */ read(std::istream &is, const int = as_literal::none)
      -> decltype(number().read<T,U>(is,0)); // SFINAE: need number::read<T,U>

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
