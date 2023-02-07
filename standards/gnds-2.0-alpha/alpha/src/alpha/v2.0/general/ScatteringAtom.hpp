
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_SCATTERINGATOM
#define ALPHA_V2_0_GENERAL_SCATTERINGATOM

#include "alpha/v2.0/general/Mass.hpp"
#include "alpha/v2.0/general/E_critical.hpp"
#include "alpha/v2.0/general/E_max.hpp"
#include "alpha/v2.0/general/BoundAtomCrossSection.hpp"
#include "alpha/v2.0/general/SelfScatteringKernel.hpp"
#include "alpha/v2.0/general/T_effective.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ScatteringAtom
// -----------------------------------------------------------------------------

class ScatteringAtom :
   public Component<general::ScatteringAtom>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ScatteringAtom"; }
   static auto FIELD() { return "scatteringAtom"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("pid") |
         int{}
            / Meta<>("numberPerMolecule") |
         std::optional<bool>{}
            / Meta<>("primaryScatterer") |

         // children
         --Child<general::Mass>
            ("mass") |
         --Child<std::optional<general::E_critical>>
            ("e_critical") |
         --Child<general::E_max>
            ("e_max") |
         --Child<general::BoundAtomCrossSection>
            ("boundAtomCrossSection") |
         --Child<general::SelfScatteringKernel>
            ("selfScatteringKernel") |
         --Child<std::optional<general::T_effective>>
            ("T_effective")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> pid{this};
   Field<int> numberPerMolecule{this};
   Field<std::optional<bool>> primaryScatterer{this};

   // children
   Field<general::Mass>
      mass{this};
   Field<std::optional<general::E_critical>>
      e_critical{this};
   Field<general::E_max>
      e_max{this};
   Field<general::BoundAtomCrossSection>
      boundAtomCrossSection{this};
   Field<general::SelfScatteringKernel>
      selfScatteringKernel{this};
   Field<std::optional<general::T_effective>>
      T_effective{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->pid, \
      this->numberPerMolecule, \
      this->primaryScatterer, \
      this->mass, \
      this->e_critical, \
      this->e_max, \
      this->boundAtomCrossSection, \
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
      const wrapper<std::string>
         &pid,
      const wrapper<int>
         &numberPerMolecule = {},
      const wrapper<std::optional<bool>>
         &primaryScatterer = {},
      const wrapper<general::Mass>
         &mass = {},
      const wrapper<std::optional<general::E_critical>>
         &e_critical = {},
      const wrapper<general::E_max>
         &e_max = {},
      const wrapper<general::BoundAtomCrossSection>
         &boundAtomCrossSection = {},
      const wrapper<general::SelfScatteringKernel>
         &selfScatteringKernel = {},
      const wrapper<std::optional<general::T_effective>>
         &T_effective = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      pid(this,pid),
      numberPerMolecule(this,numberPerMolecule),
      primaryScatterer(this,primaryScatterer),
      mass(this,mass),
      e_critical(this,e_critical),
      e_max(this,e_max),
      boundAtomCrossSection(this,boundAtomCrossSection),
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
      numberPerMolecule(this,other.numberPerMolecule),
      primaryScatterer(this,other.primaryScatterer),
      mass(this,other.mass),
      e_critical(this,other.e_critical),
      e_max(this,other.e_max),
      boundAtomCrossSection(this,other.boundAtomCrossSection),
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
      numberPerMolecule(this,std::move(other.numberPerMolecule)),
      primaryScatterer(this,std::move(other.primaryScatterer)),
      mass(this,std::move(other.mass)),
      e_critical(this,std::move(other.e_critical)),
      e_max(this,std::move(other.e_max)),
      boundAtomCrossSection(this,std::move(other.boundAtomCrossSection)),
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
         numberPerMolecule = other.numberPerMolecule;
         primaryScatterer = other.primaryScatterer;
         mass = other.mass;
         e_critical = other.e_critical;
         e_max = other.e_max;
         boundAtomCrossSection = other.boundAtomCrossSection;
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
         numberPerMolecule = std::move(other.numberPerMolecule);
         primaryScatterer = std::move(other.primaryScatterer);
         mass = std::move(other.mass);
         e_critical = std::move(other.e_critical);
         e_max = std::move(other.e_max);
         boundAtomCrossSection = std::move(other.boundAtomCrossSection);
         selfScatteringKernel = std::move(other.selfScatteringKernel);
         T_effective = std::move(other.T_effective);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ScatteringAtom/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ScatteringAtom

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
