
// -----------------------------------------------------------------------------
// Tree.top()
// -----------------------------------------------------------------------------

// const
const Node &top() const
{
   try {
      if (!has_top()) {
         log::error("Tree has no top-level GNDS node");
         throw std::exception{};
      }
      for (auto &c : this->children)
         if (c->name != special::xml &&
             c->name != special::json &&
             c->name != special::hdf5)
            return *c;
      log::error("Tree's top-level GNDS node not found");
      throw std::exception{};
   } catch (...) {
      log::member("Tree.top()");
      throw;
   }
}

// non-const
Node &top()
{
   return const_cast<Node &>(std::as_const(*this).top());
}
