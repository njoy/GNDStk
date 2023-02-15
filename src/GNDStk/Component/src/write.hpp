
// -----------------------------------------------------------------------------
// Component::write()
// Via Node, and using Node's write()s.
// So, Component-derived classes can use .write(...) directly.
// -----------------------------------------------------------------------------

// ------------------------
// stream, with enum- or
// string-based file type
// ------------------------

// write(ostream, FileType)
std::ostream &write(
   std::ostream &os = std::cout,
   const FileType format = FileType::guess,
   const bool decl = false
) const {
   return Node(*this).write(os, format, decl);
}

// write(ostream, string)
std::ostream &write(
   std::ostream &os,
   const std::string &format,
   const bool decl = false
) const {
   return Node(*this).write(os, format, decl);
}

// ------------------------
// filename, with enum- or
// string-based file type
// ------------------------

// write(filename, FileType)
bool write(
   const std::string &filename,
   const FileType format = FileType::guess,
   const bool decl = false
) const {
   return Node(*this).write(filename, format, decl);
}

// write(filename, string)
bool write(
   const std::string &filename,
   const std::string &format,
   const bool decl = false
) const {
   return Node(*this).write(filename, format, decl);
}
