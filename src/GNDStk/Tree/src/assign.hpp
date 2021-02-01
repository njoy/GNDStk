
// -----------------------------------------------------------------------------
// Tree Assignment
// -----------------------------------------------------------------------------

// move
Tree &operator=(Tree &&) = default;

// copy
Tree &operator=(const Tree &from)
{
   try {
      if (!convert(from,*this))
         throw std::exception{};
   } catch (...) {
      log::assign("Tree = Tree");
      throw;
   }
   return *this;
}
