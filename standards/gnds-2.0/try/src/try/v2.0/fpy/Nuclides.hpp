
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_FPY_NUCLIDES
#define TRY_V2_0_FPY_NUCLIDES

#include "try/v2.0/key.hpp"

namespace try {
namespace v2_0 {
namespace fpy {

// -----------------------------------------------------------------------------
// fpy::
// class Nuclides
// -----------------------------------------------------------------------------

class Nuclides : public Component<fpy::Nuclides,true> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "fpy"; }
   static auto CLASS() { return "Nuclides"; }
   static auto FIELD() { return "nuclides"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         std::optional<std::string>{}
            / Meta<>("href")
      ;
   }

public:
   using Component::construct;
   using BlockData::operator=;

   // metadata
   Field<std::optional<std::string>> href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->href)

   // default, and from fields
   explicit Nuclides(
      const wrapper<std::optional<std::string>> &href = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit Nuclides(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   Nuclides(const std::vector<T> &vector) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(vector);
   }

   // copy
   Nuclides(const Nuclides &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   Nuclides(Nuclides &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Nuclides &operator=(const Nuclides &) = default;
   Nuclides &operator=(Nuclides &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/fpy/Nuclides/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Nuclides

} // namespace fpy
} // namespace v2_0
} // namespace try

#endif