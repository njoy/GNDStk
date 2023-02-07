
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_REGIONS1D
#define ALPHA_V2_0_GENERAL_REGIONS1D

#include "alpha/v2.0/general/Axes.hpp"
#include "alpha/v2.0/general/Uncertainty.hpp"
#include "alpha/v2.0/reduced/Function1ds.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Regions1d
// -----------------------------------------------------------------------------

class Regions1d :
   public Component<general::Regions1d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Regions1d"; }
   static auto FIELD() { return "regions1d"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("label") |
         std::optional<double>{}
            / Meta<>("outerDomainValue") |

         // children
         --Child<std::optional<general::Axes>>
            ("axes") |
         --Child<std::optional<general::Uncertainty>>
            ("uncertainty") |
         --Child<reduced::Function1ds>
            ("function1ds")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<std::string>> label{this};
   Field<std::optional<double>> outerDomainValue{this};

   // children
   Field<std::optional<general::Axes>>
      axes{this};
   Field<std::optional<general::Uncertainty>>
      uncertainty{this};
   Field<reduced::Function1ds>
      function1ds{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->outerDomainValue, \
      this->axes, \
      this->uncertainty, \
      this->function1ds \
   )

   // default
   Regions1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Regions1d(
      const wrapper<std::optional<std::string>>
         &label,
      const wrapper<std::optional<double>>
         &outerDomainValue = {},
      const wrapper<std::optional<general::Axes>>
         &axes = {},
      const wrapper<std::optional<general::Uncertainty>>
         &uncertainty = {},
      const wrapper<reduced::Function1ds>
         &function1ds = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      outerDomainValue(this,outerDomainValue),
      axes(this,axes),
      uncertainty(this,uncertainty),
      function1ds(this,function1ds)
   {
      Component::finish();
   }

   // from node
   explicit Regions1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Regions1d(const Regions1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      outerDomainValue(this,other.outerDomainValue),
      axes(this,other.axes),
      uncertainty(this,other.uncertainty),
      function1ds(this,other.function1ds)
   {
      Component::finish(other);
   }

   // move
   Regions1d(Regions1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      outerDomainValue(this,std::move(other.outerDomainValue)),
      axes(this,std::move(other.axes)),
      uncertainty(this,std::move(other.uncertainty)),
      function1ds(this,std::move(other.function1ds))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Regions1d &operator=(const Regions1d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         outerDomainValue = other.outerDomainValue;
         axes = other.axes;
         uncertainty = other.uncertainty;
         function1ds = other.function1ds;
      }
      return *this;
   }

   // move
   Regions1d &operator=(Regions1d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         outerDomainValue = std::move(other.outerDomainValue);
         axes = std::move(other.axes);
         uncertainty = std::move(other.uncertainty);
         function1ds = std::move(other.function1ds);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Regions1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Regions1d

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
