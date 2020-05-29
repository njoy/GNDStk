
// -----------------------------------------------------------------------------
// get_pcdata_string
// -----------------------------------------------------------------------------

namespace detail {

template<class NODE>
const std::string &get_pcdata_string(const NODE &node)
{
   // fixme This function would be shorter if it used our keyword system,
   // which, alas, isn't #included yet at this point. Consider fixing this.
   // Also, we really could use a more-informative error message below.

   // Context: we're in, say, a <values> node, which ends up having a <pcdata>
   // node inside of it, which in turn has a metadata value with the key "text".
   // That's how something like <values>1 2 3 4</values> ends up being encoded.
   // Our goal here is to extract the "1 2 3 4".
   for (auto &c : node.children)
      if (c->name == "pcdata")
         for (auto &m : c->metadata)
            if (m.first == "text")
               return m.second;

   log::error(
      "Unable to find pcdata+text entry in the Node,\n"
      "but it's needed for an operation"
   );
   throw std::exception{};

   // leave here, even if unreached
   static const std::string empty = "";
   return empty;
}

} // namespace detail
