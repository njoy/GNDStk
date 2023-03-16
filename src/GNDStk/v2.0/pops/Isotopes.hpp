
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_ISOTOPES
#define NJOY_GNDSTK_V2_0_POPS_ISOTOPES

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Isotope.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Isotopes
// -----------------------------------------------------------------------------

namespace pops {

class Isotopes : public Component<Isotopes> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Isotopes"; }
   static auto GNDSName() { return "isotopes"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         pops::Isotope{}
            / ++Child<>("isotope")
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
      std::vector<pops::Isotope> isotope;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // isotope
   const std::vector<pops::Isotope> &isotope() const
      { return content.isotope; }
   std::vector<pops::Isotope> &isotope()
      { return content.isotope; }

   // isotope(index)
   const pops::Isotope &isotope(const std::size_t index) const
      { return getter(isotope(), index, "isotope"); }
   pops::Isotope &isotope(const std::size_t index)
      { return getter(isotope(), index, "isotope"); }

   // isotope(label)
   const pops::Isotope &isotope(const std::string &label) const
      { return getter(isotope(), label, "isotope"); }
   pops::Isotope &isotope(const std::string &label)
      { return getter(isotope(), label, "isotope"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // isotope(value)
   Isotopes &isotope(const std::vector<pops::Isotope> &obj)
      { isotope() = obj; return *this; }

   // isotope(index,value)
   Isotopes &isotope(
      const std::size_t index,
      const pops::Isotope &obj
   ) {
      isotope(index) = obj; return *this;
   }

   // isotope(label,value)
   Isotopes &isotope(
      const std::string &label,
      const pops::Isotope &obj
   ) {
      isotope(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Isotopes() :
      Component{
         BodyText{},
         content.isotope
      }
   {
      Component::finish();
   }

   // copy
   Isotopes(const Isotopes &other) :
      Component{
         other,
         content.isotope
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Isotopes(Isotopes &&other) :
      Component{
         other,
         content.isotope
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Isotopes(const Node &node) :
      Component{
         BodyText{},
         content.isotope
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Isotopes(
      const std::vector<pops::Isotope> &isotope
   ) :
      Component{
         BodyText{},
         content.isotope
      },
      content{
         isotope
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Isotopes &operator=(const Isotopes &) = default;

   // move
   Isotopes &operator=(Isotopes &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Isotopes/src/custom.hpp"

}; // class Isotopes

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
