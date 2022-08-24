
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_RESONANCES_SPINGROUP
#define NJOY_GNDSTK_V2_0_RESONANCES_SPINGROUP

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/resonances/Channels.hpp"
#include "GNDStk/v2.0/resonances/ResonanceParameters.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// resonances::
// class SpinGroup
// -----------------------------------------------------------------------------

namespace resonances {

class SpinGroup : public Component<SpinGroup> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "resonances"; }
   static auto className() { return "SpinGroup"; }
   static auto GNDSName() { return "spinGroup"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("label") |
         Integer32{1}
            / Meta<>("parity") |
         Fraction32{}
            / Meta<>("spin") |
         // children
         resonances::Channels{}
            / --Child<>("channels") |
         resonances::ResonanceParameters{}
            / --Child<>("resonanceParameters")
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
      XMLName label;
      Integer32 parity{1};
      Fraction32 spin;
      // children
      resonances::Channels channels;
      resonances::ResonanceParameters resonanceParameters;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const XMLName &label() const
      { return content.label; }
   XMLName &label()
      { return content.label; }

   // parity
   const Integer32 &parity() const
      { return content.parity; }
   Integer32 &parity()
      { return content.parity; }

   // spin
   const Fraction32 &spin() const
      { return content.spin; }
   Fraction32 &spin()
      { return content.spin; }

   // channels
   const resonances::Channels &channels() const
      { return content.channels; }
   resonances::Channels &channels()
      { return content.channels; }

   // resonanceParameters
   const resonances::ResonanceParameters &resonanceParameters() const
      { return content.resonanceParameters; }
   resonances::ResonanceParameters &resonanceParameters()
      { return content.resonanceParameters; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   SpinGroup &label(const XMLName &obj)
      { label() = obj; return *this; }

   // parity(value)
   SpinGroup &parity(const Integer32 &obj)
      { parity() = obj; return *this; }

   // spin(value)
   SpinGroup &spin(const Fraction32 &obj)
      { spin() = obj; return *this; }

   // channels(value)
   SpinGroup &channels(const resonances::Channels &obj)
      { channels() = obj; return *this; }

   // resonanceParameters(value)
   SpinGroup &resonanceParameters(const resonances::ResonanceParameters &obj)
      { resonanceParameters() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   SpinGroup() :
      Component{
         BodyText{},
         content.label,
         content.parity,
         content.spin,
         content.channels,
         content.resonanceParameters
      }
   {
      Component::finish();
   }

   // copy
   SpinGroup(const SpinGroup &other) :
      Component{
         other,
         content.label,
         content.parity,
         content.spin,
         content.channels,
         content.resonanceParameters
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   SpinGroup(SpinGroup &&other) :
      Component{
         other,
         content.label,
         content.parity,
         content.spin,
         content.channels,
         content.resonanceParameters
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   SpinGroup(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.parity,
         content.spin,
         content.channels,
         content.resonanceParameters
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit SpinGroup(
      const XMLName &label,
      const Integer32 &parity,
      const Fraction32 &spin,
      const resonances::Channels &channels,
      const resonances::ResonanceParameters &resonanceParameters
   ) :
      Component{
         BodyText{},
         content.label,
         content.parity,
         content.spin,
         content.channels,
         content.resonanceParameters
      },
      content{
         label,
         parity,
         spin,
         channels,
         resonanceParameters
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   SpinGroup &operator=(const SpinGroup &) = default;

   // move
   SpinGroup &operator=(SpinGroup &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/resonances/SpinGroup/src/custom.hpp"

}; // class SpinGroup

} // namespace resonances
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif