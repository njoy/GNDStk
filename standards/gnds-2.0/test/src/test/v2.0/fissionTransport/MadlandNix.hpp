
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_FISSIONTRANSPORT_MADLANDNIX
#define TEST_V2_0_FISSIONTRANSPORT_MADLANDNIX

#include "test/v2.0/fissionTransport/EFH.hpp"
#include "test/v2.0/fissionTransport/EFL.hpp"
#include "test/v2.0/fissionTransport/T_M.hpp"

namespace test {
namespace v2_0 {
namespace fissionTransport {

// -----------------------------------------------------------------------------
// fissionTransport::
// class MadlandNix
// -----------------------------------------------------------------------------

class MadlandNix : public Component<fissionTransport::MadlandNix> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fissionTransport"; }
   static auto CLASS() { return "MadlandNix"; }
   static auto FIELD() { return "MadlandNix"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         fissionTransport::EFH{}
            / --Child<>("EFH") |
         fissionTransport::EFL{}
            / --Child<>("EFL") |
         fissionTransport::T_M{}
            / --Child<>("T_M")
      ;
   }

public:
   using Component::construct;

   // children
   Field<fissionTransport::EFH> EFH{this};
   Field<fissionTransport::EFL> EFL{this};
   Field<fissionTransport::T_M> T_M{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->EFH, \
      this->EFL, \
      this->T_M)

   // default, and from fields
   explicit MadlandNix(
      const wrapper<fissionTransport::EFH> &EFH = {},
      const wrapper<fissionTransport::EFL> &EFL = {},
      const wrapper<fissionTransport::T_M> &T_M = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      EFH(this,EFH),
      EFL(this,EFL),
      T_M(this,T_M)
   {
      Component::finish();
   }

   // from node
   explicit MadlandNix(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   MadlandNix(const MadlandNix &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   MadlandNix(MadlandNix &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   MadlandNix &operator=(const MadlandNix &) = default;
   MadlandNix &operator=(MadlandNix &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/fissionTransport/MadlandNix/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class MadlandNix

} // namespace fissionTransport
} // namespace v2_0
} // namespace test

#endif
