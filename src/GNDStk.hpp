#ifndef GNDSTK_HPP
#define GNDSTK_HPP

#include <vector>
#include <variant>
#include <map>

#include <range/v3/all.hpp>
#include "value-ptr.hpp"
#include "pugixml.hpp"
#include "Log.hpp"

namespace njoy{
namespace GNDStk {

inline const std::vector< std::string > allKeysValid;

#include "GNDStk/Metadata.hpp"
#include "GNDStk/SterileNode.hpp"
#include "GNDStk/Node.hpp"

#include "GNDStk/nodes.hpp"
}
}
#endif // GNDSTK_HPP
