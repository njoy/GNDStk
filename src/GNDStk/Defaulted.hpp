
// -----------------------------------------------------------------------------
// Defaulted
// -----------------------------------------------------------------------------

/*
This class represents an "optional, with default" concept, for handling values
in GNDS files that can appear optionally, but are considered to have particular
defaults when they don't appear.

T is, as you'd expect, the underlying type. A Defaulted<T> contains a default
value of type T, which *must* be provided in any constructor you call, as well
as a std::optional<T> that optionally contains what we'll call a "hard value":
a value that's considered to be other than the default.

Note that you can give a Defaulted<T> a hard value that happens to equal its
default. If you do, then the value is considered to be a hard value - not the
default. That is to say, the data structure does distinguish "has its default"
versus "has a value that coincidentally happens to equal its default." It's an
issue of how you construct and then modify (or don't modify) the object.
*/

template<class T>
class Defaulted {

   // ------------------------
   // data
   // ------------------------

   // The default
   // Unconditionally const, regardless of whether or not *this is const.
   // We think it's most reasonable to say that a "Defaulted" object's
   // default value is defined once, when the object is constructed, and
   // then the stipulated default is fixed in stone. Otherwise, we'd need
   // to ask questions like this: If a Defaulted object with one default
   // is assigned to a Defaulted object with a different default, then is
   // only the value - or the default as well - assigned? Either behavior
   // would arguably be reasonable, if we accepted the notion that an
   // initially provided default should be possible to change.
   const T def;

   // An optional non-default value
   std::optional<T> opt;

   // Interpretation: if the std::optional contains a value, then that
   // value is considered to be this object's value, and this object is
   // considered to have a value that is *not* its default (even if the
   // value contained in the std::optional happens to be the same as the
   // default). If, however, the std::optional does not contain a value,
   // then this object is considered to have its default value, def.

   // ------------------------
   // functions
   // ------------------------

public:

   #include "GNDStk/Defaulted/src/ctor.hpp"
   #include "GNDStk/Defaulted/src/assign.hpp"

   // value(), *, ->, convert to T
   #include "GNDStk/Defaulted/src/value.hpp"

   // has_value(), is_default() (opposite tests)
   #include "GNDStk/Defaulted/src/has.hpp"

   // raw data access: get_default(), get_optional()
   #include "GNDStk/Defaulted/src/get.hpp"

   // reset(), a.k.a. clear()
   #include "GNDStk/Defaulted/src/reset.hpp"
};
