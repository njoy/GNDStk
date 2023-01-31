
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_NUCLEUS
#define ALPHA_V2_0_COMMON_NUCLEUS

#include "alpha/v2.0/common/Mass.hpp"
#include "alpha/v2.0/common/Spin.hpp"
#include "alpha/v2.0/common/Parity.hpp"
#include "alpha/v2.0/common/Charge.hpp"
#include "alpha/v2.0/common/Halflife.hpp"
#include "alpha/v2.0/common/Energy.hpp"
#include "alpha/v2.0/common/DecayData.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Nucleus
// -----------------------------------------------------------------------------

class Nucleus :
   public Component<common::Nucleus>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
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
         --Child<std::optional<common::Mass>>("mass") |
         --Child<std::optional<common::Spin>>("spin") |
         --Child<std::optional<common::Parity>>("parity") |
         --Child<common::Charge>("charge") |
         --Child<std::optional<common::Halflife>>("halflife") |
         --Child<common::Energy>("energy") |
         --Child<std::optional<common::DecayData>>("decayData")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> id{this};
   Field<int> index{this};

   // children
   Field<std::optional<common::Mass>> mass{this};
   Field<std::optional<common::Spin>> spin{this};
   Field<std::optional<common::Parity>> parity{this};
   Field<common::Charge> charge{this};
   Field<std::optional<common::Halflife>> halflife{this};
   Field<common::Energy> energy{this};
   Field<std::optional<common::DecayData>> decayData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->id, \
      this->index, \
      this->mass, \
      this->spin, \
      this->parity, \
      this->charge, \
      this->halflife, \
      this->energy, \
      this->decayData)

   // default
   Nucleus() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Nucleus(
      const wrapper<std::string> &id,
      const wrapper<int> &index = {},
      const wrapper<std::optional<common::Mass>> &mass = {},
      const wrapper<std::optional<common::Spin>> &spin = {},
      const wrapper<std::optional<common::Parity>> &parity = {},
      const wrapper<common::Charge> &charge = {},
      const wrapper<std::optional<common::Halflife>> &halflife = {},
      const wrapper<common::Energy> &energy = {},
      const wrapper<std::optional<common::DecayData>> &decayData = {}
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

   Nucleus &operator=(const Nucleus &) = default;
   Nucleus &operator=(Nucleus &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Nucleus/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Nucleus

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
