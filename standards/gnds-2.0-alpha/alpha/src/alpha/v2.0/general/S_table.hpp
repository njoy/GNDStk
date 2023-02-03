
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_S_TABLE
#define ALPHA_V2_0_GENERAL_S_TABLE

#include "alpha/v2.0/general/Gridded2d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class S_table
// -----------------------------------------------------------------------------

class S_table :
   public Component<general::S_table>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "S_table"; }
   static auto FIELD() { return "S_table"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Gridded2d>
            ("gridded2d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<general::Gridded2d>
      gridded2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->gridded2d)

   // default
   S_table() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit S_table(
      const wrapper<general::Gridded2d>
         &gridded2d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      gridded2d(this,gridded2d)
   {
      Component::finish();
   }

   // from node
   explicit S_table(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   S_table(const S_table &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      gridded2d(this,other.gridded2d)
   {
      Component::finish(other);
   }

   // move
   S_table(S_table &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      gridded2d(this,std::move(other.gridded2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   S_table &operator=(const S_table &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         gridded2d = other.gridded2d;
      }
      return *this;
   }

   // move
   S_table &operator=(S_table &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         gridded2d = std::move(other.gridded2d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/S_table/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class S_table

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
