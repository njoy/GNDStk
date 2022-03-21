
// -----------------------------------------------------------------------------
// Node.write()
// -----------------------------------------------------------------------------

// Cases for our FileType::debug format:
//    write(ostream,   int level)
//    write(file name, int level)
// The "level" parameter keeps track of the indentation level.
// These print exactly what's in the Node, even, say, if the Node's name
// is the empty string.
//
// General cases:
// 1. write(ostream,   FileType)
// 2. write(file name, FileType) calls 1 after making ostream from file
// 3. write(ostream,   string  ) calls 1 after making FileType from string
// 4. write(file name, string  ) calls 2 after making FileType from string



// -----------------------------------------------------------------------------
// Helper
// write(ostream, int level)
// For FileType::debug
// -----------------------------------------------------------------------------

private:

std::ostream &write(std::ostream &os, const int level) const
{
   // indentation: spaces for current and next levels
   const std::string icurr(indent* level   ,' ');
   const std::string inext(indent*(level+1),' ');

   // name
   if (!(os << icurr << name << ":"))
      log::error("ostream << Node.name returned with !ostream");

   // address and parent-node information (optionally)
   if (os && parents)
      if (!(os << " (address " << this << ", parent " << &parent() << ")"))
         log::error("ostream << (Node address/parent information) "
                    "returned with !ostream");

   // metadata
   if (os)
      for (const auto &meta : metadata)
         if (!(os << "\n" << inext << meta.first << ": " << meta.second)) {
            log::error("ostream << Node.metadata returned with !ostream");
            break;
         }

   // children
   if (os)
      for (const auto &childptr : children)
         if (childptr && !(os << "\n" && childptr->write(os,level+1))) {
            log::error("ostream << Node.children returned with !ostream");
            break;
         }

   // error context, if applicable
   if (!os)
      log::member("Node.write(ostream)");

   // done
   return os << std::flush;
}



// -----------------------------------------------------------------------------
// 1. write(ostream, FileType)
// -----------------------------------------------------------------------------

public:

std::ostream &write(
   std::ostream &os = std::cout,
   const FileType format = FileType::guess,
   const bool &DECL = detail::default_bool,
   // If circumstances are such that we end up writing an HDF5, the following
   // may be != "" if the ostream is from an ofstream. In that case, the HDF5
   // writer can produce output directly into the intended file, bypassing the
   // need to create a temporary file and transfer its contents to the ostream.
   const std::string &filename = ""
) const {

   // Discussion.
   //
   // This function might have been called through the file name write().
   // Or, it might have been called through the string (in place of FileType)
   // format write, through ostream << Node, or perhaps just called directly.
   //
   // In the former case, a file name was involved, and thus the caller had
   // the opportunity to examine the file name and, if appropriate, try to
   // make a decision (based on any file name extension) of what output format
   // was intended. The decision would have arrived here via FileType format.
   //
   // In the latter cases, only an ostream was/is involved; there's neither
   // a file name whose extension can be examined, nor an existing file (that
   // we care about, at least - we're doing *output*) whose file magic number
   // we can examine in order to guess at the file type. We therefore have
   // our else { } catchall, below, write the Node in our debugging format,
   // whether FileType::guess or FileType::debug arrived as the format.
   //
   // A case could be made that this function should *require* that a format
   // be given, considering that we don't, here, have a file or a file name
   // to examine. On the other hand, we like having format be optional, so
   // our various Node I/O functions are as consistent with one another as
   // reasonably possible. Note also that if the user calls operator<<, then
   // there's no opportunity to explicitly provide a format.

   try {
      const bool decl = detail::getDecl(*this,DECL);

      if (format == FileType::xml) {
         // write via a temporary xml object...
         XML(*this).write(os,decl);
      } else if (format == FileType::json) {
         // write via a temporary json object...
         JSON(*this).write(os,decl);
      } else if (format == FileType::hdf5) {
         // write via a temporary hdf5 object...
         if (filename == "")
            HDF5(*this).write(os,decl);
         else {
            HDF5 tmp;
            convert(*this,tmp,filename);
         }
      } else {
         // guess or debug: use our debugging format
         return write(os,0);
      }

      if (!os) {
         log::error("Could not write to output stream");
         throw std::exception{};
      }
   } catch (...) {
      log::member("Node.write(ostream)");
      throw;
   }

   // done
   return os;
}



