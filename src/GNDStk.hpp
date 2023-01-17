
#pragma once


// ------------------------
// External libraries
// ------------------------

// To circumvent errors in other libraries
#include <limits>
#undef CHAR_WIDTH

#include "pugixml.hpp"
#include "nlohmann/json.hpp"
#include "Log.hpp"
#include <highfive/H5File.hpp>
#include <highfive/H5Easy.hpp>

// OpenMP
#ifdef _OPENMP
#include <omp.h>
#endif


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
#include <cstdlib>
#include <cstring>
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

// Basic
#include "GNDStk/utility.hpp"
#include "GNDStk/precision.hpp"
#include "GNDStk/enums.hpp"

// External-library wrappers
#include "GNDStk/XML.hpp"
#include "GNDStk/JSON.hpp"
#include "GNDStk/HDF5.hpp"

// std::string/Node to/from type
#include "GNDStk/string2type.hpp"
#include "GNDStk/type2string.hpp"

// Meta, Child, and related
#include "GNDStk/Meta.hpp"
#include "GNDStk/Child.hpp"
#include "GNDStk/or.hpp"

// Our alternative to std::optional
#include "GNDStk/Optional.hpp"

// Like std::optional, but with a default
#include "GNDStk/Defaulted.hpp"

// Main classes
#include "GNDStk/Node.hpp"
#include "GNDStk/Tree.hpp"

// Node to/from type
#include "GNDStk/node2type.hpp"
#include "GNDStk/type2node.hpp"

// Node/XML/JSON/HDF5 conversions
#include "GNDStk/convert.hpp"

// Miscellaneous support constructs for Standard Interface classes
#include "GNDStk/Support.hpp"
#include "GNDStk/Lookup.hpp"

// Base classes for primary Standard Interface data classes
#include "GNDStk/BlockData.hpp"
#include "GNDStk/Component.hpp"

// Helper constructs for C language interfaces
#include "GNDStk/CInterface.hpp"

} // namespace GNDStk
} // namespace njoy
