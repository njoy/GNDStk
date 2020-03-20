
namespace detail {

// strip
// Strips leading digits and white-space from a string. Modifies
// the original string, and also returns a reference to it.
inline std::string &strip(std::string &name)
{
   int n = 0, ch; const int size = name.size();
   while (n < size and (isdigit(ch=name[n]) or isspace(ch)))
      n++;
   return n ? (name = std::string(&name[n])) : name;
}

} // namespace detail