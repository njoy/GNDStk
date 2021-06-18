
// -----------------------------------------------------------------------------
// get<std::vector<T>>()
// -----------------------------------------------------------------------------

/*
------------------------
DESCRIPTION
------------------------

If remake == true:

   Warn if T and valueType appear to conflict with one another.
   Warn if length appears to be wrong.

   Make the vector<T> in the variant contain data from the raw string.
   INCLUDE any leading/trailing zeros as determined by start/length.

   Briefly: create vector<T> = [0 ... 0 values_from_raw_string 0 ... 0].
   Note that for the T == string case, 0 really means "" (empty string).

If remake == false:

   If the variant already contains a vector<T>:
      Return it; we're done
      *** Under correct and normal use of BodyText, this simple action
      will probably be the most common. ***

   Else:
      Convert the current vector in the variant into a vector<T>.
      Print a note to the effect that this might be unintentional.
      But the note can be switched off if the use *is* intentional.

Note that in the remake == false case, length, start, and valueType aren't
considered to be relevant, and aren't used at all, in any capacity whatsoever.

Basically, we're assuming that those values are meaningful ONLY in relation
to BodyText's raw string, so that we're not going to deal with them unless
we're remaking the vector from the raw string.

This way, callers can access, manipulate, and even completely change the
vector's contents or its type - basically, can work completely with a vector,
as someone working with data would surely often want to do - without length,
start, or valueType interfering with the process. Those values are considered
to be relevant ONLY when we absolutely must deal with the raw string, which
generally happens only during creation of the current object from a Node,
or creation of a Node from the current object. (And if we create a Node from
a vector in the current object, we'll figure those out for ourselves. See
the toNode() function for more information about this.)

If you wish for length, start, and valueType to be used, the way to do that
is as follows. Set the raw string to what you wish (using BodyText's string()
setter). And/or set remake = true directly (which in fact the string() setter
does). Also set length, start, or valueType to what you wish, either before
or after possibly setting the string. Then, finally, after doing all of that,
do a get<std::vector<T>>(). Then the vector in the variant is remade, per the
new string, length, etc., as described first above.

The return value is a const reference to a (possibly newly remade, possibly
existing, or possibly newly converted) vector<T> in the variant. Note that
because the variant was declared to be mutable, we were able to remake or
convert the vector, as already described; but we'll still return a const
reference, as the present object is conceptually constant, consistent with
mutable's meaning. But the resulting vector return is appropriately const
in this case. Note that we have a non-const version of get<std::vector<T>>,
too, for non-const *this (BodyText) objects.
*/



// -----------------------------------------------------------------------------
// get<std::vector<T>>()
// const version
// -----------------------------------------------------------------------------

template<class VECTOR>
typename std::enable_if<
   detail::is_oneof<VECTOR,decltype(variant)>::value &&
  !detail::isVariant<VECTOR>::value, // else is_oneof<the variant> passes
   const VECTOR &
