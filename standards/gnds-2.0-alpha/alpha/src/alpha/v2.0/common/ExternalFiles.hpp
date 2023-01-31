
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_COMMON_EXTERNALFILES
#define ALPHA_V2_0_COMMON_EXTERNALFILES

#include "alpha/v2.0/common/ExternalFile.hpp"

namespace alpha {
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

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "common"; }
   static auto CLASS() { return "ExternalFiles"; }
   static auto FIELD() { return "externalFiles"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<common::ExternalFile>("externalFile")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<common::ExternalFile>> externalFile{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->externalFile)

   // default
   ExternalFiles() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ExternalFiles(
      const wrapper<std::vector<common::ExternalFile>> &externalFile
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

   ExternalFiles &operator=(const ExternalFiles &) = default;
   ExternalFiles &operator=(ExternalFiles &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/common/ExternalFiles/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ExternalFiles

} // namespace common
} // namespace v2_0
} // namespace alpha

#endif
