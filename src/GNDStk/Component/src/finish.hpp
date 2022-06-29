
// -----------------------------------------------------------------------------
// finish() functions
// DESCRIPTION
// -----------------------------------------------------------------------------

/*
These accomplish two goals.

1. Some perform actions that depend on derived-class data that can't be assumed
to have been initialized, or even in a valid form in memory, before the *body*
of the derived class has been entered. (Think in terms of initialization order
in derived-class constructors. Base classes are initialized first.) Our code
autogeneration tool arranges for autogenerated derived-class constructors each
to call one of the finish() functions below, so that the additional necessary
work can be done. Anyone who directly writes classes derived from Component is
advised to call a finish() as well, or to achieve the necessary effect in some
other manner.

2. These also provide a means by which derived-class constructors that are built
by our autogeneration tool can run additional code that someone's customization
of the autogenerated class might need.

The second thing is achieved in the following way. Autogenerated constructors
each call one of the finish() functions. Each finish() function first does what
it needs to do, then attempts to call a "DERIVED::construct()" function with the
same signature as the calling finish(). Derived-class custom code can provide
such a construct(), and thereby have its code be run. If a derived class doesn't
have such a construct(), then DERIVED::construct() ends up going to one of our
stub construct() functions here, in the Component base class. A derived class
thus can, but does not need to, provide a construct().

Arguments are received where (1) the derived-class constructor receives the
argument, but (2) the argument is transitory - it's used in the constructor,
but it doesn't go into the autogenerated "content" struct in the derived class.
(If it did go into the content struct then we'd simply extract it from there,
instead of having finish() receive it as a parameter.)

Specifically, the constructors in the auto-generated classes call:

   Default constructor:
      Component::finish()

   Copy and move constructors:
      Component::finish(other)
      Where other is the incoming object that's being copied or moved.

   Constructor from a Node:
      Component::finish(the Node)

   Constructors involving a vector<T> of block data:
      Component::finish(the vector)

Note: In the last case, we're speaking of a vector<T> that's specifically for
block data, not a vector<T> that might be there for a different reason.
*/



// -----------------------------------------------------------------------------
// construct() stubs
// Override in a derived-class customization, to have custom code be run.
// Cases: (), (DERIVED), (Node), (vector).
// Derived-class customizations should always return void.
// -----------------------------------------------------------------------------

void construct() { }
void construct(const DERIVED &) { }
void construct(const Node &) { }

// The next one returns bool, but customizations in DERIVED should return void,
// just as customizations to the above three construct() function variations
// return void. We use bool, here, for technical reasons, relating to the test
// used in the template finish() function (as opposed to the non-template cases)
// to determine whether or not someone has provided a custom construct().
template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
bool construct(const std::vector<T> &) { return true; }



// -----------------------------------------------------------------------------
// finish() functions
// -----------------------------------------------------------------------------

// ------------------------
// finish()
// ------------------------

void finish()
{
   // If hasBlockData == true (else no-op), have Component's BlockData base
   // get length, start, and valueType, as available, from the derived class
   if constexpr (hasBlockData)
      BLOCKDATA::pullFromDerived(derived());

   // Based on the derived class' keys(), locate and sort derived-class fields
   // that are vectors, with vector elements that have index and/or label.
   sort();

   // construct
   derived().construct();
}


// ------------------------
// finish(DERIVED)
// ------------------------

void finish(const DERIVED &other)
{
   // length, start, valueType
   if constexpr (hasBlockData)
      BLOCKDATA::pullFromDerived(derived());

   // derived-class vector fields
   sort();

   // construct
   void (Component::*stub)(const DERIVED &) = &Component::construct;
   void (DERIVED::*custom)(const DERIVED &) = &DERIVED::construct;
   if (custom != stub)
      derived().construct(other);
   else
      derived().construct();
}


// ------------------------
// finish(Node)
// ------------------------

void finish(const Node &node)
{
   // Read fields from the Node into the derived object. This applies the keys()
   // multi-query in the derived class, and also runs BlockData::fromNode() if
   // the Node has block data, in order to get the Node's string of block data.
   fromNode(node);

   if constexpr (hasBlockData) {
      // length, start, valueType
      BLOCKDATA::pullFromDerived(derived());
      // make vector
      BLOCKDATA::get();
   }

   // derived-class vector fields
   sort();

   // construct
   void (Component::*stub)(const Node &) = &Component::construct;
   void (DERIVED::*custom)(const Node &) = &DERIVED::construct;
   if (custom != stub)
      derived().construct(node);
   else
      derived().construct();
}


// ------------------------
// finish(vector)
// ------------------------

template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
void finish(const std::vector<T> &vector)
{
   // assign from the vector
   BLOCKDATA::operator=(vector);

   // length, start, valueType: push back up to derived,
   // as they would have been computed above in operator=.
   BLOCKDATA::pushToDerived(derived());

   // derived-class vector fields
   sort();

   // construct
   if constexpr (std::is_same_v<void,decltype(derived().construct(vector))>)
      derived().construct(vector);
   else
      derived().construct();
}
