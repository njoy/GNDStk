
#pragma once


// ------------------------
// External libraries
// ------------------------

#include "pugixml.hpp"
#include "nlohmann/json.hpp"
#include "Log.hpp"


// ------------------------
// C++ #includes
// ------------------------

// miscellaneous
#include <algorithm>
#include <cassert>
#include <cctype>
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
#include "GNDStk/enums.hpp"

// external-library wrappers
#include "GNDStk/XML.hpp"
#include "GNDStk/JSON.hpp"

// string/Node to/from type
#include "GNDStk/string2type.hpp"
#include "GNDStk/type2string.hpp"

// Meta, Child, and related
#include "GNDStk/convert_t.hpp"
#include "GNDStk/Meta.hpp"
#include "GNDStk/Child.hpp"
#include "GNDStk/keyword.hpp"
#include "GNDStk/or.hpp"

// optional, with default
#include "GNDStk/Defaulted.hpp"

// sets of Meta/Child
#include "GNDStk/basic.hpp"
#include "GNDStk/misc.hpp"

// Tree: primary constructs
#include "GNDStk/Node.hpp"
#include "GNDStk/Tree.hpp"

// fixme This really belongs with basic.hpp and misc.hpp above, but I had to
// move it here due to some ordering issues that arose when I de-templated
// Node and Tree. We'll deal with this later; it's an internal issue, not
// something that will affect users in any manner.
#include "GNDStk/common.hpp"

// Node to/from type
#include "GNDStk/node2type.hpp"
#include "GNDStk/type2node.hpp"

// xml/json/tree conversions
#include "GNDStk/convert.hpp"

// fixme See above fixme
namespace basic { using namespace common; }
namespace misc  { using namespace common; }

// Miscellaneous support constructs for Standard Interface classes
#include "GNDStk/Support.hpp"

// Base classes for primary Standard Interface data classes
#include "GNDStk/BodyText.hpp"
#include "GNDStk/Component.hpp"


// ------------------------
// GNDStk "core interface"
// ------------------------

/*
In a user code, writing this:

   using namespace njoy::GNDStk::core;

gives the same effect as writing this:

   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::basic;

Meaning: We consider our "core interface" to consist of everything in GNDStk::
proper, plus our basic:: set of Meta and Child objects. Those are the ones with
<void> type, so that they return metadata and nodes in their original tree form.
Note that basic:: itself brings in Meta and Child objects from its own nested
meta:: and child:: namespaces. Those are separate because there's a small amount
of overlap between allowable GNDS metadatum names and node names. With this
scheme, if a name you wish to use isn't one of the overlapping names, just use
it. If it is, then prefix with meta:: or child:: as necessary.
*/

namespace core {
   using namespace GNDStk;
   using namespace basic;
}

} // namespace GNDStk
} // namespace njoy
