
// -----------------------------------------------------------------------------
// This file defines constructs that are intended to help us, and users, create
// meta_t and child_t keywords. These constructs use two empty class templates,
// metadata and children, that are defined below. They also need to know about
// the meta_t and child_t class templates, which we will, therefore, forward
// declare. We don't simply rearrange higher-level files to bring in meta_t and
// child_t first, so that no forward declarations are needed, because the files
// that contain the meta_t and child_t definitions also define various keywords
// of those types - and may eventually (even if they don't now) use the keyword
// creation capabilities defined here. We could avoid needing the two forward
// declarations if we split out the creation of the meta_t and child_t keywords
// from the files they're currently in, into files that are brought in later.
// However, at this time, we judge that doing so would make things less clear.
// -----------------------------------------------------------------------------

// metadata
// children
template<class... Ms> class metadata { };
template<class... Cs> class children { };

// forward: meta_t
template<
   class RESULT = std::string
>
class meta_t;

// forward: child_t
template<
   class RESULT   = void,       // default means current Node type
   find  FIND     = find::one,  // one, or any number allowed?
   class METADATA = metadata<>, // allowable metadata for this child-node type
   class CHILDREN = children<>  // allowable children ...
>
class child_t;



// -----------------------------------------------------------------------------
// catenate*
// Template metaprogramming detail for use by the upcoming keyword_t
// -----------------------------------------------------------------------------

#include "GNDStk/keyword/src/catenateMetadata.hpp"
#include "GNDStk/keyword/src/catenateChildren.hpp"



// -----------------------------------------------------------------------------
// keyword_t
// keyword
// -----------------------------------------------------------------------------

class keyword_t {
public:
   #include "GNDStk/keyword/src/meta.hpp"
   #include "GNDStk/keyword/src/child.hpp"
};

// keyword
// For creating keywords: an object of the keyword_t type
inline const keyword_t keyword;
