
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_SHORTRANGESELFSCALINGVARIANCE
#define ALPHA_V2_0_GENERAL_SHORTRANGESELFSCALINGVARIANCE

#include "alpha/v2.0/general/Gridded2d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ShortRangeSelfScalingVariance
// -----------------------------------------------------------------------------

class ShortRangeSelfScalingVariance :
   public Component<general::ShortRangeSelfScalingVariance>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ShortRangeSelfScalingVariance"; }
   static auto FIELD() { return "shortRangeSelfScalingVariance"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("type") |
         std::string{}
            / Meta<>("dependenceOnProcessedGroupWidth") |

         // children
         --Child<general::Gridded2d>
            ("gridded2d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      label{this};
   Field<std::string>
      type{this};
   Field<std::string>
      dependenceOnProcessedGroupWidth{this};

   // children
   Field<general::Gridded2d>
      gridded2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->type, \
      this->dependenceOnProcessedGroupWidth, \
      this->gridded2d)

   // default
   ShortRangeSelfScalingVariance() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ShortRangeSelfScalingVariance(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &type = {},
      const wrapper<std::string>
         &dependenceOnProcessedGroupWidth = {},
      const wrapper<general::Gridded2d>
         &gridded2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      type(this,type),
      dependenceOnProcessedGroupWidth(this,dependenceOnProcessedGroupWidth),
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
      label(this,other.label),
      type(this,other.type),
      dependenceOnProcessedGroupWidth(this,other.dependenceOnProcessedGroupWidth),
      gridded2d(this,other.gridded2d)
   {
      Component::finish(other);
   }

   // move
   ShortRangeSelfScalingVariance(ShortRangeSelfScalingVariance &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      type(this,std::move(other.type)),
      dependenceOnProcessedGroupWidth(this,std::move(other.dependenceOnProcessedGroupWidth)),
      gridded2d(this,std::move(other.gridded2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ShortRangeSelfScalingVariance &operator=(const ShortRangeSelfScalingVariance &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         type = other.type;
         dependenceOnProcessedGroupWidth = other.dependenceOnProcessedGroupWidth;
         gridded2d = other.gridded2d;
      }
      return *this;
   }

   // move
   ShortRangeSelfScalingVariance &operator=(ShortRangeSelfScalingVariance &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         type = std::move(other.type);
         dependenceOnProcessedGroupWidth = std::move(other.dependenceOnProcessedGroupWidth);
         gridded2d = std::move(other.gridded2d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ShortRangeSelfScalingVariance/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ShortRangeSelfScalingVariance

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
