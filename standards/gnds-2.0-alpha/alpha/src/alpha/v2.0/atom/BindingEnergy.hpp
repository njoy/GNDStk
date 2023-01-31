
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_ATOM_BINDINGENERGY
#define ALPHA_V2_0_ATOM_BINDINGENERGY

#include "alpha/v2.0/common/Double.hpp"

namespace alpha {
namespace v2_0 {
namespace atom {

// -----------------------------------------------------------------------------
// atom::
// class BindingEnergy
// -----------------------------------------------------------------------------

class BindingEnergy :
   public Component<atom::BindingEnergy>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "atom"; }
   static auto CLASS() { return "BindingEnergy"; }
   static auto FIELD() { return "bindingEnergy"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<common::Double>("double")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<common::Double> Double{this};

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

   // from fields, comment excluded
   explicit BindingEnergy(
      const wrapper<common::Double> &Double
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

   #include "alpha/v2.0/atom/BindingEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class BindingEnergy

} // namespace atom
} // namespace v2_0
} // namespace alpha

#endif
