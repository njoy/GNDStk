
// -----------------------------------------------------------------------------
// Cases
// -----------------------------------------------------------------------------

/*
Return reference to [const] vector<T>:
   get<std::vector<T>> const
   get<std::vector<T>>

Return reference to [const] T:
   get<T>(n) const
   get<T>(n)

Return reference to [const] variant of vector<T>s:
   get() const
   get()

Return variant of Ts:
   get(n) const
   operator[](n) const

A reference return isn't possible in the get(n) case, because there's
no variant<scalars> to reference. So, it has a value return.

We also provide type-specific getters with specific names:

   const std::vector<T> &name() const
   std::vector<T> &name()
   const T &name(n) const
   T &name(n)

For example, name == doubles when T == double.
*/



// -----------------------------------------------------------------------------
// get<std::vector<T>>()
// -----------------------------------------------------------------------------

/*
------------------------
DESCRIPTION
------------------------

If active == string:

   Warn if T appears to conflict with valueType.
   Warn if length appears to be wrong.

   Make the vector<T> in the variant contain data from the raw string.
   INCLUDE any leading and trailing zeros, per start and length.
   Note that length == 0 is interpreted as no particular length prescribed.

   Briefly: create vector<T> = [0 ... 0 values_from_raw_string 0 ... 0].
   For the T == string case, 0 really means "" (empty string).

If active == vector:

   If the variant already contains a vector<T>:
      Return it; we're done.
      *** Under the correct and normal use of BodyText, ***
      *** this simple action will probably be the most common. ***

   Else:
      Convert the variant's vector<non-T> into a vector<T>.
      Print a note to the effect that this might be unintentional.
      The note can be suppressed if the call *is* intentional.

In the active == vector case, length, start, and valueType aren't considered
to be relevant, and play no role. We consider those values to be meaningful
ONLY in relation to BodyText's raw string, and we deal with them here only
if and when we make the vector from the raw string.

That way, callers can access, manipulate, and even completely change the
vector's contents or its type - basically, can work in peace with a vector,
as someone working with data would surely often want to do - without length,
start, or valueType interfering with the process. Those values are considered
to be relevant ONLY when we absolutely must deal with the raw string. This
generally happens only during creation of the current object from a Node,
or creation of a Node from the current object. (And if we create a Node from
a vector in the current object, then we'll compute length, etc. for ourselves.
See the toNode() function for more information about that.)

Therefore, if you want length, start, and valueType to be used, then proceed
as follows. Set the raw string to what you wish, using the string() setter.
Set length, start, or valueType as you wish, either before or after possibly
setting the string. Finally, after doing all that, do a get<std::vector<T>>().
Then the vector in the variant will be remade, per the new string and/or the
length etc. parameters, as described earlier in this descriptive comment, if
and when a get<vector<T>> function is next called.

The return value of the const version is a const reference to a (possibly
newly converted-to from the raw string, possibly existing, or possibly remade)
vector<T> in the variant. Note that because the variant was declared to be
mutable, we were indeed able to rebuild the vector if doing so was necessary.
But we'll still return a *const* reference in that case, because the present
object is conceptually const, and a caller shouldn't therefore be allowed to
modify the vector outside of BodyText's machinery.

Of course we also have a non-const version, for a non-const *this.
*/


// const
template<class VECTOR>
std::enable_if_t<
   detail::isAlternative<VECTOR,VariantOfVectors>,
   const VECTOR &
