
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

   // Below, the extra test involving iss.peek() proved to be necessary in
   // a couple of situations. Without it, a "date" string like, for example,
   // 2011-10-15, actually reads into three ints: 2011, -10, and -15, so that
   // the type guesser thinks "array of ints". One might have thought that
   // the >> operator would want whitespace between successive ints, but it
   // doesn't. :-/ A similar thing happened with, for example, a "version"
   // string like "8.0.1", which without the extra test looked to the type
   // guesser as two doubles. To fix this, we now directly check that after
   // any value is successfully read, we see either whitespace or EOF. (The
   // EOF check is done first; it's no doubt faster, and we anticipate that
   // many times we're checking short strings with just one value in them,
   // so that the EOF is likely to be there.)
   T value; std::size_t count = 0;
   for ( ; !iss.eof() ; ++count)
      if (!(iss >> value && (iss.peek() == EOF || isspace(iss.peek()))))
         return "";
   return count ? count > 1 ? type+"s" : type : "";
}

// guessType(string)
inline std::string guessType(const std::string &str)
{
   // the above helper assumes there are no trailing spaces
   std::size_t end = str.size();
   while (end && isspace(str[end-1])) end--;
   std::istringstream iss(str.substr(0,end));

   // one int, or more than one int, or one unsigned, or...
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
