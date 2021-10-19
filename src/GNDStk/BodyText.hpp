
// Printing-related colors.
// todo Eventually, this probably belongs in a more context-agnostic
// location, such as GNDStk's utility.hpp file or something like it.
#include "GNDStk/BodyText/src/colors.hpp"

// Miscellaneous helper constructs.
#include "GNDStk/BodyText/src/detail.hpp"


// -----------------------------------------------------------------------------
// BodyText<false,DATA>
// The <true,DATA> case is specialized and has the fun stuff. This one needs
// just a bit of content, in order to facilitate uniform treatment of BodyText.
// -----------------------------------------------------------------------------

template<bool hasBodyText, class DATA>
class BodyText {
public:
   using VariantOfVectors = std::variant<std::monostate>;
   using VariantOfScalars = std::variant<std::monostate>;
};


// -----------------------------------------------------------------------------
// BodyText<true,DATA>
//
// Designed to be flexible, smart, and safe. Does lots of checks, and, for the
// DATA == void case, can essentially re-form itself depending on what type of
// data someone tries to extract.
//
// For efficiency in the DATA == void case, an application might want to copy
// to its own vector (e.g. auto myvec = mybodytext.get<std::vector<double>>())
// in order to do work on (or with) the vector there, before copying it back.
// -----------------------------------------------------------------------------

template<class DATA>
class BodyText<true,DATA> {
public:

   #include "GNDStk/BodyText/src/types.hpp"

private:

   // For internal use
   enum class Active { string, vector };
   mutable Active active = Active::string;

   // For convenience in various SFINAE and if-constexpr constructs
   static inline constexpr bool runtime = detail::isVoid<DATA>;
   template<class T>
   struct is_supported {
      static inline constexpr bool value =
         ( runtime && detail::isAlternative<T,VariantOfScalars>) ||
         (!runtime && std::is_same_v<T,DATA>);
   };
   template<class T>
   static inline constexpr bool supported = is_supported<T>::value;

   // Raw string, directly from "plain character data" in a GNDS file.
   // We'll allow callers to set this by using a setter.
   std::string rawstring;

   // Vector of <several possibilities>.
   // Mutable, so that we can defer processing of the raw string into
   // a vector until, and unless, a caller *asks* for the vector.
   // This will be used if, and only if, DATA == void.
   mutable VariantOfVectors variant;

   // Vector of <DATA>
   // This will be used if, and only if, DATA != void.
   // data_t is used in a few places where, without it, we'd create compilation
   // errors by using "void" in invalid ways. The "int" below is arbitrary -
   // essentially a placeholder; the following is only used when !runtime.
   using data_t = std::conditional_t<runtime,int,DATA>;
   mutable std::vector<data_t> vector;

public:

   // Parameters that affect interpretation of the raw string:
   //    struct vars { length, start, valueType }
   // Includes public getters and setters for those.
   // We won't use valueType if DATA != void.
   #include "GNDStk/BodyText/src/params.hpp"

   // trim
   // Flag: should the conversion of BodyText data back into textual data,
   // in a Node, trim zeros from the start and end of the output?
   mutable bool trim = true;

   // Getters and setters for the raw string:
   #include "GNDStk/BodyText/src/string.hpp"

   // clear()
   // Clears the vector, or the active vector alternative in the variant.
   BodyText &clear()
   {
      if constexpr (runtime)
         std::visit([](auto &&alt) { alt.clear(); }, variant);
      else
         vector.clear();

      active = Active::vector;
      return *this;
   }

   // size()
   // Returns the size of the vector, or of the active vector alternative in
   // the variant. Depending on what someone may or may not have done with the
   // current BodyText object, size() might or might not reflect the values of
   // length and/or start, or reflect the current contents of the raw string.
   std::size_t size() const
   {
      if constexpr (runtime)
         return std::visit([](auto &&alt) { return alt.size(); }, variant);
      else
         return vector.size();
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

}; // class BodyText<true,DATA>
