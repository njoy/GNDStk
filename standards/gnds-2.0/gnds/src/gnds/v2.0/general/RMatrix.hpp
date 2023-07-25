
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_RMATRIX
#define GNDS_V2_0_GENERAL_RMATRIX

#include "gnds/v2.0/top/PoPs.hpp"
#include "gnds/v2.0/general/ResonanceReactions.hpp"
#include "gnds/v2.0/general/SpinGroups.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class RMatrix
// -----------------------------------------------------------------------------

class RMatrix :
   public Component<general::RMatrix>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "RMatrix"; }
   static auto NODENAME() { return "RMatrix"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::string{}
            / Meta<>("approximation") |
         std::string{}
            / Meta<>("boundaryCondition") |
         std::optional<bool>{}
            / Meta<>("calculateChannelRadius") |
         std::optional<bool>{}
            / Meta<>("supportsAngularReconstruction") |

         // children
         --Child<std::optional<top::PoPs>>
            ("PoPs") |
         --Child<general::ResonanceReactions>
            ("resonanceReactions") |
         --Child<general::SpinGroups>
            ("spinGroups")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "approximation",
         "boundaryCondition",
         "calculateChannelRadius",
         "supportsAngularReconstruction",
         "PoPs",
         "resonanceReactions",
         "spinGroups"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "approximation",
         "boundary_condition",
         "calculate_channel_radius",
         "supports_angular_reconstruction",
         "po_ps",
         "resonance_reactions",
         "spin_groups"
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
   Field<std::string>
      approximation{this};
   Field<std::string>
      boundaryCondition{this};
   Field<std::optional<bool>>
      calculateChannelRadius{this};
   Field<std::optional<bool>>
      supportsAngularReconstruction{this};

   // children
   Field<std::optional<top::PoPs>>
      PoPs{this};
   Field<general::ResonanceReactions>
      resonanceReactions{this};
   Field<general::SpinGroups>
      spinGroups{this};

   // shortcuts
   #define GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   GNDSTK_SHORTCUT(resonanceReactions(),resonanceReaction);
   GNDSTK_SHORTCUT(spinGroups(),spinGroup);
   #undef GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->approximation, \
      this->boundaryCondition, \
      this->calculateChannelRadius, \
      this->supportsAngularReconstruction, \
      this->PoPs, \
      this->resonanceReactions, \
      this->spinGroups \
   )

   // default
   RMatrix() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit RMatrix(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &approximation = {},
      const wrapper<std::string>
         &boundaryCondition = {},
      const wrapper<std::optional<bool>>
         &calculateChannelRadius = {},
      const wrapper<std::optional<bool>>
         &supportsAngularReconstruction = {},
      const wrapper<std::optional<top::PoPs>>
         &PoPs = {},
      const wrapper<general::ResonanceReactions>
         &resonanceReactions = {},
      const wrapper<general::SpinGroups>
         &spinGroups = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      approximation(this,approximation),
      boundaryCondition(this,boundaryCondition),
      calculateChannelRadius(this,calculateChannelRadius),
      supportsAngularReconstruction(this,supportsAngularReconstruction),
      PoPs(this,PoPs),
      resonanceReactions(this,resonanceReactions),
      spinGroups(this,spinGroups)
   {
      Component::finish();
   }

   // from node
   explicit RMatrix(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   RMatrix(const RMatrix &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      approximation(this,other.approximation),
      boundaryCondition(this,other.boundaryCondition),
      calculateChannelRadius(this,other.calculateChannelRadius),
      supportsAngularReconstruction(this,other.supportsAngularReconstruction),
      PoPs(this,other.PoPs),
      resonanceReactions(this,other.resonanceReactions),
      spinGroups(this,other.spinGroups)
   {
      Component::finish(other);
   }

   // move
   RMatrix(RMatrix &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      approximation(this,std::move(other.approximation)),
      boundaryCondition(this,std::move(other.boundaryCondition)),
      calculateChannelRadius(this,std::move(other.calculateChannelRadius)),
      supportsAngularReconstruction(this,std::move(other.supportsAngularReconstruction)),
      PoPs(this,std::move(other.PoPs)),
      resonanceReactions(this,std::move(other.resonanceReactions)),
      spinGroups(this,std::move(other.spinGroups))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   RMatrix &operator=(const RMatrix &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         approximation = other.approximation;
         boundaryCondition = other.boundaryCondition;
         calculateChannelRadius = other.calculateChannelRadius;
         supportsAngularReconstruction = other.supportsAngularReconstruction;
         PoPs = other.PoPs;
         resonanceReactions = other.resonanceReactions;
         spinGroups = other.spinGroups;
      }
      return *this;
   }

   // move
   RMatrix &operator=(RMatrix &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         approximation = std::move(other.approximation);
         boundaryCondition = std::move(other.boundaryCondition);
         calculateChannelRadius = std::move(other.calculateChannelRadius);
         supportsAngularReconstruction = std::move(other.supportsAngularReconstruction);
         PoPs = std::move(other.PoPs);
         resonanceReactions = std::move(other.resonanceReactions);
         spinGroups = std::move(other.spinGroups);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/RMatrix/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class RMatrix

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
