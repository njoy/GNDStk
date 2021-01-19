
// -----------------------------------------------------------------------------
// Node.add() metadata
// Direct; no meta_t
// -----------------------------------------------------------------------------

// string, T
// Return value: a reference to the key/value pair just added
template<
   class T,
   class CONVERTER = typename detail::default_converter<T>::type
>
metaPair &add(
   const std::string &key,
   const T &value,
   const CONVERTER &converter = CONVERTER{}
) {
   std::string to;
   try {
      // often (but not necessarily) identity, if T is string
      converter(value,to);
   } catch (...) {
      log::member("Node.add(\"{}\",value)", key);
      throw;
   }
   metadata.push_back(metaPair(key,to));
   return metadata.back();
}


// string, optional<T>
// Return value
//    == "did the optional have a value"
//    == "we actually added something"
template<
   class T,
   class CONVERTER = typename detail::default_converter<T>::type
>
bool add(
   const std::string &key,
   const std::optional<T> &opt,
   const CONVERTER &converter = CONVERTER{}
) {
   std::string to;
   try {
      if (opt)
         converter(*opt,to);
      else
         return false;
   } catch (...) {
      log::member("Node.add(\"{}\",std::optional)", key);
      throw;
   }
   metadata.push_back(metaPair(key,to));
   return true;
}



// -----------------------------------------------------------------------------
// Node.add() metadata
// With meta_t
// -----------------------------------------------------------------------------

// ------------------------
// <void>, T
// Works if T itself
// is an optional
// ------------------------

// The meta_t<void> means that the meta_t doesn't impose any particular type.
// So, we'll accept any type; and, then, the function to which we forward will
// do the usual GNDStk action of calling a convert function to make the T value
// into a std::string (the raw tree form of a metadatum value). The return type
// is decltype(auto) because this function might (and, in typical use, probably
// will) forward to add(string,T), but *might* forward to add(string,optional)
// instead - if, well, T is a std::optional. In the former case, metaPair & is
// returned. In the latter case, bool is returned.
template<class T = std::string>
decltype(auto) add(
   const meta_t<void> &kwd,
   const T &value = T{}
) {
   return add(kwd.name, value);
}


// ------------------------
// <TYPE> or <optional>,
// T or optional
// ------------------------

/*
Below, we have the following cases:

      meta_t<> type:   given:        returns:
      --------------   -----------   --------
   1.          TYPE             T    metaPair &
   2.          TYPE    optional<T>   metaPair & (or throws)
   3. optional<TYPE>            T    metaPair &
   4. optional<TYPE>   optional<T>   bool

In case (1), neither the meta_t nor the given value involves optionals. The
value is inserted into the node's metadata container, and a reference to the
inserted (key,value) pair is returned.

In case (2), the meta_t's type is not optional, and so the given optional
parameter *must* actually have a value. If it doesn't, an error is thrown.
If it does have a value, then we add the value, and return a metaPair &.

In case (3), an actual value is given, even though the meta_t says optional.
That's perfectly fine - we do in fact have a value, so it's irrelevant that
it's optional. We add the value, and return a metaPair &.

In case (4), the meta_t says it's optional, and the given value is optional
as well. So, the function's scenario is, in short, "everything is optional."
This function forwards to our add(string,optional) overload, which in turn
is fine with the optional value being present or absent. That function, and
thus this one, returns true or false, depending on whether the optional had
a value or not (equivalently, whether the value was inserted or not).

In all cases, TYPE must be constructible from a T.
*/


// 1. <TYPE>, T
template<class TYPE, class CONVERTER, class T = TYPE>
typename std::enable_if<
   std::is_constructible<TYPE,T>::value,
   metaPair &
>::type add(
   const meta_t<TYPE,CONVERTER> &kwd,
   const T &value = T{}
) {
   return add(kwd.name, TYPE(value), kwd.converter);
}


// 2. <TYPE>, optional<T>
// The optional must have a value, because the meta_t stipulates a hard type,
// not an optional. (add()s for meta_t<std::optional> are written separately.)
template<class TYPE, class CONVERTER, class T>
typename std::enable_if<
   std::is_constructible<TYPE,T>::value,
   metaPair &
