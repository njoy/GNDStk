
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_POPS_DECAYDATA
#define TEST_V2_0_POPS_DECAYDATA

#include "test/v2.0/pops/DecayModes.hpp"
#include "test/v2.0/pops/AverageEnergies.hpp"

namespace test {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class DecayData
// -----------------------------------------------------------------------------

class DecayData :
   public Component<pops::DecayData>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "DecayData"; }
   static auto FIELD() { return "decayData"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<pops::DecayModes>>("decayModes") |
         --Child<std::optional<pops::AverageEnergies>>("averageEnergies")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<pops::DecayModes>> decayModes{this};
   Field<std::optional<pops::AverageEnergies>> averageEnergies{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->decayModes, \
      this->averageEnergies)

   // default
   DecayData() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DecayData(
      const wrapper<std::optional<pops::DecayModes>> &decayModes,
      const wrapper<std::optional<pops::AverageEnergies>> &averageEnergies = {}
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

   DecayData &operator=(const DecayData &) = default;
   DecayData &operator=(DecayData &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/pops/DecayData/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DecayData

} // namespace pops
} // namespace v2_0
} // namespace test

#endif
