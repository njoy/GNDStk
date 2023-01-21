
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_RESONANCES_J
#define TEST_V2_0_RESONANCES_J

#include "test/v2.0/resonances/LevelSpacing.hpp"
#include "test/v2.0/resonances/Widths.hpp"

namespace test {
namespace v2_0 {
namespace resonances {

// -----------------------------------------------------------------------------
// resonances::
// class J
// -----------------------------------------------------------------------------

class J :
   public Component<resonances::J>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "resonances"; }
   static auto CLASS() { return "J"; }
   static auto FIELD() { return "J"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("label") |
         Fraction32{}
            / Meta<>("value") |

         // children
         --Child<resonances::LevelSpacing>("levelSpacing") |
         --Child<resonances::Widths>("widths")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<XMLName> label{this};
   Field<Fraction32> value{this};

   // children
   Field<resonances::LevelSpacing> levelSpacing{this};
   Field<resonances::Widths> widths{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->value, \
      this->levelSpacing, \
      this->widths)

   // default
   J() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit J(
      const wrapper<XMLName> &label,
      const wrapper<Fraction32> &value = {},
      const wrapper<resonances::LevelSpacing> &levelSpacing = {},
      const wrapper<resonances::Widths> &widths = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      value(this,value),
      levelSpacing(this,levelSpacing),
      widths(this,widths)
   {
      Component::finish();
   }

   // from node
   explicit J(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   J(const J &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      value(this,other.value),
      levelSpacing(this,other.levelSpacing),
      widths(this,other.widths)
   {
      Component::finish(other);
   }

   // move
   J(J &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      value(this,std::move(other.value)),
      levelSpacing(this,std::move(other.levelSpacing)),
      widths(this,std::move(other.widths))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   J &operator=(const J &) = default;
   J &operator=(J &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/resonances/J/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class J

} // namespace resonances
} // namespace v2_0
} // namespace test

#endif
