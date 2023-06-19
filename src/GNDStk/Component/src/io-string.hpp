
// -----------------------------------------------------------------------------
// String (not stream) I/O
// -----------------------------------------------------------------------------

// Component >> string
// Like Node >> string, but for Component's derived class.
void operator>>(std::string &str) const
{
   try {
      Node(*this) >> str;
   } catch (...) {
      log::function("{} >> string", Class());
      throw;
   }
}

// Component << string
// Like Node << string, but for Component's derived class.
void operator<<(const std::string &str)
{
   try {
      Node node;
      node << str;
      derived() = DERIVED(node);
   } catch (...) {
      log::function("{} << string", Class());
      throw;
   }
}
