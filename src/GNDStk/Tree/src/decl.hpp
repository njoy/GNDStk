
// -----------------------------------------------------------------------------
// Tree::decl()
// -----------------------------------------------------------------------------

// const
const nodeType &decl() const
{
   try {
      if (!has_decl()) {
         log::error("Tree has no declaration node");
         throw std::exception{};
      }
      for (auto &c : children)
         if (c->name == "xml" || c->name == "json" || c->name == "hdf5")
            return *c;
      log::error("Tree's declaration node not found");
      throw std::exception{};
   } catch (const std::exception &) {
      log::context("Tree::decl()");
      throw;
   }
}

// non-const
nodeType &decl()
{
   return const_cast<nodeType &>(std::as_const(*this).decl());
}
