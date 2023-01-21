
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW
#define TEST_V2_0_TSL_THERMALNEUTRONSCATTERINGLAW

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class ThermalNeutronScatteringLaw
// -----------------------------------------------------------------------------

class ThermalNeutronScatteringLaw :
   public Component<tsl::ThermalNeutronScatteringLaw>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "ThermalNeutronScatteringLaw"; }
   static auto FIELD() { return "thermalNeutronScatteringLaw"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("href")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->href)

   // default
   ThermalNeutronScatteringLaw() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ThermalNeutronScatteringLaw(
      const wrapper<XMLName> &label,
      const wrapper<XMLName> &href = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit ThermalNeutronScatteringLaw(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ThermalNeutronScatteringLaw(const ThermalNeutronScatteringLaw &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      href(this,other.href)
   {
      Component::finish(other);
   }

   // move
   ThermalNeutronScatteringLaw(ThermalNeutronScatteringLaw &&other) :
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

   ThermalNeutronScatteringLaw &operator=(const ThermalNeutronScatteringLaw &) = default;
   ThermalNeutronScatteringLaw &operator=(ThermalNeutronScatteringLaw &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/tsl/ThermalNeutronScatteringLaw/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ThermalNeutronScatteringLaw

} // namespace tsl
} // namespace v2_0
} // namespace test

#endif
