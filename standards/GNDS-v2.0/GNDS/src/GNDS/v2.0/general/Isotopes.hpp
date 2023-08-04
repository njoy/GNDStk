
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_ISOTOPES
#define GNDS_V2_0_GENERAL_ISOTOPES

#include "GNDS/v2.0/general/Isotope.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Isotopes
// -----------------------------------------------------------------------------

class Isotopes :
   public Component<general::Isotopes>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Isotopes"; }
   static auto NODENAME() { return "isotopes"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<general::Isotope>
            ("isotope")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "isotope"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "isotope"
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
   Field<std::vector<general::Isotope>>
      isotope{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->isotope \
   )

   // default
   Isotopes() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Isotopes(
      const wrapper<std::vector<general::Isotope>>
         &isotope
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      isotope(this,isotope)
   {
      Component::finish();
   }

   // from node
   explicit Isotopes(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Isotopes(const Isotopes &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      isotope(this,other.isotope)
   {
      Component::finish(other);
   }

   // move
   Isotopes(Isotopes &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      isotope(this,std::move(other.isotope))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Isotopes &operator=(const Isotopes &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         isotope = other.isotope;
      }
      return *this;
   }

   // move
   Isotopes &operator=(Isotopes &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         isotope = std::move(other.isotope);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/Isotopes/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Isotopes

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif