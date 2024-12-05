
// -----------------------------------------------------------------------------
// value::make
// -----------------------------------------------------------------------------

// Remark about the cases where read() is called.
// read() can print warnings, or even print outright errors and then throw.
// Given that our make() function is designed to return false if our "make"
// process doesn't work, a case could be made that, here, we should suppress
// any diagnostics from read() and quietly return false upon read() failure.
// Importantly, we do catch any exceptions read() throws, returning false in
// that situation. We decided, however, not to suppress read()'s diagnostics.
// Notice that we do check for "reasonableness" first; for example, if we'll
// be trying to read a boolean from the literal, we check first that the
// literal begins with 'n' or 'N'. json::literals are intended, after all,
// to contain valid JSON content, even if they're also sufficiently flexible
// to contain general gibberish. With this in mind, if OUT is one of the types
// below, and the literal seems to begin reasonably, then calling out content
// that proves to be invalid - as read() will do - seems fair enough.

template<class OUT, class>
bool value::make(OUT &to, const bool allowLiteral) const
{
   null n; boolean b; string s; array a; object o;

   // If OUT == exactly what *this value actually holds right now.
   // The constexpr-if is necessary, vis-à-vis holds<OUT>'s SFINAE requirement.
   if constexpr (invar<OUT,variant> || invar<OUT,number::variant>)
      if (holds<OUT>())
         return to = get<OUT>(), true;

   // If OUT == std::nullptr_t
   if constexpr (same<OUT,std::nullptr_t>)
      return make(n,allowLiteral) ? to = n, true : false;

   // If OUT == bool
   if constexpr (same<OUT,bool>) {
      if (holds<number>()) return get<number>().make(to);
      return make(b,allowLiteral) ? to = b, true : false;
   }

   // If OUT == std::string
   if constexpr (same<OUT,std::string>)
      return make(s,allowLiteral) ? to = s, true : false;

   // If OUT == std::vector<value>
   if constexpr (same<OUT,std::vector<value>>)
      return make(a,allowLiteral) ? to = a, true : false;

   // If OUT == std::vector<pair>
   if constexpr (same<OUT,std::vector<pair>>)
      return make(o,allowLiteral) ? to = o, true : false;

   // At this point, invar<OUT,variant> || invar<OUT,number::variant>

   // If OUT \in {null,boolean,number,string,array,object} AND literal applies.
   // Attempt to read(), as long as the literal initially looks reasonable.
   if constexpr (invar<OUT,variant>) {
      if (holds<literal>() && allowLiteral) {
         char c = '\0';
         for (const char ch : std::string(get<literal>()))
            if (!isspace(c = tolower(ch)))
               break;
         if ((same<OUT,null   > && (c == 'n')) ||
             (same<OUT,boolean> && (c == 't' || c == 'f' )) ||
             (same<OUT,number >) ||
             (same<OUT,string > && (c == '"' || c == '\'')) ||
             (same<OUT,array  > && (c == '[')) ||
             (same<OUT,object > && (c == '{'))) {
            try {
               // zzz This works, but I think it also allows trailing
               // non-whitespace, unlike readableAs(). Think about this.
               return to.read(std::istringstream(get<literal>())), true;
            } catch (...) { }
         }
      }
   }

   // If OUT == something in number, try a couple of things.
   if constexpr (invar<OUT,number::variant>)
      return holds<number>()
         ? get<number>().make(to)
         : holds<literal>() ? number::readableAs(get<literal>(),to) : false;

   // Well, nothing worked.
   return false;
}
