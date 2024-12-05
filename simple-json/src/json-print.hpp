
// -----------------------------------------------------------------------------
// Member functions: print
// -----------------------------------------------------------------------------

// ------------------------
// null
// ------------------------

template<class ACTION>
void null::print(std::ostream &os, const int level) const
{
   detail::print<ACTION>(*this, os, "null", color::null, level);
}

// ------------------------
// boolean
// ------------------------

template<class ACTION>
void boolean::print(std::ostream &os, const int level) const
{
   detail::print<ACTION>(*this, os, b?"true":"false", color::boolean, level);
}

// ------------------------
// number
// ------------------------

template<class ACTION>
void number::print(std::ostream &os, const int level) const
{
   std::string str;
   if constexpr (!same<ACTION,detail::SHAPE>)
      std::visit(
         [&os,&str](auto &alt)
         {
            #ifdef JSON_CHARS
               str = chars(alt);
            #else
               using T = std::decay_t<decltype(alt)>;
               if constexpr (integral<T>)
                  str = chars(alt);
               else {
                  std::ostringstream oss;
                  oss << std::setw(os.width()) << alt;
                  str = oss.str();
               }
            #endif
         },
         static_cast<const variant &>(*this)
      );
   detail::print<ACTION>(*this, os, str, color::number, level);
}

// ------------------------
// string
// key
// ------------------------

template<bool b>
template<class ACTION>
void String<b>::print(std::ostream &os, const int level) const
{
   std::string str;
   if constexpr (!same<ACTION,detail::SHAPE>) {
      // We won't escape forward slashes; JSON doesn't require this. See:
      //    https://stackoverflow.com/questions/1580647
      // As for single quotes: in read(), we *accepted* escaped single quotes.
      // Doing so allowed us to read input strings that were delimited by single
      // quotes, even though double quotes are the JSON standard. Now, however,
      // we're writing, not reading, and we delimit JSON strings correctly: with
      // double quotes. We thus have no need here to escape single quotes.
      str += '"';
      for (const char ch : *this) {
         // contents
         ch == '"'  ? str += "\\\"" :
         ch == '\\' ? str += "\\\\" :
         ch == '\b' ? str += "\\b"  :
         ch == '\f' ? str += "\\f"  :
         ch == '\n' ? str += "\\n"  :
         ch == '\r' ? str += "\\r"  :
         ch == '\t' ? str += "\\t"  :
         str += ch;
         // Other escapes aren't supported yet; see remarks in string's read().
      }
      str += '"';
   }
   detail::print<ACTION>(*this, os, str, b ? color::string : color::key, level);
}

// ------------------------
// array
// ------------------------

template<class ACTION>
void array::print(std::ostream &os, const int level) const
{
   detail::print<ACTION>(*this, os, color::array, '[');

   // array's values
   for (size_t n = 0; n < size(); ++n) {
      // ,
      detail::comma(os, level+1, n);
      // value
      (*this)[n].template print<ACTION>(os, level+1);
   }

   os <<
      (indent >= 0 ? "\n" : "") + (colors ? color::array : "") +
      (indent >= 1 && level >= 1 ? std::string(indent*level, ' ') : "") + ']' +
      (colors ? color::reset : "");
}

// ------------------------
// object
// ------------------------

template<class ACTION>
void object::print(std::ostream &os, const int level) const
{
   detail::print<ACTION>(*this, os, color::object, '{');

   // object's key:value pairs
   for (size_t n = 0; n < size(); ++n) {
      // ,
      detail::comma(os, level+1, n);
      // key:value
      (*this)[n].first.template print<detail::WRITE>(os, 0);
      os << (indent >= 0 ? ": " : ":");
      (*this)[n].second.template print<ACTION>(os, level+1);
   }

   os <<
      (indent >= 0 ? "\n" : "") + (colors ? color::object : "") +
      (indent >= 1 && level >= 1 ? std::string(indent*level, ' ') : "") + '}' +
      (colors ? color::reset  : "");
}

// ------------------------
// literal
// ------------------------

// Print the contents literally, with no processing or assumptions at all.
template<class ACTION>
void literal::print(std::ostream &os, const int level) const
{
   detail::print<ACTION>(*this, os, str, color::literal, level);
}

// ------------------------
// value
// ------------------------

template<class ACTION>
void value::print(std::ostream &os, const int level) const
{
   std::visit(
      [&os,level](const auto &alt)
      {
         alt.template print<ACTION>(os,level);
      },
      static_cast<const variant &>(*this)
   );
}
