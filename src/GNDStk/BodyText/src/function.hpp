
// -----------------------------------------------------------------------------
// Miscellaneous simple public member functions
// -----------------------------------------------------------------------------

// clear()
// Clears the active vector alternative in the variant.
// Doesn't *change* the alternative to any other one.
BodyText &clear()
{
   std::visit([](auto &&alt) { return alt.clear(); }, variant);
   return *this;
}


// size()
// Returns the size of the active vector alternative in the variant.
// Depending on what actions someone has performed on the current object,
// size() might or might not reflect the values of length and/or start,
// or reflect the current contents of the raw string.
std::size_t size() const
{
   return std::visit([](auto &&alt) { return alt.size(); }, variant);
}


// getter: string()
// NOT to be confused with strings() (plural), which returns vector<string>!
// const return only; the raw string can be changed only through our setter
const std::string &string() const
{
   return rawstring;
}


// setter: string(new string)
const std::string &string(const std::string &str)
{
   clear();
   remake = true;
   return rawstring = str;
}
