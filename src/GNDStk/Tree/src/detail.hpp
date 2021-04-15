
// -----------------------------------------------------------------------------
// Helpers for various tree-related code
// -----------------------------------------------------------------------------

namespace detail {

// warning_tree_io_name
inline void warning_tree_io_name(
   const std::string &op,
   const std::string &fileformat,
   const std::string &filename,
   const std::string &name
) {
   log::warning(
      "tree.{}() called with format FileType::{} and filename \"{}\",\n"
      "but the filename extension does not appear to be one for {}",
      op, fileformat, filename, name
   );
}


// warning_tree_io_data
inline void warning_tree_io_data(
   const FileType f,
   const std::string &appears
) {
   log::warning(
      "tree.read() was called with {}, but the first character\n"
      "in the file suggests perhaps {}. Trying {} anyway...",
      print_format(f), appears, print_format(f,true)
   );
}


// format_tree_read
inline const std::string format_tree_read =
   "FileType::text not allowed in tree.read(). "
   "Our \"tree\" file format is intended"
   "mainly for debug writing, not for reading. "
   "Consider xml, json, or hdf5"
;

} // namespace detail
