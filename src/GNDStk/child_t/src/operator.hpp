
// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<class TYPE, find FIND, class CONVERTER>
inline auto operator-(const child_t<TYPE,FIND,CONVERTER> &kwd)
{
   // Downgrade the type to void, and chuck the converter
   return child_t<void,FIND>(kwd.name, kwd.canBeTopLevel);
}



// -----------------------------------------------------------------------------
// T/child_t
// Change type to T
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// T/child_t<TYPE,FIND,CONVERTER>
template<class T, class TYPE, find FIND, class CONVERTER>
inline auto operator/(const T &, const child_t<TYPE,FIND,CONVERTER> &kwd)
{
   return child_t<T,FIND,CONVERTER>(kwd.name, kwd.converter, kwd.canBeTopLevel);
}

// T/child_t<void,FIND>
template<class T, find FIND>
inline auto operator/(const T &, const child_t<void,FIND> &kwd)
{
   return child_t<T,FIND>(kwd.name, kwd.canBeTopLevel);
}



// -----------------------------------------------------------------------------
// child_t/C
// Change converter to C
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// child_t<TYPE,FIND,CONVERTER>/C
template<class TYPE, find FIND, class CONVERTER, class C>
inline child_t<
   typename detail::isNotVoid<TYPE>::type,
   FIND,
   C
> operator/(
   const child_t<TYPE,FIND,CONVERTER> &kwd,
   const C &converter
) {
   return child_t<TYPE,FIND,C>(kwd.name, converter, kwd.canBeTopLevel);
}

// child_t<void,FIND>/C
template<class TYPE, find FIND, class C>
inline child_t<
   typename detail::isVoid<TYPE>::type,
   FIND
> operator/(
   const child_t<TYPE,FIND> &kwd,
   const C &
) {
   static_assert(
      !std::is_same<TYPE,void>::value,
      "child_t<void>/CONVERTER not allowed; the child_t type must be non-void"
   );
   return kwd;
}



// -----------------------------------------------------------------------------
// Post[decrement|increment]
// Downgrade|upgrade to one|all
// -----------------------------------------------------------------------------

// ------------------------
// child_t<TYPE>
// ------------------------

// operator--
template<class TYPE, find FIND, class CONVERTER>
inline auto operator--(const child_t<TYPE,FIND,CONVERTER> &kwd, const int)
{
   return child_t<TYPE,find::one,CONVERTER>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}

// operator++
template<class TYPE, find FIND, class CONVERTER>
inline auto operator++(const child_t<TYPE,FIND,CONVERTER> &kwd, const int)
{
   return child_t<TYPE,find::all,CONVERTER>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}

// ------------------------
// child_t<void>
// ------------------------

// operator--
template<find FIND>
inline auto operator--(const child_t<void,FIND> &kwd, const int)
{
   return child_t<void,find::one>(kwd.name, kwd.canBeTopLevel);
}

// operator++
template<find FIND>
inline auto operator++(const child_t<void,FIND> &kwd, const int)
{
   return child_t<void,find::all>(kwd.name, kwd.canBeTopLevel);
}
