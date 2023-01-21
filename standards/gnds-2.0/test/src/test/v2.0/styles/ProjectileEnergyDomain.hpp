
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_STYLES_PROJECTILEENERGYDOMAIN
#define TEST_V2_0_STYLES_PROJECTILEENERGYDOMAIN

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class ProjectileEnergyDomain
// -----------------------------------------------------------------------------

class ProjectileEnergyDomain :
   public Component<styles::ProjectileEnergyDomain>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "ProjectileEnergyDomain"; }
   static auto FIELD() { return "projectileEnergyDomain"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         Float64{}
            / Meta<>("max") |
         Float64{}
            / Meta<>("min") |
         XMLName{}
            / Meta<>("unit")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<Float64> max{this};
   Field<Float64> min{this};
   Field<XMLName> unit{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->max, \
      this->min, \
      this->unit)

   // default
   ProjectileEnergyDomain() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ProjectileEnergyDomain(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<Float64> &max = {},
      const wrapper<Float64> &min = {},
      const wrapper<XMLName> &unit = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      max(this,max),
      min(this,min),
      unit(this,unit)
   {
      Component::finish();
   }

   // from node
   explicit ProjectileEnergyDomain(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ProjectileEnergyDomain(const ProjectileEnergyDomain &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      max(this,other.max),
      min(this,other.min),
      unit(this,other.unit)
   {
      Component::finish(other);
   }

   // move
   ProjectileEnergyDomain(ProjectileEnergyDomain &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      max(this,std::move(other.max)),
      min(this,std::move(other.min)),
      unit(this,std::move(other.unit))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ProjectileEnergyDomain &operator=(const ProjectileEnergyDomain &) = default;
   ProjectileEnergyDomain &operator=(ProjectileEnergyDomain &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/styles/ProjectileEnergyDomain/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ProjectileEnergyDomain

} // namespace styles
} // namespace v2_0
} // namespace test

#endif
