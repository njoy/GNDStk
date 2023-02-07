
// A forward declaration of Component is needed by some constructs here
template<class DERIVED, bool hasBlockData = false, class DATATYPE = void>
class Component;

namespace detail {

// Various helper constructs
#include "GNDStk/Component/src/detail-sfinae.hpp"

// getter()
// Various cases.
// Intended for use in our Standard Interface classes.
#include "GNDStk/Component/src/detail-getter.hpp"


// -----------------------------------------------------------------------------
// Functions: miscellaneous
// -----------------------------------------------------------------------------

// indentString
inline void indentString(
   std::ostream &os, const int level, const std::string &str = ""
) {
   os << std::string(GNDStk::indent * level, ' ') << str;
}


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

// fullName
inline std::string fullName(
   const std::string &nname, // name of namespace
   const std::string &cname  // name of class
) {
   return (nname == "" ? "" : nname + "::") + cname;
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

// isDerivedFromVector
// Similar to isDerivedFromComponent
template<class T>
class isDerivedFromVector {
   template<class X, class Allocator>
   static constexpr std::pair<std::vector<X,Allocator>,std::true_type>
      test(std::vector<X,Allocator> *);
   static constexpr std::pair<int,std::false_type>
      test(...);
   using ret = decltype(test(std::declval<T *>()));
public:
   static constexpr bool value = ret::second_type::value;
   using type = std::conditional_t<value, typename ret::first_type,void>;
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
// -----------------------------------------------------------------------------

// Cases:
//    1. string
//    2. DataNode<string>
//    3. DataNode<vector<T>>
//    4. T
//    5. vector<T>
//    6. std::optional<T>, GNDStk::Optional<T>
//    7. Defaulted<T>

// ------------------------
// 1. string
// ------------------------

inline bool printComponentPart(
   std::ostream &os, const int level, const std::size_t maxlen,
   const std::string &label,
   const std::string &value,
   const std::string &labelColor = color::label,
   const std::string &valueColor = color::value
) {
   indentString(os,level);

   if (label != "") {
      // label
      os << colorize(label,labelColor);

      // alignment
      if (maxlen != 0) {
         assert(maxlen >= label.size());
         os << std::string(maxlen-label.size(), ' ');
      }

      // space, :, space
      os << ' ' << colorize_colon(":");
      // Assuming the string to be printed isn't empty - which we don't really
      // anticipate it would be - print a space after the ":", i.e. just before
      // the soon-to-be-printed string.
      if (value != "")
         os << ' ';
   }

   // Nothing to print.
   if (value == "")
      return true;

   // Print, indenting after any internal newlines the string might contain.
   const bool hascolor = GNDStk::colors && valueColor != "";
   bool start = true;

   for (auto &ch : value) {
      if (start && hascolor) os << valueColor;
      start = ch == '\n';
      if (start && hascolor) os << color::reset; // before os << \n...
      os << ch;
      if (start) { // after \n, indent for additional content
         os << std::flush;
         indentString(os,level);
      }
   }
   if (hascolor) os << color::reset;

   return true;
}


// ------------------------
// 2. DataNode<string>
// ------------------------

template<bool preferCDATA>
bool printComponentPart(
   std::ostream &os, const int level, const std::size_t,
   const std::string &,
   const DataNode<std::string,preferCDATA> &value,
   const std::string & = "",
   const std::string &valueColor = color::data::string
) {
   // If empty, don't even print a newline
   if (value == "")
      return false;

   // Forward to printComponentPart(string). The way we're printing
   // a DataNode<string>, maxlen, label, and labelColor aren't used.
   return printComponentPart(
      os, level, 0, "",
      static_cast<const std::string &>(value),
      valueColor
   );
}


// ------------------------
// 3. DataNode<vector>
// ------------------------

template<class T, bool preferCDATA>
bool printComponentPart(
   std::ostream &os, const int level, const std::size_t,
   const std::string &,
   const DataNode<std::vector<T>,preferCDATA> &vec,
   const std::string & = "",
   const std::string &valueColor = color::data::vector
) {
   // The way we're printing a DataNode<vector>, maxlen, label,
   // and labelColor aren't used.

   // If empty, don't even print a newline
   const std::size_t size = vec.size();
   if (size == 0)
      return false;

   // Coloring?
   const bool hascolor =
      (colors && valueColor != "") ||
      (shades && std::is_arithmetic_v<T>);

   // Indentation (string, with some number of spaces)
   const std::string indent(GNDStk::indent * level, ' ');

   // End, given the requested truncation
   const std::size_t end = GNDStk::truncate < 0
      ? size
      : std::min(size, std::size_t(GNDStk::truncate));

   // Compute the minimum and maximum values in the data vector, if we'll need
   // them. Our use of std::conditional_t allows us to avoid constructing two
   // possibly large and complex T values (given that T could be, for example,
   // a large Component-based object) if T isn't of arithmetic type.
   std::conditional_t<std::is_arithmetic_v<T>,T,int> min, max;
   if constexpr (std::is_arithmetic_v<T>)
      if (shades) {
         min = max = vec[0]; // vec.size() == 0 was ruled out above
         for (std::size_t i = 1; i < size; ++i) {
            min = std::min(min,vec[i]);
            max = std::max(max,vec[i]);
         }
      }

   // Print, using column formatting
   for (std::size_t i = 0; i < end; ++i) {
      // element's whitespace prefix
      i == 0
         // at the very beginning
         ? os << indent
         : GNDStk::columns <= 0 || i % std::size_t(GNDStk::columns) != 0
         // still on the current line
         ? os << ' '
         // starting the next line
         : os << (hascolor ? color::reset : "") << std::endl << indent;

      // color, if applicable
      if constexpr (std::is_arithmetic_v<T>)
         if (shades)
            os << color::blue2red(min,vec[i],max);
      if (hascolor && !(std::is_arithmetic_v<T> && shades))
         os << valueColor;

      // element
      if constexpr (std::is_floating_point_v<T>)
         os << Precision<PrecisionContext::data,T>{}.write(vec[i]);
      else
         os << vec[i];
   };
   if (hascolor) os << color::reset;

   // If applicable, print a message saying the data were truncated
   if (end < size) {
      if (end > 0)
         os << std::endl; // we printed *something*; go to the next line, then:
      os << indent << colorize_comment(
         "// truncated; actual #elements == " + std::to_string(size));
   }

   return true;
}


// ------------------------
// 4. T (general)
// ------------------------

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const std::size_t maxlen,
   const std::string &label,
   const T &value,
   const std::string &labelColor = isDerivedFromComponent<T>::value
      ? color::component
      : color::label,
   const std::string &valueColor = color::value
) {
   // If value is derived from Component, we'll call its .print() function.
   // Otherwise, we'll forward to printComponentPart(string), after creating
   // some sort of string representation of the value.

   if constexpr (isDerivedFromComponent<T>::value) {
      value.baseComponent().print(os,level,labelColor);
   } else if constexpr (std::is_floating_point_v<T>) {
      // T is floating-point. Use our floating-point printing mechanism.
      printComponentPart(
         os, level, maxlen, label,
         Precision<PrecisionContext::metadata, T>{}.write(value),
         labelColor, valueColor
      );
   } else {
      // T is not floating-point.
      // A string intermediary allows us to indent properly if the printed
      // value has internal newlines.
      std::string str;
      convert_t{}(value,str);

      printComponentPart(
         os, level, maxlen, label,
         str,
         labelColor, valueColor
      );
   }

   return true;
}


// ------------------------
// 5. vector
// ------------------------

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const std::size_t,
   const std::string &label,
   const std::vector<T> &vec,
   const std::string &labelColor = color::vector,
   const std::string & = ""
) {
   // Forward to some printComponentPart() for each element. Note that here,
   // in the vector context, maxlen isn't applicable. As for valueColor (the
   // last parameter), the forwarded-to printComponentPart() will use what's
   // appropriate for the vector elements.

   // To avoid user confusion in prettyprinted output, we'll change our special
   // name "#comment" (which identifies comment nodes to be transformed into the
   // form <!--a comment--> when writing to XML), to the name "comment" instead.
   // Also, because our code generator creates the comment vector<string> field
   // automatically, in generated classes, we won't print it here at all if the
   // vector is empty; that is, we won't write "comment [(nothing)]").
   const bool isComment = label == special::comment;
   if (isComment && vec.size() == 0)
      return false; // <== so that the caller won't print a newline

   const std::string lab = isComment ? "comment" : label;

   indentString(
      os, level,
      colorize(lab, labelColor) + ' ' + colorize_bracket("[")
   );
   os << std::endl;

   for (const auto &element : vec) {
      printComponentPart(
         os, level+1, 0, "",
         element,
         isDerivedFromComponent<T>::value ? color::component : "",
         isComment ? color::data::comment : ""
      );
      os << std::endl; // between elements
   }

   indentString(
      os, level,
      colorize_bracket("]")
       + (comments ? ' ' + colorize_comment("// " + lab) : "")
   );

   return true;
}


// ------------------------
// 6. optional
// ------------------------

// todo Maybe don't need labelColor and valueColor?
template<class OPT>
bool printComponentPart_helper(
   std::ostream &os, const int level, const std::size_t maxlen,
   const std::string &label,
   const OPT &value,
   const std::string &labelColor = "",
   const std::string &valueColor = ""
) {
   using T = typename OPT::value_type;

   if (!value.has_value())
      return false; // <== so that the caller won't print a newline

   // label color
   std::string clabel = labelColor;
   if (clabel == "") {
      if constexpr (isDerivedFromComponent<T>::value)
         clabel = color::optional::component;
      else if constexpr (isVector<T>::value)
         clabel = color::optional::vector;
      else
         clabel = color::optional::label;
   }

   // value color
   std::string cvalue = valueColor;
   if (cvalue == "")
      cvalue = color::optional::value;

   // print
   printComponentPart(
      os, level, maxlen, label,
      value.value(),
      clabel
   );
   return true;
}

// std::optional
template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const std::size_t maxlen,
   const std::string &label,
   const std::optional<T> &value,
   const std::string &labelColor = "",
   const std::string &valueColor = ""
) {
   return printComponentPart_helper(
      os, level, maxlen, label, value, labelColor, valueColor);
}

