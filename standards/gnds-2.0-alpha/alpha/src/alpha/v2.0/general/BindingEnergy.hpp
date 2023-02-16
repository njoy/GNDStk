
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_BINDINGENERGY
#define ALPHA_V2_0_GENERAL_BINDINGENERGY

#include "alpha/v2.0/general/Double.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class BindingEnergy
// -----------------------------------------------------------------------------

class BindingEnergy :
   public Component<general::BindingEnergy>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "BindingEnergy"; }
   static auto FIELD() { return "bindingEnergy"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Double>
            ("double")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "Double"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "double"
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
   Field<general::Double>
      Double{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->Double \
   )

   // default
   BindingEnergy() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit BindingEnergy(
      const wrapper<general::Double>
         &Double
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      Double(this,Double)
   {
      Component::finish();
   }

   // from node
   explicit BindingEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   BindingEnergy(const BindingEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      Double(this,other.Double)
   {
      Component::finish(other);
   }

   // move
   BindingEnergy(BindingEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      Double(this,std::move(other.Double))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   BindingEnergy &operator=(const BindingEnergy &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         Double = other.Double;
      }
      return *this;
   }

   // move
   BindingEnergy &operator=(BindingEnergy &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         Double = std::move(other.Double);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/BindingEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class BindingEnergy

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
