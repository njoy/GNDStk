
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_TSL_S_TABLE
#define TRY_V2_0_TSL_S_TABLE

#include "try/v2.0/unknownNamespace/Gridded2d.hpp"

namespace try {
namespace v2_0 {
namespace tsl {

// -----------------------------------------------------------------------------
// tsl::
// class S_table
// -----------------------------------------------------------------------------

class S_table : public Component<tsl::S_table> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "tsl"; }
   static auto CLASS() { return "S_table"; }
   static auto FIELD() { return "S_table"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         unknownNamespace::Gridded2d{}
            / --Child<>("gridded2d")
      ;
   }

public:
   using Component::construct;

   // children
   Field<unknownNamespace::Gridded2d> gridded2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->gridded2d)

   // default, and from fields
   explicit S_table(
      const wrapper<unknownNamespace::Gridded2d> &gridded2d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      gridded2d(this,gridded2d)
   {
      Component::finish();
   }

   // from node
   explicit S_table(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   S_table(const S_table &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   S_table(S_table &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   S_table &operator=(const S_table &) = default;
   S_table &operator=(S_table &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/tsl/S_table/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class S_table

} // namespace tsl
} // namespace v2_0
} // namespace try

#endif
