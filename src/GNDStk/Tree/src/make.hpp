
// -----------------------------------------------------------------------------
// Functions for MAKING or MODIFYING trees
// -----------------------------------------------------------------------------

// start
nodeType &start(
   const std::string &type_str,
   const std::string &gnds_str,
   const std::string &param1 = static_str1,
   const std::string &param2 = static_str2
) {
   // begin a new tree
   clear();

   // TYPE NODE: "xml", etc.
   root = std::make_shared<nodeType>();
   root->name = type_str;
   if (type_str == "xml") {
      // xml
      if (&param1 == &static_str1)
         root->push("version","1.0");
      else if (param1 != "")
         root->push("version",param1);
      if (&param2 == &static_str2)
         root->push("encoding","UTF-8");
      else if (param2 != "")
         root->push("encoding",param2);
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
