
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_TSL_SCATTERINGATOM
#define NJOY_GNDSTK_V2_0_TSL_SCATTERINGATOM

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/tsl/BoundAtomCrossSection.hpp"
#include "GNDStk/v2.0/tsl/CoherentAtomCrossSection.hpp"
#include "GNDStk/v2.0/tsl/DistinctScatteringKernel.hpp"
#include "GNDStk/v2.0/tsl/E_critical.hpp"
#include "GNDStk/v2.0/tsl/E_max.hpp"
#include "GNDStk/v2.0/ambiguousNamespace/Mass.hpp"
#include "GNDStk/v2.0/tsl/SelfScatteringKernel.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// tsl::
// class ScatteringAtom
// -----------------------------------------------------------------------------

namespace tsl {

class ScatteringAtom : public Component<ScatteringAtom> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "tsl"; }
   static auto className() { return "ScatteringAtom"; }
   static auto GNDSName() { return "scatteringAtom"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         Integer32{}
            / Meta<>("numberPerMolecule") |
         XMLName{}
            / Meta<>("pid") |
         bool{}
            / Meta<>("primaryScatterer") |
         // children
         tsl::BoundAtomCrossSection{}
            / --Child<>("boundAtomCrossSection") |
         std::optional<tsl::CoherentAtomCrossSection>{}
            / --Child<>("coherentAtomCrossSection") |
         std::optional<tsl::DistinctScatteringKernel>{}
            / --Child<>("distinctScatteringKernel") |
         std::optional<tsl::E_critical>{}
            / --Child<>("e_critical") |
         tsl::E_max{}
            / --Child<>("e_max") |
         ambiguousNamespace::Mass{}
            / --Child<>("mass") |
         tsl::SelfScatteringKernel{}
            / --Child<>("selfScatteringKernel")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      Integer32 numberPerMolecule;
      XMLName pid;
      bool primaryScatterer;
      // children
      tsl::BoundAtomCrossSection boundAtomCrossSection;
      std::optional<tsl::CoherentAtomCrossSection> coherentAtomCrossSection;
      std::optional<tsl::DistinctScatteringKernel> distinctScatteringKernel;
      std::optional<tsl::E_critical> e_critical;
      tsl::E_max e_max;
      ambiguousNamespace::Mass mass;
      tsl::SelfScatteringKernel selfScatteringKernel;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // numberPerMolecule
   const Integer32 &numberPerMolecule() const
      { return content.numberPerMolecule; }
   Integer32 &numberPerMolecule()
      { return content.numberPerMolecule; }

   // pid
   const XMLName &pid() const
      { return content.pid; }
   XMLName &pid()
      { return content.pid; }

   // primaryScatterer
   const bool &primaryScatterer() const
      { return content.primaryScatterer; }
   bool &primaryScatterer()
      { return content.primaryScatterer; }

   // boundAtomCrossSection
   const tsl::BoundAtomCrossSection &boundAtomCrossSection() const
      { return content.boundAtomCrossSection; }
   tsl::BoundAtomCrossSection &boundAtomCrossSection()
      { return content.boundAtomCrossSection; }

   // coherentAtomCrossSection
   const std::optional<tsl::CoherentAtomCrossSection> &coherentAtomCrossSection() const
      { return content.coherentAtomCrossSection; }
   std::optional<tsl::CoherentAtomCrossSection> &coherentAtomCrossSection()
      { return content.coherentAtomCrossSection; }

   // distinctScatteringKernel
   const std::optional<tsl::DistinctScatteringKernel> &distinctScatteringKernel() const
      { return content.distinctScatteringKernel; }
   std::optional<tsl::DistinctScatteringKernel> &distinctScatteringKernel()
      { return content.distinctScatteringKernel; }

   // e_critical
   const std::optional<tsl::E_critical> &e_critical() const
      { return content.e_critical; }
   std::optional<tsl::E_critical> &e_critical()
      { return content.e_critical; }

   // e_max
   const tsl::E_max &e_max() const
      { return content.e_max; }
   tsl::E_max &e_max()
      { return content.e_max; }

   // mass
   const ambiguousNamespace::Mass &mass() const
      { return content.mass; }
   ambiguousNamespace::Mass &mass()
      { return content.mass; }

   // selfScatteringKernel
   const tsl::SelfScatteringKernel &selfScatteringKernel() const
      { return content.selfScatteringKernel; }
   tsl::SelfScatteringKernel &selfScatteringKernel()
      { return content.selfScatteringKernel; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // numberPerMolecule(value)
   ScatteringAtom &numberPerMolecule(const Integer32 &obj)
      { numberPerMolecule() = obj; return *this; }

   // pid(value)
   ScatteringAtom &pid(const XMLName &obj)
      { pid() = obj; return *this; }

   // primaryScatterer(value)
   ScatteringAtom &primaryScatterer(const bool &obj)
      { primaryScatterer() = obj; return *this; }

   // boundAtomCrossSection(value)
   ScatteringAtom &boundAtomCrossSection(const tsl::BoundAtomCrossSection &obj)
      { boundAtomCrossSection() = obj; return *this; }

   // coherentAtomCrossSection(value)
   ScatteringAtom &coherentAtomCrossSection(const std::optional<tsl::CoherentAtomCrossSection> &obj)
      { coherentAtomCrossSection() = obj; return *this; }

   // distinctScatteringKernel(value)
   ScatteringAtom &distinctScatteringKernel(const std::optional<tsl::DistinctScatteringKernel> &obj)
      { distinctScatteringKernel() = obj; return *this; }

   // e_critical(value)
   ScatteringAtom &e_critical(const std::optional<tsl::E_critical> &obj)
      { e_critical() = obj; return *this; }

   // e_max(value)
   ScatteringAtom &e_max(const tsl::E_max &obj)
      { e_max() = obj; return *this; }

   // mass(value)
   ScatteringAtom &mass(const ambiguousNamespace::Mass &obj)
      { mass() = obj; return *this; }

   // selfScatteringKernel(value)
   ScatteringAtom &selfScatteringKernel(const tsl::SelfScatteringKernel &obj)
      { selfScatteringKernel() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   ScatteringAtom() :
      Component{
         BodyText{},
         content.numberPerMolecule,
         content.pid,
         content.primaryScatterer,
         content.boundAtomCrossSection,
         content.coherentAtomCrossSection,
         content.distinctScatteringKernel,
         content.e_critical,
         content.e_max,
         content.mass,
         content.selfScatteringKernel
      }
   {
      Component::finish();
   }

   // copy
   ScatteringAtom(const ScatteringAtom &other) :
      Component{
         other,
         content.numberPerMolecule,
         content.pid,
         content.primaryScatterer,
         content.boundAtomCrossSection,
         content.coherentAtomCrossSection,
         content.distinctScatteringKernel,
         content.e_critical,
         content.e_max,
         content.mass,
         content.selfScatteringKernel
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   ScatteringAtom(ScatteringAtom &&other) :
      Component{
         other,
         content.numberPerMolecule,
         content.pid,
         content.primaryScatterer,
         content.boundAtomCrossSection,
         content.coherentAtomCrossSection,
         content.distinctScatteringKernel,
         content.e_critical,
         content.e_max,
         content.mass,
         content.selfScatteringKernel
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   ScatteringAtom(const Node &node) :
      Component{
         BodyText{},
         content.numberPerMolecule,
         content.pid,
         content.primaryScatterer,
         content.boundAtomCrossSection,
         content.coherentAtomCrossSection,
         content.distinctScatteringKernel,
         content.e_critical,
         content.e_max,
         content.mass,
         content.selfScatteringKernel
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit ScatteringAtom(
      const Integer32 &numberPerMolecule,
      const XMLName &pid,
      const bool &primaryScatterer,
      const tsl::BoundAtomCrossSection &boundAtomCrossSection,
      const std::optional<tsl::CoherentAtomCrossSection> &coherentAtomCrossSection,
      const std::optional<tsl::DistinctScatteringKernel> &distinctScatteringKernel,
      const std::optional<tsl::E_critical> &e_critical,
      const tsl::E_max &e_max,
      const ambiguousNamespace::Mass &mass,
      const tsl::SelfScatteringKernel &selfScatteringKernel
   ) :
      Component{
         BodyText{},
         content.numberPerMolecule,
         content.pid,
         content.primaryScatterer,
         content.boundAtomCrossSection,
         content.coherentAtomCrossSection,
         content.distinctScatteringKernel,
         content.e_critical,
         content.e_max,
         content.mass,
         content.selfScatteringKernel
      },
      content{
         numberPerMolecule,
         pid,
         primaryScatterer,
         boundAtomCrossSection,
         coherentAtomCrossSection,
         distinctScatteringKernel,
         e_critical,
         e_max,
         mass,
         selfScatteringKernel
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   ScatteringAtom &operator=(const ScatteringAtom &) = default;

   // move
   ScatteringAtom &operator=(ScatteringAtom &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/tsl/ScatteringAtom/src/custom.hpp"

}; // class ScatteringAtom

} // namespace tsl
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif