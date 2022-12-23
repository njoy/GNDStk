
// Forward declaration, needed by some things later
template<class DERIVED, bool hasBlockData = false, class DATATYPE = void>
class Component;

namespace detail {

// -----------------------------------------------------------------------------
// Functions: miscellaneous
// -----------------------------------------------------------------------------

// ------------------------
// getName
// ------------------------

// Meta
template<class TYPE, class CONVERTER>
const std::string &
getName(const Meta<TYPE,CONVERTER> &m)
{
   return m.name;
}

// Child
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
const std::string &
getName(const Child<TYPE,ALLOW,CONVERTER,FILTER> &c)
{
   return c.name;
}

// pair<Child,string/regex>
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class T,
   class = std::enable_if_t<IsStringOrRegex<T>::value>
>
const std::string &
getName(const std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,T> &p)
{
   return getName(p.first);
}


// ------------------------
// Various
// ------------------------

// colorize
inline std::string colorize(
   const std::string &label,
   const std::string &color
) {
   // no coloring wanted?
   if (!GNDStk::colors)
      return label;

   // normal (not overridden) label color?
   if (color == "")
      return colorize_label(label);

   // override, e.g. for the label of a std::optional
   return color + label + GNDStk::color::reset;
}

// fullName
inline std::string fullName(
   const std::string &nname, // name of namespace
   const std::string &cname  // name of class
) {
   return (nname == "" ? "" : nname + "::") + cname;
}

// indentString
inline void indentString(
   std::ostream &os, const int level, const std::string &str = ""
) {
   os << std::string(GNDStk::indent * level,' ') << str;
}

// isDerivedFromComponent
// Adapted from an answer here:
//    https://stackoverflow.com/questions/34672441
// The issue is that Component is a class *template*.
template<class T>
class isDerivedFromComponent {
   template<class A, bool B, class C>
   static constexpr std::true_type test(Component<A,B,C> *);
   static constexpr std::false_type test(...);
   using type = decltype(test(std::declval<T *>()));
public:
   static constexpr bool value = type::value;
};


// ------------------------
// hasPrint*
// ------------------------

// These are adapted from an answer here:
// https://stackoverflow.com/questions/87372

// hasPrintOneArg
template<class DERIVED>
class HasPrintOneArg
{
   template<
      class U,
      std::ostream &(U::*)(std::ostream &) const
   > struct SFINAE {};

   template<class U> static char test(SFINAE<U, &U::print> *);
   template<class U> static long test(...);

public:
   static constexpr bool has = sizeof(test<DERIVED>(0)) == sizeof(char);
};

// HasPrintTwoArg
template<class DERIVED>
class HasPrintTwoArg
{
   template<
      class U,
      std::ostream &(U::*)(std::ostream &, const int) const
   > struct SFINAE {};

   template<class U> static char test(SFINAE<U, &U::print> *);
   template<class U> static long test(...);

public:
   static constexpr bool has = sizeof(test<DERIVED>(0)) == sizeof(char);
};

// Variable templates for the above; prefer these
template<class DERIVED>
inline constexpr bool hasPrintOneArg = HasPrintOneArg<DERIVED>::has;

template<class DERIVED>
inline constexpr bool hasPrintTwoArg = HasPrintTwoArg<DERIVED>::has;



// -----------------------------------------------------------------------------
// printComponentPart
// Forward declarations
// -----------------------------------------------------------------------------

// todo
// Verify that we really need these. At some point, I thought I determined that
// they were necessary for proper resolution of calls to the various overloaded
// printComponentPart() functions, which often call one another.

// Cases:
//    std::string
//    T
//    std::optional<T>
//    Defaulted<T>
//    std::vector<T>

bool printComponentPart(
   std::ostream &os, const int level, const std::string &str,
   const std::string &label, const std::size_t maxlen,
   const std::string &color = ""
);

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const T &value,
   const std::string &label, const std::size_t maxlen,
   const std::string &color = ""
);

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const std::optional<T> &opt,
   const std::string &label, const std::size_t maxlen
);

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const Defaulted<T> &def,
   const std::string &label, const std::size_t maxlen
);

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const std::vector<T> &vec,
   const std::string &label, const std::size_t maxlen,
   const std::string &color = ""
);



// -----------------------------------------------------------------------------
// printComponentPart
// Definitions
// -----------------------------------------------------------------------------

// ------------------------
// for string
// ------------------------

inline bool printComponentPart(
   std::ostream &os, const int level, const std::string &str,
   const std::string &label, const std::size_t maxlen,
   const std::string &color
) {
   indentString(os,level);

   if (label != "") {
      os << colorize(label,color);
      if (maxlen != 0) {
         assert(maxlen >= label.size());
         os << std::string(maxlen-label.size(),' ');
      }
      os << " " << colorize_colon(":");
      // Assuming the string to be printed isn't empty - which we don't really
      // anticipate would happen - print a space after the ":" and before the
      // soon-to-be-printed string.
      if (str != "")
         os << ' ';
   }

   // Nothing to print.
   if (str == "")
      return true;

   // Print, indenting after any internal newlines the string might happen
   // to have. Note that callers probably shouldn't *end* such strings with
   // newlines. They generally won't, given how this function is called, but
   // its possible that such newlines could arrive in the original data, from
   // somebody's file. These won't really do any harm (and all of this is just
   // prettyprinting, after all), but will simply cause a blank line to appear
   // where it may seem unexpected. Speaking of the unexpected, a newline at
   // the string's *beginning*, as opposed to its ending, will produce an end-
   // of-line space after the label and colon a few lines above ("label : \n").
   // Some may find end-of-line whitespace to feel...icky. We could write logic
   // that avoids producing end-of-line whitespace or blank lines, but believe
   // it's better to leave such things. If they occur, it may point somebody
   // to a construct like, say, the following in an XML file:
   //    <foo>
   //       <![CDATA[
   //          This is a comment.
   //       ]]>
   //    </foo>
   // which should probably be this instead:
   //    <foo>
   //       <![CDATA[This is a comment.]]>
   //    </foo>
   // That is, without leading and trailing newlines.

   bool start = true;
   for (auto &ch : str) {
      if (GNDStk::colors && start) os << color::value;
      start = ch == '\n';
      if (GNDStk::colors && start) os << color::reset; // before os << \n...
      os << ch;
      if (start) { // after \n, indent for additional content
         os << std::flush;
         indentString(os,level);
      }
   }
   if (GNDStk::colors) os << color::reset;

   return true;
}


// ------------------------
// for T
// ------------------------

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const T &value,
   const std::string &label, const std::size_t maxlen,
   const std::string &color
) {
   if constexpr (isDerivedFromComponent<T>::value) {
      // Suppress "unused parameter" warnings
      (void)value; (void)maxlen;
      (void)label; (void)color;
      // T is derived from Component, and thus inherits a print()
      value.baseComponent().print(os,level);
   } else {
      // T is any old type, not derived from Component
      if constexpr (std::is_floating_point_v<T>) {
         printComponentPart(
            os, level,
            detail::Precision<
               detail::PrecisionContext::metadata,
               T
            >{}.write(value),
            label, maxlen, color
         );
      } else {
         // The string intermediary allows us to indent properly
         // if the printed value has internal newlines.
         std::string str;
         convert_t{}(value,str);
         printComponentPart(os, level, str, label, maxlen, color);
      }
   }
   return true;
}


// ------------------------
// for optional
// ------------------------

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const std::optional<T> &opt,
   const std::string &label, const std::size_t maxlen
) {
   if (opt.has_value())
      printComponentPart(
         os, level, opt.value(),
         label, maxlen, color::optional
      );
   else if (comments)
      printComponentPart(
         os, level, colorize_comment("// optional; has no value"),
         label, maxlen, color::optional
      );
   else
      return false; // <== caller won't print newline
   return true;
}


