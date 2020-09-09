
/*
Description of convert(type,string)

Brief: type ==> string ==> node.meta(meta_t<type>)

These are essentially the reverse of the convert(string,type) functions.
The description of those, seen in reverse, applies here.

In short, these functions are for taking various types, perhaps user-defined,
and converting them into a string that's destined for the value of a metadatum's
key/value pair.
*/



// -----------------------------------------------------------------------------
// convert(T,ostream)
// Default: use operator<<
// -----------------------------------------------------------------------------

// default
template<class T>
inline void convert(const T &value, std::ostream &os)
{
   os << value;
}


// some sequence containers
#define GNDSTK_CONVERT(container) \
   template<class T, class Alloc> \
   inline void convert( \
      const std::container<T,Alloc> &value, \
      std::ostream &os \
   ) { \
      unsigned n = 0; \
      for (const T &v : value) \
         os << (n++ ? " " : "") << v; \
   }

   GNDSTK_CONVERT(deque)
   GNDSTK_CONVERT(list)
   GNDSTK_CONVERT(vector)

#undef GNDSTK_CONVERT



// -----------------------------------------------------------------------------
// convert(T,string)
// Default: make an ostringstream from the string, then use convert(*,ostream)
// -----------------------------------------------------------------------------

// default
template<class T>
inline void convert(const T &value, std::string &str)
{
   // try block, in case someone overloads our convert()s
   try {
      std::ostringstream oss;
      convert(value,oss);
      str = oss.str();
   } catch (const std::exception &) {
      log::context("convert(T,string)");
      throw;
   }
}


// char *
// Faster than we'd get by going through the generic T version. Note that we
// normally wouldn't write a "char *" case, as char * would normally convert
// to std::string, but it won't do so here, because of the generic T version.
inline void convert(const char *const value, std::string &str)
{
   str = value;
}

// convert(const std::string &, std::string &)
// Already defined, for "convert(string,type)"


// bool
inline void convert(const bool &value, std::string &str)
{
   str = value ? "true" : "false";
}


// miscellaneous
// T-to-string specializations that may be faster than our default
#define GNDSTK_CONVERT(TYPE) \
   inline void convert(const TYPE &value, std::string &str) \
   { \
      str = std::to_string(value); \
   }

   GNDSTK_CONVERT(int)
   GNDSTK_CONVERT(long)
   GNDSTK_CONVERT(long long)

   GNDSTK_CONVERT(unsigned)
   GNDSTK_CONVERT(unsigned long)
   GNDSTK_CONVERT(unsigned long long)

   // These write extra trailing 0s, e.g. 12.340000 instead of 12.34.
   // See https://en.cppreference.com/w/cpp/string/basic_string/to_string
   // So, we won't use them, and will let our default handle floating types.
   // GNDSTK_CONVERT(float)
   // GNDSTK_CONVERT(double)
   // GNDSTK_CONVERT(long double)

#undef GNDSTK_CONVERT
