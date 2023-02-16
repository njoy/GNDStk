
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_COLUMNHEADERS
#define ALPHA_V2_0_GENERAL_COLUMNHEADERS

#include "alpha/v2.0/general/Column.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class ColumnHeaders
// -----------------------------------------------------------------------------

class ColumnHeaders :
   public Component<general::ColumnHeaders>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "ColumnHeaders"; }
   static auto FIELD() { return "columnHeaders"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Column>
            ("column")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "column"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "column"
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
   Field<std::vector<general::Column>>
      column{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->column \
   )

   // default
   ColumnHeaders() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ColumnHeaders(
      const wrapper<std::vector<general::Column>>
         &column
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      column(this,column)
   {
      Component::finish();
   }

   // from node
   explicit ColumnHeaders(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ColumnHeaders(const ColumnHeaders &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      column(this,other.column)
   {
      Component::finish(other);
   }

   // move
   ColumnHeaders(ColumnHeaders &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      column(this,std::move(other.column))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   ColumnHeaders &operator=(const ColumnHeaders &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         column = other.column;
      }
      return *this;
   }

   // move
   ColumnHeaders &operator=(ColumnHeaders &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         column = std::move(other.column);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/ColumnHeaders/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ColumnHeaders

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
