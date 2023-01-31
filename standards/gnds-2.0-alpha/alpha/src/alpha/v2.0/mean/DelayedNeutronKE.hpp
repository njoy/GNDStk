
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_DELAYEDNEUTRONKE
#define ALPHA_V2_0_MEAN_DELAYEDNEUTRONKE

#include "alpha/v2.0/common/Polynomial1d.hpp"
#include "alpha/v2.0/common/XYs1d.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class DelayedNeutronKE
// -----------------------------------------------------------------------------

class DelayedNeutronKE :
   public Component<mean::DelayedNeutronKE>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "DelayedNeutronKE"; }
   static auto FIELD() { return "delayedNeutronKE"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<common::Polynomial1d>>("polynomial1d") |
         --Child<std::optional<common::XYs1d>>("XYs1d")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::optional<common::Polynomial1d>> polynomial1d{this};
   Field<std::optional<common::XYs1d>> XYs1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->polynomial1d, \
      this->XYs1d)

   // default
   DelayedNeutronKE() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit DelayedNeutronKE(
      const wrapper<std::optional<common::Polynomial1d>> &polynomial1d,
      const wrapper<std::optional<common::XYs1d>> &XYs1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      polynomial1d(this,polynomial1d),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit DelayedNeutronKE(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   DelayedNeutronKE(const DelayedNeutronKE &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      polynomial1d(this,other.polynomial1d),
      XYs1d(this,other.XYs1d)
   {
      Component::finish(other);
   }

   // move
   DelayedNeutronKE(DelayedNeutronKE &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      polynomial1d(this,std::move(other.polynomial1d)),
      XYs1d(this,std::move(other.XYs1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   DelayedNeutronKE &operator=(const DelayedNeutronKE &) = default;
   DelayedNeutronKE &operator=(DelayedNeutronKE &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/DelayedNeutronKE/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class DelayedNeutronKE

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
