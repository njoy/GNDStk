
// -----------------------------------------------------------------------------
// Node.add() metadata
// -----------------------------------------------------------------------------

// ------------------------
// general
// ------------------------

// string,T
template<class T, class CONVERTER = detail::convert_t>
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


// pair<S,T>, iff S is convertible to std::string
template<class S, class T, class CONVERTER = detail::convert_t>
typename std::enable_if<
   std::is_convertible<S,std::string>::value,
   metaPair &
>::type add(
   const std::pair<S,T> &pair,
   const CONVERTER &converter = CONVERTER{}
) {
   return add(std::string(pair.first), pair.second, converter);
}



// ------------------------
// meta_t
// ------------------------

// void
template<class T = std::string>
typename std::enable_if<
   std::is_convertible<T,std::string>::value,
   metaPair &
>::type add(
   const meta_t<void> &kwd,
   const T &value = T{}
) {
   return add(kwd.name, std::string(value));
}


// TYPE
template<class TYPE, class CONVERTER, class T = TYPE>
typename std::enable_if<
   std::is_convertible<T,TYPE>::value,
   metaPair &
>::type add(
   const meta_t<TYPE,CONVERTER> &kwd,
   const T &value = T{}
) {
   return add(kwd.name, TYPE(value), kwd.converter);
}



// -----------------------------------------------------------------------------
// Node.add() children
// -----------------------------------------------------------------------------

// ------------------------
// general
// ------------------------

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
// Accepts a convertible-to-node value.
// Builds a new child node from the value.
// Returns a reference to the new node.
template<class T>
typename std::enable_if<
   std::is_convertible<T,Node>::value,
   Node &
>::type add(const T &value)
{
   return add() = Node(value);
}



// ------------------------
// child_t, ...
// ------------------------

// Remark. The first two accept a general ALLOW child_t (either "one" or "many")
// and return a reference to the added value. The "many" is allowed here - hence
// the general ALLOW instead of just "one" - because it's perfectly reasonable
// to add just a single value in this case, even if multiple values are allowed.
// The second two functions accept only a "many" child_t, because they receive
// containers of values. (They also return void, as there's not generally just
// one added value to which we'd be able to return a reference.)


// <void,ALLOW,void,FILTER>
// Accepts a convertible-to-node value.
// Builds a new child node from the value.
// Gives the new node the name from the keyword object.
// Returns a reference to the new node.
template<allow ALLOW, class T, class FILTER>
typename std::enable_if<
   std::is_convertible<T,Node>::value,
   Node &
>::type add(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const T &value
) {
   try {
      Node &n = add(value);
      n.name = kwd.name;
      return n;
   } catch (...) {
      log::member("Node.add(child_t(\"{}\"),value)", kwd.name);
      throw;
   }
}


// <TYPE,ALLOW,CONVERTER,FILTER>
// Accepts a convertible-to-TYPE value.
// Builds a new child node from the value.
// Gives the new node the name from the keyword object.
// Returns a reference to the new node.
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER, class T>
typename std::enable_if<
   std::is_convertible<T,TYPE>::value,
   Node &
>::type add(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const T &value
) {
   try {
      Node &n = add();
      kwd.converter(TYPE(value),n);
      n.name = kwd.name;
      return n;
   } catch (...) {
      log::member("Node.add(child_t(\"{}\"),value)", kwd.name);
      throw;
   }
}


// <void,many,void,FILTER>
// Accepts a container of convertible-to-node values.
// Builds new child nodes from the values.
// Gives each new node the name from the keyword object.
// No returned reference, because we entered numerous new values.
template<
   template<class...> class CONTAINER = std::vector,
   class FILTER,
   class T = Node, class... Args
>
typename std::enable_if<
   std::is_convertible<T,Node>::value,
   void
>::type add(
   const child_t<void,allow::many,void,FILTER> &kwd,
   const CONTAINER<T,Args...> &container
) {
   try {
      for (const T &value : container)
         add(kwd.one(),value);
   } catch (...) {
      log::member("Node.add(child_t(\"{}\"),container<value>)", kwd.name);
      throw;
   }
}


// <TYPE,many,CONVERTER,FILTER>
// Accepts a container of convertible-to-TYPE values.
// Builds new child nodes from the values.
// Gives each new node the name from the keyword object.
// No returned reference, because we entered numerous new values.
template<
   class TYPE, class CONVERTER, class FILTER,
   template<class...> class CONTAINER = std::vector,
   class T = TYPE, class... Args
>
typename std::enable_if<
   std::is_convertible<T,TYPE>::value,
   void
>::type add(
   const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd,
   const CONTAINER<T,Args...> &container
) {
   try {
      for (const T &value : container)
         add(kwd.one(),value);
   } catch (...) {
      log::member("Node.add(child_t(\"{}\"),container<value>)", kwd.name);
      throw;
   }
}
