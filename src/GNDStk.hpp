
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

namespace GNDStk {

// basic
#include "GNDStk/utility.hpp"
#include "GNDStk/diagnostic.hpp"

// external-library wrappers
#include "GNDStk/XML.hpp"
#include "GNDStk/JSON.hpp"

// tree: metadata/children etc.
#include "GNDStk/keyword.hpp"
#include "GNDStk/meta.hpp"
#include "GNDStk/child.hpp"

// string/node to/from type
#include "GNDStk/string2type.hpp"
#include "GNDStk/node2type.hpp"
#include "GNDStk/type2string.hpp"
#include "GNDStk/type2node.hpp"

// tree: primary constructs
#include "GNDStk/Node.hpp"
#include "GNDStk/Tree.hpp"

// conversions
#include "GNDStk/convert.hpp"

} // namespace GNDStk
