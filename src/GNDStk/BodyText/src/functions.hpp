
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


// Getter: string()
// Not to be confused with strings() (plural), which returns vector<string>!
// Returns const &; the raw string can be *changed* only through the setter.
const std::string &string() const
{
   return rawstring;
}


// Setter: string(new string)
// Still returns const &, so that a caller can't surreptitiously set the
// raw string without calling this function and getting the clear() and
// remake = true side effects.
const std::string &string(const std::string &str)
{
   clear();
   remake = true;
   rawstring = str;
   return rawstring;
}
