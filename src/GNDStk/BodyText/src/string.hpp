
// -----------------------------------------------------------------------------
// Getters and setters for the raw string
// -----------------------------------------------------------------------------

// string()
// Not to be confused with strings() (plural), which returns vector<string>!
// Returns const &; the raw string can be *changed* only through the setter.
const std::string &string() const
{
   return rawstring;
}

// string(new string)
BodyText &string(const std::string &str)
{
   clear();
   remake = true;
   rawstring = str;
   return *this;
}
