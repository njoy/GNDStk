
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW_INCOHERENTINELASTIC
#define TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW_INCOHERENTINELASTIC

#include "test/v2.0/tsl/ScatteringAtoms.hpp"

namespace test {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class ThermalNeutronScatteringLaw_incoherentInelastic
// -----------------------------------------------------------------------------

class ThermalNeutronScatteringLaw_incoherentInelastic :
   public Component<tsl::ThermalNeutronScatteringLaw_incoherentInelastic>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "ThermalNeutronScatteringLaw_incoherentInelastic"; }
   static auto NODENAME() { return "thermalNeutronScatteringLaw_incoherentInelastic"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("label") |
         Defaulted<XMLName>{"enums::DecayType::Neutron"}
            / Meta<>("pid") |
         Defaulted<enums::Frame>{enums::Frame::lab}
            / Meta<>("productFrame") |
         Defaulted<bool>{false}
            / Meta<>("calculatedAtThermal") |
         Defaulted<bool>{true}
            / Meta<>("incoherentApproximation") |
         XMLName{}
            / Meta<>("primaryScatterer") |

         // children
         --Child<tsl::ScatteringAtoms>
            ("scatteringAtoms")
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
         "calculatedAtThermal",
         "incoherentApproximation",
         "primaryScatterer",
         "scatteringAtoms"
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
         "calculated_at_thermal",
         "incoherent_approximation",
         "primary_scatterer",
         "scattering_atoms"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const XMLName pid = "enums::DecayType::Neutron";
      static inline const enums::Frame productFrame = enums::Frame::lab;
      static inline const bool calculatedAtThermal = false;
      static inline const bool incoherentApproximation = true;
   } defaults;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<XMLName>
      label{this};
   Field<Defaulted<XMLName>>
      pid{this,defaults.pid};
   Field<Defaulted<enums::Frame>>
      productFrame{this,defaults.productFrame};
   Field<Defaulted<bool>>
      calculatedAtThermal{this,defaults.calculatedAtThermal};
   Field<Defaulted<bool>>
      incoherentApproximation{this,defaults.incoherentApproximation};
   Field<XMLName>
      primaryScatterer{this};

   // children
   Field<tsl::ScatteringAtoms>
      scatteringAtoms{this};

   // shortcuts
   #define GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   GNDSTK_SHORTCUT(scatteringAtoms(),scatteringAtom);
   #undef GNDSTK_SHORTCUT

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
      this->calculatedAtThermal, \
      this->incoherentApproximation, \
      this->primaryScatterer, \
      this->scatteringAtoms \
   )

   // default
   ThermalNeutronScatteringLaw_incoherentInelastic() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   // optional replaces Defaulted; this class knows the default(s)
   explicit ThermalNeutronScatteringLaw_incoherentInelastic(
      const wrapper<XMLName>
         &label,
      const wrapper<std::optional<XMLName>>
         &pid = {},
      const wrapper<std::optional<enums::Frame>>
         &productFrame = {},
      const wrapper<std::optional<bool>>
         &calculatedAtThermal = {},
      const wrapper<std::optional<bool>>
         &incoherentApproximation = {},
      const wrapper<XMLName>
         &primaryScatterer = {},
      const wrapper<tsl::ScatteringAtoms>
         &scatteringAtoms = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      pid(this,defaults.pid,pid),
      productFrame(this,defaults.productFrame,productFrame),
      calculatedAtThermal(this,defaults.calculatedAtThermal,calculatedAtThermal),
      incoherentApproximation(this,defaults.incoherentApproximation,incoherentApproximation),
      primaryScatterer(this,primaryScatterer),
      scatteringAtoms(this,scatteringAtoms)
   {
      Component::finish();
   }

   // from node
   explicit ThermalNeutronScatteringLaw_incoherentInelastic(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ThermalNeutronScatteringLaw_incoherentInelastic(const ThermalNeutronScatteringLaw_incoherentInelastic &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      pid(this,other.pid),
      productFrame(this,other.productFrame),
      calculatedAtThermal(this,other.calculatedAtThermal),
      incoherentApproximation(this,other.incoherentApproximation),
      primaryScatterer(this,other.primaryScatterer),
      scatteringAtoms(this,other.scatteringAtoms)
   {
      Component::finish(other);
   }

   // move
   ThermalNeutronScatteringLaw_incoherentInelastic(ThermalNeutronScatteringLaw_incoherentInelastic &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      pid(this,std::move(other.pid)),
      productFrame(this,std::move(other.productFrame)),
      calculatedAtThermal(this,std::move(other.calculatedAtThermal)),
      incoherentApproximation(this,std::move(other.incoherentApproximation)),
      primaryScatterer(this,std::move(other.primaryScatterer)),
      scatteringAtoms(this,std::move(other.scatteringAtoms))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ThermalNeutronScatteringLaw_incoherentInelastic &operator=(const ThermalNeutronScatteringLaw_incoherentInelastic &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         pid = other.pid;
         productFrame = other.productFrame;
         calculatedAtThermal = other.calculatedAtThermal;
         incoherentApproximation = other.incoherentApproximation;
         primaryScatterer = other.primaryScatterer;
         scatteringAtoms = other.scatteringAtoms;
      }
      return *this;
   }

   // move
   ThermalNeutronScatteringLaw_incoherentInelastic &operator=(ThermalNeutronScatteringLaw_incoherentInelastic &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         pid = std::move(other.pid);
         productFrame = std::move(other.productFrame);
         calculatedAtThermal = std::move(other.calculatedAtThermal);
         incoherentApproximation = std::move(other.incoherentApproximation);
         primaryScatterer = std::move(other.primaryScatterer);
         scatteringAtoms = std::move(other.scatteringAtoms);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/tsl/ThermalNeutronScatteringLaw_incoherentInelastic/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ThermalNeutronScatteringLaw_incoherentInelastic

} // namespace tsl
} // namespace v2_0
} // namespace test

#endif