>::type add(
   const meta_t<TYPE,CONVERTER> &kwd,
   const std::optional<T> &opt
) {
   if (opt)
      return add(kwd,*opt);
   else {
      log::error(
         "Node.add() called with a meta_t< non-std::optional >,\n"
         "along with a std::optional that has no value"
      );
      log::member("Node.add(" + detail::keyname(kwd) + ",std::optional)");
      throw std::exception{};
   }
}


// 3. <optional<TYPE>>, T
// The optional aspect is effectively ignored, because we're sending an actual
// value. That the meta_t says it's optional doesn't matter - this is an add()
// function, not a query, and we're getting the value as the second parameter.
// Formulating this function in the following manner means that it returns a
// metaPair &, not a bool, given that it forwards to our add(string,T), not to
// our add(string,optional<T>).
template<class TYPE, class CONVERTER, class T = TYPE>
typename std::enable_if<
   std::is_constructible<TYPE,T>::value,
   metaPair &
>::type add(
   const meta_t<std::optional<TYPE>,CONVERTER> &kwd,
   const T &value = T{}
) {
   // We still do the kwd.object vs. TYPE{} selection business, as we do in
   // similar constructs elsewhere, on the principle that we try to maintain,
   // as deeply as possible, a TYPE's value that was used when setting up the
   // query object (in this case meta_t) in the first place. Eventually, in
   // places like this, we may be able to combine some SFINAE for "is default
   // constructible" with an if-constexpr, and thereby relax, if only in one
   // small place, a requirement that TYPE be default constructible.
   return add((kwd.object ? *kwd.object : TYPE{})/kwd, value);
}


// 4. <optional<TYPE>>, optional<T>
template<class TYPE, class CONVERTER, class T>
typename std::enable_if<
   std::is_constructible<TYPE,T>::value,
   bool
>::type add(
   const meta_t<std::optional<TYPE>,CONVERTER> &kwd,
   const std::optional<T> &opt
) {
   return opt ? (add(kwd,*opt), true) : false;
}



// -----------------------------------------------------------------------------
// Node.add() children
// Direct; no child_t
// -----------------------------------------------------------------------------

// string
// Builds a new child node with the given name.
// Returns a reference to the new node.
Node &add(const std::string &name = "")
{
   children.push_back(std::make_unique<Node>());
   Node &n = *children.back();
   n.name = name;
   return n;
}


// T
// Accepts a T, where Node is constructible from a T.
// Builds a new child node from the value.
// Returns a reference to the new node.
template<class T>
typename std::enable_if<
   std::is_constructible<Node,T>::value,
   Node &
>::type add(const T &value)
{
   return add() = Node(value);
}


// optional<T>
// Accepts an optional<T>, where Node is constructible from a T.
// If the optional has a value:
//    Builds a new child node from the value.
//    Returns true.
// If the optional does not have a value:
//    Does nothing: NO new Node, not even a blank one, is added.
//    Returns false.
template<class T>
typename std::enable_if<
   std::is_constructible<Node,T>::value,
   bool
>::type add(const std::optional<T> &opt)
{
   return opt ? (add() = Node(*opt), true) : false;
}



// -----------------------------------------------------------------------------
// Node.add() children
// With child_t
// -----------------------------------------------------------------------------

// Remark. Some of these accept a general ALLOW child_t (either allow::one or
// allow::many) along with just one value. The allow::many is permissible here
// because it's perfectly reasonable to add just one value in this case; after
// all, we might be adding multiple values, but doing so one-by-one. We'll also
// have some functions that accept only an allow::many child_t, because they
// receive containers of values.


// ------------------------
// <void>, T
// Works if T itself
// is an optional
// ------------------------

