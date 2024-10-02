
// -----------------------------------------------------------------------------
// array
// In JSON: [...], with zero or more comma-separated values.
// -----------------------------------------------------------------------------

class array : public std::vector<value> {
public:

   // ------------------------
   // Construction
   // ------------------------

   // inherited
   using vector::vector;

   // from instance of base class
   array(const vector &from) : vector(from) { }
   array(vector &&from) : vector(std::move(from)) { }

   // constructor: from std::vector<T convertible to value>
   template<class T, class = require<convertible<T,value>>>
   array(const std::vector<T> &from) :
      vector(from.begin(), from.end())
   { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class T, class = require<assignable<vector, T &&>>>
   array &operator=(T &&from)
   {
      vector::operator=(std::forward<T>(from));
      return *this;
   }

   // ------------------------
   // read, write
   // ------------------------

   template<class T = void, class U = void>
   auto /* std::string */ read(std::istream &is, const int = as_literal::none)
      -> decltype(number().read<T,U>(is,0)); // SFINAE: need number::read<T,U>

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
