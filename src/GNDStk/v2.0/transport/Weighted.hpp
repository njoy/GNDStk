
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_TRANSPORT_WEIGHTED
#define NJOY_GNDSTK_V2_0_TRANSPORT_WEIGHTED

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/fissionTransport/MadlandNix.hpp"
#include "GNDStk/v2.0/fissionTransport/Watt.hpp"
#include "GNDStk/v2.0/containers/XYs1d.hpp"
#include "GNDStk/v2.0/containers/XYs2d.hpp"
#include "GNDStk/v2.0/transport/Evaporation.hpp"
#include "GNDStk/v2.0/transport/GeneralEvaporation.hpp"
#include "GNDStk/v2.0/fissionTransport/SimpleMaxwellianFission.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// transport::
// class Weighted
// -----------------------------------------------------------------------------

namespace transport {

class Weighted : public Component<Weighted> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "transport"; }
   static auto className() { return "Weighted"; }
   static auto GNDSName() { return "weighted"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         std::optional<fissionTransport::MadlandNix>{}
            / --Child<>("MadlandNix") |
         std::optional<fissionTransport::Watt>{}
            / --Child<>("Watt") |
         containers::XYs1d{}
            / --Child<>("XYs1d") |
         std::optional<containers::XYs2d>{}
            / --Child<>("XYs2d") |
         std::optional<transport::Evaporation>{}
            / --Child<>("evaporation") |
         std::optional<transport::GeneralEvaporation>{}
            / --Child<>("generalEvaporation") |
         std::optional<fissionTransport::SimpleMaxwellianFission>{}
            / --Child<>("simpleMaxwellianFission")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // children
      std::optional<fissionTransport::MadlandNix> MadlandNix;
      std::optional<fissionTransport::Watt> Watt;
      containers::XYs1d XYs1d;
      std::optional<containers::XYs2d> XYs2d;
      std::optional<transport::Evaporation> evaporation;
      std::optional<transport::GeneralEvaporation> generalEvaporation;
      std::optional<fissionTransport::SimpleMaxwellianFission> simpleMaxwellianFission;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // MadlandNix
   const std::optional<fissionTransport::MadlandNix> &MadlandNix() const
      { return content.MadlandNix; }
   std::optional<fissionTransport::MadlandNix> &MadlandNix()
      { return content.MadlandNix; }

   // Watt
   const std::optional<fissionTransport::Watt> &Watt() const
      { return content.Watt; }
   std::optional<fissionTransport::Watt> &Watt()
      { return content.Watt; }

   // XYs1d
   const containers::XYs1d &XYs1d() const
      { return content.XYs1d; }
   containers::XYs1d &XYs1d()
      { return content.XYs1d; }

   // XYs2d
   const std::optional<containers::XYs2d> &XYs2d() const
      { return content.XYs2d; }
   std::optional<containers::XYs2d> &XYs2d()
      { return content.XYs2d; }

   // evaporation
   const std::optional<transport::Evaporation> &evaporation() const
      { return content.evaporation; }
   std::optional<transport::Evaporation> &evaporation()
      { return content.evaporation; }

   // generalEvaporation
   const std::optional<transport::GeneralEvaporation> &generalEvaporation() const
      { return content.generalEvaporation; }
   std::optional<transport::GeneralEvaporation> &generalEvaporation()
      { return content.generalEvaporation; }

   // simpleMaxwellianFission
   const std::optional<fissionTransport::SimpleMaxwellianFission> &simpleMaxwellianFission() const
      { return content.simpleMaxwellianFission; }
   std::optional<fissionTransport::SimpleMaxwellianFission> &simpleMaxwellianFission()
      { return content.simpleMaxwellianFission; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // MadlandNix(value)
   Weighted &MadlandNix(const std::optional<fissionTransport::MadlandNix> &obj)
      { MadlandNix() = obj; return *this; }

   // Watt(value)
   Weighted &Watt(const std::optional<fissionTransport::Watt> &obj)
      { Watt() = obj; return *this; }

   // XYs1d(value)
   Weighted &XYs1d(const containers::XYs1d &obj)
      { XYs1d() = obj; return *this; }

   // XYs2d(value)
   Weighted &XYs2d(const std::optional<containers::XYs2d> &obj)
      { XYs2d() = obj; return *this; }

   // evaporation(value)
   Weighted &evaporation(const std::optional<transport::Evaporation> &obj)
      { evaporation() = obj; return *this; }

   // generalEvaporation(value)
   Weighted &generalEvaporation(const std::optional<transport::GeneralEvaporation> &obj)
      { generalEvaporation() = obj; return *this; }

   // simpleMaxwellianFission(value)
   Weighted &simpleMaxwellianFission(const std::optional<fissionTransport::SimpleMaxwellianFission> &obj)
      { simpleMaxwellianFission() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Weighted() :
      Component{
         BodyText{},
         content.MadlandNix,
         content.Watt,
         content.XYs1d,
         content.XYs2d,
         content.evaporation,
         content.generalEvaporation,
         content.simpleMaxwellianFission
      }
   {
      Component::finish();
   }

   // copy
   Weighted(const Weighted &other) :
      Component{
         other,
         content.MadlandNix,
         content.Watt,
         content.XYs1d,
         content.XYs2d,
         content.evaporation,
         content.generalEvaporation,
         content.simpleMaxwellianFission
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Weighted(Weighted &&other) :
      Component{
         other,
         content.MadlandNix,
         content.Watt,
         content.XYs1d,
         content.XYs2d,
         content.evaporation,
         content.generalEvaporation,
         content.simpleMaxwellianFission
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Weighted(const Node &node) :
      Component{
         BodyText{},
         content.MadlandNix,
         content.Watt,
         content.XYs1d,
         content.XYs2d,
         content.evaporation,
         content.generalEvaporation,
         content.simpleMaxwellianFission
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Weighted(
      const std::optional<fissionTransport::MadlandNix> &MadlandNix,
      const std::optional<fissionTransport::Watt> &Watt,
      const containers::XYs1d &XYs1d,
      const std::optional<containers::XYs2d> &XYs2d,
      const std::optional<transport::Evaporation> &evaporation,
      const std::optional<transport::GeneralEvaporation> &generalEvaporation,
      const std::optional<fissionTransport::SimpleMaxwellianFission> &simpleMaxwellianFission
   ) :
      Component{
         BodyText{},
         content.MadlandNix,
         content.Watt,
         content.XYs1d,
         content.XYs2d,
         content.evaporation,
         content.generalEvaporation,
         content.simpleMaxwellianFission
      },
      content{
         MadlandNix,
         Watt,
         XYs1d,
         XYs2d,
         evaporation,
         generalEvaporation,
         simpleMaxwellianFission
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Weighted &operator=(const Weighted &) = default;

   // move
   Weighted &operator=(Weighted &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/transport/Weighted/src/custom.hpp"

}; // class Weighted

} // namespace transport
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif