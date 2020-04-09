
// -----------------------------------------------------------------------------
// node2container_data
// -----------------------------------------------------------------------------

namespace detail {

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
const std::string &node2container_data(
   const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
) {
   for (auto &m : node.metadata) {
      if (m.first == detail::keyword_pcdata ||
          m.first == detail::keyword_cdata) {
         return m.second;
      }
   }

   // fixme
   assert(false);

   static const std::string empty = "";
   return empty;
}

} // namespace detail
