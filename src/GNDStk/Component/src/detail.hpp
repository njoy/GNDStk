
namespace detail {

// -----------------------------------------------------------------------------
// Functions: miscellaneous
// -----------------------------------------------------------------------------

// indentString
inline void indentString(
   std::ostream &os, const int level, const std::string &str = ""
) {
   os << std::string(GNDStk::indent * level, ' ') << str;
}

// getName(Meta)
template<class TYPE, class CONVERTER>
const std::string &
getName(const Meta<TYPE,CONVERTER> &m)
{
   return m.name;
}

// getName(Child)
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
const std::string &
getName(const Child<TYPE,ALLOW,CONVERTER,FILTER> &c)
{
   return c.name;
}

// getName(pair<Child,string/regex>)
template<
   class TYPE, Allow ALLOW, class CONVERTER, class FILTER, class T,
   class = std::enable_if_t<IsStringOrRegex<T>::value>
>
const std::string &
getName(const std::pair<Child<TYPE,ALLOW,CONVERTER,FILTER>,T> &p)
{
   return getName(p.first);
}

// fullName
inline std::string fullName(
   const std::string &nname, // name of namespace
   const std::string &cname  // name of class
) {
   return (nname == "" ? "" : nname + "::") + cname;
}


// -----------------------------------------------------------------------------
// printComponentPart
// -----------------------------------------------------------------------------

// Cases:
//    1. string
//    2. DataNode<string>
//    3. DataNode<vector<T>>
//    4. T
//    5. vector<T>
//    6. std::optional<T>
//    7. Defaulted<T>

// ------------------------
// 1. string
// ------------------------

inline bool printComponentPart(
   std::ostream &os, const int level, const size_t maxlen,
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
      os << ' ' << colorize(":",labelColor);
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

   for (const char ch : value) {
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
   std::ostream &os, const int level, const size_t,
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
      "",
      valueColor
   );
}


// ------------------------
// 3. DataNode<vector>
// ------------------------

template<class T, bool preferCDATA>
bool printComponentPart(
   std::ostream &os, const int level, const size_t,
   const std::string &,
   const DataNode<std::vector<T>,preferCDATA> &vec,
   const std::string & = "",
   const std::string &valueColor = color::data::vector
) {
   // The way we're printing a DataNode<vector>, maxlen, label,
   // and labelColor aren't used.

   // If empty, don't even print a newline
   const size_t size = vec.size();
   if (size == 0)
      return false;

   // Coloring?
   const bool hascolor =
      (colors && valueColor != "") ||
      (shades && std::is_arithmetic_v<T>);

   // Indentation (string, with some number of spaces)
   const std::string indent(GNDStk::indent * level, ' ');

   // End, given the requested truncation
   const size_t end = GNDStk::elements < 0
      ? size
      : std::min(size, size_t(GNDStk::elements));

   // Compute the minimum and maximum values in the data vector, if we'll need
   // them. Our use of std::conditional_t allows us to avoid constructing two
   // possibly large and complex T values (given that T could be, for example,
   // a large Component-based object) if T isn't of arithmetic type.
   std::conditional_t<std::is_arithmetic_v<T>,T,int> min, max;
   if constexpr (std::is_arithmetic_v<T>)
      if (shades) {
         min = max = vec[0]; // vec.size() == 0 was ruled out above
         for (size_t i = 1; i < size; ++i) {
            min = std::min(min,vec[i]);
            max = std::max(max,vec[i]);
         }
      }

   // Print, using column formatting
   for (size_t i = 0; i < end; ++i) {
      // element's whitespace prefix
      i == 0
         // at the very beginning
         ? os << indent
         : GNDStk::columns <= 0 || i % size_t(GNDStk::columns) != 0
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
        "truncated; actual #elements == " + std::to_string(size),
         valueColor
      );
   }

   return true;
}


