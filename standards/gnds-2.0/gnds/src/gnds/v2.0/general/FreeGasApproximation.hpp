
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_FREEGASAPPROXIMATION
#define GNDS_V2_0_GENERAL_FREEGASAPPROXIMATION

#include "gnds/v2.0/key.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class FreeGasApproximation
// -----------------------------------------------------------------------------

class FreeGasApproximation :
   public Component<general::FreeGasApproximation>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "FreeGasApproximation"; }
   static auto NODENAME() { return "freeGasApproximation"; }

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
   FreeGasApproximation() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from node
   explicit FreeGasApproximation(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FreeGasApproximation(const FreeGasApproximation &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment)
   {
      Component::finish(other);
   }

   // move
   FreeGasApproximation(FreeGasApproximation &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   FreeGasApproximation &operator=(const FreeGasApproximation &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
      }
      return *this;
   }

   // move
   FreeGasApproximation &operator=(FreeGasApproximation &&other)
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

   #include "gnds/v2.0/general/FreeGasApproximation/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class FreeGasApproximation

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
