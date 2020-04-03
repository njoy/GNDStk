
// -----------------------------------------------------------------------------
// Assignment
// -----------------------------------------------------------------------------

// move
XML &operator=(XML &&) = default;

// copy
// Note: pugi::xml_document's is inaccessible
XML &operator=(const XML &x)
{
   convert(x,*this);
   return *this;
}
