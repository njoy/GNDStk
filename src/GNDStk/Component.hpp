
// General helper constructs
#include "GNDStk/Component/src/detail.hpp"

// Map from some term/subject to its documentation. For use by classes that
// derive from Component, and in particular for use in Python bindings.
using helpMap = std::map<std::string,std::string>;


// -----------------------------------------------------------------------------
// Noop
// noop
// Class and object representing "no-op[eration]".
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

   // Links to fields in the object of the derived class. I can't find a way
   // to do this in a decltype(DERIVED::KEYS())-aware manner, because DERIVED
   // is generally an incomplete type *here* - outside of Component's member
   // functions. So, we'll do it the old-fashioned way.
   std::vector<void *> links;

   // This class cannot have copy or move construction. Its constructor MUST
   // know about the fields in the specific instance that derives from it.
   Component(const Component &) = delete;
   Component(Component &&) = delete;

   // Copy and move *assignments* have the right behavior, however.
   Component &operator=(const Component &other)
   {
      BLOCKDATA::operator=(other);
      return *this;
   }

   Component &operator=(Component &&other)
   {
      BLOCKDATA::operator=(std::move(other));
      return *this;
   }

   // Constructor; intentionally *private*
   #include "GNDStk/Component/src/ctor.hpp"

   // finish
   // Helpers for the constructors
   #include "GNDStk/Component/src/finish.hpp"

   // Helpers for derived-class getters and setters.
   // These allow us to shorten some other code.
   #include "GNDStk/Component/src/getter.hpp"
   #include "GNDStk/Component/src/setter.hpp"

   // Fallback for documentation() if DERIVED doesn't have help
   static inline helpMap help;

public:

   #include "GNDStk/Component/src/read.hpp"
   #include "GNDStk/Component/src/write.hpp"
   #include "GNDStk/Component/src/print.hpp"
   #include "GNDStk/Component/src/fromNode.hpp"
   #include "GNDStk/Component/src/sort.hpp"
   #include "GNDStk/Component/src/toNode.hpp"
   #include "GNDStk/Component/src/convert.hpp"

   // Access to vector base of DERIVED, if applicable
   template<
      class D = DERIVED,
      class = std::enable_if_t<detail::isDerivedFromVector_v<D>>
   >
   auto &vector()
   {
      using VECTOR = detail::isDerivedFromVector_t<D>;
      return static_cast<VECTOR &>(derived());
   }

   // Wrapper for derived-class fields
   #include "GNDStk/Component/src/field.hpp"

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

   // ------------------------
   // has
   // ------------------------

   // Note that some of these are usable in constexpr ifs.

   // constexpr, static
   // The extractor succeeds. DERIVED has a metadatum of that name.
   // No value is given. We're checking for the presence of the metadatum.
   template<
      class EXTRACTOR, class THIS = DERIVED,
      class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
   static constexpr bool has(const Lookup<LookupMode::get,EXTRACTOR,void,void> &)
   {
      return true;
   }

   // constexpr, static
   // The extractor fails. DERIVED does not have a metadatum of that name.
   // Any value to check against is meaningless here. If DERIVED doesn't
   // even have, say, .foo, then we can't check if its .foo equals the
   // one in the given Lookup.
   template<
      class EXTRACTOR, class TYPE, class CONVERTER, LookupMode GET,
      class = std::enable_if_t<GET == LookupMode::get>>
   static constexpr bool has(const Lookup<GET,EXTRACTOR,TYPE,CONVERTER> &)
   {
      return false;
   }

   // non-constexpr, non-static
   // The extractor succeeds. DERIVED has a metadatum of that name.
   // But does the value match?
   template<
      class EXTRACTOR, class TYPE, class CONVERTER, class THIS = DERIVED,
      class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
   bool has(const Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER> &from) const
   {
      return from.extractor(derived()) == from.value;
   }

   // ------------------------
   // operator()
   // ------------------------

   // These essentially provide an alternative to the has() member functions,
   // using operator() combined with the has() free functions: obj(has(...)).

   template<
      class EXTRACTOR, class THIS = DERIVED,
      class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
   constexpr bool operator()(const Lookup<LookupMode::exists,EXTRACTOR,void,void> &) const
   {
      return true;
   }

   template<
      class EXTRACTOR, class TYPE, class CONVERTER, class THIS = DERIVED,
      class = decltype(std::declval<EXTRACTOR>()(THIS{}))>
   bool operator()(const Lookup<LookupMode::exists,EXTRACTOR,TYPE,CONVERTER> &from) const
   {
      return from.extractor(derived()) == from.value;
   }

   template<
      class EXTRACTOR, class TYPE, class CONVERTER, LookupMode EXISTS,
      class = std::enable_if_t<EXISTS == LookupMode::exists>>
   constexpr bool operator()(const Lookup<EXISTS,EXTRACTOR,TYPE,CONVERTER> &) const
   {
      return false;
   }

   // ------------------------
   // String (not stream) I/O
   // ------------------------

   // Component >> string
   // Like Node >> string, but for Component's derived class.
   void operator>>(std::string &str) const
   {
      try {
         Node(*this) >> str;
      } catch (...) {
         log::function("{} >> string", Class());
         throw;
      }
   }

   // Component << string
   // Like Node << string, but for Component's derived class.
   void operator<<(const std::string &str)
   {
      try {
         Node node;
         node << str;
         derived() = DERIVED(node);
      } catch (...) {
         log::function("{} << string", Class());
         throw;
      }
   }
}; // class Component


// -----------------------------------------------------------------------------
// Stream I/O
// -----------------------------------------------------------------------------

// operator>>
template<class DERIVED, bool hasBlockData, class DATATYPE>
std::istream &operator>>(
   std::istream &is,
   Component<DERIVED,hasBlockData,DATATYPE> &comp
) {
   try {
      return comp.read(is);
   } catch (...) {
      log::function("istream >> {}", comp.Class());
      throw;
   }
}

// operator<<
template<class DERIVED, bool hasBlockData, class DATATYPE>
std::ostream &operator<<(
   std::ostream &os,
   const Component<DERIVED,hasBlockData,DATATYPE> &comp
) {
   try {
      return comp.print(os,0);
   } catch (...) {
      log::function("ostream << {}", comp.Class());
      throw;
   }
}
