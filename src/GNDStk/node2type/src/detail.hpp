
// -----------------------------------------------------------------------------
// get_pcdata_string
// -----------------------------------------------------------------------------

namespace detail {

template<class NODE>
const std::string &get_pcdata_string(const NODE &node)
{
   // Context
   // We're in, say, a <values> node, which has a <pcdata> child node, which,
   // finally, has a metadatum with key "text". That's how GNDS content like
   // <values>...</values> (from an XML file) gets encoded in our node objects.
   // Our goal here is to extract the "..." - the metadatum's value string.
   for (auto &c : node.children)
      if (c->name == "pcdata")
         for (auto &m : c->metadata)
            if (m.first == "text")
               return m.second;

   log::error(
      "Internal error in detail::get_pcdata_string().\n"
      "Unable to find child \"pcdata\" metadatum \"text\" entry in the Node,\n"
      "but it's needed for an operation"
   );
   throw std::exception{};

   // unreached, given the above throw, but might silence compiler warnings
   static const std::string empty = "";
   return empty;
}

} // namespace detail
