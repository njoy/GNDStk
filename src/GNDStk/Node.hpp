template< const std::vector< std::string >& AllowedKeys, typename... Ls >
class Node {
public:
  using child_type = std::variant< Ls... >;

private:
  Metadata< AllowedKeys > metadata_;
  std::vector< child_type > children_;

public: 
  // #include "GNDStk/Node/src/ctor.hpp"
  #include "GNDStk/Node/src/metadata.hpp"
  #include "GNDStk/Node/src/push_back.hpp"
  #include "GNDStk/Node/src/children.hpp"
};

inline const std::vector< std::string > allKeysValid;
template< typename... Ls >
using AllKeysValidNode = Node< allKeysValid, Ls... >;
