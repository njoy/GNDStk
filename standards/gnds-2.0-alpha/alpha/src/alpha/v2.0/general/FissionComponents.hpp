
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_FISSIONCOMPONENTS
#define ALPHA_V2_0_GENERAL_FISSIONCOMPONENTS

#include "alpha/v2.0/general/FissionComponent.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class FissionComponents
// -----------------------------------------------------------------------------

class FissionComponents :
   public Component<general::FissionComponents>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "FissionComponents"; }
   static auto FIELD() { return "fissionComponents"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<std::optional<general::FissionComponent>>
            ("fissionComponent")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<std::vector<general::FissionComponent>>>
      fissionComponent{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->fissionComponent \
   )

   // default
   FissionComponents() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit FissionComponents(
      const wrapper<std::optional<std::vector<general::FissionComponent>>>
         &fissionComponent
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      fissionComponent(this,fissionComponent)
   {
      Component::finish();
   }

   // from node
   explicit FissionComponents(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FissionComponents(const FissionComponents &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      fissionComponent(this,other.fissionComponent)
   {
      Component::finish(other);
   }

   // move
   FissionComponents(FissionComponents &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      fissionComponent(this,std::move(other.fissionComponent))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   FissionComponents &operator=(const FissionComponents &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         fissionComponent = other.fissionComponent;
      }
      return *this;
   }

   // move
   FissionComponents &operator=(FissionComponents &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         fissionComponent = std::move(other.fissionComponent);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/FissionComponents/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class FissionComponents

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
