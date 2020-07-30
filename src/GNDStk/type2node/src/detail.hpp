
// -----------------------------------------------------------------------------
// put_pcdata_string
// -----------------------------------------------------------------------------

namespace detail {

template<class NODE>
std::string &put_pcdata_string(NODE &node)
{
   /*
   // fixme Really, the call context is such that this should never happen
   if (node.metadata.size() != 0) {
      log::error(
         "Unable to write pcdata (plain character data) entry to the Node,\n"
         "as needed for an operation, because a pcdata entry is already there"
      );
      throw std::exception{};
   }
   */

   return node.add("pcdata").add("text","").second;
}

} // namespace detail
