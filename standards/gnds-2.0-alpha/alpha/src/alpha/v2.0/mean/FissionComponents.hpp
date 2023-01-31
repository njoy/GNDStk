
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_FISSIONCOMPONENTS
#define ALPHA_V2_0_MEAN_FISSIONCOMPONENTS

#include "alpha/v2.0/mean/FissionComponent.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class FissionComponents
// -----------------------------------------------------------------------------

class FissionComponents :
   public Component<mean::FissionComponents>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "FissionComponents"; }
   static auto FIELD() { return "fissionComponents"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<std::optional<mean::FissionComponent>>("fissionComponent")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<std::vector<mean::FissionComponent>>> fissionComponent{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->fissionComponent)

   // default
   FissionComponents() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit FissionComponents(
      const wrapper<std::optional<std::vector<mean::FissionComponent>>> &fissionComponent
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

   FissionComponents &operator=(const FissionComponents &) = default;
   FissionComponents &operator=(FissionComponents &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/FissionComponents/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class FissionComponents

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
