
// For printing.
// When writing a Component with its generic write() function (or its stream
// output, which uses write()), and the Component is based on a BodyText with
// body text, values will be printed in GNDStk::columns columns. "columns" is
// aliased to "across" for convenience, because, at the time of this writing,
// GNDStk has a Meta<> object of the same name, which is also in scope if the
// core namespace is used.
inline std::size_t columns = 4;
inline std::size_t &across = columns;

// Also for printing.
// Should Component's generic write() function emit comments?
inline bool comments = true;

// Printing-related colors.
// Eventually this probably belongs in a more context-agnostic location, such
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
   template<class CONTENT>
   void sync(const CONTENT &) { }

   void fromNode(const Node &) { }
   void toNode(Node &) const { }

   std::ostream &write(std::ostream &os, const int) const { return os; }
};


// -----------------------------------------------------------------------------
// BodyText<true>
// Designed to be flexible, smart, and safe. Does lots of checks, and can
// essentially "remake" itself depending on what someone tries to extract.
// For efficiency, an application might want to copy to a vector elsewhere.
// Example: auto myvec = mybodytext.get<std::vector<double>>().
// -----------------------------------------------------------------------------

template<>
class BodyText<true> {

   // Primary "body text" data
   // Raw string, and variant of several vector possibilities
   #include "GNDStk/BodyText/src/data.hpp"

   // Parameters that affect interpretation of the raw string
   // In struct vars: length, start, and valueType
   #include "GNDStk/BodyText/src/params.hpp"

public:

   // Flags that users are welcome to set
   // remake, trim
   #include "GNDStk/BodyText/src/flags.hpp"

   // Setters for length, start, and valueType
   #include "GNDStk/BodyText/src/setter.hpp"

   // Simple member functions
   // clear, size(), and getter/setter for the raw string
   #include "GNDStk/BodyText/src/function.hpp"

   // Various get() functions, including type-specific ones (doubles() etc.)
   #include "GNDStk/BodyText/src/get.hpp"

   // zzz working here

   // Read/write data from/to Node
   #include "GNDStk/BodyText/src/fromNode.hpp"
   #include "GNDStk/BodyText/src/toNode.hpp"

   // Write to ostream
   #include "GNDStk/BodyText/src/write.hpp"

   // zzz Do we still need this, or need it in this form?
   // sync
   template<class CONTENT>
   void sync(const CONTENT &content)
   {
      if constexpr (detail::has_length<CONTENT>::value)
         this->length(content.length);
      if constexpr (detail::has_start<CONTENT>::value)
         this->start(content.start);
      if constexpr (detail::has_valueType<CONTENT>::value)
         this->valueType(content.valueType);
   }

   // Assignment
   // To vectors and to string; the latter == calling our raw string setter
   /////   #include "GNDStk/BodyText/src/assign.hpp"

}; // class BodyText
