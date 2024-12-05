
// -----------------------------------------------------------------------------
// Member functions: read
// -----------------------------------------------------------------------------

// ------------------------
// null
// ------------------------

template<class, class, class>
literal null::read(std::istream &is, const unsigned flags)
{
   static const std::string context = "While trying to read a json::null.\n";
   const std::string tok = detail::token<true>(is,context);

   if (tok != "null") {
      const std::string msg = context + "Unrecognized value: " + tok + '.';
      if (detail::nocasecmp(tok,"null"))
         warning(msg+"\nWe'll take it as lower-case null, and continue.", &is);
      else
         error(msg,&is); // throws
   }
   return literal(flags & literal::self ? "null" : "");
}

// ------------------------
// boolean
// ------------------------

template<class, class, class>
literal boolean::read(std::istream &is, const unsigned flags)
{
   static const std::string context = "While trying to read a json::boolean.\n";
   const std::string tok = detail::token<true>(is,context);

   if (tok != "true" && tok != "false") {
      const std::string msg = context + "Unrecognized value: " + tok + '.';
      if (detail::nocasecmp(tok,"true"))
         warning(msg+"\nWe'll take it as lower-case true, and continue.", &is);
      else if (detail::nocasecmp(tok,"false"))
         warning(msg+"\nWe'll take it as lower-case false, and continue.", &is);
      else
         error(msg,&is); // throws
   }
   b = tolower(tok[0]) == 't';
   return literal(flags & literal::self ? b ? "true" : "false" : "");
}

// ------------------------
// number
// ------------------------

// Remark: We'll rig class number's read() function so it uses the first of its
// variant's types that it's able to (examining types in the order in which they
// appear in the variant) when it reads a number. Users can always convert what
// we provide into a "longer" type. Also, read() allows specific integral and/or
// floating point types to be requested, overriding our default. Note that we'll
// select "more-restrictive" integral types: unsigned, and shorter. For floating
// points, we'll prefer good old-fashioned dog-eared double, with float the last
// choice. Having float be first would no doubt lead to all manner of grief.

// A caller can use T and/or U to specify up to one integral type and one
// floating point type. (Any such type(s) must still be in our variant.)
template<class T, class U, class>
literal number::read(std::istream &is, const unsigned flags)
{
   static const std::string context = "While trying to read a json::number.\n";
   const std::string tok = detail::token<false>(is,context);

   using integral = typename types<T,U>::integral;
   using floating = typename types<T,U>::floating;
   static constexpr bool gaveIntegral = !same<integral,void>;
   static constexpr bool gaveFloating = !same<floating,void>;

   // If an integral type was given in T or U, then attempt to read the
   // token into a value of that type. Failure isn't necessarily an error;
   // if a floating point type was also given, then we'll try that next.
   if constexpr (gaveIntegral)
      if (readableAs<integral>(tok,*this))
         return literal(flags & literal::self ? tok : "");

   // If a floating point type was given in T or U, then attempt to read
   // the token into a value of that type.
   if constexpr (gaveFloating)
      if (readableAs<floating>(tok,*this))
         return literal(flags & literal::self ? tok : "");

   // If integral and floating point types were both given, but the above
   // attempts both failed, then that's an error.
   if constexpr (gaveIntegral && gaveFloating)
      error(context +
           "Unable to interpret \"" + tok + "\" as either the requested\n"
           "integral type or the requested floating point type.", &is);

   bool found = false; // so far
   std::apply(
      [this,&tok,&found](const auto &... alt)
      {
         // The fold expression is rigged to terminate if and when found
         // becomes true. But if gaveIntegral, we won't accept additional
         // integral types (the requested one would have been tried above
         // already, without success), and similarly for gaveFloating.
         (( found || (found =
          !(gaveIntegral && json::integral<std::decay_t<decltype(alt)>>) &&
          !(gaveFloating && json::floating<std::decay_t<decltype(alt)>>) &&
           (readableAs<std::decay_t<decltype(alt)>>(tok,*this)))
         ), ...);
      },
      detail::variant2tuple<variant>::type()
   );

   if (!found)
      error(context + "Unable to interpret \"" + tok + "\" as a number "
           "or other JSON type.", &is);
   return literal(flags & literal::self ? tok : "");
}

