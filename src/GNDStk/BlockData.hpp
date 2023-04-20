
// Printing style
enum class PrintMode {
   cpp,
   python
};
inline PrintMode printMode = PrintMode::cpp;

// Printing-related colors.
// todo Eventually, this probably belongs in a more context-agnostic
// location, such as GNDStk's utility.hpp file or something like it.
#include "GNDStk/BlockData/src/colors.hpp"

// Miscellaneous helper constructs.
#include "GNDStk/BlockData/src/detail.hpp"


// -----------------------------------------------------------------------------
// BlockData<false,DATATYPE>
// The <true,DATATYPE> case is specialized and has the fun stuff. This one
// needs just a bit of content, to allow for uniform treatment of BlockData.
// -----------------------------------------------------------------------------

template<bool hasBlockData, class DATATYPE>
class BlockData {
public:
   using VariantOfVectors = std::variant<std::monostate>;
   using VariantOfScalars = std::variant<std::monostate>;
   static inline constexpr bool runtime = false;
   template<class T>
   static inline constexpr bool supported = false;
};


// -----------------------------------------------------------------------------
// BlockData<true,DATATYPE>
//
// Designed to be flexible, smart, and safe. Does lots of checks, and, for the
// DATATYPE == void case, can essentially re-form itself depending on what type
// of data someone tries to extract.
//
// For efficiency in the DATATYPE == void case, an application may want to copy
// to its own vector (e.g. auto myvec = myblockdata.get<std::vector<double>>())
// in order to do work on (or with) the vector there, before copying it back.
// -----------------------------------------------------------------------------

template<class DATATYPE>
class BlockData<true,DATATYPE> {
public:

   #include "GNDStk/BlockData/src/types.hpp"

   // For convenience in various SFINAE and if-constexpr constructs
   static inline constexpr bool runtime = detail::isVoid<DATATYPE>;
   template<class T>
   struct is_supported {
      static inline constexpr bool value =
         ( runtime && detail::isAlternative<T,VariantOfScalars>) ||
         (!runtime && (
            std::is_constructible_v<DATATYPE,T> ||
            std::is_convertible_v<T,DATATYPE>
         ));
   };
   template<class T>
   static inline constexpr bool supported = is_supported<T>::value;

   enum class Active { string, vector };

private:

   // For internal use
   mutable Active act = Active::string;

   // Raw string, directly from "plain character data" in a GNDS file.
   // We'll allow callers to set this by using a setter.
   std::string rawstring;

   // Vector of <several possibilities>.
   // *** This will be used if, and only if, DATATYPE == void.
   // Mutable, so that we can defer processing of the raw string into
   // a vector until, and unless, a caller *asks* for the vector.
   mutable VariantOfVectors variant;

   // Vector of <DATATYPE>
   // *** This will be used if, and only if, DATATYPE != void.
   // data_t is used in a few places where, without it, we'd create compilation
   // errors by using "void" in invalid ways. The "int" below is arbitrary -
   // basically a placeholder - because the following is used only if !runtime.
   using data_t = std::conditional_t<runtime,int,DATATYPE>;
   mutable std::vector<data_t> vector;

public:

   // Parameters that affect interpretation of the raw string:
   //    struct vars { length, start, valueType }
   // Includes public getters and setters for those.
   // We won't use valueType if DATATYPE != void.
   #include "GNDStk/BlockData/src/params.hpp"

   // trim
   // Flag: should the conversion of BlockData data back into textual data,
   // in a Node, trim zeros from the start and end of the output?
   mutable bool trim = true;

   // Getters and setters for the raw string:
   #include "GNDStk/BlockData/src/string.hpp"

   // active()
   Active active() const { return act; }

   // clear()
   // Clears the vector, or the active vector alternative in the variant.
   BlockData &clear()
   {
      if constexpr (runtime)
         std::visit([](auto &&alt) { alt.clear(); }, variant);
      else
         vector.clear();

      act = Active::vector;
      return *this;
   }

   // size()
   // Returns the size of the vector, or of the active vector alternative in
   // the variant. Depending on what someone may or may not have done with the
   // current BlockData object, size() might or might not reflect the values of
   // length and/or start, or reflect the current contents of the raw string.
   size_t size() const
   {
      if constexpr (runtime)
         return std::visit([](auto &&alt) { return alt.size(); }, variant);
      else
         return vector.size();
   }

   // Various vector get() functions, and the type-specific doubles() etc.
   #include "GNDStk/BlockData/src/get.hpp"

   // Read/write data, from/to a Node
   #include "GNDStk/BlockData/src/fromNode.hpp"
   #include "GNDStk/BlockData/src/toNode.hpp"

   // Print to ostream
   #include "GNDStk/BlockData/src/print.hpp"

   // Pull/push length/start/valueType from/to derived-class object
   #include "GNDStk/BlockData/src/sync.hpp"

   // Assignment
   // From string or vector; the former == calling our raw string setter
   #include "GNDStk/BlockData/src/assign.hpp"

   // Conversion to vector<DATATYPE>
   // *** Available if, and only if, DATATYPE != void.
   template<
      class T = DATATYPE,
      class = std::enable_if_t<!runtime && std::is_same_v<T,DATATYPE>>
   >
   operator std::vector<T>() const
   {
      // get(), not vector; get() handles properly if the string is active
      return get();
   }

}; // class BlockData<true,DATATYPE>
