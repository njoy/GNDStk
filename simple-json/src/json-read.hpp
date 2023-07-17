
// -----------------------------------------------------------------------------
// null
// -----------------------------------------------------------------------------

template<class, class>
std::string null::
read(std::istream &is, const int litFlags)
{
   static const std::string context = "While trying to read a json::null.\n";
   const std::string tok = detail::token<true>(is,context);

   if (tok != "null") {
      const std::string msg = context + "Unrecognized value: " + tok + ".";
      detail::caseless(tok,"null")
       ? warning(msg + "\nWe'll take it as lower-case null, and continue.", is)
       : error  (msg, is); // throws
   }
   return litFlags & as_literal::null ? "null" : "";
} // null::read


// -----------------------------------------------------------------------------
// boolean
// -----------------------------------------------------------------------------

template<class, class>
std::string boolean::
read(std::istream &is, const int litFlags)
{
   static const std::string context = "While trying to read a json::boolean.\n";
   const std::string tok = detail::token<true>(is,context);

   if (tok != "true" && tok != "false") {
      const std::string msg = context + "Unrecognized value: " + tok + ".";
      detail::caseless(tok,"true")
       ? warning(msg + "\nWe'll take it as lower-case true, and continue.", is)
       : detail::caseless(tok,"false")
       ? warning(msg + "\nWe'll take it as lower-case false, and continue.", is)
       : error  (msg, is); // throws
   }
   b = tolower(tok[0]) == 't';
   return litFlags & as_literal::boolean ? b ? "true" : "false" : "";
} // boolean::read


// -----------------------------------------------------------------------------
// number
// -----------------------------------------------------------------------------

// Remark. We'll rig class number's read() function so it uses the first of its
// variant's types that it's able to (examining types in the order in which they
// appear in the variant) when it reads a number. Users can always convert what
// we provide into a "longer" type. Also, read() allows specific integral and/or
// floating-point types to be requested, overriding our default. Note that we'll
// select "more-restrictive" integral types: unsigned, and shorter. For floating
// points, we'll prefer good old-fashioned dog-eared double, with float the last
// choice. Having float be first would no doubt lead to all manner of grief.

// A caller can use T and/or U to specify up to one integral type and one
// floating-point type. (Any such type(s) must still be in our variant.)
template<class T, class U, class>
std::string number::
read(std::istream &is, const int litFlags)
{
   static const std::string context = "While trying to read a json::number.\n";
   const std::string tok = detail::token<false>(is,context);

   const int lit = litFlags & as_literal::number;
   using integral = typename number::types<T,U>::integral;
   using floating = typename number::types<T,U>::floating;
   static constexpr bool gaveIntegral = !std::is_same_v<integral,void>;
   static constexpr bool gaveFloating = !std::is_same_v<floating,void>;

   // If an integral type was given in T or U, then attempt to read the
   // token into a value of that type. Failure isn't necessarily an error;
   // if a floating-point type was also given, then we'll try that next.
   if constexpr (gaveIntegral)
      if (detail::readableAs<integral>(tok,*this))
         return lit ? tok : "";

   // If a floating-point type was given in T or U, then attempt to read
   // the token into a value of that type.
   if constexpr (gaveFloating)
      if (detail::readableAs<floating>(tok,*this))
         return lit ? tok : "";

   // If integral and floating-point types were both given, but the above
   // attempts both failed, then that's an error.
   if constexpr (gaveIntegral && gaveFloating)
      error(context +
           "Unable to interpret \"" + tok + "\" as either the requested\n"
           "integral type or the requested floating-point type.", is);

   bool found = false; // so far
   std::apply(
      [this,&tok,&found](const auto &... alt)
      {
         // The fold is rigged to effectively terminate if and when found
         // becomes true. But if gaveIntegral, we won't accept additional
         // integral types (the requested one would have been tried above
         // already, without success), and similarly for gaveFloating.
         (
            (
               found || (found =
             !(gaveIntegral && detail::isintegral<decltype(alt)>) &&
             !(gaveFloating && detail::isfloating<decltype(alt)>) &&
              (detail::readableAs<std::decay_t<decltype(alt)>>(tok,*this)))
            ), ...
         );
      },
      detail::variant2tuple<variant>::type()
   );

   if (!found)
      error(context + "Unable to interpret \"" + tok + "\" as a number "
           "or other JSON type.", is);
   return lit ? tok : "";
} // number::read


