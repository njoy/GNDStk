
// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<
   class RESULT, find FIND, class CONVERTER,
   class METADATA, class CHILDREN
>
inline auto operator-(
   const child_t<RESULT,FIND,CONVERTER,METADATA,CHILDREN> &kwd
) {
   return child_t<void,FIND,detail::failure_t,METADATA,CHILDREN>(
      kwd.name, kwd.canBeTopLevel
   );
}



// -----------------------------------------------------------------------------
// R/child_t
// Change result to R
// See meta operators for relevant comments
// -----------------------------------------------------------------------------

template<
   class R,
   class RESULT, find FIND, class CONVERTER,
   class METADATA, class CHILDREN
>
inline auto operator/(
   const R &,
   const child_t<RESULT,FIND,CONVERTER,METADATA,CHILDREN> &kwd
) {
   return child_t<R,FIND,CONVERTER,METADATA,CHILDREN>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}

template<
   class R,
   find  FIND, class CONVERTER,
   class METADATA, class CHILDREN
>
inline auto operator/(
   const R &,
   const child_t<void,FIND,CONVERTER,METADATA,CHILDREN> &kwd
) {
   return child_t<R,FIND,detail::convert_t,METADATA,CHILDREN>(
      kwd.name, kwd.canBeTopLevel
   );
}



// -----------------------------------------------------------------------------
// child_t/C
// Change converter to C
// See meta operators for relevant comments
// -----------------------------------------------------------------------------

template<
   class RESULT, find FIND, class CONVERTER,
   class METADATA, class CHILDREN,
   class C

>
inline child_t<typename detail::isNotVoid<RESULT>::type,FIND,C,METADATA,CHILDREN>
operator/(
   const child_t<RESULT,FIND,CONVERTER,METADATA,CHILDREN> &kwd,
   const C &converter
) {
   return child_t<RESULT,FIND,C,METADATA,CHILDREN>(
      kwd.name, converter, kwd.canBeTopLevel
   );
}



// -----------------------------------------------------------------------------
// Post[decrement|increment]
// -----------------------------------------------------------------------------

// child_t<void>--
template<find FIND, class METADATA, class CHILDREN>
inline auto operator--(
   const child_t<void,FIND,detail::failure_t,METADATA,CHILDREN> &kwd, const int
) {
   return child_t<void,find::one,detail::failure_t,METADATA,CHILDREN>(
      kwd.name, kwd.canBeTopLevel
   );
}

// child_t<void>++
template<find FIND, class METADATA, class CHILDREN>
inline auto operator++(
   const child_t<void,FIND,detail::failure_t,METADATA,CHILDREN> &kwd, const int
) {
   return child_t<void,find::all,detail::failure_t,METADATA,CHILDREN>(
      kwd.name, kwd.canBeTopLevel
   );
}

// child_t<TYPE>--
template<class TYPE, find FIND, class CONVERTER, class METADATA, class CHILDREN>
inline auto operator--(
   const child_t<TYPE,FIND,CONVERTER,METADATA,CHILDREN> &kwd, const int
) {
   return child_t<TYPE,find::one,CONVERTER,METADATA,CHILDREN>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}

// child_t<TYPE>++
template<class TYPE, find FIND, class CONVERTER, class METADATA, class CHILDREN>
inline auto operator++(
   const child_t<TYPE,FIND,CONVERTER,METADATA,CHILDREN> &kwd, const int
) {
   return child_t<TYPE,find::all,CONVERTER,METADATA,CHILDREN>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}
