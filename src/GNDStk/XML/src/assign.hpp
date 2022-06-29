
// -----------------------------------------------------------------------------
// XML Assignment
// -----------------------------------------------------------------------------

// move
XML &operator=(XML &&) = default;

// copy
// Note: pugi::xml_document's copy assignment is inaccessible;
// otherwise, this could = default.
XML &operator=(const XML &other)
{
   try {
      if (!convert(other,*this))
         throw std::exception{};
   } catch (...) {
      log::assign("XML = XML");
      throw;
   }
   return *this;
}
