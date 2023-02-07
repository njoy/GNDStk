
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_COULOMBPLUSNUCLEARELASTIC
#define ALPHA_V2_0_GENERAL_COULOMBPLUSNUCLEARELASTIC

#include "alpha/v2.0/general/RutherfordScattering.hpp"
#include "alpha/v2.0/general/NuclearAmplitudeExpansion.hpp"
#include "alpha/v2.0/general/NuclearPlusInterference.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class CoulombPlusNuclearElastic
// -----------------------------------------------------------------------------

class CoulombPlusNuclearElastic :
   public Component<general::CoulombPlusNuclearElastic>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "CoulombPlusNuclearElastic"; }
   static auto FIELD() { return "CoulombPlusNuclearElastic"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::string{}
            / Meta<>("label") |
         std::optional<std::string>{}
            / Meta<>("href") |
         std::optional<std::string>{}
            / Meta<>("pid") |
         std::optional<std::string>{}
            / Meta<>("productFrame") |
         std::optional<bool>{}
            / Meta<>("identicalParticles") |

         // children
         --Child<std::optional<general::RutherfordScattering>>
            ("RutherfordScattering") |
         --Child<std::optional<general::NuclearAmplitudeExpansion>>
            ("nuclearAmplitudeExpansion") |
         --Child<std::optional<general::NuclearPlusInterference>>
            ("nuclearPlusInterference")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // metadata
   Field<std::string> label{this};
   Field<std::optional<std::string>> href{this};
   Field<std::optional<std::string>> pid{this};
   Field<std::optional<std::string>> productFrame{this};
   Field<std::optional<bool>> identicalParticles{this};

   // children
   Field<std::optional<general::RutherfordScattering>>
      RutherfordScattering{this};
   Field<std::optional<general::NuclearAmplitudeExpansion>>
      nuclearAmplitudeExpansion{this};
   Field<std::optional<general::NuclearPlusInterference>>
      nuclearPlusInterference{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->label, \
      this->href, \
      this->pid, \
      this->productFrame, \
      this->identicalParticles, \
      this->RutherfordScattering, \
      this->nuclearAmplitudeExpansion, \
      this->nuclearPlusInterference \
   )

   // default
   CoulombPlusNuclearElastic() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit CoulombPlusNuclearElastic(
      const wrapper<std::string>
         &label,
      const wrapper<std::optional<std::string>>
         &href = {},
      const wrapper<std::optional<std::string>>
         &pid = {},
      const wrapper<std::optional<std::string>>
         &productFrame = {},
      const wrapper<std::optional<bool>>
         &identicalParticles = {},
      const wrapper<std::optional<general::RutherfordScattering>>
         &RutherfordScattering = {},
      const wrapper<std::optional<general::NuclearAmplitudeExpansion>>
         &nuclearAmplitudeExpansion = {},
      const wrapper<std::optional<general::NuclearPlusInterference>>
         &nuclearPlusInterference = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      label(this,label),
      href(this,href),
      pid(this,pid),
      productFrame(this,productFrame),
      identicalParticles(this,identicalParticles),
      RutherfordScattering(this,RutherfordScattering),
      nuclearAmplitudeExpansion(this,nuclearAmplitudeExpansion),
      nuclearPlusInterference(this,nuclearPlusInterference)
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
      label(this,other.label),
      href(this,other.href),
      pid(this,other.pid),
      productFrame(this,other.productFrame),
      identicalParticles(this,other.identicalParticles),
      RutherfordScattering(this,other.RutherfordScattering),
      nuclearAmplitudeExpansion(this,other.nuclearAmplitudeExpansion),
      nuclearPlusInterference(this,other.nuclearPlusInterference)
   {
      Component::finish(other);
   }

   // move
   CoulombPlusNuclearElastic(CoulombPlusNuclearElastic &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      label(this,std::move(other.label)),
      href(this,std::move(other.href)),
      pid(this,std::move(other.pid)),
      productFrame(this,std::move(other.productFrame)),
      identicalParticles(this,std::move(other.identicalParticles)),
      RutherfordScattering(this,std::move(other.RutherfordScattering)),
      nuclearAmplitudeExpansion(this,std::move(other.nuclearAmplitudeExpansion)),
      nuclearPlusInterference(this,std::move(other.nuclearPlusInterference))
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
         label = other.label;
         href = other.href;
         pid = other.pid;
         productFrame = other.productFrame;
         identicalParticles = other.identicalParticles;
         RutherfordScattering = other.RutherfordScattering;
         nuclearAmplitudeExpansion = other.nuclearAmplitudeExpansion;
         nuclearPlusInterference = other.nuclearPlusInterference;
      }
      return *this;
   }

   // move
   CoulombPlusNuclearElastic &operator=(CoulombPlusNuclearElastic &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         label = std::move(other.label);
         href = std::move(other.href);
         pid = std::move(other.pid);
         productFrame = std::move(other.productFrame);
         identicalParticles = std::move(other.identicalParticles);
         RutherfordScattering = std::move(other.RutherfordScattering);
         nuclearAmplitudeExpansion = std::move(other.nuclearAmplitudeExpansion);
         nuclearPlusInterference = std::move(other.nuclearPlusInterference);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/CoulombPlusNuclearElastic/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class CoulombPlusNuclearElastic

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
