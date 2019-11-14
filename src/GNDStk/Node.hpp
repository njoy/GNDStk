template< typename... Ls >
class Node {
public:
  using leaf_type = std::variant< Ls... >;

private:
  Metadata metadata_;

public: 
#include "GNDStk/Node/src/metadata.hpp"
};