// ------------------------
// 4. T (general)
// ------------------------

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const size_t maxlen,
   const std::string &label,
   const T &value,
   const std::string &labelColor = isDerivedFromComponent_v<T>
      ? color::field
      : color::label,
   const std::string &valueColor = color::value
) {
   // If value is derived from Component, we'll call its .print() function.
   // Otherwise, we'll forward to printComponentPart(string), after creating
   // some sort of string representation of the value.

   (void)maxlen; // silence compiler warning if unused (per constexpr if)

   if constexpr (isDerivedFromComponent_v<T>) {
      value.baseComponent().print(os,level,label,labelColor);
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
   std::ostream &os, const int level, const size_t,
   const std::string &label,
   const std::vector<T> &vec,
   const std::string &labelColor = color::vector,
   const std::string & = ""
) {
   // Forward to some printComponentPart() for each element. Note that here,
   // in the vector context, maxlen isn't applicable. As for valueColor (the
   // last parameter), the forwarded-to printComponentPart() will use what's
   // appropriate for the vector's elements.

   // To avoid user confusion in prettyprinted output, we'll change our special
   // name "#comment" (which identifies comment nodes to be transformed into the
   // form <!--a comment--> when writing to XML), to the name "comment" instead.
   // Also, because our code generator creates the comment vector<string> field
   // automatically, in generated classes, we won't print it here at all if the
   // vector is empty. That is, we won't write "comment [(nothing)]"). This way,
   // users won't wonder where it came from. (It was created automatically.)
   const bool isComment = label == special::comment;
   if ((isComment || isDerivedFromComponent_v<T>) && vec.size() == 0)
      return false; // <== so that the caller won't print a newline

   const std::string lab = isComment ? "comment" : label;

   if constexpr (isDerivedFromComponent_v<T>) {
      size_t index = 0;

      // elements
      for (const auto &element : vec) {
         if (index)
            os << std::endl; // between elements
         printComponentPart(
            os, level, 0,
            lab + '[' + std::to_string(index++) + ']',
            element,
            color::vector,
            ""
         );
      }
   } else {
      // [
      indentString(os, level, colorize(lab + " [", labelColor));
      os << std::endl;

      // elements
      for (const auto &element : vec) {
         printComponentPart(
            os, level+1, 0,
            "",
            element,
            "",
            isComment ? color::comment : ""
         );
         os << std::endl; // between elements
      }

      // ]
      indentString(
         os, level,
         comments
            ? colorize("] " + colorize_comment(lab), labelColor)
            : colorize("]", labelColor)
      );
   }

   return true;
}


// ------------------------
// 6. optional
// ------------------------

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const size_t maxlen,
   const std::string &label,
   const std::optional<T> &value,
   const std::string &labelColor = "",
   const std::string &valueColor = ""
) {
   if (!value.has_value())
      return false; // <== so that the caller won't print a newline

   // label color
   const std::string clabel =
      labelColor != ""
    ? labelColor
    : isDerivedFromComponent_v<T>
    ? color::optional::field
    : isVector_v<T>
    ? color::optional::vector
    : color::optional::label;

   // value color
   const std::string cvalue =
      valueColor != "" ? valueColor : color::optional::value;

   // print
   printComponentPart(
      os, level, maxlen, label,
      value.value(),
      clabel, cvalue
   );

   return true;
}


// ------------------------
// 7. Defaulted
// ------------------------