// As is true of its meta_t counterpart, this function's behavior is different
// depending on whether or not the second parameter's type is std::optional.
// Here, however, unlike in the meta_t case, differences in logical structure
// arise from the optional-or-not difference. To write this function as we did
// for meta_t (including having a default type T and default value), we use an
// if-constexpr to handle the structural differences.
template<
   class T = Node, allow ALLOW, class FILTER,
   class = typename std::enable_if<
      std::is_constructible<
         Node,
         typename detail::remove_optional<T>::type
      >::value
   >::type
>
decltype(auto) add(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const T &value = T{}
) {
   try {
      if constexpr (!detail::is_optional<T>::value) {
         // T != optional; return a Node &
         Node &n = add(value);
         n.name = kwd.name;
         return n;
      } else {
         // T == optional; return a bool
         if (!value)
            return false; // <== as with meta_t, nothing new gets added
         Node &n = add(*value);
         n.name = kwd.name;
         return true;
      }
   } catch (...) {
      if constexpr (!detail::is_optional<T>::value)
         log::member("Node.add(" + detail::keyname(kwd) + ",value)");
      else
         log::member("Node.add(" + detail::keyname(kwd) + ",std::optional)");
      throw;
   }
}


// ------------------------
// <TYPE> or <optional>,
// T or optional
// ------------------------

// These are analogous to the similarly structured non-<void> metadata add()s.

// 1. <TYPE>, T
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER, class T = TYPE>
typename std::enable_if<
   std::is_constructible<TYPE,T>::value,
   Node &
>::type add(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const T &value = T{}
) {
   try {
      Node &n = add();
      kwd.converter(TYPE(value),n);
      n.name = kwd.name;
      return n;
   } catch (...) {
      log::member("Node.add(" + detail::keyname(kwd) + ",value)");
      throw;
   }
}


// 2. <TYPE>, optional<T>
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER, class T>
typename std::enable_if<
   std::is_constructible<TYPE,T>::value,
   Node &
>::type add(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::optional<T> &opt
) {
   if (opt)
      return add(kwd,*opt);
   else {
      log::error(
         "Node.add() called with a child_t< non-std::optional >,\n"
         "along with a std::optional that has no value"
      );
      log::member("Node.add(" + detail::keyname(kwd) + ",std::optional)");
      throw std::exception{};
   }
}


// 3. <optional<TYPE>>, T
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER, class T = TYPE>
typename std::enable_if<
   std::is_constructible<TYPE,T>::value,
   Node &
>::type add(
   const child_t<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const T &value = T{}
) {
   return add((kwd.object ? *kwd.object : TYPE{})/kwd, value);
}


// 4. <optional<TYPE>>, optional<T>
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER, class T>
typename std::enable_if<
   std::is_constructible<TYPE,T>::value,
   bool
>::type add(
   const child_t<std::optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd,
   const std::optional<T> &opt
) {
   return opt ? (add(kwd,*opt), true) : false;
}


// ------------------------
// child_t w/allow::many
// ------------------------

// This takes a container, and builds on our non-container overloads. The add()
// that it calls, for each container element, can return either Node & or bool,
// depending on whether or not std::optional is involved. However, those Node &
// or bool returns will generally be different for different container elements.
// So, this function doesn't return anything. The relatively complex template
// specification is designed to handle both child_t<void> and child_t<TYPE>, as
// well as T being either a std::optional or something else.

// <...,many,...>, container<T>
template<
   class TYPE, class CONVERTER, class FILTER,
   template<class...> class CONTAINER = std::vector,
   class T = // <== Node (for <void>), else TYPE
      typename std::conditional<detail::isVoid<TYPE>::value,Node,TYPE>::type,
   class... Args,
   class = typename std::enable_if<
      std::is_constructible<
         typename std::conditional<detail::isVoid<TYPE>::value,Node,TYPE>::type,
         typename detail::remove_optional<T>::type
      >::value
   >::type
>
void add(
   const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd,
   const CONTAINER<T,Args...> &container
) {
   try {
      for (const T &value : container)
         add(--kwd,value); // --kwd: child_t<...,allow::one,...>
   } catch (...) {
      log::member("Node.add(" + detail::keyname(kwd) + ",container<value>)");
      throw;
   }
}
