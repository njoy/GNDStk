
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_TABULATEDWIDTHS
#define GNDS_V2_0_GENERAL_TABULATEDWIDTHS

#include "gnds/v2.0/general/ResonanceReactions.hpp"
#include "gnds/v2.0/general/Ls.hpp"
#include "gnds/v2.0/top/PoPs.hpp"
#include "gnds/v2.0/general/ScatteringRadius.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class TabulatedWidths
// -----------------------------------------------------------------------------

class TabulatedWidths :
   public Component<general::TabulatedWidths>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "TabulatedWidths"; }
   static auto NODENAME() { return "tabulatedWidths"; }

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
         std::optional<bool>{}
            / Meta<>("useForSelfShieldingOnly") |

         // children
         --Child<general::ResonanceReactions>
            ("resonanceReactions") |
         --Child<general::Ls>
            ("Ls") |
         --Child<std::optional<top::PoPs>>
            ("PoPs") |
         --Child<std::optional<general::ScatteringRadius>>
            ("scatteringRadius")
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
         "useForSelfShieldingOnly",
         "resonanceReactions",
         "Ls",
         "PoPs",
         "scatteringRadius"
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
         "use_for_self_shielding_only",
         "resonance_reactions",
         "ls",
         "po_ps",
         "scattering_radius"
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
   Field<std::optional<bool>>
      useForSelfShieldingOnly{this};

   // children
   Field<general::ResonanceReactions>
      resonanceReactions{this};
   Field<general::Ls>
      Ls{this};
   Field<std::optional<top::PoPs>>
      PoPs{this};
   Field<std::optional<general::ScatteringRadius>>
      scatteringRadius{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(Ls(),L);
   NJOY_GNDSTK_SHORTCUT(resonanceReactions(),resonanceReaction);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->approximation, \
      this->useForSelfShieldingOnly, \
      this->resonanceReactions, \
      this->Ls, \
      this->PoPs, \
      this->scatteringRadius \
   )

   // default
   TabulatedWidths() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit TabulatedWidths(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &approximation = {},
      const wrapper<std::optional<bool>>
         &useForSelfShieldingOnly = {},
      const wrapper<general::ResonanceReactions>
         &resonanceReactions = {},
      const wrapper<general::Ls>
         &Ls = {},
      const wrapper<std::optional<top::PoPs>>
         &PoPs = {},
      const wrapper<std::optional<general::ScatteringRadius>>
         &scatteringRadius = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      approximation(this,approximation),
      useForSelfShieldingOnly(this,useForSelfShieldingOnly),
      resonanceReactions(this,resonanceReactions),
      Ls(this,Ls),
      PoPs(this,PoPs),
      scatteringRadius(this,scatteringRadius)
   {
      Component::finish();
   }

   // from node
   explicit TabulatedWidths(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   TabulatedWidths(const TabulatedWidths &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      approximation(this,other.approximation),
      useForSelfShieldingOnly(this,other.useForSelfShieldingOnly),
      resonanceReactions(this,other.resonanceReactions),
      Ls(this,other.Ls),
      PoPs(this,other.PoPs),
      scatteringRadius(this,other.scatteringRadius)
   {
      Component::finish(other);
   }

   // move
   TabulatedWidths(TabulatedWidths &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      approximation(this,std::move(other.approximation)),
      useForSelfShieldingOnly(this,std::move(other.useForSelfShieldingOnly)),
      resonanceReactions(this,std::move(other.resonanceReactions)),
      Ls(this,std::move(other.Ls)),
      PoPs(this,std::move(other.PoPs)),
      scatteringRadius(this,std::move(other.scatteringRadius))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   TabulatedWidths &operator=(const TabulatedWidths &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         approximation = other.approximation;
         useForSelfShieldingOnly = other.useForSelfShieldingOnly;
         resonanceReactions = other.resonanceReactions;
         Ls = other.Ls;
         PoPs = other.PoPs;
         scatteringRadius = other.scatteringRadius;
      }
      return *this;
   }

   // move
   TabulatedWidths &operator=(TabulatedWidths &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         approximation = std::move(other.approximation);
         useForSelfShieldingOnly = std::move(other.useForSelfShieldingOnly);
         resonanceReactions = std::move(other.resonanceReactions);
         Ls = std::move(other.Ls);
         PoPs = std::move(other.PoPs);
         scatteringRadius = std::move(other.scatteringRadius);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/TabulatedWidths/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class TabulatedWidths

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
