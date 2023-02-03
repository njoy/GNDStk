
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_REALANOMALOUSFACTOR
#define ALPHA_V2_0_GENERAL_REALANOMALOUSFACTOR

#include "alpha/v2.0/general/XYs1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class RealAnomalousFactor
// -----------------------------------------------------------------------------

class RealAnomalousFactor :
   public Component<general::RealAnomalousFactor>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "RealAnomalousFactor"; }
   static auto FIELD() { return "realAnomalousFactor"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<general::XYs1d>
            ("XYs1d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<general::XYs1d>
      XYs1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->XYs1d)

   // default
   RealAnomalousFactor() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit RealAnomalousFactor(
      const wrapper<general::XYs1d>
         &XYs1d
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit RealAnomalousFactor(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   RealAnomalousFactor(const RealAnomalousFactor &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs1d(this,other.XYs1d)
   {
      Component::finish(other);
   }

   // move
   RealAnomalousFactor(RealAnomalousFactor &&other) :
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
   RealAnomalousFactor &operator=(const RealAnomalousFactor &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs1d = other.XYs1d;
      }
      return *this;
   }

   // move
   RealAnomalousFactor &operator=(RealAnomalousFactor &&other)
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

   #include "alpha/v2.0/general/RealAnomalousFactor/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class RealAnomalousFactor

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
