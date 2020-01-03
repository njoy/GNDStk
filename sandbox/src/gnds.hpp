
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
#include <cassert>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <variant>

// sequence containers
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

// boost
#include <boost/core/demangle.hpp>


// ------------------------
// GNDS
// ------------------------

namespace gnds {

// utility
#include "gnds-misc.hpp"

// library wrappers
#include "gnds-wrapper-xml.hpp"
#include "gnds-wrapper-json.hpp"

// tree metadata/children etc.
#include "gnds-keyword.hpp"
#include "gnds-keyword-meta.hpp"
#include "gnds-keyword-child.hpp"
#include "gnds-keyword-read.hpp"

// tree
#include "gnds-tree-node.hpp"
#include "gnds-tree.hpp"
#include "gnds-tree-visit.hpp"

// typed node
#include "gnds-tnode.hpp"

// conversions
#include "gnds-convert-to-xml.hpp"
#include "gnds-convert-to-json.hpp"
#include "gnds-convert-to-tree.hpp"

} // namespace gnds
