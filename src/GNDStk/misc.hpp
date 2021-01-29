
// -----------------------------------------------------------------------------
// Set of miscellaneous Meta and Child objects. These are "miscellaneous"
// in the sense that some use <void>, meaning they'll retrieve metadata and
// child nodes in their original form in the GNDS tree, while others stipulate
// specific types. We've split these out from other sets of Meta and Child
// objects because we may phase them out over time, to be replaced with ones
// that use various custom types, as GNDStk continues to develop.
// -----------------------------------------------------------------------------

namespace misc {

#include "GNDStk/misc/src/meta.hpp"
#include "GNDStk/misc/src/child.hpp"

using namespace meta;
using namespace child;
using namespace common;

} // namespace misc
