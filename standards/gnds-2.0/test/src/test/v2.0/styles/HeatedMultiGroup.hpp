
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

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "HeatedMultiGroup"; }
   static auto NODENAME() { return "heatedMultiGroup"; }

   // Core Interface multi-query to transfer information to/from core Nodes
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
         --Child<styles::Transportables>
            ("transportables") |
         --Child<styles::Flux>
            ("flux") |
         --Child<styles::InverseSpeed>
            ("inverseSpeed") |
         --Child<std::optional<documentation::Documentation>>
            ("documentation")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "date",
         "derivedFrom",
         "label",
         "transportables",
         "flux",
         "inverseSpeed",
         "documentation"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "date",
         "derived_from",
         "label",
         "transportables",
         "flux",
         "inverse_speed",
         "documentation"
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
      date{this};
   Field<XMLName>
      derivedFrom{this};
   Field<XMLName>
      label{this};

   // children
   Field<styles::Transportables>
      transportables{this};
   Field<styles::Flux>
      flux{this};
   Field<styles::InverseSpeed>
      inverseSpeed{this};
   Field<std::optional<documentation::Documentation>>
      documentation{this};

   // shortcuts
   #define GNDSTK_SHORTCUT(to,name) decltype(to.name) &name = to.name
   GNDSTK_SHORTCUT(flux(),XYs2d);
   GNDSTK_SHORTCUT(inverseSpeed().gridded1d(),array);
   GNDSTK_SHORTCUT(flux().XYs2d(),function1ds);
   GNDSTK_SHORTCUT(inverseSpeed(),gridded1d);
   GNDSTK_SHORTCUT(transportables(),transportable);
   GNDSTK_SHORTCUT(flux().XYs2d(),uncertainty);
   #undef GNDSTK_SHORTCUT

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->date, \
      this->derivedFrom, \
      this->label, \
      this->transportables, \
      this->flux, \
      this->inverseSpeed, \
      this->documentation \
   )

   // default
   HeatedMultiGroup() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit HeatedMultiGroup(
      const wrapper<std::string>
         &date,
      const wrapper<XMLName>
         &derivedFrom = {},
      const wrapper<XMLName>
         &label = {},
      const wrapper<styles::Transportables>
         &transportables = {},
      const wrapper<styles::Flux>
         &flux = {},
      const wrapper<styles::InverseSpeed>
         &inverseSpeed = {},
      const wrapper<std::optional<documentation::Documentation>>
         &documentation = {}
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

   // copy
   HeatedMultiGroup &operator=(const HeatedMultiGroup &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         date = other.date;
         derivedFrom = other.derivedFrom;
         label = other.label;
         transportables = other.transportables;
         flux = other.flux;
         inverseSpeed = other.inverseSpeed;
         documentation = other.documentation;
      }
      return *this;
   }

   // move
   HeatedMultiGroup &operator=(HeatedMultiGroup &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         date = std::move(other.date);
         derivedFrom = std::move(other.derivedFrom);
         label = std::move(other.label);
         transportables = std::move(other.transportables);
         flux = std::move(other.flux);
         inverseSpeed = std::move(other.inverseSpeed);
         documentation = std::move(other.documentation);
      }
      return *this;
   }

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
