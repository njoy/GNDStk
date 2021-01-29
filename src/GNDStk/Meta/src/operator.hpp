
// -----------------------------------------------------------------------------
// The below all create new Meta objects; they don't modify the given ones
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<class TYPE, class CONVERTER>
inline auto operator-(const Meta<TYPE,CONVERTER> &kwd)
{
   return kwd.basic();
}



// -----------------------------------------------------------------------------
// T/Meta
// Change type to T
// -----------------------------------------------------------------------------

// T/Meta<TYPE,CONVERTER>
template<class T, class TYPE, class CONVERTER>
inline auto operator/(const T &object, const Meta<TYPE,CONVERTER> &kwd)
{
   // Keep the old converter.
   // You must change that separately if it's necessary to do so,
   // e.g. because its convert()s handled TYPE, but not T.
   return Meta<T,CONVERTER>(kwd.name, object, kwd.converter);
}

// T/Meta<void>
template<class T>
inline auto operator/(const T &object, const Meta<void> &kwd)
{
   // Use our default converter. (The input, a Meta<void>, doesn't have one.)
   // You must change that separately if the default isn't wanted.
   return Meta<T>(kwd.name, object);
}



// -----------------------------------------------------------------------------
// Meta/string
// Meta/char*
// Change name to the given one
// Type remains the same
// -----------------------------------------------------------------------------

// Meta/string
template<class TYPE, class CONVERTER>
inline auto operator/(
   const Meta<TYPE,CONVERTER> &kwd,
   const std::string &name
) {
   Meta<TYPE,CONVERTER> ret = kwd;
   ret.name = name;
   return ret;
}

// Meta/char*
// Forwards to Meta/string
// Needed separately so that the generic Meta/C case below isn't used
template<class TYPE, class CONVERTER>
inline auto operator/(
   const Meta<TYPE,CONVERTER> &kwd,
   const char *const name
) {
   return kwd/std::string(name);
}



// -----------------------------------------------------------------------------
// *
// regex match-anything
// -----------------------------------------------------------------------------

template<class TYPE, class CONVERTER>
inline auto operator*(const Meta<TYPE,CONVERTER> &kwd)
{
   return kwd/".*";
}



// -----------------------------------------------------------------------------
// Meta/C
// Change converter to C
// -----------------------------------------------------------------------------

// Discussion. Meta<void> can't accept a converter, so /C only makes sense
// for Meta<non-void>. This operator/ could be formulated with one function
// template, but, not too surprisingly, misuse with Meta<void> leads in that
// case to convoluted error messages from the compilers we tested. We found that
// error messages were improved by instead formulating /C with the following two
// function templates. Via SFINAE, the first accepts only <non-void> and the
// second accepts only <void>. But the second *fails* for <void> via a static
// assertion! Thus the second always fails, as it should, but with our clearer
// message from the static assertion, not the compiler's convoluted nonsense.
// Note: we could still have one function template and give it the necessary
// static assertion, but in that case convoluted additional messages still
// come about, due to a return type of Meta<void,C> not making sense. Below,
// the static assertion is the *only* thing that goes wrong in the <void> case.

// Meta<TYPE,CONVERTER>/C
template<class TYPE, class CONVERTER, class C>
inline Meta<
   typename detail::isNotVoid<TYPE>::type, // require non-void
   C
> operator/(
   const Meta<TYPE,CONVERTER> &kwd,
   const C &converter
) {
   // Keep the old type
   return Meta<TYPE,C>(kwd.name, kwd.object, converter);
}

// Meta<void>/C
template<class TYPE, class C>
inline Meta<
   typename detail::isVoid<TYPE>::type // require void, but...
> operator/(
   const Meta<TYPE> &kwd,
   const C &
) {
   static_assert(
      !std::is_same<TYPE,void>::value, // ...require non-void!
      "Meta<void>/CONVERTER not allowed; the Meta type must be non-void"
   );
   return kwd; // placeholder; the static_assert will always fail
}



// -----------------------------------------------------------------------------
// post--
// Change converter to its default
// -----------------------------------------------------------------------------

// Meta<TYPE>--
// Meta<void>--
// Works for both
template<class TYPE, class CONVERTER>
inline auto operator--(
   const Meta<TYPE,CONVERTER> &kwd,
   const int
) {
   return Meta<TYPE,typename detail::default_converter<TYPE>::type>(
      kwd.name,
      kwd.object
   );
}
