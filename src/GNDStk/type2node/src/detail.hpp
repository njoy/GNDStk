
// -----------------------------------------------------------------------------
// put_pcdata_string
// -----------------------------------------------------------------------------

namespace detail {

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
std::string &put_pcdata_string(
   GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
) {
   if (node.metadata.size() != 0) {
      log::error(
         "Unable to write pcdata (plain character data) entry to the Node,\n"
         "as needed for an operation, because a pcdata entry is already there"
      );
      throw std::exception{};
   }

   node.metadata.push_back({keyword_pcdata,""});
   return node.metadata.back().second;
}

} // namespace detail
