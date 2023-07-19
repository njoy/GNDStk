
/*
Description of convert(type,string)

Brief: type ==> string ==> node.meta(Meta<type>)

These are essentially the reverse of the convert(string,type) functions.
The description of those, seen in reverse, applies here.

In short, these functions are for taking various types, perhaps user-defined,
and converting them into a string that's destined for the value of a metadatum's
key/value pair.
*/

// User-settable flag
inline bool commas = false;


// -----------------------------------------------------------------------------
// convert(T,ostream)
// Default: use operator<<
// -----------------------------------------------------------------------------

// default
template<class T>
void convert(const T &value, std::ostream &os)
{
   if constexpr (std::is_floating_point_v<T>) {
      os << detail::Precision<
               detail::PrecisionContext::metadata,T
            >{}.write(value);
   } else {
      os << value;
   }
}

// string
inline void convert(const std::string &value, std::ostream &os)
{
   os << value;
}

// pair
template<class X, class Y>
void convert(const std::pair<X,Y> &p, std::ostream &os)
{
   if ((convert(p.first,os),os) && os << (GNDStk::commas ? ',' : ' '))
      convert(p.second,os);
}

// some sequence containers
#define GNDSTK_CONVERT(container) \
   template<class T, class Alloc> \
   inline void convert( \
      const std::container<T,Alloc> &value, \
      std::ostream &os \
   ) { \
      const std::string sep = GNDStk::commas ? "," : " "; \
      size_t count = 0; \
      for (const T &val : value) \
         if (!(os << (count++ ? sep : "") && (convert(val,os),os))) \
            break; /* might as well, because the stream is broken */ \
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
void convert(const T &value, std::string &str)
{
   // try block, in case someone overloads our convert()s
   try {
      std::ostringstream oss;
      convert(value,oss);
      str = oss.str();
   } catch (...) {
      log::function("convert(T,string)");
      throw;
   }
}

// string
// Already defined elsewhere, in the form of convert(string,T) for T == string

// char *
// Faster than we'd get by going through the generic T version. Note that we
// normally wouldn't write a "char *" case, as char * would normally convert
// to std::string, but it won't do so here, because of the generic T version.
inline void convert(const char *const value, std::string &str)
{
   str = value;
}

// bool
inline void convert(const bool &value, std::string &str)
{
   str = value ? "true" : "false";
}

// miscellaneous
// Integral T-to-string specializations that may be faster than our default
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

#undef GNDSTK_CONVERT
