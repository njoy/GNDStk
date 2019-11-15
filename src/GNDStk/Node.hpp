template< const std::vector< std::string >& AllowedKeys, typename... Ls >
class Node : protected SterileNode< AllowedKeys > {
public:
  using Child_t = std::variant< Ls... >;

private:
  using Sterile_t = SterileNode< AllowedKeys >;
  std::vector< Child_t > children_;

public: 
  #include "GNDStk/Node/src/ctor.hpp"
  #include "GNDStk/Node/src/push_back.hpp"
  #include "GNDStk/Node/src/children.hpp"

  using Sterile_t::metadata;
};

template< typename... Ls >
using AllKeysValidNode = Node< allKeysValid, Ls... >;
