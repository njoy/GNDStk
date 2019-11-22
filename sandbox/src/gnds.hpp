
#pragma once

// ------------------------
// Libraries
// ------------------------

#include "json.hpp"
#include "knoop.hpp"
#include "pugixml.hpp"

// ------------------------
// C++
// ------------------------

#include <cassert>
#include <fstream>
#include <iostream>
#include <type_traits>
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

// tree metadata/children
#include "gnds-keyword-meta.hpp"
#include "gnds-keyword-child.hpp"

// tree
#include "gnds-tree-node.hpp"
#include "gnds-tree.hpp"
#include "gnds-tree-visit.hpp"

// tree - alternative
#include "gnds-knoop.hpp"
#include "gnds-knoop-node.hpp"

// conversions
#include "gnds-convert.hpp"

} // namespace gnds
