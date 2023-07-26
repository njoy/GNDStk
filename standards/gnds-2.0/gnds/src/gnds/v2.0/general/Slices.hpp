
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_SLICES
#define GNDS_V2_0_GENERAL_SLICES

#include "gnds/v2.0/general/Slice.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Slices
// -----------------------------------------------------------------------------

class Slices :
   public Component<general::Slices>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Slices"; }
   static auto NODENAME() { return "slices"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Slice>
            ("slice")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "slice"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "slice"
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
   Field<std::vector<general::Slice>>
      slice{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->slice \
   )

   // default
   Slices() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Slices(
      const wrapper<std::vector<general::Slice>>
         &slice
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      slice(this,slice)
   {
      Component::finish();
   }

   // from node
   explicit Slices(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Slices(const Slices &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      slice(this,other.slice)
   {
      Component::finish(other);
   }

   // move
   Slices(Slices &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      slice(this,std::move(other.slice))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Slices &operator=(const Slices &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         slice = other.slice;
      }
      return *this;
   }

   // move
   Slices &operator=(Slices &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         slice = std::move(other.slice);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/Slices/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Slices

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
