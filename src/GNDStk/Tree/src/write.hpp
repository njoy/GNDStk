
// -----------------------------------------------------------------------------
// Tree::write()
// -----------------------------------------------------------------------------

/*
Cases:
   bool     write( string  &file, format = null ) const
   ostream &write( ostream &os,   format = null ) const
   bool     write( string  &file, string &form  ) const
   ostream &write( ostream &os,   string &form  ) const
*/



// ------------------------
// write(string,format)
// ------------------------

bool write(
   const std::string &file,
   format form = format::null
) const {

   // ------------------------
   // format::null
   // Decide from file name
   // ------------------------

   if (form == format::null) {
      if (endsin_xml (file))
         form = format::xml;
      else if (endsin_json(file))
         form = format::json;
      else if (endsin_hdf5(file))
         form = format::hdf5;
      else
         form = format::tree;
   }

   // ------------------------
   // format::xml,json,hdf5
   // Check: consistent name?
   // ------------------------

   // Note that the above code block may have changed form,
   // via automagick file type detection. So...

   if (form == format::xml  and has_extension(file) and not endsin_xml (file))
      detail::warning_tree_io_name<dummy>("write", file, "xml",  "XML" );
   if (form == format::json and has_extension(file) and not endsin_json(file))
      detail::warning_tree_io_name<dummy>("write", file, "json", "JSON");
   if (form == format::hdf5 and has_extension(file) and not endsin_hdf5(file))
      detail::warning_tree_io_name<dummy>("write", file, "hdf5", "HDF5");

   // ------------------------
   // Open and write
   // ------------------------

   std::ofstream ofs(file.c_str());
   if (not ofs)
      error("Could not open output file \"" + file + "\"");

   // Call write(ostream), below, to do the remaining work.
   return not write(ofs,form).fail();
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
   // else { } catchall, below, write the tree in our basic tree-output form,
   // whether format::null or format::tree arrived as the format. An argument
   // could be made that write(ostream,format) should require that a format
   // be given, considering that we don't, here, have a file or filename to
   // examine. On the other hand, we like having format be optional, to make
   // our various tree I/O functions be as consistent with one another as
   // possible. Note, also, that if the user calls operator<<, then there's
   // no opportunity to explicitly provide a format.

   if (form == format::xml) {
      // write via a temporary xml object...
      GNDStk::XML(*this).write(os);
   } else if (form == format::json) {
      // write via a temporary json object...
      GNDStk::JSON(*this).write(os);
   } else if (form == format::hdf5) {
      // write via a temporary hdf5 object...
      error("HDF5 write() is not implemented yet");
   } else {
      // default, or our internal tree format
      if (not empty()) {
         int level = 0;
         root->write(os,level);
      }
   }

   if (not os)
      error("Could not write to output stream");
   return os;
}



// ------------------------
// write(string,string)
// ------------------------

bool write(
   const std::string &file,
   const std::string &form
) const {
   if (eq_null(form)) return write(file,format::null);
   if (eq_tree(form)) return write(file,format::tree);
   if (eq_xml (form)) return write(file,format::xml );
   if (eq_json(form)) return write(file,format::json);
   if (eq_hdf5(form)) return write(file,format::hdf5);

   // fixme Have some sort of warning
   assert(false);

   // fallback: try automagick
   return write(file,format::null);
}



// ------------------------
// write(ostream,string)
// ------------------------

std::ostream &write(
   std::ostream &os,
   const std::string &form
) const {
   if (eq_null(form)) return write(os,format::null);
   if (eq_tree(form)) return write(os,format::tree);
   if (eq_xml (form)) return write(os,format::xml );
   if (eq_json(form)) return write(os,format::json);
   if (eq_hdf5(form)) return write(os,format::hdf5);

   // fixme Have some sort of warning
   assert(false);

   // fallback: try automagick
   return write(os,format::null);
}
