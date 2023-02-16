
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_INSTITUTION
#define ALPHA_V2_0_GENERAL_INSTITUTION

#include "alpha/v2.0/general/ENDFconversionFlags.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Institution
// -----------------------------------------------------------------------------

class Institution :
   public Component<general::Institution>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Institution"; }
   static auto FIELD() { return "institution"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("label") |

         // children
         --Child<general::ENDFconversionFlags>
            ("ENDFconversionFlags")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "ENDFconversionFlags"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "endfconversion_flags"
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
   Field<std::optional<std::string>>
      label{this};

   // children
   Field<general::ENDFconversionFlags>
      ENDFconversionFlags{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->ENDFconversionFlags \
   )

   // default
   Institution() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Institution(
      const wrapper<std::optional<std::string>>
         &label,
      const wrapper<general::ENDFconversionFlags>
         &ENDFconversionFlags = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ENDFconversionFlags(this,ENDFconversionFlags)
   {
      Component::finish();
   }

   // from node
   explicit Institution(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Institution(const Institution &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      ENDFconversionFlags(this,other.ENDFconversionFlags)
   {
      Component::finish(other);
   }

   // move
   Institution(Institution &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      ENDFconversionFlags(this,std::move(other.ENDFconversionFlags))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Institution &operator=(const Institution &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         ENDFconversionFlags = other.ENDFconversionFlags;
      }
      return *this;
   }

   // move
   Institution &operator=(Institution &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         ENDFconversionFlags = std::move(other.ENDFconversionFlags);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Institution/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Institution

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