>::type get(const bool print_type_change_note = true) const
{

   // ------------------------
   // if remake == true
   // ------------------------

   if (remake) {
      // Completely remake the vector from the raw string, making use of
      // length, start, and valueType.

      // Element type requested
      using T = typename VECTOR::value_type;

      // For this get() function, the caller stipulates VECTOR - a particular
      // vector type. We'll print a warning if VECTOR's element type appears
      // to conflict with a valueType other than "", but will return what the
      // caller requested, even if it doesn't match valueType.
      if ((vars.valueType == "Integer32" && !std::is_same_v<T,Integer32>) ||
          (vars.valueType == "Float64"   && !std::is_same_v<T,Float64  >)) {
         log::warning(
           "Element type T may be inconsistent with valueType == \"{}\";\n",
           "creating the requested std::vector<T> anyway",
            vars.valueType
         );
         log::member("BodyText::get<std::vector<T>>(), remake from raw string");
      }

      // Initialize
      variant = VECTOR{};
      VECTOR &to = std::get<VECTOR>(variant); // std::get, not this get :-)

      // [*****----------]: leading values, if any
      for (std::size_t i = 0; i < vars.start; ++i) {
         if constexpr (std::is_same<T,std::string>::value)
            to.push_back("");
         else
            to.push_back(T(0));
      }

      // [-----*****-----]: values from the raw string
      T element;
      std::istringstream iss(rawstring);
      while (iss >> element)
         to.push_back(element);

      // Print a warning if "length" appears to be impossible, because we
      // already have more than "length" values. (But length=0 is ignored.)
      if (0 < vars.length && vars.length < to.size()) {
         log::warning(
           "The given value length == {} appears to be wrong, because we\n"
           "already have {} values from start == {}, plus {} values read\n"
           "from the raw string, for a total of {} values.",
            vars.length,
            vars.start,
            vars.start,
            to.size() - vars.start,
            to.size()
         );
         log::member("BodyText::get<std::vector<T>>(), remake from raw string");
      }

      // [----------*****]: trailing values, if any
      for (std::size_t i = to.size(); i < vars.length; ++i) {
         if constexpr (std::is_same<T,std::string>::value)
            to.push_back("");
         else
            to.push_back(T(0));
      }

      remake = false; // because we just remade it
      return to;
   } // if (remake)


   // ------------------------
   // if remake == false
   // ------------------------

   // A vector of the requested type is what we already have
   if (std::holds_alternative<VECTOR>(variant))
      return std::get<VECTOR>(variant);

   // If we reach this point, it means two things. (1) We're NOT remaking
   // a vector from the raw string (that case was handled first.) (2) The
   // caller is requesting a vector of a different type than what we have
   // currently in the variant.
   //
   // So, for example, perhaps the variant currently has a vector<double>,
   // and a call get<std::vector<int>>() was made, meaning that the caller
   // wishes to get a vector<int>.
   //
   // BodyText is intended to store just one vector - one that represents
   // values in a GNDS node that has "body text." We don't, and shouldn't,
   // try to juggle multiple vectors of different types. Therefore, we'll
   // attempt to convert the existing vector to one of the requested type,
   // then place the new vector into the variant (replacing the old one.)
   //
   // This is arguably an odd situation, but one that might - might - have
   // some utility. (We're not sure yet.) So, we'll print an informational
   // note (not even a warning), then proceed.

   if (print_type_change_note) {
      log::info(
         "Reworking vector of one type into vector of another type;\n"
         "was this intentional?"
      );
      log::member("BodyText::get<std::vector<T>>()");
   }

   // Initialize new vector
   VECTOR newVector;
   newVector.reserve(size());

   // Convert elements from the old vector to the new vector
   std::visit(
      [&newVector](auto &&oldVector)
      {
         // Types
         // Note that the F(rom) and T(o) element types will be different
         // here, as the holds_alternative test, earlier in this function,
         // would otherwise have triggered a return at that point. That
         // was, however, a run-time test, so we've formulated the below
         // code so that it still compiles (but does nothing) for F == T.
         using F = typename
            detail::remove_cvref<decltype(oldVector[0])>::type; // from
         using T = typename
            detail::remove_cvref<decltype(newVector[0])>::type; // to

         // We don't use to_string() below, so that we can eventually deal
         // with precision. to_string() might be insufficient for our needs.
         // todo: see if GNDStk's convert() free functions are appropriate
         // for doing all possible cases here, or could be extended to be.
         for (auto &from : oldVector) {

            // string ==> arithmetic
            if constexpr (
               std::is_same<F,std::string>::value &&
              !std::is_same<T,std::string>::value
            ) {
               std::istringstream iss(from);
               T to;
               iss >> to;
               newVector.push_back(to);
            }

            // arithmetic ==> string
            if constexpr (
              !std::is_same<F,std::string>::value &&
               std::is_same<T,std::string>::value
            ) {
               std::ostringstream oss;
               oss << from; // <== precision would be relevant here
               newVector.push_back(oss.str());
            }

            // arithmetic ==> arithmetic
            if constexpr (
              !std::is_same<F,std::string>::value &&
              !std::is_same<T,std::string>::value
            ) {
               newVector.push_back(T(from));
            }
         };
      },

      const_cast<std::remove_const<decltype(variant)>::type &>(variant)
   );

   // Replace the existing vector with the new vector
   variant = newVector;
   return std::get<VECTOR>(variant);
}



// -----------------------------------------------------------------------------
// get<std::vector<T>>()
// non-const version
// -----------------------------------------------------------------------------

