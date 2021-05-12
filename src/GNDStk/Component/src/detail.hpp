
namespace detail {

// -----------------------------------------------------------------------------
// Functions: for coloring
// -----------------------------------------------------------------------------

// Use:
//    detail::colorize_part(text)
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



// -----------------------------------------------------------------------------
// writeComponentPart
// -----------------------------------------------------------------------------

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
