template< const std::vector< std::string >& AllowedKeys >
class SterileNode {
protected:
  using Meta_t = Metadata< AllowedKeys >;
  Meta_t metadata_;


  #include "GNDStk/SterileNode/src/ctor.hpp"
  #include "GNDStk/SterileNode/src/metadata.hpp"
};

using AllKeysValidSterileNode = SterileNode< allKeysValid >;
