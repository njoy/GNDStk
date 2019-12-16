
#pragma once

// ------------------------
// Libraries
// ------------------------

#include "pugixml.hpp"
#include "json.hpp"
#include <boost/core/demangle.hpp>

// ------------------------
// C++
// ------------------------

#include <cassert>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <variant>

#include <deque>
#include <forward_list>
#include <list>
#include <vector>

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
#include "gnds-keyword-meta.hpp"
#include "gnds-keyword-child.hpp"
#include "gnds-keyword-read.hpp"

// tree
#include "gnds-tree-node.hpp"
#include "gnds-tree.hpp"
#include "gnds-tree-visit.hpp"

// fixme where does this belong?
#include "gnds-keyword-wrapper.hpp"

// conversions
#include "gnds-convert.hpp"

} // namespace gnds
