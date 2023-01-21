
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_REGIONS1D
#define TEST_V2_0_CONTAINERS_REGIONS1D

#include "test/v2.0/containers/Axes.hpp"
#include "test/v2.0/containers/Function1ds.hpp"
#include "test/v2.0/extra/Uncertainty.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Regions1d
// -----------------------------------------------------------------------------

class Regions1d :
   public Component<containers::Regions1d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Regions1d"; }
   static auto FIELD() { return "regions1d"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |

         // children
         --Child<std::optional<containers::Axes>>("axes") |
         --Child<containers::Function1ds>("function1ds") |
         --Child<std::optional<extra::Uncertainty>>("uncertainty")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<Float64>> outerDomainValue{this};

   // children
   Field<std::optional<containers::Axes>> axes{this};
   Field<containers::Function1ds> function1ds{this};
   Field<std::optional<extra::Uncertainty>> uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->outerDomainValue, \
      this->axes, \
      this->function1ds, \
      this->uncertainty)

   // default
   Regions1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Regions1d(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<std::optional<Float64>> &outerDomainValue = {},
      const wrapper<std::optional<containers::Axes>> &axes = {},
      const wrapper<containers::Function1ds> &function1ds = {},
      const wrapper<std::optional<extra::Uncertainty>> &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      outerDomainValue(this,outerDomainValue),
      axes(this,axes),
      function1ds(this,function1ds),
      uncertainty(this,uncertainty)
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
      function1ds(this,other.function1ds),
      uncertainty(this,other.uncertainty)
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
      function1ds(this,std::move(other.function1ds)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Regions1d &operator=(const Regions1d &) = default;
   Regions1d &operator=(Regions1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Regions1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Regions1d

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
