
// -----------------------------------------------------------------------------
// operator==
// -----------------------------------------------------------------------------

bool operator==(const Node &two) const
{
   const auto &one = *this;

   // same Node?
   if (&one == &two)
      return true;

   // ------------------------
   // Fast/easy checks
   // ------------------------

   // name
   if (one.name != two.name)
      return false;

   // sizes
   if (one.metadata.size() != two.metadata.size()) return false;
   if (one.children.size() != two.children.size()) return false;

   // metadata
   if (std::set<metaPair>(one.metadata.begin(), one.metadata.end()) !=
       std::set<metaPair>(two.metadata.begin(), two.metadata.end()))
      return false;

   // ------------------------
   // OK, not fast/easy :-(
   // ------------------------

   // Here, we need the moral equivalent of the metadata test, but for children.
   // This requires ordering (and recursively so), as for sort(). (And note the
   // caveat described above our sort()'s less() helper.) For now, let's compare
   // printed versions of the Nodes in *sorted* form. (This will, in effect, do
   // the above comparisons again. Oh well.) We'll optimize later if necessary.

   const int indent = GNDStk::indent; // back up indentation
   GNDStk::indent = 0; // saves memory in the ostringstreams

   try {
      auto a = one; std::ostringstream ossa; ossa << a.sort();
      auto b = two; std::ostringstream ossb; ossb << b.sort();
      GNDStk::indent = indent; // restore indentation
      return ossa.str() == ossb.str();
   } catch (...) {
      GNDStk::indent = indent; // restore indentation
      log::function("Node == Node");
      throw;
   }
}


// -----------------------------------------------------------------------------
// operator!=
// -----------------------------------------------------------------------------

bool operator!=(const Node &two) const
{
   try {
      return !(*this == two);
   } catch (...) {
      log::function("Node != Node");
      throw;
   }
}
