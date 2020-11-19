
// -----------------------------------------------------------------------------
// Tree.read()
// -----------------------------------------------------------------------------

// Cases:
// 1. read(istream,   file format)
// 2. read(file name, file format) calls 1 after making istream from file name
// 3. read(istream,   string     ) calls 1 after making file format from string
// 4. read(file name, string     ) calls 2 after making file format from string



// -----------------------------------------------------------------------------
// 1. read(istream, file format)
// -----------------------------------------------------------------------------

std::istream &read(
   std::istream &is,
   file form = file::null
) {
   // clear
   // Remark as in read(string). Note that we need the clear() here, too,
   // because this function might be called directly, not via read(string).
   clear();

   // ------------------------
   // file::tree
   // Not allowed in read
   // ------------------------

   if (form == file::tree) {
      log::error(detail::format_tree_read);
      log::member("Tree.read(istream)");
      throw std::exception{};
   }

   // ------------------------
   // file::xml,json,hdf5
   // Check: consistent
   // initial content?
   // ------------------------

   // Description of the "file magic number" in case something goes wrong.
   // This may be important for diagnostics purposes in, for example, cases
   // where the file isn't valid in any format we recognize. Unless format
   // is stipulated, we assume XML if the stream begins with '<', HDF5 if
   // it begins with character 137, and JSON (for which the first file
   // character isn't set in stone) if neither. The choice is thus based
   // on file contents, not file extension. (Indeed, if this read() function
   // is called directly, there is no file name/extension - there's just
   // an istream.) Imagine that someone tries to open a bad .XML file, one
   // that doesn't begin with '<'. Via the above process, we end up assuming
   // below (unless format was provided) that it's JSON, and the diagnostic
   // message mentions "JSON" - which would be confusing to a user who knows
   // they wrote something.XML. So, when applicable, we'll include in our
   // diagnostic the file type assumption we make, to clarify the error.
   std::string magic;
   static const std::string request = ", because it was requested";

   // Examine the stream's first character ("file magic number")
   if (is.peek() == EOF) {
      log::error("The istream is empty");
      log::member("Tree.read(istream)");
      throw std::exception{};
   } else if (is.peek() == '<') {
      // looks like XML
      if (form == file::null) {
         form = file::xml;
         magic = "Assuming XML, based on the first character of the istream";
      } else if (form != file::xml) {
         detail::warning_tree_io_data(form, "XML");
         magic = "Using " + detail::print_format(form) + request;
      }
   } else if (is.peek() == 137) {
      // looks like HDF5
      if (form == file::null) {
         form = file::hdf5;
         magic = "Assuming HDF5, based on the first character of the istream";
      } else if (form != file::hdf5) {
         detail::warning_tree_io_data(form, "HDF5");
         magic = "Using " + detail::print_format(form) + request;
      }
   } else {
      // looks like JSON (via process of elimination)
      if (form == file::null) {
         form = file::json;
         magic = "Assuming JSON, based on the first character of the istream";
      } else if (form != file::json) {
         detail::warning_tree_io_data(form, "JSON");
         magic = "Using " + detail::print_format(form) + request;
      }
   }

   // The above logic is such that form cannot henceforth be file::tree,
   // which would have triggered a return, or file::null, which would have
   // become one of {xml,json,hdf5} somewhere in the above conditional.

   // ------------------------
   // Read and convert
   // ------------------------

   try {
      // Obey form, independent of whatever might or might not have been
      // warned about above. Note that if the original form parameter was
      // file::null, then form would have been modified, above, to the
      // likely correct file format, based on the peek() calls.
      if (form == file::xml) {
         // assume XML; so, create tree by converting from a temporary XML...
         XML tmp;
         if (!tmp.read(is) || !convert(tmp, *this))
            throw std::exception{};
      } else if (form == file::json) {
         // assume JSON; so, create tree by converting from a temporary JSON...
         JSON tmp;
         if (!tmp.read(is) || !convert(tmp, *this))
            throw std::exception{};
      } else if (form == file::hdf5) {
         log::error("Tree.read() for HDF5 is not implemented yet");
         throw std::exception{};
      } else {
         // The earlier logic is such that this shouldn't happen; consider
         // removing at some point
         log::error(
            "Internal error: unrecognized file format. "
            "Please report this to us"
         );
         throw std::exception{};
      }
   } catch (...) {
      if (magic != "")
         log::info(magic);
      log::member("Tree.read(istream)");
      throw;
   }

   // done
   return is;
}



