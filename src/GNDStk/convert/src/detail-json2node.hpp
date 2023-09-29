
#ifndef NJOY_GNDSTK_DISABLE_JSON

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
void json2node(const json::object &, NODE &, const bool inferNodeName = false);


// -----------------------------------------------------------------------------
// json_array
// -----------------------------------------------------------------------------

inline std::string json_array(const json::array &array)
{
   std::ostringstream oss;
   size_t count = 0;

   for (const json::value &element : array) {
      // separator
      oss << (count++ ? " " : "");
      // array element types we use
      // Remark. std::string(...) is indeed needed in the following line,
      // because json::string has its own operator<< that prints the string
      // in the JSON manner - with delimiting quotes. For our purposes here,
      // we need the string printed as std::string does - without quotes.
      element.is_number() ? (oss << element.get<json::number>())
    : element.is_string() ? (oss << std::string(element.get<json::string>()))
    : // unexpected element type
     (json2node_error("JSON array element is of unexpected type"), oss);
   }

   return oss.str();
}


// -----------------------------------------------------------------------------
// json_pair
// -----------------------------------------------------------------------------

template<class NODE>
void json_pair(
   const std::string &key, const json::value &val,
   const json::object &peers, NODE &node
) {
   if (val.is_null()) {
      // null; nothing to do
   } else if (val.is_boolean()) {
      // boolean
      node.add(key, val.get<json::boolean>() ? "true" : "false");
   } else if (val.is_number()) {
      // number
      std::visit(
         [&node,&key](auto &&alt)
         {
            node.add(key,alt);
         },
         json::number::variant(val.get<json::number>())
      );
   } else if (val.is_string()) {
      // string
      node.add(key, val.get<json::string>());
   } else if (val.is_array()) {
      // array
      if (peers.size() == 0) {
         // context is such that it's metadata
         node.add(key, json_array(val.get<json::array>()));
      } else {
         node.add(special::data)
             .add(special::text, json_array(val.get<json::array>()));
         for (const auto &peer : peers.items()) {
            if (peer.first == key + special::nodename)
               node.name = peer.second.get<json::string>();
            if (peer.first == key + special::metadata) {
               for (const auto &m : peer.second.items())
                  json_pair(m.first, m.second, json::object{}, node);
            }
         }
      }
   } else if (val.is_object()) {
      // object
      try {
         json2node(val.get<json::object>(),node);
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
void json2node(const json::object &object, NODE &node, bool inferNodeName)
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
      const std::string &key = pair.first;
      const json::value &val = pair.second;

      if (inferNodeName && key.find(special::prefix) == std::string::npos) {
         // Infer the node name from this (non-special) key
         node.name = key;
         inferNodeName = false;
         json_pair(key, val, object, node);
      } else if (key == special::nodename) {
         // Special key: nodename
         node.name = val.get<json::string>();
         inferNodeName = false;
      } else if (key == special::metadata) {
         // Special key: metadata
         for (const auto &m : val.items())
            json_pair(m.first, m.second, json::object{}, node);
      } else if (
         beginsin(key,special::cdata) ||
         beginsin(key,special::comment) ||
         beginsin(key,special::data)
      ) {
         // Special key: cdata, comment, or data, with optional suffix
         if (val.is_object()) {
            try {
               json2node(val.get<json::object>(), node.add(key));
            } catch (...) {
               log::function("json2node()");
               throw;
            }
         } else {
            beginsin(key,special::data)
          ? node.add(special::data   )
                .add(special::text, json_array(val.get<json::array>()))
          : beginsin(key,special::cdata)
          ? node.add(special::cdata  )
                .add(special::text, val.get<json::string>())
          : node.add(special::comment)
                .add(special::text, val.get<json::string>());
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

#endif
