
// -----------------------------------------------------------------------------
// This file defines constructs that are intended to help us, and users,
// create meta_t and child_t keywords.
// -----------------------------------------------------------------------------

// catenate*
// Template metaprogramming detail for use by the upcoming keyword_t
#include "GNDStk/keyword/src/catenateMetadata.hpp"
#include "GNDStk/keyword/src/catenateChildren.hpp"

// keyword_t
class keyword_t {
public:
   #include "GNDStk/keyword/src/meta.hpp"
   #include "GNDStk/keyword/src/child.hpp"
};

// keyword
// For creating keywords: an object of the keyword_t type
inline const keyword_t keyword;
