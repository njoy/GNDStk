
/*
Description of convert(string,type)

Brief: Node.meta(Meta<type>) ==> string ==> type

These are called from some of Node's meta() functions, in order to convert
a string argument (from the value portion of a metadata key/value pair) to
some particular type, possibly user-defined.

This way, users who make custom types can define precisely how a string
from a GNDS hierarchy converts into their custom type.

Here, we'll predefine some convert(string,type) functions for certain existing
C++ types - in particular, for some container and POD types - and also for
output into a string itself (which of course just copies the input string).

The fallback behavior, for types that are neither specially handled by us nor
custom-defined by users, is to make an istringstream from the string, and then
call the type's stream-input operator.

Note that in some sense, these functions serve as intermediaries between a
meta() function that retrieves a string and wants to convert it to a given
type, and (if the fallback is used) a stream-input operator. One might ask
why we have the intermediary at all, instead of using stream-input directly.
There are, in fact, several reasons for this. One is efficiency: we have direct
conversions for certain simple types like int, and string itself. Another is
correctness; imagine what would happen if conversion from string to *another*
string went through the fallback's istringstream process. We also believe it's
a better design if users who create custom types can - but are *not* required
to - make stream-input operators for this specialized purpose. Maybe they want
a type's general stream-input operator to behave differently, or don't want it
to exist at all. Finally, consider the last point in relation to our defining
convert(string,type) for some existing C++ container types.
*/


// -----------------------------------------------------------------------------
// convert(istream,T)
// Default: use operator>>
// -----------------------------------------------------------------------------

// default
template<class T>
void convert(std::istream &is, T &value)
{
   if constexpr (std::is_floating_point_v<T>) {
      std::string str;
      is >> str;
      value = detail::Precision<
         detail::PrecisionContext::metadata,T
      >{}.read(str);
   } else {
      is >> value;
   }
}

// string
inline void convert(std::istream &is, std::string &value)
{
   is >> value;
}

// pair
template<class X, class Y>
void convert(std::istream &is, std::pair<X,Y> &p)
{
   // we allow:
   //    x y
   // or:
   //    x,y
   if ((convert(is,p.first),is)) {
      if (is.get() != ',')
         is.unget();
      convert(is,p.second);
   }
}

// some sequence containers
#define GNDSTK_CONVERT(container) \
   template<class T, class Alloc> \
   inline void convert( \
      std::istream &is, \
      std::container<T,Alloc> &value \
   ) { \
      value.clear(); \
      T val; \
      while ((convert(is,val),is)) { \
         value.push_back(val); \
         /* The following of course means that any ',' after the container  */ \
         /* elements will be eaten, but we don't believe this will create   */ \
         /* problems, given this function's usage. In fact, the container's */ \
         /* last element is *probably* at the end of the istream anyway.    */ \
         if (is.get() != ',') \
            is.unget(); \
      } \
   }

   GNDSTK_CONVERT(deque)
   GNDSTK_CONVERT(list)
   GNDSTK_CONVERT(vector)

#undef GNDSTK_CONVERT


// -----------------------------------------------------------------------------
// convert(string,T)
// Default: make an istringstream from the string, then use convert(istream,*)
// -----------------------------------------------------------------------------

// default
template<class T>
void convert(const std::string &str, T &value)
{
   // try block, in case someone overloads our convert()s
   try {
      std::istringstream iss(str);
      convert(iss,value);
   } catch (...) {
      log::function("convert(string,T)");
      throw;
   }
}

// string
inline void convert(const std::string &str, std::string &value)
{
   value = str;
}

// bool
inline void convert(const std::string &str, bool &value)
{
   // The GNDS files I have appear to use "true" and "false" exclusively
   if (str == "true")
      value = true;
   else if (str == "false")
      value = false;
   else {
      value = false;
      log::error(
         "Expected \"true\" or \"false\" in convert(string,bool); "
         "got \"{}\" instead",
         str
      );
      throw std::exception{};
   }
}

// miscellaneous
// string-to-T specializations that may be faster than our default
#define GNDSTK_CONVERT(fun,TYPE) \
   inline void convert(const std::string &str, TYPE &value) \
   { \
      value = std::fun(str); \
   }

   GNDSTK_CONVERT(stoi,   int)
   GNDSTK_CONVERT(stol,   long)
   GNDSTK_CONVERT(stoll,  long long)
   GNDSTK_CONVERT(stoul,  unsigned) // apparently there's no std::stou()
   GNDSTK_CONVERT(stoul,  unsigned long)
   GNDSTK_CONVERT(stoull, unsigned long long)

#undef GNDSTK_CONVERT
