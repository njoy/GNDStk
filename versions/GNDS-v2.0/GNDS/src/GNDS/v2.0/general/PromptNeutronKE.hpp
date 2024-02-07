
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDS_V2_0_GENERAL_PROMPTNEUTRONKE
#define GNDS_V2_0_GENERAL_PROMPTNEUTRONKE

#include "GNDS/v2.0/general/Polynomial1d.hpp"
#include "GNDS/v2.0/general/XYs1d.hpp"

namespace GNDS {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class PromptNeutronKE
// -----------------------------------------------------------------------------

class PromptNeutronKE :
   public Component<general::PromptNeutronKE>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "PromptNeutronKE"; }
   static auto NODENAME() { return "promptNeutronKE"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::Polynomial1d>>
            ("polynomial1d") |
         --Child<std::optional<general::XYs1d>>
            ("XYs1d")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "polynomial1d",
         "XYs1d"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "polynomial1d",
         "xys1d"
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

   // children
   Field<std::optional<general::Polynomial1d>>
      polynomial1d{this};
   Field<std::optional<general::XYs1d>>
      XYs1d{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define NJOY_GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->polynomial1d, \
      this->XYs1d \
   )

   // default
   PromptNeutronKE() :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit PromptNeutronKE(
      const wrapper<std::optional<general::Polynomial1d>>
         &polynomial1d,
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d = {}
   ) :
      NJOY_GNDSTK_COMPONENT(BlockData{}),
      polynomial1d(this,polynomial1d),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit PromptNeutronKE(const Node &node) :
      NJOY_GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   PromptNeutronKE(const PromptNeutronKE &other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      polynomial1d(this,other.polynomial1d),
      XYs1d(this,other.XYs1d)
   {
      Component::finish(other);
   }

   // move
   PromptNeutronKE(PromptNeutronKE &&other) :
      NJOY_GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      polynomial1d(this,std::move(other.polynomial1d)),
      XYs1d(this,std::move(other.XYs1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   PromptNeutronKE &operator=(const PromptNeutronKE &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         polynomial1d = other.polynomial1d;
         XYs1d = other.XYs1d;
      }
      return *this;
   }

   // move
   PromptNeutronKE &operator=(PromptNeutronKE &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         polynomial1d = std::move(other.polynomial1d);
         XYs1d = std::move(other.XYs1d);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDS/v2.0/general/PromptNeutronKE/src/custom.hpp"
   #undef NJOY_GNDSTK_COMPONENT
}; // class PromptNeutronKE

} // namespace general
} // namespace v2_0
} // namespace GNDS

#endif
