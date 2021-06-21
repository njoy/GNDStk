
// -----------------------------------------------------------------------------
// Miscellaneous simple member functions
// -----------------------------------------------------------------------------

// clear()
// Clears the active vector alternative in the variant.
BodyText &clear()
{
   std::visit([](auto &&alt) { return alt.clear(); }, variant);
   return *this;
}

// size()
// Returns the size of the active vector alternative in the variant.
// Depending on what actions someone has performed on the current BodyText
// object, size() might or might not reflect the values of length and/or
// start, or reflect the current contents of the raw string.
std::size_t size() const
{
   return std::visit([](auto &&alt) { return alt.size(); }, variant);
}
