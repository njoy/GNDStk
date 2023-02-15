
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_AVERAGEENERGY
#define ALPHA_V2_0_GENERAL_AVERAGEENERGY

#include "alpha/v2.0/general/Uncertainty.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class AverageEnergy
// -----------------------------------------------------------------------------

class AverageEnergy :
   public Component<general::AverageEnergy>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "AverageEnergy"; }
   static auto FIELD() { return "averageEnergy"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         double{}
            / Meta<>("value") |
         std::string{}
            / Meta<>("unit") |

         // children
         --Child<std::optional<general::Uncertainty>>
            ("uncertainty")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "value",
         "unit",
         "uncertainty"
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
      label{this};
   Field<double>
      value{this};
   Field<std::string>
      unit{this};

   // children
   Field<std::optional<general::Uncertainty>>
      uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->value, \
      this->unit, \
      this->uncertainty \
   )

   // default
   AverageEnergy() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit AverageEnergy(
      const wrapper<std::string>
         &label,
      const wrapper<double>
         &value = {},
      const wrapper<std::string>
         &unit = {},
      const wrapper<std::optional<general::Uncertainty>>
         &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      value(this,value),
      unit(this,unit),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit AverageEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AverageEnergy(const AverageEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      value(this,other.value),
      unit(this,other.unit),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   AverageEnergy(AverageEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      value(this,std::move(other.value)),
      unit(this,std::move(other.unit)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   AverageEnergy &operator=(const AverageEnergy &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         value = other.value;
         unit = other.unit;
         uncertainty = other.uncertainty;
      }
      return *this;
   }

   // move
   AverageEnergy &operator=(AverageEnergy &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         value = std::move(other.value);
         unit = std::move(other.unit);
         uncertainty = std::move(other.uncertainty);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/AverageEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class AverageEnergy

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
