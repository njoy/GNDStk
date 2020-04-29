
// -----------------------------------------------------------------------------
// Tree::reset()
//
// For starting a tree, or resetting it with certain top-level boilerplate.
// Contrast with clear(), which completely clears the tree of any contents.
// Note that the constructors call this, as necessary, so that you don't need
// to - and probably shouldn't, in a construction context. It's intended for
// the relatively unusual but plausible cases where you have a tree object
// that's persistent in some way (function or class scope static, global
// variable, singleton), and you wish to remove the tree's current contents
// and begin again with some boilerplate (declaration node and top-level GNDS
// node.) The described effect could be had in other ways, of course; this
// function is just intended to be a convenience.
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
   // Begin a new tree
   clear();

   // Warn if the given child_t is not valid for a top-level GNDS node
   if (not top.canBeTopLevel) {
      log::warning(
         "Tree::reset(child_t(\"{}\")) called, but the top-level GNDS node\n"
         "as given by the child_t object is not encoded as being appropriate\n"
         "for a top-level GNDS node. (bool child_t.canBeTopLevel is false).\n"
         "Allowing it, but know what you're doing. (Or have us fix it.)",
         top.name
      );
   }

   // Declaration node: "xml", etc.
   // This is our Tree object's technically top-level ("over the top"?) node
   // that can specify an eventual intended file type for the GNDS hierarchy.
   root = std::make_unique<nodeType>();

   // The add()s can throw, and we have our own potential throw as well;
   // so let's just put this all in a try...
   try {
      if (form == format::xml or form == format::null or form == format::tree) {
         // xml, null, tree
         decl().name = "xml";
         decl().add("version",  detail::sent(version ) ? version  : "1.0"  );
         decl().add("encoding", detail::sent(encoding) ? encoding : "UTF-8");
      } else if (form == format::json) {
         // json
         decl().name = "json";
         // any use for version and encoding?
      } else if (form == format::hdf5) {
         // hdf5
         decl().name = "hdf5";
         // any use for version and encoding?
      } else {
         log::error(
            "Internal error in Tree::reset(child_t(\"{}\"),format,...):\n"
            "Unrecognized format; apparently, we missed something. "
            "Please report this to us",
            top.name
         );
         throw std::exception{};
      }

      // GNDS node: "reactionSuite", etc.
      return decl().add(top.name);

   } catch (const std::exception &) {
      log::context("Tree::reset(child_t(\"{}\"),format,...)", top.name);
      throw;
   }
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
   try {
      // recognized formats
      if (eq_null(form)) return reset(top, format::null, version, encoding);
      if (eq_tree(form)) return reset(top, format::tree, version, encoding);
      if (eq_xml (form)) return reset(top, format::xml,  version, encoding);
      if (eq_json(form)) return reset(top, format::json, version, encoding);
      if (eq_hdf5(form)) return reset(top, format::hdf5, version, encoding);

      // fallback: use XML
      // Note: we should consider making this an error
      log::warning("Unrecognized format \"{}\"; defaulting to XML", form);
      return reset(top, format::xml, version, encoding);

   } catch (const std::exception &) {
      log::context("Tree::reset(child_t(\"{}\"),\"{}\",...)", top.name, form);
      throw;
   }
}
