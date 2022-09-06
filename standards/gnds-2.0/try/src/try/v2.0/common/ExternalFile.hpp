
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TRY_V2_0_COMMON_EXTERNALFILE
#define TRY_V2_0_COMMON_EXTERNALFILE

#include "try/v2.0/key.hpp"

namespace try {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class ExternalFile
// -----------------------------------------------------------------------------

class ExternalFile : public Component<common::ExternalFile> {
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "ExternalFile"; }
   static auto FIELD() { return "externalFile"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("path") |
         std::optional<checksum>{}
            / Meta<>("checksum") |
         std::optional<algorithm>{}
            / Meta<>("algorithm")
      ;
   }

public:
   using Component::construct;

   // metadata
   Field<XMLName> label{this};
   Field<XMLName> path{this};
   Field<std::optional<checksum>> checksum{this};
   Field<std::optional<algorithm>> algorithm{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->label, \
      this->path, \
      this->checksum, \
      this->algorithm)

   // default, and from fields
   explicit ExternalFile(
      const wrapper<XMLName> &label = {},
      const wrapper<XMLName> &path = {},
      const wrapper<std::optional<checksum>> &checksum = {},
      const wrapper<std::optional<algorithm>> &algorithm = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      path(this,path),
      checksum(this,checksum),
      algorithm(this,algorithm)
   {
      Component::finish();
   }

   // from node
   explicit ExternalFile(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ExternalFile(const ExternalFile &other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = other;
      Component::finish(other);
   }

   // move
   ExternalFile(ExternalFile &&other) :
      GNDSTK_COMPONENT(other.baseBlockData())
   {
      *this = std::move(other);
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ExternalFile &operator=(const ExternalFile &) = default;
   ExternalFile &operator=(ExternalFile &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "try/v2.0/common/ExternalFile/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ExternalFile

} // namespace common
} // namespace v2_0
} // namespace try

#endif