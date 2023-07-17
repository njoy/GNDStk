
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_CPTRANSPORT_COULOMBPLUSNUCLEARELASTIC
#define TEST_V2_0_CPTRANSPORT_COULOMBPLUSNUCLEARELASTIC

#include "test/v2.0/cpTransport/RutherfordScattering.hpp"
#include "test/v2.0/cpTransport/NuclearAmplitudeExpansion.hpp"

namespace test {
namespace v2_0 {
namespace cpTransport {

// -----------------------------------------------------------------------------
// cpTransport::
// class CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

class CoulombPlusNuclearElastic :
   public Component<cpTransport::CoulombPlusNuclearElastic>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "cpTransport"; }
   static auto CLASS() { return "CoulombPlusNuclearElastic"; }
   static auto NODENAME() { return "CoulombPlusNuclearElastic"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<XMLName>{}
            / Meta<>("href") |
         Defaulted<bool>{false}
            / Meta<>("identicalParticles") |
         XMLName{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("pid") |
         std::optional<enums::Frame>{}
            / Meta<>("productFrame") |

         // children
         --Child<std::optional<cpTransport::RutherfordScattering>>
            ("RutherfordScattering") |
         --Child<std::optional<cpTransport::NuclearAmplitudeExpansion>>
            ("nuclearAmplitudeExpansion")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "href",
         "identicalParticles",
         "label",
         "pid",
         "productFrame",
         "RutherfordScattering",
         "nuclearAmplitudeExpansion"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "href",
         "identical_particles",
         "label",
         "pid",
         "product_frame",
         "rutherford_scattering",
         "nuclear_amplitude_expansion"
      };
      return names;
   }

   // ------------------------
   // Public interface
   // ------------------------

public:

   using component_t = Component;
   using Component::construct;

   // defaults
   static inline const struct Defaults {
      static inline const bool identicalParticles = false;
   } defaults;

   // ------------------------
   // Data members
   // ------------------------

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::optional<XMLName>>
      href{this};
   Field<Defaulted<bool>>
      identicalParticles{this,defaults.identicalParticles};
   Field<XMLName>
      label{this};
   Field<std::optional<XMLName>>
      pid{this};
   Field<std::optional<enums::Frame>>
      productFrame{this};

   // children
   Field<std::optional<cpTransport::RutherfordScattering>>
      RutherfordScattering{this};
   Field<std::optional<cpTransport::NuclearAmplitudeExpansion>>
      nuclearAmplitudeExpansion{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->href, \
      this->identicalParticles, \
      this->label, \
      this->pid, \
      this->productFrame, \
      this->RutherfordScattering, \
      this->nuclearAmplitudeExpansion \
   )

   // default
   CoulombPlusNuclearElastic() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   // optional replaces Defaulted; this class knows the default(s)
   explicit CoulombPlusNuclearElastic(
      const wrapper<std::optional<XMLName>>
         &href,
      const wrapper<std::optional<bool>>
         &identicalParticles = {},
      const wrapper<XMLName>
         &label = {},
      const wrapper<std::optional<XMLName>>
         &pid = {},
      const wrapper<std::optional<enums::Frame>>
         &productFrame = {},
      const wrapper<std::optional<cpTransport::RutherfordScattering>>
         &RutherfordScattering = {},
      const wrapper<std::optional<cpTransport::NuclearAmplitudeExpansion>>
         &nuclearAmplitudeExpansion = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      href(this,href),
      identicalParticles(this,defaults.identicalParticles,identicalParticles),
      label(this,label),
      pid(this,pid),
      productFrame(this,productFrame),
      RutherfordScattering(this,RutherfordScattering),
      nuclearAmplitudeExpansion(this,nuclearAmplitudeExpansion)
   {
      Component::finish();
   }

   // from node
   explicit CoulombPlusNuclearElastic(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   CoulombPlusNuclearElastic(const CoulombPlusNuclearElastic &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      href(this,other.href),
      identicalParticles(this,other.identicalParticles),
      label(this,other.label),
      pid(this,other.pid),
      productFrame(this,other.productFrame),
      RutherfordScattering(this,other.RutherfordScattering),
      nuclearAmplitudeExpansion(this,other.nuclearAmplitudeExpansion)
   {
      Component::finish(other);
   }

   // move
   CoulombPlusNuclearElastic(CoulombPlusNuclearElastic &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      href(this,std::move(other.href)),
      identicalParticles(this,std::move(other.identicalParticles)),
      label(this,std::move(other.label)),
      pid(this,std::move(other.pid)),
      productFrame(this,std::move(other.productFrame)),
      RutherfordScattering(this,std::move(other.RutherfordScattering)),
      nuclearAmplitudeExpansion(this,std::move(other.nuclearAmplitudeExpansion))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   CoulombPlusNuclearElastic &operator=(const CoulombPlusNuclearElastic &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         href = other.href;
         identicalParticles = other.identicalParticles;
         label = other.label;
         pid = other.pid;
         productFrame = other.productFrame;
         RutherfordScattering = other.RutherfordScattering;
         nuclearAmplitudeExpansion = other.nuclearAmplitudeExpansion;
      }
      return *this;
   }

   // move
   CoulombPlusNuclearElastic &operator=(CoulombPlusNuclearElastic &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         href = std::move(other.href);
         identicalParticles = std::move(other.identicalParticles);
         label = std::move(other.label);
         pid = std::move(other.pid);
         productFrame = std::move(other.productFrame);
         RutherfordScattering = std::move(other.RutherfordScattering);
         nuclearAmplitudeExpansion = std::move(other.nuclearAmplitudeExpansion);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/cpTransport/CoulombPlusNuclearElastic/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CoulombPlusNuclearElastic

} // namespace cpTransport
} // namespace v2_0
} // namespace test

#endif
