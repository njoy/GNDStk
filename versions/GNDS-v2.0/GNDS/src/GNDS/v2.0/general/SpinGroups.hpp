
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_SPINGROUPS
#define GNDS_V2_0_GENERAL_SPINGROUPS

#include "GNDS/v2.0/general/SpinGroup.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class SpinGroups
// -----------------------------------------------------------------------------

class SpinGroups :
   public Component<general::SpinGroups>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "SpinGroups"; }
   static auto NODENAME() { return "spinGroups"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::SpinGroup>
            ("spinGroup")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "spinGroup"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "spin_group"
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
   Field<std::vector<general::SpinGroup>>
      spinGroup{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->spinGroup \
   )

   // default
   SpinGroups() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit SpinGroups(
      const wrapper<std::vector<general::SpinGroup>>
         &spinGroup
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      spinGroup(this,spinGroup)
   {
      Component::finish();
   }

   // from node
   explicit SpinGroups(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   SpinGroups(const SpinGroups &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      spinGroup(this,other.spinGroup)
   {
      Component::finish(other);
   }

   // move
   SpinGroups(SpinGroups &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      spinGroup(this,std::move(other.spinGroup))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   SpinGroups &operator=(const SpinGroups &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         spinGroup = other.spinGroup;
      }
      return *this;
   }

   // move
   SpinGroups &operator=(SpinGroups &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         spinGroup = std::move(other.spinGroup);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/SpinGroups/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class SpinGroups

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
