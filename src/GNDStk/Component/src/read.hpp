
// -----------------------------------------------------------------------------
// Component::read()
// Via Node, and using Node's available read() functions.
// So, autogenerated classes can directly use .read(...).
// -----------------------------------------------------------------------------

// read(istream, FileType)
std::istream &read(
   std::istream &is,
   const FileType format = FileType::guess,
   const bool decl = false
) {
   Node node;
   std::istream &ret = node.read(is, format, decl);
   derived() = DERIVED(node);
   return ret;
}

// read(file name, FileType)
bool read(
   const std::string &filename,
   const FileType format = FileType::guess,
   const bool decl = false
) {
   Node node;
   bool ret = node.read(filename, format, decl);
   derived() = DERIVED(node);
   return ret;
}

// read(istream, string)
std::istream &read(
   std::istream &is,
   const std::string &format,
   const bool decl = false
) {
   Node node;
   std::istream &ret = node.read(is, format, decl);
   derived() = DERIVED(node);
   return ret;
}

// read(file name, string)
bool read(
   const std::string &filename,
   const std::string &format,
   const bool decl = false
) {
   Node node;
   bool ret = node.read(filename, format, decl);
   derived() = DERIVED(node);
   return ret;
}
