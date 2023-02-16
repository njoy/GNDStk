
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_THERMALNEUTRONSCATTERINGLAW_INCOHERENTELASTIC
#define ALPHA_V2_0_GENERAL_THERMALNEUTRONSCATTERINGLAW_INCOHERENTELASTIC

#include "alpha/v2.0/general/BoundAtomCrossSection.hpp"
#include "alpha/v2.0/general/DebyeWallerIntegral.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ThermalNeutronScatteringLaw_incoherentElastic
// -----------------------------------------------------------------------------

class ThermalNeutronScatteringLaw_incoherentElastic :
   public Component<general::ThermalNeutronScatteringLaw_incoherentElastic>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ThermalNeutronScatteringLaw_incoherentElastic"; }
   static auto NODENAME() { return "thermalNeutronScatteringLaw_incoherentElastic"; }

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
            / Meta<>("pid") |
         std::string{}
            / Meta<>("productFrame") |

         // children
         --Child<general::BoundAtomCrossSection>
            ("boundAtomCrossSection") |
         --Child<general::DebyeWallerIntegral>
            ("DebyeWallerIntegral")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "pid",
         "productFrame",
         "boundAtomCrossSection",
         "DebyeWallerIntegral"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "pid",
         "product_frame",
         "bound_atom_cross_section",
         "debye_waller_integral"
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
      pid{this};
   Field<std::string>
      productFrame{this};

   // children
   Field<general::BoundAtomCrossSection>
      boundAtomCrossSection{this};
   Field<general::DebyeWallerIntegral>
      DebyeWallerIntegral{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->pid, \
      this->productFrame, \
      this->boundAtomCrossSection, \
      this->DebyeWallerIntegral \
   )

   // default
   ThermalNeutronScatteringLaw_incoherentElastic() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ThermalNeutronScatteringLaw_incoherentElastic(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &pid = {},
      const wrapper<std::string>
         &productFrame = {},
      const wrapper<general::BoundAtomCrossSection>
         &boundAtomCrossSection = {},
      const wrapper<general::DebyeWallerIntegral>
         &DebyeWallerIntegral = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      pid(this,pid),
      productFrame(this,productFrame),
      boundAtomCrossSection(this,boundAtomCrossSection),
      DebyeWallerIntegral(this,DebyeWallerIntegral)
   {
      Component::finish();
   }

   // from node
   explicit ThermalNeutronScatteringLaw_incoherentElastic(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ThermalNeutronScatteringLaw_incoherentElastic(const ThermalNeutronScatteringLaw_incoherentElastic &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      pid(this,other.pid),
      productFrame(this,other.productFrame),
      boundAtomCrossSection(this,other.boundAtomCrossSection),
      DebyeWallerIntegral(this,other.DebyeWallerIntegral)
   {
      Component::finish(other);
   }

   // move
   ThermalNeutronScatteringLaw_incoherentElastic(ThermalNeutronScatteringLaw_incoherentElastic &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      pid(this,std::move(other.pid)),
      productFrame(this,std::move(other.productFrame)),
      boundAtomCrossSection(this,std::move(other.boundAtomCrossSection)),
      DebyeWallerIntegral(this,std::move(other.DebyeWallerIntegral))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ThermalNeutronScatteringLaw_incoherentElastic &operator=(const ThermalNeutronScatteringLaw_incoherentElastic &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         pid = other.pid;
         productFrame = other.productFrame;
         boundAtomCrossSection = other.boundAtomCrossSection;
         DebyeWallerIntegral = other.DebyeWallerIntegral;
      }
      return *this;
   }

   // move
   ThermalNeutronScatteringLaw_incoherentElastic &operator=(ThermalNeutronScatteringLaw_incoherentElastic &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         pid = std::move(other.pid);
         productFrame = std::move(other.productFrame);
         boundAtomCrossSection = std::move(other.boundAtomCrossSection);
         DebyeWallerIntegral = std::move(other.DebyeWallerIntegral);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ThermalNeutronScatteringLaw_incoherentElastic/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ThermalNeutronScatteringLaw_incoherentElastic

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
