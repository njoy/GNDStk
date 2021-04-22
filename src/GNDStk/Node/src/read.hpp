
// -----------------------------------------------------------------------------
// Node.read()
// -----------------------------------------------------------------------------

// Cases:
//
// 1. read(istream,   FileType)
// 2. read(file name, FileType) calls 1 after making istream from file name
// 3. read(istream,   string  ) calls 1 after making FileType from string
// 4. read(file name, string  ) calls 2 after making FileType from string
//
// Discussion
//
// Each of these also takes a final bool parameter, decl, to indicate whether
// or not any declaration node (say, <?xml version="1.0" encoding="UTF-8"?>)
// should be read.
//
// GNDStk distinguishes between Node (which means a typical node somewhere in
// an entire GNDS tree), and Tree, which specifically means an entire GNDS tree.
// Tree derives from Node, and, for most functionality, Tree defers to Node.
// For Tree I/O, however, GNDStk tries to preserve any declaration node that
// might be present. It does not, by default, do this for Node.
//
// To support all this, Node's read functionality, below, provides the optional
// bool decl parameter, indicating whether or not to handle any declaration node
// that might be seen. It's false, by default. These Node read() functions are
// called by the Tree read() functions, however, and those call these with decl
// set to true, precisely so that they preserve declaration nodes.
//
// If decl == false, we'll find any NON-declaration node in the input, and
// place it directly into the *this node. Any declaration node that's present,
// in the input, will be ignored. This behavior reflects what we want for
// "regular" Node objects.
//
// If decl == true, we'll make *this be a Node with an empty name, "". Then,
// we'll place any input non-declaration node into one of its children. And,
// finally, we'll preserve any *declaration* node as another child. This
// behavior reflects what we actually want for Tree objects (and, remember,
// Tree derives from Node).



// -----------------------------------------------------------------------------
// 1. read(istream, FileType)
// -----------------------------------------------------------------------------

std::istream &read(
   std::istream &is,
   FileType format = FileType::null,
   const bool decl = false
) {
   // ------------------------
   // Clear current contents
   // ------------------------

   // Note that this happens even if something below fails. This makes
   // sense, given that the intention was to replace prior contents.
   clear();

   // ------------------------
   // FileType::text
   // Not allowed in read
   // ------------------------

   if (format == FileType::text) {
      log::error(detail::error_format_read);
      log::member("Node.read(istream)");
      throw std::exception{};
   }

   // ------------------------
   // FileType::xml,json,hdf5
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
   std::string used;
   static const std::string request = ", because it was requested";

   // Retrieve the stream's first character ("file magic number")
   int magicNumber;
   do {
      magicNumber = is.get();
   } while (isspace(magicNumber));
   is.unget();

   // Perform some checks
   if (magicNumber == EOF) {
      log::info("No content in the istream");
      log::info("Node will be empty");
      log::member("Node.read(istream)");
      return is;
   } else if (magicNumber == '<') {
      // looks like XML
      if (format == FileType::null) {
         format = FileType::xml;
         used = "Assumed XML, based on the first character of the istream";
      } else if (format != FileType::xml) {
         detail::warning_io_data(format, "XML");
         used = "Used " + detail::print_format(format) + request;
      }
   } else if (magicNumber == 137) {
      // looks like HDF5
      if (format == FileType::null) {
         format = FileType::hdf5;
         used = "Assumed HDF5, based on the first character of the istream";
      } else if (format != FileType::hdf5) {
         detail::warning_io_data(format, "HDF5");
         used = "Used " + detail::print_format(format) + request;
      }
   } else {
      // looks like JSON (via process of elimination)
      if (format == FileType::null) {
         format = FileType::json;
         used = "Assumed JSON, based on the first character of the istream";
      } else if (format != FileType::json) {
         detail::warning_io_data(format, "JSON");
         used = "Used " + detail::print_format(format) + request;
      }
   }

   // The above logic is such that format cannot henceforth be FileType::text,
   // which would have triggered a return, or FileType::null, which would have
   // become one of {xml,json,hdf5}, somewhere in the above conditional, if we
   // didn't return already.

   // ------------------------
   // Read and convert
   // ------------------------

   try {
      // Obey format, independent of whatever might or might not have been
      // warned about above. Note that if the original format parameter was
      // FileType::null, then format would have been modified, above, to the
      // likely correct one, based on the file magic number.
      if (format == FileType::xml) {
         // assume XML; so, create Node by converting from a temporary XML...
         if (!convert(XML(is), *this, decl))
            throw std::exception{};
      } else if (format == FileType::json) {
         // assume JSON; so, create Node by converting from a temporary JSON...
         if (!convert(JSON(is), *this, decl))
            throw std::exception{};
      } else if (format == FileType::hdf5) {
         log::error("Node.read() for HDF5 is not implemented yet");
         throw std::exception{};
      } else {
         // The earlier logic is such that this shouldn't happen; consider
         // removing at some point
         log::error(
            "Internal error: unrecognized file format. "
            "Please report this to us");
         throw std::exception{};
      }
   } catch (...) {
      if (used != "")
         log::info(used);
      log::member("Node.read(istream)");
      throw;
   }

   // done
   return is;
}



