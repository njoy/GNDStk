
// -----------------------------------------------------------------------------
// boolean
// In JSON: lower-case true or false.
// -----------------------------------------------------------------------------

class boolean {
   bool b;

public:

   // ------------------------
   // Construction
   // ------------------------

   // default
   boolean() :
      b(false)
   { }

   // from bool
   template<class T, class = std::enable_if_t<std::is_same_v<T,bool>>>
   boolean(const T &from) :
      b(from)
   { }

   // ------------------------
   // Conversion
   // ------------------------

   // to bool
   operator const bool &() const { return b; }
   operator bool &() { return b; }

   // ------------------------
   // read, write
   // ------------------------

   template<class T = void, class U = void>
   std::string read(std::istream &, const int = as_literal::none);

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
