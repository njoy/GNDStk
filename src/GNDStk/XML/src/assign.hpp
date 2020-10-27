
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
      if (!convert(x,*this))
         throw std::exception{};
   } catch (...) {
      log::assign("XML = XML");
      throw;
   }
   return *this;
}
