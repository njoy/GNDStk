
// -----------------------------------------------------------------------------
// array
// In JSON: [...], with zero or more comma-separated values.
// -----------------------------------------------------------------------------

class array : public std::vector<value> {
public:
   JSON_IO(array);

   // ------------------------
   // Construction
   // ------------------------

   // inherited
   using vector::vector;

   // from instance of base class
   array(const vector &from) : vector(from) { }
   array(vector &&from) : vector(std::move(from)) { }

   // from std::vector<T convertible to value>
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
      return vector::operator=(std::forward<T>(from)), *this;
   }

   // ------------------------
   // Other
   // ------------------------

   // values
   const std::vector<value> &values() const { return *this; }
   std::vector<value> &values() { return *this; }
};
