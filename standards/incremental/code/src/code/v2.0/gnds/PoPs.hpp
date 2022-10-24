
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_POPS
#define CODE_V2_0_GNDS_POPS

#include "code/v2.0/gnds/Styles.hpp"
#include "code/v2.0/gnds/ChemicalElements.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class PoPs
// -----------------------------------------------------------------------------

class PoPs : public Component<gnds::PoPs> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "PoPs"; }
   static auto FIELD() { return "PoPs"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("name") |
         std::string{}
            / Meta<>("version") |
         std::string{}
            / Meta<>("format") |
         // children
         gnds::Styles{}
            / --Child<>("styles") |
         gnds::ChemicalElements{}
            / --Child<>("chemicalElements")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> name{this};
   Field<std::string> version{this};
   Field<std::string> format{this};

   // children
   Field<gnds::Styles> styles{this};
   Field<gnds::ChemicalElements> chemicalElements{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->name, \
      this->version, \
      this->format, \
      this->styles, \
      this->chemicalElements)

   // default, and from fields
   explicit PoPs(
      const wrapper<std::string> &name = {},
      const wrapper<std::string> &version = {},
      const wrapper<std::string> &format = {},
      const wrapper<gnds::Styles> &styles = {},
      const wrapper<gnds::ChemicalElements> &chemicalElements = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      name(this,name),
      version(this,version),
      format(this,format),
      styles(this,styles),
      chemicalElements(this,chemicalElements)
   {
      Component::finish();
   }

   // from node
   explicit PoPs(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   PoPs(const PoPs &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   PoPs(PoPs &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   PoPs &operator=(const PoPs &) = default;
   PoPs &operator=(PoPs &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/PoPs/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class PoPs

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
