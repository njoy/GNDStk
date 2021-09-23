
// -----------------------------------------------------------------------------
// Component
// conversion to Node
// -----------------------------------------------------------------------------

// Normally we'd need just a const version of a conversion operator, and, if
// we needed a non-const version at all, it could build on the const version.
// A glitch in the present circumstances is that BodyText::toNode(), which is
// called from within these, splits const and non-const cases, and that needs
// to be preserved here. So, then, why does BodyText::toNode() have a non-const
// version? The issue is that in the non-const case, BodyText::toNode() may
// need to deal with a vector (not just an original "body text" string as may
// have been read into a const BodyText). And, dealing with a vector means
// computing a proper length, start, and valueType while doing toNode() - and
// pushing those up to the class derived from Component, as it's from that
// class that those fields are written to the Node. The need to compute proper
// values for those parameters is why we need the non-const case. (And we can't
// just make length etc. mutable in BodyText, as the length etc. in the derived
// class come into play too.) Maybe we'll work out a different way to handle
// all this, but for now, we have the following.

// const
operator Node() const
{
   try {
      #include "GNDStk/Component/src/toNodeBody.hpp"
   } catch (...) {
      log::member("Component.operator Node() const");
      throw;
   }
}

// non-const
operator Node()
{
   try {
      #include "GNDStk/Component/src/toNodeBody.hpp"
   } catch (...) {
      log::member("Component.operator Node()");
      throw;
   }
}
