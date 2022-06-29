
// Forward declaration, needed by some things later
template<class DERIVED, bool hasBlockData = false, class DATATYPE = void>
class Component;

namespace detail {

// -----------------------------------------------------------------------------
// colorize_*(text)
// -----------------------------------------------------------------------------

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
   class = std::enable_if_t<IsStringOrRegex<T>::value>
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

// class
template<class DERIVED>
class HasWriteOneArg
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

// variable - use this
template<class DERIVED>
inline constexpr bool hasWriteOneArg = HasWriteOneArg<DERIVED>::has;

// class
template<class DERIVED>
class HasWriteTwoArg
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

// variable - use this
template<class DERIVED>
inline constexpr bool hasWriteTwoArg = HasWriteTwoArg<DERIVED>::has;



// -----------------------------------------------------------------------------
// writeComponentPart
// -----------------------------------------------------------------------------

// Cases:
//    std::string
//    T
//    std::optional<T>
//    Defaulted<T>
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

template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const std::vector<T> &vec,
   const std::string &label, const std::size_t maxlen,
   const std::string &color = ""
);


// ------------------------
// for string
// ------------------------

inline bool writeComponentPart(
   std::ostream &os, const int level, const std::string &str,
   const std::string &label, const std::size_t maxlen,
   const std::string &color
) {
   indentString(os,level);

   if (label != "") {
      os << colorize(label,color);
      if (maxlen != 0)
         os << std::string(maxlen-label.size(),' ');
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

// helper
// is_base_of_Component
// Adapted from an answer here:
// https://stackoverflow.com/questions/34672441
template<class T>
class is_base_of_Component {
   template<class A, bool B, class C>
   static constexpr std::true_type test(Component<A,B,C> *);
   static constexpr std::false_type test(...);
   using type = decltype(test(std::declval<T *>()));
public:
   static constexpr bool value = type::value;
};

template<class T>
bool writeComponentPart(
   std::ostream &os, const int level, const T &value,
   const std::string &label, const std::size_t maxlen,
   const std::string &color
) {
   if constexpr (is_base_of_Component<T>::value) {
      // Suppress "unused parameter" warnings
      (void)value; (void)maxlen;
      (void)label; (void)color;
      // T is derived from Component, and thus inherits a write()
      value.write(os,level);
   } else {
      // T is any old type, not derived from Component
      if constexpr (std::is_floating_point_v<T>) {
         writeComponentPart(
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
         writeComponentPart(os, level, str, label, maxlen, color);
      }
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
      std::string str;
      convert_t{}(def.get_default(),str);
      writeComponentPart(
         os, level,
         colorize_comment("// defaulted; is its default (" + str + ")"),
         label, maxlen, colors::defaulted
      );
   } else
      return false; // <== caller won't print newline
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

// -----------------------------------------------------------------------------
// getter(vector, index, ...)
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

      if constexpr (hasIndex<T>) {
         // hasIndex<T>
         // T (or at least one alternative in T, if T is a variant) has a
         // metadatum called "index". In this case, this function's size_t
         // index parameter is interpreted to mean: find the object with
         // an "index" metadatum that matches the parameter. Importantly,
         // then, index in this case is ***NOT*** a C++ [index] index!

         // fixme Make the following more efficient, e.g. by assuming that the
         // vector's elements are sorted by index, so that the wanted value is
         // likely to be found at [index], even though (as stated above) [index]
         // is not the interpretation here...
         const T *selected = nullptr;

         for (auto &v : vec) {
            const T *ptr = nullptr;

            if constexpr (isVariant<T>::value) {
               // T == variant
               std::visit(
                  [&v,&index,&ptr](auto &&alternative)
                  {
                     if constexpr (hasIndex<decltype(alternative)>)
                        if (alternative.index() == index)
                           ptr = &v;
                  },
                  v
               );
            } else {
               // T != variant
               if constexpr (hasIndex<T>)
                  if (v.index() == index)
                     ptr = &v;
            }

            if (!ptr)
               continue;

            if (selected) {
               log::warning(
                 "Element with metadatum \"index\" {} was already found "
                 "in the vector.\n"
                 "Keeping the first element that was found.",
                  index
               );
               log::member(context, nsname, clname, field, index);
            } else
               selected = ptr;
         } // for

         if (!selected) {
            log::error(
              "Element with metadatum \"index\" {} was not found "
              "in the vector" + std::string(vec.size()
                  ? "."
                  : ";\nin fact the vector is empty."),
               index
            );
            throw std::exception{};
         }
         return *selected;

      } else {

         // !hasIndex<T>
         // No "index" is anywhere to be found in T. Here, then, we interpret
         // this function's index parameter to be a regular, C++ [index] index.
         if (!(index < vec.size())) {
            log::error(
              "Index {} is out of range; vector size is {}.",
               vec.size());
            throw std::exception{};
         }
         return vec[index];
      }

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
// getter(vector, label, ...)
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
                  if constexpr (hasLabel<decltype(alternative)>)
                     if (alternative.label() == label)
                        ptr = &v;
               },
               v
            );
         } else {
            // T != variant
            if constexpr (hasLabel<T>)
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
// getter(optional<vector>, index or label, ...)
// As earlier, but for optional<vector> data member.
// -----------------------------------------------------------------------------

// const
template<
   class T, class LOOKUP,
   class = std::enable_if_t<
      std::is_convertible_v<LOOKUP,std::size_t> ||
      std::is_convertible_v<LOOKUP,std::string>
   >
>
const T &getter(
   const std::optional<std::vector<T>> &opt,
   const LOOKUP &index_or_label,
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
      return getter((*opt), index_or_label, nsname, clname, field);
   } catch (...) {
      // context
      log::member(
         std::is_convertible_v<LOOKUP,std::size_t>
            ? "getter {}::{}.{}({}) on optional<vector>"
            : "getter {}::{}.{}(\"{}\") on optional<vector>",
         nsname, clname, field, index_or_label);
      throw;
   }
}

// non-const
template<
   class T, class LOOKUP,
   class = std::enable_if_t<
      std::is_convertible_v<LOOKUP,std::size_t> ||
      std::is_convertible_v<LOOKUP,std::string>
   >
>
T &getter(
   std::optional<std::vector<T>> &opt,
   const LOOKUP &index_or_label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(opt), index_or_label, nsname, clname, field)
   );
}



