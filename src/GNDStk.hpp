
#pragma once


// ------------------------
// External libraries
// ------------------------

#include "pugixml.hpp"
#include "json.hpp"
#include "Log.hpp"


// ------------------------
// C++
// ------------------------

// miscellaneous
#include <algorithm>
#include <cassert>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <variant>

// some sequence containers
#include <deque>
#include <list>
#include <vector>


// ------------------------
// GNDS
// ------------------------

namespace njoy {
namespace GNDStk {

// basic
#include "GNDStk/utility.hpp"

// external-library wrappers
#include "GNDStk/XML.hpp"
#include "GNDStk/JSON.hpp"

// string|node to|from type
#include "GNDStk/string2type.hpp"
#include "GNDStk/node2type.hpp"
#include "GNDStk/type2string.hpp"
#include "GNDStk/type2node.hpp"

// tree: metadata/children etc.
#include "GNDStk/convert_t.hpp"
#include "GNDStk/keyword.hpp"
#include "GNDStk/meta.hpp"
#include "GNDStk/child.hpp"

// tree: primary constructs
#include "GNDStk/Node.hpp"
#include "GNDStk/Tree.hpp"

// xml/json/tree conversions
#include "GNDStk/convert.hpp"

} // namespace GNDStk
} // namespace njoy
