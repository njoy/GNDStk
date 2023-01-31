
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_NUCLIDE
#define ALPHA_V2_0_COMMON_NUCLIDE

#include "alpha/v2.0/common/Mass.hpp"
#include "alpha/v2.0/common/Charge.hpp"
#include "alpha/v2.0/common/Nucleus.hpp"
#include "alpha/v2.0/common/DecayData.hpp"
#include "alpha/v2.0/common/FissionFragmentData.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Nuclide
// -----------------------------------------------------------------------------

class Nuclide :
   public Component<common::Nuclide>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Nuclide"; }
   static auto FIELD() { return "nuclide"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("id") |

         // children
         --Child<std::optional<common::Mass>>("mass") |
         --Child<common::Charge>("charge") |
         --Child<common::Nucleus>("nucleus") |
         --Child<std::optional<common::DecayData>>("decayData") |
         --Child<std::optional<common::FissionFragmentData>>("fissionFragmentData")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> id{this};

   // children
   Field<std::optional<common::Mass>> mass{this};
   Field<common::Charge> charge{this};
   Field<common::Nucleus> nucleus{this};
   Field<std::optional<common::DecayData>> decayData{this};
   Field<std::optional<common::FissionFragmentData>> fissionFragmentData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->id, \
      this->mass, \
      this->charge, \
      this->nucleus, \
      this->decayData, \
      this->fissionFragmentData)

   // default
   Nuclide() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Nuclide(
      const wrapper<std::string> &id,
      const wrapper<std::optional<common::Mass>> &mass = {},
      const wrapper<common::Charge> &charge = {},
      const wrapper<common::Nucleus> &nucleus = {},
      const wrapper<std::optional<common::DecayData>> &decayData = {},
      const wrapper<std::optional<common::FissionFragmentData>> &fissionFragmentData = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      mass(this,mass),
      charge(this,charge),
      nucleus(this,nucleus),
      decayData(this,decayData),
      fissionFragmentData(this,fissionFragmentData)
   {
      Component::finish();
   }

   // from node
   explicit Nuclide(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Nuclide(const Nuclide &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      id(this,other.id),
      mass(this,other.mass),
      charge(this,other.charge),
      nucleus(this,other.nucleus),
      decayData(this,other.decayData),
      fissionFragmentData(this,other.fissionFragmentData)
   {
      Component::finish(other);
   }

   // move
   Nuclide(Nuclide &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      id(this,std::move(other.id)),
      mass(this,std::move(other.mass)),
      charge(this,std::move(other.charge)),
      nucleus(this,std::move(other.nucleus)),
      decayData(this,std::move(other.decayData)),
      fissionFragmentData(this,std::move(other.fissionFragmentData))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Nuclide &operator=(const Nuclide &) = default;
   Nuclide &operator=(Nuclide &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Nuclide/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Nuclide

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
