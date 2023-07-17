
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_DOCUMENTATION_RELATEDITEMS
#define TEST_V2_0_DOCUMENTATION_RELATEDITEMS

#include "test/v2.0/documentation/RelatedItem.hpp"

namespace test {
namespace v2_0 {
namespace documentation {

// -----------------------------------------------------------------------------
// documentation::
// class RelatedItems
// -----------------------------------------------------------------------------

class RelatedItems :
   public Component<documentation::RelatedItems>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "documentation"; }
   static auto CLASS() { return "RelatedItems"; }
   static auto NODENAME() { return "relatedItems"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<documentation::RelatedItem>
            ("relatedItem")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "relatedItem"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "related_item"
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
   Field<std::vector<documentation::RelatedItem>>
      relatedItem{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->relatedItem \
   )

   // default
   RelatedItems() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit RelatedItems(
      const wrapper<std::vector<documentation::RelatedItem>>
         &relatedItem
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      relatedItem(this,relatedItem)
   {
      Component::finish();
   }

   // from node
   explicit RelatedItems(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   RelatedItems(const RelatedItems &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      relatedItem(this,other.relatedItem)
   {
      Component::finish(other);
   }

   // move
   RelatedItems(RelatedItems &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      relatedItem(this,std::move(other.relatedItem))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   RelatedItems &operator=(const RelatedItems &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         relatedItem = other.relatedItem;
      }
      return *this;
   }

   // move
   RelatedItems &operator=(RelatedItems &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         relatedItem = std::move(other.relatedItem);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/documentation/RelatedItems/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class RelatedItems

} // namespace documentation
} // namespace v2_0
} // namespace test

#endif
