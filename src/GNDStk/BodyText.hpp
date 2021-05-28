
// for printing
inline std::size_t columns = 4; // there's a columns Meta<> in another namespace
inline std::size_t &across = columns; // no conflict with other-namespace name
inline bool comments = true;

// printing-related colors
#include "GNDStk/BodyText/src/colors.hpp"

// helper constructs
#include "GNDStk/BodyText/src/detail.hpp"



// -----------------------------------------------------------------------------
// BodyText<false>
// The <true> case is specialized.
// -----------------------------------------------------------------------------

template<bool hasBodyText>
class BodyText {
public:
   void fromNode(const Node &) const { }
   std::ostream &write(std::ostream &os, const int) const { return os; }
};



// -----------------------------------------------------------------------------
// BodyText<true>
// Designed to be flexible, smart, and safe. Does lots of checks, and can
// essentially "remake" itself depending on what someone tries to extract.
// For efficiency, an application might want to copy to a vector elsewhere.
// Example: auto myvec = mybodytext.get<std::vector<double>>();
// -----------------------------------------------------------------------------

// fixme The contents of this class should be split into several files

template<>
class BodyText<true> {

   // ------------------------
   // general member data
   // ------------------------

   // raw string, directly from the "plain character data" in the GNDS file
   std::string rawstring;

   // vector of (several possibilities)
   // This is mutable, so that we can reinterpret rawstring at will.
   mutable std::variant<
      // strings
      std::vector<std::string>,

      // integrals
      std::vector<signed char>,
      std::vector<short>,
      std::vector<int>,
      std::vector<long>,
      std::vector<long long>,

      // unsigned integrals
      std::vector<unsigned char>,
      std::vector<unsigned short>,
      std::vector<unsigned int>,
      std::vector<unsigned long>,
      std::vector<unsigned long long>,

      // floating-points
      std::vector<float>,
      std::vector<double>,
      std::vector<long double>
   > variant;

   // ------------------------
   // Optional values that
   // affect interpretation
   // of the raw body text
   // ------------------------

   // Quoted from the official JSON files for GNDS:
   //
   // valueType
   //    Specifies the type of data in the body (e.g., Integer32, Float64).
   //    Only one type of data can be stored in each instance of a values node.
   //
   // start
   //    default: 0
   //    For start = N, the first N values are zero and are not stored.
   //
   // length
   //    The total number of data values including leading and trailing zero
   //    values that are not stored. This attribute should only be used when
   //    the sum of start and the number of listed values do not add to the
   //    total number of data values. This should only happen when there are
   //    trailing zeros not listed in the Body text.

   // These are placed in a struct, so our setters can use the names
   struct {
      // these might or might not have been in a node with body text...
      std::string valueType = "";
      std::size_t start = 0;
      std::size_t length = 0;
      // flag, to help get<std::vector<T>>() work smoothly
      mutable bool hasZeros = false; // <== fixme May or may not want setter
   } vars;

   // flag; a setter or other function may set this to true, in order
   // to indicate that the vector must be (re)made from the raw string
   mutable bool changed = true;

public:

   // ------------------------
   // Change valueType,
   // start, or length
   // ------------------------

   // Discussion. Remember, the context here is that some class derives from
   // Component, which further derives from this class - BodyText. We're here,
   // in BodyText<true>, if the derived class has "body text". Such a derived
   // class might have valueType, start, and length (possibly as std::optional
   // or GNDStk::Defaulted), but we won't *require* it to have any of those.
   // For whichever ones the derived class has, we suggest writing setters
   // that also call these, below, so that we can handle them correctly here.

   // valueType
   auto &valueType(const std::optional<std::string> &opt)
   {
      if (opt.has_value() && opt.value() != vars.valueType) {
         // different value
         vars.valueType = opt.value();
         changed = true;
      }
      return *this;
   }

   // start
   auto &start(const std::optional<std::size_t> &opt)
   {
      if (opt.has_value() && opt.value() != vars.start) {
         vars.start = opt.value();
         changed = true;
         std::cout << "value changed" << std::endl;
      }
      return *this;
   }

   // length
   auto &length(const std::optional<std::size_t> &opt)
   {
      if (opt.has_value() && opt.value() != vars.length) {
         vars.length = opt.value();
         changed = true;
         std::cout << "length changed" << std::endl;
      }
      return *this;
   }

   // the above three together
   // Defaults are so that (not given) ==> (no effect)
   auto &set(
      const std::optional<std::string> &optv = std::nullopt,
      const std::optional<std::size_t> &opts = std::nullopt,
      const std::optional<std::size_t> &optl = std::nullopt
   ) {
      valueType(optv);
      start(opts);
      length(optl);
      return *this;
   }

   // ------------------------
   // Simple member functions
   // ------------------------

   // clear()
   // Clears whatever is the current variant alternative. (Doesn't *change*
   // the alternative to any other one.)
   void clear()
   {
      std::visit([](auto &&alt) { return alt.clear(); }, variant);
      rawstring = "";
      changed = true;
   }

   // size()
   // Actual current size of the active vector alternative in the variant.
   // Depending on what actions someone has performed on the current object,
   // size() might or might not reflect the values of start and/or length,
   // or even reflect the current contents of the raw string.
   std::size_t size() const
   {
      return std::visit([](auto &&alt) { return alt.size(); }, variant);
   }

   // ------------------------
   // get<std::vector<T>>()
   // get<T>(n)
   // ------------------------

