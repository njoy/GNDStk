
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_XYS1D
#define ALPHA_V2_0_COMMON_XYS1D

#include "alpha/v2.0/common/Axes.hpp"
#include "alpha/v2.0/common/Values.hpp"
#include "alpha/v2.0/common/Uncertainty.hpp"

namespace alpha {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class XYs1d
// -----------------------------------------------------------------------------

class XYs1d :
   public Component<common::XYs1d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "XYs1d"; }
   static auto FIELD() { return "XYs1d"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("label") |
         std::optional<int>{}
            / Meta<>("index") |
         std::optional<std::string>{}
            / Meta<>("interpolation") |
         std::optional<double>{}
            / Meta<>("outerDomainValue") |

         // children
         --Child<std::optional<common::Axes>>("axes") |
         --Child<common::Values>("values") |
         --Child<std::optional<common::Uncertainty>>("uncertainty")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<std::string>> label{this};
   Field<std::optional<int>> index{this};
   Field<std::optional<std::string>> interpolation{this};
   Field<std::optional<double>> outerDomainValue{this};

   // children
   Field<std::optional<common::Axes>> axes{this};
   Field<common::Values> values{this};
   Field<std::optional<common::Uncertainty>> uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->index, \
      this->interpolation, \
      this->outerDomainValue, \
      this->axes, \
      this->values, \
      this->uncertainty)

   // default
   XYs1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit XYs1d(
      const wrapper<std::optional<std::string>> &label,
      const wrapper<std::optional<int>> &index = {},
      const wrapper<std::optional<std::string>> &interpolation = {},
      const wrapper<std::optional<double>> &outerDomainValue = {},
      const wrapper<std::optional<common::Axes>> &axes = {},
      const wrapper<common::Values> &values = {},
      const wrapper<std::optional<common::Uncertainty>> &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      index(this,index),
      interpolation(this,interpolation),
      outerDomainValue(this,outerDomainValue),
      axes(this,axes),
      values(this,values),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit XYs1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   XYs1d(const XYs1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      index(this,other.index),
      interpolation(this,other.interpolation),
      outerDomainValue(this,other.outerDomainValue),
      axes(this,other.axes),
      values(this,other.values),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   XYs1d(XYs1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      index(this,std::move(other.index)),
      interpolation(this,std::move(other.interpolation)),
      outerDomainValue(this,std::move(other.outerDomainValue)),
      axes(this,std::move(other.axes)),
      values(this,std::move(other.values)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   XYs1d &operator=(const XYs1d &) = default;
   XYs1d &operator=(XYs1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/XYs1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class XYs1d

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
