
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_CROSSSECTIONRECONSTRUCTED
#define ALPHA_V2_0_GENERAL_CROSSSECTIONRECONSTRUCTED

#include "alpha/v2.0/key.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class CrossSectionReconstructed
// -----------------------------------------------------------------------------

class CrossSectionReconstructed :
   public Component<general::CrossSectionReconstructed>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "CrossSectionReconstructed"; }
   static auto FIELD() { return "crossSectionReconstructed"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("derivedFrom") |
         std::string{}
            / Meta<>("date")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "derivedFrom",
         "date"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "derived_from",
         "date"
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

   // metadata
   Field<std::string>
      label{this};
   Field<std::string>
      derivedFrom{this};
   Field<std::string>
      date{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->derivedFrom, \
      this->date \
   )

   // default
   CrossSectionReconstructed() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CrossSectionReconstructed(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &derivedFrom = {},
      const wrapper<std::string>
         &date = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      derivedFrom(this,derivedFrom),
      date(this,date)
   {
      Component::finish();
   }

   // from node
   explicit CrossSectionReconstructed(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CrossSectionReconstructed(const CrossSectionReconstructed &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      derivedFrom(this,other.derivedFrom),
      date(this,other.date)
   {
      Component::finish(other);
   }

   // move
   CrossSectionReconstructed(CrossSectionReconstructed &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      derivedFrom(this,std::move(other.derivedFrom)),
      date(this,std::move(other.date))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   CrossSectionReconstructed &operator=(const CrossSectionReconstructed &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         derivedFrom = other.derivedFrom;
         date = other.date;
      }
      return *this;
   }

   // move
   CrossSectionReconstructed &operator=(CrossSectionReconstructed &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         derivedFrom = std::move(other.derivedFrom);
         date = std::move(other.date);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/CrossSectionReconstructed/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CrossSectionReconstructed

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
