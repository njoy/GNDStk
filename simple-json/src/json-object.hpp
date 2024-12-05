
// -----------------------------------------------------------------------------
// object
// In JSON: {...}, with zero or more comma-separated key:value pairs.
// -----------------------------------------------------------------------------

class object : public std::vector<pair> {
public:
   JSON_IO(object);

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
      return vector::operator=(std::forward<T>(from)), *this;
   }

   // ------------------------
   // operator[]
   // ------------------------

   // vector's: [index]
   using vector::operator[];

   // ours: [key]
   const value &operator[](const key &) const;
   value &operator[](const key &);

   // ------------------------
   // Other
   // ------------------------

   // key:value pairs
   const std::vector<pair> &pairs() const { return *this; }
   std::vector<pair> &pairs() { return *this; }

   // has key
   bool has(const key &) const;
};
