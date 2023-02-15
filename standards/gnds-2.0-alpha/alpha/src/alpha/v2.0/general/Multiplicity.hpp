
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_MULTIPLICITY
#define ALPHA_V2_0_GENERAL_MULTIPLICITY

#include "alpha/v2.0/general/Constant1d.hpp"
#include "alpha/v2.0/general/XYs1d.hpp"
#include "alpha/v2.0/general/Regions1d.hpp"
#include "alpha/v2.0/general/Polynomial1d.hpp"
#include "alpha/v2.0/general/Reference.hpp"
#include "alpha/v2.0/general/Branching1d.hpp"
#include "alpha/v2.0/general/Branching3d.hpp"
#include "alpha/v2.0/general/Unspecified.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Multiplicity
// -----------------------------------------------------------------------------

class Multiplicity :
   public Component<general::Multiplicity>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Multiplicity"; }
   static auto FIELD() { return "multiplicity"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<general::Constant1d>>
            ("constant1d") |
         --Child<std::optional<general::XYs1d>>
            ("XYs1d") |
         --Child<std::optional<general::Regions1d>>
            ("regions1d") |
         --Child<std::optional<general::Polynomial1d>>
            ("polynomial1d") |
         --Child<std::optional<general::Reference>>
            ("reference") |
         --Child<std::optional<general::Branching1d>>
            ("branching1d") |
         --Child<std::optional<general::Branching3d>>
            ("branching3d") |
         --Child<std::optional<general::Unspecified>>
            ("unspecified")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "constant1d",
         "XYs1d",
         "regions1d",
         "polynomial1d",
         "reference",
         "branching1d",
         "branching3d",
         "unspecified"
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
   Field<std::optional<general::Constant1d>>
      constant1d{this};
   Field<std::optional<general::XYs1d>>
      XYs1d{this};
   Field<std::optional<general::Regions1d>>
      regions1d{this};
   Field<std::optional<general::Polynomial1d>>
      polynomial1d{this};
   Field<std::optional<general::Reference>>
      reference{this};
   Field<std::optional<general::Branching1d>>
      branching1d{this};
   Field<std::optional<general::Branching3d>>
      branching3d{this};
   Field<std::optional<general::Unspecified>>
      unspecified{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->constant1d, \
      this->XYs1d, \
      this->regions1d, \
      this->polynomial1d, \
      this->reference, \
      this->branching1d, \
      this->branching3d, \
      this->unspecified \
   )

   // default
   Multiplicity() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Multiplicity(
      const wrapper<std::optional<general::Constant1d>>
         &constant1d,
      const wrapper<std::optional<general::XYs1d>>
         &XYs1d = {},
      const wrapper<std::optional<general::Regions1d>>
         &regions1d = {},
      const wrapper<std::optional<general::Polynomial1d>>
         &polynomial1d = {},
      const wrapper<std::optional<general::Reference>>
         &reference = {},
      const wrapper<std::optional<general::Branching1d>>
         &branching1d = {},
      const wrapper<std::optional<general::Branching3d>>
         &branching3d = {},
      const wrapper<std::optional<general::Unspecified>>
         &unspecified = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      constant1d(this,constant1d),
      XYs1d(this,XYs1d),
      regions1d(this,regions1d),
      polynomial1d(this,polynomial1d),
      reference(this,reference),
      branching1d(this,branching1d),
      branching3d(this,branching3d),
      unspecified(this,unspecified)
   {
      Component::finish();
   }

   // from node
   explicit Multiplicity(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Multiplicity(const Multiplicity &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      constant1d(this,other.constant1d),
      XYs1d(this,other.XYs1d),
      regions1d(this,other.regions1d),
      polynomial1d(this,other.polynomial1d),
      reference(this,other.reference),
      branching1d(this,other.branching1d),
      branching3d(this,other.branching3d),
      unspecified(this,other.unspecified)
   {
      Component::finish(other);
   }

   // move
   Multiplicity(Multiplicity &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      constant1d(this,std::move(other.constant1d)),
      XYs1d(this,std::move(other.XYs1d)),
      regions1d(this,std::move(other.regions1d)),
      polynomial1d(this,std::move(other.polynomial1d)),
      reference(this,std::move(other.reference)),
      branching1d(this,std::move(other.branching1d)),
      branching3d(this,std::move(other.branching3d)),
      unspecified(this,std::move(other.unspecified))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Multiplicity &operator=(const Multiplicity &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         constant1d = other.constant1d;
         XYs1d = other.XYs1d;
         regions1d = other.regions1d;
         polynomial1d = other.polynomial1d;
         reference = other.reference;
         branching1d = other.branching1d;
         branching3d = other.branching3d;
         unspecified = other.unspecified;
      }
      return *this;
   }

   // move
   Multiplicity &operator=(Multiplicity &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         constant1d = std::move(other.constant1d);
         XYs1d = std::move(other.XYs1d);
         regions1d = std::move(other.regions1d);
         polynomial1d = std::move(other.polynomial1d);
         reference = std::move(other.reference);
         branching1d = std::move(other.branching1d);
         branching3d = std::move(other.branching3d);
         unspecified = std::move(other.unspecified);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Multiplicity/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Multiplicity

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
