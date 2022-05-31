
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
      else {
         assert(false);
      }
   }

   return oss.str();
}


// -----------------------------------------------------------------------------
// json_pair
// -----------------------------------------------------------------------------

template<class NODE>
bool json_pair(
   NODE &node, const orderedJSON &siblings,
   const std::string &key, const orderedJSON &value,
   const bool plain
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
      if (plain)
         node.add(key, json_array(value));
      else {
         Node &child = node.add(key);
         child.add("#pcdata").add("#text", json_array(value));
         for (auto sib = siblings.begin();  sib != siblings.end();  ++sib) {
            if (sib.key() == key + "#nodename")
               child.name = sib->get<std::string>();
            else if (sib.key() == key + "#metadata") {
               const orderedJSON &jsub = sib.value();
               for (auto attr = jsub.begin();  attr != jsub.end();  ++attr)
                  json_pair(child, orderedJSON{}, attr.key(), *attr, true);
            }
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
      // *** unknown!
      json2node_error("Unknown/unhandled JSON value type");
   }

   return true;
}


// -----------------------------------------------------------------------------
// json2node
// -----------------------------------------------------------------------------

// NODE is GNDStk::Node, which is an "incomplete type" to the compiler here.
template<class NODE>
bool json2node(const std::string &key, const orderedJSON &value, NODE &node)
{
   // the node sent here should be fresh, ready to receive entries
   if (!node.empty())
      json2node_error("!node.empty()");

   // non-(JSON "objects") should have been handled in the caller
   if (!value.is_object())
      json2node_error("JSON value !is_object()");

   // the following cases should have been handled in the caller
   if (endsin(key, "#nodename"))
      json2node_error("JSON key ends in \"#nodename\"");
   if (endsin(key, "#metadata"))
      json2node_error("JSON key ends in \"#metadata\"");

   // node name: from key
   node.name = key;

   // ------------------------
   // JSON object's elements
   // ==> metadata
   // ==> children
   // ------------------------

   const orderedJSON &siblings = value;
   for (auto keyval = value.begin();  keyval != value.end();  ++keyval) {
      const std::string &key   = keyval.key();
      const orderedJSON &child = keyval.value();

      if (key == "#nodename") {
         // *** #nodename
         // Special entry, giving the parent Node's original name
         node.name = child.get<std::string>();
      } else if (key == "#metadata") {
         // *** #metadata
         for (auto attr = child.begin();  attr != child.end();  ++attr)
            json_pair(node, orderedJSON{}, attr.key(), *attr, true);
      } else if (beginsin(key,"#cdata") || beginsin(key,"#comment")) {
         // *** #cdata[N]/#comment[N]
         // Expand into a child node #cdata/#comment with a #text attribute.
         if (child.is_object())
            try {
               if (!json2node(key, child, node.add()))
                  return false;
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         else
            node.add(beginsin(key,"#cdata") ? "#cdata" : "#comment")
                .add("#text",child.get<std::string>());
      } else if (beginsin(key,"#pcdata")) {
         // *** #pcdata[N]
         if (child.is_object())
            try {
               if (!json2node(key, child, node.add()))
                  return false;
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         else // array
            node.add("#pcdata").add("#text", json_array(child));
      } else if (endsin(key,"#nodename") || endsin(key,"#metadata")) {
         // *** Ignore, in this context
      } else {
         // *** General case
         json_pair(node, siblings, key, child, false);
      }
   } // for each element of the key/value pair corresponding to the Node

   // done
   return true;
}
