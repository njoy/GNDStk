
// -----------------------------------------------------------------------------
// value::is_literal
// value::is_null
// value::is_boolean
// -----------------------------------------------------------------------------

bool is_literal() const
{
   return has<literal>();
}

bool is_null(const bool allowLiteral = true) const
{
   return has<null>() || (allowLiteral && is_literal() && trim() == "null");
}

bool is_boolean(const bool allowLiteral = true) const
{
   std::string s;
   return has<boolean>() || (
      allowLiteral && is_literal() && ((s = trim()) == "true" || s == "false"));
}


// -----------------------------------------------------------------------------
// value::is_number<T>
// -----------------------------------------------------------------------------

// Sketch.
//
// if T == void:
//    if this value has a number:
//       TRUE
//    if this value has a literal:
//       if the literal doesn't look like a null, boolean, or other NON-number:
//          TRUE
//       else
//          FALSE
//
// if T != void: (the caller gave a specific T)
//    if this value has a number:
//       if the number has a T
//          TRUE
//       else
//          TRUE if number ==> T ==> number is non-lossy, else FALSE
//    if this value has a literal:
//       TRUE if literal fully extracts as a T, else FALSE
//
// fallback:
//    FALSE

template<
   class T = void,
   class = std::enable_if_t<
      std::is_same_v<T,void> || detail::invar<T,number::variant>
   >
>
bool is_number(const bool allowLiteral = true) const
{
   if constexpr (std::is_same_v<T,void>) {
      // *** CASE: T == void
      // *** This is the default is_number<>() call, and means the caller
      // *** is asking if this value is a "number" in a generalized sense.

      // Does this value hold a number (which in turn will have one of
      // the numeric types in class number's variant)?
      if (has<number>())
         return true;

      // Does this value hold a literal whose string doesn't look viable
      // as anything *other* than a number? (If the literal's string begins
      // with 'n', 't', 'f', '"', '[', or '}', then it's probably a null,
      // boolean, string, array, or object. And, in any event, it certainly
      // can't be a valid number if it begins with one of those.)
      if (allowLiteral && is_literal()) {
         const std::string s = trim();
         // todo Recall if there was a reason we didn't allow for N, T, or F,
         // that is, in upper case. And why }, not {? Was there a reason?
         static const std::string other = "ntf\"[}";
         return s.size() && other.find(s[0]) == std::string::npos;
      }

   } else {
      // *** CASE: T != void
      // *** In this case, the caller stipulates a specific number type T.

      // Does this value hold a number?
      if (has<number>()) {
         // Yes. Get the number, which itself might be a T, or something else.
         const number &num = get<number>();

         // Does the number actually hold a T?
         if (std::holds_alternative<T>(number::variant(num)))
            return true;

         // The number has something other than a T. We'll say that the
         // is_number<T> test - this function call - passes if, and only if, the
         // existing non-T can be converted to a T, and back again, with no loss
         // of information. The thinking: someone is calling is_number<T>() to
         // determine if they can legitimately extract a value of type T from
         // the value. We'd say that that's a "yes" if this test passes.
         return std::visit(
            [](const auto &alt)
            {
               return std::decay_t<decltype(alt)>(T(alt)) == alt;
            },
            number::variant(num)
         );
      }

      // Does this value hold a literal? If so, in this "T is given by
      // the caller" case, we'll attempt to read a T from the literal's string,
      // and see if this is successful. As suggested above, in another remark:
      // is_number<T>() is probably being called as a prelude to attempting to
      // extract a T if is_number<T>() returns true. In other logical branches,
      // above, we didn't need to go so far as to try the (relatively expensive)
      // extraction itself, to be confident (barring JSON content errors!) that
      // a T extraction will work. Here, just trying it is about all we can do.
      if (allowLiteral && is_literal()) {
         T tmp;
         return detail::readableAs<T>(trim(),tmp);
      }
   }

   return false;
}


// -----------------------------------------------------------------------------
// value::is_string
// value::is_array
// value::is_object
// -----------------------------------------------------------------------------

bool is_string(const bool allowLiteral = true) const
{
   return has<string>() || (allowLiteral && is_literal() && init() == '"');
}

bool is_array (const bool allowLiteral = true) const
{
   return has<array >() || (allowLiteral && is_literal() && init() == '[');
}

bool is_object(const bool allowLiteral = true) const
{
   return has<object>() || (allowLiteral && is_literal() && init() == '{');
}
