
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_COMMON_EXTERNALFILES
#define TEST_V2_0_COMMON_EXTERNALFILES

#include "test/v2.0/common/ExternalFile.hpp"

namespace test {
namespace v2_0 {
namespace common {

// -----------------------------------------------------------------------------
// common::
// class ExternalFiles
// -----------------------------------------------------------------------------

class ExternalFiles :
   public Component<common::ExternalFiles>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "ExternalFiles"; }
   static auto NODENAME() { return "externalFiles"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<common::ExternalFile>
            ("externalFile")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "externalFile"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "external_file"
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

   // children
   Field<std::vector<common::ExternalFile>>
      externalFile{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->externalFile \
   )

   // default
   ExternalFiles() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ExternalFiles(
      const wrapper<std::vector<common::ExternalFile>>
         &externalFile
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      externalFile(this,externalFile)
   {
      Component::finish();
   }

   // from node
   explicit ExternalFiles(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ExternalFiles(const ExternalFiles &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      externalFile(this,other.externalFile)
   {
      Component::finish(other);
   }

   // move
   ExternalFiles(ExternalFiles &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      externalFile(this,std::move(other.externalFile))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ExternalFiles &operator=(const ExternalFiles &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         externalFile = other.externalFile;
      }
      return *this;
   }

   // move
   ExternalFiles &operator=(ExternalFiles &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         externalFile = std::move(other.externalFile);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/common/ExternalFiles/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ExternalFiles

} // namespace common
} // namespace v2_0
} // namespace test

#endif
