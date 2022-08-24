
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_NUCLIDES
#define NJOY_GNDSTK_V2_0_POPS_NUCLIDES

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Nuclide.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Nuclides
// -----------------------------------------------------------------------------

namespace pops {

class Nuclides : public Component<Nuclides> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Nuclides"; }
   static auto GNDSName() { return "nuclides"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         pops::Nuclide{}
            / ++Child<>("nuclide")
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
      std::vector<pops::Nuclide> nuclide;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // nuclide
   const std::vector<pops::Nuclide> &nuclide() const
      { return content.nuclide; }
   std::vector<pops::Nuclide> &nuclide()
      { return content.nuclide; }

   // nuclide(index)
   const pops::Nuclide &nuclide(const std::size_t index) const
      { return getter(nuclide(), index, "nuclide"); }
   pops::Nuclide &nuclide(const std::size_t index)
      { return getter(nuclide(), index, "nuclide"); }

   // nuclide(label)
   const pops::Nuclide &nuclide(const std::string &label) const
      { return getter(nuclide(), label, "nuclide"); }
   pops::Nuclide &nuclide(const std::string &label)
      { return getter(nuclide(), label, "nuclide"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // nuclide(value)
   Nuclides &nuclide(const std::vector<pops::Nuclide> &obj)
      { nuclide() = obj; return *this; }

   // nuclide(index,value)
   Nuclides &nuclide(
      const std::size_t index,
      const pops::Nuclide &obj
   ) {
      nuclide(index) = obj; return *this;
   }

   // nuclide(label,value)
   Nuclides &nuclide(
      const std::string &label,
      const pops::Nuclide &obj
   ) {
      nuclide(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Nuclides() :
      Component{
         BodyText{},
         content.nuclide
      }
   {
      Component::finish();
   }

   // copy
   Nuclides(const Nuclides &other) :
      Component{
         other,
         content.nuclide
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Nuclides(Nuclides &&other) :
      Component{
         other,
         content.nuclide
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Nuclides(const Node &node) :
      Component{
         BodyText{},
         content.nuclide
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Nuclides(
      const std::vector<pops::Nuclide> &nuclide
   ) :
      Component{
         BodyText{},
         content.nuclide
      },
      content{
         nuclide
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Nuclides &operator=(const Nuclides &) = default;

   // move
   Nuclides &operator=(Nuclides &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Nuclides/src/custom.hpp"

}; // class Nuclides

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif