
// -----------------------------------------------------------------------------
// Helpers for various tree-related code.
// -----------------------------------------------------------------------------

namespace detail {

// A couple of these are templated because we'd prefer not to say inline,
// and this is a header-only library. (Not that "inline" really means it.)

// warning_tree_io_name
template<class unused>
void warning_tree_io_name(
   const std::string &op,
   const std::string &file,
   const std::string &format,
   const std::string &name
) {
   warning(
      "Tree " + op + " called with "
      "format::" + format + " and "
      "filename \"" + file + "\",\n"
      "but the filename extension does not appear to be one for " +
       name + "."
   );
}

// warning_tree_io_data
template<class unused>
void warning_tree_io_data(
   const format f,
   const std::string &ch,
   const std::string &name
) {
   const std::string form =
      f == format::xml  ? "xml"
    : f == format::json ? "json"
    : f == format::hdf5 ? "hdf5"
    : "?";

   warning(
      "Tree read called with "
      "format::" + form + ",\n"
      "but the file begins with " + ch + ", which suggests " +
       name + "."
   );
}

// format_tree_read
inline const std::string format_tree_read =
   "Format format::tree is not allowed in tree.read(). "
   "Our \"tree\" format\nis intended only for debug writing; "
   "it is not a first-class file format."
;

} // namespace detail
