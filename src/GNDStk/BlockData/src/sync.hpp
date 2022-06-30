
// pullFromDerived(derived)
// Make this BlockData's length, start, and valueType be consistent with any or
// all such parameters that exist in the given object. Remember that this class,
// BlockData, is a base of Component, which is a base of some other class.
template<class DERIVED>
void pullFromDerived(const DERIVED &derived)
{
   length   (derived.length   ());
   start    (derived.start    ());
   valueType(derived.valueType());
}

// pushToDerived(derived)
// The reverse of the above.
template<class DERIVED>
void pushToDerived(DERIVED &derived) const
{
   derived.length   () = length   ();
   derived.start    () = start    ();
   derived.valueType() = valueType();
}
