
// -----------------------------------------------------------------------------
// Functions for MAKING or MODIFYING trees
// -----------------------------------------------------------------------------

// start
nodeType &start(
   const std::string &type_str,
   const std::string &gnds_str,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   // begin a new tree
   clear();

   // TYPE NODE: "xml", etc.
   root = std::make_shared<nodeType>();
   root->name = type_str;
   if (type_str == "xml") {
      // xml
      if (&version == &detail::default_string)
         root->push("version","1.0");
      else if (version != "")
         root->push("version",version);
      if (&encoding == &detail::default_string)
         root->push("encoding","UTF-8");
      else if (encoding != "")
         root->push("encoding",encoding);
   } else if (type_str == "hdf5") {
      // fixme Write hdf5 case
   } else {
      // fixme Write json case
   }

   // PRIMARY GNDS NODE: "reactionSuite", etc.
   nodeType &gnds_node = root->push();
   gnds_node.name = gnds_str;
   return gnds_node;
}
