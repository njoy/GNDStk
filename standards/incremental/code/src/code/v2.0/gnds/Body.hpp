
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_BODY
#define CODE_V2_0_GNDS_BODY

#include "code/v2.0/key.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class Body
// -----------------------------------------------------------------------------

class Body : public Component<gnds::Body,true> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "Body"; }
   static auto FIELD() { return "body"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return std::tuple<>{};
   }

public:
   using Component::construct;
   using BlockData::operator=;

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata)

   // default
   Body() :
      GNDSTK_COMPONENT(BlockData{})
   {
      std::cout << "ctor: Body: default" << std::endl;
      Component::finish();
   }

   // from node
   explicit Body(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      std::cout << "ctor: Body: node" << std::endl;
      Component::finish(node);
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   Body(const std::vector<T> &vector) :
      GNDSTK_COMPONENT(BlockData{})
   {
      std::cout << "ctor: Body: vector" << std::endl;
      Component::finish(vector);
   }

   // copy
   Body(const Body &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: Body: copy" << std::endl;
      Component::finish(other);
   }

   // move
   Body(Body &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      std::cout << "ctor: Body: move" << std::endl;
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Body &operator=(const Body &other)
   {
      if (this != &other) {
         std::cout << "assign: Body: copy" << std::endl;
         Component::operator=(other);
      }
      return *this;
   }

   // move
   Body &operator=(Body &&other)
   {
      if (this != &other) {
         std::cout << "assign: Body: move" << std::endl;
         Component::operator=(std::move(other));
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/Body/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Body

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
