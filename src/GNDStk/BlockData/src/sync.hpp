
// pullFromDerived(derived)
// Make this BlockData's length, start, and valueType be consistent with any or
// all such parameters that exist in the given object. Remember that this class,
// BlockData, is a base of Component, which is a base of some other class.
template<class T>
void pullFromDerived(const T &obj)
{
   if constexpr (detail::hasLength   <T>) length   (obj.length   ());
   if constexpr (detail::hasStart    <T>) start    (obj.start    ());
   if constexpr (detail::hasValueType<T>) valueType(obj.valueType());
}

// pushToDerived(derived)
// The reverse of the above.
template<class T>
void pushToDerived(T &obj) const
{
   if constexpr (detail::hasLength   <T>) obj.length   () = length   ();
   if constexpr (detail::hasStart    <T>) obj.start    () = start    ();
   if constexpr (detail::hasValueType<T>) obj.valueType() = valueType();
}
