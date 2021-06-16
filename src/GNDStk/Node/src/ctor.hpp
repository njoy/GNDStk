
// -----------------------------------------------------------------------------
// Basic Node Constructors
// -----------------------------------------------------------------------------

// default
Node() = default;

// move
Node(Node &&other) :
   name(std::move(other.name)),
   metadata(std::move(other.metadata)),
   children(std::move(other.children))
   // but don't move the parentNode pointer!
{
   std::cout << "zzz here!!!" << std::endl;
   assert(false);

   // The above move of the children vector *copies* (it doesn't move) the
   // elements themselves. Therefore, an update of this->children's parentNode
   // pointers is not needed here; it's handled in the copy constructor below.

   // validate
   for (auto &c : children)
      assert(c->parentNode == this);
}

// copy
Node(const Node &other)
{
   ///std::cout << "zzz here 222!!!" << std::endl;
   ///assert(false);

   // This assignment ends up updating this->children's parentNode pointers,
   // so there's no need to do it directly in this function.
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
Node(const std::string &name) :
   name(name)
{
}

// Child<*>
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
Node(const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd) :
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
   class = typename std::enable_if<std::is_constructible<TYPE,T>::value>::type
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
