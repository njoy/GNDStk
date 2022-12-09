
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_RESONANCES_LS
#define NJOY_GNDSTK_V2_0_RESONANCES_LS

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/resonances/L.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// resonances::
// class Ls
// -----------------------------------------------------------------------------

namespace resonances {

class Ls : public Component<Ls> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "resonances"; }
   static auto className() { return "Ls"; }
   static auto GNDSName() { return "Ls"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         resonances::L{}
            / ++Child<>("L")
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
      std::vector<resonances::L> L;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // L
   const std::vector<resonances::L> &L() const
      { return content.L; }
   std::vector<resonances::L> &L()
      { return content.L; }

   // L(index)
   const resonances::L &L(const std::size_t index) const
      { return getter(L(), index, "L"); }
   resonances::L &L(const std::size_t index)
      { return getter(L(), index, "L"); }

   // L(label)
   const resonances::L &L(const std::string &label) const
      { return getter(L(), label, "L"); }
   resonances::L &L(const std::string &label)
      { return getter(L(), label, "L"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // L(value)
   Ls &L(const std::vector<resonances::L> &obj)
      { L() = obj; return *this; }

   // L(index,value)
   Ls &L(
      const std::size_t index,
      const resonances::L &obj
   ) {
      L(index) = obj; return *this;
   }

   // L(label,value)
   Ls &L(
      const std::string &label,
      const resonances::L &obj
   ) {
      L(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Ls() :
      Component{
         BodyText{},
         content.L
      }
   {
      Component::finish();
   }

   // copy
   Ls(const Ls &other) :
      Component{
         other,
         content.L
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Ls(Ls &&other) :
      Component{
         other,
         content.L
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Ls(const Node &node) :
      Component{
         BodyText{},
         content.L
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Ls(
      const std::vector<resonances::L> &L
   ) :
      Component{
         BodyText{},
         content.L
      },
      content{
         L
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Ls &operator=(const Ls &) = default;

   // move
   Ls &operator=(Ls &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/resonances/Ls/src/custom.hpp"

}; // class Ls

} // namespace resonances
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
