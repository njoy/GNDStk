
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_SHELL
#define ALPHA_V2_0_GENERAL_SHELL

#include "alpha/v2.0/general/Uncertainty.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Shell
// -----------------------------------------------------------------------------

class Shell :
   public Component<general::Shell>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Shell"; }
   static auto FIELD() { return "shell"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         double{}
            / Meta<>("value") |

         // children
         --Child<std::optional<general::Uncertainty>>
            ("uncertainty")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<double> value{this};

   // children
   Field<std::optional<general::Uncertainty>>
      uncertainty{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->value, \
      this->uncertainty \
   )

   // default
   Shell() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Shell(
      const wrapper<std::string>
         &label,
      const wrapper<double>
         &value = {},
      const wrapper<std::optional<general::Uncertainty>>
         &uncertainty = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      value(this,value),
      uncertainty(this,uncertainty)
   {
      Component::finish();
   }

   // from node
   explicit Shell(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Shell(const Shell &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      value(this,other.value),
      uncertainty(this,other.uncertainty)
   {
      Component::finish(other);
   }

   // move
   Shell(Shell &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      value(this,std::move(other.value)),
      uncertainty(this,std::move(other.uncertainty))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Shell &operator=(const Shell &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         value = other.value;
         uncertainty = other.uncertainty;
      }
      return *this;
   }

   // move
   Shell &operator=(Shell &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         value = std::move(other.value);
         uncertainty = std::move(other.uncertainty);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Shell/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Shell

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
