
// -----------------------------------------------------------------------------
// Tree::init()
// For making or modifying trees
// -----------------------------------------------------------------------------

// init(top-level node, format[, version[, encoding]])
// Example:
//    GNDStk::Tree<> t(GNDStk::child::reactionSuite,GNDStk::format::xml);
// Briefly:
//    Tree<> t(reactionSuite,format::xml);
// with appropriate usings.


// ------------------------
// init(top, format, ...)
// ------------------------

template<class RESULT, bool MULTIPLE, class METADATA, class CHILDREN>
nodeType &init(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &top,
   const format form = format::xml,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   // fixme Write all the cases where I currently have assert(false)

   // Begin a new tree
   clear();

   // Is the given child_t object invalid for a top-level node?
   if (not top.canBeTopLevel) {
      assert(false);
      // consider having a warning, but allowing
      // the allegedly invalid top-level node
   }

   // Declaration node: "xml", etc.
   // This is our Tree object's technically top-level ("over the top"?) node
   // that can specify an eventual intended file type for the GNDS hierarchy.
   root = std::make_unique<nodeType>();

   if (form == format::xml or form == format::null or form == format::tree) {
      // xml, null, tree
      root->name = "xml";
      root->add(
         "version",
         &version  == &detail::default_string ? "1.0"   : version);
      root->add(
         "encoding",
         &encoding == &detail::default_string ? "UTF-8" : encoding);
   } else if (form == format::json) {
      // json
      root->name = "json";
      // what about version and encoding?
   } else if (form == format::hdf5) {
      // hdf5
      root->name = "hdf5";
      // what about version and encoding?
   } else {
      assert(false);
   }

   // TOP-LEVEL GNDS NODE: "reactionSuite", etc.
   nodeType &GNDSTop = root->add();
   GNDSTop.name = top.name; // extract name from the give child_t top parameter
   return GNDSTop;
}


// ------------------------
// init(top, string, ...)
// ------------------------

template<class RESULT, bool MULTIPLE, class METADATA, class CHILDREN>
nodeType &init(
   const child_t<RESULT,MULTIPLE,METADATA,CHILDREN> &top,
   const std::string &form,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   if (eq_null(form)) return init(top, format::null, version, encoding);
   if (eq_tree(form)) return init(top, format::tree, version, encoding);
   if (eq_xml (form)) return init(top, format::xml,  version, encoding);
   if (eq_json(form)) return init(top, format::json, version, encoding);
   if (eq_hdf5(form)) return init(top, format::hdf5, version, encoding);

   // fixme Have some sort of warning
   assert(false);

   // fallback: assume intended output file format, if any, is XML
   return init(top, format::xml, version, encoding);
}
