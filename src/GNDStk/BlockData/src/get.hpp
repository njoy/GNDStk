
// -----------------------------------------------------------------------------
// Cases
// -----------------------------------------------------------------------------

/*
------------------------
When DATATYPE == void
------------------------

Case 1
Return reference to [const] vector<T>:
   get<std::vector<T>> const
   get<std::vector<T>>
T must be such that vector<T> is in our variant.

Case 2
Return reference to [const] T:
   get<T>(n) const
   get<T>(n)
T must be such that vector<T> is in our variant.

Case 3
Return reference to [const] variant<vector<>s>:
   get() const
   get()

Case 4
Return (by value) a variant<scalars>:
   get(n) const
   operator[](n) const
A reference return isn't possible with the above two, because there's
no variant<scalars> to reference; it's computed on-the-fly. The value
return means, further, that non-const version aren't necessary.

Case 5
Type-specific getters with specific names:
   const std::vector<T> &name() const
   std::vector<T> &name()
   const T &name(n) const
   T &name(n)
For example, name == doubles when T == double.

------------------------
When DATATYPE != void
------------------------

Case 1
Return reference to [const] vector<T>:
   get<std::vector<T>> const
   get<std::vector<T>>
T must == DATATYPE.

Case 2
Return reference to [const] T:
   get<T>(n) const
   get<T>(n)
T must == DATATYPE.

Case 3
Return reference to [const] vector<DATATYPE>
   get() const
   get()

Case 4
Return reference to [const] DATATYPE:
   get(n) const
   operator[](n) const
   get(n)
   operator[](n)

Case 5
Type-specific getters with a specific name:
   const std::vector<DATATYPE> &name() const
   std::vector<DATATYPE> &name()
   const DATATYPE &name(n) const
   DATATYPE &name(n)
For example, name == doubles if DATATYPE == double. Unlike in the DATATYPE ==
void case, we won't have this set of functions for each of name == doubles,
name == ints, name == strings, etc., but only for the name that's appropriate
for type DATATYPE.
*/



// -----------------------------------------------------------------------------
// 1. get<std::vector<T>>()
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
      *** Under the correct and normal use of BlockData, ***
      *** this simple action will probably be the most common. ***

   Else:
      Convert the variant's vector<non-T> into a vector<T>.
      Print a note to the effect that this might be unintentional.
      The note can be suppressed if the call *is* intentional.

In the active == vector case, length, start, and valueType aren't considered
to be relevant, and play no role. We consider those values to be meaningful
ONLY in relation to BlockData's raw string, and we deal with them here only
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
modify the vector outside of BlockData's machinery.

Of course we also have a non-const version, for a non-const *this.
*/


// const
template<class VECTOR>
std::enable_if_t<
   ( runtime && detail::isAlternative<VECTOR,VariantOfVectors>) ||
   (!runtime && std::is_same_v<VECTOR,std::vector<DATATYPE>>),
   const VECTOR &
> get() const
{
   // Element type requested
   using T = typename VECTOR::value_type;


   // ------------------------
   // if active == string
   // ------------------------

   if (active() == Active::string) {
      static const std::string context_rebuilding =
         "BlockData::get<std::vector<T>>(), remade from raw string";

      // Completely rebuild the vector from the raw string, making use of
      // length, start, and valueType.

      // For this get(), the caller has stipulated a particular vector type.
      // We'll print a warning if that vector type appears to conflict with
      // valueType. Regardless, we'll return what the caller requested. Note
      // that valueType == "" is acceptable with any element type.
      if (valueType() != "" && !detail::MapTypeString<T>::find(valueType())) {
         log::warning(
           "Vector element type may be inconsistent with valueType \"{}\";\n"
           "we'll create the requested std::vector<> anyway",
            valueType()
         );
         log::member(context_rebuilding);
      }

      // Initialize
      VECTOR *to;
      if constexpr (runtime) {
         variant = VECTOR{};
         to = &std::get<VECTOR>(variant); // std::get, not this get :-)
      } else {
         vector.clear();
         to = &vector;
      }

      T zero;
      if constexpr (std::is_same_v<T,std::string>) zero = ""; else zero = T(0);

      // [*****----------]: leading 0s
      for (std::size_t i = 0; i < start(); ++i)
         to->push_back(zero);

      // [-----*****-----]: values from the raw string
      std::istringstream iss(rawstring);
      if constexpr (std::is_floating_point_v<T>) {
         std::string str;
         while (iss >> str)
            to->push_back(
               detail::Precision<detail::PrecisionContext::data,T>{}.read(str)
            );
      } else {
         T element;
         while (iss >> element)
            to->push_back(element);
      }

      // Print a warning if length appears to be impossible because we already
      // have more than that number of values. (But length == 0 is ignored.)
      if (0 < length() && length() < to->size()) {
         log::warning(
           "The value of length == {} appears to be wrong, because we\n"
           "already have {} values from start == {}, plus {} values read\n"
           "from the raw string, for a total of {} values.",
            length(),
            start(),
            start(),
            to->size() - start(),
            to->size()
         );
         log::member(context_rebuilding);
      }

      // [----------*****]: trailing 0s
      for (std::size_t i = to->size(); i < length(); ++i)
         to->push_back(zero);

      act = Active::vector; // was string; now is vector
      return *to;
   } // if (active == Active::string)


   // ------------------------
   // if active == vector
   // ------------------------

   if constexpr (runtime) {
      // VARIANT CASE...
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
      // BlockData is intended to store just one vector - one that represents
      // values in a GNDS node that has block data. We don't, and shouldn't,
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
      log::member("BlockData::get<std::vector<T>>()");

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

   } else {
      // VECTOR CASE...
      // The vector is (via SFINAE) already of the requested type
      return vector;
   }
}


