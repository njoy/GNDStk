
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
// Returns: reference to the added metadatum pair
// -----------------------------------------------------------------------------

// string, plain
template<
   class T,
   class CONVERTER = detail::default_converter_t<T>,
   class = std::enable_if_t<!detail::isOptional<T>>
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
   class CONVERTER = detail::default_converter_t<T>
>
metaPair &add(
   const std::string &key,
   const Defaulted<T> &def,
   const CONVERTER &converter = CONVERTER{}
) {
   return add(key, def.value(), converter);
}



// -----------------------------------------------------------------------------
// Meta<void>, *
// Guaranteed to add something
// Returns: reference to the added metadatum pair
// -----------------------------------------------------------------------------

// A Meta<void> means that the Meta imposes no particular type, and thus
// no particular behavior as far as the Meta itself is concerned. So, here,
// we just extract the Meta's name, and bounce to one of the (string,*) cases
// above, which behave according to *'s type. The below add() bounces to the
// correct string case above, for both plain and Defaulted; and, like those,
// cases, doesn't handle optional.

// Meta<void>, plain
// Meta<void>, Defaulted
template<
   class T = std::string,
   class CONVERTER = detail::default_converter_t<T>,
   class = std::enable_if_t<!detail::isOptional<T>>
>
metaPair &add(
   const Meta<void> &kwd,
   const T &val = T{}, // <== via SFINAE, T != optional
   const CONVERTER &converter = CONVERTER{}
) {
   return add(kwd.name, val, converter);
}

// Meta<void>, optional
// Not available, because adding it couldn't be certain



// -----------------------------------------------------------------------------
// Meta<plain>, *
// Guaranteed to add something
// Returns: reference to the added metadatum pair
// -----------------------------------------------------------------------------

// Meta<plain>, plain
template<
   class TYPE, class CONVERTER,
   class T = TYPE,
   class = std::enable_if_t<!detail::isOptional<T>>,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
metaPair &add(
   const Meta<TYPE,CONVERTER> &kwd,
   const T &val = T{} // <== via SFINAE, T != optional
) {
   return add(kwd.name, TYPE(val), kwd.converter);
}

// Meta<plain>, optional
// Not available, because adding it couldn't be certain

// Meta<plain>, Defaulted
template<
   class TYPE, class CONVERTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
metaPair &add(
   const Meta<TYPE,CONVERTER> &kwd,
   const Defaulted<T> &def
) {
   return add(kwd, def.value());
}



// -----------------------------------------------------------------------------
// Meta<optional>, *
// -----------------------------------------------------------------------------

// Meta<optional>, plain
// Returns: metaPair &
template<
   class TYPE, class CONVERTER,
   class T = TYPE,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
metaPair &add(
   const Meta<std::optional<TYPE>,CONVERTER> &kwd,
   const T &val = T{}
) {
   return add(kwd.name, TYPE(val), kwd.converter);
}

// Meta<optional>, optional
// Returns: bool: was something added?
template<
   class TYPE, class CONVERTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
bool add(
   const Meta<std::optional<TYPE>,CONVERTER> &kwd,
   const std::optional<T> &opt
) {
   return opt.has_value()
      ? (add(kwd.name, TYPE(opt.value()), kwd.converter), true)
      :  false;
}

// Meta<optional>, Defaulted
// Returns: bool: was something added?
template<
   class TYPE, class CONVERTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
bool add(
   const Meta<std::optional<TYPE>,CONVERTER> &kwd,
   const Defaulted<T> &def
) {
   return def.has_value()
      ? (add(kwd.name, TYPE(def.value()), kwd.converter), true)
      :  false;
}



// -----------------------------------------------------------------------------
// Meta<Defaulted>, *
// -----------------------------------------------------------------------------

// Meta<Defaulted>, plain
// Returns: metaPair &
template<
   class TYPE, class CONVERTER,
   class T = TYPE,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
metaPair &add(
   const Meta<Defaulted<TYPE>,CONVERTER> &kwd,
   const T &val = T{}
) {
   return add(kwd.name, TYPE(val), kwd.converter);
}

// Meta<Defaulted>, optional
// Returns: bool: was something added?
template<
   class TYPE, class CONVERTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
bool add(
   const Meta<Defaulted<TYPE>,CONVERTER> &kwd,
   const std::optional<T> &opt
) {
   return opt.has_value()
      ? (add(kwd.name, TYPE(opt.value()), kwd.converter), true)
      :  false;
}

// Meta<Defaulted>, Defaulted
// Returns: bool: was something added?
template<
   class TYPE, class CONVERTER,
   class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
bool add(
   const Meta<Defaulted<TYPE>,CONVERTER> &kwd,
   const Defaulted<T> &def
) {
   return def.has_value()
      ? (add(kwd.name, TYPE(def.value()), kwd.converter), true)
      :  false;
}
