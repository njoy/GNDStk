
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_CHANNEL
#define ALPHA_V2_0_MEAN_CHANNEL

#include "alpha/v2.0/mean/ScatteringRadius.hpp"
#include "alpha/v2.0/mean/HardSphereRadius.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class Channel
// -----------------------------------------------------------------------------

class Channel :
   public Component<mean::Channel>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "Channel"; }
   static auto FIELD() { return "channel"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("resonanceReaction") |
         int{}
            / Meta<>("L") |
         int{}
            / Meta<>("channelSpin") |
         int{}
            / Meta<>("columnIndex") |

         // children
         --Child<std::optional<mean::ScatteringRadius>>("scatteringRadius") |
         --Child<std::optional<mean::HardSphereRadius>>("hardSphereRadius")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<std::string> resonanceReaction{this};
   Field<int> L{this};
   Field<int> channelSpin{this};
   Field<int> columnIndex{this};

   // children
   Field<std::optional<mean::ScatteringRadius>> scatteringRadius{this};
   Field<std::optional<mean::HardSphereRadius>> hardSphereRadius{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->resonanceReaction, \
      this->L, \
      this->channelSpin, \
      this->columnIndex, \
      this->scatteringRadius, \
      this->hardSphereRadius)

   // default
   Channel() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Channel(
      const wrapper<std::string> &label,
      const wrapper<std::string> &resonanceReaction = {},
      const wrapper<int> &L = {},
      const wrapper<int> &channelSpin = {},
      const wrapper<int> &columnIndex = {},
      const wrapper<std::optional<mean::ScatteringRadius>> &scatteringRadius = {},
      const wrapper<std::optional<mean::HardSphereRadius>> &hardSphereRadius = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      resonanceReaction(this,resonanceReaction),
      L(this,L),
      channelSpin(this,channelSpin),
      columnIndex(this,columnIndex),
      scatteringRadius(this,scatteringRadius),
      hardSphereRadius(this,hardSphereRadius)
   {
      Component::finish();
   }

   // from node
   explicit Channel(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Channel(const Channel &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      resonanceReaction(this,other.resonanceReaction),
      L(this,other.L),
      channelSpin(this,other.channelSpin),
      columnIndex(this,other.columnIndex),
      scatteringRadius(this,other.scatteringRadius),
      hardSphereRadius(this,other.hardSphereRadius)
   {
      Component::finish(other);
   }

   // move
   Channel(Channel &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      resonanceReaction(this,std::move(other.resonanceReaction)),
      L(this,std::move(other.L)),
      channelSpin(this,std::move(other.channelSpin)),
      columnIndex(this,std::move(other.columnIndex)),
      scatteringRadius(this,std::move(other.scatteringRadius)),
      hardSphereRadius(this,std::move(other.hardSphereRadius))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Channel &operator=(const Channel &) = default;
   Channel &operator=(Channel &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/Channel/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Channel

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
