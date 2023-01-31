
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_DELAYEDGAMMAENERGY
#define ALPHA_V2_0_MEAN_DELAYEDGAMMAENERGY

#include "alpha/v2.0/common/Polynomial1d.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class DelayedGammaEnergy
// -----------------------------------------------------------------------------

class DelayedGammaEnergy :
   public Component<mean::DelayedGammaEnergy>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "DelayedGammaEnergy"; }
   static auto FIELD() { return "delayedGammaEnergy"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<common::Polynomial1d>("polynomial1d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<common::Polynomial1d> polynomial1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->polynomial1d)

   // default
   DelayedGammaEnergy() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DelayedGammaEnergy(
      const wrapper<common::Polynomial1d> &polynomial1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      polynomial1d(this,polynomial1d)
   {
      Component::finish();
   }

   // from node
   explicit DelayedGammaEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DelayedGammaEnergy(const DelayedGammaEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      polynomial1d(this,other.polynomial1d)
   {
      Component::finish(other);
   }

   // move
   DelayedGammaEnergy(DelayedGammaEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      polynomial1d(this,std::move(other.polynomial1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DelayedGammaEnergy &operator=(const DelayedGammaEnergy &) = default;
   DelayedGammaEnergy &operator=(DelayedGammaEnergy &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/DelayedGammaEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DelayedGammaEnergy

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
