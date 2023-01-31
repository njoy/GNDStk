
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_DELAYEDNEUTRONS
#define ALPHA_V2_0_MEAN_DELAYEDNEUTRONS

#include "alpha/v2.0/mean/DelayedNeutron.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class DelayedNeutrons
// -----------------------------------------------------------------------------

class DelayedNeutrons :
   public Component<mean::DelayedNeutrons>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "DelayedNeutrons"; }
   static auto FIELD() { return "delayedNeutrons"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<mean::DelayedNeutron>("delayedNeutron")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<mean::DelayedNeutron>> delayedNeutron{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->delayedNeutron)

   // default
   DelayedNeutrons() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DelayedNeutrons(
      const wrapper<std::vector<mean::DelayedNeutron>> &delayedNeutron
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      delayedNeutron(this,delayedNeutron)
   {
      Component::finish();
   }

   // from node
   explicit DelayedNeutrons(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DelayedNeutrons(const DelayedNeutrons &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      delayedNeutron(this,other.delayedNeutron)
   {
      Component::finish(other);
   }

   // move
   DelayedNeutrons(DelayedNeutrons &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      delayedNeutron(this,std::move(other.delayedNeutron))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DelayedNeutrons &operator=(const DelayedNeutrons &) = default;
   DelayedNeutrons &operator=(DelayedNeutrons &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/DelayedNeutrons/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DelayedNeutrons

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
