
// -----------------------------------------------------------------------------
// Stream I/O
// -----------------------------------------------------------------------------

// istream >> Component
template<class DERIVED, bool hasBlockData, class DATATYPE>
std::istream &operator>>(
   std::istream &is,
   Component<DERIVED,hasBlockData,DATATYPE> &comp
) {
   try {
      return comp.read(is);
   } catch (...) {
      log::function("istream >> {}", comp.Class());
      throw;
   }
}

// ostream << Component
template<class DERIVED, bool hasBlockData, class DATATYPE>
std::ostream &operator<<(
   std::ostream &os,
   const Component<DERIVED,hasBlockData,DATATYPE> &comp
) {
   try {
      return comp.print(os,0);
   } catch (...) {
      log::function("ostream << {}", comp.Class());
      throw;
   }
}
