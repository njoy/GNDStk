
// -----------------------------------------------------------------------------
// Node::add() metadatum
// This adds a new metadatum to the current node.
// -----------------------------------------------------------------------------

// ------------------------
// general
// ------------------------

// string,T
template<class T, class CONVERTER = detail::convert_t>
metaPair &add(
   const std::string &key,
   const T &from,
   const CONVERTER &converter = CONVERTER{}
) {
   std::string to;
   try {
      // often (but not necessarily) identity, if T is string
      converter(from,to);
   } catch (const std::exception &) {
      log::context("Node::add(key=\"{}\",value)", key);
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

// void
template<class CONVERTER, class T = std::string>
typename std::enable_if<
   std::is_convertible<T,std::string>::value,
   metaPair &
>::type add(
   const meta_t<void,CONVERTER> &kwd,
   const T &value = T{}
) {
   return add(kwd.name, std::string(value));
}



// -----------------------------------------------------------------------------
// Node::add() child node
// This adds a new child node to the current node.
// -----------------------------------------------------------------------------

// ------------------------
// general
// ------------------------

// string
// Creates a new child, in the current node, with the given name.
// Returns a reference to the new child.
Node &add(const std::string &name = "")
{
   children.push_back(std::make_unique<Node>());
   Node &n = *children.back();
   n.name = name;
   return n;
}

// Node<same or different>
// Creates a new child, in the current node, copied from the parameter.
// Returns a reference to the new child.
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
Node &add(const Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from)
{
   Node &n = add();
   detail::node2Node(from,n);
   return n;
}


// ------------------------
// child_t, ...
// ------------------------

// <void,one>: accepts one node
// Creates a new child, in the current node, copied from the parameter.
// Gives the new node the name from the keyword object, not the one it
// got from the copied-in node.
// Returns a reference to the new child node.
template<
   class METADATA,
   class CHILDREN,
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
Node &add(
   const child_t<void,find::one,METADATA,CHILDREN> &kwd,
   const Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &value
) {
   Node &n = add();

   try {
      convert(value,n);
   } catch (const std::exception &) {
      log::context("Node::add(child_t(\"{}\"),Node)", kwd.name);
      throw;
   }

   n.name = kwd.name;
   return n;
}


// <T,one>: accepts one T
// Creates a new child, in the current node, converted from the T sent as
// a parameter. Gives the new node the name from the keyword object, not
// any name it might have gotten from the conversion.
// Returns a reference to the new child node.
template<
   class METADATA,
   class CHILDREN,
   class T
>
Node &add(
   const child_t<T,find::one,METADATA,CHILDREN> &kwd,
   const T &value
) {
   Node &n = add();

   try {
      convert(value,n);
   } catch (const std::exception &) {
      log::context("Node::add(child_t(\"{}\"),value)", kwd.name);
      throw;
   }

   n.name = kwd.name;
   return n;
}


// <void,all>: accepts a container of nodes
// Creates new children, in the current node, copied from the nodes sent in
// the container parameter. Gives all the new nodes the name from the keyword
// object, not the ones they got from the copied-in nodes.
// No returned reference, because we entered numerous new values.
template<
   class METADATA,
   class CHILDREN,
   template<class...> class CONTAINER = std::vector,
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   class... Args
>
void add(
   const child_t<void,find::all,METADATA,CHILDREN> &kwd,
   const CONTAINER<
      Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM>,
      Args...
   > &container
) {
   try {
      for (auto &value : container)
         add(child_t<void,find::one,METADATA,CHILDREN>(kwd.name), value);
   } catch (const std::exception &) {
      log::context("Node::add(child_t(\"{}\"),container<Node>)", kwd.name);
      throw;
   }
}


// <T,all>: accepts a container of Ts
// Creates new children, in the current node, converted from the Ts sent
// in the container parameter. Gives all the new nodes the name from the
// keyword object, not the names they might have gotten from the conversions.
// No returned reference, because we entered numerous new values.
template<
   class T,
   class METADATA,
   class CHILDREN,
   template<class...> class CONTAINER = std::vector,
   class... Args
>
void add(
   const child_t<T,find::all,METADATA,CHILDREN> &kwd,
   const CONTAINER<T,Args...> &container
) {
   try {
      for (auto &value : container)
         add(child_t<T,find::one,METADATA,CHILDREN>(kwd.name), value);
   } catch (const std::exception &) {
      log::context("Node::add(child_t(\"{}\"),container<value>)", kwd.name);
      throw;
   }
}
