
// -----------------------------------------------------------------------------
// null
// boolean
// -----------------------------------------------------------------------------

inline void null::
write(std::ostream &os, const int, const int) const
{
   os << "null";
}

inline void boolean::
write(std::ostream &os, const int, const int) const
{
   os << (b ? "true" : "false");
}


// -----------------------------------------------------------------------------
// number
// -----------------------------------------------------------------------------

// todo
// Idea: give all write() functions <T,U>, like the read()s; then be able
// to do floating ==> chars ==> literal ==> literal.write() from here...
inline void number::
write(std::ostream &os, const int, const int) const
{
   // Visit the active alternative, and write it in the usual manner.
   std::visit(
      [&os](auto &alt)
      {
         using T = std::decay_t<decltype(alt)>;
         if constexpr (std::is_same_v<T,unsigned char>)
            os << (unsigned short)alt;
         else if constexpr (std::is_same_v<T,signed char>)
            os << (signed short)alt;
         else
            os << alt;
      },
      static_cast<const variant &>(*this)
   );
}


// -----------------------------------------------------------------------------
// string
// -----------------------------------------------------------------------------

inline void string::
write(std::ostream &os, const int, const int) const
{
   // For now, we won't escape forward slashes. JSON doesn't require this.
   // See https://stackoverflow.com/questions/1580647
   os << '"';
   for (const char ch : *this)
      ch == '"'  ? os << "\\\"" :
      ch == '\\' ? os << "\\\\" :
      ch == '\b' ? os << "\\b"  :
      ch == '\f' ? os << "\\f"  :
      ch == '\n' ? os << "\\n"  :
      ch == '\r' ? os << "\\r"  :
      ch == '\t' ? os << "\\t"  :
      os << ch;
   os << '"';
}


// -----------------------------------------------------------------------------
// array
// -----------------------------------------------------------------------------

inline void array::
write(std::ostream &os, const int indentLevel, const int width) const
{
   const int indentNSpaces = width < 0 ? int(os.width()) : width;

   // [
   detail::prefix(os, '[');

   // array's elements
   bool first = true;
   for (const auto &elem : *this) {
      // ,
      detail::inside(os, ',', indentNSpaces, indentLevel+1, first);
      // value
      elem.write(os, indentLevel+1, indentNSpaces);
   }

   // ]
   detail::suffix(os, ']', indentNSpaces, indentLevel, first);
}


// -----------------------------------------------------------------------------
// object
// -----------------------------------------------------------------------------

inline void object::
write(std::ostream &os, const int indentLevel, const int width) const
{
   const int indentNSpaces = width < 0 ? int(os.width()) : width;

   // {
   detail::prefix(os, '{');

   // object's key:value pairs
   bool first = true;
   for (const auto &elem : *this) {
      // ,
      detail::inside(os, ',', indentNSpaces, indentLevel+1, first);
      // key:value
      elem.first.write(os);
      os << (indentNSpaces ? ": " : ":");
      elem.second.write(os, indentLevel+1, indentNSpaces);
   }

   // }
   detail::suffix(os, '}', indentNSpaces, indentLevel, first);
}


// -----------------------------------------------------------------------------
// literal
// value
// -----------------------------------------------------------------------------

inline void literal::
write(std::ostream &os, const int, const int) const
{
   // Write the literal string literally, with no processing or assumptions
   // at all. Know what you're doing, or you could produce invalid JSON. :-)
   os << str;
}

inline void value::
write(std::ostream &os, const int indentLevel, const int indentNSpaces) const
{
   std::visit(
      [&os,indentLevel,indentNSpaces](const auto &alt)
      {
         alt.write(os, indentLevel, indentNSpaces);
      },
      static_cast<const variant &>(*this)
   );
}
