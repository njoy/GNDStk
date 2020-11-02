
#pragma once


// ------------------------
// External libraries
// ------------------------

#include "pugixml.hpp"
#include "nlohmann/json.hpp"
#include "Log.hpp"


// ------------------------
// C++
// ------------------------

// miscellaneous
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
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
#include "GNDStk/type2string.hpp"
#include "GNDStk/node2type.hpp"
#include "GNDStk/type2node.hpp"

// meta_t, child_t, and related
#include "GNDStk/convert_t.hpp"
#include "GNDStk/meta_t.hpp"
#include "GNDStk/child_t.hpp"
#include "GNDStk/keyword.hpp"

// sets of meta_t/child_t
#include "GNDStk/basic.hpp"
#include "GNDStk/typed.hpp"
#include "GNDStk/misc.hpp"

// tree: primary constructs
#include "GNDStk/Node.hpp"
#include "GNDStk/Tree.hpp"

// xml/json/tree conversions
#include "GNDStk/convert.hpp"

} // namespace GNDStk
} // namespace njoy
