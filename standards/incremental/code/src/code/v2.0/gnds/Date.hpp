
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_DATE
#define CODE_V2_0_GNDS_DATE

#include "code/v2.0/key.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Date
// -----------------------------------------------------------------------------

class Date : public Component<gnds::Date> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Date"; }
   static auto FIELD() { return "date"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::string{}
            / Meta<>("value") |
         enums::DateType{}
            / Meta<>("dateType")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::string> value{this};
   Field<enums::DateType> dateType{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->value, \
      this->dateType)

   // default
   Date() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Date(
      const wrapper<std::string> &value,
      const wrapper<enums::DateType> &dateType = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      value(this,value),
      dateType(this,dateType)
   {
      Component::finish();
   }

   // from node
   explicit Date(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Date(const Date &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      value(this,other.value),
      dateType(this,other.dateType)
   {
      Component::finish(other);
   }

   // move
   Date(Date &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      value(this,std::move(other.value)),
      dateType(this,std::move(other.dateType))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Date &operator=(const Date &) = default;
   Date &operator=(Date &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Date/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Date

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif