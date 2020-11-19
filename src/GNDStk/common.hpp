
// -----------------------------------------------------------------------------
// Set of meta_t and child_t keywords that are useful enough as-is that we wish
// to share them in other sets of keywords. (Which are in other namespaces.)
// -----------------------------------------------------------------------------

#include "GNDStk/common/src/detail.hpp"

namespace common {

// values
template<class T = double>
inline const child_t<
   typename detail::values_type<T>::type,
   allow::one,
   typename detail::values_type<T>::converter
> values("values");

} // namespace common