template<class VECTOR>
typename std::enable_if<
   detail::is_oneof<VECTOR,decltype(variant)>::value &&
  !detail::isVariant<VECTOR>::value, // else is_oneof<the variant> passes
   VECTOR &
>::type get(const bool print_type_change_note = true)
{
   // The usual rigmarole for implementing non-const in terms of const...
   return const_cast<VECTOR &>(
      std::as_const(*this).template get<VECTOR>(print_type_change_note)
   );
}



// -----------------------------------------------------------------------------
// get<T>(n)
// -----------------------------------------------------------------------------

// These can trigger a complete remake of the vector if it isn't already of type
// vector<T>, for the given T. This is intentional, in order to provide maximum
// flexibility. However, be aware of it, for the sake of efficiency! In general,
// when using a BodyText object, we recommend sticking with one underlying type.
// Say, calling the above as get<std::vector<double>>(), or one of the following
// with get<double>(n).

// const
template<class T>
typename std::enable_if<
   detail::is_oneof<std::vector<T>,decltype(variant)>::value,
   const T &
>::type get(const std::size_t n, const bool print_type_change_note = true) const
{
   try {
      return get<std::vector<T>>(print_type_change_note)[n];
   } catch (...) {
      log::member("BodyText::get<T>({})", n);
      throw;
   }
}

// non-const
template<class T>
typename std::enable_if<
   detail::is_oneof<std::vector<T>,decltype(variant)>::value,
   T &
>::type get(const std::size_t n, const bool print_type_change_note = true)
{
   return const_cast<T &>(
      std::as_const(*this).template get<T>(n,print_type_change_note)
   );
}



// -----------------------------------------------------------------------------
// get()
// Perform a get<std::vector<T>> with T determined by valueType.
// Whether or not start and length are used depends on circumstances,
// as described in detail for get<std::vector<T>>.
// -----------------------------------------------------------------------------

// const
const auto &get(const bool print_type_change_note = true) const
{
   if (vars.valueType == "Integer32")
      get<std::vector<Integer32>>(print_type_change_note);
   else if (vars.valueType == "Float64")
      get<std::vector<Float64>>(print_type_change_note);
   else
      get<std::vector<std::string>>(print_type_change_note);

   // We can't return the specific variant *alternative* that exists right
   // now, because that depended on valueType (run-time). So, we'll return
   // the whole variant, for whatever use that might have to a caller.
   return variant;
}

// non-const
auto &get(const bool print_type_change_note = true)
{
   return const_cast<decltype(variant) &>(
      std::as_const(*this).get(print_type_change_note)
   );
}



// -----------------------------------------------------------------------------
// Type-specific "get()" functions.
// Function names reflect the types: strings(), ints(), doubles(), etc.
// These provide convenient, shorthand access to specific get<vector<T>s.
// -----------------------------------------------------------------------------

#define GNDSTK_MAKE_GETTER(name,T) \
   /* const */ \
   const auto &name(const bool print_type_change_note = true) const \
   { \
      return get<std::vector<T>>(print_type_change_note); \
   } \
   /* non-const */ \
   auto &name(const bool print_type_change_note = true) \
   { \
      return get<std::vector<T>>(print_type_change_note); \
   }

GNDSTK_MAKE_GETTER(strings,     std::string);

GNDSTK_MAKE_GETTER(schars,      signed char);
GNDSTK_MAKE_GETTER(shorts,      short);
GNDSTK_MAKE_GETTER(ints,        int);
GNDSTK_MAKE_GETTER(longs,       long);
GNDSTK_MAKE_GETTER(longlongs,   long long);

GNDSTK_MAKE_GETTER(uchars,      unsigned char);
GNDSTK_MAKE_GETTER(ushorts,     unsigned short);
GNDSTK_MAKE_GETTER(uint,        unsigned int);
GNDSTK_MAKE_GETTER(ulongs,      unsigned long);
GNDSTK_MAKE_GETTER(ulonglongs,  unsigned long long);

GNDSTK_MAKE_GETTER(floats,      float);
GNDSTK_MAKE_GETTER(doubles,     double);
GNDSTK_MAKE_GETTER(longdoubles, long double);

#undef GNDSTK_MAKE_GETTER
