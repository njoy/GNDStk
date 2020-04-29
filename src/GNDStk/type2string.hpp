
/*
Description of type2string()

Brief: type ==> string ==> node.meta(meta_t<type>)

These are essentially the reverse of the string2type() functions.
The description of those, seen in reverse, applies here.

In short, these functions are for taking various types, perhaps user-defined,
and writing them into a string that's destined for the value of a metadatum's
key/value pair.
*/



// -----------------------------------------------------------------------------
// type2ostream(T,ostream)
//
// Note the name: type2ostream, not type2string. These are helpers for the
// actual type2string functions that we'll define shortly. Also note that the
// ostream is the second parameter, to be consistent with the "foo2bar" style
// function name. (Contrast with stream I/O, where the stream is always first.)
//
// Default: use operator<<
// -----------------------------------------------------------------------------

// default
template<class T>
inline void type2ostream(const T &value, std::ostream &os)
{
   os << value;
}


// some sequence containers
#define GNDSTK_TYPE2OSTREAM(container) \
   template<class T, class Alloc> \
   inline void type2ostream( \
      const std::container<T,Alloc> &value, \
      std::ostream &os \
   ) { \
      unsigned n = 0; \
      for (const T &v : value) \
         os << (n++ ? " " : "") << v; \
   }

   GNDSTK_TYPE2OSTREAM(deque)
   GNDSTK_TYPE2OSTREAM(list)
   GNDSTK_TYPE2OSTREAM(vector)

#undef GNDSTK_TYPE2OSTREAM



// -----------------------------------------------------------------------------
// type2string(T,string)
// Default: make an ostringstream from the string, then use type2ostream()
// -----------------------------------------------------------------------------

// default
template<class T>
inline void type2string(const T &value, std::string &str)
{
   // try block, in case someone overloads our own type2ostream functions
   try {
      std::ostringstream oss;
      type2ostream(value,oss);
      str = oss.str();
   } catch (const std::exception &) {
      log::context("type2string(T,string)");
      throw;
   }
}


// char *
// string
// Faster than we'd get by going through the generic T version. Note that we
// normally wouldn't write a "char *" case, as char * would normally convert
// to std::string, but it won't do so here, because of the generic T version.
inline void type2string(const char *const value, std::string &str)
{
   str = value;
}

inline void type2string(const std::string &value, std::string &str)
{
   str = value;
}


// bool
inline void type2string(const bool &value, std::string &str)
{
   str = value ? "true" : "false";
}


// miscellaneous
// T-to-string specializations that may be faster than our default
#define GNDSTK_TYPE2STRING(T) \
   inline void type2string(const T &value, std::string &str) \
   { \
      str = std::to_string(value); \
   }

   GNDSTK_TYPE2STRING(int)
   GNDSTK_TYPE2STRING(long)
   GNDSTK_TYPE2STRING(long long)

   GNDSTK_TYPE2STRING(unsigned)
   GNDSTK_TYPE2STRING(unsigned long)
   GNDSTK_TYPE2STRING(unsigned long long)

   GNDSTK_TYPE2STRING(float)
   GNDSTK_TYPE2STRING(double)
   GNDSTK_TYPE2STRING(long double)

#undef GNDSTK_TYPE2STRING
