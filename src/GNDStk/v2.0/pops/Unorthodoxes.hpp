
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_UNORTHODOXES
#define NJOY_GNDSTK_V2_0_POPS_UNORTHODOXES

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Unorthodox.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Unorthodoxes
// -----------------------------------------------------------------------------

namespace pops {

class Unorthodoxes : public Component<Unorthodoxes> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Unorthodoxes"; }
   static auto GNDSName() { return "unorthodoxes"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         pops::Unorthodox{}
            / ++Child<>("unorthodox")
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
      std::vector<pops::Unorthodox> unorthodox;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // unorthodox
   const std::vector<pops::Unorthodox> &unorthodox() const
      { return content.unorthodox; }
   std::vector<pops::Unorthodox> &unorthodox()
      { return content.unorthodox; }

   // unorthodox(index)
   const pops::Unorthodox &unorthodox(const std::size_t index) const
      { return getter(unorthodox(), index, "unorthodox"); }
   pops::Unorthodox &unorthodox(const std::size_t index)
      { return getter(unorthodox(), index, "unorthodox"); }

   // unorthodox(label)
   const pops::Unorthodox &unorthodox(const std::string &label) const
      { return getter(unorthodox(), label, "unorthodox"); }
   pops::Unorthodox &unorthodox(const std::string &label)
      { return getter(unorthodox(), label, "unorthodox"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // unorthodox(value)
   Unorthodoxes &unorthodox(const std::vector<pops::Unorthodox> &obj)
      { unorthodox() = obj; return *this; }

   // unorthodox(index,value)
   Unorthodoxes &unorthodox(
      const std::size_t index,
      const pops::Unorthodox &obj
   ) {
      unorthodox(index) = obj; return *this;
   }

   // unorthodox(label,value)
   Unorthodoxes &unorthodox(
      const std::string &label,
      const pops::Unorthodox &obj
   ) {
      unorthodox(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Unorthodoxes() :
      Component{
         BodyText{},
         content.unorthodox
      }
   {
      Component::finish();
   }

   // copy
   Unorthodoxes(const Unorthodoxes &other) :
      Component{
         other,
         content.unorthodox
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Unorthodoxes(Unorthodoxes &&other) :
      Component{
         other,
         content.unorthodox
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Unorthodoxes(const Node &node) :
      Component{
         BodyText{},
         content.unorthodox
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Unorthodoxes(
      const std::vector<pops::Unorthodox> &unorthodox
   ) :
      Component{
         BodyText{},
         content.unorthodox
      },
      content{
         unorthodox
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Unorthodoxes &operator=(const Unorthodoxes &) = default;

   // move
   Unorthodoxes &operator=(Unorthodoxes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Unorthodoxes/src/custom.hpp"

}; // class Unorthodoxes

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
