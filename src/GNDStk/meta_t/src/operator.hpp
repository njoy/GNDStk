
// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<class RESULT, class CONVERTER>
inline auto operator-(const meta_t<RESULT,CONVERTER> &kwd)
{
   // Downgrade the result to void, and chuck the converter.
   return meta_t<void>(kwd.name);
}



// -----------------------------------------------------------------------------
// R/meta_t
// Change result to R
// -----------------------------------------------------------------------------

// R/meta_t<RESULT,CONVERTER>
template<class R, class RESULT, class CONVERTER>
inline auto operator/(const R &, const meta_t<RESULT,CONVERTER> &kwd)
{
   // Keep the old converter.
   // You must change that separately if it's necessary to do so,
   // e.g. because it can't convert to an R.
   return meta_t<R,CONVERTER>(kwd.name, kwd.converter);
}

// R/meta_t<void>
template<class R>
inline auto operator/(const R &, const meta_t<void> &kwd)
{
   // Use our default converter. (The input meta_t<void> doesn't have one.)
   // You must change that separately if the default isn't wanted.
   return meta_t<R>(kwd.name);
}



// -----------------------------------------------------------------------------
// meta_t/C
// Change converter to C
// -----------------------------------------------------------------------------

// Discussion. meta_t<void> can't accept a converter, so /C only makes sense
// for meta_t<non-void>. This operator/ could be formulated with one function
// template, but, not too surprisingly, misuse with meta_t<void> leads in that
// case to convoluted error messages from the compilers we tested. We found that
// error messages were improved by instead formulating /C with the following two
// function templates. Via SFINAE, the first accepts only <non-void> and the
// second accepts only <void>. But the second *fails* for <void> via a static
// assertion! Thus the second always fails, as it should, but with our clearer
// message from the static assertion, not the compiler's convoluted nonsense.
// Note: we could still have one function template and give it the necessary
// static assertion, but in that case convoluted additional messages still
// come about, due to a return type of meta_t<void,C> not making sense. Below,
// the static assertion is the *only* thing that goes wrong in the <void> case.

// meta_t<RESULT,CONVERTER>/C
template<class RESULT, class CONVERTER, class C>
inline meta_t<
   typename detail::isNotVoid<RESULT>::type, // require non-void
   C
> operator/(
   const meta_t<RESULT,CONVERTER> &kwd,
   const C &converter
) {
   // Keep the old result type.
   return meta_t<RESULT,C>(kwd.name, converter);
}

// meta_t<void>/C
template<class RESULT, class C>
inline meta_t<
   typename detail::isVoid<RESULT>::type // require void, but...
> operator/(
   const meta_t<RESULT> &kwd,
   const C &
) {
   static_assert(
      !std::is_same<RESULT,void>::value,  // ...require non-void!
      "meta_t<void>/CONVERTER not allowed; the meta_t type must be non-void"
   );
   return kwd; // placeholder; the static_assert will always fail
}
