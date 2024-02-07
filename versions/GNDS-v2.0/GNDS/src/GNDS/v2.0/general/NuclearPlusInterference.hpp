
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_NUCLEARPLUSINTERFERENCE
#define GNDS_V2_0_GENERAL_NUCLEARPLUSINTERFERENCE

#include "GNDS/v2.0/reduced/CrossSection.hpp"
#include "GNDS/v2.0/reduced/Distribution.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class NuclearPlusInterference
// -----------------------------------------------------------------------------

class NuclearPlusInterference :
   public Component<general::NuclearPlusInterference>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "NuclearPlusInterference"; }
   static auto NODENAME() { return "nuclearPlusInterference"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         double{}
            / Meta<>("muCutoff") |

         // children
         --Child<reduced::CrossSection>
            ("crossSection") |
         --Child<reduced::Distribution>
            ("distribution")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "muCutoff",
         "crossSection",
         "distribution"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "mu_cutoff",
         "cross_section",
         "distribution"
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
   Field<double>
      muCutoff{this};

   // children
   Field<reduced::CrossSection>
      crossSection{this};
   Field<reduced::Distribution>
      distribution{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(crossSection(),XYs1d);
   NJOY_GNDSTK_SHORTCUT(distribution(),XYs2d);
   NJOY_GNDSTK_SHORTCUT(distribution(),branching3d);
   NJOY_GNDSTK_SHORTCUT(crossSection(),reference);
   NJOY_GNDSTK_SHORTCUT(crossSection(),regions1d);
   NJOY_GNDSTK_SHORTCUT(distribution(),thermalNeutronScatteringLaw);
   NJOY_GNDSTK_SHORTCUT(distribution(),uncorrelated);
   NJOY_GNDSTK_SHORTCUT(distribution(),unspecified);
   #undef NJOY_GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->muCutoff, \
      this->crossSection, \
      this->distribution \
   )

   // default
   NuclearPlusInterference() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit NuclearPlusInterference(
      const wrapper<double>
         &muCutoff,
      const wrapper<reduced::CrossSection>
         &crossSection = {},
      const wrapper<reduced::Distribution>
         &distribution = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      muCutoff(this,muCutoff),
      crossSection(this,crossSection),
      distribution(this,distribution)
   {
      Component::finish();
   }

   // from node
   explicit NuclearPlusInterference(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   NuclearPlusInterference(const NuclearPlusInterference &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      muCutoff(this,other.muCutoff),
      crossSection(this,other.crossSection),
      distribution(this,other.distribution)
   {
      Component::finish(other);
   }

   // move
   NuclearPlusInterference(NuclearPlusInterference &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      muCutoff(this,std::move(other.muCutoff)),
      crossSection(this,std::move(other.crossSection)),
      distribution(this,std::move(other.distribution))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   NuclearPlusInterference &operator=(const NuclearPlusInterference &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         muCutoff = other.muCutoff;
         crossSection = other.crossSection;
         distribution = other.distribution;
      }
      return *this;
   }

   // move
   NuclearPlusInterference &operator=(NuclearPlusInterference &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         muCutoff = std::move(other.muCutoff);
         crossSection = std::move(other.crossSection);
         distribution = std::move(other.distribution);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/NuclearPlusInterference/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class NuclearPlusInterference

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif