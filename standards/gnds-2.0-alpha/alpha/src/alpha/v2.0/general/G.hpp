
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_G
#define ALPHA_V2_0_GENERAL_G

#include "alpha/v2.0/general/XYs1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class G
// -----------------------------------------------------------------------------

class G :
   public Component<general::G>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "G"; }
   static auto FIELD() { return "g"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::XYs1d>>
            ("XYs1d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<general::XYs1d>>
      XYs1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->XYs1d \
   )

   // default
   G() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit G(
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit G(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   G(const G &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d)
   {
      Component::finish(other);
   }

   // move
   G(G &&other) :
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
   G &operator=(const G &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs1d = other.XYs1d;
      }
      return *this;
   }

   // move
   G &operator=(G &&other)
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

   #include "alpha/v2.0/general/G/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class G

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
