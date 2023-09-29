
// -----------------------------------------------------------------------------
// The below all create new Child objects; they don't modify the given ones
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Voidify
// -----------------------------------------------------------------------------

// operator-
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator-(const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd.basic();
}


// -----------------------------------------------------------------------------
// T/Child
// Change type to T
// See Meta analogs for relevant remarks
// -----------------------------------------------------------------------------

// T/Child<TYPE,ALLOW,CONVERTER,FILTER>
template<class T, class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator/(
   const T &,
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd
) {
   return Child<T,ALLOW,CONVERTER,FILTER>(
      kwd.name,
      kwd.converter,
      kwd.filter
   );
}

// T/Child<void,ALLOW,void,FILTER>
template<class T, Allow ALLOW, class FILTER>
auto operator/(
   const T &,
   const Child<void,ALLOW,void,FILTER> &kwd
) {
   using CONVERTER = detail::default_converter_t<T>;
   return Child<T,ALLOW,CONVERTER,FILTER>(
      kwd.name,
      CONVERTER{}, // because the input Child didn't have one
      kwd.filter
   );
}


// -----------------------------------------------------------------------------
// Child/string
// Child/char*
// Change name to the given one
// Type remains the same
// Note: the <TYPE> and <void> cases, as well as the <string> and <char*>
// cases, must all be given, or else ambiguities will arise with the later
// Child/converter operators.
// -----------------------------------------------------------------------------

// Child/string
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator/(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::string &name
) {
   auto ret = kwd;
   return ret.name = name, ret;
}

template<Allow ALLOW, class FILTER>
auto operator/(
   const Child<void,ALLOW,void,FILTER> &kwd,
   const std::string &name
) {
   auto ret = kwd;
   return ret.name = name, ret;
}

// Child/char*
// Forwards to Child/string
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator/(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const char *const name
) {
   return kwd/std::string(name);
}

template<Allow ALLOW, class FILTER>
auto operator/(
   const Child<void,ALLOW,void,FILTER> &kwd,
   const char *const name
) {
   return kwd/std::string(name);
}


// -----------------------------------------------------------------------------
// *
// regex match-anything
// -----------------------------------------------------------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator*(const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd/".*";
}


// -----------------------------------------------------------------------------
// Child/C
// Change converter to C
// See Meta analogs for relevant remarks
// -----------------------------------------------------------------------------

// Child<TYPE,ALLOW,CONVERTER,FILTER>/C
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class C,
   class = std::enable_if_t<!detail::is_void_v<TYPE>>
>
Child<TYPE,ALLOW,C,FILTER> operator/(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const C &converter
) {
   return Child<TYPE,ALLOW,C,FILTER>(
      kwd.name,
      converter, // the new one; not kwd.converter!
      kwd.filter
   );
}

// Child<void,ALLOW,void,FILTER>/C
template<
   class TYPE, Allow ALLOW, class FILTER, class C,
   class = std::enable_if_t<detail::is_void_v<TYPE>>
>
Child<void,ALLOW,void,FILTER> operator/(
   const Child<TYPE,ALLOW,void,FILTER> &kwd,
   const C &
) {
   static_assert(
      !detail::is_void_v<TYPE>,
      "Child<void>/CONVERTER not allowed; the Child must be non-void"
   );
   return kwd;
}


// -----------------------------------------------------------------------------
// post--
// Change converter to its default
// -----------------------------------------------------------------------------

// Child<TYPE>--
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator--(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const int
) {
   using C = detail::default_converter_t<TYPE>;
   return Child<TYPE,ALLOW,C,FILTER>(
      kwd.name,
      C{},
      kwd.filter
   );
}

// Child<void>--
template<Allow ALLOW, class FILTER>
auto operator--(
   const Child<void,ALLOW,void,FILTER> &kwd,
   const int
) {
   return kwd;
}


// -----------------------------------------------------------------------------
// --pre, ++pre
// Downgrade/upgrade to Allow::one/many
// -----------------------------------------------------------------------------

// --Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator--(const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd.one();
}

// ++Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator++(const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return kwd.many();
}


// -----------------------------------------------------------------------------
// Child + F
// Change filter to F
// -----------------------------------------------------------------------------

// Child<TYPE,ALLOW,CONVERTER,FILTER> + F
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class F>
auto operator+(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const F &filter
) {
   return Child<TYPE,ALLOW,CONVERTER,F>(
      kwd.name,
      kwd.converter,
      filter // the new one
   );
}

// Child<void,ALLOW,void,FILTER> + F
template<Allow ALLOW, class FILTER, class F>
auto operator+(
   const Child<void,ALLOW,void,FILTER> &kwd,
   const F &filter
) {
   return Child<void,ALLOW,void,F>(
      kwd.name,
      filter // the new one
   );
}


// -----------------------------------------------------------------------------
// Child || Child
// Create a Child that represents one or the other of two children
// -----------------------------------------------------------------------------

// <void> || <void>
// Return type is Child<void,...>
template<
   Allow ALLOW, class CONVERTER, class FILTER
>
auto operator||(
   const Child<void,ALLOW,CONVERTER,FILTER> &a,
   const Child<void,ALLOW,CONVERTER,FILTER> &b
) {
   return Child<void,ALLOW,CONVERTER,FILTER>(
      // both names, space-separated; this gets special treatment elsewhere
      a.name + " " + b.name,
      // need a filter; use the first Child's
      a.filter
   );
}

// <non-void> || <non-void>
// Return type is Child<variant,...>
template<
   class ATYPE, class BTYPE,
   Allow ALLOW, class CONVERTER, class FILTER,
   class = std::enable_if_t<
      !detail::is_void_v<ATYPE> &&
      !detail::is_void_v<BTYPE>
   >
>
auto operator||(
   const Child<ATYPE,ALLOW,CONVERTER,FILTER> &a,
   const Child<BTYPE,ALLOW,CONVERTER,FILTER> &b
) {
   return Child<std::variant<ATYPE,BTYPE>,ALLOW,CONVERTER,FILTER>(
      // both names, space-separated; this gets special treatment elsewhere
      a.name + " " + b.name,
      // we need a converter and a filter; use the first Child's
      a.converter,
      a.filter
   );
}
