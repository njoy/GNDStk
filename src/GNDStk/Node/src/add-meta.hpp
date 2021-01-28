
// -----------------------------------------------------------------------------
// Node.add()
// For metadata
// -----------------------------------------------------------------------------

// Terminology:
//
//    "plain"     : some type, but NOT std::optional or GNDStk::Defaulted
//    "optional"  : std::optional
//    "Defaulted" : GNDStk::Defaulted
//
// Note: in applicable add() functions throughout this file, we'll write:
//
//    class T = TYPE
//
// instead of just:
//
//    class T
//
// The "= TYPE" part helps to facilitate the correct interpretation if,
// for instance, a value is given as a brace-enclosed initializer list.



// -----------------------------------------------------------------------------
// string, *
// Guaranteed to add something
// Returns: reference to added metadatum pair
// -----------------------------------------------------------------------------

// string, plain
template<
   class T,
   class CONVERTER = typename detail::default_converter<T>::type,
   class = typename std::enable_if<!detail::is_optional<T>::value>::type
>
metaPair &add(
   const std::string &key,
   const T &val, // <== via SFINAE, T != optional
   const CONVERTER &converter = CONVERTER{}
) {
   try {
      std::string str;
      converter(val,str);
      metadata.push_back(metaPair(key,str));
      return metadata.back();
   } catch (...) {
      log::member("Node.add(\"{}\",value)", key);
      throw;
   }
}

// string, optional
// Not available, because adding it couldn't be certain

// string, Defaulted
template<
   class T,
   class CONVERTER = typename detail::default_converter<T>::type
>
metaPair &add(
   const std::string &key,
   const Defaulted<T> &def,
   const CONVERTER &converter = CONVERTER{}
) {
   return add(key, def.value(), converter);
}



// -----------------------------------------------------------------------------
// meta_t<void>, *
// Guaranteed to add something
// Returns: reference to added metadatum pair
// -----------------------------------------------------------------------------

// A meta_t<void> means that the meta_t imposes no particular type, and thus
// no particular behavior as far as the meta_t itself is concerned. So, here,
// we just extract the meta_t's name, and bounce to one of the (string,*) cases
// above, which behave according to *'s type. The below add() bounces to the
// correct string case above, for both plain and Defaulted; and, like those,
// cases, doesn't handle optional.

// meta_t<void>, plain
// meta_t<void>, Defaulted
template<
   class T = std::string,
   class CONVERTER = typename detail::default_converter<T>::type,
   class = typename std::enable_if<!detail::is_optional<T>::value>::type
>
metaPair &add(
   const meta_t<void> &kwd,
   const T &val = T{}, // <== via SFINAE, T != optional
   const CONVERTER &converter = CONVERTER{}
) {
   return add(kwd.name, val, converter);
}

// meta_t<void>, optional
// Not available, because adding it couldn't be certain



// -----------------------------------------------------------------------------
// meta_t<plain>, *
// Guaranteed to add something
// Returns: reference to added metadatum pair
// -----------------------------------------------------------------------------

// meta_t<plain>, plain
template<
   class TYPE, class CONVERTER,
   class T = TYPE,
   class = typename std::enable_if<!detail::is_optional<T>::value>::type,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
metaPair &add(
   const meta_t<TYPE,CONVERTER> &kwd,
   const T &val = T{} // <== via SFINAE, T != optional
) {
   return add(kwd.name, TYPE(val), kwd.converter);
}

// meta_t<plain>, optional
// Not available, because adding it couldn't be certain

// meta_t<plain>, Defaulted
template<
   class TYPE, class CONVERTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
metaPair &add(
   const meta_t<TYPE,CONVERTER> &kwd,
   const Defaulted<T> &def
) {
   return add(kwd, def.value());
}



// -----------------------------------------------------------------------------
// meta_t<optional>, *
// -----------------------------------------------------------------------------

// meta_t<optional>, plain
// Returns: metaPair &
template<
   class TYPE, class CONVERTER,
   class T = TYPE,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
metaPair &add(
   const meta_t<std::optional<TYPE>,CONVERTER> &kwd,
   const T &val = T{}
) {
   return add(kwd.name, TYPE(val), kwd.converter);
}

// meta_t<optional>, optional
// Returns: bool: was something added?
template<
   class TYPE, class CONVERTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
bool add(
   const meta_t<std::optional<TYPE>,CONVERTER> &kwd,
   const std::optional<T> &opt
) {
   return opt.has_value()
      ? (add(kwd.name, TYPE(opt.value()), kwd.converter), true)
      :  false;
}

// meta_t<optional>, Defaulted
// Returns: bool: was something added?
template<
   class TYPE, class CONVERTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
bool add(
   const meta_t<std::optional<TYPE>,CONVERTER> &kwd,
   const Defaulted<T> &def
) {
   return def.has_value()
      ? (add(kwd.name, TYPE(def.value()), kwd.converter), true)
      :  false;
}



// -----------------------------------------------------------------------------
// meta_t<Defaulted>, *
// -----------------------------------------------------------------------------

// meta_t<Defaulted>, plain
// Returns: metaPair &
template<
   class TYPE, class CONVERTER,
   class T = TYPE,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
metaPair &add(
   const meta_t<Defaulted<TYPE>,CONVERTER> &kwd,
   const T &val = T{}
) {
   return add(kwd.name, TYPE(val), kwd.converter);
}

// meta_t<Defaulted>, optional
// Returns: bool: was something added?
template<
   class TYPE, class CONVERTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
bool add(
   const meta_t<Defaulted<TYPE>,CONVERTER> &kwd,
   const std::optional<T> &opt
) {
   return opt.has_value()
      ? (add(kwd.name, TYPE(opt.value()), kwd.converter), true)
      :  false;
}

// meta_t<Defaulted>, Defaulted
// Returns: bool: was something added?
template<
   class TYPE, class CONVERTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
bool add(
   const meta_t<Defaulted<TYPE>,CONVERTER> &kwd,
   const Defaulted<T> &def
) {
   return def.has_value()
      ? (add(kwd.name, TYPE(def.value()), kwd.converter), true)
      :  false;
}
