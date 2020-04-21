
// -----------------------------------------------------------------------------
// Tree::reset()
// For starting a tree, or resetting it with certain top-level boilerplate.
// Contrast with clear(), which completely clears the tree of any contents.
// Note that the constructors call this, as necessary, so that you don't need
// to - and probably shouldn't, in a construction context. It's intended for
// the relatively unusual but plausible cases where you have a tree object
// that's persistent in some way (function- or class-scope static, global
// variable, singleton), and wish to remove its current contents and begin
// again with some boilerplate (declaration node plus top-level GNDS node.)
// The described effect could be had in other ways, of course; this is just
// intended as a convenience.
// -----------------------------------------------------------------------------

// reset(top-level node, format[, version[, encoding]])
// Example:
//    GNDStk::Tree<> t(GNDStk::child::reactionSuite, GNDStk::format::xml);
// Briefly:
//    Tree<> t(reactionSuite, format::xml);
// with appropriate usings.


// ------------------------
// reset(top, format, ...)
// ------------------------

template<class RESULT, find FIND, class METADATA, class CHILDREN>
nodeType &reset(
   const child_t<RESULT,FIND,METADATA,CHILDREN> &top,
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
      root->add("version",  detail::sent(version ) ? version  : "1.0"  );
      root->add("encoding", detail::sent(encoding) ? encoding : "UTF-8");
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
// reset(top, string, ...)
// ------------------------

template<class RESULT, find FIND, class METADATA, class CHILDREN>
nodeType &reset(
   const child_t<RESULT,FIND,METADATA,CHILDREN> &top,
   const std::string &form,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   if (eq_null(form)) return reset(top, format::null, version, encoding);
   if (eq_tree(form)) return reset(top, format::tree, version, encoding);
   if (eq_xml (form)) return reset(top, format::xml,  version, encoding);
   if (eq_json(form)) return reset(top, format::json, version, encoding);
   if (eq_hdf5(form)) return reset(top, format::hdf5, version, encoding);

   // fixme Have some sort of warning
   assert(false);

   // fallback: assume intended output file format, if any, is XML
   return reset(top, format::xml, version, encoding);
}
