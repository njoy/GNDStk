
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_FORMFACTOR
#define ALPHA_V2_0_MEAN_FORMFACTOR

#include "alpha/v2.0/common/XYs1d.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class FormFactor
// -----------------------------------------------------------------------------

class FormFactor :
   public Component<mean::FormFactor>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "FormFactor"; }
   static auto FIELD() { return "formFactor"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<common::XYs1d>
            ("XYs1d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<common::XYs1d>
      XYs1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->XYs1d)

   // default
   FormFactor() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit FormFactor(
      const wrapper<common::XYs1d>
         &XYs1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit FormFactor(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   FormFactor(const FormFactor &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d)
   {
      Component::finish(other);
   }

   // move
   FormFactor(FormFactor &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs1d(this,std::move(other.XYs1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   FormFactor &operator=(const FormFactor &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs1d = other.XYs1d;
      }
      return *this;
   }

   // move
   FormFactor &operator=(FormFactor &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         XYs1d = std::move(other.XYs1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/FormFactor/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class FormFactor

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
