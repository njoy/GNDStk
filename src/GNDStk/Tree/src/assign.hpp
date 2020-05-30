
// -----------------------------------------------------------------------------
// Tree Assignment
// -----------------------------------------------------------------------------

// move
Tree &operator=(Tree &&) = default;

// copy
Tree &operator=(const Tree &from)
{
   try {
      convert(from,*this);
   } catch (const std::exception &) {
      log::context("Tree = Tree");
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
      convert(from,*this);
   } catch (const std::exception &) {
      log::context("Tree = Tree<different>");
      throw;
   }
   return *this;
}
