
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_NUCLIDE
#define ALPHA_V2_0_GENERAL_NUCLIDE

#include "alpha/v2.0/general/Mass.hpp"
#include "alpha/v2.0/general/Charge.hpp"
#include "alpha/v2.0/general/Nucleus.hpp"
#include "alpha/v2.0/general/DecayData.hpp"
#include "alpha/v2.0/top/FissionFragmentData.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Nuclide
// -----------------------------------------------------------------------------

class Nuclide :
   public Component<general::Nuclide>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
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
         --Child<std::optional<general::Mass>>
            ("mass") |
         --Child<general::Charge>
            ("charge") |
         --Child<general::Nucleus>
            ("nucleus") |
         --Child<std::optional<general::DecayData>>
            ("decayData") |
         --Child<std::optional<top::FissionFragmentData>>
            ("fissionFragmentData")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      id{this};

   // children
   Field<std::optional<general::Mass>>
      mass{this};
   Field<general::Charge>
      charge{this};
   Field<general::Nucleus>
      nucleus{this};
   Field<std::optional<general::DecayData>>
      decayData{this};
   Field<std::optional<top::FissionFragmentData>>
      fissionFragmentData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->id, \
      this->mass, \
      this->charge, \
      this->nucleus, \
      this->decayData, \
      this->fissionFragmentData \
   )

   // default
   Nuclide() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Nuclide(
      const wrapper<std::string>
         &id,
      const wrapper<std::optional<general::Mass>>
         &mass = {},
      const wrapper<general::Charge>
         &charge = {},
      const wrapper<general::Nucleus>
         &nucleus = {},
      const wrapper<std::optional<general::DecayData>>
         &decayData = {},
      const wrapper<std::optional<top::FissionFragmentData>>
         &fissionFragmentData = {}
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

   // copy
   Nuclide &operator=(const Nuclide &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         id = other.id;
         mass = other.mass;
         charge = other.charge;
         nucleus = other.nucleus;
         decayData = other.decayData;
         fissionFragmentData = other.fissionFragmentData;
      }
      return *this;
   }

   // move
   Nuclide &operator=(Nuclide &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         id = std::move(other.id);
         mass = std::move(other.mass);
         charge = std::move(other.charge);
         nucleus = std::move(other.nucleus);
         decayData = std::move(other.decayData);
         fissionFragmentData = std::move(other.fissionFragmentData);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Nuclide/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Nuclide

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
