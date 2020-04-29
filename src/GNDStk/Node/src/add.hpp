
// -----------------------------------------------------------------------------
// Node::add() metadatum
// This adds a new metadatum to the current node.
// -----------------------------------------------------------------------------

// ------------------------
// general
// ------------------------

// (metaPair)
metaPair &add(const metaPair &pair)
{
   metadata.push_back(pair);
   return metadata.back();
}

// (string,string)
metaPair &add(const std::string &key, const std::string &value)
{
   return add(metaPair(key,value));
}

// (string,T)
template<class T>
metaPair &add(const std::string &key, const T &value)
{
   std::string str;
   try {
      type2string(value,str);
   } catch (const std::exception &) {
      log::context("Node::add(key=\"{}\",value)", key);
      throw;
   }
   return add(key,str);
}


// ------------------------
// meta_t, ...
// ------------------------

// (meta_t<T>,T)
template<class T>
typename detail::metaReturn<T,metaPair&>::general
add(const meta_t<T> &kwd, const T &value = T{})
{
   return add(kwd.name,value);
}

// (meta_t<void or string>,string)
template<class T>
typename detail::metaReturn<T,metaPair&>::special
add(const meta_t<T> &kwd, const std::string &value = "")
{
   return add(kwd.name,value);
}



// -----------------------------------------------------------------------------
// Node::add() child node
// This adds a new child node to the current node.
// -----------------------------------------------------------------------------

// ------------------------
// general
// ------------------------

// ()
// (string)
// Action: creates a new child in the current node, and with the given name
// if any.
// Returns a reference to the new child node.
Node &add(const std::string &name = "")
{
   children.push_back(std::make_unique<Node>());
   Node &n = *children.back();
   n.name = name;
   return n;
}

// (Node<same or different>)
// Action: creates a new child in the current node, and copies the new node
// (sent as a parameter) into it.
// Returns a reference to the new child node.
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
// Action: creates a new child in the current node, and copies the node sent
// as a parameter into it. Gives the new node the name from the keyword object,
// not the one it got from the copied-in node.
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
      type2node(value,n);
   } catch (const std::exception &) {
      log::context("Node::add(child_t(\"{}\"),Node)", kwd.name);
      throw;
   }

   n.name = kwd.name;
   return n;
}


// <T,one>: accepts one T
// Action: creates a new child in the current node, and converts the T sent
// as a parameter into it. Gives the new node the name from the keyword object,
// not the one it might have gotten from the conversion.
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
      type2node(value,n);
   } catch (const std::exception &) {
      log::context("Node::add(child_t(\"{}\"),value)", kwd.name);
      throw;
   }

   n.name = kwd.name;
   return n;
}


// <void,all>: accepts a container of nodes
// Action: creates new children in the current node, copying the nodes sent
// in the container parameter into them. Gives all the new nodes the name from
// the keyword object, not the ones they got from the copied-in nodes.
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


// <T,all>: accepts container of Ts
// Action: creates new children in the current node, converting the Ts sent
// in the container parameter into them. Gives all the new nodes the name from
// the keyword object, not the ones they might have gotten from the conversions.
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
