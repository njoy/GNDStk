
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
// json_array
// -----------------------------------------------------------------------------

inline std::string json_array(const orderedJSON &attr)
{
   std::ostringstream oss;
   int count = 0;

   for (const orderedJSON &e : attr) {
      oss << (count++ ? " " : "");
      if (e.is_string())
         oss << e.get<std::string>();
      else if (e.is_number_integer())
         oss << e.get<std::int64_t>();
      else if (e.is_number_unsigned())
         oss << e.get<std::uint64_t>();
      else if (e.is_number_float())
         oss << e.get<double>();
      else
         assert(false);
   }

   return oss.str();
}


// -----------------------------------------------------------------------------
// json_pair
// -----------------------------------------------------------------------------

template<class NODE>
bool json2node(const orderedJSON::const_iterator &iter, NODE &node);

template<class NODE>
bool json_pair(NODE &node, const orderedJSON::const_iterator &keyval)
{
   const std::string key = keyval.key();

   if (keyval->is_null()) {
      // *** null
      // Create a normal (albeit empty) child node.
      // Example in XML GNDS: <RutherfordScattering/>.
      node.add(key);
   } else if (keyval->is_boolean()) {
      // *** boolean
      node.add(key, keyval->get<bool>() ? "true" : "false");
   } else if (keyval->is_number_integer()) {
      // *** number: integer
      node.add(key, keyval->get<std::int64_t>());
   } else if (keyval->is_number_unsigned()) {
      // *** number: unsigned
      node.add(key, keyval->get<std::uint64_t>());
   } else if (keyval->is_number_float()) {
      // *** number: double
      node.add(key, keyval->get<double>());
   } else if (keyval->is_string()) {
      // *** string
      node.add(key, keyval->get<std::string>());
   } else if (keyval->is_array()) {
      // *** array
      node.add(key, json_array(*keyval));
   } else if (keyval->is_object()) {
      // *** object
      try {
         if (!json2node(keyval,node.add()))
            return false;
      } catch (...) {
         log::function("json2node()");
         throw;
      }
   } else {
      // *** unknown!
      error_json2node("Unknown/unhandled JSON value type");
   }

   return true;
}


// -----------------------------------------------------------------------------
// json2node
// -----------------------------------------------------------------------------

// NODE is GNDStk::Node, which is an "incomplete type" to the compiler here.
template<class NODE>
bool json2node(const orderedJSON::const_iterator &iter, NODE &node)
{
   // the node sent here should be fresh, ready to receive entries
   if (!node.empty())
      error_json2node("!node.empty()");

   // non-(JSON "objects") should have been handled in the caller
   if (!iter->is_object())
      error_json2node("JSON value !is_object()");

   // any "#metadata" keys (specially-named "child nodes" that we use in JSON
   // in order to identify attributes) should have been handled in the caller
   if (endsin(iter.key(), "#metadata"))
      error_json2node("JSON key ends in \"#metadata\"");

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

   const orderedJSON &children = iter.value();
   for (auto keyval = children.begin(); keyval != children.end(); ++keyval) {
      const std::string &key = keyval.key();

      // #nodename
      // Special entry, giving the parent Node's original name
      if (key == "#nodename") {
         node.name = keyval->get<std::string>();
         continue;
      }

      // #metadata
      if (key == "#metadata") {
         assert(keyval->is_object());
         const orderedJSON &jsub = keyval.value();
         for (auto attr = jsub.begin(); attr != jsub.end(); ++attr)
            json_pair(node,attr);
         continue;
      }

      // #cdata/#comment
      // Possibly with a numeric suffix.
      // Expand into a child node #cdata/#comment with a #text attribute.
      if (beginsin(key,"#cdata") || beginsin(key,"#comment")) {
         assert(keyval->is_object() || keyval->is_string());
         if (keyval->is_object())
            try {
               if (!json2node(keyval,node.add()))
                  return false;
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         else if (keyval->is_string())
            node.add(beginsin(key,"#cdata") ? "#cdata" : "#comment")
                .add("#text",keyval->get<std::string>());
         continue;
      }

      // #pcdata
      // Possibly with a numeric suffix.
      if (beginsin(key,"#pcdata")) {
         assert(keyval->is_object() || keyval->is_array());
         if (keyval->is_object())
            try {
               if (!json2node(keyval,node.add()))
                  return false;
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         else // array
            node.add("#pcdata").add("#text",json_array(*keyval));
         continue;
      }

      // general
      json_pair(node,keyval);

   } // for each element of the key/value corresponding to the Node

   // done
   return true;
}
