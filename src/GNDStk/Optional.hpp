
// -----------------------------------------------------------------------------
// Optional
// This alternative to std::optional uses a pointer, not containment. With
// our Optional, therefore, someone could have, for example, classes X and
// Y, where an X optionally contains a Y, and a Y optionally contains an X.
// -----------------------------------------------------------------------------

template<class T>
class Optional {

   T *ptr = nullptr;

public:

   using value_type = T;

   // construction, assignment
   #include "GNDStk/Optional/src/ctor.hpp"
   #include "GNDStk/Optional/src/assign.hpp"

   // value(), *, ->
   #include "GNDStk/Optional/src/value.hpp"

   // reset()
   void reset()
   {
      delete ptr;
      ptr = nullptr;
   }

   // clear()
   // Same as reset(). We just prefer this name.
   void clear()
   {
      reset();
   }

   // conversion to bool
   operator bool() const
   {
      return ptr;
   }

   // has_value
   bool has_value() const
   {
      return ptr;
   }
};
