
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_TABULATEDWIDTHS
#define TEST_V2_0_RESONANCES_TABULATEDWIDTHS

#include "test/v2.0/pops/PoPs_database.hpp"
#include "test/v2.0/resonances/ScatteringRadius.hpp"
#include "test/v2.0/resonances/HardSphereRadius.hpp"
#include "test/v2.0/resonances/ResonanceReactions.hpp"
#include "test/v2.0/resonances/Ls.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class TabulatedWidths
// -----------------------------------------------------------------------------

class TabulatedWidths :
   public Component<resonances::TabulatedWidths>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "TabulatedWidths"; }
   static auto NODENAME() { return "tabulatedWidths"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("approximation") |
         Defaulted<bool>{false}
            / Meta<>("useForSelfShieldingOnly") |

         // children
         --Child<std::optional<pops::PoPs_database>>
            ("PoPs") |
         --Child<std::optional<resonances::ScatteringRadius>>
            ("scatteringRadius") |
         --Child<std::optional<resonances::HardSphereRadius>>
            ("hardSphereRadius") |
         --Child<resonances::ResonanceReactions>
            ("resonanceReactions") |
         --Child<resonances::Ls>
            ("Ls")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "approximation",
         "useForSelfShieldingOnly",
         "PoPs_database",
         "scatteringRadius",
         "hardSphereRadius",
         "resonanceReactions",
         "Ls"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "approximation",
         "use_for_self_shielding_only",
         "po_ps_database",
         "scattering_radius",
         "hard_sphere_radius",
         "resonance_reactions",
         "ls"
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
      static inline const bool useForSelfShieldingOnly = false;
   } defaults;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<XMLName>
      label{this};
   Field<XMLName>
      approximation{this};
   Field<Defaulted<bool>>
      useForSelfShieldingOnly{this,defaults.useForSelfShieldingOnly};

   // children
   Field<std::optional<pops::PoPs_database>>
      PoPs_database{this};
   Field<std::optional<resonances::ScatteringRadius>>
      scatteringRadius{this};
   Field<std::optional<resonances::HardSphereRadius>>
      hardSphereRadius{this};
   Field<resonances::ResonanceReactions>
      resonanceReactions{this};
   Field<resonances::Ls>
      Ls{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->approximation, \
      this->useForSelfShieldingOnly, \
      this->PoPs_database, \
      this->scatteringRadius, \
      this->hardSphereRadius, \
      this->resonanceReactions, \
      this->Ls \
   )

   // default
   TabulatedWidths() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   // optional replaces Defaulted; this class knows the default(s)
   explicit TabulatedWidths(
      const wrapper<XMLName>
         &label,
      const wrapper<XMLName>
         &approximation = {},
      const wrapper<std::optional<bool>>
         &useForSelfShieldingOnly = {},
      const wrapper<std::optional<pops::PoPs_database>>
         &PoPs_database = {},
      const wrapper<std::optional<resonances::ScatteringRadius>>
         &scatteringRadius = {},
      const wrapper<std::optional<resonances::HardSphereRadius>>
         &hardSphereRadius = {},
      const wrapper<resonances::ResonanceReactions>
         &resonanceReactions = {},
      const wrapper<resonances::Ls>
         &Ls = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      approximation(this,approximation),
      useForSelfShieldingOnly(this,defaults.useForSelfShieldingOnly,useForSelfShieldingOnly),
      PoPs_database(this,PoPs_database),
      scatteringRadius(this,scatteringRadius),
      hardSphereRadius(this,hardSphereRadius),
      resonanceReactions(this,resonanceReactions),
      Ls(this,Ls)
   {
      Component::finish();
   }

   // from node
   explicit TabulatedWidths(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   TabulatedWidths(const TabulatedWidths &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      approximation(this,other.approximation),
      useForSelfShieldingOnly(this,other.useForSelfShieldingOnly),
      PoPs_database(this,other.PoPs_database),
      scatteringRadius(this,other.scatteringRadius),
      hardSphereRadius(this,other.hardSphereRadius),
      resonanceReactions(this,other.resonanceReactions),
      Ls(this,other.Ls)
   {
      Component::finish(other);
   }

   // move
   TabulatedWidths(TabulatedWidths &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      approximation(this,std::move(other.approximation)),
      useForSelfShieldingOnly(this,std::move(other.useForSelfShieldingOnly)),
      PoPs_database(this,std::move(other.PoPs_database)),
      scatteringRadius(this,std::move(other.scatteringRadius)),
      hardSphereRadius(this,std::move(other.hardSphereRadius)),
      resonanceReactions(this,std::move(other.resonanceReactions)),
      Ls(this,std::move(other.Ls))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   TabulatedWidths &operator=(const TabulatedWidths &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         approximation = other.approximation;
         useForSelfShieldingOnly = other.useForSelfShieldingOnly;
         PoPs_database = other.PoPs_database;
         scatteringRadius = other.scatteringRadius;
         hardSphereRadius = other.hardSphereRadius;
         resonanceReactions = other.resonanceReactions;
         Ls = other.Ls;
      }
      return *this;
   }

   // move
   TabulatedWidths &operator=(TabulatedWidths &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         approximation = std::move(other.approximation);
         useForSelfShieldingOnly = std::move(other.useForSelfShieldingOnly);
         PoPs_database = std::move(other.PoPs_database);
         scatteringRadius = std::move(other.scatteringRadius);
         hardSphereRadius = std::move(other.hardSphereRadius);
         resonanceReactions = std::move(other.resonanceReactions);
         Ls = std::move(other.Ls);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/TabulatedWidths/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class TabulatedWidths

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif
