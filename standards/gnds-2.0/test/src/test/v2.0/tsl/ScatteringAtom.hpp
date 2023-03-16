
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TSL_SCATTERINGATOM
#define TEST_V2_0_TSL_SCATTERINGATOM

#include "test/v2.0/tsl/Mass.hpp"
#include "test/v2.0/tsl/E_critical.hpp"
#include "test/v2.0/tsl/E_max.hpp"
#include "test/v2.0/tsl/BoundAtomCrossSection.hpp"
#include "test/v2.0/tsl/CoherentAtomCrossSection.hpp"
#include "test/v2.0/tsl/DistinctScatteringKernel.hpp"
#include "test/v2.0/tsl/SelfScatteringKernel.hpp"
#include "test/v2.0/tsl/T_effective.hpp"

namespace test {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class ScatteringAtom
// -----------------------------------------------------------------------------

class ScatteringAtom :
   public Component<tsl::ScatteringAtom>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "ScatteringAtom"; }
   static auto NODENAME() { return "scatteringAtom"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("pid") |
         bool{}
            / Meta<>("primaryScatterer") |
         Integer32{}
            / Meta<>("numberPerMolecule") |

         // children
         --Child<tsl::Mass>
            ("mass") |
         --Child<std::optional<tsl::E_critical>>
            ("e_critical") |
         --Child<tsl::E_max>
            ("e_max") |
         --Child<tsl::BoundAtomCrossSection>
            ("boundAtomCrossSection") |
         --Child<std::optional<tsl::CoherentAtomCrossSection>>
            ("coherentAtomCrossSection") |
         --Child<std::optional<tsl::DistinctScatteringKernel>>
            ("distinctScatteringKernel") |
         --Child<tsl::SelfScatteringKernel>
            ("selfScatteringKernel") |
         --Child<std::optional<tsl::T_effective>>
            ("T_effective")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "pid",
         "primaryScatterer",
         "numberPerMolecule",
         "mass",
         "e_critical",
         "e_max",
         "boundAtomCrossSection",
         "coherentAtomCrossSection",
         "distinctScatteringKernel",
         "selfScatteringKernel",
         "T_effective"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "pid",
         "primary_scatterer",
         "number_per_molecule",
         "mass",
         "e_critical",
         "e_max",
         "bound_atom_cross_section",
         "coherent_atom_cross_section",
         "distinct_scattering_kernel",
         "self_scattering_kernel",
         "t_effective"
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
   Field<XMLName>
      pid{this};
   Field<bool>
      primaryScatterer{this};
   Field<Integer32>
      numberPerMolecule{this};

   // children
   Field<tsl::Mass>
      mass{this};
   Field<std::optional<tsl::E_critical>>
      e_critical{this};
   Field<tsl::E_max>
      e_max{this};
   Field<tsl::BoundAtomCrossSection>
      boundAtomCrossSection{this};
   Field<std::optional<tsl::CoherentAtomCrossSection>>
      coherentAtomCrossSection{this};
   Field<std::optional<tsl::DistinctScatteringKernel>>
      distinctScatteringKernel{this};
   Field<tsl::SelfScatteringKernel>
      selfScatteringKernel{this};
   Field<std::optional<tsl::T_effective>>
      T_effective{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->pid, \
      this->primaryScatterer, \
      this->numberPerMolecule, \
      this->mass, \
      this->e_critical, \
      this->e_max, \
      this->boundAtomCrossSection, \
      this->coherentAtomCrossSection, \
      this->distinctScatteringKernel, \
      this->selfScatteringKernel, \
      this->T_effective \
   )

   // default
   ScatteringAtom() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ScatteringAtom(
      const wrapper<XMLName>
         &pid,
      const wrapper<bool>
         &primaryScatterer = {},
      const wrapper<Integer32>
         &numberPerMolecule = {},
      const wrapper<tsl::Mass>
         &mass = {},
      const wrapper<std::optional<tsl::E_critical>>
         &e_critical = {},
      const wrapper<tsl::E_max>
         &e_max = {},
      const wrapper<tsl::BoundAtomCrossSection>
         &boundAtomCrossSection = {},
      const wrapper<std::optional<tsl::CoherentAtomCrossSection>>
         &coherentAtomCrossSection = {},
      const wrapper<std::optional<tsl::DistinctScatteringKernel>>
         &distinctScatteringKernel = {},
      const wrapper<tsl::SelfScatteringKernel>
         &selfScatteringKernel = {},
      const wrapper<std::optional<tsl::T_effective>>
         &T_effective = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      pid(this,pid),
      primaryScatterer(this,primaryScatterer),
      numberPerMolecule(this,numberPerMolecule),
      mass(this,mass),
      e_critical(this,e_critical),
      e_max(this,e_max),
      boundAtomCrossSection(this,boundAtomCrossSection),
      coherentAtomCrossSection(this,coherentAtomCrossSection),
      distinctScatteringKernel(this,distinctScatteringKernel),
      selfScatteringKernel(this,selfScatteringKernel),
      T_effective(this,T_effective)
   {
      Component::finish();
   }

   // from node
   explicit ScatteringAtom(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ScatteringAtom(const ScatteringAtom &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      pid(this,other.pid),
      primaryScatterer(this,other.primaryScatterer),
      numberPerMolecule(this,other.numberPerMolecule),
      mass(this,other.mass),
      e_critical(this,other.e_critical),
      e_max(this,other.e_max),
      boundAtomCrossSection(this,other.boundAtomCrossSection),
      coherentAtomCrossSection(this,other.coherentAtomCrossSection),
      distinctScatteringKernel(this,other.distinctScatteringKernel),
      selfScatteringKernel(this,other.selfScatteringKernel),
      T_effective(this,other.T_effective)
   {
      Component::finish(other);
   }

   // move
   ScatteringAtom(ScatteringAtom &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      pid(this,std::move(other.pid)),
      primaryScatterer(this,std::move(other.primaryScatterer)),
      numberPerMolecule(this,std::move(other.numberPerMolecule)),
      mass(this,std::move(other.mass)),
      e_critical(this,std::move(other.e_critical)),
      e_max(this,std::move(other.e_max)),
      boundAtomCrossSection(this,std::move(other.boundAtomCrossSection)),
      coherentAtomCrossSection(this,std::move(other.coherentAtomCrossSection)),
      distinctScatteringKernel(this,std::move(other.distinctScatteringKernel)),
      selfScatteringKernel(this,std::move(other.selfScatteringKernel)),
      T_effective(this,std::move(other.T_effective))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ScatteringAtom &operator=(const ScatteringAtom &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         pid = other.pid;
         primaryScatterer = other.primaryScatterer;
         numberPerMolecule = other.numberPerMolecule;
         mass = other.mass;
         e_critical = other.e_critical;
         e_max = other.e_max;
         boundAtomCrossSection = other.boundAtomCrossSection;
         coherentAtomCrossSection = other.coherentAtomCrossSection;
         distinctScatteringKernel = other.distinctScatteringKernel;
         selfScatteringKernel = other.selfScatteringKernel;
         T_effective = other.T_effective;
      }
      return *this;
   }

   // move
   ScatteringAtom &operator=(ScatteringAtom &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         pid = std::move(other.pid);
         primaryScatterer = std::move(other.primaryScatterer);
         numberPerMolecule = std::move(other.numberPerMolecule);
         mass = std::move(other.mass);
         e_critical = std::move(other.e_critical);
         e_max = std::move(other.e_max);
         boundAtomCrossSection = std::move(other.boundAtomCrossSection);
         coherentAtomCrossSection = std::move(other.coherentAtomCrossSection);
         distinctScatteringKernel = std::move(other.distinctScatteringKernel);
         selfScatteringKernel = std::move(other.selfScatteringKernel);
         T_effective = std::move(other.T_effective);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/tsl/ScatteringAtom/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ScatteringAtom

} // namespace tsl
} // namespace v2_0
} // namespace test

#endif
