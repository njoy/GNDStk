
// -----------------------------------------------------------------------------
// I/O with respect to a string
// These are conveniences for reading and writing, for instance, XML or JSON
// content from/to a string.
// -----------------------------------------------------------------------------

// Node << string
// Remark: we return void, not the Node. This way, users don't incorrectly think
// that the <<s can be chained together in the way they can with stream output.
// We intend for the string's content to entirely replace whatever is currently
// in the Node; so, chaining doesn't really make sense.
void operator<<(const std::string &str)
{
   try {
      std::istringstream iss(str);
      read(iss);
   } catch (...) {
      log::function("Node << string");
      throw;
   }
}

// Node >> string
void operator>>(std::string &str) const
{
   try {
      std::ostringstream oss;
      write(oss);
      str = oss.str();
   } catch (...) {
      log::function("Node >> string");
      throw;
   }
}
