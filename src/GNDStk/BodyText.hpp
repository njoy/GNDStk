
// For printing.
// When writing a Component with its generic write() function (or its stream
// output, which uses write()), and the Component is based on a BodyText<true>,
// values will be printed in GNDStk::columns columns. "columns" is aliased to
// "across" for convenience, because, at the time of this writing, GNDStk has
// a Meta<> object, named "columns", which will also be in scope if the core
// namespace is used.
inline std::size_t columns = 4;
inline std::size_t &across = columns;

// Printing-related colors.
// Eventually, this probably belongs in a more context-agnostic location such
// as GNDStk's utility.hpp file or another file like it.
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
   void fromNode(const Node &) { }
   void toNode(Node &) const { }

   std::ostream &write(std::ostream &os, const int) const { return os; }

   template<class CONTENT>
   void pullFromDerived(const CONTENT &) { }
   template<class CONTENT>
   void pushToDerived(CONTENT &) const { }
};


// -----------------------------------------------------------------------------
// BodyText<true>
// Designed to be flexible, smart, and safe. Does lots of checks, and can
// essentially "remake" itself depending on what someone tries to extract.
// For efficiency, an application might want to copy to a vector elsewhere,
// for example with auto myvec = mybodytext.get<std::vector<double>>(), do
// work on (or with) the vector there, then copy it back.
// -----------------------------------------------------------------------------

template<>
class BodyText<true> {

   // Primary data:
   // Raw string, and variant of several vector possibilities
   #include "GNDStk/BodyText/src/data.hpp"

   // Parameters that affect interpretation of the raw string:
   // In struct vars: length, start, and valueType
   #include "GNDStk/BodyText/src/params.hpp"

public:

   // Flags that users are welcome to set:
   // remake, trim
   #include "GNDStk/BodyText/src/flags.hpp"

   // Setters for length, start, and valueType:
   #include "GNDStk/BodyText/src/setters.hpp"

   // Getters and setters for the raw string:
   #include "GNDStk/BodyText/src/string.hpp"

   // Simple member functions
   // clear(), size(), and a getter and a setter for the raw string
   #include "GNDStk/BodyText/src/functions.hpp"

   // Various get() functions, including type-specific ones (doubles() etc.)
   #include "GNDStk/BodyText/src/get.hpp"

   // Read/write data from/to a Node
   #include "GNDStk/BodyText/src/fromNode.hpp"
   #include "GNDStk/BodyText/src/toNode.hpp"

   // Write to ostream
   // Not to be confused with writing to a Node
   #include "GNDStk/BodyText/src/write.hpp"

   // Get length, start, and valueType from derived-class content,
   // or possibly put them there (if we determined them from a vector)
   #include "GNDStk/BodyText/src/sync.hpp"

   // Assignment
   // From vectors or a string; the latter == calling our raw string setter
   #include "GNDStk/BodyText/src/assign.hpp"

}; // class BodyText
