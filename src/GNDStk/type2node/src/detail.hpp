
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
   assert(node.metadata.size() == 0);
   node.metadata.push_back({keyword_pcdata,""});
   return node.metadata.back().second;
}

} // namespace detail
