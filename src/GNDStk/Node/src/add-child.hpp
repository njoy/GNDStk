
// -----------------------------------------------------------------------------
// Node.add()
// For child nodes
// -----------------------------------------------------------------------------

// Terminology: as for the Node.add()s for metadata.
//
// Remark. Some of the child_t add()s accept a general ALLOW child_t (either
// allow::one or allow::many) along with just *one* value. The allow::many
// is permissible here - even with just one value - because we could certainly
// wish to add multiple values one-by-one.
//
// Naturally, we'll also have add() functions that accept only an allow::many
// child_t, and receive containers of values.



// -----------------------------------------------------------------------------
// 0-argument
// 1-argument:
//    string
//    plain
//    defaulted
// Guaranteed to add something
// Returns reference to added node
// -----------------------------------------------------------------------------

// 0-argument
// 1-argument: string (the name)
Node &add(const std::string &name = "")
{
   children.push_back(std::make_unique<Node>());
   Node &n = *children.back();
   n.name = name;
   return n;
}

// 1-argument: plain
template<
   class T,
   class = typename std::enable_if<std::is_constructible<Node,T>::value>::type,
   class = typename std::enable_if<!detail::is_optional<T>::value>::type
>
Node &add(
   const T &val // <== via SFINAE, T != optional
) {
   return add() = Node(val);
}

// 1-argument: optional
// Not available, because adding it couldn't be certain

// 1-argument: defaulted
template<
   class T,
   class = typename std::enable_if<std::is_constructible<Node,T>::value>::type
>
Node &add(const defaulted<T> &def)
{
   return add(def.value());
}



// -----------------------------------------------------------------------------
// child_t<void>, *
// Guaranteed to add something
// Returns reference to added node
// -----------------------------------------------------------------------------

// Similar in principle to its meta_t counterpart. Bounces to one of the above
// add() functions; and like those, doesn't allow std::optional.

// child_t<void>, plain
// child_t<void>, defaulted
template<
   class T = Node, allow ALLOW, class FILTER,
   class = typename std::enable_if<std::is_constructible<Node,T>::value>::type,
   class = typename std::enable_if<!detail::is_optional<T>::value>::type
>
Node &add(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const T &val = T{} // <== via SFINAE, T != optional
) {
   Node &n = add(val);
   n.name = kwd.name;
   return n;
}



// -----------------------------------------------------------------------------
// child_t<plain>, *
// Guaranteed to add something
// Returns reference to added node
// -----------------------------------------------------------------------------

// child_t<plain>, plain
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class T = TYPE,
   class = typename std::enable_if<!detail::is_optional<T>::value>::type,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
Node &add(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const T &val = T{} // <== via SFINAE, T != optional
) {
   try {
      Node &n = add();
      kwd.converter(TYPE(val),n);
      n.name = kwd.name;
      return n;
   } catch (...) {
      log::member("Node.add(" + detail::keyname(kwd) + ",value)");
      throw;
   }
}

// child_t<plain>, optional
// Not available, because adding it couldn't be certain

// child_t<plain>, defaulted
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
Node &add(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const defaulted<T> &def
) {
   return add(kwd, def.value());
}



// -----------------------------------------------------------------------------
// child_t<optional>, *
// -----------------------------------------------------------------------------

// child_t<optional>, plain
// Returns Node &
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class T = TYPE,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
Node &add(
   const child_t<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const T &val = T{}
) {
   return add(TYPE{}/kwd, val);
}

// child_t<optional>, optional
// Returns bool: was something added?
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
bool add(
   const child_t<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const std::optional<T> &opt
) {
   return opt.has_value() ? (add(kwd, opt.value()), true) : false;
}

// child_t<optional>, defaulted
// Returns bool: was something added?
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
bool add(
   const child_t<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const defaulted<T> &def
) {
   return def.has_value() ? (add(kwd, def.value()), true) : false;
}



// -----------------------------------------------------------------------------
// child_t<defaulted>, *
// -----------------------------------------------------------------------------

// child_t<defaulted>, plain
// Returns Node &
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class T = TYPE,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
Node &add(
   const child_t<defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const T &val = T{}
) {
   return add(TYPE{}/kwd, val);
}

// child_t<defaulted>, optional
// Returns bool: was something added?
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
bool add(
   const child_t<defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const std::optional<T> &opt
) {
   return opt.has_value() ? (add(kwd, opt.value()), true) : false;
}

// child_t<defaulted>, defaulted
// Returns bool: was something added?
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER,
   class T,
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
>
bool add(
   const child_t<defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const defaulted<T> &def
) {
   return def.has_value() ? (add(kwd, def.value()), true) : false;
}



// -----------------------------------------------------------------------------
// child_t<*> with allow::many, and a container
// -----------------------------------------------------------------------------

// This takes a container, and builds on our non-container overloads. The add()
// that it calls, for each container element, can return either Node & or bool,
// depending on what particular types are involved. Those returns will, in any
// event, generally be different for different container elements. Therefore,
// this function doesn't return anything.

// The relatively complicated template specification is designed to handle both
// child_t<void> and child_t<TYPE>, and T (for the container elements) being a
// plain type, a std::optional<something>, or a defaulted<something>.

template<
   // re: the child_t
   class TYPE, class CONVERTER, class FILTER,

   // re: the container
   template<class...> class CONTAINER = std::vector,
   class T = // <== Node for child_t<void>; else TYPE
      typename std::conditional<detail::isVoid<TYPE>::value,Node,TYPE>::type,
   class... Args,
   class = typename std::enable_if<
      detail::isIterable<CONTAINER<T,Args...>>::value
   >::type,

   // re: constructible-to that an underlying add() will require:
   // to Node if child_t<void>, to TYPE if child_t<TYPE>
   class = typename std::enable_if<
      std::is_constructible<
         typename std::conditional<detail::isVoid<TYPE>::value,Node,TYPE>::type,
         // remove type, if inside optional<> or defaulted<>
         typename detail::remove_opt_def<T>::type
      >::value
   >::type
>
void add(
   const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd,
   const CONTAINER<T,Args...> &container
) {
   try {
      for (const T &val : container)
         add(--kwd,val); // --kwd: child_t w/allow::one
   } catch (...) {
      log::member("Node.add(" + detail::keyname(kwd) + ",container)");
      throw;
   }
}
