
namespace detail {

// -----------------------------------------------------------------------------
// guessType(string)
// Guess what a string contains.
// -----------------------------------------------------------------------------

// helper
template<class T>
inline std::string guessType(std::istringstream &iss, const std::string &type)
{
   iss.clear();
   iss.seekg(0);

   T value; std::size_t count = 0;
   for ( ; !iss.eof() ; ++count)
      if (!(iss >> value))
         return "";
   return count ? count > 1 ? type+"s" : type : "";
}

// guessType(string)
inline std::string guessType(const std::string &str)
{
   // the above helper assumes there are no trailing spaces
   std::size_t e = str.size();
   while (e && isspace(str[e-1])) e--;
   std::istringstream iss(str.substr(0,e));

   // one int, or more than one int, or one unsigned, or ...
   std::string s;
   if ((s = guessType<int          >(iss,"int"   )) != "") return s;
   if ((s = guessType<unsigned     >(iss,"uint"  )) != "") return s;
   if ((s = guessType<long         >(iss,"long"  )) != "") return s;
   if ((s = guessType<unsigned long>(iss,"ulong" )) != "") return s;
   if ((s = guessType<double       >(iss,"double")) != "") return s;
   if ((s = guessType<std::string  >(iss,"string")) != "") return s;
   return "";
}

} // namespace detail
