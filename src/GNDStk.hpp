
#pragma once


// ------------------------
// External libraries
// ------------------------

#include "pugixml.hpp"
#include "nlohmann/json.hpp"
#include <highfive/H5File.hpp>
#include <highfive/H5Easy.hpp>
#include "Log.hpp"


// ------------------------
// C++ #includes
// ------------------------

// miscellaneous
#include <algorithm>
#include <cassert>
#include <cctype>
#ifdef GNDSTK_PRECISION
#include <charconv>
#endif
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <optional>
#include <random>
#include <regex>
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
// GNDStk #includes
// ------------------------

namespace njoy {
namespace GNDStk {

// basic
#include "GNDStk/utility.hpp"
#include "GNDStk/precision.hpp"
#include "GNDStk/enums.hpp"

// external-library wrappers
#include "GNDStk/XML.hpp"
#include "GNDStk/JSON.hpp"
#include "GNDStk/HDF5.hpp"

// string/Node to/from type
#include "GNDStk/string2type.hpp"
#include "GNDStk/type2string.hpp"

// Meta, Child, and related
#include "GNDStk/Meta.hpp"
#include "GNDStk/Child.hpp"
#include "GNDStk/or.hpp"

// optional, with default
#include "GNDStk/Defaulted.hpp"

// Tree: primary constructs
#include "GNDStk/Node.hpp"
#include "GNDStk/Tree.hpp"

// Node to/from type
#include "GNDStk/node2type.hpp"
#include "GNDStk/type2node.hpp"

// Tree/XML/JSON/HDF5 conversions
#include "GNDStk/convert.hpp"

// Miscellaneous support constructs for Standard Interface classes
#include "GNDStk/Support.hpp"
#include "GNDStk/Lookup.hpp"

// Base classes for primary Standard Interface data classes
#include "GNDStk/BlockData.hpp"
#include "GNDStk/Component.hpp"

} // namespace GNDStk
} // namespace njoy
