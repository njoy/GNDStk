
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_PHOTONEMISSIONPROBABILITIES
#define ALPHA_V2_0_GENERAL_PHOTONEMISSIONPROBABILITIES

#include "alpha/v2.0/general/Shell.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class PhotonEmissionProbabilities
// -----------------------------------------------------------------------------

class PhotonEmissionProbabilities :
   public Component<general::PhotonEmissionProbabilities>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "PhotonEmissionProbabilities"; }
   static auto FIELD() { return "photonEmissionProbabilities"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Shell>
            ("shell")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "shell"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "shell"
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
   Field<general::Shell>
      shell{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->shell \
   )

   // default
   PhotonEmissionProbabilities() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit PhotonEmissionProbabilities(
      const wrapper<general::Shell>
         &shell
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      shell(this,shell)
   {
      Component::finish();
   }

   // from node
   explicit PhotonEmissionProbabilities(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   PhotonEmissionProbabilities(const PhotonEmissionProbabilities &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      shell(this,other.shell)
   {
      Component::finish(other);
   }

   // move
   PhotonEmissionProbabilities(PhotonEmissionProbabilities &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      shell(this,std::move(other.shell))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   PhotonEmissionProbabilities &operator=(const PhotonEmissionProbabilities &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         shell = other.shell;
      }
      return *this;
   }

   // move
   PhotonEmissionProbabilities &operator=(PhotonEmissionProbabilities &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         shell = std::move(other.shell);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/PhotonEmissionProbabilities/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class PhotonEmissionProbabilities

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