// -----------------------------------------------------------------------------
// 2. write(file name, FileType)
// -----------------------------------------------------------------------------

bool write(
   const std::string &filename,
   const FileType FORMAT = FileType::guess,
   const bool &DECL = detail::default_bool
) const {
   FileType format = FORMAT; // non-const; may change

   // ------------------------
   // FileType::guess
   // Decide from file name
   // ------------------------

   if (format == FileType::guess) {
      if (has_extension(filename) && endsin_xml(filename))
         format = FileType::xml;
      else if (has_extension(filename) && endsin_json(filename))
         format = FileType::json;
      else if (has_extension(filename) && endsin_hdf5(filename))
         format = FileType::hdf5;
      else {
         // fallback: our debugging format
         format = FileType::debug;
      }
   }

   // ------------------------
   // FileType::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   // Remark. The above code block might have changed the [format] variable,
   // but not in a manner that would trigger any of the following warnings
   // where they wouldn't have otherwise existed. So, print them if warranted.

   // Caller asked for XML, but there's an extension that isn't XML...
   if (format == FileType::xml && has_extension(filename)
       && !endsin_xml(filename)) {
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
      const bool decl = detail::getDecl(*this,DECL);
      if (!write(ofs, format, decl, filename))
         throw std::exception{};
      return bool(ofs);
   } catch (...) {
      log::member("Node.write(\"{}\")", filename);
      throw;
   }
}



// -----------------------------------------------------------------------------
// 3. write(ostream, string)
// -----------------------------------------------------------------------------

std::ostream &write(
   std::ostream &os,
   const std::string &format,
   const bool &DECL = detail::default_bool
) const {
   try {
      const bool decl = detail::getDecl(*this,DECL);

      if (eq_guess(format)) return write(os, FileType::guess, decl);
      if (eq_debug(format)) return write(os, FileType::debug, decl);
      if (eq_xml  (format)) return write(os, FileType::xml,   decl);
      if (eq_json (format)) return write(os, FileType::json,  decl);
      if (eq_hdf5 (format)) return write(os, FileType::hdf5,  decl);

      // unrecognized file format
      log::warning(
         "Unrecognized file format in call to Node.write(ostream,\"{}\").\n"
         "We'll use our debugging format",
         format
      );

      // fallback: guess, from file extension
      return write(os, FileType::guess, decl);
   } catch (...) {
      log::member("Node.write(ostream,\"{}\")", format);
      throw;
   }
}



// -----------------------------------------------------------------------------
// 4. write(file name, string)
// -----------------------------------------------------------------------------

bool write(
   const std::string &filename,
   const std::string &format,
   const bool &DECL = detail::default_bool
) const {
   try {
      const bool decl = detail::getDecl(*this,DECL);

      if (eq_guess(format)) return write(filename, FileType::guess, decl);
      if (eq_debug(format)) return write(filename, FileType::debug, decl);
      if (eq_xml  (format)) return write(filename, FileType::xml,   decl);
      if (eq_json (format)) return write(filename, FileType::json,  decl);
      if (eq_hdf5 (format)) return write(filename, FileType::hdf5,  decl);

      // unrecognized file format
      log::warning(
         "Unrecognized file format in call to Node.write(\"{}\",\"{}\").\n"
         "We'll guess from the file extension, or use our debugging\n"
         "format if that fails",
         filename, format
      );

      // fallback: guess, from file extension
      return write(filename, FileType::guess, decl);
   } catch (...) {
      log::member("Node.write(\"{}\",\"{}\")", filename, format);
      throw;
   }
}
