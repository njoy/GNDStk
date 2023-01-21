
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COVARIANCE_SHORTRANGESELFSCALINGVARIANCE
#define TEST_V2_0_COVARIANCE_SHORTRANGESELFSCALINGVARIANCE

#include "test/v2.0/containers/Gridded2d.hpp"

namespace test {
namespace v2_0 {
namespace covariance {

// -----------------------------------------------------------------------------
// covariance::
// class ShortRangeSelfScalingVariance
// -----------------------------------------------------------------------------

class ShortRangeSelfScalingVariance :
   public Component<covariance::ShortRangeSelfScalingVariance>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "covariance"; }
   static auto CLASS() { return "ShortRangeSelfScalingVariance"; }
   static auto FIELD() { return "shortRangeSelfScalingVariance"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<XMLName>{}
            / Meta<>("dependenceOnProcessedGroupWidth") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("type") |

         // children
         --Child<std::optional<containers::Gridded2d>>("gridded2d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<XMLName>> dependenceOnProcessedGroupWidth{this};
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<XMLName>> type{this};

   // children
   Field<std::optional<containers::Gridded2d>> gridded2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->dependenceOnProcessedGroupWidth, \
      this->label, \
      this->type, \
      this->gridded2d)

   // default
   ShortRangeSelfScalingVariance() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ShortRangeSelfScalingVariance(
      const wrapper<std::optional<XMLName>> &dependenceOnProcessedGroupWidth,
      const wrapper<std::optional<XMLName>> &label = {},
      const wrapper<std::optional<XMLName>> &type = {},
      const wrapper<std::optional<containers::Gridded2d>> &gridded2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      dependenceOnProcessedGroupWidth(this,dependenceOnProcessedGroupWidth),
      label(this,label),
      type(this,type),
      gridded2d(this,gridded2d)
   {
      Component::finish();
   }

   // from node
   explicit ShortRangeSelfScalingVariance(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ShortRangeSelfScalingVariance(const ShortRangeSelfScalingVariance &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      dependenceOnProcessedGroupWidth(this,other.dependenceOnProcessedGroupWidth),
      label(this,other.label),
      type(this,other.type),
      gridded2d(this,other.gridded2d)
   {
      Component::finish(other);
   }

   // move
   ShortRangeSelfScalingVariance(ShortRangeSelfScalingVariance &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      dependenceOnProcessedGroupWidth(this,std::move(other.dependenceOnProcessedGroupWidth)),
      label(this,std::move(other.label)),
      type(this,std::move(other.type)),
      gridded2d(this,std::move(other.gridded2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ShortRangeSelfScalingVariance &operator=(const ShortRangeSelfScalingVariance &) = default;
   ShortRangeSelfScalingVariance &operator=(ShortRangeSelfScalingVariance &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/covariance/ShortRangeSelfScalingVariance/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ShortRangeSelfScalingVariance

} // namespace covariance
} // namespace v2_0
} // namespace test

#endif