   // Make a vector in the variant contain data from the raw string, and also
   // INCLUDE any leading and/or trailing 0s (or ""s) as determined by start
   // and length. Briefly: create [0 0 ... 0 values_from_raw_string 0 0 ... 0].

   // get<std::vector<T>>(), remaking the variant if necessary
   // Important: gets an entire vector!
   // Not to be confused with get<T>(n) for T != vector
   template<class VECTOR>
   typename std::enable_if<
      detail::is_oneof<VECTOR,decltype(variant)>::value &&
     !detail::isVariant<VECTOR>::value, // else is_oneof<the variant> passes
      const VECTOR &
   >::type get(const bool wantZeros = true) const
   {
      // vector already there?
      if (
         // nothing else (e.g. the raw data string) has changed?
         !changed &&
         // already have the (leading+trailing) or (reduced) case?
         vars.hasZeros == wantZeros &&
         // have the particular vector type we're wanting right now?
         std::holds_alternative<VECTOR>(variant)
      ) {
         return std::get<VECTOR>(variant);
      }

      // remake...
      std::cout << "remaking vector..." << std::endl;

      // initialize
      VECTOR &to = std::get<VECTOR>(variant = VECTOR{});
      using T = typename VECTOR::value_type;

      // [*****----------]
      // leading values, if any
      if (wantZeros)
         for (std::size_t i = vars.start; i-- ;) {
            if constexpr (std::is_same<T,std::string>::value)
               to.push_back("");
            else
               to.push_back(T(0));
         }

      // [-----*****-----]
      // given values
      T element;
      std::istringstream iss(rawstring);
      while (iss >> element)
         to.push_back(element);

      // [----------*****]
      // trailing values, if any
      if (wantZeros && vars.length > vars.start + to.size())
         for (std::size_t i = vars.length - (vars.start + to.size()); i-- ;) {
            if constexpr (std::is_same<T,std::string>::value)
               to.push_back("");
            else
               to.push_back(T(0));
         }

      vars.hasZeros = wantZeros;
      changed = false; // just applied changes
      return to;
   }

   // The following can actually trigger a complete remake of the vector if
   // it isn't already vector<T> for the given type T. This is intentional,
   // in order to provide maximum flexibility. However, be aware of it, for
   // the sake of efficiency! In general, when using the present class, we
   // recommend sticking with one underlying type. Say, calling the above as
   // get<std::vector<double>>(), or one of the following with get<double>(n).

   // get<T>(n), const
   template<class T>
   typename std::enable_if<
      detail::is_oneof<std::vector<T>,decltype(variant)>::value,
      const T &
   >::type get(const std::size_t n, const bool wantZeros = true) const
   {
      try {
         return get<std::vector<T>>(wantZeros)[n];
      } catch (...) {
         log::member("BodyText::get<T>({})", n);
         throw;
      }
   }

   // ------------------------
   // get()
   // ------------------------

   const auto &get(const bool wantZeros = true) const
   {
      // fixme Think about other possibilities...
      if (vars.valueType == "Integer32")
         get<std::vector<Integer32>>(wantZeros);
      else if (vars.valueType == "Float64")
         get<std::vector<Float64>>(wantZeros);
      else
         get<std::vector<std::string>>(wantZeros);

      // Can't return the specific variant *alternative* in this one function,
      // so just return the whole variant.
      return variant;
   }

   // ------------------------
   // fromNode
   // ------------------------

   void fromNode(const Node &node)
   {
      // optional data type and start/length
      valueType(node(std::optional<std::string>{""} / Meta<>{"valueType"}));
      start    (node(std::optional<std::size_t>{0 } / Meta<>{"start"    }));
      length   (node(std::optional<std::size_t>{0 } / Meta<>{"length"   }));

      // body text
      bool found = false;
      rawstring = node.pcdata(found);
      changed = true;

      if (!found) {
         rawstring = "";
         // Warning: so, why are we in BodyText<true> if there's no body text?
         // Of course, it's possible that start or length is nonzero, so that
         // the values are all *supposed* to be "" or 0. :-/
         log::warning(
            "Component marked as having \"body text\", a.k.a. XML \"pcdata\" "
            "(plain\ncharacter data), but none was found in the GNDS node."
         );
         log::member("BodyText::fromNode(Node, with name \"{}\")", node.name);
      }

      get();
   }

   // ------------------------
   // getters
   // ------------------------

   // get the raw string
   // Not to be confused with strings() (plural), which returns vector<string>.
   const std::string &string() const { return rawstring; }

   // vectors
   // fixme Write shorthand access to get<various Ts>

   // ------------------------
   // setters
   // ------------------------

   // set the raw string
   const std::string &string(const std::string &str)
   {
      clear();
      changed = true;
      return rawstring = str;
   }

   // vectors
   // fixme Write shorthand access to get<various Ts>

   // ------------------------
   // write
   // ------------------------

   std::ostream &write(std::ostream &os, const int level) const
   {
      if (changed || (size() == 0 && rawstring != ""))
         get();

      if (size() == 0)
         return os;

      std::visit(
         [&os,level](auto &&alt)
         {
            const auto indent = std::string(GNDStk::indent*level,' ');
            std::size_t count = 0;

            for (auto &element : alt) {
               count == 0
                  ? os << indent
                  : GNDStk::across == 0 || count % GNDStk::across
                  ? os << ' '
                  : os << '\n' << indent;

               GNDStk::color && GNDStk::colors::value != ""
                  ? os << colors::value << element << colors::reset
                  : os << element;

               count++;
            };
         },
         variant
      );

      return os << std::endl;
   }

}; // class BodyText
