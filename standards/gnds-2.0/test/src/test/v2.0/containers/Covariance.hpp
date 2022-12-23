
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CONTAINERS_COVARIANCE
#define TEST_V2_0_CONTAINERS_COVARIANCE

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace containers {

// -----------------------------------------------------------------------------
// containers::
// class Covariance
// -----------------------------------------------------------------------------

class Covariance : public Component<containers::Covariance> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "containers"; }
   static auto CLASS() { return "Covariance"; }
   static auto FIELD() { return "covariance"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<std::string>{}
            / Meta<>("href")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<std::optional<XMLName>> label{this};
   Field<std::optional<std::string>> href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->href)

   // default
   Covariance() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields
   explicit Covariance(
      const wrapper<std::optional<XMLName>> &label,
      const wrapper<std::optional<std::string>> &href = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit Covariance(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Covariance(const Covariance &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,other.label),
      href(this,other.href)
   {
      Component::finish(other);
   }

   // move
   Covariance(Covariance &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      label(this,std::move(other.label)),
      href(this,std::move(other.href))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Covariance &operator=(const Covariance &) = default;
   Covariance &operator=(Covariance &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/containers/Covariance/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Covariance

} // namespace containers
} // namespace v2_0
} // namespace test

#endif