// -----------------------------------------------------------------------------
// 2. read(file name, FileType)
// -----------------------------------------------------------------------------

bool read(
   const std::string &filename,
   const FileType format = FileType::null,
   const bool decl = false
) {
   // Remark as in read(istream) above
   clear();

   // ------------------------
   // FileType::text
   // Not allowed in read()
   // ------------------------

   // This format ("debugging output") is only for write(), not for read()
   if (format == FileType::text) {
      log::error(detail::error_format_read);
      log::member("Node.read(\"{}\",format)", filename);
      throw std::exception{};
   }

   // ------------------------
   // FileType::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   // If we requested XML, but the file name has an extension that's not xml...
   if (format == FileType::xml && has_extension(filename)
       && !endsin_xml(filename)) {
      detail::warning_io_name("read", "xml",  filename, "XML" );
   }
   if (format == FileType::json && has_extension(filename)
       && !endsin_json(filename)) {
      detail::warning_io_name("read", "json", filename, "JSON");
   }
   if (format == FileType::hdf5 && has_extension(filename)
       && !endsin_hdf5(filename)) {
      detail::warning_io_name("read", "hdf5", filename, "HDF5");
   }

   // ------------------------
   // Open and read
   // ------------------------

   try {
      std::ifstream ifs(filename);
      if (!ifs) {
         log::error("Could not open input file \"{}\"", filename);
         throw std::exception{};
      }

      // Call read(istream) to do the remaining work. Note that although the
      // file name is no longer available there, that function can, and does,
      // do additional checking (complimentary to what we already did above),
      // based on examining the content that we'll be attempting to read.
      if (!read(ifs, format, decl))
         throw std::exception{};
      return bool(ifs);
   } catch (...) {
      log::member("Node.read(\"{}\")", filename);
      throw;
   }
}



// -----------------------------------------------------------------------------
// 3. read(istream, string)
// -----------------------------------------------------------------------------

std::istream &read(
   std::istream &is,
   const std::string &format,
   const bool decl = false
) {
   try {
      if (eq_null(format)) return read(is, FileType::null, decl);
      if (eq_text(format)) return read(is, FileType::text, decl);
      if (eq_xml (format)) return read(is, FileType::xml,  decl);
      if (eq_json(format)) return read(is, FileType::json, decl);
      if (eq_hdf5(format)) return read(is, FileType::hdf5, decl);

      // unrecognized file format
      log::warning(
         "Unrecognized file format in call to Node.read(istream,\"{}\").\n"
         "We'll guess from the stream contents",
         format
      );

      // fallback: automagick
      return read(is, FileType::null, decl);
   } catch (...) {
      log::member("Node.read(istream,\"{}\")", format);
      throw;
   }
}



// -----------------------------------------------------------------------------
// 4. read(file name, string)
// -----------------------------------------------------------------------------

bool read(
   const std::string &filename,
   const std::string &format,
   const bool decl = false
) {
   try {
      if (eq_null(format)) return read(filename, FileType::null, decl);
      if (eq_text(format)) return read(filename, FileType::text, decl);
      if (eq_xml (format)) return read(filename, FileType::xml,  decl);
      if (eq_json(format)) return read(filename, FileType::json, decl);
      if (eq_hdf5(format)) return read(filename, FileType::hdf5, decl);

      // unrecognized file format
      log::warning(
         "Unrecognized file format in call to Node.read(\"{}\",\"{}\").\n"
         "We'll guess from the file contents",
         filename, format
      );

      // fallback: automagick
      return read(filename, FileType::null, decl);
   } catch (...) {
      log::member("Node.read(\"{}\",\"{}\")", filename, format);
      throw;
   }
}
