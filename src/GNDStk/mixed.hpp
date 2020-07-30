
// -----------------------------------------------------------------------------
// Set of meta_t and child_t keywords as originally written. These are "mixed"
// in the sense that some use <void>, meaning they'll retrieve values in their
// original form in the GNDS tree, while others stipulate specific types. We've
// split these out from other sets of keywords because we anticipate phasing
// them out over time, to be replaced with ones that use various custom types,
// as GNDStk continues to develop.
// -----------------------------------------------------------------------------

namespace mixed {

#include "GNDStk/mixed/src/meta.hpp"
#include "GNDStk/mixed/src/child.hpp"

}
