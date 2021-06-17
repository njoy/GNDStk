
// -----------------------------------------------------------------------------
// construct
// -----------------------------------------------------------------------------

// These do two things.
//
// 1. Some perform actions that depend, in one way or another, on derived-class
// data that can't be assumed to have been initialized, or even in a valid form
// in memory, before the body of the derived class has been entered. (Think in
// terms of initialization order in derived-class constructors. Base classes are
// initialized first.) So, we do the actions in question in the constructor body
// by calling one of these construct() functions.
//
// 2. They provide a means by which derived-class constructors, possibly built
// by our auto-generation process from JSON-format GNDS specs, can run arbitrary
// additional code that we (but not the mechanical auto-generation process) may
// know *should* be run.
//
// The second thing above can be achieved, if we wish, by writing a construct()
// function - with exactly the same signature - in the derived class. Via SFINAE
// constructs, each of the following base-class construct() functions determines
// if the derived class has its own such construct(). (Not just inherited from
// the base, but its own.)
//
// Note that all of the below can access member data in the derived class simply
// by casting first: static_cast<DERIVED &>(*this). Arguments are received where
// the derived-class constructor receives the argument, but the argument isn't
// something that goes into the derived-class member data (or at least that the
// auto-generation process knows does so; it's always possible that a user's
// customization might do something additional in this regard). A user's custom
// construct() may wish to do something with the argument, so we handle it here.
//
// Examples. The auto-generation code arranges for the following, with regard
// to the constructors in a class derived from Component:
//
//    For the default constructor:
//       Component::construct() is called.
//
//    For the copy and move constructors:
//       Component::construct(other) is called, where other is the incoming
//       object that's being copied or moved.
//
//    For the constructor from a Node:
//       Component::construct(the Node) is called.


// ------------------------
// construct()
// ------------------------

// No-argument version.
void construct()
{
   // This instance of the derived class
   DERIVED &d = static_cast<DERIVED &>(*this);

   // If hasBodyText == true (else no-op), AND d.content has certain values -
   // in particular, any of length, start, or valueType - with which BodyText
   // should sync.
   BodyText<hasBodyText>::sync(d.content);

   // Call derived class' construct() function if it has one.
   if constexpr (detail::hasConstruct<DERIVED>::has)
      d.construct();
}


// ------------------------
// construct(DERIVED)
// ------------------------

// Called from the derived class' copy and move constructors. Something extra
// could potentially be done with the copied- or moved-from derived object.
void construct(const DERIVED &other)
{
   // As above
   DERIVED &d = static_cast<DERIVED &>(*this);
   BodyText<hasBodyText>::sync(d.content);

   // Call derived class' construct(const DERIVED &) function if it has one,
   // else call its construct() function if it has one.
   if constexpr (detail::hasConstructDerived<DERIVED>::has)
      d.construct(other);
   else if constexpr (detail::hasConstruct<DERIVED>::has)
      d.construct();
}


// ------------------------
// construct(Node)
// ------------------------

// Called from the derived class' constructor that takes a Node; i.e. from its
// converting constructor from Node. Something extra could potentially be done
// with the Node.
void construct(const Node &node)
{
   // As above, but also pulling data from the Node into the derived object's
   // content before syncing (if applicable) BodyText.
   DERIVED &d = static_cast<DERIVED &>(*this);
   fromNode(node);
   BodyText<hasBodyText>::sync(d.content);

   // Call derived class' construct(const Node &) function if it has one,
   // else call its construct() function if it has one.
   if constexpr (detail::hasConstructNode<DERIVED>::has)
      d.construct(node);
   else if constexpr (detail::hasConstruct<DERIVED>::has)
      d.construct();
}


// ------------------------
// construct(vector)
// ------------------------

template<
   class T,
   class = typename std::enable_if<std::is_arithmetic<T>::value,T>::type
>
void construct(const std::vector<T> &values)
{
   // As above
   DERIVED &d = static_cast<DERIVED &>(*this);
   BodyText<hasBodyText>::sync(d.content);

   /// todo Do something with values

   // Call derived class' construct(const vector<T> &) function if it has one,
   // else call its construct() function if it has one.
   if constexpr (detail::hasConstructVector<DERIVED>::template has<T>)
      d.construct(values);
   else if constexpr (detail::hasConstruct<DERIVED>::has)
      d.construct();
}
