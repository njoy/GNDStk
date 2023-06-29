
namespace detail {

// -----------------------------------------------------------------------------
// Classes
// -----------------------------------------------------------------------------

// inVariant
// count == number of times T is exactly the same as a type in the std::variant
template<class, class>
struct inVariant { };

template<class T, class... As>
struct inVariant<T, std::variant<As...>>
{
   static inline constexpr int count = (std::is_same_v<T,As> + ...);
};

// toVariant
// count == number of times T is convertible to a type in the std::variant
template<class, class>
struct toVariant { };

template<class T, class A>
struct toVariant<T, std::variant<A>>
{
   static inline constexpr int count =
      std::is_convertible_v<T,A>;
};

template<class T, class A, class... As>
struct toVariant<T, std::variant<A,As...>>
{
   static inline constexpr int count =
      std::is_convertible_v<T,A> + toVariant<T,std::variant<As...>>::count;
};

// For brevity
template<class T, class U> inline constexpr bool
   invar = inVariant<T,U>::count == 1;
template<class T, class U> inline constexpr bool
   tovar = toVariant<T,U>::count == 1;
template<class T> inline constexpr bool isintegral =
   std::is_integral_v<std::decay_t<T>>;
template<class T> inline constexpr bool isfloating =
   std::is_floating_point_v<std::decay_t<T>>;

// variant2tuple
template<class>
struct variant2tuple { };

template<class... As>
struct variant2tuple<std::variant<As...>> { using type = std::tuple<As...>; };


// -----------------------------------------------------------------------------
// Functions
// -----------------------------------------------------------------------------

// prefix
inline void prefix(
   std::ostream &os, const char ch
) {
   os << std::setw(0) << ch;
}

// inside
inline void inside(
   std::ostream &os, const char ch, // ch is always a ',' separator, for now
   const int indentNSpaces, const int indentLevel, bool &first
) {
   const std::string spaces(indentNSpaces*indentLevel,' ');
   first
      ? indentNSpaces ? (os       << '\n' << spaces) : (os      )
      : indentNSpaces ? (os << ch << '\n' << spaces) : (os << ch);
   first = false;
}

// suffix
inline void suffix(
   std::ostream &os, const char ch,
   const int indentNSpaces, const int indentLevel, const bool first
) {
   const std::string spaces(indentNSpaces*indentLevel,' ');
   first
      ? indentNSpaces ? (os                   << ch) : (os << ch)
      : indentNSpaces ? (os << '\n' << spaces << ch) : (os << ch);
}

// token
// First, skip white space. Then, read and return a token. Depending on the
// template argument, the token must consist of either (1) alpha characters
// only, or (2) alphanumeric characters, '.', '-', or '+'.
template<bool justAlpha> // <== alpha characters only
inline std::string token(std::istream &is, const std::string &context)
{
   std::string result; int ch;
   is >> std::ws;

   if constexpr (justAlpha)
      while (isalpha(is.peek()))
         result += char(is.get());
   else
      while ((isalnum(ch = is.peek()) || ch == '.' || ch == '-' || ch == '+'))
         result += char(is.get());

   if (result.empty()) {
      const std::string found = "Found " + ((ch = is.get()) == EOF
         ? "EOF" : "'" + std::string(1,ch) + "'") + "... instead.";
      const std::string expected = context + "Expected a token consisting of ";
      justAlpha
       ? error(expected + "alphabetic characters.\n" + found, is)
       : error(expected + "alphanumeric characters, ., -, or +.\n" + found, is);
   }
   return result;
}

// expect
inline void expect(std::istream &is, const int want, const std::string &context)
{
   const int ch = (is >> std::ws).get();
   if (ch != want) {
      const std::string got = ch == EOF ? "EOF" : "'" + std::string(1,ch) + "'";
      warning(context + "Expected the character '" + char(want) + "'.\nFound " +
              got + " instead.\nWe'll pretend we saw a '" + char(want) + "' "
             "before the " + got + ", but further problems could arise.", is);
      is.unget();
   }
}

// caseless
// Case-insensitive string comparison.
// The old C language strcasecmp() is nonstandard. A modern, true case
// insensitive string comparison is actually a tougher nut to crack than
// meets the eye, but the following should suffice for our purposes.
inline bool caseless(const std::string &one, const std::string &two)
{
   return std::equal(
      one.begin(), one.end(),
      two.begin(), two.end(),
      [](const char a, const char b) { return tolower(a) == tolower(b); }
   );
}

// many: forward declaration
template<class T, class U, class ELEMENT>
std::string many(
   std::vector<ELEMENT> &vec, std::istream &is,
   const int litFlags, const int as,
   const int prefix, const int suffix, const std::string &context
);


// -----------------------------------------------------------------------------
// readableAs<T>(string,target)
// -----------------------------------------------------------------------------

// Return value: are the string's contents *completely* readable as a T? (For
// example, "123" is readable as an int, among other things. However, "123foo"
// is not. Neither is, for example, 3.1415927, which in other interpretations
// might read as the int 3.) If so, then the so-read value will be placed into
// target. Note that we allow target to be of a different type than T. In some
// calls it is; in others, TARGET is (derived from) a std::variant with T as
// an alternative. This is why we have both T and TARGET.
template<class T, class TARGET>
bool readableAs(const std::string &str, TARGET &target)
{
   if constexpr (std::is_same_v<T,int>) {
      size_t idx;
      try { target = std::stoi(str,&idx); } catch (...) { return false; }
      while (isspace(str.data()[idx])) ++idx;
      return str.data()[idx] == '\0';
   } else if constexpr (detail::isfloating<T>) {
      char *end; using quad = long double;
      if constexpr (std::is_same_v<T,float >) target = strtof (str.data(),&end);
      if constexpr (std::is_same_v<T,double>) target = strtod (str.data(),&end);
      if constexpr (std::is_same_v<T,quad  >) target = strtold(str.data(),&end);
      if (end == str.data()) return false; // no conversion performed
      while (isspace(*end)) ++end; // white space is fine at the end...
      return *end == '\0'; // ...but only white space, nothing else, before \0
   } else {
      // Can we successfully read a T, with nothing of substance remaining?
      // The second condition means e.g. that "3.1415927" wouldn't pass as
      // an int merely because >> by itself would get 3.
      std::istringstream iss(str);
      T t;
      return iss >> t >> std::ws && iss.get() == EOF ? (target=t,true) : false;
   }
}

} // namespace detail
