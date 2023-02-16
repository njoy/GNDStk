
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_INCOHERENTPHOTONSCATTERING
#define ALPHA_V2_0_GENERAL_INCOHERENTPHOTONSCATTERING

#include "alpha/v2.0/general/ScatteringFactor.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class IncoherentPhotonScattering
// -----------------------------------------------------------------------------

class IncoherentPhotonScattering :
   public Component<general::IncoherentPhotonScattering>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "IncoherentPhotonScattering"; }
   static auto FIELD() { return "incoherentPhotonScattering"; }

   // Core Interface multi-query to transfer information to/from Nodes
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
         --Child<std::optional<general::ScatteringFactor>>
            ("scatteringFactor")
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
         "scatteringFactor"
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
         "scattering_factor"
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
   Field<std::optional<general::ScatteringFactor>>
      scatteringFactor{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->href, \
      this->pid, \
      this->productFrame, \
      this->scatteringFactor \
   )

   // default
   IncoherentPhotonScattering() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit IncoherentPhotonScattering(
      const wrapper<std::string>
         &label,
      const wrapper<std::optional<std::string>>
         &href = {},
      const wrapper<std::optional<std::string>>
         &pid = {},
      const wrapper<std::optional<std::string>>
         &productFrame = {},
      const wrapper<std::optional<general::ScatteringFactor>>
         &scatteringFactor = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      href(this,href),
      pid(this,pid),
      productFrame(this,productFrame),
      scatteringFactor(this,scatteringFactor)
   {
      Component::finish();
   }

   // from node
   explicit IncoherentPhotonScattering(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   IncoherentPhotonScattering(const IncoherentPhotonScattering &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      href(this,other.href),
      pid(this,other.pid),
      productFrame(this,other.productFrame),
      scatteringFactor(this,other.scatteringFactor)
   {
      Component::finish(other);
   }

   // move
   IncoherentPhotonScattering(IncoherentPhotonScattering &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      href(this,std::move(other.href)),
      pid(this,std::move(other.pid)),
      productFrame(this,std::move(other.productFrame)),
      scatteringFactor(this,std::move(other.scatteringFactor))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   IncoherentPhotonScattering &operator=(const IncoherentPhotonScattering &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         href = other.href;
         pid = other.pid;
         productFrame = other.productFrame;
         scatteringFactor = other.scatteringFactor;
      }
      return *this;
   }

   // move
   IncoherentPhotonScattering &operator=(IncoherentPhotonScattering &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         href = std::move(other.href);
         pid = std::move(other.pid);
         productFrame = std::move(other.productFrame);
         scatteringFactor = std::move(other.scatteringFactor);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/IncoherentPhotonScattering/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class IncoherentPhotonScattering

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
