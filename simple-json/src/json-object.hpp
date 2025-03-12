
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

   // from std::vector<pair> (instance of base class)
   object(const vector &base) : vector(base) { }
   object(vector &&base) : vector(std::move(base)) { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class FROM, class = require<assignable<vector, FROM &&>>>
   object &operator=(FROM &&from)
   {
      return vector::operator=(std::forward<FROM>(from)), *this;
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
