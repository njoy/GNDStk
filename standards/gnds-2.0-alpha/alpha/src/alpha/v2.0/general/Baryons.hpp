
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_BARYONS
#define ALPHA_V2_0_GENERAL_BARYONS

#include "alpha/v2.0/general/Baryon.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Baryons
// -----------------------------------------------------------------------------

class Baryons :
   public Component<general::Baryons>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Baryons"; }
   static auto NODENAME() { return "baryons"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Baryon>
            ("baryon")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "baryon"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "baryon"
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
   Field<std::vector<general::Baryon>>
      baryon{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->baryon \
   )

   // default
   Baryons() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Baryons(
      const wrapper<std::vector<general::Baryon>>
         &baryon
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      baryon(this,baryon)
   {
      Component::finish();
   }

   // from node
   explicit Baryons(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Baryons(const Baryons &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      baryon(this,other.baryon)
   {
      Component::finish(other);
   }

   // move
   Baryons(Baryons &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      baryon(this,std::move(other.baryon))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Baryons &operator=(const Baryons &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         baryon = other.baryon;
      }
      return *this;
   }

   // move
   Baryons &operator=(Baryons &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         baryon = std::move(other.baryon);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Baryons/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Baryons

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif