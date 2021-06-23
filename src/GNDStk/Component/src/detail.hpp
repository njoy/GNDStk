
namespace detail {

// -----------------------------------------------------------------------------
// Functions: for coloring
// -----------------------------------------------------------------------------

// Use:
//    colorize_part(text)
// where part is some portion of the printed output.

#define gndstkPaste(one,two) one ## two
#define gndstkColorFun(part) \
   inline std::string gndstkPaste(colorize_,part)(const std::string &text) \
   { \
      return GNDStk::color && colors::part != "" \
         ? colors::part + text + colors::reset \
         : text; \
   }

   // colorize_label() etc.
   gndstkColorFun(label)
   gndstkColorFun(colon)
   gndstkColorFun(component)
   gndstkColorFun(brace)
   gndstkColorFun(bracket)
   gndstkColorFun(comment)

#undef gndstkColorFun
#undef gndstkPaste



// -----------------------------------------------------------------------------
// Functions: miscellaneous
// -----------------------------------------------------------------------------

// ------------------------
// getName
// ------------------------

// Meta
template<class TYPE, class CONVERTER>
std::string getName(const Meta<TYPE,CONVERTER> &m)
{
   return m.name;
}

// Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::string getName(const Child<TYPE,ALLOW,CONVERTER,FILTER> &c)
{
   return c.name;
}

// pair<Child,string/regex>
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class T,
   class = typename std::enable_if<IsStringOrRegex<T>::value>::type
>
std::string getName(const std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,T> &p)
{
   return getName(p.first);
}


// ------------------------
// colorize
// ------------------------

inline std::string colorize(
   const std::string &label,
   const std::string &color
) {
   // no coloring in the first place?
   if (!GNDStk::color)
      return label;

   // normal label color?
   if (color == "")
      return colorize_label(label);

   // override, e.g. for optional
   return color + label + colors::reset;
}


// ------------------------
// fullName
// ------------------------

inline std::string fullName(
   const std::string &nsname,
   const std::string &clname
) {
   return (nsname == "" ? "" : nsname + "::") + clname;
}


// ------------------------
// indentString
// ------------------------

inline void indentString(
   std::ostream &os, const int level, const std::string &str = ""
) {
   os << std::string(GNDStk::indent * level,' ') << str;
}


// ------------------------
// hasWriteOneArg
// hasWriteTwoArg
// ------------------------

// These are adapted from an answer here:
// https://stackoverflow.com/questions/87372

template<class DERIVED>
class hasWriteOneArg
{
   template<
      class U,
      std::ostream &(U::*)(std::ostream &) const
   > struct SFINAE {};

   template<class U> static char test(SFINAE<U, &U::write> *);
   template<class U> static long test(...);

public:
   static const bool has = sizeof(test<DERIVED>(0)) == sizeof(char);
};

template<class DERIVED>
class hasWriteTwoArg
{
   template<
      class U,
      std::ostream &(U::*)(std::ostream &, const int) const
   > struct SFINAE {};

   template<class U> static char test(SFINAE<U, &U::write> *);
   template<class U> static long test(...);

public:
   static const bool has = sizeof(test<DERIVED>(0)) == sizeof(char);
};



// -----------------------------------------------------------------------------
// writeComponentPart
// -----------------------------------------------------------------------------

// Cases:
//    std::string
//    T
//    std::optional<T>
//    Defaulted<T>
//    std::variant<Ts...>
//    std::vector<T>

bool writeComponentPart(
   std::ostream &os, const int level, const std::string &str,
   const std::string &label, const std::size_t maxlen,
   const std::string &color = ""
);

template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const T &value,
   const std::string &label, const std::size_t maxlen,
   const std::string &color = ""
);

template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const std::optional<T> &opt,
   const std::string &label, const std::size_t maxlen
);

template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const Defaulted<T> &def,
   const std::string &label, const std::size_t maxlen
);

template<class... Ts>
bool writeComponentPart(
   std::ostream &os, const int level, const std::variant<Ts...> &var,
   const std::string &label, const std::size_t maxlen
);

template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const std::vector<T> &vec,
   const std::string &label, const std::size_t maxlen,
   const std::string &color = ""
);


// ------------------------
// for string
// ------------------------

// label : value
inline bool writeComponentPart(
   std::ostream &os, const int level, const std::string &str,
   const std::string &label, const std::size_t maxlen,
   const std::string &color
) {
   indentString(os,level);
   if (label != "") {
      os << colorize(label,color);
      if (maxlen != 0) os << std::string(maxlen-label.size(),' ');
      os << " " << colorize_colon(":");
      // assuming the string to be printed isn't empty - which we don't really
      // anticipate would happen - then print a space after the ":" and before
      // the soon-to-be-printed string
      if (str != "")
         os << ' ';
   }
   for (auto &ch : str) {
      os << ch;
      // indent after any internal newlines the string might happen to have;
      // but callers probably shouldn't *end* such strings with newlines
      if (ch == '\n')
         indentString(os,level);
   }
   return true;
}


