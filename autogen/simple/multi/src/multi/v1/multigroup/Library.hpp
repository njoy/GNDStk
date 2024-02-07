
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef MULTI_V1_MULTIGROUP_LIBRARY
#define MULTI_V1_MULTIGROUP_LIBRARY

#include "multi/v1/multigroup/Element.hpp"

namespace multi {
namespace v1 {
namespace multigroup {

// -----------------------------------------------------------------------------
// multigroup::
// class Library
// -----------------------------------------------------------------------------

class Library :
   public Component<multigroup::Library>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "multigroup"; }
   static auto CLASS() { return "Library"; }
   static auto NODENAME() { return "library"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("name") |

         // children
         ++Child<multigroup::Element>
            ("element")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "name",
         "element"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "name",
         "element"
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
   Field<std::string>
      name{this};

   // children
   Field<std::vector<multigroup::Element>>
      element{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->name, \
      this->element \
   )

   // default
   Library() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Library(
      const wrapper<std::string>
         &name,
      const wrapper<std::vector<multigroup::Element>>
         &element = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      name(this,name),
      element(this,element)
   {
      Component::finish();
   }

   // from node
   explicit Library(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Library(const Library &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      name(this,other.name),
      element(this,other.element)
   {
      Component::finish(other);
   }

   // move
   Library(Library &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      name(this,std::move(other.name)),
      element(this,std::move(other.element))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Library &operator=(const Library &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         name = other.name;
         element = other.element;
      }
      return *this;
   }

   // move
   Library &operator=(Library &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         name = std::move(other.name);
         element = std::move(other.element);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "multi/v1/multigroup/Library/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Library

} // namespace multigroup
} // namespace v1
} // namespace multi

#endif
