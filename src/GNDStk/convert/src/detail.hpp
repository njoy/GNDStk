
namespace detail {

// Node <==> XML
#include "detail-node2xml.hpp"
#include "detail-xml2node.hpp"

// Node <==> JSON
#include "detail-node2json.hpp"
#include "detail-json2node.hpp"

// Node <==> HDF5
#include "detail-node2hdf5.hpp"
#include "detail-hdf52node.hpp"


// -----------------------------------------------------------------------------
// node2node
// -----------------------------------------------------------------------------

template<class NODE>
void node2node(const NODE &from, NODE &to)
{
   // clear
   to.clear();

   // name
   to.name = from.name;

   // metadata
   for (auto &m : from.metadata)
      to.add(m.first,m.second);

   // children
   for (auto &c : from.children)
      node2node(*c, to.add());
}

} // namespace detail
