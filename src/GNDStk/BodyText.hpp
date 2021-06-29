
// For printing.
// When writing a Component with its generic write() function (or its stream
// output, which uses write()), and the Component is based on a BodyText<true>,
// values will be printed in GNDStk::columns columns. "columns" is aliased to
// "across" for convenience, because, at the time of this writing, GNDStk has
// a Meta<> object, named "columns", which would also be in scope if the core
// namespace is used. So, a user might prefer to use "across".
inline std::size_t columns = 4;
inline std::size_t &across = columns;

// Printing-related colors.
// Eventually, this probably belongs in a more context-agnostic location such
// as GNDStk's utility.hpp file or something like it.
#include "GNDStk/BodyText/src/colors.hpp"

// Miscellaneous helper constructs.
#include "GNDStk/BodyText/src/detail.hpp"


// -----------------------------------------------------------------------------
// BodyText<false>
// The <true> case is specialized and has the fun stuff. This one needs various
// functions, to facilitate uniform treatment of BodyText, but they're stubs.
// -----------------------------------------------------------------------------

template<bool hasBodyText>
class BodyText {
public:
   using variant_t = std::variant<std::monostate>;

   void fromNode(const Node &) { }

   template<class CONTENT>
   void toNode(Node &, const CONTENT &) const { };
   template<class CONTENT>
   void toNode(Node &, CONTENT &) { };

   std::ostream &write(std::ostream &os, const int) const { return os; }

   template<class CONTENT>
   void pullFromDerived(const CONTENT &) { }

   template<class CONTENT>
   void pushToDerived(CONTENT &) const { }
};


// -----------------------------------------------------------------------------
// BodyText<true>
// Designed to be flexible, smart, and safe. Does lots of checks, and can
// essentially re-form itself depending on what someone tries to extract.
// For efficiency, an application might want to copy to a vector elsewhere,
// for example with auto myvec = mybodytext.get<std::vector<double>>() to
// do work on (or with) the vector there before copying it back.
// -----------------------------------------------------------------------------

template<>
class BodyText<true> {

   // Primary data:
   // Raw string, and variant of vectors
   #include "GNDStk/BodyText/src/data.hpp"

   // Parameters that affect interpretation of the raw string:
   // vars { length, start, and valueType }
   #include "GNDStk/BodyText/src/params.hpp"

public:

   enum class Active {
      string,
      vector
   };
   mutable Active active = Active::string;

   // trim
   // This indicates whether the process of converting a BodyText object back
   // into data - in a Node - should, or should not, trim zeros from the start
   // and/or the end of the vector.
   mutable bool trim = true;

   // Getters and setters for length, start, and valueType:
   #include "GNDStk/BodyText/src/setters.hpp"

   // Getters and setters for the raw string:
   #include "GNDStk/BodyText/src/string.hpp"

   // Simple member functions:
   // clear() and size()
   #include "GNDStk/BodyText/src/functions.hpp"

   // Various get() functions, including type-specific ones (doubles() etc.)
   #include "GNDStk/BodyText/src/get.hpp"

   // Read/write data from/to a Node
   #include "GNDStk/BodyText/src/fromNode.hpp"
   #include "GNDStk/BodyText/src/toNode.hpp"

   // Write to ostream
   // Not to be confused with the process of writing data to a Node
   #include "GNDStk/BodyText/src/write.hpp"

   // Get length, start, and valueType from derived-class content,
   // or possibly put them there (if we determined them from a vector)
   #include "GNDStk/BodyText/src/sync.hpp"

   // Assignment
   // From vector or string; the latter == calling our raw string setter
   #include "GNDStk/BodyText/src/assign.hpp"

}; // class BodyText
