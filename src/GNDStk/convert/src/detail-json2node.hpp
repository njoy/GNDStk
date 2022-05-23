
// Helper: error_json2node
inline void error_json2node(const std::string &message)
{
   log::error(
     "Internal error in json2node():\n"
     "Message: \"{}\".", message
   );
   throw std::exception{};
}


// -----------------------------------------------------------------------------
// json2node
// -----------------------------------------------------------------------------

// orderedJSON::const_iterator ==> Node
// Why the iterator rather than the orderedJSON object? I found that there
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
   // the node sent here should be fresh, ready to receive entries
   if (!node.empty())
      error_json2node("!node.empty()");

   // non-(JSON "object") cases should have been handled in the caller
   if (!iter->is_object())
      error_json2node("!iter->is_object()");

   // any "#metadata" key (a specially-named "child node" that we use in JSON
   // in order to identify attributes) should have been handled in the caller
   if (endsin(iter.key(), "#metadata"))
      error_json2node("iter.key() ends in \"#metadata\"");

   // ------------------------
   // key
   // ==> node name
   // ------------------------

   node.name = iter.key();

   // ------------------------
   // JSON object's elements
   // ==> metadata
   // ==> children
   // ------------------------

   const orderedJSON &json = iter.value();
   for (auto elem = json.begin();  elem != json.end();  ++elem) {

      // ------------------------
      // #nodename
      // ------------------------

      // Handled not as a regular metadatum,
      // but as the present node's true name.
      if (elem.key() == "#nodename") {
         node.name = elem->get<std::string>();
         continue;
      }

      // ------------------------
      // #cdata
      // ------------------------

      // Possibly with a numeric suffix.
      // Expand into a child node #cdata with a #text attribute.
      if (beginsin(elem.key(),"#cdata")) {
         // 3 cases:
         //    cdata: { metadata/text }
         //    cdata: { nodename, metadata/text }
         //    cdata: "string"
         assert(elem->is_object() || elem->is_string());

         if (elem->is_object()) {
            try {
               if (!json2node(elem,node.add()))
                  return false;
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         }

         if (elem->is_string()) {
            node.add("#cdata").add("#text",elem->get<std::string>());
         }

         continue;
      } // "#cdata"

      // ------------------------
      // #comment
      // Like cdata case above
      // ------------------------

      // Possibly with a numeric suffix.
      // Expand into a child node #comment with a #text attribute.
      if (beginsin(elem.key(),"#comment")) {
         assert(elem->is_object() || elem->is_string());
         if (elem->is_object()) {
            try {
               if (!json2node(elem,node.add()))
                  return false;
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         }
         if (elem->is_string())
            node.add("#comment").add("#text",elem->get<std::string>());
         continue;
      } // "#comment"

      // ------------------------
      // #pcdata
      // ------------------------

      if (beginsin(elem.key(),"#pcdata")) {
         assert(elem->is_object() || elem->is_array());

         if (elem->is_object()) {
            try {
               if (!json2node(elem,node.add()))
                  return false;
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         } // #pcdata is_object()

         if (elem->is_array()) {
            std::ostringstream oss; int count = 0;
            for (const orderedJSON &e : *elem) {
               oss << (count ? " " : "");
               if (e.is_number_integer())
                  oss << e.get<std::int64_t>();
               else if (e.is_number_unsigned())
                  oss << e.get<std::uint64_t>();
               else if (e.is_number_float())
                  oss << e.get<double>();
               else if (e.is_string())
                  oss << e.get<std::string>();
               else {
                  assert(false);
               }
               count++;
            }
            node.add("#pcdata").add("#text",oss.str());
         } // #pcdata is_array()
         continue;
      } // #pcdata

      // ------------------------
      // #metadata
      // ------------------------

      if (elem.key() == "#metadata") {
         assert(elem->is_object());

         const orderedJSON &jsub = elem.value();
         for (auto attr = jsub.begin();  attr != jsub.end();  ++attr) {
            // number: integer
            if (attr->is_number_integer()) {
               node.add(attr.key(), attr->get<std::int64_t>());
               continue;
            }

            // number: unsigned
            if (attr->is_number_unsigned()) {
               node.add(attr.key(), attr->get<std::uint64_t>());
               continue;
            }

            // number: double
            if (attr->is_number_float()) {
               node.add(attr.key(), attr->get<double>());
               continue;
            }

            // string
            if (attr->is_string()) {
               node.add(attr.key(), attr->get<std::string>());
               continue;
            }

            // array
            if (attr->is_array()) {
               std::ostringstream oss; int count = 0;
               for (const orderedJSON &e : *attr) {
                  oss << (count ? " " : "");
                  if (e.is_number_integer())
                     oss << e.get<std::int64_t>();
                  else if (e.is_number_unsigned())
                     oss << e.get<std::uint64_t>();
                  else if (e.is_number_float())
                     oss << e.get<double>();
                  else if (e.is_string())
                     oss << e.get<std::string>();
                  else {
                     assert(false);
                  }
                  count++;
               }
               node.add(attr.key(), oss.str());
               continue;
            } // is_array

            assert(false);
         } // for (attr)
         continue;
      } // #metadata

      // ------------------------
      // general
      // ------------------------

      // number: integer
      if (elem->is_number_integer()) {
         node.add(elem.key(), elem->get<std::int64_t>());
         continue;
      } // is_number_integer

      // number: unsigned
      if (elem->is_number_unsigned()) {
         node.add(elem.key(), elem->get<std::uint64_t>());
         continue;
      } // is_number_unsigned

      // number: double
      if (elem->is_number_float()) {
         node.add(elem.key(), elem->get<double>());
         continue;
      } // is_number_float

      // string
      if (elem->is_string()) {
         // string? ...extract as metadata key/value pair
         node.add(elem.key(), elem->get<std::string>());
         continue;
      } // is_string

      // object
      if (elem->is_object()) {
         // {} object? ...extract as normal child node
         try {
            if (!json2node(elem,node.add()))
               return false;
         } catch (...) {
            log::function("json2node()");
            throw;
         }
         continue;
      } // is_object

      // array
      if (elem->is_array()) {
         std::ostringstream oss; int count = 0;
         for (const orderedJSON &e : *elem) {
            oss << (count ? " " : "");
            if (e.is_number_integer())
               oss << e.get<std::int64_t>();
            else if (e.is_number_unsigned())
               oss << e.get<std::uint64_t>();
            else if (e.is_number_float())
               oss << e.get<double>();
            else if (e.is_string())
               oss << e.get<std::string>();
            else {
               assert(false);
            }
            count++;
         }
         node.add(elem.key(), oss.str());
         continue;
      } // is_array

      // null
      if (elem->is_null()) {
         // null node? ...extract as normal (albeit empty) child node
         // In GNDS, e.g. XML's <RutherfordScattering/> or <isotropic2d/>
         node.add().name = elem.key();
         continue;
      } // is_null

      // no other cases are handled right now
      error_json2node("unhandled JSON value type");
      assert(false);

   } // for each element of the key/value corresponding to the Node

   // done
   return true;
}
