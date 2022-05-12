
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// error_json2node
inline void error_json2node(const std::string &message)
{
   log::error(
     "Internal error in json2node(orderedJSON, Node):\n"
     "Message: \"{}\".",
      message
   );
   throw std::exception{};
}


// -----------------------------------------------------------------------------
// json2node
// -----------------------------------------------------------------------------

// orderedJSON::const_iterator ==> Node
// Why the iterator rather than the ordered_json object? I found that there
// were some seemingly funny semantics in the nlohmann/json library. As we
// can see below, we have for example iter->is_object() (so, the -> operator,
// typical for iterators), but also iter.value() (the . operator - on an
// iterator). Similarly, also seen below, with the sub-elements. This is why
// we are, for now, writing our for-loops, here as well as in the functions
// that call this, in the older iterator form rather than the range-based-for
// form. Perhaps there's a way to reformulate all this in a shorter way, but
// this is what we have for now.

template<class NODE>
bool json2node(const orderedJSON::const_iterator &iter, NODE &node)
{
   static const std::string context =
      "json2node(orderedJSON::const_iterator, Node)";

   // the node sent here should be fresh, ready to receive entries
   if (!node.empty())
      error_json2node("!node.empty()");

   // non-object cases should have been handled in the caller
   if (!iter->is_object())
      error_json2node("!iter->is_object()");

   // any "#metadata" key (a specially-named "child node" that we use in JSON
   // in order to identify attributes) should have been handled in the caller
   if (iter.key() == "#metadata")
      error_json2node("iter.key() == \"#metadata\"");

   // ------------------------
   // key
   // ==> node name
   // ------------------------

   node.name = iter.key();

   // ------------------------
   // JSON value's elements
   // ==> children
   // ------------------------

   const orderedJSON &json = iter.value();
   for (auto elem = json.begin();  elem != json.end();  ++elem) {
      if (elem.key() == "#nodename") {
         // #nodename? ...extract as current node's true name
         node.name = elem->get<std::string>();
      } else if (elem.key() == "#metadata") {
         // #metadata? ...extract as current node's metadata
         const orderedJSON /*auto*/ &jsub = elem.value();
         for (auto attr = jsub.begin();  attr != jsub.end();  ++attr) {
            // zzz working here
            // zzz should no longer assume it's necessarily a string
            /*
            (x) string
            ( ) number
            (-) null
            (-) object
            ( ) array
            (-) boolean
            */
            if (attr->is_string()) {
               node.add(attr.key(), attr->get<std::string>());

               // zzz this is a test...
               {
                  /*
                  // zzz works...
                  using nlohmann::detail::json_sax_dom_parser;
                  ///orderedJSON val = const_cast<orderedJSON>(attr.value());
                  orderedJSON rhs = attr.value();
                  json_sax_dom_parser<orderedJSON> parser(rhs);
                  */

                  orderedJSON rhs = attr.value();
                  nlohmann::detail::json_sax_dom_parser<orderedJSON> sax(rhs);
#if 0
                  std::string str;
                  zzz.string(str);
                  std::cout << "zzz string is: \"" << str << '"' << std::endl;
#endif
               }

            } else if (attr->is_number()) {
#if 0
#if 0
#if 0
               // zzz should handle this
               /////const orderedJSON &zzz = attr.value();/////
               ///const nlohmann::ordered_json &zzz = attr.value();/////
               ///const nlohmann::json_sax<nlohmann::json> zzz = attr.value();
               /**/
               /**/
               /**/
               orderedJSON &val = const_cast<orderedJSON &>(attr.value());
               using nlohmann::detail::json_sax_dom_parser;
               json_sax_dom_parser<orderedJSON> zzz(val);
               std::string str;
               zzz.string(str);
               /**/
               /**/
               /**/
#endif
#endif
#endif
               assert(false);
            } else if (attr->is_array()) {
               // zzz should handle this
               assert(false);
            } else {
               // zzz have better message
               assert(false);
            }
         }
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
