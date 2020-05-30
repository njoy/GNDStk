
// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<class RESULT, find FIND, class CONVERTER>
inline auto operator-(const child_t<RESULT,FIND,CONVERTER> &kwd)
{
   // Downgrade the result to void, and chuck the converter.
   return child_t<void,FIND>(kwd.name, kwd.canBeTopLevel);
}



// -----------------------------------------------------------------------------
// R/child_t
// Change result to R
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// R/child_t<RESULT,FIND,CONVERTER>
template<class R, class RESULT, find FIND, class CONVERTER>
inline auto operator/(const R &, const child_t<RESULT,FIND,CONVERTER> &kwd)
{
   return child_t<R,FIND,CONVERTER>(kwd.name, kwd.converter, kwd.canBeTopLevel);
}

// R/child_t<void,FIND>
template<class R, find FIND>
inline auto operator/(const R &, const child_t<void,FIND> &kwd)
{
   return child_t<R,FIND>(kwd.name, kwd.canBeTopLevel);
}



// -----------------------------------------------------------------------------
// child_t/C
// Change converter to C
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// child_t<RESULT,FIND,CONVERTER>/C
template<class RESULT, find FIND, class CONVERTER, class C>
inline child_t<
   typename detail::isNotVoid<RESULT>::type,
   FIND,
   C
> operator/(
   const child_t<RESULT,FIND,CONVERTER> &kwd,
   const C &converter
) {
   return child_t<RESULT,FIND,C>(kwd.name, converter, kwd.canBeTopLevel);
}

// child_t<void,FIND>/C
template<class RESULT, find FIND, class C>
inline child_t<
   typename detail::isVoid<RESULT>::type,
   FIND
> operator/(
   const child_t<RESULT,FIND> &kwd,
   const C &
) {
   static_assert(
      !std::is_same<RESULT,void>::value,
      "child_t<void>/CONVERTER not allowed; the child_t type must be non-void"
   );
   return kwd;
}



// -----------------------------------------------------------------------------
// Post[decrement|increment]
// Downgrade|upgrade to one|all
// -----------------------------------------------------------------------------

// child_t<void>--
template<find FIND>
inline auto operator--(const child_t<void,FIND> &kwd, const int)
{
   return child_t<void,find::one>(kwd.name, kwd.canBeTopLevel);
}

// child_t<void>++
template<find FIND>
inline auto operator++(const child_t<void,FIND> &kwd, const int)
{
   return child_t<void,find::all>(kwd.name, kwd.canBeTopLevel);
}

// child_t<TYPE>--
template<class TYPE, find FIND, class CONVERTER>
inline auto operator--(const child_t<TYPE,FIND,CONVERTER> &kwd, const int)
{
   return child_t<TYPE,find::one,CONVERTER>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}

// child_t<TYPE>++
template<class TYPE, find FIND, class CONVERTER>
inline auto operator++(const child_t<TYPE,FIND,CONVERTER> &kwd, const int)
{
   return child_t<TYPE,find::all,CONVERTER>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}
