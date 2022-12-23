
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_BINDINGENERGY
#define CODE_V2_0_GNDS_BINDINGENERGY

#include "code/v2.0/gnds/Double.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class BindingEnergy
// -----------------------------------------------------------------------------

class BindingEnergy : public Component<gnds::BindingEnergy> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "BindingEnergy"; }
   static auto FIELD() { return "bindingEnergy"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment)/commentConverter{} |

         // children
         --Child<gnds::Double>("double")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<gnds::Double> Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->Double)

   // default
   BindingEnergy() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit BindingEnergy(
      const wrapper<gnds::Double> &Double
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      Double(this,Double)
   {
      Component::finish();
   }

   // from node
   explicit BindingEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   BindingEnergy(const BindingEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      Double(this,other.Double)
   {
      Component::finish(other);
   }

   // move
   BindingEnergy(BindingEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      Double(this,std::move(other.Double))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   BindingEnergy &operator=(const BindingEnergy &) = default;
   BindingEnergy &operator=(BindingEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/BindingEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class BindingEnergy

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
