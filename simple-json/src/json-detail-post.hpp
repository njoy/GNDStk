
namespace detail {

// variant2tuple
template<class>
struct variant2tuple { };
template<class... As>
struct variant2tuple<std::variant<As...>> { using type = std::tuple<As...>; };


// -----------------------------------------------------------------------------
// Re: printing
// -----------------------------------------------------------------------------

// name: specific cases
#define JSON_NAME(type) \
   inline std::string name(const type &) { return #type; }

JSON_NAME(unsigned char)
JSON_NAME(unsigned short)
JSON_NAME(unsigned int)
JSON_NAME(unsigned long)
JSON_NAME(unsigned long long)
JSON_NAME(signed char)
JSON_NAME(short)
JSON_NAME(int)
JSON_NAME(long)
JSON_NAME(long long)
JSON_NAME(double)
JSON_NAME(long double)
JSON_NAME(float)
JSON_NAME(null)
JSON_NAME(boolean)
JSON_NAME(string)
JSON_NAME(key)
JSON_NAME(array)
JSON_NAME(object)
JSON_NAME(literal)

#undef JSON_NAME

// name: for atom
// Remark: If preprocessor directives are such that atom<T> == T, then name(),
// as defined below, without the class = require<> SFINAE, would be infinitely
// recursive. It presumably wouldn't be called, because, above, we define each
// case we intend to use. To be exceedingly proper, though, we have the SFINAE.
template<class T, class = require<!same<atom<T>,T>>>
std::string name(const atom<T> &)
{
   return name(T());
}

// name: for number
inline std::string name(const number &n)
{
   return std::visit(
      [](const auto &alt) { return "number/" + name(alt); },
      static_cast<const number::variant &>(n)
   );
}

// print, for array and object
template<class ACTION, class T>
void print(
   const T &obj, std::ostream &os,
   const std::string &color, const char ch
) {
   std::string str = colors ? color : "";
   if constexpr (same<ACTION,SHAPE>)
      str += name(obj) + (indent < 0 ? ""  : " "  );
   if constexpr (same<ACTION,DEBUG>)
      str += name(obj) + (indent < 0 ? "=" : " = ");
   os << std::setw(0) << str + ch + (colors ? json::color::reset : "");
}

// print, for other types
template<class ACTION, class T>
void print(
   const T &obj, std::ostream &os, const std::string &content,
   const std::string &color, const int level
) {
   std::string str = same<ACTION,WRITE> ? content : name(obj);
   if constexpr (same<ACTION,DEBUG>)
      str += (indent < 0 ? "=" : " = ") + content;

   const std::streamsize setw = os.width();
   const size_t len = str.size(); // pre-colorized

   if (colors)
      str = color + str + json::color::reset;

   level || setw < 0 || size_t(setw) <= len
    ? os << std::setw(0) << str
    : os.flags() & std::ios::left
    ? os << std::setw(0) << str << std::string(setw-len, os.fill())
    : os << std::setw(0) << std::string(setw-len, os.fill()) << str;
}


// -----------------------------------------------------------------------------
// Miscellaneous small functions
// -----------------------------------------------------------------------------

// comma
inline void comma(std::ostream &os, const int level, int n)
{
   if (n)
      os << ',';
   if (indent >= 0)
      os << '\n';
   if (indent >= 1 && level >= 1)
      os << std::string(indent*level, ' ');
}

// token
// First, skip whitespace. Then, read and return a token. Depending on the
// template argument, the token must consist of either (1) alpha characters
// only, or (2) alphanumeric characters, '.', '-', or '+'.
template<bool justAlpha> // <== alpha characters only
std::string token(std::istream &is, const std::string &context)
{
   std::string result; int ch;
   is >> std::ws;

   if constexpr (justAlpha)
      while (isalpha(is.peek()))
         result += char(is.get());
   else
      while ((isalnum(ch = is.peek()) || ch == '.' || ch == '-' || ch == '+'))
         result += char(is.get());
   if (!result.empty())
      return result;

   const std::string found = "Found " + ((ch = is.get()) == EOF
      ? "EOF" : "'" + std::string(1,ch) + "'") + "... instead.";
   const std::string expected = context + "Expected a token consisting of ";
   justAlpha
    ? error(expected + "alphabetic characters.\n"               + found, &is)
    : error(expected + "alphanumeric characters, ., -, or +.\n" + found, &is);
   return ""; // error throws; this just suppresses compiler warnings
}

// expect
inline void expect(
   std::istream &is, const char want,
   const std::string &context
) {
   const int ch = (is >> std::ws).get();
   if (ch != want) {
      const std::string got = ch == EOF ? "EOF" : "'" + std::string(1,ch) + "'";
      warning(context + "Expected the character '" + want + "'.\nFound " +
              got + " instead.\nWe'll pretend we saw a '" + want + "' "
             "before the " + got + ", but further problems could arise.", &is);
      is.unget();
   }
}

// nocasecmp
// Case-insensitive std::string comparison.
// The old C language strcasecmp() is nonstandard. A modern, true caseless
// std::string comparison would depend on, e.g., locale, but the following
// should suffice for our purposes.
inline bool nocasecmp(const std::string &one, const std::string &two)
{
   return std::equal(
      one.begin(), one.end(),
      two.begin(), two.end(),
      [](const char a, const char b) { return tolower(a) == tolower(b); }
   );
}


// -----------------------------------------------------------------------------
// many
// -----------------------------------------------------------------------------

template<class T, class U, class ELEMENT>
literal many(
   std::vector<ELEMENT> &vec, std::istream &is, const unsigned flags,
   const char prefix, const char suffix, const std::string &context
) {
   vec.clear();
   expect(is,prefix,context);
   std::string text(1,prefix);

   int ch;
   while ((ch = (is >> std::ws).peek()) != EOF && ch != suffix) {
      // comma
      if (vec.size()) {
         expect(is,',',context);
         if (flags & literal::self)
            text += ',';
      }

      // value or key:value, with value read in-place for efficiency
      value *vptr = nullptr;
      if constexpr (same<ELEMENT,value>) {
         // array
         // ELEMENT == value (from array's base std::vector<value>)
         vec.push_back(value());
         vptr = &vec.back();
      } else {
         // object
         // ELEMENT == pair (from object's base std::vector<pair>)
         json::key key;
         key.read<T,U>(is);
         expect(is,':',context);
         if (flags & literal::self)
            text += '"' + key + "\":";
         vec.push_back(pair(key,value()));
         vptr = &vec.back().second;
      }

      text += vptr->read<T,U>(is,flags);
   }

   expect(is,suffix,context);
   return literal(flags & literal::self ? text+suffix : "");
} // many


// -----------------------------------------------------------------------------
// Support for reading string escapes of the form \u####
// -----------------------------------------------------------------------------

// ------------------------
// Constants, functions
// ------------------------

// Ranges for surrogates.
// Remark: each of [himin..himax] and [lomin..lomax]
// has 1024 values inclusive. Also, lomin == himax+1.
inline constexpr int himin = 0xD800; // 0b 11011 000 00000000
inline constexpr int himax = 0xDBFF; // 0b 11011 011 11111111
inline constexpr int lomin = 0xDC00; // 0b 11011 100 00000000
inline constexpr int lomax = 0xDFFF; // 0b 11011 111 11111111
inline constexpr unsigned tweak =
   unsigned(himin << 10) + unsigned(lomin) - 0x10000u;

// High/low surrogate?
inline bool hi(const int p) { return himin <= p && p <= himax; }
inline bool lo(const int p) { return lomin <= p && p <= lomax; }

// ------------------------
// codepoint
// ------------------------

// \uabcd ==> (a << 12) + (b << 8) + (c << 4) + (d << 0)
inline int codepoint(
   const std::string &context, std::istream &is,
   std::string &token // representation of hex number, for diagnostic printing
) {
   int ret = 0, ch;
   token = "\\u";
   for (const unsigned shift : { 12u, 8u, 4u, 0u }) {
      if ((ch = is.get()) == EOF)
         error(context +
              "Expected 4-character hex code; reached EOF instead.", &is);
      else if ('0' <= ch && ch <= '9') ret += int((unsigned(ch)-48u) << shift);
      else if ('A' <= ch && ch <= 'F') ret += int((unsigned(ch)-55u) << shift);
      else if ('a' <= ch && ch <= 'f') ret += int((unsigned(ch)-87u) << shift);
      else
         error(context +
              "Invalid hex digit found while reading \\u####.", &is);
      token += ch;
   }
   return ret;
}

// ------------------------
// unicode
// ------------------------

inline void unicode(
   const std::string &context, std::istream &is,
   std::string &str
) {
   std::string one, two;
   int first = codepoint(context,is,one), second;

   static const std::string
      hi_before_lo = "A high surrogate must precede the low surrogate",
      lo_follow_hi = "A low surrogate must follow the high surrogate";

   if (lo(first))
      error(context + hi_before_lo + " " + one + ".\n" +
           "There was no such high surrogate.", &is);
   if (hi(first)) {
      if (is.get() != '\\' || is.get() != 'u')
         error(context + lo_follow_hi + " " + one + ".\n" +
              "There is no such low surrogate.", &is);
      if (!lo(second = codepoint(context,is,two)))
         error(context + lo_follow_hi + " " + one + ".\n" +
               two + " is not a low surrogate.", &is);
      first = (unsigned(first) << 10u) + unsigned(second) - tweak;
   }

   if (first <= 127) {
      // 0bbbbbbb (ASCII case)
      str += int(first);
   } else if (first <= 2047) {
      // 110bbbbb 10bbbbbb
      str += int(0b11000000u | ((unsigned(first) >>  6u)              ));
      str += int(0b10000000u | ((unsigned(first)       ) & 0b00111111u));
   } else if (first <= 65535) {
      // 1110bbbb 10bbbbbb 10bbbbbb
      str += int(0b11100000u | ((unsigned(first) >> 12u)              ));
      str += int(0b10000000u | ((unsigned(first) >>  6u) & 0b00111111u));
      str += int(0b10000000u | ((unsigned(first)       ) & 0b00111111u));
   } else {
      // 11110bbb 10bbbbbb 10bbbbbb 10bbbbbb
      str += int(0b11110000u | ((unsigned(first) >> 18u)              ));
      str += int(0b10000000u | ((unsigned(first) >> 12u) & 0b00111111u));
      str += int(0b10000000u | ((unsigned(first) >>  6u) & 0b00111111u));
      str += int(0b10000000u | ((unsigned(first)       ) & 0b00111111u));
   }
}

} // namespace detail
