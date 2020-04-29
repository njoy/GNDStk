
/*
Description of string2type()

Brief: node.meta(meta_t<type>) ==> string ==> type

These are called from some of node's meta() functions, in order to convert
a string argument (from the value portion of a metadata key/value pair) to
some particular type, possibly user-defined.

This way, users who make custom types can define precisely how a string value,
from a GNDS hierarchy, converts into their custom type.

Here, we'll pre-define some string2type() functions for certain existing
C++ types - in particular some container types and some POD types - and also
for output into a string itself (which of course just copies the input string).

The fallback string2type() behavior, for types that are neither specially
handled by us nor custom-defined by users, is to make an istringstream from
the string, and then call the type's stream-input operator.

Note that in some sense, these string2type() functions serve as intermediaries
between a meta() function that retrieves a string and wants to convert it to a
given type, and (if the fallback is used) a stream-input operator. One might
ask why we have the intermediary at all, instead of using stream-input directly.
There are, in fact, several reasons for this. One is efficiency: we have direct
conversions for certain simple types like int, and string itself. Another is
correctness; imagine what would happen if conversion from string to *another*
string went through the fallback's istringstream process. We also believe it's
a better design if users who create custom types can - but are *not* required
to - make stream-input operators for this specialized purpose. Maybe they want
a type's general stream-input operator to behave differently, or don't want it
to exist at all. Finally, consider the last point in relation to our defining
string2type for some existing C++ container types.
*/



// -----------------------------------------------------------------------------
// istream2type(istream,T)
//
// Note the name: istream2type, not string2type. These are helpers for the
// actual string2type() functions that we'll define shortly.
//
// Default: use operator>>
// -----------------------------------------------------------------------------

// default
template<class T>
inline void istream2type(std::istream &is, T &value)
{
   is >> value;
}


// some sequence containers
#define GNDSTK_ISTREAM2TYPE(container) \
   template<class T, class Alloc> \
   inline void istream2type( \
      std::istream &is, \
      std::container<T,Alloc> &value \
   ) { \
      value.clear(); \
      T v; \
      while (is >> v) \
         value.push_back(v); \
   }

   GNDSTK_ISTREAM2TYPE(deque)
   GNDSTK_ISTREAM2TYPE(list)
   GNDSTK_ISTREAM2TYPE(vector)

#undef GNDSTK_ISTREAM2TYPE



// -----------------------------------------------------------------------------
// string2type(string,T)
// Default: make an istringstream from the string, then use istream2type()
// -----------------------------------------------------------------------------

// default
template<class T>
inline void string2type(const std::string &str, T &value)
{
   // try block, in case someone overloads our own istream2type functions
   try {
      std::istringstream iss(str);
      istream2type(iss,value);
   } catch (const std::exception &) {
      log::context("string2type(string,T)");
      throw;
   }
}


// string
inline void string2type(const std::string &str, std::string &value)
{
   value = str;
}


// bool
inline void string2type(const std::string &str, bool &value)
{
   // The GNDS files I have appear to use "true" and "false" exclusively
   if (str == "true")
      value = true;
   else if (str == "false")
      value = false;
   else {
      value = false;
      log::error(
         "Expected \"true\" or \"false\" in string2type(string,bool); "
         "got \"{}\" instead",
         str
      );
      throw std::exception{};
   }
}


// miscellaneous
// string-to-T specializations that may be faster than our default
#define GNDSTK_STRING2TYPE(fun,T) \
   inline void string2type(const std::string &str, T &value) \
   { \
      value = std::fun(str); \
   }

   GNDSTK_STRING2TYPE(stoi,   int)
   GNDSTK_STRING2TYPE(stol,   long)
   GNDSTK_STRING2TYPE(stoll,  long long)

   GNDSTK_STRING2TYPE(stoul,  unsigned) // apparently there's no std::stou()
   GNDSTK_STRING2TYPE(stoul,  unsigned long)
   GNDSTK_STRING2TYPE(stoull, unsigned long long)

   GNDSTK_STRING2TYPE(stof,   float)
   GNDSTK_STRING2TYPE(stod,   double)
   GNDSTK_STRING2TYPE(stold,  long double)

#undef GNDSTK_STRING2TYPE
