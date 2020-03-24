
#include "catch.hpp"
#include "GNDStk.hpp"

SCENARIO("Testing GNDStk tree normalize()") {

   // fixme
   // The "normalize" concept is intended to deal with certain issues regarding
   // limitations of different specific file formats; for example, the issue of
   // attributes not being supported in the .json format. The GNDS manual speaks
   // of ways that "attributes" could be represented as child nodes in .json,
   // in such a way that child nodes thus represented could be recognized, upon
   // reading the .json, as actually being attributes. Then, a normalize() would
   // perform any necessary child-to-attribute transformations. At the moment,
   // however, we haven't quite worked out precisely how, or when, processes
   // such as this might happen, or what we might offer with respect to such
   // things happening automatically, versus users being allowed to specify what
   // they wish to happen. So, right now, we're not yet testing this concept.

}
