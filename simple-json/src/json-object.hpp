
// -----------------------------------------------------------------------------
// object
// In JSON: {...}, with zero or more comma-separated key:value pairs.
// -----------------------------------------------------------------------------

class object : public std::vector<pair> {
public:
   using vector::vector;
   using vector::operator=;
   object(const vector &from) : vector(from) { }
   object(vector &&from) : vector(std::move(from)) { }
   object &operator=(const vector &from)
   { static_cast<vector &>(*this) = from; return *this; }
   object &operator=(vector &&from)
   { static_cast<vector &>(*this) = std::move(from); return *this; }

   // read, write
   template<class T = void, class U = void>
   auto read(std::istream &is, const int = as_literal::none)
      -> decltype(number().read<T,U>(is,0)); // SFINAE: need number::read<T,U>
   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;

   // items
   // Returns the std::vector base.
   const vector &items() const { return *this; }
   vector &items() { return *this; }

   // operator[]
   // Provided directly - not inherited - because we want certain behavior
   // that std::vector's operator[]s don't have.
   value &operator[](const string &key);
   const value &operator[](const string &key) const;

   // contains
   bool contains(const string &key) const;
};