// GNDStk::Optional
template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const std::size_t maxlen,
   const std::string &label,
   const GNDStk::Optional<T> &value,
   const std::string &labelColor = "",
   const std::string &valueColor = ""
) {
   return printComponentPart_helper(
      os, level, maxlen, label, value, labelColor, valueColor);
}


// ------------------------
// 7. Defaulted
// ------------------------

// todo Maybe don't need labelColor and valueColor?
template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const std::size_t maxlen,
   const std::string &label,
   const Defaulted<T> &value,
   const std::string &labelColor = "",
   const std::string &valueColor = ""
) {
   // label color
   std::string clabel = labelColor;
   if (clabel == "") {
      if constexpr (isDerivedFromComponent<T>::value)
         clabel = color::optional::component;
      else if constexpr (isVector<T>::value)
         clabel = color::optional::vector;
      else
         clabel = color::optional::label;
   }

   // value color
   std::string cvalue = valueColor;
   if (cvalue == "")
      cvalue = color::optional::value;

   // print
   printComponentPart(
      os, level, maxlen, label,
      value.value(),
      clabel, cvalue
   );

   // comment
   if (comments)
      os << ' ' << colorize_comment("// its default");
   return true;
}


// -----------------------------------------------------------------------------
// For sorting derived-class fields based on index and label, if and when one
// or the other of those is determined to be present. That determination hinges
// on both a compile-time check that the classes involved even *have* index
// or label fields, and, if they do, if either of those is possibly an optional
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