// ------------------------
// string (and key)
// Via String
// ------------------------

template<bool b>
template<class, class, class>
literal String<b>::read(std::istream &is, const unsigned flags)
{
   static const std::string context = b
    ? "While trying to read a json::string.\n"
    : "While trying to read a json::key.\n";

   const bool single = (is >> std::ws).get() == '\'';
   if (single)
      warning(
         context +
        "We'll accept the single-quoted string '" +
        (is.peek() != EOF ? std::string(1,is.peek()) : "") +
        "..., but double quotes are standard.\n"
        "An ending single quote will be expected.",
         &is
      );
   else
      detail::expect(is.unget(), '"', context);

   const char delimiter = single ? '\'' : '"';
   *this = "";
   int ch;

   while ((ch = is.get()) != EOF && ch != delimiter)
      if (ch != '\\') {
         // plain character (not backslash)
         *this += ch;
      } else switch (ch = is.get()) {
         // backslash; so, get next character
         case '\'' : *this += '\'' ; break;
         case '"'  : *this += '"'  ; break;
         case '/'  : *this += '/'  ; break;
         case '\\' : *this += '\\' ; break;
         case 'b'  : *this += '\b' ; break;
         case 'f'  : *this += '\f' ; break;
         case 'n'  : *this += '\n' ; break;
         case 'r'  : *this += '\r' ; break;
         case 't'  : *this += '\t' ; break;

         case 'u': // these escapes aren't supported yet :-(
            error(context + "String escapes of the form \\u#### "
                 "aren't supported at this time.", &is);
            break;

         case EOF: // a '\' appeared right before EOF
            error(context + "String escape \\ appears right before EOF.", &is);
            break;

         default : // unrecognized escape
            error(context + "Unrecognized string escape \\" +
                  char(ch) + '.', &is);
            break;
      }

   if (ch != delimiter)
      error(context + "Unterminated string " + delimiter + *this + "....", &is);

   // Note that any json::literal return indeed gets delimiting quotes.
   return literal(flags & literal::self ? '"' + *this + '"' : "");
}

// ------------------------
// array
// ------------------------

template<class T, class U, class>
literal array::read(std::istream &is, const unsigned flags)
{
   static const std::string context = "While trying to read a json::array.\n";
   return detail::many<T,U>(*this, is, flags, '[', ']', context);
}

// ------------------------
// object
// ------------------------

template<class T, class U, class>
literal object::read(std::istream &is, const unsigned flags)
{
   static const std::string context = "While trying to read a json::object.\n";
   return detail::many<T,U>(*this, is, flags, '{', '}', context);
}

// ------------------------
// literal
// ------------------------

template<class T, class U, class>
literal literal::read(std::istream &is, const unsigned flags)
{
   str = value().read<T,U>(is, literal::self);
   return literal(flags & literal::self ? str : "");
}

// ------------------------
// value
// ------------------------

template<class T, class U, class>
literal value::read(std::istream &is, const unsigned flags)
{
   static const std::string context = "While trying to read a json::value.\n";
   const int peek = (is >> std::ws).peek();
   if (peek == EOF)
      error(context + "Expected a value (null, boolean, number, "
           "string, array, or object).", &is);

   return
      peek == 'n' || peek == 'N'
    ? read<T,U,null   >(is, flags, literal::null)
    : peek == 't' || peek == 'T' || peek == 'f' || peek == 'F'
    ? read<T,U,boolean>(is, flags, literal::boolean)
    : peek == '"' || peek == '\''
    ? read<T,U,string >(is, flags, literal::string)
    : peek == '['
    ? read<T,U,array  >(is, flags, literal::array)
    : peek == '{'
    ? read<T,U,object >(is, flags, literal::object)
    : read<T,U,number >(is, flags, literal::number);
   // Remark: number being the fallback makes the most sense. JSON doesn't
   // precisely say what "numbers" look like, but I think it's safe for us
   // to say that they shouldn't begin with n, t, f, ", etc.
}
