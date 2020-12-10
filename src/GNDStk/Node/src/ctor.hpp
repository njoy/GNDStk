
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
Node(const std::string &name) :
   name(name)
{
}

// child_t<*>
template<class TYPE, allow ALLOW, class CONVERTER, class FILTER>
Node(const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd) :
   name(kwd.name)
{
}


// ------------------------
// Name and value, using
// a child_t
// ------------------------

// child_t<void,...>, Node
template<allow ALLOW, class FILTER>
Node(
   const child_t<void,ALLOW,void,FILTER> &kwd,
   const Node &value
) {
   try {
      *this = value;
      name = kwd.name; // overrides any name from the above assignment
   } catch (...) {
      log::ctor("Node(child_t(\"{}\"),value)", kwd.name);
      throw;
   }
}

// child_t<TYPE,...>, T
//
// T must be convertible, in the C++ sense, to TYPE.
//
// Then, the child_t's converter converts TYPE(value) to a Node. (If child_t
// has our default converter, this means that convert(TYPE,Node) is called.)
//
// Remark, to prevent confusion: two concepts of conversion apply here. TYPE
// and T are given separately, to prevent "conflicting types for TYPE deduced"
// compiler errors in the event that the "value" parameter's type, T, doesn't
// exactly match with TYPE - but is *convertible* (in the C++ sense) to TYPE.
// In that case, after all, it's reasonable for someone to have sent T value
// here, and we handle it by converting (again, in the C++ sense) T value to
// TYPE(value). Then, once we have an object of type TYPE, we do the usual
// GNDStk action when a child_t<TYPE> is involved: we convert (in the GNDStk
// sense) the TYPE object to a node, using the child_t's converter.
template<
   class TYPE, allow ALLOW, class CONVERTER, class FILTER, class T,
   class = typename std::enable_if<std::is_convertible<T,TYPE>::value>::type
>
Node(
   const child_t<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const T &value
) {
   try {
      kwd.converter(TYPE(value),*this);
      name = kwd.name; // overrides any name from the above conversion
   } catch (...) {
      log::ctor("Node(child_t(\"{}\"),value)", kwd.name);
      throw;
   }
}
