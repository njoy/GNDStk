
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_BARYON
#define ALPHA_V2_0_COMMON_BARYON

#include "alpha/v2.0/common/Mass.hpp"
#include "alpha/v2.0/common/Spin.hpp"
#include "alpha/v2.0/common/Parity.hpp"
#include "alpha/v2.0/common/Charge.hpp"
#include "alpha/v2.0/common/Halflife.hpp"
#include "alpha/v2.0/common/DecayData.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class Baryon
// -----------------------------------------------------------------------------

class Baryon :
   public Component<common::Baryon>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "Baryon"; }
   static auto FIELD() { return "baryon"; }

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
         --Child<common::Mass>("mass") |
         --Child<common::Spin>("spin") |
         --Child<common::Parity>("parity") |
         --Child<common::Charge>("charge") |
         --Child<common::Halflife>("halflife") |
         --Child<std::optional<common::DecayData>>("decayData")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> id{this};

   // children
   Field<common::Mass> mass{this};
   Field<common::Spin> spin{this};
   Field<common::Parity> parity{this};
   Field<common::Charge> charge{this};
   Field<common::Halflife> halflife{this};
   Field<std::optional<common::DecayData>> decayData{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->id, \
      this->mass, \
      this->spin, \
      this->parity, \
      this->charge, \
      this->halflife, \
      this->decayData)

   // default
   Baryon() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Baryon(
      const wrapper<std::string> &id,
      const wrapper<common::Mass> &mass = {},
      const wrapper<common::Spin> &spin = {},
      const wrapper<common::Parity> &parity = {},
      const wrapper<common::Charge> &charge = {},
      const wrapper<common::Halflife> &halflife = {},
      const wrapper<std::optional<common::DecayData>> &decayData = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      mass(this,mass),
      spin(this,spin),
      parity(this,parity),
      charge(this,charge),
      halflife(this,halflife),
      decayData(this,decayData)
   {
      Component::finish();
   }

   // from node
   explicit Baryon(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Baryon(const Baryon &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      id(this,other.id),
      mass(this,other.mass),
      spin(this,other.spin),
      parity(this,other.parity),
      charge(this,other.charge),
      halflife(this,other.halflife),
      decayData(this,other.decayData)
   {
      Component::finish(other);
   }

   // move
   Baryon(Baryon &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      id(this,std::move(other.id)),
      mass(this,std::move(other.mass)),
      spin(this,std::move(other.spin)),
      parity(this,std::move(other.parity)),
      charge(this,std::move(other.charge)),
      halflife(this,std::move(other.halflife)),
      decayData(this,std::move(other.decayData))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Baryon &operator=(const Baryon &) = default;
   Baryon &operator=(Baryon &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/Baryon/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Baryon

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
