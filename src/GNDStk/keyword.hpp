
// -----------------------------------------------------------------------------
// This file defines constructs that are intended to help us, and users,
// create meta_t and child_t objects.
// -----------------------------------------------------------------------------

// keyword_t
class keyword_t {
public:
   #include "GNDStk/keyword/src/meta.hpp"
   #include "GNDStk/keyword/src/child.hpp"
};

// keyword
// An object of the keyword_t type.
// Useful for creating meta_t and child_t objects.
inline const keyword_t keyword;