// -----------------------------------------------------------------------------
// string
// -----------------------------------------------------------------------------

template<class, class>
std::string string::
read(std::istream &is, const int litFlags)
{
   static const std::string context = "While trying to read a json::string.\n";
   detail::expect(is,'"',context);

   *this = "";
   int ch;

   while ((ch = is.get()) != EOF && ch != '"')
      if (ch != '\\') {
         // plain character (not backslash)
         *this += ch;
      } else switch (ch = is.get()) {
         // backslash; so, get next character
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
                 "aren't supported at this time.", is);
            break;

         case EOF: // a '\' appeared right before EOF
            error(context + "String escape \\ appears right before EOF.", is);
            break;

         default : // unrecognized escape
            error(context + "Unrecognized string escape \\" +
                  char(ch) + '.', is);
            break;
      }

   if (ch != '"')
      error(context + "Unterminated string \"" + *this + "....", is);

   // Note that the json::literal-ized string indeed requires delimiting quotes
   return litFlags & as_literal::string ? '"' + *this + '"' : "";
} // string::read


// -----------------------------------------------------------------------------
// array
// object
// literal
// -----------------------------------------------------------------------------

template<class T, class U>
auto array::
read(std::istream &is, const int litFlags) -> decltype(number().read<T,U>(is,0))
{
   static const std::string context = "While trying to read a json::array.\n";
   return detail::many<T,U>(*this, is, litFlags, as_literal::array,
                            '[', ']', context);
} // array::read

template<class T, class U>
auto object::
read(std::istream &is, const int litFlags) -> decltype(number().read<T,U>(is,0))
{
   static const std::string context = "While trying to read a json::object.\n";
   return detail::many<T,U>(*this, is, litFlags, as_literal::object,
                            '{', '}', context);
} // object::read

template<class T, class U>
std::string literal::
read(std::istream &is, const int)
{
   return str = value().read<T,U>(is,as_literal::all);
} // literal::read


// -----------------------------------------------------------------------------
// value
// -----------------------------------------------------------------------------

template<class T, class U>
auto value::
read(std::istream &is, const int litFlags) -> decltype(number().read<T,U>(is,0))
{
   static const std::string context = "While trying to read a json::value.\n";
   const int peek = (is >> std::ws).peek();
   if (peek == EOF)
      error(context + "Expected a value (null, boolean, number, "
           "string, array, or object", is);

   // If we end up reading an array or an object, each of which contains some
   // number of JSON values, each of any type, then wanting to read the array
   // or the object as a literal means that each of its contained values must
   // be read as a literal too. These - for array and object - help with that.
   const int ARR = litFlags & as_literal::array  ? as_literal::all : litFlags;
   const int OBJ = litFlags & as_literal::object ? as_literal::all : litFlags;

   std::string ret;
   if (peek == 't' || peek == 'T' || peek == 'f' || peek == 'F')
      readValue<T,U,boolean>(ret, is, litFlags, litFlags & as_literal::boolean);
   else if (peek == 'n' || peek == 'N')
      readValue<T,U,null   >(ret, is, litFlags, litFlags & as_literal::null);
   else if (peek == '"')
      readValue<T,U,string >(ret, is, litFlags, litFlags & as_literal::string);
   else if (peek == '[')
      readValue<T,U,array  >(ret, is, ARR,      litFlags & as_literal::array);
   else if (peek == '{')
      readValue<T,U,object >(ret, is, OBJ,      litFlags & as_literal::object);
   else
      readValue<T,U,number >(ret, is, litFlags, litFlags & as_literal::number);
   return ret;
} // value::read
