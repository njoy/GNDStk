
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_ISOTROPIC2D
#define GNDS_V2_0_GENERAL_ISOTROPIC2D

#include "gnds/v2.0/key.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Isotropic2d
// -----------------------------------------------------------------------------

class Isotropic2d :
   public Component<general::Isotropic2d>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Isotropic2d"; }
   static auto NODENAME() { return "isotropic2d"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{}
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment"
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

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment \
   )

   // default
   Isotropic2d() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit Isotropic2d(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Isotropic2d(const Isotropic2d &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment)
   {
      Component::finish(other);
   }

   // move
   Isotropic2d(Isotropic2d &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Isotropic2d &operator=(const Isotropic2d &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
      }
      return *this;
   }

   // move
   Isotropic2d &operator=(Isotropic2d &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Isotropic2d/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Isotropic2d

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