// ------------------------
// for Defaulted
// ------------------------

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const Defaulted<T> &def,
   const std::string &label, const std::size_t maxlen
) {
   if (def.has_value()) {
      printComponentPart(
         os, level, def.value(),
         label, maxlen, color::defaulted
      );
   } else if (comments) {
      std::string str;
      convert_t{}(def.get_default(),str);
      printComponentPart(
         os, level,
         colorize_comment("// defaulted; is its default (" + str + ")"),
         label, maxlen, color::defaulted
      );
   } else
      return false; // <== so that caller won't print newline
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
bool printComponentPart(
   std::ostream &os, const int level, const std::vector<T> &vec,
   const std::string &label, const std::size_t /*maxlen*/,
   const std::string &color
) {
   // Doesn't use maxlen; formats with [...]

   // To avoid user confusion in prettyprinted output, we'll change our special
   // name "#comment" (which identifies comment nodes to be transformed into the
   // form <!--a comment--> when writing to XML), to the name "comment" instead.
   // Also, because our code generator creates the comment vector<string> field
   // automatically, in generated classes, we'll forego printing it here at all,
   // that is, we won't write "comment [(nothing)]"), if the vector is empty.
   const bool comment = label == special::comment;
   if (comment && vec.size() == 0)
      return false; // <== so that caller won't print newline

   indentString(
      os, level,
      colorize(
         comment ? "comment" : label,
         color != "" ? color : GNDStk::color::vector
      )
      + " " + colorize_bracket("[") + "\n"
   );

   for (auto &value : vec) {
      printComponentPart(os, level+1, value, "", 0);
      os << std::endl; // between elements
   }

   indentString(
      os, level,
      colorize_bracket("]")
   );

   return true;
}



// -----------------------------------------------------------------------------
// getter()
// Various cases.
// Intended for use in our Standard Interface classes.
// -----------------------------------------------------------------------------

#include "GNDStk/Component/src/detail-sfinae.hpp"
#include "GNDStk/Component/src/detail-getter.hpp"



// -----------------------------------------------------------------------------
// For sorting derived-class fields based on index and label, if and when one
// or the other of those is determined to be present. That determination hinges
// on both a compile-time check that the classes involved even *have* index or
// label fields, and, if they do, if either of those is possibly a std::optional
// that may or may not contain a value at the moment.
// -----------------------------------------------------------------------------

// ------------------------
// compareRegular
// ------------------------

// See compareVariant() below to understand
// why we have A and B, not T for both
template<class A, class B>
bool compareRegular(const A &a, const B &b)
{
   // Intentional: some "if ((x = y))"s below; i.e. =, not ==

   // index?
   std::size_t aindex = 0;  bool ahasindex = false;
   if constexpr (hasIndex<A>) {
      if constexpr (isOptional<decltype(A{}.index())>) {
         if ((ahasindex = a.index().has_value()))
            aindex = a.index().value();
      } else {
         ahasindex = true;
         aindex = a.index();
      }
   }

   std::size_t bindex = 0;  bool bhasindex = false;
   if constexpr (hasIndex<B>) {
      if constexpr (isOptional<decltype(B{}.index())>) {
         if ((bhasindex = b.index().has_value()))
            bindex = b.index().value();
      } else {
         bhasindex = true;
         bindex = b.index();
      }
   }

   // label?
   std::string alabel = "";  bool ahaslabel = false;
   if constexpr (hasLabel<A>) {
      if constexpr (isOptional<decltype(A{}.label())>) {
         if ((ahaslabel = a.label().has_value()))
            alabel = a.label().value();
      } else {
         ahaslabel = true;
         alabel = a.label();
      }
   }

   std::string blabel = "";  bool bhaslabel = false;
   if constexpr (hasLabel<B>) {
      if constexpr (isOptional<decltype(B{}.label())>) {
         if ((bhaslabel = b.label().has_value()))
            blabel = b.label().value();
      } else {
         bhaslabel = true;
         blabel = b.label();
      }
   }

   return
      // index: primary
      ahasindex && bhasindex ? aindex < bindex
    : ahasindex ? true
    : bhasindex ? false
      // label: secondary
    : ahaslabel && bhaslabel ? alabel < blabel
    : ahaslabel ? true
    : bhaslabel ? false
      // equal (so, not <, for strict weak ordering purposes)
    : false;
}


// ------------------------
// compareVariant
// ------------------------

template<class... Ts>
bool compareVariant(const std::variant<Ts...> &a, const std::variant<Ts...> &b)
{
   return std::visit(
      [&b](const auto &aalt)
      {
         return std::visit(
            [&aalt](const auto &balt)
            {
               // why compareRegular() needs A and B...
               return compareRegular(aalt,balt);
            },
            b
         );
      },
      a
   );
}


// ------------------------
// sort
// ------------------------

// T
template<class T>
void sort(T &)
{
   // nothing
}

// vector<T>
template<class T>
void sort(std::vector<T> &vec)
{
   if constexpr (hasIndex<T> || hasLabel<T>)
      std::sort(vec.begin(), vec.end(), compareRegular<T,T>);
}

// vector<variant<Ts...>>
template<class... Ts>
void sort(std::vector<std::variant<Ts...>> &vec)
{
   using T = std::variant<Ts...>;
   if constexpr (hasIndex<T> || hasLabel<T>)
      std::sort(vec.begin(), vec.end(), compareVariant<Ts...>);
}

// optional<vector>
template<class T>
void sort(std::optional<std::vector<T>> &opt)
{
   if (opt.has_value())
      sort(opt.value());
}



// -----------------------------------------------------------------------------
// queryResult
// doNotAlign
// -----------------------------------------------------------------------------

// default
template<class KEY>
struct queryResult {
   using type = std::decay_t<decltype(Node{}(std::declval<KEY>()))>;
};

// For Meta<Defaulted>
template<class TYPE, class CONVERTER>
struct queryResult<Meta<Defaulted<TYPE>,CONVERTER>> {
   using type = Defaulted<TYPE>;
};

// For std::tuple
template<class... KEYS>
struct queryResult<std::tuple<KEYS...>> {
   using type = std::tuple<typename queryResult<KEYS>::type...>;
};

// doNotAlign
// Component::print() uses the following to exclude [optional] vectors and
// Component-derived classes from its alignment computation. Those are printed
// in their own specific manner, and we think the alignment just looks better,
// and has fewer spurious-looking spaces, when those constructs are excluded.
template<class KEY>
struct doNotAlign {
   static constexpr bool value =
      isVector<
         typename queryResult<std::decay_t<KEY>>::type>::value ||
      isOptionalVector<
         typename queryResult<std::decay_t<KEY>>::type>::value ||
      isDerivedFromComponent<
         typename queryResult<std::decay_t<KEY>>::type>::value;
};

} // namespace detail
