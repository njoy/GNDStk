
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_ADD
#define ALPHA_V2_0_GENERAL_ADD

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Add
// -----------------------------------------------------------------------------

class Add :
   public Component<general::Add>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Add"; }
   static auto FIELD() { return "add"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("href")
      ;
   }

public:
   using component_t = Component;
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string>
      href{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->href \
   )

   // default
   Add() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Add(
      const wrapper<std::string>
         &href
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href)
   {
      Component::finish();
   }

   // from node
   explicit Add(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Add(const Add &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      href(this,other.href)
   {
      Component::finish(other);
   }

   // move
   Add(Add &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      href(this,std::move(other.href))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Add &operator=(const Add &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         href = other.href;
      }
      return *this;
   }

   // move
   Add &operator=(Add &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         href = std::move(other.href);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Add/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Add

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
