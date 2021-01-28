
// -----------------------------------------------------------------------------
// The below all create new child_t objects; they don't modify the given ones
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
inline auto operator-(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd.basic();
}



// -----------------------------------------------------------------------------
// operator~: Allow as top-level
// operator!: Disallow as top-level
//
// We don't expect much use of these, but someone may occasionally find the
// first (more likely) or the second (less likely) to be helpful. The unary
// operators that we chose for these purposes seemed like the best, given a
// limited selection. One could think: (T)ilde for (T)op; Not for Not.
// -----------------------------------------------------------------------------

// operator~
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
inline auto operator~(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   auto ret = kwd;
   ret.top(true);
   return ret;
}

// operator!
// fixme This switches off the canBeTopLevel flag in an individual child_t,
// but we actually use the namespace-scope set<string> AllowedTop when we
// determine if a particular name is allowed as a top-level node. So, turning
// of a child_t's previously-true top-level designator does not, at the moment,
// have any meaningful effect anywhere. We'll look at this more carefully
// sometime; for now, it just isn't a super important issue.
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
inline auto operator!(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   auto ret = kwd;
   ret.top(false);
   return ret;
}



// -----------------------------------------------------------------------------
// T/child_t
// Change type to T
// See meta_t analogs for relevant remarks
// -----------------------------------------------------------------------------

// T/child_t<TYPE,ALLOW,CONVERTER,FILTER>
template<class T, class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
inline auto operator/(
   const T &object,
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd
) {
   return child_t<T,ALLOW,CONVERTER,FILTER>(
      kwd.name,
      object,
      kwd.converter,
      kwd.filter,
      kwd.top()
   );
}

// T/child_t<void,ALLOW,void,FILTER>
template<class T, Allow ALLOW, class FILTER>
inline auto operator/(
   const T &object,
   const child_t<void,ALLOW,void,FILTER> &kwd
) {
   using CONVERTER = typename detail::default_converter<T>::type;
   return child_t<T,ALLOW,CONVERTER,FILTER>(
      kwd.name,
      object,
      CONVERTER{}, // because the input child_t didn't have one
      kwd.filter,
      kwd.top()
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
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
inline auto operator/(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::string &name
) {
   auto ret = kwd;
   return ret.name = name, ret;
}

template<Allow ALLOW, class FILTER>
inline auto operator/(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const std::string &name
) {
   auto ret = kwd;
   return ret.name = name, ret;
}

// child_t/char*
// Forwards to child_t/string
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
inline auto operator/(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const char *const name
) {
   return kwd/std::string(name);
}

template<Allow ALLOW, class FILTER>
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

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
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
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class C>
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
      kwd.object,
      converter, // the new one; not kwd.converter!
      kwd.filter,
      kwd.top()
   );
}

// child_t<void,ALLOW,void,FILTER>/C
template<class TYPE, Allow ALLOW, class FILTER, class C>
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
// Change converter to its default
// -----------------------------------------------------------------------------

// child_t<TYPE>--
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
inline auto operator--(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const int
) {
   using C = typename detail::default_converter<TYPE>::type;
   return child_t<TYPE,ALLOW,C,FILTER>(
      kwd.name,
      kwd.object,
      C{},
      kwd.filter,
      kwd.top()
   );
}

// child_t<void>--
template<Allow ALLOW, class FILTER>
inline auto operator--(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const int
) {
   return kwd;
}



// -----------------------------------------------------------------------------
// --pre, ++pre
// Downgrade/upgrade to Allow::one/many
// -----------------------------------------------------------------------------

// --child_t
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
inline auto operator--(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd.one();
}

// ++child_t
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
inline auto operator++(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd.many();
}



// -----------------------------------------------------------------------------
// child_t + F
// Change filter to F
// -----------------------------------------------------------------------------

// child_t<TYPE,ALLOW,CONVERTER,FILTER> + F
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class F>
inline auto operator+(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const F &filter
) {
   return child_t<TYPE,ALLOW,CONVERTER,F>(
      kwd.name,
      kwd.object,
      kwd.converter,
      filter, // the new one
      kwd.top()
   );
}

// child_t<void,ALLOW,void,FILTER> + F
template<Allow ALLOW, class FILTER, class F>
inline auto operator+(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const F &filter
) {
   return child_t<void,ALLOW,void,F>(
      kwd.name,
      filter, // the new one
      kwd.top()
   );
}
