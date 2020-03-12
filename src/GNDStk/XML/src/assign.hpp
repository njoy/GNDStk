
// -----------------------------------------------------------------------------
// Assignment
// -----------------------------------------------------------------------------

// move
xml &operator=(xml &&) = default;

// copy
// Note: pugi::xml_document's is inaccessible
xml &operator=(const xml &x)
{
   convert(x,*this);
   return *this;
}