// non-const
template<class VECTOR>
std::enable_if_t<
   ( runtime && detail::isAlternative<VECTOR,VariantOfVectors>) ||
   (!runtime && std::is_same_v<VECTOR,std::vector<DATATYPE>>),
   VECTOR &
> get()
{
   return const_cast<VECTOR &>(std::as_const(*this).template get<VECTOR>());
}



// -----------------------------------------------------------------------------
// 2. get<T>(n)
// -----------------------------------------------------------------------------

// For DATATYPE == void (so that we have a variant<vector<>s>):
// These trigger a complete rebuild of the vector, if it isn't already of type
// vector<T> for the given T. This is intentional, in order to provide maximum
// flexibility. However, be aware of it, for the sake of efficiency! In general,
// when using a BlockData object, we recommend sticking with one underlying
// type, not dynamically changing from one type to another.

// For DATATYPE != void (so that we have a vector):
// T == DATATYPE is required, so that returning an element of the
// vector<DATATYPE> will return a reference to T. (A constructibility/
// convertibility requirement that we have in other BlockData-related code thus
// needs to be more stringent here. We can't just be able to make a T from a
// DATATYPE. They must in fact be the same type, because we return a reference.)

// For both of the above cases:
// If the string (not the variant or the vector) is active, then a rebuild from
// the string is necessary, and will happen in the get<std::vector<T>>() call.

// const
template<class T>
std::enable_if_t<
   supported<T> && (runtime || std::is_same_v<T,DATATYPE>),
   const T &
>
get(const std::size_t n) const
{
   try {
      return get<std::vector<T>>()[n];
   } catch (...) {
      log::member("BlockData::get<T>({})", n);
      throw;
   }
}

// non-const
template<class T>
std::enable_if_t<
   supported<T> && (runtime || std::is_same_v<T,DATATYPE>),
   T &
>
get(const std::size_t n)
{
   return const_cast<T &>(std::as_const(*this).template get<T>(n));
}



// -----------------------------------------------------------------------------
// 3. get()
// If DATATYPE == void, returns a variant<vector<>s>.
// If DATATYPE != void, returns a vector<>.
// -----------------------------------------------------------------------------

// const
std::conditional_t<
   runtime,
   const VariantOfVectors &,
   const std::vector<DATATYPE> &
> get() const
{
   if constexpr (runtime) {
      detail::MapStringType(
         valueType(),
         [this](auto &&t)
         {
            // clang seems to need this-> explicitly to *not* emit a warning
            this->get<std::vector<std::decay_t<decltype(t)>>>();
         }
      );
      // We can't return the specific variant alternative that was just put
      // in place; it depended on a run-time check. So, we return the whole
      // variant, for whatever use that might have to a caller.
      return variant;
   } else {
      // Simpler, but we do still need a get (in case the *string* is active).
      get<std::vector<DATATYPE>>();
      return vector;
   }
}

// non-const
std::conditional_t<
   runtime,
   VariantOfVectors &,
   std::vector<DATATYPE> &
> get()
{
   return const_cast<
      std::conditional_t<
         runtime,
         VariantOfVectors &,
         std::vector<DATATYPE> &
      >
   >(std::as_const(*this).get());
}



// -----------------------------------------------------------------------------
// 4. get(n)
//
// If DATATYPE == void, returns a variant<scalars> (by value, because the
// returned object must be made on-the-fly from our variant<vector<>s>).
//
// If DATATYPE != void, returns a scalar of type [const] DATATYPE (by reference,
// because it's available directly in our vector<DATATYPE>).
// -----------------------------------------------------------------------------

