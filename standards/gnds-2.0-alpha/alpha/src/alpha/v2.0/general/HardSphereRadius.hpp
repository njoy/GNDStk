
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_HARDSPHERERADIUS
#define ALPHA_V2_0_GENERAL_HARDSPHERERADIUS

#include "alpha/v2.0/general/Constant1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class HardSphereRadius
// -----------------------------------------------------------------------------

class HardSphereRadius :
   public Component<general::HardSphereRadius>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "HardSphereRadius"; }
   static auto NODENAME() { return "hardSphereRadius"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Constant1d>
            ("constant1d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "constant1d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "constant1d"
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
   Field<general::Constant1d>
      constant1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->constant1d \
   )

   // default
   HardSphereRadius() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit HardSphereRadius(
      const wrapper<general::Constant1d>
         &constant1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      constant1d(this,constant1d)
   {
      Component::finish();
   }

   // from node
   explicit HardSphereRadius(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   HardSphereRadius(const HardSphereRadius &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      constant1d(this,other.constant1d)
   {
      Component::finish(other);
   }

   // move
   HardSphereRadius(HardSphereRadius &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      constant1d(this,std::move(other.constant1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   HardSphereRadius &operator=(const HardSphereRadius &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         constant1d = other.constant1d;
      }
      return *this;
   }

   // move
   HardSphereRadius &operator=(HardSphereRadius &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         constant1d = std::move(other.constant1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/HardSphereRadius/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class HardSphereRadius

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif