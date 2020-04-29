
// -----------------------------------------------------------------------------
// Helpers for various tree-related code.
// -----------------------------------------------------------------------------

namespace detail {

// warning_tree_io_name
inline void warning_tree_io_name(
   const std::string &op,
   const std::string &format,
   const std::string &filename,
   const std::string &name
) {
   log::warning(
      "tree.{}() called with format::{} and filename \"{}\",\n"
      "but the filename extension does not appear to be one for {}",
      op, format, filename, name
   );
}


// warning_tree_io_data
inline void warning_tree_io_data(
   const format f,
   const std::string &ch,
   const std::string &name
) {
   const std::string form =
      f == format::xml  ? "xml"
    : f == format::json ? "json"
    : f == format::hdf5 ? "hdf5"
    : "?";

   log::warning(
      "tree.read() called with format::{},\n"
      "but the file begins with {}, which suggests {}",
      form, ch, name
   );
}


// format_tree_read
inline const std::string format_tree_read =
   "format::tree not allowed in tree.read(). Our \"tree\" format is intended"
   "only for debug writing, not for reading. Consider xml, json, or hdf5"
;

} // namespace detail