// ------------------------
// const
// ------------------------

// get(n)
std::conditional_t<
   runtime,
   VariantOfScalars,
   const data_t &
> get(const std::size_t n) const
{
   try {
      get();
      if constexpr (runtime) {
         return std::visit(
            [n](auto &&alt) { return VariantOfScalars(alt[n]); },
            variant
         );
      } else {
         return vector[n];
      }
   } catch (...) {
      log::member("BlockData::get({})", n);
      throw;
   }
}

// operator[](n): useful alternative form
std::conditional_t<
   runtime,
   VariantOfScalars,
   const data_t &
> operator[](const std::size_t n) const
{
   return get(n);
}


// ------------------------
// non-const
// ------------------------

// If DATATYPE == void:
// Not needed, because the const versions return by value.
//
// If DATATYPE != void:
// Meaningful, because returns are by reference in this (DATATYPE != void) case.
// So, we'll enable non-const versions for this case only.

// In case anyone wonders, D (not just DATATYPE) is needed below because SFINAE
// applies when template argument *deduction* is taking place. DATATYPE is
// already fixed, by context - we're in BlockData<true,DATATYPE> - and thus it
// isn't being deduced here. Templating these (otherwise non-template) functions
// with an argument that defaults to DATATYPE, then using that argument in the
// SFINAE, is a simple trick that makes the SFINAE work as intended. As for
// VOID, it's necessary in order for the following to be unambiguous with the
// template versions of get(n) that are defined elsewhere in this file.

// get(n)
template<class VOID = void, class D = DATATYPE>
std::enable_if_t<std::is_same_v<VOID,void> && !detail::isVoid<D>, data_t &>
get(const std::size_t n)
{
   try {
      get();
      return vector[n];
   } catch (...) {
      log::member("BlockData::get({})", n);
      throw;
   }
}

// operator[](n)
template<class D = DATATYPE>
std::enable_if_t<!detail::isVoid<D>, data_t &>
operator[](const std::size_t n)
{
   return get(n);
}



// -----------------------------------------------------------------------------
// 5. Type-specific "get()" functions.
// Function names reflect the types: strings(), ints(), doubles(), etc.
// These provide convenient, shorthand access to specific get<vector<T>s.
// -----------------------------------------------------------------------------

// Cases:
// vector, const
// vector, non-const
// element, const
// element, non-const

#define GNDSTK_MAKE_GETTER(name,TYPE) \
   \
   template<class D = DATATYPE> \
   std::enable_if_t< \
      detail::isVoid<D> || \
      std::is_same_v<TYPE,D>, const std::vector<TYPE> & \
   > name() const { return get<std::vector<TYPE>>(); } \
   \
   template<class D = DATATYPE> \
   std::enable_if_t< \
      detail::isVoid<D> || \
      std::is_same_v<TYPE,D>, std::vector<TYPE> & \
   > name() { return get<std::vector<TYPE>>(); } \
   \
   template<class D = DATATYPE> \
   std::enable_if_t< \
      detail::isVoid<D> || \
      std::is_same_v<TYPE,D>, const TYPE & \
   > name(const std::size_t n) const { return get<TYPE>(n); } \
   \
   template<class D = DATATYPE> \
   std::enable_if_t< \
      detail::isVoid<D> || \
      std::is_same_v<TYPE,D>, TYPE & \
   > name(const std::size_t n) { return get<TYPE>(n); }

GNDSTK_MAKE_GETTER(strings,     std::string)
GNDSTK_MAKE_GETTER(chars,       char)
GNDSTK_MAKE_GETTER(schars,      signed char)
GNDSTK_MAKE_GETTER(shorts,      short)
GNDSTK_MAKE_GETTER(ints,        int)
GNDSTK_MAKE_GETTER(longs,       long)
GNDSTK_MAKE_GETTER(longlongs,   long long)
GNDSTK_MAKE_GETTER(uchars,      unsigned char)
GNDSTK_MAKE_GETTER(ushorts,     unsigned short)
GNDSTK_MAKE_GETTER(uints,       unsigned int)
GNDSTK_MAKE_GETTER(ulongs,      unsigned long)
GNDSTK_MAKE_GETTER(ulonglongs,  unsigned long long)
GNDSTK_MAKE_GETTER(floats,      float)
GNDSTK_MAKE_GETTER(doubles,     double)
GNDSTK_MAKE_GETTER(longdoubles, long double)

#undef GNDSTK_MAKE_GETTER
