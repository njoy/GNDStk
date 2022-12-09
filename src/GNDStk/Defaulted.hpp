
// -----------------------------------------------------------------------------
// Defaulted
// -----------------------------------------------------------------------------

/*
This class implements an "optional, with default" concept, for handling values
in GNDS files that can appear optionally, and are considered to have particular
defaults when they don't appear.

T is, as you'd expect, the underlying type. A Defaulted<T> contains a desired
default value of type T; this *must* be provided in any constructor you call.
It also contains a std::optional<T> that optionally contains what we'll call
a "hard value": a value that's considered to be other than the default.

Note that you can explicitly give a Defaulted object a value that happens to
equal its default. If you do, then the value is considered to be a hard value,
not the Defaulted object's default. That is to say, the data structure *does*
distinguish "has its default" from "has a value that coincidentally happens to
be equal to its default."

The above distinction has ramifications when a Defaulted object is written.
Specifically, when a Defaulted object is written to a Node: (1) If the object
has a hard value, the hard value is written. (2) If the object has only its
default value, then nothing is written. In case (2), the Node's lack of any
value, for the quantity that was represented by the Defaulted object, should
be understood to mean that the value has its default.
*/

template<class T>
class Defaulted {

   // ------------------------
   // data
   // ------------------------

   // The default
   T def;

   // An optional value
   std::optional<T> opt;

   // Interpretation: if the std::optional contains a value, then that value
   // is considered to be this object's value, and this object is considered
   // to have a value that is *not* its default (even if the value contained
   // in the std::optional happens to be the same as the default). If, however,
   // the std::optional does not contain a value, then this object is considered
   // to have its default.

   // ------------------------
   // functions
   // ------------------------

public:

   using value_type = T;

   // construction, assignment
   #include "GNDStk/Defaulted/src/ctor.hpp"
   #include "GNDStk/Defaulted/src/assign.hpp"

   // value(), *, ->, conversion to T
   #include "GNDStk/Defaulted/src/value.hpp"

   // has_value(), is_default() (opposite tests)
   #include "GNDStk/Defaulted/src/has.hpp"

   // raw data access: get_default(), get_optional()
   #include "GNDStk/Defaulted/src/get.hpp"

   // reset(), a.k.a. clear()
   #include "GNDStk/Defaulted/src/reset.hpp"
};
