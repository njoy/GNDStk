
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef PROTO_V1_9_CONTAINERS_XYS1D
#define PROTO_V1_9_CONTAINERS_XYS1D

#include "proto/v1.9/containers/Axes.hpp"
#include "proto/v1.9/containers/Values.hpp"

namespace proto {
namespace v1_9 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class XYs1d
// -----------------------------------------------------------------------------

class XYs1d :
   public Component<containers::XYs1d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "XYs1d"; }
   static auto FIELD() { return "XYs1d"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<int>{}
            / Meta<>("index") |
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<std::string>{}
            / Meta<>("label") |
         std::optional<double>{}
            / Meta<>("outerDomainValue") |

         // children
         --Child<std::optional<containers::Axes>>("axes") |
         --Child<containers::Values>("values")
      ;
   }

public:
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const enums::Interpolation interpolation = enums::Interpolation::linlin;
   } defaults;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<int>> index{this};
   Field<Defaulted<enums::Interpolation>> interpolation{this,defaults.interpolation};
   Field<std::optional<std::string>> label{this};
   Field<std::optional<double>> outerDomainValue{this};

   // children
   Field<std::optional<containers::Axes>> axes{this};
   Field<containers::Values> values{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->index, \
      this->interpolation, \
      this->label, \
      this->outerDomainValue, \
      this->axes, \
      this->values)

   // default
   XYs1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   // optional replaces Defaulted; this class knows the default(s)
   explicit XYs1d(
      const wrapper<std::optional<int>> &index,
      const wrapper<std::optional<enums::Interpolation>> &interpolation = {},
      const wrapper<std::optional<std::string>> &label = {},
      const wrapper<std::optional<double>> &outerDomainValue = {},
      const wrapper<std::optional<containers::Axes>> &axes = {},
      const wrapper<containers::Values> &values = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      index(this,index),
      interpolation(this,defaults.interpolation,interpolation),
      label(this,label),
      outerDomainValue(this,outerDomainValue),
      axes(this,axes),
      values(this,values)
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
      index(this,other.index),
      interpolation(this,other.interpolation),
      label(this,other.label),
      outerDomainValue(this,other.outerDomainValue),
      axes(this,other.axes),
      values(this,other.values)
   {
      Component::finish(other);
   }

   // move
   XYs1d(XYs1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      index(this,std::move(other.index)),
      interpolation(this,std::move(other.interpolation)),
      label(this,std::move(other.label)),
      outerDomainValue(this,std::move(other.outerDomainValue)),
      axes(this,std::move(other.axes)),
      values(this,std::move(other.values))
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

   #include "proto/v1.9/containers/XYs1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class XYs1d

} // namespace containers
} // namespace v1_9
} // namespace proto

#endif
