
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_POPS_POPS_DATABASE
#define TRY_V2_0_POPS_POPS_DATABASE

#include "try/v2.0/styles/Styles.hpp"
#include "try/v2.0/documentation/Documentation.hpp"
#include "try/v2.0/pops/Aliases.hpp"
#include "try/v2.0/pops/GaugeBosons.hpp"
#include "try/v2.0/pops/Leptons.hpp"
#include "try/v2.0/pops/Baryons.hpp"
#include "try/v2.0/pops/ChemicalElements.hpp"
#include "try/v2.0/pops/Unorthodoxes.hpp"

namespace try {
namespace v2_0 {
namespace pops {

// -----------------------------------------------------------------------------
// pops::
// class PoPs_database
// -----------------------------------------------------------------------------

class PoPs_database : public Component<pops::PoPs_database> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "pops"; }
   static auto CLASS() { return "PoPs_database"; }
   static auto FIELD() { return "PoPs"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("name") |
         XMLName{}
            / Meta<>("version") |
         XMLName{}
            / Meta<>("format") |
         // children
         std::optional<styles::Styles>{}
            / --Child<>("styles") |
         std::optional<documentation::Documentation>{}
            / --Child<>("documentation") |
         std::optional<pops::Aliases>{}
            / --Child<>("aliases") |
         std::optional<pops::GaugeBosons>{}
            / --Child<>("gaugeBosons") |
         std::optional<pops::Leptons>{}
            / --Child<>("leptons") |
         std::optional<pops::Baryons>{}
            / --Child<>("baryons") |
         std::optional<pops::ChemicalElements>{}
            / --Child<>("chemicalElements") |
         std::optional<pops::Unorthodoxes>{}
            / --Child<>("unorthodoxes")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> name{this};
   Field<XMLName> version{this};
   Field<XMLName> format{this};

   // children
   Field<std::optional<styles::Styles>> styles{this};
   Field<std::optional<documentation::Documentation>> documentation{this};
   Field<std::optional<pops::Aliases>> aliases{this};
   Field<std::optional<pops::GaugeBosons>> gaugeBosons{this};
   Field<std::optional<pops::Leptons>> leptons{this};
   Field<std::optional<pops::Baryons>> baryons{this};
   Field<std::optional<pops::ChemicalElements>> chemicalElements{this};
   Field<std::optional<pops::Unorthodoxes>> unorthodoxes{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->name, \
      this->version, \
      this->format, \
      this->styles, \
      this->documentation, \
      this->aliases, \
      this->gaugeBosons, \
      this->leptons, \
      this->baryons, \
      this->chemicalElements, \
      this->unorthodoxes)

   // default, and from fields
   explicit PoPs_database(
      const wrapper<XMLName> &name = {},
      const wrapper<XMLName> &version = {},
      const wrapper<XMLName> &format = {},
      const wrapper<std::optional<styles::Styles>> &styles = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {},
      const wrapper<std::optional<pops::Aliases>> &aliases = {},
      const wrapper<std::optional<pops::GaugeBosons>> &gaugeBosons = {},
      const wrapper<std::optional<pops::Leptons>> &leptons = {},
      const wrapper<std::optional<pops::Baryons>> &baryons = {},
      const wrapper<std::optional<pops::ChemicalElements>> &chemicalElements = {},
      const wrapper<std::optional<pops::Unorthodoxes>> &unorthodoxes = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      name(this,name),
      version(this,version),
      format(this,format),
      styles(this,styles),
      documentation(this,documentation),
      aliases(this,aliases),
      gaugeBosons(this,gaugeBosons),
      leptons(this,leptons),
      baryons(this,baryons),
      chemicalElements(this,chemicalElements),
      unorthodoxes(this,unorthodoxes)
   {
      Component::finish();
   }

   // from node
   explicit PoPs_database(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   PoPs_database(const PoPs_database &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   PoPs_database(PoPs_database &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   PoPs_database &operator=(const PoPs_database &) = default;
   PoPs_database &operator=(PoPs_database &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/pops/PoPs_database/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class PoPs_database

} // namespace pops
} // namespace v2_0
} // namespace try

#endif
