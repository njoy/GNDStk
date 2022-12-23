
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_POPS_BARYONS
#define NJOY_GNDSTK_V2_0_POPS_BARYONS

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/pops/Baryon.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// pops::
// class Baryons
// -----------------------------------------------------------------------------

namespace pops {

class Baryons : public Component<Baryons> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "pops"; }
   static auto className() { return "Baryons"; }
   static auto GNDSName() { return "baryons"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         std::optional<pops::Baryon>{}
            / ++Child<>("baryon")
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
      std::optional<std::vector<pops::Baryon>> baryon;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // baryon
   const std::optional<std::vector<pops::Baryon>> &baryon() const
      { return content.baryon; }
   std::optional<std::vector<pops::Baryon>> &baryon()
      { return content.baryon; }

   // baryon(index)
   const pops::Baryon &baryon(const std::size_t index) const
      { return getter(baryon(), index, "baryon"); }
   pops::Baryon &baryon(const std::size_t index)
      { return getter(baryon(), index, "baryon"); }

   // baryon(label)
   const pops::Baryon &baryon(const std::string &label) const
      { return getter(baryon(), label, "baryon"); }
   pops::Baryon &baryon(const std::string &label)
      { return getter(baryon(), label, "baryon"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // baryon(value)
   Baryons &baryon(const std::optional<std::vector<pops::Baryon>> &obj)
      { baryon() = obj; return *this; }

   // baryon(index,value)
   Baryons &baryon(
      const std::size_t index,
      const pops::Baryon &obj
   ) {
      baryon(index) = obj; return *this;
   }

   // baryon(label,value)
   Baryons &baryon(
      const std::string &label,
      const pops::Baryon &obj
   ) {
      baryon(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Baryons() :
      Component{
         BodyText{},
         content.baryon
      }
   {
      Component::finish();
   }

   // copy
   Baryons(const Baryons &other) :
      Component{
         other,
         content.baryon
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Baryons(Baryons &&other) :
      Component{
         other,
         content.baryon
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Baryons(const Node &node) :
      Component{
         BodyText{},
         content.baryon
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Baryons(
      const std::optional<std::vector<pops::Baryon>> &baryon
   ) :
      Component{
         BodyText{},
         content.baryon
      },
      content{
         baryon
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Baryons &operator=(const Baryons &) = default;

   // move
   Baryons &operator=(Baryons &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/pops/Baryons/src/custom.hpp"

}; // class Baryons

} // namespace pops
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
