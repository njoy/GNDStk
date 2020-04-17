
// -----------------------------------------------------------------------------
// get_pcdata_string
// -----------------------------------------------------------------------------

namespace detail {

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
const std::string &get_pcdata_string(
   const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &node
) {
   for (auto &m : node.metadata) {
      if (
         ///m.first == keyword_cdata ||
         m.first == keyword_pcdata
      ) {
         return m.second;
      }
   }

   // fixme
   assert(false);

   static const std::string empty = "";
   return empty;
}

} // namespace detail
