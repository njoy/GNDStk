
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_BIBLIOGRAPHY
#define TEST_V2_0_DOCUMENTATION_BIBLIOGRAPHY

#include "test/v2.0/documentation/Bibitem.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class Bibliography
// -----------------------------------------------------------------------------

class Bibliography : public Component<documentation::Bibliography> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "Bibliography"; }
   static auto FIELD() { return "bibliography"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         documentation::Bibitem{}
            / ++Child<>("bibitem")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<documentation::Bibitem>> bibitem{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->bibitem)

   // default, and from fields
   explicit Bibliography(
      const wrapper<std::vector<documentation::Bibitem>> &bibitem = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      bibitem(this,bibitem)
   {
      Component::finish();
   }

   // from node
   explicit Bibliography(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Bibliography(const Bibliography &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Bibliography(Bibliography &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Bibliography &operator=(const Bibliography &) = default;
   Bibliography &operator=(Bibliography &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/Bibliography/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Bibliography

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
