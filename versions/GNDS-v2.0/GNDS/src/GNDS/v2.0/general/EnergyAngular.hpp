
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_ENERGYANGULAR
#define GNDS_V2_0_GENERAL_ENERGYANGULAR

#include "GNDS/v2.0/general/XYs3d.hpp"

namespace GNDS {
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

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "EnergyAngular"; }
   static auto NODENAME() { return "energyAngular"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "productFrame",
         "XYs3d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "product_frame",
         "xys3d"
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
   Field<std::string>
      productFrame{this};

   // children
   Field<std::optional<general::XYs3d>>
      XYs3d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->productFrame, \
      this->XYs3d \
   )

   // default
   EnergyAngular() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
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
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame),
      XYs3d(this,XYs3d)
   {
      Component::finish();
   }

   // from node
   explicit EnergyAngular(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   EnergyAngular(const EnergyAngular &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      productFrame(this,other.productFrame),
      XYs3d(this,other.XYs3d)
   {
      Component::finish(other);
   }

   // move
   EnergyAngular(EnergyAngular &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
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

   #include "GNDS/v2.0/general/EnergyAngular/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class EnergyAngular

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
