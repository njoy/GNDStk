
// -----------------------------------------------------------------------------
// Tree.reset()
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
// Example: Tree<> t(child::reactionSuite, format::xml);


// -----------------------------------------------------------------------------
// reset(kwd, format, ...)
// -----------------------------------------------------------------------------

template<class TYPE, find FIND, class CONVERTER>
Tree &reset(
   const child_t<TYPE,FIND,CONVERTER> &kwd,
   const format form = format::xml,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   // Begin a new tree
   clear();

   // Warn if the given child_t doesn't look valid for a top-level GNDS node
   if (!kwd.canBeTopLevel) {
      log::warning(
         "Tree.reset(child_t(\"{}\")) called, but the node as given by the\n"
         "child_t object is not encoded as being suitable for a top-level\n"
         "GNDS node (bool child_t.canBeTopLevel is false)",
         kwd.name
      );
   }

   try {
      // Declaration node: "xml", etc.
      // This can specify an eventual intended file type for the GNDS hierarchy.
      if (form == format::xml || form == format::null || form == format::tree) {
         // xml, null, tree
         nodeType::add("xml");
         decl().add("version",  detail::sent(version ) ? version  : "1.0"  );
         decl().add("encoding", detail::sent(encoding) ? encoding : "UTF-8");
      } else if (form == format::json) {
         // json
         nodeType::add("json");
         // any use for version and encoding?
      } else if (form == format::hdf5) {
         // hdf5
         nodeType::add("hdf5");
         // any use for version and encoding?
      } else {
         log::error(
            "Internal error in Tree.reset(child_t(\"{}\"),format,...):\n"
            "Unrecognized format; apparently, we missed something. "
            "Please report this to us",
            kwd.name
         );
         throw std::exception{};
      }

      // GNDS node: "reactionSuite", etc.
      nodeType::add(kwd.name);
      return *this;

   } catch (...) {
      log::member("Tree.reset(child_t(\"{}\"),format,...)", kwd.name);
      throw;
   }
}



// -----------------------------------------------------------------------------
// reset(kwd, string, ...)
// -----------------------------------------------------------------------------

template<class TYPE, find FIND, class CONVERTER>
Tree &reset(
   const child_t<TYPE,FIND,CONVERTER> &kwd,
   const std::string &form,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   try {
      // recognized formats
      if (eq_null(form)) return reset(kwd, format::null, version, encoding);
      if (eq_tree(form)) return reset(kwd, format::tree, version, encoding);
      if (eq_xml (form)) return reset(kwd, format::xml,  version, encoding);
      if (eq_json(form)) return reset(kwd, format::json, version, encoding);
      if (eq_hdf5(form)) return reset(kwd, format::hdf5, version, encoding);

      // fallback: use XML
      // Note: we should consider making this an error
      log::warning("Unrecognized format \"{}\"; defaulting to XML", form);
      return reset(kwd, format::xml, version, encoding);

   } catch (...) {
      log::member("Tree.reset(child_t(\"{}\"),\"{}\",...)", kwd.name, form);
      throw;
   }
}
