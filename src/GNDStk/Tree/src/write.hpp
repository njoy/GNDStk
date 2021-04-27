
// -----------------------------------------------------------------------------
// Tree.write()
// Forward to Node.write(), with decl == true.
// -----------------------------------------------------------------------------

// 1. write(ostream, FileType)
std::ostream &write(
   std::ostream &os = std::cout,
   const FileType format = FileType::null,
   const bool decl = true
) const {
   try {
      return this->Node::write(os, format, decl);
   } catch (...) {
      log::member("Tree.write(ostream)");
      throw;
   }
}

// 2. write(file name, FileType)
bool write(
   const std::string &filename,
   const FileType format = FileType::null,
   const bool decl = true
) const {
   try {
      return this->Node::write(filename, format, decl);
   } catch (...) {
      log::member("Tree.write(\"{}\")", filename);
      throw;
   }
}

// 3. write(ostream, string)
std::ostream &write(
   std::ostream &os,
   const std::string &format,
   const bool decl = true
) const {
   try {
      return this->Node::write(os, format, decl);
   } catch (...) {
      log::member("Tree.write(ostream,\"{}\")", format);
      throw;
   }
}

// 4. write(file name, string)
bool write(
   const std::string &filename,
   const std::string &format,
   const bool decl = true
) const {
   try {
      return this->Node::write(filename, format, decl);
   } catch (...) {
      log::member("Tree.write(\"{}\",\"{}\")", filename, format);
      throw;
   }
}
