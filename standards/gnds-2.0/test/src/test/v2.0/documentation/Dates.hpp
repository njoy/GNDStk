
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_DATES
#define TEST_V2_0_DOCUMENTATION_DATES

#include "test/v2.0/documentation/Date.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Dates
// -----------------------------------------------------------------------------

class Dates : public Component<documentation::Dates> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Dates"; }
   static auto FIELD() { return "dates"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         documentation::Date{}
            / ++Child<>("date")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<documentation::Date>> date{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->date)

   // default, and from fields
   explicit Dates(
      const wrapper<std::vector<documentation::Date>> &date = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      date(this,date)
   {
      Component::finish();
   }

   // from node
   explicit Dates(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Dates(const Dates &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Dates(Dates &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Dates &operator=(const Dates &) = default;
   Dates &operator=(Dates &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/Dates/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Dates

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif