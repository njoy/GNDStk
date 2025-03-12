
namespace detail {

// -----------------------------------------------------------------------------
// Type2Names
// -----------------------------------------------------------------------------

// ------------------------
// Generic
// ------------------------

template<class T>
class Type2Names {
public:
   static inline const std::vector<std::string> value = {""};
   static bool find(const std::string &str)
   {
      return std::find(value.begin(), value.end(), str) != value.end();
   }
};

// ------------------------
// For specific types
// ------------------------

#define makeType2Names(T,vec) \
   template<> \
   class Type2Names<T> { \
   public: \
      static inline const std::vector<std::string> value = vec; \
      static bool find(const std::string &str) \
      { \
         return std::find(value.begin(), value.end(), str) != value.end(); \
      } \
   }

makeType2Names(char,               {"char"});
makeType2Names(signed char,        {"signed char"});
makeType2Names(short,              {"short"});
makeType2Names(long,               {"long"});
makeType2Names(long long,          {"long long"});
makeType2Names(unsigned char,      {"unsigned char"});
makeType2Names(unsigned short,     {"unsigned short"});
makeType2Names(unsigned long,      {"unsigned long"});
makeType2Names(unsigned long long, {"unsigned long long"});
makeType2Names(float,              {"float"});
makeType2Names(long double,        {"long double"});

// COMMA idea: https://stackoverflow.com/questions/13842468
#define COMMA ,
makeType2Names(std::string,
   {"UTF8Text" COMMA "string" COMMA "std::string"});
makeType2Names(int,
   {"Integer32" COMMA "int"});
makeType2Names(unsigned,
   {"UInteger32" COMMA "unsigned" COMMA "unsigned int"});
makeType2Names(double,
   {"Float64" COMMA "double"});
#undef COMMA

#undef makeType2Names

// ------------------------
// Based on variant visit
// ------------------------

template<class VARIANT>
std::string visitType2Names(const VARIANT &variant)
{
   return std::visit(
      [](auto &&vec)
      {
         return Type2Names<std::decay_t<decltype(vec[0])>>::value[0];
      },
      variant
   );
}


// -----------------------------------------------------------------------------
// Names2Type
// -----------------------------------------------------------------------------

template<class CALLBACK>
void Names2Type(const std::string &str, const CALLBACK &call)
{
   // U helps when type T has spaces (e.g. T is long double)
#define makeNames2Type(T) \
   else if (Type2Names<T>::find(str)) { using U = T; call(U{}); }

   if (false) { } // so macro's "else" always works
   makeNames2Type(std::string)
   makeNames2Type(char)
   makeNames2Type(signed char)
   makeNames2Type(short)
   makeNames2Type(int)
   makeNames2Type(long)
   makeNames2Type(long long)
   makeNames2Type(unsigned char)
   makeNames2Type(unsigned short)
   makeNames2Type(unsigned)
   makeNames2Type(unsigned long)
   makeNames2Type(unsigned long long)
   makeNames2Type(float)
   makeNames2Type(double)
   makeNames2Type(long double)
   else
      call(std::string{});

#undef makeNames2Type
}

} // namespace detail
