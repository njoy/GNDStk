
// -----------------------------------------------------------------------------
// Tree Assignment
// -----------------------------------------------------------------------------

// move
Tree &operator=(Tree &&) = default;

// copy
Tree &operator=(const Tree &other)
{
   try {
      if (!convert(other,*this))
         throw std::exception{};
   } catch (...) {
      log::assign("Tree = Tree");
      throw;
   }
   return *this;
}
