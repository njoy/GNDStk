
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_CONFIGURATIONS
#define CODE_V2_0_GNDS_CONFIGURATIONS

#include "code/v2.0/gnds/Configuration.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Configurations
// -----------------------------------------------------------------------------

class Configurations : public Component<gnds::Configurations> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Configurations"; }
   static auto FIELD() { return "configurations"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         gnds::Configuration{}
            / ++Child<>("configuration")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<gnds::Configuration>> configuration{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->configuration)

   // default, and from fields
   explicit Configurations(
      const wrapper<std::vector<gnds::Configuration>> &configuration = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      configuration(this,configuration)
   {
      Component::finish();
   }

   // from node
   explicit Configurations(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Configurations(const Configurations &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Configurations(Configurations &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Configurations &operator=(const Configurations &) = default;
   Configurations &operator=(Configurations &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Configurations/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Configurations

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
