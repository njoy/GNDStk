inline const
std::vector< std::string > valuesKeys{ "start", "length" };

template< typename ValueType = double >
struct Values : public SterileNode< valuesKeys >{
public:
  using Node_t = SterileNode< valuesKeys >;
private:
  std::vector< ValueType > values_;

public:

#include "GNDStk/nodes/Values/src/ctor.hpp"

  const auto& values() const{ return values_; }
};
