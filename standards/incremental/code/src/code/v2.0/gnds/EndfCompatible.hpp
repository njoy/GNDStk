
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef CODE_V2_0_GNDS_ENDFCOMPATIBLE
#define CODE_V2_0_GNDS_ENDFCOMPATIBLE

#include "code/v2.0/key.hpp"

namespace code {
namespace v2_0 {
namespace gnds {

// -----------------------------------------------------------------------------
// gnds::
// class EndfCompatible
// -----------------------------------------------------------------------------

class EndfCompatible : public Component<gnds::EndfCompatible,true> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "gnds"; }
   static auto CLASS() { return "EndfCompatible"; }
   static auto FIELD() { return "endfCompatible"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment)/commentConverter{}
      ;
   }

public:
   using Component::construct;
   using BlockData::operator=;

   // comment
   Field<std::vector<std::string>> comment{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment)

   // default
   EndfCompatible() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit EndfCompatible(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   EndfCompatible(const std::vector<T> &vector) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(vector);
   }

   // copy
   EndfCompatible(const EndfCompatible &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment)
   {
      Component::finish(other);
   }

   // move
   EndfCompatible(EndfCompatible &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   EndfCompatible &operator=(const EndfCompatible &) = default;
   EndfCompatible &operator=(EndfCompatible &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "code/v2.0/gnds/EndfCompatible/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class EndfCompatible

} // namespace gnds
} // namespace v2_0
} // namespace code

#endif
