
// pullFromDerived(derived)
// Make this BlockData's length, start, and valueType be consistent with any or
// all such parameters that exist in the given object. Remember that this class,
// BlockData, is a base of Component, which is a base of some other class.
template<class T>
void pullFromDerived(const T &obj)
{
   if constexpr (detail::hasLength<T>)
      length(obj.content.length);
   if constexpr (detail::hasStart<T>)
      start(obj.content.start);
   if constexpr (detail::hasValueType<T>)
      valueType(obj.content.valueType);
}

// pushToDerived(derived)
// The reverse of the above.
template<class T>
void pushToDerived(T &obj) const
{
   if constexpr (detail::hasLength<T>)
      obj.content.length = length();
   if constexpr (detail::hasStart<T>)
      obj.content.start = start();
   if constexpr (detail::hasValueType<T>)
      obj.content.valueType = valueType();
}
