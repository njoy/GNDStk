
// pullFromDerived(content)
// Make this BodyText's length, start, and valueType parameters be consistent
// with any or all such parameters that exist in the given content. Remember
// that BodyText (this class) is a base of Component, which is a base of some
// other class. That derived class is what contains the "content" struct.
template<class CONTENT>
void pullFromDerived(const CONTENT &content)
{
   if constexpr (detail::hasLength<CONTENT>)
      length(content.length);
   if constexpr (detail::hasStart<CONTENT>)
      start(content.start);
   if constexpr (detail::hasValueType<CONTENT>)
      valueType(content.valueType);
}

// pushToDerived(content)
// The reverse of the above.
template<class CONTENT>
void pushToDerived(CONTENT &content) const
{
   if constexpr (detail::hasLength<CONTENT>)
      content.length = length();
   if constexpr (detail::hasStart<CONTENT>)
      content.start = start();
   if constexpr (detail::hasValueType<CONTENT>)
      content.valueType = valueType();
}
