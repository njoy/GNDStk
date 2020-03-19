
// -----------------------------------------------------------------------------
// Tree::read()
// -----------------------------------------------------------------------------

// ------------------------
// read(file,format)
// ------------------------

bool read(
   const std::string &file,
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
      error(detail::format_tree_read);
      return false;
   }

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   if (form == format::xml  and has_extension(file) and not endsin_xml (file))
      detail::warning_tree_io_name<dummy>("read", file, "xml",  "XML" );
   if (form == format::json and has_extension(file) and not endsin_json(file))
      detail::warning_tree_io_name<dummy>("read", file, "json", "JSON");
   if (form == format::hdf5 and has_extension(file) and not endsin_hdf5(file))
      detail::warning_tree_io_name<dummy>("read", file, "hdf5", "HDF5");

   // ------------------------
   // Open and read
   // ------------------------

   std::ifstream ifs(file.c_str());
   if (not ifs)
      error("Could not open input file \"" + file + "\"");

   // Call read(istream), below, to do the remaining work. Note that although
   // the filename isn't available any longer in that function, the function
   // can, and does, do additional checking (complimentary to what we already
   // did above), based on looking at the content we'll be attempting to read.
   return not read(ifs,form).fail();
}



// ------------------------
// read(file,string)
// ------------------------

bool read(const std::string &file, const std::string &form)
{
   if (eq_null(form)) return read(file,format::null);
   if (eq_tree(form)) return read(file,format::tree);
   if (eq_xml (form)) return read(file,format::xml );
   if (eq_json(form)) return read(file,format::json);
   if (eq_hdf5(form)) return read(file,format::hdf5);

   // fixme Have some sort of warning
   assert(false);

   // fallback: try automagick
   return read(file,format::null);
}



// ------------------------
// read(istream,format)
// ------------------------

std::istream &read(
   std::istream &is,
   format form = format::null
) {
   // clear
   // Comment as in read(string). Note that we need the clear() here, too,
   // because this function might be called directly, not via read(string).
   clear();

   // ------------------------
   // format::tree
   // Not allowed in read
   // ------------------------

   if (form == format::tree) {
      error(detail::format_tree_read);
      return is;
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
         detail::warning_tree_io_data<dummy>(
            form, "'<'", "XML");
   } else if (is.peek() == 137) {
      // looks like hdf5
      if (form == format::null)
         form = format::hdf5;
      else if (form != format::hdf5)
         detail::warning_tree_io_data<dummy>(
            form, "char 137", "HDF5");
   } else {
      // looks like json (via process of elimination)
      if (form == format::null)
         form = format::json;
      else if (form != format::json)
         detail::warning_tree_io_data<dummy>(
            form, "neither '<' nor char 137", "JSON");
   }

   // The above logic is such that form cannot henceforth be format::tree,
   // which would have triggered a return, or format::null, which would have
   // become one of {xml,json,hdf5} somewhere in the above conditional.

   // ------------------------
   // Read and convert
   // ------------------------

   // Obey form, independent of whatever might or might not have been warned
   // about above. Note that if the original form parameter was format::null,
   // then form would have been modified, above, to the likely correct format,
   // based on the peek() calls.
   if (form == format::xml) {
      // assume .xml
      // go through a temporary xml object to create the tree...
      const xml tmp(is);
      if (not is.fail())
         convert(tmp, *this);
   } else if (form == format::json) {
      // assume .json
      // go through a temporary json object to create the tree...
      const json tmp(is);

      // It would seem that the nlohmann::json stream input operation,
      // which is used by the constructor we just called, sets failbit
      // in instances in which it should just set eofbit. So, for now,
      // we'll comment-out the "not is.fail()" test... :-/
      // if (not is.fail())
      convert(tmp, *this);
   } else if (form == format::hdf5) {
      error("HDF5 read() is not implemented yet");
   } else {
      // we may or may not want slippery-slope stuff like this
      internal("Unrecognized form = " + std::to_string(int(form)) + " "
               "in tree.read()");
   }

   // done
   return is;
}



// ------------------------
// read(istream,string)
// ------------------------

std::istream &read(std::istream &is, const std::string &form)
{
   if (eq_null(form)) return read(is,format::null);
   if (eq_tree(form)) return read(is,format::tree);
   if (eq_xml (form)) return read(is,format::xml );
   if (eq_json(form)) return read(is,format::json);
   if (eq_hdf5(form)) return read(is,format::hdf5);

   // fixme Have some sort of warning
   assert(false);

   // fallback: try automagick
   return read(is,format::null);
}
