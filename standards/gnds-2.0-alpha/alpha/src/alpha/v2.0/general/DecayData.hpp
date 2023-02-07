
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DECAYDATA
#define ALPHA_V2_0_GENERAL_DECAYDATA

#include "alpha/v2.0/general/DecayModes.hpp"
#include "alpha/v2.0/general/AverageEnergies.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class DecayData
// -----------------------------------------------------------------------------

class DecayData :
   public Component<general::DecayData>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "DecayData"; }
   static auto FIELD() { return "decayData"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::DecayModes>
            ("decayModes") |
         --Child<std::optional<general::AverageEnergies>>
            ("averageEnergies")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<general::DecayModes>
      decayModes{this};
   Field<std::optional<general::AverageEnergies>>
      averageEnergies{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->decayModes, \
      this->averageEnergies \
   )

   // default
   DecayData() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DecayData(
      const wrapper<general::DecayModes>
         &decayModes,
      const wrapper<std::optional<general::AverageEnergies>>
         &averageEnergies = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      decayModes(this,decayModes),
      averageEnergies(this,averageEnergies)
   {
      Component::finish();
   }

   // from node
   explicit DecayData(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DecayData(const DecayData &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      decayModes(this,other.decayModes),
      averageEnergies(this,other.averageEnergies)
   {
      Component::finish(other);
   }

   // move
   DecayData(DecayData &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      decayModes(this,std::move(other.decayModes)),
      averageEnergies(this,std::move(other.averageEnergies))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   DecayData &operator=(const DecayData &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         decayModes = other.decayModes;
         averageEnergies = other.averageEnergies;
      }
      return *this;
   }

   // move
   DecayData &operator=(DecayData &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         decayModes = std::move(other.decayModes);
         averageEnergies = std::move(other.averageEnergies);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/DecayData/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DecayData

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
