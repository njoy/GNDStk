
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_STYLES_COULOMBPLUSNUCLEARELASTICMUCUTOFF
#define TEST_V2_0_STYLES_COULOMBPLUSNUCLEARELASTICMUCUTOFF

#include "test/v2.0/documentation/Documentation.hpp"

namespace test {
namespace v2_0 {
namespace styles {

// -----------------------------------------------------------------------------
// styles::
// class CoulombPlusNuclearElasticMuCutoff
// -----------------------------------------------------------------------------

class CoulombPlusNuclearElasticMuCutoff :
   public Component<styles::CoulombPlusNuclearElasticMuCutoff>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "styles"; }
   static auto CLASS() { return "CoulombPlusNuclearElasticMuCutoff"; }
   static auto FIELD() { return "CoulombPlusNuclearElasticMuCutoff"; }

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
         Float64{}
            / Meta<>("muCutoff") |

         // children
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
   Field<Float64> muCutoff{this};

   // children
   Field<std::optional<documentation::Documentation>> documentation{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->date, \
      this->derivedFrom, \
      this->label, \
      this->muCutoff, \
      this->documentation)

   // default
   CoulombPlusNuclearElasticMuCutoff() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CoulombPlusNuclearElasticMuCutoff(
      const wrapper<std::string> &date,
      const wrapper<XMLName> &derivedFrom = {},
      const wrapper<XMLName> &label = {},
      const wrapper<Float64> &muCutoff = {},
      const wrapper<std::optional<documentation::Documentation>> &documentation = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      date(this,date),
      derivedFrom(this,derivedFrom),
      label(this,label),
      muCutoff(this,muCutoff),
      documentation(this,documentation)
   {
      Component::finish();
   }

   // from node
   explicit CoulombPlusNuclearElasticMuCutoff(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CoulombPlusNuclearElasticMuCutoff(const CoulombPlusNuclearElasticMuCutoff &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      date(this,other.date),
      derivedFrom(this,other.derivedFrom),
      label(this,other.label),
      muCutoff(this,other.muCutoff),
      documentation(this,other.documentation)
   {
      Component::finish(other);
   }

   // move
   CoulombPlusNuclearElasticMuCutoff(CoulombPlusNuclearElasticMuCutoff &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      date(this,std::move(other.date)),
      derivedFrom(this,std::move(other.derivedFrom)),
      label(this,std::move(other.label)),
      muCutoff(this,std::move(other.muCutoff)),
      documentation(this,std::move(other.documentation))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   CoulombPlusNuclearElasticMuCutoff &operator=(const CoulombPlusNuclearElasticMuCutoff &) = default;
   CoulombPlusNuclearElasticMuCutoff &operator=(CoulombPlusNuclearElasticMuCutoff &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/styles/CoulombPlusNuclearElasticMuCutoff/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CoulombPlusNuclearElasticMuCutoff

} // namespace styles
} // namespace v2_0
} // namespace test

#endif
