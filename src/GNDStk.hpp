
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

// sequence containers,
// except array and
// forward_list
#include <deque>
#include <list>
#include <vector>


// ------------------------
// GNDS
// ------------------------

namespace gnds {

// utility
#include "GNDStk/gnds-utility.hpp"
#include "GNDStk/gnds-diagnostic.hpp"

// external-library wrappers
#include "GNDStk/gnds-wrapper-xml.hpp"
#include "GNDStk/gnds-wrapper-json.hpp"

// tree metadata/children etc.
#include "GNDStk/gnds-keyword.hpp"
#include "GNDStk/gnds-keyword-meta.hpp"
#include "GNDStk/gnds-keyword-child.hpp"
#include "GNDStk/gnds-keyword-read.hpp"

// tree
#include "GNDStk/gnds-tree-node.hpp"
#include "GNDStk/gnds-tree.hpp"

// typed node
#include "GNDStk/gnds-tnode.hpp"

// conversions
#include "GNDStk/gnds-convert-to-xml.hpp"
#include "GNDStk/gnds-convert-to-json.hpp"
#include "GNDStk/gnds-convert-to-tree.hpp"

} // namespace gnds
