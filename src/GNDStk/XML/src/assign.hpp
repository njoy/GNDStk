
// -----------------------------------------------------------------------------
// XML Assignment
// -----------------------------------------------------------------------------

// move
XML &operator=(XML &&) = default;

// copy
// Note: pugi::xml_document's is inaccessible
XML &operator=(const XML &x)
{
   try {
      convert(x,*this);
   } catch (const std::exception &) {
      detail::context("XML = XML");
      throw;
   }
   return *this;
}
