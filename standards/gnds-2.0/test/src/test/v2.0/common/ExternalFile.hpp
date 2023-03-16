
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COMMON_EXTERNALFILE
#define TEST_V2_0_COMMON_EXTERNALFILE

#include "test/v2.0/key.hpp"

namespace test {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class ExternalFile
// -----------------------------------------------------------------------------

class ExternalFile :
   public Component<common::ExternalFile>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "ExternalFile"; }
   static auto NODENAME() { return "externalFile"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         XMLName{}
            / Meta<>("label") |
         XMLName{}
            / Meta<>("path") |
         std::optional<std::string>{}
            / Meta<>("checksum") |
         std::optional<enums::HashAlgorithm>{}
            / Meta<>("algorithm")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "path",
         "checksum",
         "algorithm"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "path",
         "checksum",
         "algorithm"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<XMLName>
      label{this};
   Field<XMLName>
      path{this};
   Field<std::optional<std::string>>
      checksum{this};
   Field<std::optional<enums::HashAlgorithm>>
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
      const wrapper<XMLName>
         &label,
      const wrapper<XMLName>
         &path = {},
      const wrapper<std::optional<std::string>>
         &checksum = {},
      const wrapper<std::optional<enums::HashAlgorithm>>
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

   #include "test/v2.0/common/ExternalFile/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ExternalFile

} // namespace common
} // namespace v2_0
} // namespace test

#endif
