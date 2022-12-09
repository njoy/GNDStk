
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CPTRANSPORT_NUCLEARTERM
#define TEST_V2_0_CPTRANSPORT_NUCLEARTERM

#include "test/v2.0/containers/XYs2d.hpp"
#include "test/v2.0/containers/Regions2d.hpp"

namespace test {
namespace v2_0 {
namespace cpTransport {

// -----------------------------------------------------------------------------
// cpTransport::
// class NuclearTerm
// -----------------------------------------------------------------------------

class NuclearTerm : public Component<cpTransport::NuclearTerm> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "cpTransport"; }
   static auto CLASS() { return "NuclearTerm"; }
   static auto FIELD() { return "nuclearTerm"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         std::optional<containers::XYs2d>{}
            / --Child<>("XYs2d") |
         std::optional<containers::Regions2d>{}
            / --Child<>("regions2d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::optional<containers::XYs2d>> XYs2d{this};
   Field<std::optional<containers::Regions2d>> regions2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->XYs2d, \
      this->regions2d)

   // default, and from fields
   explicit NuclearTerm(
      const wrapper<std::optional<containers::XYs2d>> &XYs2d = {},
      const wrapper<std::optional<containers::Regions2d>> &regions2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs2d(this,XYs2d),
      regions2d(this,regions2d)
   {
      Component::finish();
   }

   // from node
   explicit NuclearTerm(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   NuclearTerm(const NuclearTerm &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   NuclearTerm(NuclearTerm &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   NuclearTerm &operator=(const NuclearTerm &) = default;
   NuclearTerm &operator=(NuclearTerm &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/cpTransport/NuclearTerm/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class NuclearTerm

} // namespace cpTransport
} // namespace v2_0
} // namespace test

#endif
