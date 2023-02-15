
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_POLYNOMIAL1D
#define ALPHA_V2_0_GENERAL_POLYNOMIAL1D

#include "alpha/v2.0/general/Axes.hpp"
#include "alpha/v2.0/general/Values.hpp"
#include "alpha/v2.0/general/Uncertainty.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Polynomial1d
// -----------------------------------------------------------------------------

class Polynomial1d :
   public Component<general::Polynomial1d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Polynomial1d"; }
   static auto FIELD() { return "polynomial1d"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("label") |
         double{}
            / Meta<>("domainMin") |
         double{}
            / Meta<>("domainMax") |

         // children
         --Child<general::Axes>
            ("axes") |
         --Child<general::Values>
            ("values") |
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
         "domainMin",
         "domainMax",
         "axes",
         "values",
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
   Field<std::optional<std::string>>
      label{this};
   Field<double>
      domainMin{this};
   Field<double>
      domainMax{this};

   // children
   Field<general::Axes>
      axes{this};
   Field<general::Values>
      values{this};
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
      this->domainMin, \
      this->domainMax, \
      this->axes, \
      this->values, \
      this->uncertainty \
   )

   // default
   Polynomial1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Polynomial1d(
      const wrapper<std::optional<std::string>>
         &label,
      const wrapper<double>
         &domainMin = {},
      const wrapper<double>
         &domainMax = {},
      const wrapper<general::Axes>
         &axes = {},
      const wrapper<general::Values>
         &values = {},
      const wrapper<std::optional<general::Uncertainty>>
         &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      domainMin(this,domainMin),
      domainMax(this,domainMax),
      axes(this,axes),
      values(this,values),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit Polynomial1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Polynomial1d(const Polynomial1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      domainMin(this,other.domainMin),
      domainMax(this,other.domainMax),
      axes(this,other.axes),
      values(this,other.values),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   Polynomial1d(Polynomial1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      domainMin(this,std::move(other.domainMin)),
      domainMax(this,std::move(other.domainMax)),
      axes(this,std::move(other.axes)),
      values(this,std::move(other.values)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Polynomial1d &operator=(const Polynomial1d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         domainMin = other.domainMin;
         domainMax = other.domainMax;
         axes = other.axes;
         values = other.values;
         uncertainty = other.uncertainty;
      }
      return *this;
   }

   // move
   Polynomial1d &operator=(Polynomial1d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         domainMin = std::move(other.domainMin);
         domainMax = std::move(other.domainMax);
         axes = std::move(other.axes);
         values = std::move(other.values);
         uncertainty = std::move(other.uncertainty);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Polynomial1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Polynomial1d

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
