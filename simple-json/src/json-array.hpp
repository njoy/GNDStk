
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

   // from std::vector<value> (instance of base class)
   array(const vector &base) : vector(base) { }
   array(vector &&base) : vector(std::move(base)) { }

   // from std::vector<T convertible to value>
   template<class T, class = require<convertible<T,value>>>
   array(const std::vector<T> &vec) :
      vector(vec.begin(), vec.end())
   { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class FROM, class = require<assignable<vector, FROM &&>>>
   array &operator=(FROM &&from)
   {
      return vector::operator=(std::forward<FROM>(from)), *this;
   }

   // ------------------------
   // Other
   // ------------------------

   // values
   const std::vector<value> &values() const { return *this; }
   std::vector<value> &values() { return *this; }
};
