
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_SPECTRUM
#define TEST_V2_0_POPS_SPECTRUM

#include "test/v2.0/pops/Continuum.hpp"
#include "test/v2.0/pops/Discrete.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class Spectrum
// -----------------------------------------------------------------------------

class Spectrum : public Component<pops::Spectrum> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "Spectrum"; }
   static auto FIELD() { return "spectrum"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("pid") |
         // children
         std::optional<pops::Continuum>{}
            / --Child<>("continuum") |
         std::optional<pops::Discrete>{}
            / ++Child<>("discrete")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> pid{this};

   // children
   Field<std::optional<pops::Continuum>> continuum{this};
   Field<std::optional<std::vector<pops::Discrete>>> discrete{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->pid, \
      this->continuum, \
      this->discrete)

   // default, and from fields
   explicit Spectrum(
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &pid = {},
      const wrapper<std::optional<pops::Continuum>> &continuum = {},
      const wrapper<std::optional<std::vector<pops::Discrete>>> &discrete = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      pid(this,pid),
      continuum(this,continuum),
      discrete(this,discrete)
   {
      Component::finish();
   }

   // from node
   explicit Spectrum(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Spectrum(const Spectrum &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Spectrum(Spectrum &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Spectrum &operator=(const Spectrum &) = default;
   Spectrum &operator=(Spectrum &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/Spectrum/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Spectrum

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
