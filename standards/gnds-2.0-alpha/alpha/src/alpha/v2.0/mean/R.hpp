
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_R
#define ALPHA_V2_0_MEAN_R

#include "alpha/v2.0/mean/XYs2d.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class R
// -----------------------------------------------------------------------------

class R :
   public Component<mean::R>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "R"; }
   static auto FIELD() { return "r"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<mean::XYs2d>("XYs2d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<mean::XYs2d> XYs2d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->XYs2d)

   // default
   R() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit R(
      const wrapper<mean::XYs2d> &XYs2d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs2d(this,XYs2d)
   {
      Component::finish();
   }

   // from node
   explicit R(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   R(const R &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs2d(this,other.XYs2d)
   {
      Component::finish(other);
   }

   // move
   R(R &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs2d(this,std::move(other.XYs2d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   R &operator=(const R &) = default;
   R &operator=(R &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/R/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class R

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