> get() const
{
   // Element type requested
   using T = typename VECTOR::value_type;


   // ------------------------
   // if active == string
   // ------------------------

   if (active == Active::string) {
      static const std::string context_rebuilding =
         "BodyText::get<std::vector<T>>(), remade from raw string";

      // Completely rebuild the vector from the raw string, making use of
      // length, start, and valueType.

      // For this get(), the caller has stipulated a particular vector type.
      // We'll print a warning if that type appears to conflict with valueType,
      // or if valueType isn't something we know what to do with. In any event,
      // we'll return what the caller requested. Note that valueType = "" (the
      // empty string) is acceptable with any element type.

      bool consistent = true;
      if (valueType() == "Integer32") {
         if (!std::is_same_v<T,Integer32>)
            consistent = false;
      } else if (valueType() == "Float64") {
         if (!std::is_same_v<T,Float64>)
            consistent = false;
      } else if (valueType() != "") {
         log::warning(
           "Unrecognized valueType == \"{}\"; ignoring",
            valueType()
         );
         log::member(context_rebuilding);
      }

      if (!consistent) {
         log::warning(
           "Element type T may be inconsistent with valueType == \"{}\";\n",
           "we'll create the requested std::vector<T> anyway",
            valueType()
         );
         log::member(context_rebuilding);
      }

      // Initialize
      variant = VECTOR{};
      VECTOR &to = std::get<VECTOR>(variant); // std::get, not this get :-)

      T zero;
      if constexpr (std::is_same_v<T,std::string>) zero = ""; else zero = T(0);

      // [*****----------]: leading 0s
      for (std::size_t i = 0; i < start(); ++i)
         to.push_back(zero);

      // [-----*****-----]: values from the raw string
      T element;
      std::istringstream iss(rawstring);
      while (iss >> element)
         to.push_back(element);

      // Print a warning if length appears to be impossible because we already
      // have more than that number of values. (But length == 0 is ignored.)
      if (0 < length() && length() < to.size()) {
         log::warning(
           "The value of length == {} appears to be wrong, because we\n"
           "already have {} values from start == {}, plus {} values read\n"
           "from the raw string, for a total of {} values.",
            length(),
            start(),
            start(),
            to.size() - start(),
            to.size()
         );
         log::member(context_rebuilding);
      }

      // [----------*****]: trailing 0s
      for (std::size_t i = to.size(); i < length(); ++i)
         to.push_back(zero);

      active = Active::vector; // was string; now is vector
      return to;
   } // if (active == Active::string)


   // ------------------------
   // if active == vector
   // ------------------------

   // Do we already have a vector of the requested type?
   if (std::holds_alternative<VECTOR>(variant))
      return std::get<VECTOR>(variant);

   // If we reach this point, it means two things. (1) We're NOT remaking
   // a vector from the raw string (that case was handled first). (2) The
   // caller wants a vector of a different type than the type the variant
   // currently holds (or we'd have returned immediately above).
   //
   // So, for example, perhaps the variant currently has a vector<double>,
   // and a call get<std::vector<int>>() was made, meaning that the caller
   // wants a vector<int>.
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

   log::info(
      "Re-forming vector of one type into vector of another type;\n"
      "was this intentional?");
   log::member("BodyText::get<std::vector<T>>()");

   // Initialize a new vector that will soon replace the old one
   VECTOR newVector;
   newVector.reserve(size());

   // Convert elements from the old vector to the new vector
   std::visit(
      [&newVector](auto &&oldVector)
      {
         for (const auto &from : oldVector) {
            newVector.push_back(T());
            detail::element2element(from,newVector.back());
         }
      },
      variant
   );

   // Replace the existing vector with the new vector
   variant = newVector;
   return std::get<VECTOR>(variant);
}


// non-const
template<class VECTOR>
std::enable_if_t<
   detail::isAlternative<VECTOR,VariantOfVectors>,
   VECTOR &
> get()
{
   return const_cast<VECTOR &>(std::as_const(*this).template get<VECTOR>());
}



// -----------------------------------------------------------------------------
// get<T>(n)
// -----------------------------------------------------------------------------

// These trigger a complete rebuild of the vector, if it isn't already of type
// vector<T> for the given T. This is intentional, in order to provide maximum
// flexibility. However, be aware of it, for the sake of efficiency! In general,
// when using a BodyText object, we recommend sticking with one underlying type.

// const
template<class T>
std::enable_if_t<
   detail::isAlternative<std::vector<T>,VariantOfVectors>,
   const T &
> get(const std::size_t n) const
{
   try {
      return get<std::vector<T>>()[n];
   } catch (...) {
      log::member("BodyText::get<T>({})", n);
      throw;
   }
}

// non-const
template<class T>
std::enable_if_t<
   detail::isAlternative<std::vector<T>,VariantOfVectors>,
   T &
> get(const std::size_t n)
{
   return const_cast<T &>(
      std::as_const(*this).template get<T>(n)
   );
}



// -----------------------------------------------------------------------------
// get()
// -----------------------------------------------------------------------------

// const
const VariantOfVectors &get() const
{
   if (valueType() == "Integer32")
      get<std::vector<Integer32>>();
   else if (valueType() == "Float64")
      get<std::vector<Float64>>();
   else
      get<std::vector<std::string>>();

   // We can't return the specific variant *alternative* that exists right
   // now, because that depended on valueType (run-time). So, we'll return
   // the whole variant, for whatever use that might have to a caller.
   return variant;
}

// non-const
VariantOfVectors &get()
{
   return const_cast<VariantOfVectors &>(std::as_const(*this).get());
}



// -----------------------------------------------------------------------------
// get(n)
// -----------------------------------------------------------------------------

// const
VariantOfScalars get(const std::size_t n) const
{
   try {
      get();
      return std::visit(
         [n](auto &&alt) { return VariantOfScalars(alt[n]); },
         variant
      );
   } catch (...) {
      log::member("BodyText::get({})", n);
      throw;
   }
}

// operator[]: useful alternative form
VariantOfScalars operator[](const std::size_t n) const
{
   return get(n);
}

// non-const get(n) and operator[]
// Not applicable, because the const versions return by value.



// -----------------------------------------------------------------------------
// Type-specific "get()" functions.
// Function names reflect the types: strings(), ints(), doubles(), etc.
// These provide convenient, shorthand access to specific get<vector<T>s.
// -----------------------------------------------------------------------------

// Cases:
// vector, const
// vector, non-const
// element, const
// element, non-const
#define GNDSTK_MAKE_GETTER(name,T) \
   const std::vector<T> &name() const { return get<std::vector<T>>(); } \
         std::vector<T> &name()       { return get<std::vector<T>>(); } \
   const T &name(const std::size_t n) const { return get<T>(n); } \
         T &name(const std::size_t n)       { return get<T>(n); }

GNDSTK_MAKE_GETTER(strings,     std::string);
GNDSTK_MAKE_GETTER(chars,       char);

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
