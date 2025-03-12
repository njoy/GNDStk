
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

// Helper
inline void warn_node_top_metadata(const Node &node, const std::string &context)
{
   if (node.metadata.size() != 0) {
      log::warning(
         "Node has name \"/\" but also contains metadata. This is\n"
         "not expected in this context. We'll ignore the metadata.");
      log::function(context);
   }
}

// Helper
inline void info_node_multiple_dec(const std::string &context)
{
   log::info(
      "Node has name \"/\" but multiple \"declaration nodes\".\n"
      "We'll combine the metadata from all such nodes.");
   log::function(context);
}

} // namespace detail
