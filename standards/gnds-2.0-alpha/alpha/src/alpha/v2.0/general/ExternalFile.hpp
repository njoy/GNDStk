
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_EXTERNALFILE
#define ALPHA_V2_0_GENERAL_EXTERNALFILE

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ExternalFile
// -----------------------------------------------------------------------------

class ExternalFile :
   public Component<general::ExternalFile>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ExternalFile"; }
   static auto FIELD() { return "externalFile"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("path") |
         std::optional<std::string>{}
            / Meta<>("checksum") |
         std::optional<std::string>{}
            / Meta<>("algorithm")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      label{this};
   Field<std::string>
      path{this};
   Field<std::optional<std::string>>
      checksum{this};
   Field<std::optional<std::string>>
      algorithm{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->path, \
      this->checksum, \
      this->algorithm \
   )

   // default
   ExternalFile() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ExternalFile(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &path = {},
      const wrapper<std::optional<std::string>>
         &checksum = {},
      const wrapper<std::optional<std::string>>
         &algorithm = {}
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
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      path(this,other.path),
      checksum(this,other.checksum),
      algorithm(this,other.algorithm)
   {
      Component::finish(other);
   }

   // move
   ExternalFile(ExternalFile &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      path(this,std::move(other.path)),
      checksum(this,std::move(other.checksum)),
      algorithm(this,std::move(other.algorithm))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ExternalFile &operator=(const ExternalFile &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         path = other.path;
         checksum = other.checksum;
         algorithm = other.algorithm;
      }
      return *this;
   }

   // move
   ExternalFile &operator=(ExternalFile &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         path = std::move(other.path);
         checksum = std::move(other.checksum);
         algorithm = std::move(other.algorithm);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ExternalFile/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ExternalFile

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
