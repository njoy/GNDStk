
// -----------------------------------------------------------------------------
// string
// In JSON: string, in double quotes.
// -----------------------------------------------------------------------------

class string : public std::string {
public:

   // ------------------------
   // Construction
   // ------------------------

   // default
   string() { }

   // from std::string
   // from const char *
   // from char *
   // from char
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
   string(const T &from) :
      std::string{from}
   { }

   string(const std::string &from) :
      std::string(from)
   { }

   string(std::string &&from) :
      std::string(std::move(from))
   { }

   // from char[N]
   template<
      class T, size_t N,
      class = std::enable_if_t<std::is_same_v<T,char>>
   >
   string(const T (&from)[N]) :
      std::string(from)
   { }

   // ------------------------
   // Assignment
   // ------------------------

   template<
      class T,
      class = std::enable_if_t<std::is_assignable_v<std::string,T>>
   >
   string &operator=(const T &from)
   {
      std::string::operator=(from);
      return *this;
   }

   template<
      class T,
      class = std::enable_if_t<std::is_assignable_v<std::string,T>>
   >
   string &operator=(T &&from)
   {
      std::string::operator=(std::move(from));
      return *this;
   }

   // ------------------------
   // read, write
   // ------------------------

   template<class T = void, class U = void>
   std::string read(std::istream &, const int = as_literal::none);

   void write(std::ostream & = std::cout, const int = 0, const int = -1) const;
};
