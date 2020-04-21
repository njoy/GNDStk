
// This is equivalent to !empty(), with an additional well-formedness check
bool has_decl() const
{
   // no
   if (root == nullptr)
      return false;

   // well-formedness checks
   const auto &elems = root->children;
   if (elems.size() > 1) {
      njoy::Log::error(
         "tree does not appear to be well-formed. Its declaration node\n"
         "has {} child nodes, but should have either one or none",
         elems.size()
      );
      throw std::exception{};
   }

   if (elems.size() != 0 && *elems.begin() == nullptr) {
      njoy::Log::error(
         "tree does not appear to be well-formed. Its declaration node\n"
         "has one child, but with nullptr"
      );
      throw std::exception{};
   }

   // yes
   return true;
}
