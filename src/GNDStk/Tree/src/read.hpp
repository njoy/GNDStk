
// -----------------------------------------------------------------------------
// Tree.read()
// Cases are as for Node.read(), to which these defer with decl == true,
// meaning that, for Tree, we preserve any declaration node.
// -----------------------------------------------------------------------------

// 1. read(istream, FileType)
std::istream &read(
   std::istream &is,
   const FileType format = FileType::null
) {
   try {
      return this->Node::read(is, format, true);
   } catch (...) {
      log::member("Tree.read(istream)");
      throw;
   }
}

// 2. read(file name, FileType)
bool read(
   const std::string &filename,
   const FileType format = FileType::null
) {
   try {
      return this->Node::read(filename, format, true);
   } catch (...) {
      log::member("Tree.read(\"{}\")", filename);
      throw;
   }
}

// 3. read(istream, string)
std::istream &read(
   std::istream &is,
   const std::string &format
) {
   try {
      return this->Node::read(is, format, true);
   } catch (...) {
      log::member("Tree.read(istream,\"{}\")", format);
      throw;
   }
}

// 4. read(file name, string)
bool read(
   const std::string &filename,
   const std::string &format
) {
   try {
      return this->Node::read(filename, format, true);
   } catch (...) {
      log::member("Tree.read(\"{}\",\"{}\")", filename, format);
      throw;
   }
}
