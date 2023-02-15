
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_PROMPTPRODUCTKE
#define ALPHA_V2_0_GENERAL_PROMPTPRODUCTKE

#include "alpha/v2.0/general/Polynomial1d.hpp"
#include "alpha/v2.0/general/XYs1d.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class PromptProductKE
// -----------------------------------------------------------------------------

class PromptProductKE :
   public Component<general::PromptProductKE>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "PromptProductKE"; }
   static auto FIELD() { return "promptProductKE"; }

   // Core Interface multi-query to transfer information to/from Nodes
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

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->polynomial1d, \
      this->XYs1d \
   )

   // default
   PromptProductKE() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit PromptProductKE(
      const wrapper<std::optional<general::Polynomial1d>>
         &polynomial1d,
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      polynomial1d(this,polynomial1d),
      XYs1d(this,XYs1d)
   {
      Component::finish();
   }

   // from node
   explicit PromptProductKE(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   PromptProductKE(const PromptProductKE &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      polynomial1d(this,other.polynomial1d),
      XYs1d(this,other.XYs1d)
   {
      Component::finish(other);
   }

   // move
   PromptProductKE(PromptProductKE &&other) :
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

   // copy
   PromptProductKE &operator=(const PromptProductKE &other)
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
   PromptProductKE &operator=(PromptProductKE &&other)
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

   #include "alpha/v2.0/general/PromptProductKE/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class PromptProductKE

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
