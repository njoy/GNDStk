
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_WIDTH
#define GNDS_V2_0_GENERAL_WIDTH

#include "GNDS/v2.0/general/XYs1d.hpp"
#include "GNDS/v2.0/general/Constant1d.hpp"
#include "GNDS/v2.0/general/Regions1d.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Width
// -----------------------------------------------------------------------------

class Width :
   public Component<general::Width>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Width"; }
   static auto NODENAME() { return "width"; }

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
            / Meta<>("resonanceReaction") |
         int{}
            / Meta<>("degreesOfFreedom") |

         // children
         --Child<std::optional<general::XYs1d>>
            ("XYs1d") |
         --Child<std::optional<general::Constant1d>>
            ("constant1d") |
         --Child<std::optional<general::Regions1d>>
            ("regions1d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "resonanceReaction",
         "degreesOfFreedom",
         "XYs1d",
         "constant1d",
         "regions1d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "label",
         "resonance_reaction",
         "degrees_of_freedom",
         "xys1d",
         "constant1d",
         "regions1d"
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
      resonanceReaction{this};
   Field<int>
      degreesOfFreedom{this};

   // children
   Field<std::optional<general::XYs1d>>
      XYs1d{this};
   Field<std::optional<general::Constant1d>>
      constant1d{this};
   Field<std::optional<general::Regions1d>>
      regions1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->resonanceReaction, \
      this->degreesOfFreedom, \
      this->XYs1d, \
      this->constant1d, \
      this->regions1d \
   )

   // default
   Width() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Width(
      const wrapper<std::string>
         &label,
      const wrapper<std::string>
         &resonanceReaction = {},
      const wrapper<int>
         &degreesOfFreedom = {},
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d = {},
      const wrapper<std::optional<general::Constant1d>>
         &constant1d = {},
      const wrapper<std::optional<general::Regions1d>>
         &regions1d = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      resonanceReaction(this,resonanceReaction),
      degreesOfFreedom(this,degreesOfFreedom),
      XYs1d(this,XYs1d),
      constant1d(this,constant1d),
      regions1d(this,regions1d)
   {
      Component::finish();
   }

   // from node
   explicit Width(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Width(const Width &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      label(this,other.label),
      resonanceReaction(this,other.resonanceReaction),
      degreesOfFreedom(this,other.degreesOfFreedom),
      XYs1d(this,other.XYs1d),
      constant1d(this,other.constant1d),
      regions1d(this,other.regions1d)
   {
      Component::finish(other);
   }

   // move
   Width(Width &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      resonanceReaction(this,std::move(other.resonanceReaction)),
      degreesOfFreedom(this,std::move(other.degreesOfFreedom)),
      XYs1d(this,std::move(other.XYs1d)),
      constant1d(this,std::move(other.constant1d)),
      regions1d(this,std::move(other.regions1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Width &operator=(const Width &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         label = other.label;
         resonanceReaction = other.resonanceReaction;
         degreesOfFreedom = other.degreesOfFreedom;
         XYs1d = other.XYs1d;
         constant1d = other.constant1d;
         regions1d = other.regions1d;
      }
      return *this;
   }

   // move
   Width &operator=(Width &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         resonanceReaction = std::move(other.resonanceReaction);
         degreesOfFreedom = std::move(other.degreesOfFreedom);
         XYs1d = std::move(other.XYs1d);
         constant1d = std::move(other.constant1d);
         regions1d = std::move(other.regions1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/Width/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class Width

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
