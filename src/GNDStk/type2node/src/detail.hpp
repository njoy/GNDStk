
// -----------------------------------------------------------------------------
// put_pcdata_string
// -----------------------------------------------------------------------------

namespace detail {

template<class NODE>
std::string &put_pcdata_string(NODE &node)
{
   // Our own calls to this detail function clear the node first,
   // and it shouldn't be called directly. So let's double-check.
   if (node.metadata.size() != 0) {
      log::error(
         "Internal error in detail::put_pcdata_string().\n"
         "Please contact us"
      );
      throw std::exception{};
   }

   return node.add("pcdata").add("text","").second;
}

} // namespace detail
