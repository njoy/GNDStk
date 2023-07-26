
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_ANGULARTWOBODY
#define GNDS_V2_0_GENERAL_ANGULARTWOBODY

#include "gnds/v2.0/general/XYs2d.hpp"
#include "gnds/v2.0/general/Regions2d.hpp"
#include "gnds/v2.0/general/Recoil.hpp"
#include "gnds/v2.0/general/Isotropic2d.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class AngularTwoBody
// -----------------------------------------------------------------------------

class AngularTwoBody :
   public Component<general::AngularTwoBody>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "AngularTwoBody"; }
   static auto NODENAME() { return "angularTwoBody"; }

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
         --Child<std::optional<general::XYs2d>>
            ("XYs2d") |
         --Child<std::optional<general::Regions2d>>
            ("regions2d") |
         --Child<std::optional<general::Recoil>>
            ("recoil") |
         --Child<std::optional<general::Isotropic2d>>
            ("isotropic2d")
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
         "XYs2d",
         "regions2d",
         "recoil",
         "isotropic2d"
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
         "xys2d",
         "regions2d",
         "recoil",
         "isotropic2d"
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
   Field<std::optional<general::XYs2d>>
      XYs2d{this};
   Field<std::optional<general::Regions2d>>
      regions2d{this};
   Field<std::optional<general::Recoil>>
      recoil{this};
   Field<std::optional<general::Isotropic2d>>
      isotropic2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->productFrame, \
      this->XYs2d, \
      this->regions2d, \
      this->recoil, \
      this->isotropic2d \
   )

   // default
   AngularTwoBody() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit AngularTwoBody(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &productFrame = {},
      const wrapper<std::optional<general::XYs2d>>
         &XYs2d = {},
      const wrapper<std::optional<general::Regions2d>>
         &regions2d = {},
      const wrapper<std::optional<general::Recoil>>
         &recoil = {},
      const wrapper<std::optional<general::Isotropic2d>>
         &isotropic2d = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      productFrame(this,productFrame),
      XYs2d(this,XYs2d),
      regions2d(this,regions2d),
      recoil(this,recoil),
      isotropic2d(this,isotropic2d)
   {
      Component::finish();
   }

   // from node
   explicit AngularTwoBody(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   AngularTwoBody(const AngularTwoBody &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      productFrame(this,other.productFrame),
      XYs2d(this,other.XYs2d),
      regions2d(this,other.regions2d),
      recoil(this,other.recoil),
      isotropic2d(this,other.isotropic2d)
   {
      Component::finish(other);
   }

   // move
   AngularTwoBody(AngularTwoBody &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      productFrame(this,std::move(other.productFrame)),
      XYs2d(this,std::move(other.XYs2d)),
      regions2d(this,std::move(other.regions2d)),
      recoil(this,std::move(other.recoil)),
      isotropic2d(this,std::move(other.isotropic2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   AngularTwoBody &operator=(const AngularTwoBody &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         productFrame = other.productFrame;
         XYs2d = other.XYs2d;
         regions2d = other.regions2d;
         recoil = other.recoil;
         isotropic2d = other.isotropic2d;
      }
      return *this;
   }

   // move
   AngularTwoBody &operator=(AngularTwoBody &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         productFrame = std::move(other.productFrame);
         XYs2d = std::move(other.XYs2d);
         regions2d = std::move(other.regions2d);
         recoil = std::move(other.recoil);
         isotropic2d = std::move(other.isotropic2d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/AngularTwoBody/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class AngularTwoBody

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
