
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_DOUBLE
#define CODE_V2_0_GNDS_DOUBLE

#include "code/v2.0/key.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Double
// -----------------------------------------------------------------------------

class Double : public Component<gnds::Double> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Double"; }
   static auto FIELD() { return "double"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("label") |
         double{}
            / Meta<>("value") |
         std::string{}
            / Meta<>("unit")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> label{this};
   Field<double> value{this};
   Field<std::string> unit{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->value, \
      this->unit)

   // default, and from fields
   explicit Double(
      const wrapper<std::string> &label = {},
      const wrapper<double> &value = {},
      const wrapper<std::string> &unit = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      value(this,value),
      unit(this,unit)
   {
      Component::finish();
   }

   // from node
   explicit Double(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Double(const Double &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Double(Double &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Double &operator=(const Double &) = default;
   Double &operator=(Double &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Double/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Double

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
