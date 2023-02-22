
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DELAYEDBETAENERGY
#define ALPHA_V2_0_GENERAL_DELAYEDBETAENERGY

#include "alpha/v2.0/general/Polynomial1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class DelayedBetaEnergy
// -----------------------------------------------------------------------------

class DelayedBetaEnergy :
   public Component<general::DelayedBetaEnergy>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "DelayedBetaEnergy"; }
   static auto NODENAME() { return "delayedBetaEnergy"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Polynomial1d>
            ("polynomial1d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "polynomial1d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "polynomial1d"
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
   Field<general::Polynomial1d>
      polynomial1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->polynomial1d \
   )

   // default
   DelayedBetaEnergy() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DelayedBetaEnergy(
      const wrapper<general::Polynomial1d>
         &polynomial1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      polynomial1d(this,polynomial1d)
   {
      Component::finish();
   }

   // from node
   explicit DelayedBetaEnergy(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DelayedBetaEnergy(const DelayedBetaEnergy &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      polynomial1d(this,other.polynomial1d)
   {
      Component::finish(other);
   }

   // move
   DelayedBetaEnergy(DelayedBetaEnergy &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      polynomial1d(this,std::move(other.polynomial1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   DelayedBetaEnergy &operator=(const DelayedBetaEnergy &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         polynomial1d = other.polynomial1d;
      }
      return *this;
   }

   // move
   DelayedBetaEnergy &operator=(DelayedBetaEnergy &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         polynomial1d = std::move(other.polynomial1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/DelayedBetaEnergy/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DelayedBetaEnergy

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif