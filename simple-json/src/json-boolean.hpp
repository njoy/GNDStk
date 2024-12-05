
// -----------------------------------------------------------------------------
// boolean
// In JSON: lower-case true or false.
// -----------------------------------------------------------------------------

class boolean {
   bool b;

public:
   JSON_IO(boolean);

   // ------------------------
   // Construction
   // ------------------------

   // default
   boolean() : b(false) { }

   // from bool (exactly)
   template<class T, class = require<same<T,bool>>>
   boolean(const T &from) : b(from) { }

   // ------------------------
   // Conversion
   // ------------------------

   // to bool
   operator const bool &() const { return b; }
   operator bool &() { return b; }
};
