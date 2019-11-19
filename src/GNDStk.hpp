#ifndef GNDSTK_HPP
#define GNDSTK_HPP

#include <vector>
#include <variant>
#include <map>

#include <range/v3/all.hpp>
#include "value-ptr.hpp"
#include "pugixml.hpp"
#include "Log.hpp"
#include "header-utilities.hpp"

namespace njoy{
namespace GNDStk {

inline const std::vector< std::string > allKeysValid;

// We need a way to ensure that no keys are allowed; i.e., there is no metadata
// allowed in some nodes.
// Using this vector as "allowedKeys" (virtually) ensures that no keys are 
// allowed. Bonus points if you know what it means.
inline const std::vector< std::string > noValidKeys{ "241993800" };

#include "GNDStk/Metadata.hpp"
#include "GNDStk/SterileNode.hpp"
#include "GNDStk/Node.hpp"

#include "GNDStk/nodes.hpp"
}
}
#endif // GNDSTK_HPP
