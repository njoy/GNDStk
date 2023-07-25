
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_CHANNEL
#define GNDS_V2_0_GENERAL_CHANNEL

#include "gnds/v2.0/general/ScatteringRadius.hpp"
#include "gnds/v2.0/general/HardSphereRadius.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Channel
// -----------------------------------------------------------------------------

class Channel :
   public Component<general::Channel>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Channel"; }
   static auto NODENAME() { return "channel"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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
         --Child<std::optional<general::ScatteringRadius>>
            ("scatteringRadius") |
         --Child<std::optional<general::HardSphereRadius>>
            ("hardSphereRadius")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "resonanceReaction",
         "L",
         "channelSpin",
         "columnIndex",
         "scatteringRadius",
         "hardSphereRadius"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "resonance_reaction",
         "l",
         "channel_spin",
         "column_index",
         "scattering_radius",
         "hard_sphere_radius"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      label{this};
   Field<std::string>
      resonanceReaction{this};
   Field<int>
      L{this};
   Field<int>
      channelSpin{this};
   Field<int>
      columnIndex{this};

   // children
   Field<std::optional<general::ScatteringRadius>>
      scatteringRadius{this};
   Field<std::optional<general::HardSphereRadius>>
      hardSphereRadius{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->resonanceReaction, \
      this->L, \
      this->channelSpin, \
      this->columnIndex, \
      this->scatteringRadius, \
      this->hardSphereRadius \
   )

   // default
   Channel() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Channel(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &resonanceReaction = {},
      const wrapper<int>
         &L = {},
      const wrapper<int>
         &channelSpin = {},
      const wrapper<int>
         &columnIndex = {},
      const wrapper<std::optional<general::ScatteringRadius>>
         &scatteringRadius = {},
      const wrapper<std::optional<general::HardSphereRadius>>
         &hardSphereRadius = {}
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

   // copy
   Channel &operator=(const Channel &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         resonanceReaction = other.resonanceReaction;
         L = other.L;
         channelSpin = other.channelSpin;
         columnIndex = other.columnIndex;
         scatteringRadius = other.scatteringRadius;
         hardSphereRadius = other.hardSphereRadius;
      }
      return *this;
   }

   // move
   Channel &operator=(Channel &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         resonanceReaction = std::move(other.resonanceReaction);
         L = std::move(other.L);
         channelSpin = std::move(other.channelSpin);
         columnIndex = std::move(other.columnIndex);
         scatteringRadius = std::move(other.scatteringRadius);
         hardSphereRadius = std::move(other.hardSphereRadius);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Channel/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Channel

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
