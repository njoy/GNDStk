
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_L
#define ALPHA_V2_0_MEAN_L

#include "alpha/v2.0/mean/Js.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class L
// -----------------------------------------------------------------------------

class L :
   public Component<mean::L>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "L"; }
   static auto FIELD() { return "L"; }

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
         --Child<mean::Js>
            ("Js")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<int> value{this};

   // children
   Field<mean::Js>
      Js{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->value, \
      this->Js)

   // default
   L() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit L(
      const wrapper<std::string>
         &label,
      const wrapper<int>
         &value = {},
      const wrapper<mean::Js>
         &Js = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      value(this,value),
      Js(this,Js)
   {
      Component::finish();
   }

   // from node
   explicit L(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   L(const L &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      value(this,other.value),
      Js(this,other.Js)
   {
      Component::finish(other);
   }

   // move
   L(L &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      value(this,std::move(other.value)),
      Js(this,std::move(other.Js))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   L &operator=(const L &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         value = other.value;
         Js = other.Js;
      }
      return *this;
   }

   // move
   L &operator=(L &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         value = std::move(other.value);
         Js = std::move(other.Js);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/L/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class L

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
