
namespace detail {

// -----------------------------------------------------------------------------
// Miscellaneous small constructs
// -----------------------------------------------------------------------------

// default_*
// These are for internal use only, where we want to determine whether
// certain out-parameters were, or were not, sent to certain functions.

// bool
inline bool default_bool = false;
inline bool sent(const bool &found)
{
   return &found != &default_bool;
}

// string
inline std::string default_string = "";
inline bool sent(const std::string &string)
{
   return &string != &default_string;
}

// allowable declaration nodes
inline std::set<std::string> AllowedDecl = {
   "#xml",
   "#json",
   "#hdf5",
};

// noFilter
class noFilter {
public:
   template<class NODE>
   bool operator()(const NODE &) const { return true; }
};

// failback
inline void failback(std::istream &is, const std::streampos pos)
{
   is.clear();
   is.seekg(pos);
   is.setstate(std::ios::failbit);
}



// -----------------------------------------------------------------------------
// diagnostic
// -----------------------------------------------------------------------------

inline std::string diagnostic(
   const std::string &label,
   const std::string &message,
   const std::string &prefix = ""
) {
   static std::map<std::string,std::string> codes = {
      { "info",    "\033[36;21m" }, // cyan
      { "warning", "\033[33;1m"  }, // yellow
      { "error",   "\033[31;21m" }, // red
      { "debug",   "\033[37;1m"  }  // white
   };
   static const std::string under = "\033[4m";  // underline on
   static const std::string unoff = "\033[24m"; // underline off
   static const std::string reset = "\033[0m";  // all color/decorations off
   static const std::size_t warn = 7; // length of "warning", the longest label

   // full text, including the (possibly underlined) prefix if one was provided
   const std::string text = prefix == ""
    ?  message
    : (color ? under : "") + prefix + (color ? unoff : "") + ": " + message;

   // full text, possibly spaced for alignment
   std::string spaced, indent = std::string(warn+3,' '); // 3 for '[', ']', ' '
   if (align) {
      spaced = std::string(warn > label.size() ? warn-label.size() : 0, ' ');
      for (char c : text)
         spaced += c + (c == '\n' ? indent : "");
   } else
      spaced = text;

   // final message, possibly colorized
   return color ? codes[label] + spaced + reset : spaced;
}



// -----------------------------------------------------------------------------
// For SFINAE
// -----------------------------------------------------------------------------

// ------------------------
// isVariant
// ------------------------

template<class T>
class isVariant {
public:
   static constexpr bool value = false;
};

template<class... Ts>
class isVariant<std::variant<Ts...>> {
public:
   static constexpr bool value = true;
};

// ------------------------
// isAlternative
// ------------------------

// Is T one of the alternatives in variant<Ts...>?

// no (general case)
template<class T, class VARIANT>
class is_alternative {
public:
   static constexpr bool value = false;
};

// yes
template<class T, class... Ts>
class is_alternative<T,std::variant<Ts...>> {
public:
   static constexpr bool value = (std::is_same_v<T,Ts> || ...);
};

template<class T, class VARIANT>
inline constexpr bool isAlternative =
   is_alternative<T,VARIANT>::value;

// ------------------------
// isAlternativeOrTheVariant
// ------------------------

// Is T one of the alternatives in variant<Ts...>, OR is T == variant<Ts...>
// itself? (Not any variant, but precisely that one.)
//
// Consider the functionality (Node::meta() and Node::child(), at the time of
// this writing) that use this. Invoked with a particular type from the variant,
// a call - say, to meta() - might look like node.template meta<type>(M), where
// M is a Meta<> object with the variant type. In contrast, one could merely
// write node.meta(M) for the full variant, i.e. with no specific alternative
// type stipulated. By making this SFINAE work for the full variant, not just
// for each of its constituent types (as with isAlternative), we allow the
// node.template meta<type>(M) form also to work for the full variant. While
// the short (and no doubt preferred) form would be available even without the
// following, we choose to support consistency by allowing the .template form
// to be used too. This might prove to be useful if, for instance, a user embeds
// the call in question into a single function template that invokes the long
// form, while intending to support calls of either the full variant or any of
// its types.

template<class T, class VARIANT>
class is_alternativeOrTheVariant {
public:
   static constexpr bool value =
      isAlternative<T,VARIANT> || std::is_same_v<T,VARIANT>;
};

template<class T, class VARIANT>
inline constexpr bool isAlternativeOrTheVariant =
   is_alternativeOrTheVariant<T,VARIANT>::value;

// ------------------------
// is_void
// ------------------------

// general
template<class T>
class is_void {
public:
   static constexpr bool value = false;
};

// void
template<>
class is_void<void> {
public:
   static constexpr bool value = true;
   using type = void;
};

// isVoid
template<class T>
inline constexpr bool isVoid = is_void<T>::value;

// ------------------------
// isNotVoid
// ------------------------

// general
template<class T>
class isNotVoid {
public:
   static constexpr bool value = true;
   using type = T;
};

// void
template<>
class isNotVoid<void> {
public:
   static constexpr bool value = false;
};


// ------------------------
// isIterable
// ------------------------

// fixme
// At some point, we really need a reliable "is_container" traits class.
// For now, I'll use this.

template<class T, class = void>
class isIterable {
public:
   static constexpr bool value = false;
};

template<class T>
class isIterable<
   T,
   std::void_t<
      decltype(std::declval<T>().begin()),
      decltype(std::declval<T>().end())
   >
> {
public:
   static constexpr bool value = true;
};



// -----------------------------------------------------------------------------
// print_format
// -----------------------------------------------------------------------------

inline std::string print_format(const FileType f, const bool brief = false)
{
   return std::string(brief ? "" : "FileType::") + (
      f == FileType::null ? "null"
    : f == FileType::text ? "text"
    : f == FileType::xml  ? "XML"
    : f == FileType::json ? "JSON"
    : f == FileType::hdf5 ? "HDF5"
    : "unknown"
   );
}

} // namespace detail
