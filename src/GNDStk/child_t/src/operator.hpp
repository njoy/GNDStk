
// -----------------------------------------------------------------------------
// The below all create new child_t objects; they don't modify the given ones
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
inline auto operator-(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd.basic();
}



// -----------------------------------------------------------------------------
// T/child_t
// Change type to T
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// T/child_t<TYPE,ALLOW,CONVERTER,FILTER>
template<class T, class TYPE, allow ALLOW, class CONVERTER, class FILTER>
inline auto operator/(
   const T &,
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd
) {
   return child_t<T,ALLOW,CONVERTER,FILTER>(
      kwd.name,
      kwd.converter,
      kwd.filter,
      kwd.canBeTopLevel
   );
}

// T/child_t<void,ALLOW,void,FILTER>
template<class T, allow ALLOW, class FILTER>
inline auto operator/(
   const T &,
   const child_t<void,ALLOW,void,FILTER> &kwd
) {
   using CONVERTER = typename detail::default_converter<T>::type;
   return child_t<T,ALLOW,CONVERTER,FILTER>(
      kwd.name,
      CONVERTER{}, // because the input child_t didn't have one
      kwd.filter,
      kwd.canBeTopLevel
   );
}



// -----------------------------------------------------------------------------
// child_t/string
// child_t/char*
// Change name to the given one
// Type remains the same
// Note: the <TYPE> and <void> cases, as well as the <string> and <char*>
// cases, must all be given, or else ambiguities will arise with the later
// child_t/converter operators.
// -----------------------------------------------------------------------------

// child_t/string
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
inline auto operator/(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::string &name
) {
   auto ret = kwd;
   return ret.name = name, ret;
}

template<allow ALLOW, class FILTER>
inline auto operator/(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const std::string &name
) {
   auto ret = kwd;
   return ret.name = name, ret;
}

// child_t/char*
// Forwards to child_t/string
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
inline auto operator/(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const char *const name
) {
   return kwd/std::string(name);
}

template<allow ALLOW, class FILTER>
inline auto operator/(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const char *const name
) {
   return kwd/std::string(name);
}



// -----------------------------------------------------------------------------
// *
// regex match-anything
// -----------------------------------------------------------------------------

template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
inline auto operator*(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd/".*";
}



// -----------------------------------------------------------------------------
// child_t/C
// Change converter to C
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// child_t<TYPE,ALLOW,CONVERTER,FILTER>/C
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER, class C>
inline child_t<
   typename detail::isNotVoid<TYPE>::type, // for SFINAE
   ALLOW,
   C,
   FILTER
> operator/(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const C &converter
) {
   return child_t<TYPE,ALLOW,C,FILTER>(
      kwd.name,
      converter, // the new one; not kwd.converter!
      kwd.filter,
      kwd.canBeTopLevel
   );
}

// child_t<void,ALLOW,void,FILTER>/C
template<class TYPE, allow ALLOW, class FILTER, class C>
inline child_t<
   typename detail::isVoid<TYPE>::type, // for SFINAE
   ALLOW,
   void,
   FILTER
> operator/(
   const child_t<TYPE,ALLOW,void,FILTER> &kwd,
   const C &
) {
   static_assert(
      !std::is_same<TYPE,void>::value,
      "child_t<void>/CONVERTER not allowed; the child_t must be non-void"
   );
   return kwd;
}



// -----------------------------------------------------------------------------
// post--
// Downgrade converter to its default
// -----------------------------------------------------------------------------

// child_t<TYPE>--
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
inline auto operator--(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const int
) {
   using C = typename detail::default_converter<TYPE>::type;
   return child_t<TYPE,ALLOW,C,FILTER>(
      kwd.name,
      C{},
      kwd.filter,
      kwd.canBeTopLevel
   );
}

// child_t<void>--
template<allow ALLOW, class FILTER>
inline auto operator--(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const int
) {
   return kwd;
}



// -----------------------------------------------------------------------------
// --pre, ++pre
// Downgrade|upgrade to allow::one|many
// -----------------------------------------------------------------------------

// --child_t
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
inline auto operator--(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd.one();
}

// ++child_t
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
inline auto operator++(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd.many();
}



// -----------------------------------------------------------------------------
// child_t + F
// Change filter to F
// -----------------------------------------------------------------------------

// child_t<TYPE,ALLOW,CONVERTER,FILTER> + F
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER, class F>
inline auto operator+(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const F &filter
) {
   return child_t<TYPE,ALLOW,CONVERTER,F>(
      kwd.name,
      kwd.converter,
      filter, // the new one
      kwd.canBeTopLevel
   );
}

// child_t<void,ALLOW,void,FILTER> + F
template<allow ALLOW, class FILTER, class F>
inline auto operator+(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const F &filter
) {
   return child_t<void,ALLOW,void,F>(
      kwd.name,
      filter, // the new one
      kwd.canBeTopLevel
   );
}
