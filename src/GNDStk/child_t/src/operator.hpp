
// -----------------------------------------------------------------------------
// The below all create new child_t objects; they don't modify the given ones
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<class TYPE, allow ALLOW, class CONVERTER>
inline auto operator-(const child_t<TYPE,ALLOW,CONVERTER> &kwd)
{
   // Downgrade the type to void, and (necessarily) chuck the converter.
   return child_t<void,ALLOW>(
      kwd.name,
      kwd.canBeTopLevel
   );
}



// -----------------------------------------------------------------------------
// T/child_t
// Change type to T
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// T/child_t<TYPE,ALLOW,CONVERTER>
template<class T, class TYPE, allow ALLOW, class CONVERTER>
inline auto operator/(const T &, const child_t<TYPE,ALLOW,CONVERTER> &kwd)
{
   return child_t<T,ALLOW,CONVERTER>(
      kwd.name,
      kwd.converter,
      kwd.canBeTopLevel
   );
}

// T/child_t<void,ALLOW>
template<class T, allow ALLOW>
inline auto operator/(const T &, const child_t<void,ALLOW> &kwd)
{
   return child_t<T,ALLOW>(
      kwd.name,
      kwd.canBeTopLevel
   );
}



// -----------------------------------------------------------------------------
// child_t/string
// child_t/char*
// Change name to the given one
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// child_t/string
template<class TYPE, allow ALLOW, class CONVERTER>
inline child_t<TYPE,ALLOW,CONVERTER> operator/(
   const child_t<TYPE,ALLOW,CONVERTER> &kwd,
   const std::string &name
) {
   child_t<TYPE,ALLOW,CONVERTER> ret = kwd;
   return ret.name = name, ret;
}

// child_t/char*
// Forwards to child_t/string
// Needed separately so that the generic child_t/C case below isn't used
template<class TYPE, allow ALLOW, class CONVERTER>
inline child_t<TYPE,ALLOW,CONVERTER> operator/(
   const child_t<TYPE,ALLOW,CONVERTER> &kwd,
   const char *const name
) {
   return kwd/std::string(name);
}



// -----------------------------------------------------------------------------
// child_t/C
// Change converter to C
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// child_t<TYPE,ALLOW,CONVERTER>/C
template<class TYPE, allow ALLOW, class CONVERTER, class C>
inline child_t<
   typename detail::isNotVoid<TYPE>::type,
   ALLOW,
   C
> operator/(
   const child_t<TYPE,ALLOW,CONVERTER> &kwd,
   const C &converter
) {
   return child_t<TYPE,ALLOW,C>(kwd.name, converter, kwd.canBeTopLevel);
}

// child_t<void,ALLOW>/C
template<class TYPE, allow ALLOW, class C>
inline child_t<
   typename detail::isVoid<TYPE>::type,
   ALLOW
> operator/(
   const child_t<TYPE,ALLOW> &kwd,
   const C &
) {
   static_assert(
      !std::is_same<TYPE,void>::value,
      "child_t<void>/CONVERTER not allowed; the child_t type must be non-void"
   );
   return kwd;
}



// -----------------------------------------------------------------------------
// one(), many()
// Downgrade|upgrade to allow:: one|many
// -----------------------------------------------------------------------------

// ------------------------
// child_t<TYPE>
// ------------------------

// one()
template<class TYPE, allow ALLOW, class CONVERTER>
inline auto one(const child_t<TYPE,ALLOW,CONVERTER> &kwd)
{
   return child_t<TYPE,allow::one,CONVERTER>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}

// many()
template<class TYPE, allow ALLOW, class CONVERTER>
inline auto many(const child_t<TYPE,ALLOW,CONVERTER> &kwd)
{
   return child_t<TYPE,allow::many,CONVERTER>(
      kwd.name, kwd.converter, kwd.canBeTopLevel
   );
}

// ------------------------
// child_t<void>
// ------------------------

// one()
template<allow ALLOW>
inline auto one(const child_t<void,ALLOW> &kwd)
{
   return child_t<void,allow::one>(kwd.name, kwd.canBeTopLevel);
}

// many()
template<allow ALLOW>
inline auto many(const child_t<void,ALLOW> &kwd)
{
   return child_t<void,allow::many>(kwd.name, kwd.canBeTopLevel);
}
