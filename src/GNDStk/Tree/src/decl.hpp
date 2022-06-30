
// -----------------------------------------------------------------------------
// Tree.decl()
// -----------------------------------------------------------------------------

// const
const Node &decl() const
{
   try {
      if (!has_decl()) {
         log::error("Tree has no declaration node");
         throw std::exception{};
      }
      for (auto &c : this->children)
         if (c->name == special::xml ||
             c->name == special::json ||
             c->name == special::hdf5)
            return *c;
      log::error("Tree's declaration node not found");
      throw std::exception{};
   } catch (...) {
      log::member("Tree.decl()");
      throw;
   }
}

// non-const
Node &decl()
{
   return const_cast<Node &>(std::as_const(*this).decl());
}
