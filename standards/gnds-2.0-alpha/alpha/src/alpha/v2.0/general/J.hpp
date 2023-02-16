
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_J
#define ALPHA_V2_0_GENERAL_J

#include "alpha/v2.0/general/LevelSpacing.hpp"
#include "alpha/v2.0/general/Widths.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class J
// -----------------------------------------------------------------------------

class J :
   public Component<general::J>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "J"; }
   static auto FIELD() { return "J"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         int{}
            / Meta<>("value") |

         // children
         --Child<general::LevelSpacing>
            ("levelSpacing") |
         --Child<general::Widths>
            ("widths")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "value",
         "levelSpacing",
         "widths"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "value",
         "level_spacing",
         "widths"
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
   Field<int>
      value{this};

   // children
   Field<general::LevelSpacing>
      levelSpacing{this};
   Field<general::Widths>
      widths{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->value, \
      this->levelSpacing, \
      this->widths \
   )

   // default
   J() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit J(
      const wrapper<std::string>
         &label,
      const wrapper<int>
         &value = {},
      const wrapper<general::LevelSpacing>
         &levelSpacing = {},
      const wrapper<general::Widths>
         &widths = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      value(this,value),
      levelSpacing(this,levelSpacing),
      widths(this,widths)
   {
      Component::finish();
   }

   // from node
   explicit J(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   J(const J &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      value(this,other.value),
      levelSpacing(this,other.levelSpacing),
      widths(this,other.widths)
   {
      Component::finish(other);
   }

   // move
   J(J &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      value(this,std::move(other.value)),
      levelSpacing(this,std::move(other.levelSpacing)),
      widths(this,std::move(other.widths))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   J &operator=(const J &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         value = other.value;
         levelSpacing = other.levelSpacing;
         widths = other.widths;
      }
      return *this;
   }

   // move
   J &operator=(J &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         value = std::move(other.value);
         levelSpacing = std::move(other.levelSpacing);
         widths = std::move(other.widths);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/J/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class J

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
