
// -----------------------------------------------------------------------------
// Set of Meta and Child objects that are useful enough as-is that we wish
// to include them in other sets of such objects, in other namespaces.
// -----------------------------------------------------------------------------

#include "GNDStk/common/src/detail.hpp"

namespace common {

// numeric
template<class T = double>
inline const Child<
   // for general T, the following produces a vector<T>;
   // for T already a vector, it remains as-is
   typename detail::numeric_type<T>::type,
   Allow::one,
   detail::convert_pcdata_text_t
> numeric("#pcdata");

// shortcuts for numeric; each gives a vector
inline const auto ints = numeric<int>/"#pcdata";
inline const auto floats = numeric<float>/"#pcdata";
inline const auto doubles = numeric<double>/"#pcdata";
// fixme I'm not sure why the "#pcdata" name doesn't come over automatically
// from numeric; it probably relates to order-of-initialization rules (or
// lack of rules?) for variable templates. We'll figure that out sometime.
// For now, the shortcuts are given the name directly, so it doesn't matter.

} // namespace common
