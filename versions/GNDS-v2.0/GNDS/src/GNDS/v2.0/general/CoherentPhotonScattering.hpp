
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_COHERENTPHOTONSCATTERING
#define GNDS_V2_0_GENERAL_COHERENTPHOTONSCATTERING

#include "GNDS/v2.0/general/FormFactor.hpp"
#include "GNDS/v2.0/general/RealAnomalousFactor.hpp"
#include "GNDS/v2.0/general/ImaginaryAnomalousFactor.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class CoherentPhotonScattering
// -----------------------------------------------------------------------------

class CoherentPhotonScattering :
   public Component<general::CoherentPhotonScattering>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "CoherentPhotonScattering"; }
   static auto NODENAME() { return "coherentPhotonScattering"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::optional<std::string>{}
            / Meta<>("href") |
         std::optional<std::string>{}
            / Meta<>("pid") |
         std::optional<std::string>{}
            / Meta<>("productFrame") |

         // children
         --Child<std::optional<general::FormFactor>>
            ("formFactor") |
         --Child<std::optional<general::RealAnomalousFactor>>
            ("realAnomalousFactor") |
         --Child<std::optional<general::ImaginaryAnomalousFactor>>
            ("imaginaryAnomalousFactor")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "href",
         "pid",
         "productFrame",
         "formFactor",
         "realAnomalousFactor",
         "imaginaryAnomalousFactor"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "href",
         "pid",
         "product_frame",
         "form_factor",
         "real_anomalous_factor",
         "imaginary_anomalous_factor"
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
   Field<std::optional<std::string>>
      href{this};
   Field<std::optional<std::string>>
      pid{this};
   Field<std::optional<std::string>>
      productFrame{this};

   // children
   Field<std::optional<general::FormFactor>>
      formFactor{this};
   Field<std::optional<general::RealAnomalousFactor>>
      realAnomalousFactor{this};
   Field<std::optional<general::ImaginaryAnomalousFactor>>
      imaginaryAnomalousFactor{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->href, \
      this->pid, \
      this->productFrame, \
      this->formFactor, \
      this->realAnomalousFactor, \
      this->imaginaryAnomalousFactor \
   )

   // default
   CoherentPhotonScattering() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CoherentPhotonScattering(
      const wrapper<std::string>
         &label,
      const wrapper<std::optional<std::string>>
         &href = {},
      const wrapper<std::optional<std::string>>
         &pid = {},
      const wrapper<std::optional<std::string>>
         &productFrame = {},
      const wrapper<std::optional<general::FormFactor>>
         &formFactor = {},
      const wrapper<std::optional<general::RealAnomalousFactor>>
         &realAnomalousFactor = {},
      const wrapper<std::optional<general::ImaginaryAnomalousFactor>>
         &imaginaryAnomalousFactor = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      href(this,href),
      pid(this,pid),
      productFrame(this,productFrame),
      formFactor(this,formFactor),
      realAnomalousFactor(this,realAnomalousFactor),
      imaginaryAnomalousFactor(this,imaginaryAnomalousFactor)
   {
      Component::finish();
   }

   // from node
   explicit CoherentPhotonScattering(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CoherentPhotonScattering(const CoherentPhotonScattering &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      href(this,other.href),
      pid(this,other.pid),
      productFrame(this,other.productFrame),
      formFactor(this,other.formFactor),
      realAnomalousFactor(this,other.realAnomalousFactor),
      imaginaryAnomalousFactor(this,other.imaginaryAnomalousFactor)
   {
      Component::finish(other);
   }

   // move
   CoherentPhotonScattering(CoherentPhotonScattering &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      href(this,std::move(other.href)),
      pid(this,std::move(other.pid)),
      productFrame(this,std::move(other.productFrame)),
      formFactor(this,std::move(other.formFactor)),
      realAnomalousFactor(this,std::move(other.realAnomalousFactor)),
      imaginaryAnomalousFactor(this,std::move(other.imaginaryAnomalousFactor))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   CoherentPhotonScattering &operator=(const CoherentPhotonScattering &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         href = other.href;
         pid = other.pid;
         productFrame = other.productFrame;
         formFactor = other.formFactor;
         realAnomalousFactor = other.realAnomalousFactor;
         imaginaryAnomalousFactor = other.imaginaryAnomalousFactor;
      }
      return *this;
   }

   // move
   CoherentPhotonScattering &operator=(CoherentPhotonScattering &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         href = std::move(other.href);
         pid = std::move(other.pid);
         productFrame = std::move(other.productFrame);
         formFactor = std::move(other.formFactor);
         realAnomalousFactor = std::move(other.realAnomalousFactor);
         imaginaryAnomalousFactor = std::move(other.imaginaryAnomalousFactor);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/CoherentPhotonScattering/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class CoherentPhotonScattering

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
