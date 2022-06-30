
// -----------------------------------------------------------------------------
// node2json
// -----------------------------------------------------------------------------

template<class NODE>
bool node2json(
   const NODE &node, nlohmann::ordered_json &j,
   const std::string &suffix = ""
) {
   // Original node name, and suffixed name. The latter is for handling child
   // nodes of the same name under the same parent node, and includes a numeric
   // suffix (so, name0, name1, etc.) in that scenario. This is needed for JSON
   // because JSON doesn't support same-named child nodes. In cases where the
   // name was unique to begin with, nameOriginal == nameSuffixed.
   const std::string nameOriginal = node.name;
   const std::string nameSuffixed = node.name + suffix;

   // Create new ordered_json in j
   nlohmann::ordered_json &json = j[nameSuffixed];

   // ------------------------
   // metadata ==> json
   // ------------------------

   if (suffix != "")
      json["#nodeName"] = nameOriginal;

   for (auto &meta : node.metadata)
      json["#attributes"][meta.first] = meta.second;

   // ------------------------
   // children ==> json
   // ------------------------

   // First, account for what children appear in the current node. If any child
   // name appears multiple times, we must deal with that. For each represented
   // child name, the map gets 0 if the name appears once, 1 if it appears more
   // than once. Later, this 0/1 is used initially to make a boolean choice;
   // then it serves as a counter to generate a 0-indexed numeric suffix that
   // makes the child names unique: name0, name1, etc.
   std::map<std::string,std::size_t> childNames;
   for (auto &c : node.children) {
      auto iter = childNames.find(c->name);
      if (iter == childNames.end())
         childNames.insert({c->name,0}); // once (so far)
      else
         iter->second = 1; // more than once
   }

   // now revisit and process the child nodes
   for (auto &c : node.children) {
      const std::size_t counter = childNames.find(c->name)->second++;
      if (!node2json(*c, json, counter ? std::to_string(counter-1) : ""))
         return false;
   }

   // done
   return true;
}