// ------------------------
// for T
// ------------------------

// label : value
template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const T &value,
   const std::string &label, const std::size_t maxlen,
   const std::string &color
) {
   if constexpr (
      std::is_base_of<Component<T,false>,T>::value ||
      std::is_base_of<Component<T,true >,T>::value
   ) {
      value.write(os,level);
   } else {
      // The ostringstream intermediary allows us to properly indent
      // in the event that the printed value has internal newlines.
      std::ostringstream oss;
      oss << value;
      writeComponentPart(os, level, oss.str(), label, maxlen, color);
   }
   return true;
}


// ------------------------
// for optional
// ------------------------

template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const std::optional<T> &opt,
   const std::string &label, const std::size_t maxlen
) {
   if (opt.has_value())
      writeComponentPart(
         os, level, opt.value(),
         label, maxlen, colors::optional
      );
   else if (comments)
      writeComponentPart(
         os, level, colorize_comment("// optional; has no value"),
         label, maxlen, colors::optional
      );
   else
      return false; // <== caller won't print newline
   return true;
}


// ------------------------
// for Defaulted
// ------------------------

template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const Defaulted<T> &def,
   const std::string &label, const std::size_t maxlen
) {
   if (def.has_value()) {
      writeComponentPart(
         os, level, def.value(),
         label, maxlen, colors::defaulted
      );
   } else if (comments) {
      std::ostringstream ostr;
      ostr << def.get_default();
      writeComponentPart(
         os, level,
         colorize_comment("// defaulted; is its default (" + ostr.str() + ")"),
         label, maxlen, colors::defaulted
      );
   } else
      return false; // <== caller won't print newline
   return true;
}


// ------------------------
// for variant
// ------------------------

template<class... Ts>
bool writeComponentPart(
   std::ostream &os, const int level, const std::variant<Ts...> &var,
   const std::string &label, const std::size_t maxlen
) {
   return std::visit(
      [&os,level,&label,maxlen](auto &&alternative)
      {
         return writeComponentPart(os, level, alternative, label, maxlen);
      },
      var
   );
}


// ------------------------
// for vector
// ------------------------

// label [
//    element
//    element
//    ...
// ]
template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const std::vector<T> &vec,
   const std::string &label, const std::size_t maxlen,
   const std::string &color
) {
   (void)maxlen; // doesn't use; formats with [...]

   indentString(
      os, level,
      colorize(
         label,
         color != "" ? color : colors::vector
      )
      + " " + colorize_bracket("[") + "\n"
   );

   for (auto &value : vec) {
      writeComponentPart(os, level+1, value, "", 0);
      os << '\n'; // between elements
   }

   indentString(
      os, level,
      colorize_bracket("]")
   );

   return true;
}



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// getter()
// Various cases.
// Intended for use in our auto-generated Standard Interface classes.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

// ------------------------
// SFINAE helpers
// ------------------------

// has_index
template<class T, class = int>
struct has_index : std::false_type { };
template<class T>
struct has_index<T,decltype((void)T::index,0)> : std::true_type { };

// has_label
template<class T, class = int>
struct has_label : std::false_type { };
template<class T>
struct has_label<T,decltype((void)T::label,0)> : std::true_type { };



// -----------------------------------------------------------------------------
// getter(vector,index,...)
// Index into vector data member of class.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::vector<T> &vec,
   const std::size_t index,
   const std::string &nsname, // enclosing class' namespace
   const std::string &clname, // enclosing class
   const std::string &field   // enclosing class' field we're accessing
) {
   static const std::string context = "getter {}::{}.{}({}) on vector";

   try {
      // fixme Make this more efficient, e.g. by assuming that the vector's
      // elements are sorted by index, so that the wanted value is likely
      // to be found at [index].

      const T *selected = nullptr;

      for (auto &v : vec) {
         const T *ptr = nullptr;

         if constexpr (isVariant<T>::value) {
            // T == variant
            std::visit(
               [&v,&index,&ptr](auto &&alternative)
               {
                  if constexpr (has_index<decltype(alternative)>::value)
                     if (alternative.index() == index)
                        ptr = &v;
               },
               v
            );
         } else {
            // T != variant
            if constexpr (has_index<T>::value)
               if (v.index() == index)
                  ptr = &v;
         }

         if (!ptr)
            continue;

         if (selected) {
            log::warning(
              "Element with index {} was already found in the vector.\n"
              "Keeping the first element that was found.",
               index
            );
            log::member(context, nsname, clname, field, index);
         } else
            selected = ptr;
      } // for

      if (!selected) {
         log::error(
           "Element with index {} was not found in the vector" +
            std::string(vec.size() ? "." : ";\nin fact the vector is empty."),
            index
         );
         throw std::exception{};
      }

      return *selected;

   } catch (...) {
      // context
      // Example: prints "getter containers::Axes.axis(100)"
      log::member(context, nsname, clname, field, index);
      throw;
   }
}

