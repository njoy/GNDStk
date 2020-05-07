
// -----------------------------------------------------------------------------
// Tree::write()
// -----------------------------------------------------------------------------

/*
Cases:
   bool     write( string  &filename, format = null ) const
   ostream &write( ostream &os,       format = null ) const
   bool     write( string  &filename, string &form  ) const
   ostream &write( ostream &os,       string &form  ) const
*/



// ------------------------
// write(filename,format)
// ------------------------

bool write(
   const std::string &filename,
   format form = format::null
) const {

   // ------------------------
   // format::null
   // Decide from file name
   // ------------------------

   if (form == format::null) {
      if (endsin_xml (filename))
         form = format::xml;
      else if (endsin_json(filename))
         form = format::json;
      else if (endsin_hdf5(filename))
         form = format::hdf5;
      else
         form = format::tree;
   }

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   // Note that the above code block may have changed "form",
   // via automagick file type detection. So...

   if (form == format::xml  and has_extension(filename)
       and not endsin_xml (filename)) {
      detail::warning_tree_io_name("write", "xml",  filename, "XML" );
   }
   if (form == format::json and has_extension(filename)
       and not endsin_json(filename)) {
      detail::warning_tree_io_name("write", "json", filename, "JSON");
   }
   if (form == format::hdf5 and has_extension(filename)
       and not endsin_hdf5(filename)) {
      detail::warning_tree_io_name("write", "hdf5", filename, "HDF5");
   }

   // ------------------------
   // Open and write
   // ------------------------

   try {
      std::ofstream ofs(filename.c_str());
      if (not ofs) {
         log::error("Could not open output file \"{}\"", filename);
         throw std::exception{};
      }

      // Call write(ostream) to do the remaining work.
      return not write(ofs,form).fail();
   } catch (const std::exception &) {
      log::context("Tree::write(\"{}\")", filename);
      throw;
   }
}



// ------------------------
// write(ostream,format)
// ------------------------

std::ostream &write(
   std::ostream &os,
   const format form = format::null
) const {

   // Discussion.
   //
   // This function might have been called through the filename write(); OR,
   // might have been called directly by a user, or possibly called through
   // the << stream output operator.
   //
   // In the former case, a filename was given, and thus the earlier function
   // had the opportunity to examine the filename and, if applicable, make a
   // smart decision - based on the filename extension - of what output format
   // the user would like. That decision would have been forwarded to here.
   //
   // In the latter cases, only an ostream is involved, and there's neither
   // a filename whose extension can be examined, nor an existing file (that
   // we care about, at least - we're doing *output*) whose first character
   // we can peek() in order to guess at the file type. We therefore have our
   // else { } catch-all, below, write the tree in our basic tree-output form,
   // whether format::null or format::tree arrived as the format. An argument
   // could be made that write(ostream,format) should require that a format
   // be given, considering that we don't, here, have a file or filename to
   // examine. On the other hand, we like having format be optional, to make
   // our various tree I/O functions be as consistent with one another as
   // possible. Note, also, that if the user calls operator<<, then there's
   // no opportunity to explicitly provide a format.

   try {
      if (form == format::xml) {
         // write via a temporary xml object...
         GNDStk::XML(*this).write(os);
      } else if (form == format::json) {
         // write via a temporary json object...
         GNDStk::JSON(*this).write(os);
      } else if (form == format::hdf5) {
         // write via a temporary hdf5 object...
         log::error("Tree::write() for HDF5 is not implemented yet");
         throw std::exception{};
      } else {
         // default: our internal tree format
         if (not empty())
            top().write(os,0); // 0 is level
      }

      if (not os) {
         log::error("Could not write to output stream");
         throw std::exception{};
      }
   } catch (const std::exception &) {
      log::context("Tree::write(ostream)");
      throw;
   }

   // done
   return os;
}



// ------------------------
// write(filename,string)
// ------------------------

bool write(
   const std::string &filename,
   const std::string &form
) const {
   try {
      if (eq_null(form)) return write(filename,format::null);
      if (eq_tree(form)) return write(filename,format::tree);
      if (eq_xml (form)) return write(filename,format::xml );
      if (eq_json(form)) return write(filename,format::json);
      if (eq_hdf5(form)) return write(filename,format::hdf5);

      // unrecognized format
      log::warning(
         "Unrecognized format in call to Tree::write(\"{}\",\"{}\").\n"
         "We'll guess from the file extension, or use our internal debug\n"
         "write format if that fails",
         filename, form
      );

      // fallback: automagick
      return write(filename,format::null);
   } catch (const std::exception &) {
      log::context("Tree::write(\"{}\",\"{}\")", filename, form);
      throw;
   }
}



// ------------------------
// write(ostream,string)
// ------------------------

std::ostream &write(
   std::ostream &os,
   const std::string &form
) const {
   try {
      if (eq_null(form)) return write(os,format::null);
      if (eq_tree(form)) return write(os,format::tree);
      if (eq_xml (form)) return write(os,format::xml );
      if (eq_json(form)) return write(os,format::json);
      if (eq_hdf5(form)) return write(os,format::hdf5);

      // unrecognized format
      log::warning(
         "Unrecognized format in call to Tree::write(ostream,\"{}\").\n"
         "We'll use our internal debug write format",
         form
      );

      // fallback: automagick
      return write(os,format::null);
   } catch (const std::exception &) {
      log::context("Tree::write(ostream,\"{}\")", form);
      throw;
   }
}