// -----------------------------------------------------------------------------
// 2. read(file name, file format)
// -----------------------------------------------------------------------------

bool read(
   const std::string &filename,
   const file form = file::null
) {
   // ------------------------
   // Clear current contents
   // ------------------------

   // Note that this happens even if something below fails. This is reasonable
   // behavior; an empty tree is a reminder that the read attempt failed.
   clear();

   // ------------------------
   // file::tree
   // Not allowed in read
   // ------------------------

   // Error; this file format isn't allowed for read() (only for write())
   if (form == file::tree) {
      log::error(detail::format_tree_read);
      log::member("Tree.read(\"{}\",format)", filename);
      throw std::exception{};
   }

   // ------------------------
   // file::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   if (form == file::xml && has_extension(filename)
       && !endsin_xml(filename)) {
      detail::warning_tree_io_name("read", "xml",  filename, "XML" );
   }
   if (form == file::json && has_extension(filename)
       && !endsin_json(filename)) {
      detail::warning_tree_io_name("read", "json", filename, "JSON");
   }
   if (form == file::hdf5 && has_extension(filename)
       && !endsin_hdf5(filename)) {
      detail::warning_tree_io_name("read", "hdf5", filename, "HDF5");
   }

   // ------------------------
   // Open and read
   // ------------------------

   try {
      std::ifstream ifs(filename.c_str());
      if (!ifs) {
         log::error("Could not open input file \"{}\"", filename);
         throw std::exception{};
      }

      // Call read(istream) to do the remaining work. Note that although the
      // filename is no longer available there, the function can, and does,
      // do additional checking (complimentary to what we already did above),
      // based on looking at the content that we'll be attempting to read.
      if (!read(ifs,form))
         throw std::exception{};
      return bool(ifs);
   } catch (...) {
      log::member("Tree.read(\"{}\")", filename);
      throw;
   }
}



// -----------------------------------------------------------------------------
// 3. read(istream,string)
// -----------------------------------------------------------------------------

std::istream &read(
   std::istream &is,
   const std::string &form
) {
   try {
      if (eq_null(form)) return read(is,file::null);
      if (eq_tree(form)) return read(is,file::tree);
      if (eq_xml (form)) return read(is,file::xml );
      if (eq_json(form)) return read(is,file::json);
      if (eq_hdf5(form)) return read(is,file::hdf5);

      // unrecognized file format
      log::warning(
         "Unrecognized file format in call to tree.read(istream,\"{}\").\n"
         "We'll guess from the stream contents",
         form
      );

      // fallback: automagick
      return read(is,file::null);
   } catch (...) {
      log::member("Tree.read(istream,\"{}\")", form);
      throw;
   }
}



// -----------------------------------------------------------------------------
// 4. read(filename,string)
// -----------------------------------------------------------------------------

bool read(
   const std::string &filename,
   const std::string &form
) {
   try {
      if (eq_null(form)) return read(filename,file::null);
      if (eq_tree(form)) return read(filename,file::tree);
      if (eq_xml (form)) return read(filename,file::xml );
      if (eq_json(form)) return read(filename,file::json);
      if (eq_hdf5(form)) return read(filename,file::hdf5);

      // unrecognized file format
      log::warning(
         "Unrecognized file format in call to Tree.read(\"{}\",\"{}\").\n"
         "We'll guess from the file contents",
         filename, form
      );

      // fallback: automagick
      return read(filename,file::null);
   } catch (...) {
      log::member("Tree.read(\"{}\",\"{}\")", filename, form);
      throw;
   }
}
