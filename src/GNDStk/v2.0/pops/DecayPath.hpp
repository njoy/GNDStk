
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_DECAYPATH
#define NJOY_GNDSTK_V2_0_POPS_DECAYPATH

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Decay.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class DecayPath
// -----------------------------------------------------------------------------

namespace pops {

class DecayPath : public Component<DecayPath> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "DecayPath"; }
   static auto GNDSName() { return "decayPath"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         pops::Decay{}
            / ++Child<>("decay")
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
      std::vector<pops::Decay> decay;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // decay
   const std::vector<pops::Decay> &decay() const
      { return content.decay; }
   std::vector<pops::Decay> &decay()
      { return content.decay; }

   // decay(index)
   const pops::Decay &decay(const std::size_t index) const
      { return getter(decay(), index, "decay"); }
   pops::Decay &decay(const std::size_t index)
      { return getter(decay(), index, "decay"); }

   // decay(label)
   const pops::Decay &decay(const std::string &label) const
      { return getter(decay(), label, "decay"); }
   pops::Decay &decay(const std::string &label)
      { return getter(decay(), label, "decay"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // decay(value)
   DecayPath &decay(const std::vector<pops::Decay> &obj)
      { decay() = obj; return *this; }

   // decay(index,value)
   DecayPath &decay(
      const std::size_t index,
      const pops::Decay &obj
   ) {
      decay(index) = obj; return *this;
   }

   // decay(label,value)
   DecayPath &decay(
      const std::string &label,
      const pops::Decay &obj
   ) {
      decay(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   DecayPath() :
      Component{
         BodyText{},
         content.decay
      }
   {
      Component::finish();
   }

   // copy
   DecayPath(const DecayPath &other) :
      Component{
         other,
         content.decay
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   DecayPath(DecayPath &&other) :
      Component{
         other,
         content.decay
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   DecayPath(const Node &node) :
      Component{
         BodyText{},
         content.decay
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit DecayPath(
      const std::vector<pops::Decay> &decay
   ) :
      Component{
         BodyText{},
         content.decay
      },
      content{
         decay
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   DecayPath &operator=(const DecayPath &) = default;

   // move
   DecayPath &operator=(DecayPath &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/DecayPath/src/custom.hpp"

}; // class DecayPath

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
