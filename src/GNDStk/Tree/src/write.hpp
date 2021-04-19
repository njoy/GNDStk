
// -----------------------------------------------------------------------------
// Tree.write()
// -----------------------------------------------------------------------------

// Cases:
// 1. write(ostream,   file format)
// 2. write(file name, file format) calls 1 after making ostream from file name
// 3. write(ostream,   string     ) calls 1 after making file format from string
// 4. write(file name, string     ) calls 2 after making file format from string



// -----------------------------------------------------------------------------
// 1. write(ostream, file format)
// -----------------------------------------------------------------------------

std::ostream &write(
   std::ostream &os,
   const FileType format = FileType::null
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
   // we can examine in order to guess at the file type. We therefore have our
   // else { } catchall, below, write the Tree in our basic Tree-output form,
   // whether FileType::null or FileType::text arrived as the format. A case
   // could be made that write(ostream,format) should require that a format
   // be given, considering that we don't, here, have a file or filename to
   // examine. On the other hand, we like having format be optional, to make
   // our various Tree I/O functions be as consistent with one another as
   // possible. Note, also, that if the user calls operator<<, then there's
   // no opportunity to explicitly provide a format.

   try {
      if (format == FileType::xml) {
         // write via a temporary xml object...
         XML(*this).write(os);
      } else if (format == FileType::json) {
         // write via a temporary json object...
         JSON(*this).write(os);
      } else if (format == FileType::hdf5) {
         // write via a temporary hdf5 object...
         log::error("Tree.write() for HDF5 is not implemented yet");
         throw std::exception{};
      } else {
         // default: our internal Tree file format
         if (!this->empty()) {
            if (GNDStk::decl)
               decl().write(os,0);
            top().write(os,0); // 0 is level
         }
      }

      if (!os) {
         log::error("Could not write to output stream");
         throw std::exception{};
      }
   } catch (...) {
      log::member("Tree.write(ostream)");
      throw;
   }

   // done
   return os;
}



// -----------------------------------------------------------------------------
// 2. write(filename, file format)
// -----------------------------------------------------------------------------

bool write(
   const std::string &filename,
   FileType format = FileType::null
) const {

   // ------------------------
   // FileType::null
   // Decide from file name
   // ------------------------

   if (format == FileType::null) {
      if (endsin_xml (filename))
         format = FileType::xml;
      else if (endsin_json(filename))
         format = FileType::json;
      else if (endsin_hdf5(filename))
         format = FileType::hdf5;
      else
         format = FileType::text;
   }

   // ------------------------
   // FileType::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   // Note that the above code block may have changed "format",
   // via automagick file type detection. So...

   if (format == FileType::xml && has_extension(filename)
       && !endsin_xml (filename)) {
      detail::warning_io_name("write", "xml",  filename, "XML" );
   }
   if (format == FileType::json && has_extension(filename)
       && !endsin_json(filename)) {
      detail::warning_io_name("write", "json", filename, "JSON");
   }
   if (format == FileType::hdf5 && has_extension(filename)
       && !endsin_hdf5(filename)) {
      detail::warning_io_name("write", "hdf5", filename, "HDF5");
   }

   // ------------------------
   // Open and write
   // ------------------------

   try {
      std::ofstream ofs(filename);
      if (!ofs) {
         log::error("Could not open output file \"{}\"", filename);
         throw std::exception{};
      }

      // Call write(ostream) to do the remaining work.
      if (!write(ofs,format))
         throw std::exception{};
      return bool(ofs);
   } catch (...) {
      log::member("Tree.write(\"{}\")", filename);
      throw;
   }
}


// -----------------------------------------------------------------------------
// 3. write(ostream,string)
// -----------------------------------------------------------------------------

std::ostream &write(
   std::ostream &os,
   const std::string &format
) const {
   try {
      if (eq_null(format)) return write(os,FileType::null);
      if (eq_text(format)) return write(os,FileType::text);
      if (eq_xml (format)) return write(os,FileType::xml );
      if (eq_json(format)) return write(os,FileType::json);
      if (eq_hdf5(format)) return write(os,FileType::hdf5);

      // unrecognized file format
      log::warning(
         "Unrecognized file format in call to Tree.write(ostream,\"{}\").\n"
         "We'll use our internal debug-write file format",
         format
      );

      // fallback: automagick
      return write(os,FileType::null);
   } catch (...) {
      log::member("Tree.write(ostream,\"{}\")", format);
      throw;
   }
}



// -----------------------------------------------------------------------------
// 4. write(filename,string)
// -----------------------------------------------------------------------------

bool write(
   const std::string &filename,
   const std::string &format
) const {
   try {
      if (eq_null(format)) return write(filename,FileType::null);
      if (eq_text(format)) return write(filename,FileType::text);
      if (eq_xml (format)) return write(filename,FileType::xml );
      if (eq_json(format)) return write(filename,FileType::json);
      if (eq_hdf5(format)) return write(filename,FileType::hdf5);

      // unrecognized file format
      log::warning(
         "Unrecognized file format in call to Tree.write(\"{}\",\"{}\").\n"
         "We'll guess from the file extension, or use our internal debug-\n"
         "write file format if that fails",
         filename, format
      );

      // fallback: automagick
      return write(filename,FileType::null);
   } catch (...) {
      log::member("Tree.write(\"{}\",\"{}\")", filename, format);
      throw;
   }
}
