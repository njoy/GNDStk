
// -----------------------------------------------------------------------------
// pullFromDerived(content)
// Make this BodyText's length, start, and valueType parameters be consistent
// with any or all such parameters that exist in the given content. Remember
// that BodyText (this class) is a base of Component, which is a base of some
// other class. The final derived class is what contains the "content" struct.
// -----------------------------------------------------------------------------

template<class CONTENT>
void pullFromDerived(const CONTENT &content)
{
   // length?
   if constexpr (detail::has_length<CONTENT>::value)
      length(content.length);

   // start?
   if constexpr (detail::has_start<CONTENT>::value)
      start(content.start);

   // valueType?
   if constexpr (detail::has_valueType<CONTENT>::value)
      valueType(content.valueType);
}


// -----------------------------------------------------------------------------
// pushToDerived(content)
// Basically, the reverse of the above.
// -----------------------------------------------------------------------------

template<class CONTENT>
void pushToDerived(CONTENT &content) const
{
   // length?
   if constexpr (detail::has_length<CONTENT>::value)
      content.length = vars.length;

   // start?
   if constexpr (detail::has_start<CONTENT>::value)
      content.start = vars.start;

   // valueType?
   if constexpr (detail::has_valueType<CONTENT>::value)
      content.valueType = vars.valueType;
}
