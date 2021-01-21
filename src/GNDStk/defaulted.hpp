
// -----------------------------------------------------------------------------
// defaulted
// -----------------------------------------------------------------------------

/*
This class represents an "optional, with default" concept, for handling values
in GNDS files that can appear optionally, but are considered to have particular
defaults when they don't appear.

Template parameter T:
This is, as you'd expect, the underlying type. A defaulted<T> contains a default
value of type T, which *must* be provided in any constructor you call, as well
as a std::optional<T> that optionally contains what we'll call a "hard value":
a value that's considered to be other than the default.

Template parameter WRITES:
We plan to use this when integrating native handling of defaulted objects into
GNDStk. The question is: In applicable output functions (for example, GNDStk's
Node::add() functions), should an "optional, with default" value be written out
unconditionally - whether its value is its default, or a hard value - or should
it only be written if it has a non-default value? After all, the idea of a value
having a default suggests that we don't necessarily want to clutter a GNDS file
with something's value even when that value is the default. If we always wanted
to write *defaults*, that arguably would defeat the purpose of having them.

We decided to make WRITES be a template parameter, not a data member, in part
because we don't really anticipate that someone would wish to modify such a
property after setting up an object in the first place. And, because compilers
generally pad data structures so that they align well in memory, it turns out
that including this single extra bool as a data member would typically increase
an object's sizeof() by - for small Ts, at least - a relatively large amount.
Given these two factors, we believe that having WRITES be a template parameter
will probably serve us best.

Note that you can give a defaulted<T> a hard value that happens to equal its
default. If you do, then the value is indeed considered to be a hard value -
not the default. That is, the data structure does distinguish those situations,
as we believe it should.
*/

template<class T, bool WRITES = false>
class defaulted {

   // ------------------------
   // data
   // ------------------------

   // Default value
   // Unconditionally const, regardless of whether or not *this is const.
   // We think it's most reasonable to say that a "defaulted" object's
   // default value is defined once, when the object is constructed, and
   // then the stipulated default is fixed in stone. Otherwise, we'd need
   // to ask questions like this: If a defaulted object with one default
   // is assigned to a defaulted object with a different default, then is
   // only the value - or the default as well - assigned? Either behavior
   // would arguably be reasonable, if we accepted the notion that an
   // initially provided default should be possible to change.
   const T def;

   // Optional non-default value
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

   #include "GNDStk/defaulted/src/ctor.hpp"
   #include "GNDStk/defaulted/src/assign.hpp"

   // value(), *, ->, convert to T
   #include "GNDStk/defaulted/src/value.hpp"

   // has_value(), is_default() (opposite tests)
   #include "GNDStk/defaulted/src/has.hpp"

   // raw data access: get_default(), get_optional()
   #include "GNDStk/defaulted/src/get.hpp"

   // reset(), a.k.a. clear()
   #include "GNDStk/defaulted/src/reset.hpp"

   // writes(), quiet(): new defaulted with WRITES flag true or false
   #include "GNDStk/defaulted/src/writes.hpp"
};
