
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_GENERAL_DISCRETE
#define ALPHA_V2_0_GENERAL_DISCRETE

#include "alpha/v2.0/general/Intensity.hpp"
#include "alpha/v2.0/general/Energy.hpp"
#include "alpha/v2.0/general/InternalConversionCoefficients.hpp"
#include "alpha/v2.0/general/PositronEmissionIntensity.hpp"

namespace alpha {
namespace v2_0 {
namespace general {

// -----------------------------------------------------------------------------
// general::
// class Discrete
// -----------------------------------------------------------------------------

class Discrete :
   public Component<general::Discrete>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "general"; }
   static auto CLASS() { return "Discrete"; }
   static auto FIELD() { return "discrete"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // metadata
         std::optional<std::string>{}
            / Meta<>("type") |

         // children
         --Child<general::Intensity>
            ("intensity") |
         --Child<general::Energy>
            ("energy") |
         --Child<std::optional<general::InternalConversionCoefficients>>
            ("internalConversionCoefficients") |
         --Child<std::optional<general::PositronEmissionIntensity>>
            ("positronEmissionIntensity")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "type",
         "intensity",
         "energy",
         "internalConversionCoefficients",
         "positronEmissionIntensity"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "type",
         "intensity",
         "energy",
         "internal_conversion_coefficients",
         "positron_emission_intensity"
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
   Field<std::optional<std::string>>
      type{this};

   // children
   Field<general::Intensity>
      intensity{this};
   Field<general::Energy>
      energy{this};
   Field<std::optional<general::InternalConversionCoefficients>>
      internalConversionCoefficients{this};
   Field<std::optional<general::PositronEmissionIntensity>>
      positronEmissionIntensity{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->type, \
      this->intensity, \
      this->energy, \
      this->internalConversionCoefficients, \
      this->positronEmissionIntensity \
   )

   // default
   Discrete() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Discrete(
      const wrapper<std::optional<std::string>>
         &type,
      const wrapper<general::Intensity>
         &intensity = {},
      const wrapper<general::Energy>
         &energy = {},
      const wrapper<std::optional<general::InternalConversionCoefficients>>
         &internalConversionCoefficients = {},
      const wrapper<std::optional<general::PositronEmissionIntensity>>
         &positronEmissionIntensity = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      type(this,type),
      intensity(this,intensity),
      energy(this,energy),
      internalConversionCoefficients(this,internalConversionCoefficients),
      positronEmissionIntensity(this,positronEmissionIntensity)
   {
      Component::finish();
   }

   // from node
   explicit Discrete(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Discrete(const Discrete &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      type(this,other.type),
      intensity(this,other.intensity),
      energy(this,other.energy),
      internalConversionCoefficients(this,other.internalConversionCoefficients),
      positronEmissionIntensity(this,other.positronEmissionIntensity)
   {
      Component::finish(other);
   }

   // move
   Discrete(Discrete &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      type(this,std::move(other.type)),
      intensity(this,std::move(other.intensity)),
      energy(this,std::move(other.energy)),
      internalConversionCoefficients(this,std::move(other.internalConversionCoefficients)),
      positronEmissionIntensity(this,std::move(other.positronEmissionIntensity))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Discrete &operator=(const Discrete &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         type = other.type;
         intensity = other.intensity;
         energy = other.energy;
         internalConversionCoefficients = other.internalConversionCoefficients;
         positronEmissionIntensity = other.positronEmissionIntensity;
      }
      return *this;
   }

   // move
   Discrete &operator=(Discrete &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         type = std::move(other.type);
         intensity = std::move(other.intensity);
         energy = std::move(other.energy);
         internalConversionCoefficients = std::move(other.internalConversionCoefficients);
         positronEmissionIntensity = std::move(other.positronEmissionIntensity);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/general/Discrete/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Discrete

} // namespace general
} // namespace v2_0
} // namespace alpha

#endif
