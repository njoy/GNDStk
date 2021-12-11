
// -----------------------------------------------------------------------------
// Getters and setters for the raw string
// -----------------------------------------------------------------------------

// getter
// string()
// Not to be confused with strings() (plural), which returns vector<string>.
// Returns const &; the raw string can be *changed* only through the setter.
const std::string &string() const
{
   return rawstring;
}

// setter
// string(new string)
// Builder pattern: return *this, so callers can use this function smoothly
// in conjunction with the setters for length, start, and valueType.
BlockData &string(const std::string &str)
{
   clear(); // <== the vector, because it's no longer considered meaningful
   rawstring = str;
   act = Active::string;
   return *this;
}
