
// Helper: json2node_error
inline void json2node_error(const std::string &message)
{
   log::error(
     "Internal error in json2node():\n"
     "Message: \"{}\".", message);
   throw std::exception{};
}

// Forward declaration
template<class NODE>
void json2node(const orderedJSON &, NODE &, const bool inferNodeName = false);


// -----------------------------------------------------------------------------
// json_array
// -----------------------------------------------------------------------------

inline std::string json_array(const orderedJSON &array)
{
   assert(array.is_array());

   std::ostringstream oss;
   int count = 0;

   for (const orderedJSON &element : array) {
      // separator
      oss << (count++ ? " " : "");
      // array element types we use
      element.is_number_integer () ? (oss << element.get<std::int64_t >())
    : element.is_number_unsigned() ? (oss << element.get<std::uint64_t>())
    : element.is_number_float   () ? (oss << element.get<double       >())
    : element.is_string         () ? (oss << element.get<std::string  >())
    : // unexpected
     (json2node_error("JSON array element is of unexpected type"), oss);
   }

   return oss.str();
}


// -----------------------------------------------------------------------------
// json_pair
// -----------------------------------------------------------------------------

template<class NODE>
void json_pair(
   const std::string &key, const orderedJSON &val,
   const orderedJSON &peers, NODE &node
) {
   if (val.is_null()) {
      // null; nothing to do
   } else if (val.is_boolean()) {
      // boolean
      node.add(key, val.get<bool>() ? "true" : "false");
   } else if (val.is_number_integer()) {
      // number: integer
      node.add(key, val.get<std::int64_t>());
   } else if (val.is_number_unsigned()) {
      // number: unsigned
      node.add(key, val.get<std::uint64_t>());
   } else if (val.is_number_float()) {
      // number: double
      node.add(key, val.get<double>());
   } else if (val.is_string()) {
      // string
      node.add(key, val.get<std::string>());
   } else if (val.is_array()) {
      // array
      if (peers.size() == 0)
         node.add(key, json_array(val)); // context is such that it's metadata
      else {
         node.add(special::data).add(special::text, json_array(val));
         for (const auto &peer : peers.items()) {
            if (peer.key() == key + special::nodename)
               node.name = peer.value().get<std::string>();
            if (peer.key() == key + special::metadata) {
               for (const auto &m : peer.value().items())
                  json_pair(m.key(), m.value(), orderedJSON{}, node);
            }
         }
      }
   } else if (val.is_object()) {
      // object
      try {
         json2node(val,node);
      } catch (...) {
         log::function("json2node()");
         throw;
      }
   } else {
      // unexpected
      json2node_error("JSON key/value pair's value is of unexpected type");
   }
}


// -----------------------------------------------------------------------------
// json2node
// -----------------------------------------------------------------------------

// NODE is GNDStk::Node, an incomplete type to the compiler here.
// Note: the object parameter is a JSON "object", i.e. {...}.
template<class NODE>
void json2node(const orderedJSON &object, NODE &node, bool inferNodeName)
{
   // The node sent here shouldn't already have metadata or children
   if (node.metadata.size() != 0 || node.children.size() != 0)
      json2node_error("Node should be empty, but has metadata and/or children");

   // Special node names (special::prefix...) need trailing digits removed
   if (node.name != "" && node.name[0] == special::prefix)
      while (isdigit(node.name.back()))
         node.name.pop_back();

   // For each key/value pair
   for (const auto &pair : object.items()) {
      const std::string &key = pair.key();
      const orderedJSON &val = pair.value();

      if (inferNodeName && key.find(special::prefix) == std::string::npos) {
         // Infer the node name from this (non-special) key
         node.name = key;
         inferNodeName = false;
         json_pair(key, val, object, node);
      } else if (key == special::nodename) {
         // Special key: nodename
         node.name = val.get<std::string>();
         inferNodeName = false;
      } else if (key == special::metadata) {
         // Special key: metadata
         for (const auto &m : val.items())
            json_pair(m.key(), m.value(), orderedJSON{}, node);
      } else if (
         beginsin(key,special::cdata) ||
         beginsin(key,special::comment) ||
         beginsin(key,special::data)
      ) {
         // Special key: cdata, comment, or data, with optional suffix
         if (val.is_object()) {
            try {
               json2node(val, node.add(key));
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         } else {
            beginsin(key,special::data)
          ? node.add(special::data   ).add(special::text, json_array(val))
          : beginsin(key,special::cdata)
          ? node.add(special::cdata  ).add(special::text, val.get<std::string>())
          : node.add(special::comment).add(special::text, val.get<std::string>());
         }
      } else if (endsin(key,special::nodename) ||
                 endsin(key,special::metadata)) {
         // Special key: with nodename or metadata *suffix*
         // Ignore, in this context. Note that key *equal* to either of those
         // was handled earlier. The cases here are dealt with in json_pair(),
         // called below. There, we process e.g. "foo", and scan object.items()
         // to process "foo*" where * is either of the relevant suffixes.
      } else {
         // Normal key
         json_pair(key, val, object, node.add(key));
      }
   } // key/value pairs
}
