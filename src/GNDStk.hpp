
#pragma once

// ------------------------
// External libraries
// ------------------------

#include "pugixml.hpp"
#include "json.hpp"


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
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <variant>

// sequence containers,
// except array and
// forward_list
#include <deque>
#include <list>
#include <vector>


// ------------------------
// GNDS
// ------------------------

namespace GNDStk {

// utility
#include "GNDStk/gnds-utility.hpp"
#include "GNDStk/gnds-diagnostic.hpp"

// external-library wrappers
#include "GNDStk/XML.hpp"
#include "GNDStk/JSON.hpp"

// tree metadata/children etc.
#include "GNDStk/keyword.hpp"
#include "GNDStk/meta.hpp"
#include "GNDStk/child.hpp"
#include "GNDStk/read.hpp"

// tree
#include "GNDStk/Node.hpp"
#include "GNDStk/Tree.hpp"

// typed node
#include "GNDStk/gnds-tnode.hpp"

// conversions
#include "GNDStk/convert.hpp"

} // namespace GNDStk