// std::optional<vector>
template<class T>
void sort(std::optional<std::vector<T>> &opt)
{
   if (opt.has_value())
      sort(opt.value());
}

// GNDStk::Optional<vector>
template<class T>
void sort(GNDStk::Optional<std::vector<T>> &opt)
{
   if (opt.has_value())
      sort(opt.value());
}


// -----------------------------------------------------------------------------
// Miscellaneous helper constructs
// -----------------------------------------------------------------------------

// ------------------------
// queryResult
// ------------------------

// general
template<class KEY>
struct queryResult {
   using type = std::decay_t<decltype(Node{}(std::declval<KEY>()))>;
};

// for Meta<Defaulted>
// Needed, because Node{}(std::declval<KEY>()) in the above "general" case
// doesn't instantiate for Defaulted, which has no default constructor.
template<class TYPE, class CONVERTER>
struct queryResult<Meta<Defaulted<TYPE>,CONVERTER>> {
   using type = Defaulted<TYPE>;
};

// for std::tuple
template<class... KEYS>
struct queryResult<std::tuple<KEYS...>> {
   using type = std::tuple<typename queryResult<KEYS>::type...>;
};

// ------------------------
// isDataNode
// ------------------------

// general
template<class T>
struct isDataNode {
   static constexpr bool value = false;
};

// for DataNode
template<class T, bool preferCDATA>
struct isDataNode<DataNode<T,preferCDATA>> {
   static constexpr bool value = true;
};

// ------------------------
// pprintAlign
// ------------------------

// Component::print() - the prettyprinter - uses the following in order to
// include certain constructs in Component-derived classes from its alignment
// computation, and exclude other constructs. We believe that the alignment
// just looks better, and has fewer spurious-looking spaces, when some types
// of constructs are excluded.

struct pprintAlign {
   template<class KEY>
   bool operator()(const KEY &, const void *const link) const
   {
      using RESULT = typename queryResult<KEY>::type;

      // [optional] vectors, component-derived classes, and data nodes
      // print in their own special manner; so, no key:value alignment.
      if constexpr (
         isVector              <RESULT>::value ||
         isOptionalVector      <RESULT>::value ||
         isDerivedFromComponent<RESULT>::value ||
         isDataNode            <RESULT>::value)
         return false;

      // if optional (with a non-vector value, or already handled above),
      // align iff optional has value, and value isn't component-derived
      if constexpr (isOptional<RESULT>)
         return ((const RESULT *)link)->has_value() &&
            !isDerivedFromComponent<typename RESULT::value_type>::value;

      return true;
   }
};

} // namespace detail
