
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_ORPHANPRODUCT
#define GNDS_V2_0_GENERAL_ORPHANPRODUCT

#include "GNDS/v2.0/general/CrossSection.hpp"
#include "GNDS/v2.0/general/OutputChannel.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class OrphanProduct
// -----------------------------------------------------------------------------

class OrphanProduct :
   public Component<general::OrphanProduct>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "OrphanProduct"; }
   static auto NODENAME() { return "orphanProduct"; }

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
         --Child<general::CrossSection>
            ("crossSection") |
         --Child<general::OutputChannel>
            ("outputChannel")
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
         "crossSection",
         "outputChannel"
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
         "cross_section",
         "output_channel"
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
   Field<general::CrossSection>
      crossSection{this};
   Field<general::OutputChannel>
      outputChannel{this};

   // shortcuts
   #define NJOY_GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   NJOY_GNDSTK_SHORTCUT(crossSection(),CoulombPlusNuclearElastic);
   NJOY_GNDSTK_SHORTCUT(outputChannel().Q(),Double);
   NJOY_GNDSTK_SHORTCUT(outputChannel(),Q);
   NJOY_GNDSTK_SHORTCUT(crossSection(),XYs1d);
   NJOY_GNDSTK_SHORTCUT(outputChannel().Q(),constant1d);
   NJOY_GNDSTK_SHORTCUT(outputChannel(),fissionFragmentData);
   NJOY_GNDSTK_SHORTCUT(outputChannel(),products);
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
      this->crossSection, \
      this->outputChannel \
   )

   // default
   OrphanProduct() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit OrphanProduct(
      const wrapper<std::string>
         &label,
      const wrapper<int>
         &ENDF_MT = {},
      const wrapper<general::CrossSection>
         &crossSection = {},
      const wrapper<general::OutputChannel>
         &outputChannel = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      ENDF_MT(this,ENDF_MT),
      crossSection(this,crossSection),
      outputChannel(this,outputChannel)
   {
      Component::finish();
   }

   // from node
   explicit OrphanProduct(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   OrphanProduct(const OrphanProduct &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      ENDF_MT(this,other.ENDF_MT),
      crossSection(this,other.crossSection),
      outputChannel(this,other.outputChannel)
   {
      Component::finish(other);
   }

   // move
   OrphanProduct(OrphanProduct &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      ENDF_MT(this,std::move(other.ENDF_MT)),
      crossSection(this,std::move(other.crossSection)),
      outputChannel(this,std::move(other.outputChannel))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   OrphanProduct &operator=(const OrphanProduct &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         ENDF_MT = other.ENDF_MT;
         crossSection = other.crossSection;
         outputChannel = other.outputChannel;
      }
      return *this;
   }

   // move
   OrphanProduct &operator=(OrphanProduct &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         ENDF_MT = std::move(other.ENDF_MT);
         crossSection = std::move(other.crossSection);
         outputChannel = std::move(other.outputChannel);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/OrphanProduct/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class OrphanProduct

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
