
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_CPTRANSPORT_IMAGINARYINTERFERENCETERM
#define TRY_V2_0_CPTRANSPORT_IMAGINARYINTERFERENCETERM

#include "try/v2.0/unknownNamespace/XYs2d.hpp"
#include "try/v2.0/unknownNamespace/Regions2d.hpp"

namespace try {
namespace v2_0 {
namespace cpTransport {

// -----------------------------------------------------------------------------
// cpTransport::
// class ImaginaryInterferenceTerm
// -----------------------------------------------------------------------------

class ImaginaryInterferenceTerm : public Component<cpTransport::ImaginaryInterferenceTerm> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "cpTransport"; }
   static auto CLASS() { return "ImaginaryInterferenceTerm"; }
   static auto FIELD() { return "imaginaryInterferenceTerm"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<unknownNamespace::XYs2d>{}
            / --Child<>("XYs2d") |
         std::optional<unknownNamespace::Regions2d>{}
            / --Child<>("regions2d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<unknownNamespace::XYs2d>> XYs2d{this};
   Field<std::optional<unknownNamespace::Regions2d>> regions2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs2d, \
      this->regions2d)

   // default, and from fields
   explicit ImaginaryInterferenceTerm(
      const wrapper<std::optional<unknownNamespace::XYs2d>> &XYs2d = {},
      const wrapper<std::optional<unknownNamespace::Regions2d>> &regions2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs2d(this,XYs2d),
      regions2d(this,regions2d)
   {
      Component::finish();
   }

   // from node
   explicit ImaginaryInterferenceTerm(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ImaginaryInterferenceTerm(const ImaginaryInterferenceTerm &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ImaginaryInterferenceTerm(ImaginaryInterferenceTerm &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ImaginaryInterferenceTerm &operator=(const ImaginaryInterferenceTerm &) = default;
   ImaginaryInterferenceTerm &operator=(ImaginaryInterferenceTerm &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/cpTransport/ImaginaryInterferenceTerm/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ImaginaryInterferenceTerm

} // namespace cpTransport
} // namespace v2_0
} // namespace try

#endif
