
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_LEPTONS
#define NJOY_GNDSTK_V2_0_POPS_LEPTONS

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Lepton.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Leptons
// -----------------------------------------------------------------------------

namespace pops {

class Leptons : public Component<Leptons> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Leptons"; }
   static auto GNDSName() { return "leptons"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         pops::Lepton{}
            / ++Child<>("lepton")
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
      std::vector<pops::Lepton> lepton;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // lepton
   const std::vector<pops::Lepton> &lepton() const
      { return content.lepton; }
   std::vector<pops::Lepton> &lepton()
      { return content.lepton; }

   // lepton(index)
   const pops::Lepton &lepton(const std::size_t index) const
      { return getter(lepton(), index, "lepton"); }
   pops::Lepton &lepton(const std::size_t index)
      { return getter(lepton(), index, "lepton"); }

   // lepton(label)
   const pops::Lepton &lepton(const std::string &label) const
      { return getter(lepton(), label, "lepton"); }
   pops::Lepton &lepton(const std::string &label)
      { return getter(lepton(), label, "lepton"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // lepton(value)
   Leptons &lepton(const std::vector<pops::Lepton> &obj)
      { lepton() = obj; return *this; }

   // lepton(index,value)
   Leptons &lepton(
      const std::size_t index,
      const pops::Lepton &obj
   ) {
      lepton(index) = obj; return *this;
   }

   // lepton(label,value)
   Leptons &lepton(
      const std::string &label,
      const pops::Lepton &obj
   ) {
      lepton(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Leptons() :
      Component{
         BodyText{},
         content.lepton
      }
   {
      Component::finish();
   }

   // copy
   Leptons(const Leptons &other) :
      Component{
         other,
         content.lepton
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Leptons(Leptons &&other) :
      Component{
         other,
         content.lepton
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Leptons(const Node &node) :
      Component{
         BodyText{},
         content.lepton
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Leptons(
      const std::vector<pops::Lepton> &lepton
   ) :
      Component{
         BodyText{},
         content.lepton
      },
      content{
         lepton
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Leptons &operator=(const Leptons &) = default;

   // move
   Leptons &operator=(Leptons &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Leptons/src/custom.hpp"

}; // class Leptons

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif