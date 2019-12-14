
#pragma once

// ------------------------
// Libraries
// ------------------------

#include "pugixml.hpp"
#include "json.hpp"
#include "knoop.hpp"

// ------------------------
// C++
// ------------------------

#include <cassert>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <type_traits>
#include <vector>
#include <typeinfo>
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
#include "gnds-keyword-meta.hpp"
#include "gnds-keyword-child.hpp"
#include "gnds-keyword-read.hpp"

// tree
#include "gnds-tree-node.hpp"
#include "gnds-tree.hpp"
#include "gnds-tree-visit.hpp"

// fixme where does this really belong?
#include "gnds-keyword-wrapper.hpp"

// tree - alternative
#include "gnds-knoop-node.hpp"
#include "gnds-knoop.hpp"

// conversions
#include "gnds-convert.hpp"

} // namespace gnds
