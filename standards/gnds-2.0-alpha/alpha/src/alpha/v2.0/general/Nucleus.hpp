
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_NUCLEUS
#define ALPHA_V2_0_GENERAL_NUCLEUS

#include "alpha/v2.0/general/Mass.hpp"
#include "alpha/v2.0/general/Spin.hpp"
#include "alpha/v2.0/general/Parity.hpp"
#include "alpha/v2.0/general/Charge.hpp"
#include "alpha/v2.0/general/Halflife.hpp"
#include "alpha/v2.0/general/Energy.hpp"
#include "alpha/v2.0/general/DecayData.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Nucleus
// -----------------------------------------------------------------------------

class Nucleus :
   public Component<general::Nucleus>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Nucleus"; }
   static auto FIELD() { return "nucleus"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("id") |
         int{}
            / Meta<>("index") |

         // children
         --Child<std::optional<general::Mass>>
            ("mass") |
         --Child<std::optional<general::Spin>>
            ("spin") |
         --Child<std::optional<general::Parity>>
            ("parity") |
         --Child<general::Charge>
            ("charge") |
         --Child<std::optional<general::Halflife>>
            ("halflife") |
         --Child<general::Energy>
            ("energy") |
         --Child<std::optional<general::DecayData>>
            ("decayData")
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
   Field<int>
      index{this};

   // children
   Field<std::optional<general::Mass>>
      mass{this};
   Field<std::optional<general::Spin>>
      spin{this};
   Field<std::optional<general::Parity>>
      parity{this};
   Field<general::Charge>
      charge{this};
   Field<std::optional<general::Halflife>>
      halflife{this};
   Field<general::Energy>
      energy{this};
   Field<std::optional<general::DecayData>>
      decayData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->id, \
      this->index, \
      this->mass, \
      this->spin, \
      this->parity, \
      this->charge, \
      this->halflife, \
      this->energy, \
      this->decayData \
   )

   // default
   Nucleus() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Nucleus(
      const wrapper<std::string>
         &id,
      const wrapper<int>
         &index = {},
      const wrapper<std::optional<general::Mass>>
         &mass = {},
      const wrapper<std::optional<general::Spin>>
         &spin = {},
      const wrapper<std::optional<general::Parity>>
         &parity = {},
      const wrapper<general::Charge>
         &charge = {},
      const wrapper<std::optional<general::Halflife>>
         &halflife = {},
      const wrapper<general::Energy>
         &energy = {},
      const wrapper<std::optional<general::DecayData>>
         &decayData = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      index(this,index),
      mass(this,mass),
      spin(this,spin),
      parity(this,parity),
      charge(this,charge),
      halflife(this,halflife),
      energy(this,energy),
      decayData(this,decayData)
   {
      Component::finish();
   }

   // from node
   explicit Nucleus(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Nucleus(const Nucleus &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      id(this,other.id),
      index(this,other.index),
      mass(this,other.mass),
      spin(this,other.spin),
      parity(this,other.parity),
      charge(this,other.charge),
      halflife(this,other.halflife),
      energy(this,other.energy),
      decayData(this,other.decayData)
   {
      Component::finish(other);
   }

   // move
   Nucleus(Nucleus &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      id(this,std::move(other.id)),
      index(this,std::move(other.index)),
      mass(this,std::move(other.mass)),
      spin(this,std::move(other.spin)),
      parity(this,std::move(other.parity)),
      charge(this,std::move(other.charge)),
      halflife(this,std::move(other.halflife)),
      energy(this,std::move(other.energy)),
      decayData(this,std::move(other.decayData))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Nucleus &operator=(const Nucleus &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         id = other.id;
         index = other.index;
         mass = other.mass;
         spin = other.spin;
         parity = other.parity;
         charge = other.charge;
         halflife = other.halflife;
         energy = other.energy;
         decayData = other.decayData;
      }
      return *this;
   }

   // move
   Nucleus &operator=(Nucleus &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         id = std::move(other.id);
         index = std::move(other.index);
         mass = std::move(other.mass);
         spin = std::move(other.spin);
         parity = std::move(other.parity);
         charge = std::move(other.charge);
         halflife = std::move(other.halflife);
         energy = std::move(other.energy);
         decayData = std::move(other.decayData);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Nucleus/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Nucleus

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
