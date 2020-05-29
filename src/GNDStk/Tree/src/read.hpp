
// -----------------------------------------------------------------------------
// Tree::read()
// -----------------------------------------------------------------------------

// ------------------------
// read(filename,format)
// ------------------------

bool read(
   const std::string &filename,
   const format form = format::null
) {
   // ------------------------
   // Clear current contents
   // ------------------------

   // Note that this happens even if something below fails. This is reasonable
   // behavior; an empty tree is a reminder that the read attempt failed.
   clear();

   // ------------------------
   // format::tree
   // Not allowed in read
   // ------------------------

   // Error; this format isn't allowed for read() (only for write())
   if (form == format::tree) {
      log::error(detail::format_tree_read);
      log::context("Tree::read(\"{}\",format)", filename);
      throw std::exception{};
   }

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   if (form == format::xml  and has_extension(filename)
       and not endsin_xml (filename)) {
      detail::warning_tree_io_name("read", "xml",  filename, "XML" );
   }
   if (form == format::json and has_extension(filename)
       and not endsin_json(filename)) {
      detail::warning_tree_io_name("read", "json", filename, "JSON");
   }
   if (form == format::hdf5 and has_extension(filename)
       and not endsin_hdf5(filename)) {
      detail::warning_tree_io_name("read", "hdf5", filename, "HDF5");
   }

   // ------------------------
   // Open and read
   // ------------------------

   try {
      std::ifstream ifs(filename.c_str());
      if (not ifs) {
         log::error("Could not open input file \"{}\"", filename);
         throw std::exception{};
      }

      // Call read(istream) to do the remaining work. Note that although the
      // filename isn't available any longer there, the function can, and does,
      // do additional checking (complimentary to what we already did above),
      // based on looking at the content that we'll be attempting to read.
      return not read(ifs,form).fail();
   } catch (const std::exception &) {
      log::context("Tree::read(\"{}\")", filename);
      throw;
   }
}



// ------------------------
// read(istream,format)
// ------------------------

std::istream &read(
   std::istream &is,
   format form = format::null
) {
   // clear
   // Remark as in read(string). Note that we need the clear() here, too,
   // because this function might be called directly, not via read(string).
   clear();

   // ------------------------
   // format::tree
   // Not allowed in read
   // ------------------------

   if (form == format::tree) {
      log::error(detail::format_tree_read);
      log::context("Tree::read(istream,format)");
      throw std::exception{};
   }

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent
   // initial content?
   // ------------------------

   if (is.peek() == '<') {
      // looks like xml
      if (form == format::null)
         form = format::xml;
      else if (form != format::xml)
         detail::warning_tree_io_data(form, "'<'", "XML");
   } else if (is.peek() == 137) {
      // looks like hdf5
      if (form == format::null)
         form = format::hdf5;
      else if (form != format::hdf5)
         detail::warning_tree_io_data(form, "char 137", "HDF5");
   } else {
      // looks like json (for now, via process of elimination)
      if (form == format::null)
         form = format::json;
      else if (form != format::json)
         detail::warning_tree_io_data(form, "neither '<' nor char 137", "JSON");
   }

   // The above logic is such that form cannot henceforth be format::tree,
   // which would have triggered a return, or format::null, which would have
   // become one of {xml,json,hdf5} somewhere in the above conditional.

   // ------------------------
   // Read and convert
   // ------------------------

   try {
      // Obey form, independent of whatever might or might not have been
      // warned about above. Note that if the original form parameter was
      // format::null, then form would have been modified, above, to the
      // likely correct format, based on the peek() calls.
      if (form == format::xml) {
         // assume .xml
         // go through a temporary XML object to create the tree...
         const XML tmp(is);
         if (not is.fail())
            convert(tmp, *this);
      } else if (form == format::json) {
         // assume .json
         // go through a temporary json object to create the tree...
         const JSON tmp(is);

         // It would seem that the nlohmann::json stream input operation,
         // which is used by the constructor we just called, sets failbit
         // in instances in which it should just set eofbit. So, for now,
         // we'll remove the "not is.fail()" test... :-/
         // if (not is.fail())
         convert(tmp, *this);
      } else if (form == format::hdf5) {
         log::error("Tree::read() for HDF5 is not implemented yet");
         throw std::exception{};
      } else {
         // The earlier logic is such that this shouldn't happen; consider
         // removing at some point
         log::error(
            "Internal error: unrecognized format. "
            "Please report this to us"
         );
         throw std::exception{};
      }
   } catch (const std::exception &) {
      log::context("Tree::read(istream)");
      throw;
   }

   // done
   return is;
}



// ------------------------
// read(filename,string)
// ------------------------

bool read(
   const std::string &filename,
   const std::string &form
) {
   try {
      if (eq_null(form)) return read(filename,format::null);
      if (eq_tree(form)) return read(filename,format::tree);
      if (eq_xml (form)) return read(filename,format::xml );
      if (eq_json(form)) return read(filename,format::json);
      if (eq_hdf5(form)) return read(filename,format::hdf5);

      // unrecognized format
      log::warning(
         "Unrecognized format in call to Tree::read(\"{}\",\"{}\").\n"
         "We'll guess from the file contents",
         filename, form
      );

      // fallback: automagick
      return read(filename,format::null);
   } catch (const std::exception &) {
      log::context("Tree::read(\"{}\",\"{}\")", filename, form);
      throw;
   }
}



// ------------------------
// read(istream,string)
// ------------------------

std::istream &read(
   std::istream &is,
   const std::string &form
) {
   try {
      if (eq_null(form)) return read(is,format::null);
      if (eq_tree(form)) return read(is,format::tree);
      if (eq_xml (form)) return read(is,format::xml );
      if (eq_json(form)) return read(is,format::json);
      if (eq_hdf5(form)) return read(is,format::hdf5);

      // unrecognized format
      log::warning(
         "Unrecognized format in call to Tree::read(istream,\"{}\").\n"
         "We'll guess from the stream contents",
         form
      );

      // fallback: automagick
      return read(is,format::null);
   } catch (const std::exception &) {
      log::context("Tree::read(istream,\"{}\")", form);
      throw;
   }
}
