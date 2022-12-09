
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CPTRANSPORT_NUCLEARAMPLITUDEEXPANSION
#define TEST_V2_0_CPTRANSPORT_NUCLEARAMPLITUDEEXPANSION

#include "test/v2.0/cpTransport/NuclearTerm.hpp"
#include "test/v2.0/cpTransport/RealInterferenceTerm.hpp"
#include "test/v2.0/cpTransport/ImaginaryInterferenceTerm.hpp"

namespace test {
namespace v2_0 {
namespace cpTransport {

// -----------------------------------------------------------------------------
// cpTransport::
// class NuclearAmplitudeExpansion
// -----------------------------------------------------------------------------

class NuclearAmplitudeExpansion : public Component<cpTransport::NuclearAmplitudeExpansion> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "cpTransport"; }
   static auto CLASS() { return "NuclearAmplitudeExpansion"; }
   static auto FIELD() { return "nuclearAmplitudeExpansion"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         --Child<cpTransport::NuclearTerm>("nuclearTerm") |
         --Child<cpTransport::RealInterferenceTerm>("realInterferenceTerm") |
         --Child<cpTransport::ImaginaryInterferenceTerm>("imaginaryInterferenceTerm")
      ;
   }

public:
   using Component::construct;

   // children
   Field<cpTransport::NuclearTerm> nuclearTerm{this};
   Field<cpTransport::RealInterferenceTerm> realInterferenceTerm{this};
   Field<cpTransport::ImaginaryInterferenceTerm> imaginaryInterferenceTerm{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->nuclearTerm, \
      this->realInterferenceTerm, \
      this->imaginaryInterferenceTerm)

   // default
   NuclearAmplitudeExpansion() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit NuclearAmplitudeExpansion(
      const wrapper<cpTransport::NuclearTerm> &nuclearTerm,
      const wrapper<cpTransport::RealInterferenceTerm> &realInterferenceTerm = {},
      const wrapper<cpTransport::ImaginaryInterferenceTerm> &imaginaryInterferenceTerm = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      nuclearTerm(this,nuclearTerm),
      realInterferenceTerm(this,realInterferenceTerm),
      imaginaryInterferenceTerm(this,imaginaryInterferenceTerm)
   {
      Component::finish();
   }

   // from node
   explicit NuclearAmplitudeExpansion(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   NuclearAmplitudeExpansion(const NuclearAmplitudeExpansion &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      nuclearTerm(this,other.nuclearTerm),
      realInterferenceTerm(this,other.realInterferenceTerm),
      imaginaryInterferenceTerm(this,other.imaginaryInterferenceTerm)
   {
      Component::finish(other);
   }

   // move
   NuclearAmplitudeExpansion(NuclearAmplitudeExpansion &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      nuclearTerm(this,std::move(other.nuclearTerm)),
      realInterferenceTerm(this,std::move(other.realInterferenceTerm)),
      imaginaryInterferenceTerm(this,std::move(other.imaginaryInterferenceTerm))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   NuclearAmplitudeExpansion &operator=(const NuclearAmplitudeExpansion &) = default;
   NuclearAmplitudeExpansion &operator=(NuclearAmplitudeExpansion &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/cpTransport/NuclearAmplitudeExpansion/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class NuclearAmplitudeExpansion

} // namespace cpTransport
} // namespace v2_0
} // namespace test

#endif
