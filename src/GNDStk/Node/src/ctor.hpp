
// -----------------------------------------------------------------------------
// Basic Node Constructors
// -----------------------------------------------------------------------------

// default
Node() = default;

// move
Node(Node &&) = default;

// copy
Node(const Node &from)
{
   *this = from;
}

// templated "copy"
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
Node(const Node<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from)
{
   *this = from;
}



// -----------------------------------------------------------------------------
// Other Node Constructors
// -----------------------------------------------------------------------------

// ------------------------
// Name: directly, or from
// a child_t
// ------------------------

// string
Node(const std::string &name) : name(name)
{
}

// child_t<*>
template<class TYPE, allow ALLOW, class CONVERTER>
Node(const child_t<TYPE,ALLOW,CONVERTER> &kwd) : name(kwd.name)
{
}


// ------------------------
// Name and value, using
// a child_t
// ------------------------

// child_t<void,...>, Node
template<allow ALLOW>
Node(
   const child_t<void,ALLOW> &kwd,
   const Node &value
) {
   try {
      *this = value;
      name = kwd.name; // overrides any name from the assignment
   } catch (...) {
      log::ctor("Node(child_t(\"{}\"),value)", kwd.name);
      throw;
   }
}

// child_t<TYPE,...>, T
// T must be convertible to TYPE
// Then, the child_t's converter converts the TYPE value to a Node. With
// child_t's default converter, this means convert(TYPE,Node) is called.
template<
   class TYPE, allow ALLOW, class CONVERTER, class T,
   class = typename std::enable_if<std::is_convertible<T,TYPE>::value>::type
>
Node(
   const child_t<TYPE,ALLOW,CONVERTER> &kwd,
   const T &value
) {
   try {
      kwd.converter(TYPE(value),*this);
      name = kwd.name; // overrides any name from the above line
   } catch (...) {
      log::ctor("Node(child_t(\"{}\"),value)", kwd.name);
      throw;
   }
}