// -----------------------------------------------------------------------------
// getter<T>(...)
// With caller-specified type, when variant is involved
// -----------------------------------------------------------------------------

// ------------------------
// variant,...
// ------------------------

template<
   class T,
   class... Ts,
   class = std::enable_if_t<detail::isAlternative<T,std::variant<Ts...>>>
>
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
// vector<variant>,
// index or label,
// ...
// ------------------------

// The (size_t index) and (string label) cases were similar enough that
// we were able to combine them into one function.

template<
   class T, class LOOKUP,
   class = std::enable_if_t<
      std::is_convertible_v<LOOKUP,std::size_t> ||
      std::is_convertible_v<LOOKUP,std::string>
   >,
   class... Ts
>
const T *getter(
   const std::vector<std::variant<Ts...>> &vec,
   const LOOKUP &index_or_label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return getter<T>(
         // no <T>, so it calls getter(generic vector); it isn't recursive
         getter(vec, index_or_label, nsname, clname, field), // scalar variant
         nsname, clname, field
      );
   } catch (...) {
      // context
      log::member(
         std::is_convertible_v<LOOKUP,std::size_t>
            ? "getter {}::{}.{}({}) on vector<variant>"
            : "getter {}::{}.{}(\"{}\") on vector<variant>",
         nsname, clname, field, index_or_label);
      throw;
   }
}



// -----------------------------------------------------------------------------
// For sorting derived-class fields based on index and label, if and when one
// or the other of those is determined to be present. That determination hinges
// on both a compile-time check that the classes involved even *have* index or
// label fields in their content struct, and if they do, if either of those is
// possibly a std::optional that may or may not contain a value at the moment.
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
      if constexpr (isOptional<decltype(A{}.content.index)>) {
         if ((ahasindex = a.content.index.has_value()))
            aindex = a.content.index.value();
      } else {
         ahasindex = true;
         aindex = a.content.index;
      }
   }

   std::size_t bindex = 0;  bool bhasindex = false;
   if constexpr (hasIndex<B>) {
      if constexpr (isOptional<decltype(B{}.content.index)>) {
         if ((bhasindex = b.content.index.has_value()))
            bindex = b.content.index.value();
      } else {
         bhasindex = true;
         bindex = b.content.index;
      }
   }

   // label?
   std::string alabel = "";  bool ahaslabel = false;
   if constexpr (hasLabel<A>) {
      if constexpr (isOptional<decltype(A{}.content.label)>) {
         if ((ahaslabel = a.content.label.has_value()))
            alabel = a.content.label.value();
      } else {
         ahaslabel = true;
         alabel = a.content.label;
      }
   }

   std::string blabel = "";  bool bhaslabel = false;
   if constexpr (hasLabel<B>) {
      if constexpr (isOptional<decltype(B{}.content.label)>) {
         if ((bhaslabel = b.content.label.has_value()))
            blabel = b.content.label.value();
      } else {
         bhaslabel = true;
         blabel = b.content.label;
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
      // equal
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

} // namespace detail
