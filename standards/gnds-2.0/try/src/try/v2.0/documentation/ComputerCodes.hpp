
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_DOCUMENTATION_COMPUTERCODES
#define TRY_V2_0_DOCUMENTATION_COMPUTERCODES

#include "try/v2.0/documentation/ComputerCode.hpp"

namespace try {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class ComputerCodes
// -----------------------------------------------------------------------------

class ComputerCodes : public Component<documentation::ComputerCodes> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "ComputerCodes"; }
   static auto FIELD() { return "computerCodes"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         documentation::ComputerCode{}
            / ++Child<>("computerCode")
      ;
   }

public:
   using Component::construct;

   // children
   Field<std::vector<documentation::ComputerCode>> computerCode{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->computerCode)

   // default, and from fields
   explicit ComputerCodes(
      const wrapper<std::vector<documentation::ComputerCode>> &computerCode = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      computerCode(this,computerCode)
   {
      Component::finish();
   }

   // from node
   explicit ComputerCodes(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ComputerCodes(const ComputerCodes &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ComputerCodes(ComputerCodes &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ComputerCodes &operator=(const ComputerCodes &) = default;
   ComputerCodes &operator=(ComputerCodes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/documentation/ComputerCodes/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ComputerCodes

} // namespace documentation
} // namespace v2_0
} // namespace try

#endif
