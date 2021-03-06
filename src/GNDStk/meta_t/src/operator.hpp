
// -----------------------------------------------------------------------------
// The below all create new meta_t objects; they don't modify the given ones
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<class TYPE, class CONVERTER>
inline auto operator-(const meta_t<TYPE,CONVERTER> &kwd)
{
   return kwd.basic();
}



// -----------------------------------------------------------------------------
// T/meta_t
// Change type to T
// -----------------------------------------------------------------------------

// T/meta_t<TYPE,CONVERTER>
template<class T, class TYPE, class CONVERTER>
inline auto operator/(const T &object, const meta_t<TYPE,CONVERTER> &kwd)
{
   // Keep the old converter.
   // You must change that separately if it's necessary to do so,
   // e.g. because its convert()s handled TYPE, but not T.
   return meta_t<T,CONVERTER>(kwd.name, object, kwd.converter);
}

// T/meta_t<void>
template<class T>
inline auto operator/(const T &object, const meta_t<void> &kwd)
{
   // Use our default converter. (The input, a meta_t<void>, doesn't have one.)
   // You must change that separately if the default isn't wanted.
   return meta_t<T>(kwd.name, object);
}



// -----------------------------------------------------------------------------
// meta_t/string
// meta_t/char*
// Change name to the given one
// Type remains the same
// -----------------------------------------------------------------------------

// meta_t/string
template<class TYPE, class CONVERTER>
inline auto operator/(
   const meta_t<TYPE,CONVERTER> &kwd,
   const std::string &name
) {
   meta_t<TYPE,CONVERTER> ret = kwd;
   ret.name = name;
   return ret;
}

// meta_t/char*
// Forwards to meta_t/string
// Needed separately so that the generic meta_t/C case below isn't used
template<class TYPE, class CONVERTER>
inline auto operator/(
   const meta_t<TYPE,CONVERTER> &kwd,
   const char *const name
) {
   return kwd/std::string(name);
}



// -----------------------------------------------------------------------------
// *
// regex match-anything
// -----------------------------------------------------------------------------

template<class TYPE, class CONVERTER>
inline auto operator*(const meta_t<TYPE,CONVERTER> &kwd)
{
   return kwd/".*";
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

// meta_t<TYPE,CONVERTER>/C
template<class TYPE, class CONVERTER, class C>
inline meta_t<
   typename detail::isNotVoid<TYPE>::type, // require non-void
   C
> operator/(
   const meta_t<TYPE,CONVERTER> &kwd,
   const C &converter
) {
   // Keep the old type
   return meta_t<TYPE,C>(kwd.name, kwd.object, converter);
}

// meta_t<void>/C
template<class TYPE, class C>
inline meta_t<
   typename detail::isVoid<TYPE>::type // require void, but...
> operator/(
   const meta_t<TYPE> &kwd,
   const C &
) {
   static_assert(
      !std::is_same<TYPE,void>::value, // ...require non-void!
      "meta_t<void>/CONVERTER not allowed; the meta_t type must be non-void"
   );
   return kwd; // placeholder; the static_assert will always fail
}



// -----------------------------------------------------------------------------
// post--
// Change converter to its default
// -----------------------------------------------------------------------------

// meta_t<TYPE>--
// meta_t<void>--
// Works for both
template<class TYPE, class CONVERTER>
inline auto operator--(
   const meta_t<TYPE,CONVERTER> &kwd,
   const int
) {
   return meta_t<TYPE,typename detail::default_converter<TYPE>::type>(
      kwd.name,
      kwd.object
   );
}
