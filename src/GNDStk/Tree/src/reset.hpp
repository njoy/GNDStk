
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

// reset(top-level node, FileType [, version[, encoding]])
// Example: Tree t(child::reactionSuite, FileType::xml);


// -----------------------------------------------------------------------------
// reset(kwd, FileType, ...)
// -----------------------------------------------------------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
Tree &reset(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const FileType format = FileType::xml,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   // Begin a new tree
   clear();

   try {
      // Declaration node: "#xml", etc.
      // This can specify an eventual intended file format
      // for the GNDS hierarchy.
      if (format == FileType::xml ||
          format == FileType::guess ||
          format == FileType::debug
      ) {
         // xml, guess, tree
         add("#xml");
         decl().add("version",  detail::sent(version ) ? version  : "1.0"  );
         decl().add("encoding", detail::sent(encoding) ? encoding : "UTF-8");
      } else if (format == FileType::json) {
         // json
         add("#json");
      } else if (format == FileType::hdf5) {
         // hdf5
         add("#hdf5");
      } else {
         log::error(
            "Internal error in Tree.reset(" + detail::keyname(kwd) +
            ", format, ...):\n"
            "Unrecognized file format; apparently, we missed something.\n"
            "Please report this to us.");
         throw std::exception{};
      }

      // GNDS node: "reactionSuite", etc.
      add(kwd.name);
      return *this;

   } catch (...) {
      log::member("Tree.reset(" + detail::keyname(kwd) + ",format,...)");
      throw;
   }
}



// -----------------------------------------------------------------------------
// reset(kwd, string, ...)
// -----------------------------------------------------------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
Tree &reset(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   const std::string &format,
   const std::string &version  = detail::default_string,
   const std::string &encoding = detail::default_string
) {
   try {
      bool matched;
      const FileType type = string2filetype(format,matched);
      if (matched)
         return reset(kwd, type, version, encoding);

      // fallback: use XML
      // Note: we should consider making this an error
      log::warning(
         "Unrecognized file format \"{}\"; defaulting to XML", format);
      return reset(kwd, FileType::xml, version, encoding);

   } catch (...) {
      log::member(
         "Tree.reset(" + detail::keyname(kwd) + ",\"{}\",...)", format);
      throw;
   }
}
