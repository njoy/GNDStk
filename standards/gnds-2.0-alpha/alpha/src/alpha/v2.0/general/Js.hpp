
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_JS
#define ALPHA_V2_0_GENERAL_JS

#include "alpha/v2.0/general/J.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Js
// -----------------------------------------------------------------------------

class Js :
   public Component<general::Js>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Js"; }
   static auto FIELD() { return "Js"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::J>
            ("J")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "J"
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
   Field<std::vector<general::J>>
      J{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->J \
   )

   // default
   Js() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Js(
      const wrapper<std::vector<general::J>>
         &J
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      J(this,J)
   {
      Component::finish();
   }

   // from node
   explicit Js(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Js(const Js &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      J(this,other.J)
   {
      Component::finish(other);
   }

   // move
   Js(Js &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      J(this,std::move(other.J))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Js &operator=(const Js &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         J = other.J;
      }
      return *this;
   }

   // move
   Js &operator=(Js &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         J = std::move(other.J);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Js/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Js

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
