
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_THERMALNEUTRONSCATTERINGLAW1D
#define ALPHA_V2_0_GENERAL_THERMALNEUTRONSCATTERINGLAW1D

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ThermalNeutronScatteringLaw1d
// -----------------------------------------------------------------------------

class ThermalNeutronScatteringLaw1d :
   public Component<general::ThermalNeutronScatteringLaw1d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ThermalNeutronScatteringLaw1d"; }
   static auto FIELD() { return "thermalNeutronScatteringLaw1d"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("href")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      label{this};
   Field<std::string>
      href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->href \
   )

   // default
   ThermalNeutronScatteringLaw1d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ThermalNeutronScatteringLaw1d(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &href = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit ThermalNeutronScatteringLaw1d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ThermalNeutronScatteringLaw1d(const ThermalNeutronScatteringLaw1d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      href(this,other.href)
   {
      Component::finish(other);
   }

   // move
   ThermalNeutronScatteringLaw1d(ThermalNeutronScatteringLaw1d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      href(this,std::move(other.href))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ThermalNeutronScatteringLaw1d &operator=(const ThermalNeutronScatteringLaw1d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         href = other.href;
      }
      return *this;
   }

   // move
   ThermalNeutronScatteringLaw1d &operator=(ThermalNeutronScatteringLaw1d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         href = std::move(other.href);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ThermalNeutronScatteringLaw1d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ThermalNeutronScatteringLaw1d

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
