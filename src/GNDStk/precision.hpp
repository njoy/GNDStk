
// -----------------------------------------------------------------------------
// This file contains constructs related to the reading and writing
// of floating-point numbers.
// -----------------------------------------------------------------------------

// Some detail classes that underlie our I/O manipulators
#include "GNDStk/precision/src/detail.hpp"


// -----------------------------------------------------------------------------
// For users
// context::real << ...
// Example: metadata::floats << ...
// -----------------------------------------------------------------------------

// We'll have:
//    floats, doubles, long doubles
//    reals: all of the above
// in each of:
//    GNDStk::metadata::
//    GNDStk::data:: (in body text, i.e. XML "plain character data")
//    GNDStk::
// the last meaning for both metadata:: and data::.

// ------------------------
// GNDStk::metadata::
// ------------------------

namespace metadata {
inline detail::Precision<detail::PrecisionContext::metadata, float>
   floats;
inline detail::Precision<detail::PrecisionContext::metadata, double>
   doubles;
inline detail::Precision<detail::PrecisionContext::metadata, long double>
   longdoubles, &quads = longdoubles;
inline detail::Precision<detail::PrecisionContext::metadata, void>
   reals;
}

// ------------------------
// GNDStk::data::
// ------------------------

namespace data {
inline detail::Precision<detail::PrecisionContext::data, float>
   floats;
inline detail::Precision<detail::PrecisionContext::data, double>
   doubles;
inline detail::Precision<detail::PrecisionContext::data, long double>
   longdoubles, &quads = longdoubles;
inline detail::Precision<detail::PrecisionContext::data, void>
   reals;
}

// ------------------------
// GNDStk::
// ------------------------

inline detail::Precision<detail::PrecisionContext::general, float>
   floats;
inline detail::Precision<detail::PrecisionContext::general, double>
   doubles;
inline detail::Precision<detail::PrecisionContext::general, long double>
   longdoubles, &quads = longdoubles;
inline detail::Precision<detail::PrecisionContext::general, void>
   reals;


// -----------------------------------------------------------------------------
// For users
// ... << manipulator
// Example: ... << GNDStk::scientific
// -----------------------------------------------------------------------------

inline const detail::Fixed      fixed;
inline const detail::Scientific scientific;
inline const detail::Shortest   shortest;
