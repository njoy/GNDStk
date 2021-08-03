
// For printing.
// When writing a Component with its generic write() function (or its stream
// output, which uses write()), and the Component is based on a BodyText<true>,
// values will be printed with GNDStk::columns across. "columns" is aliased to
// "across" for convenience, because, at the time of this writing, GNDStk has
// a Meta<> object, named "columns", which would also be in scope if the core
// namespace is used. So, a user might prefer to use the name "across".
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
// The <true> case is specialized and has the fun stuff. This one needs a few
// stub functions just to facilitate uniform treatment of BodyText.
// -----------------------------------------------------------------------------

template<bool hasBodyText>
class BodyText {
public:
   using VariantOfVectors = std::variant<std::monostate>;
   std::ostream &write(std::ostream &os, const int) const { return os; }
   template<class CONTENT>
   void pullFromDerived(const CONTENT &) { }
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
public:

   #include "GNDStk/BodyText/src/types.hpp"

private:

   // For internal use
   enum class Active { string, vector };
   mutable Active active = Active::string;

   // Raw string, directly from "plain character data" in a GNDS file.
   // We'll allow callers to set this by using a setter.
   std::string rawstring;

   // Vector of <several possibilities>.
   // Mutable, so that we can defer processing of the raw string into
   // a vector until, and unless, a caller *asks* for the vector.
   mutable VariantOfVectors variant;

   // Parameters that affect interpretation of the raw string:
   //    struct vars { length, start, valueType }
   // Includes public getters and setters for those.
   #include "GNDStk/BodyText/src/params.hpp"

public:

   // trim
   // Flag: should the conversion of BodyText data back into textual data, in
   // a Node, trim zeros from the start and end of the output?
   mutable bool trim = true;

   // Getters and setters for the raw string:
   #include "GNDStk/BodyText/src/string.hpp"

   // clear()
   // Clears the active vector alternative in the variant.
   BodyText &clear()
   {
      std::visit([](auto &&alt) { alt.clear(); }, variant);
      return *this;
   }

   // size()
   // Returns the size of the active vector alternative in the variant.
   // Depending on what actions someone has or hasn't performed on the current
   // BodyText object, size() might or might not reflect the values of length
   // and/or start, or reflect the current contents of the raw string.
   std::size_t size() const
   {
      return std::visit([](auto &&alt) { return alt.size(); }, variant);
   }

   // Various vector get() functions, and the type-specific doubles() etc.
   #include "GNDStk/BodyText/src/get.hpp"

   // Read/write data, from/to a Node
   #include "GNDStk/BodyText/src/fromNode.hpp"
   #include "GNDStk/BodyText/src/toNode.hpp"

   // Write to ostream
   // Not to be confused with the process of writing data to a Node
   #include "GNDStk/BodyText/src/write.hpp"

   // Pull/push length/start/valueType from/to derived-class struct content
   #include "GNDStk/BodyText/src/sync.hpp"

   // Assignment
   // From string or vector; the former == calling our raw string setter
   #include "GNDStk/BodyText/src/assign.hpp"

}; // class BodyText<true>
