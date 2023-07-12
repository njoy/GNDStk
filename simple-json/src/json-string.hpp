
// -----------------------------------------------------------------------------
// string
// In JSON: string, in double quotes.
// -----------------------------------------------------------------------------

class string : public std::string {
   using STRING = std::string;

public:
   using STRING::operator=;
   string(const STRING &from) : STRING(from) { }
   string(STRING &&from) : STRING(std::move(from)) { }
   string &operator=(const STRING &from)
   { static_cast<STRING &>(*this) = from; return *this; }
   string &operator=(STRING &&from)
   { static_cast<STRING &>(*this) = std::move(from); return *this; }

   // constructor: default
   string() { }

   // constructor: from std::string
   // constructor: from const char *
   // constructor: from char *
   // constructor: from char
   // Remark. For the "from char" case, using str{from} below, not str(from),
   // allows std::string's constructor from initializer_list<char> to be used.
   template<
      class T,
      class = std::enable_if_t<
         std::is_same_v<T,std::string> ||
         std::is_same_v<T,const char*> ||
         std::is_same_v<T,      char*> ||
         std::is_same_v<T,      char >
      >
   >
   string(const T &from) : STRING{from} { }

   // constructor: from char[N]
   template<class T, size_t N, class = std::enable_if_t<std::is_same_v<T,char>>>
   string(const T (&from)[N]) : STRING(from) { }

   // read, write
   template<class T = void, class U = void>
   std::string read(std::istream &, const int = as_literal::none);
   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