// non-const
template<class T>
T &getter(
   std::vector<T> &vec,
   const std::size_t index,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(vec), index, nsname, clname, field)
   );
}



// -----------------------------------------------------------------------------
// getter(vector,label,...)
// Element of the vector that has .label() == label.
// Assumes that the element type has a .label() getter.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::vector<T> &vec,
   const std::string &label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   static const std::string context = "getter {}::{}.{}(\"{}\") on vector";

   try {
      const T *selected = nullptr;

      for (auto &v : vec) {
         const T *ptr = nullptr;

         if constexpr (isVariant<T>::value) {
            // T == variant
            std::visit(
               [&v,&label,&ptr](auto &&alternative)
               {
                  if constexpr (has_label<decltype(alternative)>::value)
                     if (alternative.label() == label)
                        ptr = &v;
               },
               v
            );
         } else {
            // T != variant
            if constexpr (has_label<T>::value)
               if (v.label() == label)
                  ptr = &v;
         }

         if (!ptr)
            continue;

         if (selected) {
            log::warning(
              "Element with label \"{}\" was already found in the vector.\n"
              "Keeping the first element that was found.",
               label
            );
            log::member(context, nsname, clname, field, label);
         } else
            selected = ptr;
      } // for

      if (!selected) {
         log::error(
           "Element with label \"{}\" was not found in the vector" +
            std::string(vec.size() ? "." : ";\nin fact the vector is empty."),
            label
         );
         throw std::exception{};
      }

      return *selected;

   } catch (...) {
      // context
      log::member(context, nsname, clname, field, label);
      throw;
   }
}

// non-const
template<class T>
T &getter(
   std::vector<T> &vec,
   const std::string &label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(vec), label, nsname, clname, field)
   );
}



// -----------------------------------------------------------------------------
// getter(optional<vector>,index,...)
// As earlier, but for optional<vector> data member.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::optional<std::vector<T>> &opt,
   const std::size_t index,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      // optional must have value
      if (!opt.has_value()) {
         log::error("optional vector {} does not have a value", field);
         throw std::exception{};
      }
      return getter((*opt), index, nsname, clname, field);
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}({}) on optional<vector>",
         nsname, clname, field, index);
      throw;
   }
}

// non-const
template<class T>
T &getter(
   std::optional<std::vector<T>> &opt,
   const std::size_t index,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(opt), index, nsname, clname, field)
   );
}



// -----------------------------------------------------------------------------
// getter(optional<vector>,label,...)
// As earlier, but for optional<vector> data member.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::optional<std::vector<T>> &opt,
   const std::string &label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      // optional must have value
      if (!opt.has_value()) {
         log::error("optional vector {} does not have a value", field);
         throw std::exception{};
      }
      return getter((*opt), label, nsname, clname, field);
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}(\"{}\") on optional<vector>",
         nsname, clname, field, label);
      throw;
   }
}

// non-const
template<class T>
T &getter(
   std::optional<std::vector<T>> &opt,
   const std::string &label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(opt), label, nsname, clname, field)
   );
}



// -----------------------------------------------------------------------------
// getter<T>(...)
// With caller-specified type, when variant is involved
// -----------------------------------------------------------------------------

// ------------------------
// variant,...
// ------------------------

template<class T, class... Ts>
const T *getter(
   const std::variant<Ts...> &var,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return std::holds_alternative<T>(var)
         ? &std::get<T>(var)
         : nullptr;
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}() on variant",
         nsname, clname, field);
      throw;
   }
}


// ------------------------
// vector<variant>,index,...
// ------------------------

template<class T, class... Ts>
const T *getter(
   const std::vector<std::variant<Ts...>> &vec,
   const std::size_t index,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return getter<T>(
         // no <T>, so it calls getter(generic vector); it isn't recursive...
         getter(vec, index, nsname, clname, field), // <== returns scalar variant
         nsname, clname, field
      );
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}({}) on vector<variant>",
         nsname, clname, field, index);
      throw;
   }
}


// ------------------------
// vector<variant>,label,...
// ------------------------

template<class T, class... Ts>
const T *getter(
   const std::vector<std::variant<Ts...>> &vec,
   const std::string &label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return getter<T>(
         getter(vec, label, nsname, clname, field),
         nsname, clname, field
      );
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}(\"{}\") on vector<variant>",
         nsname, clname, field, label);
      throw;
   }
}

} // namespace detail
