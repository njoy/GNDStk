
// readValue
template<class T, class U, class JSONCLASS>
void readValue(
   std::string &text, std::istream &is,
   const int flag, const int thisAsLiteral
) {
   if (thisAsLiteral) {
      JSONCLASS obj;
      *this = literal(text = obj.template read<T,U>(is,flag));
   } else {
      // read variant (= JSONCLASS()) in-place, for efficiency
      std::get<JSONCLASS>(*this = JSONCLASS()).template read<T,U>(is,flag);
   }
}

// trim
std::string trim() const
{
   const std::string &str = std::get<literal>(*this);
   size_t b = 0, e = str.size(); // begin, end
   while (b < e && isspace(str[b  ])) b++; // skip beginning spaces
   while (b < e && isspace(str[e-1])) e--; // skip ending spaces
   return str.substr(b,e-b);
}

// init
char init() const
{
   const std::string &str = std::get<literal>(*this);
   const char *s = str.data(); // guarantee '\0'
   while (isspace(*s))
      ++s;
   return *s; // '\0', if nothing else
}
