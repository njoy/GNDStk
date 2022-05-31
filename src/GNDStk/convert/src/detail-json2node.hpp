
// Helper: json2node_error
inline void json2node_error(const std::string &message)
{
   log::error(
     "Internal error in json2node():\n"
     "Message: \"{}\".", message
   );
   throw std::exception{};
}

// json2node: forward declaration
template<class NODE>
bool json2node(const std::string &, const orderedJSON &, NODE &);


// -----------------------------------------------------------------------------
// json_array
// -----------------------------------------------------------------------------

inline std::string json_array(const orderedJSON &meta)
{
   std::ostringstream oss;
   int count = 0;

   for (const orderedJSON &m : meta) {
      oss << (count++ ? " " : "");
      if (m.is_string())
         oss << m.get<std::string>();
      else if (m.is_number_integer())
         oss << m.get<std::int64_t>();
      else if (m.is_number_unsigned())
         oss << m.get<std::uint64_t>();
      else if (m.is_number_float())
         oss << m.get<double>();
      else
         json2node_error("JSON array element has unexpected type");
   }

   return oss.str();
}


// -----------------------------------------------------------------------------
// json_pair
// -----------------------------------------------------------------------------

template<class NODE>
bool json_pair(
   NODE &node, const orderedJSON &siblings,
   const std::string &key, const orderedJSON &value, const bool metadatum
) {
   if (value.is_null()) {
      // *** null
      node.add(key);
   } else if (value.is_boolean()) {
      // *** boolean
      node.add(key, value.get<bool>() ? "true" : "false");
   } else if (value.is_number_integer()) {
      // *** number: integer
      node.add(key, value.get<std::int64_t>());
   } else if (value.is_number_unsigned()) {
      // *** number: unsigned
      node.add(key, value.get<std::uint64_t>());
   } else if (value.is_number_float()) {
      // *** number: double
      node.add(key, value.get<double>());
   } else if (value.is_string()) {
      // *** string
      node.add(key, value.get<std::string>());
   } else if (value.is_array()) {
      // *** array
      if (metadatum)
         node.add(key, json_array(value));
      else {
         Node &child = node.add(key);
         child.add("#pcdata").add("#text", json_array(value));
         for (const auto &sib : siblings.items()) {
            if (sib.key() == key + "#nodename")
               child.name = sib.value().get<std::string>();
            else if (sib.key() == key + "#metadata")
               for (const auto &m : sib.value().items())
                  json_pair(child, orderedJSON{}, m.key(), m.value(), true);
         }
      }
   } else if (value.is_object()) {
      // *** object
      try {
         if (!json2node(key, value, node.add()))
            return false;
      } catch (...) {
         log::function("json2node()");
         throw;
      }
   } else {
      // *** unknown
      json2node_error("JSON value type unknown or not handled");
   }

   return true;
}


// -----------------------------------------------------------------------------
// json2node
// -----------------------------------------------------------------------------

// NODE is GNDStk::Node, which is an "incomplete type" to the compiler here.
template<class NODE>
bool json2node(const std::string &key, const orderedJSON &siblings, NODE &node)
{
   // The node sent here should be fresh, ready to receive entries
   if (!node.empty())
      json2node_error("Node not empty()");

   // Non-(JSON "objects") should have been handled in the caller
   if (!siblings.is_object())
      json2node_error("JSON value !is_object() not expected here");

   // The following cases should have been handled in the caller
   if (endsin(key, "#nodename"))
      json2node_error("JSON key ending in \"#nodename\" not expected here");
   if (endsin(key, "#metadata"))
      json2node_error("JSON key ending in \"#metadata\" not expected here");

   // Node name: from key
   node.name = key;

   // ------------------------
   // JSON object's elements
   // ==> metadata
   // ==> children
   // ------------------------

   for (const auto &child : siblings.items()) {
      const std::string &childkey = child.key();
      const orderedJSON &childval = child.value();

      if (childkey == "#nodename") {
         // *** #nodename
         node.name = childval.get<std::string>();
      } else if (childkey == "#metadata") {
         // *** #metadata
         for (const auto &m : childval.items())
            json_pair(node, orderedJSON{}, m.key(), m.value(), true);
      } else if (
         beginsin(childkey,"#cdata") ||
         beginsin(childkey,"#comment") ||
         beginsin(childkey,"#pcdata")
      ) {
         // *** #cdata[N], #comment[N], #pcdata[N]
         if (childval.is_object())
            try {
               if (!json2node(childkey, childval, node.add()))
                  return false;
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         else
            beginsin(childkey,"#pcdata")
          ? node.add("#pcdata" ).add("#text", json_array(childval))
          : beginsin(childkey,"#cdata")
          ? node.add("#cdata"  ).add("#text", childval.get<std::string>())
          : node.add("#comment").add("#text", childval.get<std::string>());
      } else if (endsin(childkey,"#nodename") || endsin(childkey,"#metadata")) {
         // *** Ignore, in this context
      } else {
         // *** General case
         json_pair(node, siblings, childkey, childval, false);
      }
   }

   // done
   return true;
}
