
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef TEST_V2_0_TRANSPORT_ENERGY_UNCORRELATED
#define TEST_V2_0_TRANSPORT_ENERGY_UNCORRELATED

#include "test/v2.0/containers/XYs2d.hpp"
#include "test/v2.0/containers/Regions2d.hpp"
#include "test/v2.0/transport/GeneralEvaporation.hpp"
#include "test/v2.0/transport/DiscreteGamma.hpp"
#include "test/v2.0/transport/PrimaryGamma.hpp"
#include "test/v2.0/transport/NBodyPhaseSpace.hpp"
#include "test/v2.0/transport/Evaporation.hpp"
#include "test/v2.0/transport/WeightedFunctionals.hpp"
#include "test/v2.0/fissionTransport/SimpleMaxwellianFission.hpp"
#include "test/v2.0/fissionTransport/Watt.hpp"
#include "test/v2.0/fissionTransport/MadlandNix.hpp"

namespace test {
namespace v2_0 {
namespace transport {

// -----------------------------------------------------------------------------
// transport::
// class Energy_uncorrelated
// -----------------------------------------------------------------------------

class Energy_uncorrelated :
   public Component<transport::Energy_uncorrelated>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace and class, and original nodes (as in XML <...>)
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "Energy_uncorrelated"; }
   static auto NODENAME() { return "energy"; }

   // Core Interface multi-query to transfer information to/from core Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         --Child<std::optional<containers::XYs2d>>
            ("XYs2d") |
         --Child<std::optional<containers::Regions2d>>
            ("regions2d") |
         --Child<std::optional<transport::GeneralEvaporation>>
            ("generalEvaporation") |
         --Child<std::optional<transport::DiscreteGamma>>
            ("discreteGamma") |
         --Child<std::optional<transport::PrimaryGamma>>
            ("primaryGamma") |
         --Child<std::optional<transport::NBodyPhaseSpace>>
            ("NBodyPhaseSpace") |
         --Child<std::optional<transport::Evaporation>>
            ("evaporation") |
         --Child<std::optional<transport::WeightedFunctionals>>
            ("weightedFunctionals") |
         --Child<std::optional<fissionTransport::SimpleMaxwellianFission>>
            ("simpleMaxwellianFission") |
         --Child<std::optional<fissionTransport::Watt>>
            ("Watt") |
         --Child<std::optional<fissionTransport::MadlandNix>>
            ("MadlandNix")
      ;
   }

