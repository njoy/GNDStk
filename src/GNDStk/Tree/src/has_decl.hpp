
// This is equivalent to !empty(), with additional well-formedness checks
bool has_decl() const
{
   // no
   if (empty())
      return false;

   // fixme
   // Note to self. A goal in designing the tree structure was to respect and
   // follow the structure of existing XML GNDS files, which have a declaration
   // node, per XML, followed by a single top-level regular node. This structure
   // also slightly simplifies some of the recursive functions here and there.
   // The design has merits, but having worked with it for a while, I think a
   // reasonable change would be to have the tree structure instead have the
   // declaration node and the top-level gnds node instead both be std::optional
   // objects. This would allow us to avoid clutter like the two well-formedness
   // checks below, and might help to simplify and clarify some other things,
   // giving the overall design a net benefit. It's also worth considering a
   // name change: gnds() instead of top().

   // well-formedness checks
   const auto &elements = root->children;
   if (elements.size() > 1) {
      log::error(
         "Tree does not appear to be well-formed. Its declaration node\n"
         "has {} child nodes, but should have either one or none",
         elements.size()
      );
      throw std::exception{};
   }

   if (elements.size() != 0 && *elements.begin() == nullptr) {
      log::error(
         "Tree does not appear to be well-formed. Its declaration node\n"
         "has one child, but with nullptr"
      );
      throw std::exception{};
   }

   // yes
   return true;
}
