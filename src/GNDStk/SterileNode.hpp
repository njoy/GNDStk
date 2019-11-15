template< const std::vector< std::string >& AllowedKeys >
class SterileNode {
public:
  using Meta_t = Metadata< AllowedKeys >;

protected:
  Meta_t metadata_;

public:
  #include "GNDStk/SterileNode/src/ctor.hpp"
  #include "GNDStk/SterileNode/src/metadata.hpp"
};

using AllKeysValidSterileNode = SterileNode< allKeysValid >;