   // Data member names. Usually - but not necessarily - the same as the node
   // names appearing in KEYS(). These are used by Component's prettyprinter.
   static const auto &FIELDNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "XYs2d",
         "regions2d",
         "generalEvaporation",
         "discreteGamma",
         "primaryGamma",
         "NBodyPhaseSpace",
         "evaporation",
         "weightedFunctionals",
         "simpleMaxwellianFission",
         "Watt",
         "MadlandNix"
      };
      return names;
   }

   // Data member names, as they'll be presented in the Python bindings.
   static const auto &PYTHONNAMES()
   {
      static const std::vector<std::string> names = {
         "comment",
         "xys2d",
         "regions2d",
         "general_evaporation",
         "discrete_gamma",
         "primary_gamma",
         "nbody_phase_space",
         "evaporation",
         "weighted_functionals",
         "simple_maxwellian_fission",
         "watt",
         "madland_nix"
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
   Field<std::optional<containers::XYs2d>>
      XYs2d{this};
   Field<std::optional<containers::Regions2d>>
      regions2d{this};
   Field<std::optional<transport::GeneralEvaporation>>
      generalEvaporation{this};
   Field<std::optional<transport::DiscreteGamma>>
      discreteGamma{this};
   Field<std::optional<transport::PrimaryGamma>>
      primaryGamma{this};
   Field<std::optional<transport::NBodyPhaseSpace>>
      NBodyPhaseSpace{this};
   Field<std::optional<transport::Evaporation>>
      evaporation{this};
   Field<std::optional<transport::WeightedFunctionals>>
      weightedFunctionals{this};
   Field<std::optional<fissionTransport::SimpleMaxwellianFission>>
      simpleMaxwellianFission{this};
   Field<std::optional<fissionTransport::Watt>>
      Watt{this};
   Field<std::optional<fissionTransport::MadlandNix>>
      MadlandNix{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) \
   Component( \
      blockdata, \
      this->comment, \
      this->XYs2d, \
      this->regions2d, \
      this->generalEvaporation, \
      this->discreteGamma, \
      this->primaryGamma, \
      this->NBodyPhaseSpace, \
      this->evaporation, \
      this->weightedFunctionals, \
      this->simpleMaxwellianFission, \
      this->Watt, \
      this->MadlandNix \
   )

   // default
   Energy_uncorrelated() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Energy_uncorrelated(
      const wrapper<std::optional<containers::XYs2d>>
         &XYs2d,
      const wrapper<std::optional<containers::Regions2d>>
         &regions2d = {},
      const wrapper<std::optional<transport::GeneralEvaporation>>
         &generalEvaporation = {},
      const wrapper<std::optional<transport::DiscreteGamma>>
         &discreteGamma = {},
      const wrapper<std::optional<transport::PrimaryGamma>>
         &primaryGamma = {},
      const wrapper<std::optional<transport::NBodyPhaseSpace>>
         &NBodyPhaseSpace = {},
      const wrapper<std::optional<transport::Evaporation>>
         &evaporation = {},
      const wrapper<std::optional<transport::WeightedFunctionals>>
         &weightedFunctionals = {},
      const wrapper<std::optional<fissionTransport::SimpleMaxwellianFission>>
         &simpleMaxwellianFission = {},
      const wrapper<std::optional<fissionTransport::Watt>>
         &Watt = {},
      const wrapper<std::optional<fissionTransport::MadlandNix>>
         &MadlandNix = {}
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      XYs2d(this,XYs2d),
      regions2d(this,regions2d),
      generalEvaporation(this,generalEvaporation),
      discreteGamma(this,discreteGamma),
      primaryGamma(this,primaryGamma),
      NBodyPhaseSpace(this,NBodyPhaseSpace),
      evaporation(this,evaporation),
      weightedFunctionals(this,weightedFunctionals),
      simpleMaxwellianFission(this,simpleMaxwellianFission),
      Watt(this,Watt),
      MadlandNix(this,MadlandNix)
   {
      Component::finish();
   }

   // from node
   explicit Energy_uncorrelated(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Energy_uncorrelated(const Energy_uncorrelated &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      XYs2d(this,other.XYs2d),
      regions2d(this,other.regions2d),
      generalEvaporation(this,other.generalEvaporation),
      discreteGamma(this,other.discreteGamma),
      primaryGamma(this,other.primaryGamma),
      NBodyPhaseSpace(this,other.NBodyPhaseSpace),
      evaporation(this,other.evaporation),
      weightedFunctionals(this,other.weightedFunctionals),
      simpleMaxwellianFission(this,other.simpleMaxwellianFission),
      Watt(this,other.Watt),
      MadlandNix(this,other.MadlandNix)
   {
      Component::finish(other);
   }

   // move
   Energy_uncorrelated(Energy_uncorrelated &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      XYs2d(this,std::move(other.XYs2d)),
      regions2d(this,std::move(other.regions2d)),
      generalEvaporation(this,std::move(other.generalEvaporation)),
      discreteGamma(this,std::move(other.discreteGamma)),
      primaryGamma(this,std::move(other.primaryGamma)),
      NBodyPhaseSpace(this,std::move(other.NBodyPhaseSpace)),
      evaporation(this,std::move(other.evaporation)),
      weightedFunctionals(this,std::move(other.weightedFunctionals)),
      simpleMaxwellianFission(this,std::move(other.simpleMaxwellianFission)),
      Watt(this,std::move(other.Watt)),
      MadlandNix(this,std::move(other.MadlandNix))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   // copy
   Energy_uncorrelated &operator=(const Energy_uncorrelated &other)
   {
      if (this != &other) {
         Component::operator=(other);
         comment = other.comment;
         XYs2d = other.XYs2d;
         regions2d = other.regions2d;
         generalEvaporation = other.generalEvaporation;
         discreteGamma = other.discreteGamma;
         primaryGamma = other.primaryGamma;
         NBodyPhaseSpace = other.NBodyPhaseSpace;
         evaporation = other.evaporation;
         weightedFunctionals = other.weightedFunctionals;
         simpleMaxwellianFission = other.simpleMaxwellianFission;
         Watt = other.Watt;
         MadlandNix = other.MadlandNix;
      }
      return *this;
   }

   // move
   Energy_uncorrelated &operator=(Energy_uncorrelated &&other)
   {
      if (this != &other) {
         Component::operator=(std::move(other));
         comment = std::move(other.comment);
         XYs2d = std::move(other.XYs2d);
         regions2d = std::move(other.regions2d);
         generalEvaporation = std::move(other.generalEvaporation);
         discreteGamma = std::move(other.discreteGamma);
         primaryGamma = std::move(other.primaryGamma);
         NBodyPhaseSpace = std::move(other.NBodyPhaseSpace);
         evaporation = std::move(other.evaporation);
         weightedFunctionals = std::move(other.weightedFunctionals);
         simpleMaxwellianFission = std::move(other.simpleMaxwellianFission);
         Watt = std::move(other.Watt);
         MadlandNix = std::move(other.MadlandNix);
      }
      return *this;
   }

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "test/v2.0/transport/Energy_uncorrelated/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Energy_uncorrelated

} // namespace transport
} // namespace v2_0
} // namespace test

#endif