template<class T>
bool printComponentPart(
   std::ostream &os, const int level, const size_t maxlen,
   const std::string &label,
   const Defaulted<T> &value,
   const std::string &labelColor = "",
   const std::string &valueColor = ""
) {
   // label color
   const std::string clabel =
      labelColor != ""
    ? labelColor
    : isDerivedFromComponent_v<T>
    ? color::optional::field
    : isVector_v<T>
    ? color::optional::vector
    : color::optional::label;

   // value color
   const std::string cvalue =
      valueColor != "" ? valueColor : color::optional::value;

   // print
   printComponentPart(
      os, level, maxlen, label,
      value.value(),
      clabel, cvalue
   );

   // comment
   if (comments)
      os << ' ' << colorize_comment("its default",cvalue);

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

// See compareVariant() below to understand why we have A and B,
// not T for both
template<class A, class B>
bool compareRegular(const A &a, const B &b)
{
   // Intentional: some "if ((x = y))"s below; i.e. =, not ==

   // index?
   size_t aindex = 0;  bool a_has_index = false;
   if constexpr (has_index_v<A>) {
      if constexpr (isOptional<decltype(A{}.index())>) {
         if ((a_has_index = a.index().has_value()))
            aindex = a.index().value();
      } else {
         a_has_index = true;
         aindex = a.index();
      }
   }

   size_t bindex = 0;  bool b_has_index = false;
   if constexpr (has_index_v<B>) {
      if constexpr (isOptional<decltype(B{}.index())>) {
         if ((b_has_index = b.index().has_value()))
            bindex = b.index().value();
      } else {
         b_has_index = true;
         bindex = b.index();
      }
   }

   // label?
   std::string alabel = "";  bool a_has_label = false;
   if constexpr (has_label_v<A>) {
      if constexpr (isOptional<decltype(A{}.label())>) {
         if ((a_has_label = a.label().has_value()))
            alabel = a.label().value();
      } else {
         a_has_label = true;
         alabel = a.label();
      }
   }

   std::string blabel = "";  bool b_has_label = false;
   if constexpr (has_label_v<B>) {
      if constexpr (isOptional<decltype(B{}.label())>) {
         if ((b_has_label = b.label().has_value()))
            blabel = b.label().value();
      } else {
         b_has_label = true;
         blabel = b.label();
      }
   }

   return
      // index: primary
      a_has_index && b_has_index ? aindex < bindex
    : a_has_index ? true
    : b_has_index ? false
      // label: secondary
    : a_has_label && b_has_label ? alabel < blabel
    : a_has_label ? true
    : b_has_label ? false
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
   if constexpr (has_index_v<T> || has_label_v<T>)
      std::sort(vec.begin(), vec.end(), compareRegular<T,T>);
}

// vector<variant<Ts...>>
template<class... Ts>
void sort(std::vector<std::variant<Ts...>> &vec)
{
   using T = std::variant<Ts...>;
   if constexpr (has_index_v<T> || has_label_v<T>)
      std::sort(vec.begin(), vec.end(), compareVariant<Ts...>);
}

// std::optional<vector>
template<class T>
void sort(std::optional<std::vector<T>> &opt)
{
   if (opt.has_value())
      sort(opt.value());
}


// -----------------------------------------------------------------------------
// queryResult
// -----------------------------------------------------------------------------

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


// -----------------------------------------------------------------------------
// pprintAlign
// -----------------------------------------------------------------------------

// Component::print() - the prettyprinter - uses the following in order to
// include certain constructs in Component-derived classes from its alignment
// computation, and exclude other constructs. We believe that the alignment
// just looks better, and has fewer spurious-looking spaces, when some types
// of constructs are excluded.

struct pprintAlign {
   template<class KEY>
   bool operator()(const KEY &, const void *const link) const
   {
      (void)link; // silence compiler warning if unused (per constexpr if)
      using RESULT = typename queryResult<KEY>::type;

      // [optional] vectors, component-derived classes, and data nodes
      // print in their own special manner; so, no key:value alignment.
      if constexpr (
         isVector_v<RESULT> ||
         isOptionalVector_v<RESULT> ||
         isDerivedFromComponent_v<RESULT> ||
         isDataNode<RESULT>::value)
         return false;

      // if optional (with a non-vector value, or already handled above),
      // align iff optional has value, and value isn't component-derived
      if constexpr (isOptional<RESULT>)
         return ((const RESULT *)link)->has_value() &&
            !isDerivedFromComponent_v<typename RESULT::value_type>;

      return true;
   }
};

} // namespace detail
