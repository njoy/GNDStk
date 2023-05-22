
// A forward declaration of Component is needed by some detail constructs
template<class DERIVED, bool hasBlockData = false, class DATATYPE = void>
class Component;

#include "GNDStk/Component/src/detail-sfinae.hpp"
#include "GNDStk/Component/src/detail-getter.hpp"
#include "GNDStk/Component/src/detail.hpp"

// Map from some term/subject to its documentation. For use by classes that
// derive from Component, and in particular for use in Python bindings.
using helpMap = std::map<std::string,std::string>;


// -----------------------------------------------------------------------------
// Noop (class)
// noop (object)
// To represent "no-op[eration]".
// -----------------------------------------------------------------------------

// At the moment, this is designed to provide a "do-nothing converter" that
// might be used in Component-based classes. We might eventually extend its
// contents in a way that supports other uses of the "no-op" concept.

struct Noop {
   template<class FROM, class TO>
   bool operator()(const FROM &, TO &) const
   {
      // No action. And, in the context of Node's add() functions, a
      // return value of false means nothing will be added after all.
      return false;
   }
};

inline const Noop noop;


// -----------------------------------------------------------------------------
// Component
// -----------------------------------------------------------------------------

template<class DERIVED, bool hasBlockData, class DATATYPE>
class Component : public BlockData<hasBlockData,DATATYPE>
{
   template<class COMPONENT, class FROM, class MC>
   friend bool detail::added(
      const COMPONENT &, const FROM &, const MC &, const bool, const size_t
   );

   template<class, class, class>
   friend class detail::bracket;

   // Links to fields in the object of the derived class. I can't find a way
   // to do this in a decltype(DERIVED::KEYS())-aware manner, because DERIVED
   // is generally an incomplete type *here* - outside of Component's member
   // functions. So, we'll do it the old-fashioned way.
   std::vector<void *> links;

   // Fallback for documentation() if DERIVED doesn't have help
   static inline helpMap help;

   // For convenience
   using BLOCKDATA = BlockData<hasBlockData,DATATYPE>;
   using typename BLOCKDATA::VariantOfVectors;
   using typename BLOCKDATA::VariantOfScalars;

   // Keys()
   static const auto &Keys()
   {
      static const auto value = makeKeyTuple(DERIVED::KEYS());
      return value;
   }

   // Constructors and assignment operators. Intentionally private.
   #include "GNDStk/Component/src/ctor.hpp"
   #include "GNDStk/Component/src/assign.hpp"

   // finish
   // Helpers for the constructors
   #include "GNDStk/Component/src/finish.hpp"

   // Helpers for derived-class getters and setters.
   // These allow us to shorten some other code.
   #include "GNDStk/Component/src/getter.hpp"
   #include "GNDStk/Component/src/setter.hpp"

public:

   #include "GNDStk/Component/src/read.hpp"
   #include "GNDStk/Component/src/write.hpp"
   #include "GNDStk/Component/src/print.hpp"
   #include "GNDStk/Component/src/fromNode.hpp"
   #include "GNDStk/Component/src/sort.hpp"
   #include "GNDStk/Component/src/toNode.hpp"
   #include "GNDStk/Component/src/convert.hpp"
   #include "GNDStk/Component/src/has.hpp"
   #include "GNDStk/Component/src/call.hpp"
   #include "GNDStk/Component/src/io-string.hpp"

   // For use in DERIVED
   template<class, class> class FieldPart { /* nothing; see specialization */ };
   #include "GNDStk/Component/src/field.hpp"
   #include "GNDStk/Component/src/fieldPart.hpp"
   #include "GNDStk/Component/src/wrapper.hpp"

   // Forwards, where viable and unambiguous, to certain capabilities
   // in DERIVED's fields
   #include "GNDStk/Component/src/forward.hpp"

   // Namespace, Class
   static std::string Namespace() { return DERIVED::NAMESPACE(); }
   static std::string Class() { return DERIVED::CLASS(); }

   // documentation
   static std::string documentation(const std::string &subject = "")
   {
      try {
         return DERIVED::help.at(subject);
      } catch (...) {
         return "No help information is available";
      }
   }

   // DERIVED's vector base, if applicable
   template<
      class D = DERIVED,
      class = std::enable_if_t<detail::isDerivedFromVector_v<D>>
   >
   auto &vector()
   {
      using VECTOR = detail::isDerivedFromVector_t<D>;
      return static_cast<VECTOR &>(derived());
   }

   // ------------------------
   // Shorthand access...
   // ------------------------

   // To the BlockData base class
   BLOCKDATA &baseBlockData() { return *this; }
   const BLOCKDATA &baseBlockData() const { return *this; }

   // To the Component base class (of the derived class)
   Component &baseComponent() { return *this; }
   const Component &baseComponent() const { return *this; }

   // To the derived class
   DERIVED &derived()
      { return static_cast<DERIVED &>(*this); }
   const DERIVED &derived() const
      { return static_cast<const DERIVED &>(*this); }

private:

   // Helper: fieldAddress
   template<class T> void *fieldAddress(      T  &value) { return &value  ; }
   template<class T> void *fieldAddress(Field<T> &field) { return &field(); }

   // Helper: stripField
   template<class T> struct stripField           { using type = T; };
   template<class T> struct stripField<Field<T>> { using type = T; };
}; // class Component


// -----------------------------------------------------------------------------
// Stream I/O
// -----------------------------------------------------------------------------

#include "GNDStk/Component/src/io-stream.hpp"
