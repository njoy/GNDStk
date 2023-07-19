
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_CHANNEL
#define TEST_V2_0_RESONANCES_CHANNEL

#include "test/v2.0/resonances/ExternalRMatrix.hpp"
#include "test/v2.0/resonances/ScatteringRadius.hpp"
#include "test/v2.0/resonances/HardSphereRadius.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class Channel
// -----------------------------------------------------------------------------

class Channel :
   public Component<resonances::Channel>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "Channel"; }
   static auto NODENAME() { return "channel"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("resonanceReaction") |
         Integer32{}
            / Meta<>("L") |
         Fraction32{}
            / Meta<>("channelSpin") |
         std::optional<Float64>{}
            / Meta<>("boundaryConditionValue") |
         Integer32{}
            / Meta<>("columnIndex") |

         // children
         --Child<std::optional<resonances::ExternalRMatrix>>
            ("externalRMatrix") |
         --Child<std::optional<resonances::ScatteringRadius>>
            ("scatteringRadius") |
         --Child<std::optional<resonances::HardSphereRadius>>
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
         "boundaryConditionValue",
         "columnIndex",
         "externalRMatrix",
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
         "boundary_condition_value",
         "column_index",
         "external_rmatrix",
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
   Field<XMLName>
      label{this};
   Field<std::string>
      resonanceReaction{this};
   Field<Integer32>
      L{this};
   Field<Fraction32>
      channelSpin{this};
   Field<std::optional<Float64>>
      boundaryConditionValue{this};
   Field<Integer32>
      columnIndex{this};

   // children
   Field<std::optional<resonances::ExternalRMatrix>>
      externalRMatrix{this};
   Field<std::optional<resonances::ScatteringRadius>>
      scatteringRadius{this};
   Field<std::optional<resonances::HardSphereRadius>>
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
      this->boundaryConditionValue, \
      this->columnIndex, \
      this->externalRMatrix, \
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
      const wrapper<XMLName>
         &label,
      const wrapper<std::string>
         &resonanceReaction = {},
      const wrapper<Integer32>
         &L = {},
      const wrapper<Fraction32>
         &channelSpin = {},
      const wrapper<std::optional<Float64>>
         &boundaryConditionValue = {},
      const wrapper<Integer32>
         &columnIndex = {},
      const wrapper<std::optional<resonances::ExternalRMatrix>>
         &externalRMatrix = {},
      const wrapper<std::optional<resonances::ScatteringRadius>>
         &scatteringRadius = {},
      const wrapper<std::optional<resonances::HardSphereRadius>>
         &hardSphereRadius = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      resonanceReaction(this,resonanceReaction),
      L(this,L),
      channelSpin(this,channelSpin),
      boundaryConditionValue(this,boundaryConditionValue),
      columnIndex(this,columnIndex),
      externalRMatrix(this,externalRMatrix),
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
      boundaryConditionValue(this,other.boundaryConditionValue),
      columnIndex(this,other.columnIndex),
      externalRMatrix(this,other.externalRMatrix),
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
      boundaryConditionValue(this,std::move(other.boundaryConditionValue)),
      columnIndex(this,std::move(other.columnIndex)),
      externalRMatrix(this,std::move(other.externalRMatrix)),
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
         boundaryConditionValue = other.boundaryConditionValue;
         columnIndex = other.columnIndex;
         externalRMatrix = other.externalRMatrix;
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
         boundaryConditionValue = std::move(other.boundaryConditionValue);
         columnIndex = std::move(other.columnIndex);
         externalRMatrix = std::move(other.externalRMatrix);
         scatteringRadius = std::move(other.scatteringRadius);
         hardSphereRadius = std::move(other.hardSphereRadius);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/Channel/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Channel

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif
