
// -----------------------------------------------------------------------------
// Tree.top()
// -----------------------------------------------------------------------------

// const
const nodeType &top() const
{
   try {
      if (!has_top()) {
         log::error("Tree has no top-level GNDS node");
         throw std::exception{};
      }
      for (auto &c : this->children)
         if (c->name != "xml" && c->name != "json" && c->name != "hdf5")
            return *c;
      log::error("Tree's top-level GNDS node not found");
      throw std::exception{};
   } catch (...) {
      log::member("Tree.top()");
      throw;
   }
}

// non-const
nodeType &top()
{
   return const_cast<nodeType &>(std::as_const(*this).top());
}
