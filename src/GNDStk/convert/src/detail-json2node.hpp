
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// error_json2node
inline void error_json2node(const std::string &message)
{
   log::error(
     "Internal error in json2node(nlohmann::ordered_json, Node):\n"
     "Message: \"{}\".",
      message
   );
   throw std::exception{};
}


// -----------------------------------------------------------------------------
// json2node
// -----------------------------------------------------------------------------

// nlohmann::ordered_json::const_iterator ==> Node
// Why the iterator rather than the ordered_json object? I found that there
// were some seemingly funny semantics in the nlohmann JSON library. As we
// can see below, we have for example iter->is_object() (so, the -> operator,
// typical for iterators), but also iter.value() (the . operator - on an
// iterator). Similarly, also seen below, with the sub-elements. This is why
// we are, for now, writing our for-loops, here as well as in the functions
// that call this, in the older iterator form rather than the range-based-for
// form. Perhaps there's a way to reformulate all this in a shorter way, but
// this is what we have for now.

template<class NODE>
bool json2node(const nlohmann::ordered_json::const_iterator &iter, NODE &node)
{
   static const std::string context =
      "json2node(nlohmann::ordered_json::const_iterator, Node)";

   // the node sent here should be fresh, ready to receive entries...
   if (!node.empty())
      error_json2node("!node.empty()");

   // non-object cases should have been handled
   // before any caller calls this function...
   if (!iter->is_object())
      error_json2node("!iter->is_object()");

   // any "#metadata" key (a specially-named "child node" that we use in JSON
   // in order to identify attributes) should have been handled in the caller...
   if (iter.key() == "#metadata")
      error_json2node("iter.key() == \"#metadata\"");

   // key,value ==> node name, JSON value to bring in
   node.name = iter.key();
   const nlohmann::ordered_json &json = iter.value();

   // elements
   for (auto elem = json.begin();  elem != json.end();  ++elem) {
      if (elem.key() == "#nodename") {
         // #nodename? ...extract as current node's true name
         node.name = elem->get<std::string>();
      } else if (elem.key() == "#metadata") {
         // #metadata? ...extract as current node's metadata
         const auto &jsub = elem.value();
         for (auto attr = jsub.begin();  attr != jsub.end();  ++attr)
            node.add(attr.key(), attr->get<std::string>());
      } else if (elem->is_string()) {
         // string? ...extract as metadata key/value pair
         node.add(elem.key(), elem->get<std::string>());
      } else if (elem->is_object()) {
         // {} object? ...extract as normal child node
         try {
            if (!json2node(elem,node.add()))
               return false;
         } catch (...) {
            log::function(context);
            throw;
         }
      } else if (elem->is_null()) {
         // null node? ...extract as normal (albeit empty) child node
         // In GNDS, e.g. XML's <RutherfordScattering/> or <isotropic2d/>
         node.add().name = elem.key();
      } else {
         // no other cases are handled right now
         error_json2node("unhandled JSON value type");
      }
   }

   // done
   return true;
}
