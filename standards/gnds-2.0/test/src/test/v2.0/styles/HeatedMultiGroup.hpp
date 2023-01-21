
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_STYLES_HEATEDMULTIGROUP
#define TEST_V2_0_STYLES_HEATEDMULTIGROUP

#include "test/v2.0/styles/Transportables.hpp"
#include "test/v2.0/styles/Flux.hpp"
#include "test/v2.0/styles/InverseSpeed.hpp"
#include "test/v2.0/documentation/Documentation.hpp"

namespace test {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class HeatedMultiGroup
// -----------------------------------------------------------------------------

class HeatedMultiGroup :
   public Component<styles::HeatedMultiGroup>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "HeatedMultiGroup"; }
   static auto FIELD() { return "heatedMultiGroup"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("date") |
         XMLName{}
            / Meta<>("derivedFrom") |
         XMLName{}
            / Meta<>("label") |

         // children
         --Child<styles::Transportables>("transportables") |
         --Child<styles::Flux>("flux") |
         --Child<styles::InverseSpeed>("inverseSpeed") |
         --Child<std::optional<documentation::Documentation>>("documentation")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> date{this};
   Field<XMLName> derivedFrom{this};
   Field<XMLName> label{this};

   // children
   Field<styles::Transportables> transportables{this};
   Field<styles::Flux> flux{this};
   Field<styles::InverseSpeed> inverseSpeed{this};
   Field<std::optional<documentation::Documentation>> documentation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->date, \
      this->derivedFrom, \
      this->label, \
      this->transportables, \
      this->flux, \
      this->inverseSpeed, \
      this->documentation)

   // default
   HeatedMultiGroup() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit HeatedMultiGroup(
      const wrapper<std::string> &date,
      const wrapper<XMLName> &derivedFrom = {},
      const wrapper<XMLName> &label = {},
      const wrapper<styles::Transportables> &transportables = {},
      const wrapper<styles::Flux> &flux = {},
      const wrapper<styles::InverseSpeed> &inverseSpeed = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      date(this,date),
      derivedFrom(this,derivedFrom),
      label(this,label),
      transportables(this,transportables),
      flux(this,flux),
      inverseSpeed(this,inverseSpeed),
      documentation(this,documentation)
   {
      Component::finish();
   }

   // from node
   explicit HeatedMultiGroup(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   HeatedMultiGroup(const HeatedMultiGroup &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      date(this,other.date),
      derivedFrom(this,other.derivedFrom),
      label(this,other.label),
      transportables(this,other.transportables),
      flux(this,other.flux),
      inverseSpeed(this,other.inverseSpeed),
      documentation(this,other.documentation)
   {
      Component::finish(other);
   }

   // move
   HeatedMultiGroup(HeatedMultiGroup &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      date(this,std::move(other.date)),
      derivedFrom(this,std::move(other.derivedFrom)),
      label(this,std::move(other.label)),
      transportables(this,std::move(other.transportables)),
      flux(this,std::move(other.flux)),
      inverseSpeed(this,std::move(other.inverseSpeed)),
      documentation(this,std::move(other.documentation))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   HeatedMultiGroup &operator=(const HeatedMultiGroup &) = default;
   HeatedMultiGroup &operator=(HeatedMultiGroup &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/styles/HeatedMultiGroup/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class HeatedMultiGroup

} // namespace styles
} // namespace v2_0
} // namespace test

#endif
