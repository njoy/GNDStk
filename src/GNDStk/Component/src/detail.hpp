
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
// remove_cvref
// remove_cvrefs
// ------------------------

// C++20 will have this
template<class T>
class remove_cvref {
public:
   using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

// With -s, for tuple
template<class T>
class remove_cvrefs {
};

template<class... Ts>
class remove_cvrefs<std::tuple<Ts...>> {
public:
   using type = std::tuple<typename remove_cvref<Ts>::type ...>;
};


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
// indentString
// ------------------------

inline void indentString(
   std::ostream &os, const int level, const std::string &str = ""
) {
   os << std::string(njoy::GNDStk::indent * level,' ') << str;
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



// -----------------------------------------------------------------------------
// writeComponentPart
// -----------------------------------------------------------------------------

// Cases:
//    std::string
//    T
//    std::vector<T>
//    std::optional<T>
//    Defaulted<T>
//    std::variant<Ts...>


// ------------------------
// for string
// ------------------------

// label : value
inline bool writeComponentPart(
   std::ostream &os, const int level, const std::string &str,
   const std::string &label, const std::size_t maxlen,
   const std::string &color = ""
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
   const std::string &color = ""
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
   const std::string &color = ""
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
   if (def.has_value())
      writeComponentPart(
         os, level, def.value(),
         label, maxlen, colors::defaulted
      );
   else if (comments)
      writeComponentPart(
         os, level, colorize_comment("// defaulted; is its default"),
         label, maxlen, colors::defaulted
      );
   else
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



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// getter()
// Various cases.
// Intended for use in our auto-generated Standard Interface classes.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

// Helper
template<class T>
void check_index(const std::vector<T> &vec, const std::size_t n)
{
   const std::size_t size = vec.size();
   if (!(n < size)) {
      if (size > 0)
         log::error(
           "Index ({}) is out of range [0..{}] (the vector size is {})",
            n, size-1, size
         );
      else
         log::error(
           "Index ({}) is out of range; in fact the vector is empty",
            n
         );
      throw std::exception{};
   }
}



// -----------------------------------------------------------------------------
// getter(vector,n,...)
// Index into vector data member of class.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::vector<T> &vec,
   const std::size_t n,
   const std::string &nsname, // enclosing class' namespace
   const std::string &clname, // enclosing class
   const std::string &field   // enclosing class' field we're accessing
) {
   try {
      check_index(vec,n);
      return vec[n];
   } catch (...) {
      // context
      // Example: prints "getter containers::Axes.axis(100)"
      log::member(
        "getter {}::{}.{}({}) on vector",
         nsname, clname, field, n);
      throw;
   }
}

// non-const
template<class T>
T &getter(
   std::vector<T> &vec,
   const std::size_t n,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(vec), n, nsname, clname, field)
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
                  if (alternative.label() == label)
                     ptr = &v;
               },
               v
            );
         } else {
            // T != variant
            if (v.label() == label)
               ptr = &v;
         }

         if (!ptr)
            continue;

         if (selected) {
            log::warning(
              "Element with label \"\" was already found in the vector."
              "Keeping the first element that was found.",
               label
            );
            log::member(context, nsname, clname, field, label);
         } else
            selected = ptr;
      } // for

      if (!selected) {
         log::error(
           "Element with label \"\" was not found in the vector" +
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
// getter(optional<vector>,n,...)
// As earlier, but for optional<vector> data member.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::optional<std::vector<T>> &opt,
   const std::size_t n,
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
      return getter((*opt), n, nsname, clname, field);
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}({}) on optional<vector>",
         nsname, clname, field, n);
      throw;
   }
}

// non-const
template<class T>
T &getter(
   std::optional<std::vector<T>> &opt,
   const std::size_t n,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(opt), n, nsname, clname, field)
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
const std::optional<T> getter(
   const std::variant<Ts...> &var,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return std::holds_alternative<T>(var)
         ? std::optional<T>(std::get<T>(var))
         : std::optional<T>();
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}() on variant",
         nsname, clname, field);
      throw;
   }
}

// ------------------------
// vector<variant>,n,...
// ------------------------

template<class T, class... Ts>
const std::optional<T> getter(
   const std::vector<std::variant<Ts...>> &vec,
   const std::size_t n,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return getter<T>(
         // no <T>, so it calls getter(generic vector); it isn't recursive...
         getter(vec, n, nsname, clname, field), // <== returns scalar variant
         nsname, clname, field
      );
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}({}) on vector<variant>",
         nsname, clname, field, n);
      throw;
   }
}

// ------------------------
// vector<variant>,label,...
// ------------------------

template<class T, class... Ts>
const std::optional<T> getter(
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



// -----------------------------------------------------------------------------
// setter(vector<variant>,n,optional,...)
// That is, setter(), not getter() as the earlier functions were.
// Intended for use in our auto-generated Standard Interface classes.
// -----------------------------------------------------------------------------

template<class T, class... Ts>
void setter(
   std::vector<std::variant<Ts...>> &vec,
   const std::size_t n,
   const std::optional<T> &opt,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      check_index(vec,n);
      if (opt)
         vec[n] = *opt;
   } catch (...) {
      // context
      log::member(
        "setter {}::{}.{}({})",
         nsname, clname, field, n);
      throw;
   }
}



// -----------------------------------------------------------------------------
// BodyText
// -----------------------------------------------------------------------------

// default
template<bool bodyText>
class BodyText {
};

// for bodyText == true
template<>
class BodyText<true> {
public:
   // fixme Something fabulous and exciting here
}; // class BodyText

} // namespace detail
