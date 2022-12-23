
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_ATOMIC
#define CODE_V2_0_GNDS_ATOMIC

#include "code/v2.0/gnds/Configurations.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Atomic
// -----------------------------------------------------------------------------

class Atomic : public Component<gnds::Atomic> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Atomic"; }
   static auto FIELD() { return "atomic"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment)/commentConverter{} |

         // children
         --Child<gnds::Configurations>("configurations")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<gnds::Configurations> configurations{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->configurations)

   // default
   Atomic() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Atomic(
      const wrapper<gnds::Configurations> &configurations
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      configurations(this,configurations)
   {
      Component::finish();
   }

   // from node
   explicit Atomic(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Atomic(const Atomic &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      configurations(this,other.configurations)
   {
      Component::finish(other);
   }

   // move
   Atomic(Atomic &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      configurations(this,std::move(other.configurations))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Atomic &operator=(const Atomic &) = default;
   Atomic &operator=(Atomic &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Atomic/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Atomic

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
