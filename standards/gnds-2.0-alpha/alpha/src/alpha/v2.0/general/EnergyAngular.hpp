
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_ENERGYANGULAR
#define ALPHA_V2_0_GENERAL_ENERGYANGULAR

#include "alpha/v2.0/general/XYs3d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class EnergyAngular
// -----------------------------------------------------------------------------

class EnergyAngular :
   public Component<general::EnergyAngular>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "EnergyAngular"; }
   static auto FIELD() { return "energyAngular"; }

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
            / Meta<>("productFrame") |

         // children
         --Child<std::optional<general::XYs3d>>
            ("XYs3d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<std::string> productFrame{this};

   // children
   Field<std::optional<general::XYs3d>>
      XYs3d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->productFrame, \
      this->XYs3d \
   )

   // default
   EnergyAngular() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit EnergyAngular(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &productFrame = {},
      const wrapper<std::optional<general::XYs3d>>
         &XYs3d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame),
      XYs3d(this,XYs3d)
   {
      Component::finish();
   }

   // from node
   explicit EnergyAngular(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   EnergyAngular(const EnergyAngular &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      productFrame(this,other.productFrame),
      XYs3d(this,other.XYs3d)
   {
      Component::finish(other);
   }

   // move
   EnergyAngular(EnergyAngular &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      productFrame(this,std::move(other.productFrame)),
      XYs3d(this,std::move(other.XYs3d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   EnergyAngular &operator=(const EnergyAngular &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         productFrame = other.productFrame;
         XYs3d = other.XYs3d;
      }
      return *this;
   }

   // move
   EnergyAngular &operator=(EnergyAngular &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         productFrame = std::move(other.productFrame);
         XYs3d = std::move(other.XYs3d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/EnergyAngular/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EnergyAngular

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
