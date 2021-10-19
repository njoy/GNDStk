
// fixme
// The "MapTypeString" and "MapStringType" terminology could probably be
// improved. For now this is detail material, so we won't worry about it.

namespace detail {

// -----------------------------------------------------------------------------
// MapTypeString
// -----------------------------------------------------------------------------

// ------------------------
// Generic
// ------------------------

template<class T>
class MapTypeString {
public:
   static inline const std::vector<std::string> value = {""};
   static bool find(const std::string &str)
   {
      return std::find(value.begin(),value.end(),str) != value.end();
   }
};

// ------------------------
// For specific types
// ------------------------

#define makeMapTypeString(T,vec) \
   template<> \
   class MapTypeString<T> { \
   public: \
      static inline const std::vector<std::string> value = vec; \
      static bool find(const std::string &str) \
      { \
         return std::find(value.begin(),value.end(),str) != value.end(); \
      } \
   }

makeMapTypeString(char,               {"char"});
makeMapTypeString(signed char,        {"signed char"});
makeMapTypeString(short,              {"short"});
makeMapTypeString(long,               {"long"});
makeMapTypeString(long long,          {"long long"});
makeMapTypeString(unsigned char,      {"unsigned char"});
makeMapTypeString(unsigned short,     {"unsigned short"});
makeMapTypeString(unsigned long,      {"unsigned long"});
makeMapTypeString(unsigned long long, {"unsigned long long"});
makeMapTypeString(float,              {"float"});
makeMapTypeString(long double,        {"long double"});

// COMMA idea: https://stackoverflow.com/questions/13842468
#define COMMA ,
makeMapTypeString(std::string,
   {"UTF8Text" COMMA "string" COMMA "std::string"});
makeMapTypeString(int,
   {"Integer32" COMMA "int"});
makeMapTypeString(unsigned int,
   {"UInteger32" COMMA "unsigned" COMMA "unsigned int"});
makeMapTypeString(double,
   {"Float64" COMMA "double"});
#undef COMMA

#undef makeMapTypeString

// ------------------------
// Based on variant visit
// ------------------------

template<class VARIANT>
std::string visitMapTypeString(const VARIANT &variant)
{
   return std::visit(
      [](auto &&vec)
      {
         return MapTypeString<std::decay_t<decltype(vec[0])>>::value[0];
      },
      variant
   );
}



// -----------------------------------------------------------------------------
// MapStringType
// -----------------------------------------------------------------------------

template<class CALLBACK>
void MapStringType(const std::string &str, const CALLBACK &call)
{
   // U helps when type T has spaces (e.g. T is long double)
#define makeMapStringType(T) \
   else if (MapTypeString<T>::find(str)) { using U = T; call(U{}); }

   if (false) { } // so macro's "else" always works
   makeMapStringType(std::string)
   makeMapStringType(char)
   makeMapStringType(signed char)
   makeMapStringType(short)
   makeMapStringType(int)
   makeMapStringType(long)
   makeMapStringType(long long)
   makeMapStringType(unsigned char)
   makeMapStringType(unsigned short)
   makeMapStringType(unsigned int)
   makeMapStringType(unsigned long)
   makeMapStringType(unsigned long long)
   makeMapStringType(float)
   makeMapStringType(double)
   makeMapStringType(long double)
   else
      call(std::string{});

#undef makeMapStringType
}

} // namespace detail
