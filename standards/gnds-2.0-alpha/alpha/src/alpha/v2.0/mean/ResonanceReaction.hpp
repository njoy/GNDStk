
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_MEAN_RESONANCEREACTION
#define ALPHA_V2_0_MEAN_RESONANCEREACTION

#include "alpha/v2.0/common/Link.hpp"
#include "alpha/v2.0/mean/HardSphereRadius.hpp"
#include "alpha/v2.0/common/Q.hpp"
#include "alpha/v2.0/mean/ScatteringRadius.hpp"

namespace alpha {
namespace v2_0 {
namespace mean {

// -----------------------------------------------------------------------------
// mean::
// class ResonanceReaction
// -----------------------------------------------------------------------------

class ResonanceReaction :
   public Component<mean::ResonanceReaction>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "mean"; }
   static auto CLASS() { return "ResonanceReaction"; }
   static auto FIELD() { return "resonanceReaction"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::optional<std::string>{}
            / Meta<>("ejectile") |
         std::optional<bool>{}
            / Meta<>("eliminated") |

         // children
         --Child<common::Link>("link") |
         --Child<std::optional<mean::HardSphereRadius>>("hardSphereRadius") |
         --Child<std::optional<common::Q>>("Q") |
         --Child<std::optional<mean::ScatteringRadius>>("scatteringRadius")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<std::optional<std::string>> ejectile{this};
   Field<std::optional<bool>> eliminated{this};

   // children
   Field<common::Link> link{this};
   Field<std::optional<mean::HardSphereRadius>> hardSphereRadius{this};
   Field<std::optional<common::Q>> Q{this};
   Field<std::optional<mean::ScatteringRadius>> scatteringRadius{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->label, \
      this->ejectile, \
      this->eliminated, \
      this->link, \
      this->hardSphereRadius, \
      this->Q, \
      this->scatteringRadius)

   // default
   ResonanceReaction() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit ResonanceReaction(
      const wrapper<std::string> &label,
      const wrapper<std::optional<std::string>> &ejectile = {},
      const wrapper<std::optional<bool>> &eliminated = {},
      const wrapper<common::Link> &link = {},
      const wrapper<std::optional<mean::HardSphereRadius>> &hardSphereRadius = {},
      const wrapper<std::optional<common::Q>> &Q = {},
      const wrapper<std::optional<mean::ScatteringRadius>> &scatteringRadius = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ejectile(this,ejectile),
      eliminated(this,eliminated),
      link(this,link),
      hardSphereRadius(this,hardSphereRadius),
      Q(this,Q),
      scatteringRadius(this,scatteringRadius)
   {
      Component::finish();
   }

   // from node
   explicit ResonanceReaction(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   ResonanceReaction(const ResonanceReaction &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      ejectile(this,other.ejectile),
      eliminated(this,other.eliminated),
      link(this,other.link),
      hardSphereRadius(this,other.hardSphereRadius),
      Q(this,other.Q),
      scatteringRadius(this,other.scatteringRadius)
   {
      Component::finish(other);
   }

   // move
   ResonanceReaction(ResonanceReaction &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      ejectile(this,std::move(other.ejectile)),
      eliminated(this,std::move(other.eliminated)),
      link(this,std::move(other.link)),
      hardSphereRadius(this,std::move(other.hardSphereRadius)),
      Q(this,std::move(other.Q)),
      scatteringRadius(this,std::move(other.scatteringRadius))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   ResonanceReaction &operator=(const ResonanceReaction &) = default;
   ResonanceReaction &operator=(ResonanceReaction &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/mean/ResonanceReaction/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class ResonanceReaction

} // namespace mean
} // namespace v2_0
} // namespace alpha

#endif
