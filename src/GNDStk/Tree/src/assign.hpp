
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

// templated "copy"
template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM
>
Tree &operator=(
   const Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from
) {
   try {
      if (!convert(from,*this))
         throw std::exception{};
   } catch (...) {
      log::assign("Tree = Tree<different>");
      throw;
   }
   return *this;
}
