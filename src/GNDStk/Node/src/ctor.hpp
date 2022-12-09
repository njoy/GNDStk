
// -----------------------------------------------------------------------------
// Basic Node Constructors
// -----------------------------------------------------------------------------

// default
Node() = default;

// move
Node(Node &&other)
{
   *this = std::move(other);
   // validate
   for (auto &c : children)
      assert(c->parentNode == this);
}

// copy
Node(const Node &other)
{
   *this = other;
   // validate
   for (auto &c : children)
      assert(c->parentNode == this);
}



// -----------------------------------------------------------------------------
// Other Node Constructors
// -----------------------------------------------------------------------------

// ------------------------
// Name: directly, or from
// a Child object
// ------------------------

// string
explicit Node(const std::string &name) :
   name(name)
{
}

// Child<*>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
explicit Node(const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd) :
   name(kwd.name)
{
}


// ------------------------
// Name and value, using
// a Child object
// ------------------------

// Child<void,...>, Node
template<Allow ALLOW, class FILTER>
Node(
   const Child<void,ALLOW,void,FILTER> &kwd,
   const Node &value
) {
   try {
      *this = value; // <== updates this->children's parentNode pointers
      name = kwd.name; // overrides any name from the above assignment
      // validate
      for (auto &c : children)
         assert(c->parentNode == this);
   } catch (...) {
      log::ctor("Node(" + detail::keyname(kwd) + ",value)");
      throw;
   }
}

// Child<TYPE,...>, T
//
// TYPE must be constructible from T.
//
// Then, the Child's converter converts TYPE(value) to a Node. (If the Child
// has our default converter, this means that convert(TYPE,Node) is called.)
//
// Remark, to prevent confusion: two concepts of conversion apply here. TYPE
// and T are given separately, to prevent "conflicting types for TYPE deduced"
// compiler errors in the event that the "value" parameter's type, T, doesn't
// exactly match with TYPE - but is usable to construct a value of type TYPE.
// In that case, after all, it's reasonable for someone to have sent T value
// here, and we handle it by constructing an object of type TYPE from it; and
// then, once we have an object of type TYPE, we do the usual GNDStk action
// when a Child<TYPE> is involved: we convert (in the GNDStk sense) the TYPE
// object to a Node, using the Child's converter.
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class T,
   class = std::enable_if_t<std::is_constructible_v<TYPE,T>>
>
Node(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const T &value
) {
   try {
      kwd.converter(TYPE(value),*this);
      name = kwd.name; // overrides any name from the above conversion
      // validate
      for (auto &c : children)
         assert(c->parentNode == this);
   } catch (...) {
      log::ctor("Node(" + detail::keyname(kwd) + ",value)");
      throw;
   }
}
