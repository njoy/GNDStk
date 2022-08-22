
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_NUCLEUS
#define NJOY_GNDSTK_V2_0_POPS_NUCLEUS

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Charge.hpp"
#include "GNDStk/v2.0/pops/DecayData.hpp"
#include "GNDStk/v2.0/pops/Energy.hpp"
#include "GNDStk/v2.0/fissionFragmentData/FissionFragmentData.hpp"
#include "GNDStk/v2.0/pops/Halflife.hpp"
#include "GNDStk/v2.0/pops/Parity.hpp"
#include "GNDStk/v2.0/pops/Spin.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Nucleus
// -----------------------------------------------------------------------------

namespace pops {

class Nucleus : public Component<Nucleus> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Nucleus"; }
   static auto GNDSName() { return "nucleus"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("id") |
         Integer32{}
            / Meta<>("index") |
         // children
         std::optional<pops::Charge>{}
            / --Child<>("charge") |
         std::optional<pops::DecayData>{}
            / --Child<>("decayData") |
         std::optional<pops::Energy>{}
            / --Child<>("energy") |
         std::optional<fissionFragmentData::FissionFragmentData>{}
            / --Child<>("fissionFragmentData") |
         std::optional<pops::Halflife>{}
            / --Child<>("halflife") |
         std::optional<pops::Parity>{}
            / --Child<>("parity") |
         std::optional<pops::Spin>{}
            / --Child<>("spin")
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
      // metadata
      XMLName id;
      Integer32 index;
      // children
      std::optional<pops::Charge> charge;
      std::optional<pops::DecayData> decayData;
      std::optional<pops::Energy> energy;
      std::optional<fissionFragmentData::FissionFragmentData> fissionFragmentData;
      std::optional<pops::Halflife> halflife;
      std::optional<pops::Parity> parity;
      std::optional<pops::Spin> spin;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // id
   const XMLName &id() const
      { return content.id; }
   XMLName &id()
      { return content.id; }

   // index
   const Integer32 &index() const
      { return content.index; }
   Integer32 &index()
      { return content.index; }

   // charge
   const std::optional<pops::Charge> &charge() const
      { return content.charge; }
   std::optional<pops::Charge> &charge()
      { return content.charge; }

   // decayData
   const std::optional<pops::DecayData> &decayData() const
      { return content.decayData; }
   std::optional<pops::DecayData> &decayData()
      { return content.decayData; }

   // energy
   const std::optional<pops::Energy> &energy() const
      { return content.energy; }
   std::optional<pops::Energy> &energy()
      { return content.energy; }

   // fissionFragmentData
   const std::optional<fissionFragmentData::FissionFragmentData> &fissionFragmentData() const
      { return content.fissionFragmentData; }
   std::optional<fissionFragmentData::FissionFragmentData> &fissionFragmentData()
      { return content.fissionFragmentData; }

   // halflife
   const std::optional<pops::Halflife> &halflife() const
      { return content.halflife; }
   std::optional<pops::Halflife> &halflife()
      { return content.halflife; }

   // parity
   const std::optional<pops::Parity> &parity() const
      { return content.parity; }
   std::optional<pops::Parity> &parity()
      { return content.parity; }

   // spin
   const std::optional<pops::Spin> &spin() const
      { return content.spin; }
   std::optional<pops::Spin> &spin()
      { return content.spin; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // id(value)
   Nucleus &id(const XMLName &obj)
      { id() = obj; return *this; }

   // index(value)
   Nucleus &index(const Integer32 &obj)
      { index() = obj; return *this; }

   // charge(value)
   Nucleus &charge(const std::optional<pops::Charge> &obj)
      { charge() = obj; return *this; }

   // decayData(value)
   Nucleus &decayData(const std::optional<pops::DecayData> &obj)
      { decayData() = obj; return *this; }

   // energy(value)
   Nucleus &energy(const std::optional<pops::Energy> &obj)
      { energy() = obj; return *this; }

   // fissionFragmentData(value)
   Nucleus &fissionFragmentData(const std::optional<fissionFragmentData::FissionFragmentData> &obj)
      { fissionFragmentData() = obj; return *this; }

   // halflife(value)
   Nucleus &halflife(const std::optional<pops::Halflife> &obj)
      { halflife() = obj; return *this; }

   // parity(value)
   Nucleus &parity(const std::optional<pops::Parity> &obj)
      { parity() = obj; return *this; }

   // spin(value)
   Nucleus &spin(const std::optional<pops::Spin> &obj)
      { spin() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Nucleus() :
      Component{
         BodyText{},
         content.id,
         content.index,
         content.charge,
         content.decayData,
         content.energy,
         content.fissionFragmentData,
         content.halflife,
         content.parity,
         content.spin
      }
   {
      Component::finish();
   }

   // copy
   Nucleus(const Nucleus &other) :
      Component{
         other,
         content.id,
         content.index,
         content.charge,
         content.decayData,
         content.energy,
         content.fissionFragmentData,
         content.halflife,
         content.parity,
         content.spin
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Nucleus(Nucleus &&other) :
      Component{
         other,
         content.id,
         content.index,
         content.charge,
         content.decayData,
         content.energy,
         content.fissionFragmentData,
         content.halflife,
         content.parity,
         content.spin
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Nucleus(const Node &node) :
      Component{
         BodyText{},
         content.id,
         content.index,
         content.charge,
         content.decayData,
         content.energy,
         content.fissionFragmentData,
         content.halflife,
         content.parity,
         content.spin
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Nucleus(
      const XMLName &id,
      const Integer32 &index,
      const std::optional<pops::Charge> &charge,
      const std::optional<pops::DecayData> &decayData,
      const std::optional<pops::Energy> &energy,
      const std::optional<fissionFragmentData::FissionFragmentData> &fissionFragmentData,
      const std::optional<pops::Halflife> &halflife,
      const std::optional<pops::Parity> &parity,
      const std::optional<pops::Spin> &spin
   ) :
      Component{
         BodyText{},
         content.id,
         content.index,
         content.charge,
         content.decayData,
         content.energy,
         content.fissionFragmentData,
         content.halflife,
         content.parity,
         content.spin
      },
      content{
         id,
         index,
         charge,
         decayData,
         energy,
         fissionFragmentData,
         halflife,
         parity,
         spin
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Nucleus &operator=(const Nucleus &) = default;

   // move
   Nucleus &operator=(Nucleus &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Nucleus/src/custom.hpp"

}; // class Nucleus

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
