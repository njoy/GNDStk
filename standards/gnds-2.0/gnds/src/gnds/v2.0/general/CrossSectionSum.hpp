
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_CROSSSECTIONSUM
#define GNDS_V2_0_GENERAL_CROSSSECTIONSUM

#include "gnds/v2.0/general/Summands.hpp"
#include "gnds/v2.0/general/Q.hpp"
#include "gnds/v2.0/general/CrossSection.hpp"

namespace gnds {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class CrossSectionSum
// -----------------------------------------------------------------------------

class CrossSectionSum :
   public Component<general::CrossSectionSum>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "CrossSectionSum"; }
   static auto NODENAME() { return "crossSectionSum"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         int{}
            / Meta<>("ENDF_MT") |

         // children
         --Child<general::Summands>
            ("summands") |
         --Child<general::Q>
            ("Q") |
         --Child<general::CrossSection>
            ("crossSection")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "ENDF_MT",
         "summands",
         "Q",
         "crossSection"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "endf_mt",
         "summands",
         "q",
         "cross_section"
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
   Field<int>
      ENDF_MT{this};

   // children
   Field<general::Summands>
      summands{this};
   Field<general::Q>
      Q{this};
   Field<general::CrossSection>
      crossSection{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(crossSection(),CoulombPlusNuclearElastic);
   NJOY_GNDSTK_SHORTCUT(Q(),Double);
   NJOY_GNDSTK_SHORTCUT(crossSection(),XYs1d);
   NJOY_GNDSTK_SHORTCUT(summands(),add);
   NJOY_GNDSTK_SHORTCUT(Q(),constant1d);
   NJOY_GNDSTK_SHORTCUT(crossSection(),reference);
   NJOY_GNDSTK_SHORTCUT(crossSection(),regions1d);
   NJOY_GNDSTK_SHORTCUT(crossSection(),resonancesWithBackground);
   NJOY_GNDSTK_SHORTCUT(crossSection(),thermalNeutronScatteringLaw1d);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->ENDF_MT, \
      this->summands, \
      this->Q, \
      this->crossSection \
   )

   // default
   CrossSectionSum() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CrossSectionSum(
      const wrapper<std::string>
         &label,
      const wrapper<int>
         &ENDF_MT = {},
      const wrapper<general::Summands>
         &summands = {},
      const wrapper<general::Q>
         &Q = {},
      const wrapper<general::CrossSection>
         &crossSection = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ENDF_MT(this,ENDF_MT),
      summands(this,summands),
      Q(this,Q),
      crossSection(this,crossSection)
   {
      Component::finish();
   }

   // from node
   explicit CrossSectionSum(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CrossSectionSum(const CrossSectionSum &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      ENDF_MT(this,other.ENDF_MT),
      summands(this,other.summands),
      Q(this,other.Q),
      crossSection(this,other.crossSection)
   {
      Component::finish(other);
   }

   // move
   CrossSectionSum(CrossSectionSum &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      ENDF_MT(this,std::move(other.ENDF_MT)),
      summands(this,std::move(other.summands)),
      Q(this,std::move(other.Q)),
      crossSection(this,std::move(other.crossSection))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   CrossSectionSum &operator=(const CrossSectionSum &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         ENDF_MT = other.ENDF_MT;
         summands = other.summands;
         Q = other.Q;
         crossSection = other.crossSection;
      }
      return *this;
   }

   // move
   CrossSectionSum &operator=(CrossSectionSum &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         ENDF_MT = std::move(other.ENDF_MT);
         summands = std::move(other.summands);
         Q = std::move(other.Q);
         crossSection = std::move(other.crossSection);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "gnds/v2.0/general/CrossSectionSum/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class CrossSectionSum

} // namespace general
} // namespace v2_0
} // namespace gnds

#endif
