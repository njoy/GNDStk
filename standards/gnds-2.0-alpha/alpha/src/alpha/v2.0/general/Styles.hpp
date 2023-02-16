
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_STYLES
#define ALPHA_V2_0_GENERAL_STYLES

#include "alpha/v2.0/general/Evaluated.hpp"
#include "alpha/v2.0/general/CrossSectionReconstructed.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Styles
// -----------------------------------------------------------------------------

class Styles :
   public Component<general::Styles>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Styles"; }
   static auto FIELD() { return "styles"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::Evaluated>
            ("evaluated") |
         --Child<std::optional<general::CrossSectionReconstructed>>
            ("crossSectionReconstructed")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "evaluated",
         "crossSectionReconstructed"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "evaluated",
         "cross_section_reconstructed"
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
   Field<general::Evaluated>
      evaluated{this};
   Field<std::optional<general::CrossSectionReconstructed>>
      crossSectionReconstructed{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->evaluated, \
      this->crossSectionReconstructed \
   )

   // default
   Styles() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Styles(
      const wrapper<general::Evaluated>
         &evaluated,
      const wrapper<std::optional<general::CrossSectionReconstructed>>
         &crossSectionReconstructed = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      evaluated(this,evaluated),
      crossSectionReconstructed(this,crossSectionReconstructed)
   {
      Component::finish();
   }

   // from node
   explicit Styles(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Styles(const Styles &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      evaluated(this,other.evaluated),
      crossSectionReconstructed(this,other.crossSectionReconstructed)
   {
      Component::finish(other);
   }

   // move
   Styles(Styles &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      evaluated(this,std::move(other.evaluated)),
      crossSectionReconstructed(this,std::move(other.crossSectionReconstructed))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Styles &operator=(const Styles &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         evaluated = other.evaluated;
         crossSectionReconstructed = other.crossSectionReconstructed;
      }
      return *this;
   }

   // move
   Styles &operator=(Styles &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         evaluated = std::move(other.evaluated);
         crossSectionReconstructed = std::move(other.crossSectionReconstructed);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Styles/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Styles

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
