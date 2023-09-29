
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_NUCLEARAMPLITUDEEXPANSION
#define GNDS_V2_0_GENERAL_NUCLEARAMPLITUDEEXPANSION

#include "GNDS/v2.0/general/NuclearTerm.hpp"
#include "GNDS/v2.0/general/RealInterferenceTerm.hpp"
#include "GNDS/v2.0/general/ImaginaryInterferenceTerm.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class NuclearAmplitudeExpansion
// -----------------------------------------------------------------------------

class NuclearAmplitudeExpansion :
   public Component<general::NuclearAmplitudeExpansion>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "NuclearAmplitudeExpansion"; }
   static auto NODENAME() { return "nuclearAmplitudeExpansion"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::NuclearTerm>
            ("nuclearTerm") |
         --Child<general::RealInterferenceTerm>
            ("realInterferenceTerm") |
         --Child<general::ImaginaryInterferenceTerm>
            ("imaginaryInterferenceTerm")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "nuclearTerm",
         "realInterferenceTerm",
         "imaginaryInterferenceTerm"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "nuclear_term",
         "real_interference_term",
         "imaginary_interference_term"
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
   Field<general::NuclearTerm>
      nuclearTerm{this};
   Field<general::RealInterferenceTerm>
      realInterferenceTerm{this};
   Field<general::ImaginaryInterferenceTerm>
      imaginaryInterferenceTerm{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->nuclearTerm, \
      this->realInterferenceTerm, \
      this->imaginaryInterferenceTerm \
   )

   // default
   NuclearAmplitudeExpansion() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit NuclearAmplitudeExpansion(
      const wrapper<general::NuclearTerm>
         &nuclearTerm,
      const wrapper<general::RealInterferenceTerm>
         &realInterferenceTerm = {},
      const wrapper<general::ImaginaryInterferenceTerm>
         &imaginaryInterferenceTerm = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      nuclearTerm(this,nuclearTerm),
      realInterferenceTerm(this,realInterferenceTerm),
      imaginaryInterferenceTerm(this,imaginaryInterferenceTerm)
   {
      Component::finish();
   }

   // from node
   explicit NuclearAmplitudeExpansion(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   NuclearAmplitudeExpansion(const NuclearAmplitudeExpansion &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      nuclearTerm(this,other.nuclearTerm),
      realInterferenceTerm(this,other.realInterferenceTerm),
      imaginaryInterferenceTerm(this,other.imaginaryInterferenceTerm)
   {
      Component::finish(other);
   }

   // move
   NuclearAmplitudeExpansion(NuclearAmplitudeExpansion &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      nuclearTerm(this,std::move(other.nuclearTerm)),
      realInterferenceTerm(this,std::move(other.realInterferenceTerm)),
      imaginaryInterferenceTerm(this,std::move(other.imaginaryInterferenceTerm))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   NuclearAmplitudeExpansion &operator=(const NuclearAmplitudeExpansion &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         nuclearTerm = other.nuclearTerm;
         realInterferenceTerm = other.realInterferenceTerm;
         imaginaryInterferenceTerm = other.imaginaryInterferenceTerm;
      }
      return *this;
   }

   // move
   NuclearAmplitudeExpansion &operator=(NuclearAmplitudeExpansion &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         nuclearTerm = std::move(other.nuclearTerm);
         realInterferenceTerm = std::move(other.realInterferenceTerm);
         imaginaryInterferenceTerm = std::move(other.imaginaryInterferenceTerm);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/NuclearAmplitudeExpansion/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class NuclearAmplitudeExpansion

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
