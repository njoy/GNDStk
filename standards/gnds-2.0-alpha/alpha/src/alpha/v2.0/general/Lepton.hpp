
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_LEPTON
#define ALPHA_V2_0_GENERAL_LEPTON

#include "alpha/v2.0/general/Mass.hpp"
#include "alpha/v2.0/general/Spin.hpp"
#include "alpha/v2.0/general/Parity.hpp"
#include "alpha/v2.0/general/Charge.hpp"
#include "alpha/v2.0/general/Halflife.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Lepton
// -----------------------------------------------------------------------------

class Lepton :
   public Component<general::Lepton>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Lepton"; }
   static auto FIELD() { return "lepton"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("id") |
         std::string{}
            / Meta<>("generation") |

         // children
         --Child<general::Mass>
            ("mass") |
         --Child<general::Spin>
            ("spin") |
         --Child<general::Parity>
            ("parity") |
         --Child<general::Charge>
            ("charge") |
         --Child<general::Halflife>
            ("halflife")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> id{this};
   Field<std::string> generation{this};

   // children
   Field<general::Mass>
      mass{this};
   Field<general::Spin>
      spin{this};
   Field<general::Parity>
      parity{this};
   Field<general::Charge>
      charge{this};
   Field<general::Halflife>
      halflife{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->id, \
      this->generation, \
      this->mass, \
      this->spin, \
      this->parity, \
      this->charge, \
      this->halflife \
   )

   // default
   Lepton() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Lepton(
      const wrapper<std::string>
         &id,
      const wrapper<std::string>
         &generation = {},
      const wrapper<general::Mass>
         &mass = {},
      const wrapper<general::Spin>
         &spin = {},
      const wrapper<general::Parity>
         &parity = {},
      const wrapper<general::Charge>
         &charge = {},
      const wrapper<general::Halflife>
         &halflife = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      id(this,id),
      generation(this,generation),
      mass(this,mass),
      spin(this,spin),
      parity(this,parity),
      charge(this,charge),
      halflife(this,halflife)
   {
      Component::finish();
   }

   // from node
   explicit Lepton(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Lepton(const Lepton &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      id(this,other.id),
      generation(this,other.generation),
      mass(this,other.mass),
      spin(this,other.spin),
      parity(this,other.parity),
      charge(this,other.charge),
      halflife(this,other.halflife)
   {
      Component::finish(other);
   }

   // move
   Lepton(Lepton &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      id(this,std::move(other.id)),
      generation(this,std::move(other.generation)),
      mass(this,std::move(other.mass)),
      spin(this,std::move(other.spin)),
      parity(this,std::move(other.parity)),
      charge(this,std::move(other.charge)),
      halflife(this,std::move(other.halflife))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Lepton &operator=(const Lepton &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         id = other.id;
         generation = other.generation;
         mass = other.mass;
         spin = other.spin;
         parity = other.parity;
         charge = other.charge;
         halflife = other.halflife;
      }
      return *this;
   }

   // move
   Lepton &operator=(Lepton &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         id = std::move(other.id);
         generation = std::move(other.generation);
         mass = std::move(other.mass);
         spin = std::move(other.spin);
         parity = std::move(other.parity);
         charge = std::move(other.charge);
         halflife = std::move(other.halflife);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Lepton/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Lepton

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
