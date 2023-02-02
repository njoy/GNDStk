
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_WIDTHS
#define ALPHA_V2_0_MEAN_WIDTHS

#include "alpha/v2.0/mean/Width.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class Widths
// -----------------------------------------------------------------------------

class Widths :
   public Component<mean::Widths>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "Widths"; }
   static auto FIELD() { return "widths"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<mean::Width>
            ("width")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<mean::Width>>
      width{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->width)

   // default
   Widths() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Widths(
      const wrapper<std::vector<mean::Width>>
         &width
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      width(this,width)
   {
      Component::finish();
   }

   // from node
   explicit Widths(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Widths(const Widths &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      width(this,other.width)
   {
      Component::finish(other);
   }

   // move
   Widths(Widths &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      width(this,std::move(other.width))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Widths &operator=(const Widths &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         width = other.width;
      }
      return *this;
   }

   // move
   Widths &operator=(Widths &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         width = std::move(other.width);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/Widths/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Widths

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
