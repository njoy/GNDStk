
// -----------------------------------------------------------------------------
// Read this object, in-place, from a Node
// -----------------------------------------------------------------------------

void read(const Node &node)
{
   // todo Maybe we don't really need/want a separate fromNode() function...?

   // Read fields from the Node into the derived object. This applies the KEYS()
   // multi-query in the derived class, and also runs BlockData::fromNode() - if
   // the Node has block data - in order to get the Node's string of block data.
   fromNode(node);

   if constexpr (hasBlockData) {
      // length, start, valueType
      BLOCKDATA::pullFromDerived(derived());
      // make vector
      BLOCKDATA::get();
   }

   // derived-class vector fields
   sort();

   // construct
   void (Component::*componentConstruct)
      (const Node &) = &Component::construct;
   void (DERIVED::*derivedConstruct)
      (const Node &) = &DERIVED::construct;

   if (derivedConstruct != componentConstruct)
      derived().construct(node);
   else
      derived().construct();
}


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
   read(node);
   return ret;
}

// read(file, FileType)
bool read(
   const std::string &filename,
   const FileType format = FileType::guess,
   const bool decl = false
) {
   Node node;
   bool ret = node.read(filename, format, decl);
   read(node);
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
   read(node);
   return ret;
}

// read(file, string)
bool read(
   const std::string &filename,
   const std::string &format,
   const bool decl = false
) {
   Node node;
   bool ret = node.read(filename, format, decl);
   read(node);
   return ret;
}
