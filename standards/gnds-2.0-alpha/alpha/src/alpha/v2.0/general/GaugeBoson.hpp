
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_GAUGEBOSON
#define ALPHA_V2_0_GENERAL_GAUGEBOSON

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
// class GaugeBoson
// -----------------------------------------------------------------------------

class GaugeBoson :
   public Component<general::GaugeBoson>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "GaugeBoson"; }
   static auto FIELD() { return "gaugeBoson"; }

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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "id",
         "mass",
         "spin",
         "parity",
         "charge",
         "halflife"
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
      id{this};

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
      this->mass, \
      this->spin, \
      this->parity, \
      this->charge, \
      this->halflife \
   )

   // default
   GaugeBoson() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit GaugeBoson(
      const wrapper<std::string>
         &id,
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
      mass(this,mass),
      spin(this,spin),
      parity(this,parity),
      charge(this,charge),
      halflife(this,halflife)
   {
      Component::finish();
   }

   // from node
   explicit GaugeBoson(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   GaugeBoson(const GaugeBoson &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      id(this,other.id),
      mass(this,other.mass),
      spin(this,other.spin),
      parity(this,other.parity),
      charge(this,other.charge),
      halflife(this,other.halflife)
   {
      Component::finish(other);
   }

   // move
   GaugeBoson(GaugeBoson &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      id(this,std::move(other.id)),
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
   GaugeBoson &operator=(const GaugeBoson &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         id = other.id;
         mass = other.mass;
         spin = other.spin;
         parity = other.parity;
         charge = other.charge;
         halflife = other.halflife;
      }
      return *this;
   }

   // move
   GaugeBoson &operator=(GaugeBoson &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         id = std::move(other.id);
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

   #include "alpha/v2.0/general/GaugeBoson/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class GaugeBoson

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
