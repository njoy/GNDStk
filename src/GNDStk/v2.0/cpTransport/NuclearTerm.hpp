
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_CPTRANSPORT_NUCLEARTERM
#define NJOY_GNDSTK_V2_0_CPTRANSPORT_NUCLEARTERM

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/containers/XYs2d.hpp"
#include "GNDStk/v2.0/containers/Regions2d.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// cpTransport::
// class NuclearTerm
// -----------------------------------------------------------------------------

namespace cpTransport {

class NuclearTerm : public Component<NuclearTerm> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "cpTransport"; }
   static auto className() { return "NuclearTerm"; }
   static auto GNDSName() { return "nuclearTerm"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         std::optional<containers::XYs2d>{}
            / --Child<>("XYs2d") |
         std::optional<containers::Regions2d>{}
            / --Child<>("regions2d")
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
      std::optional<containers::XYs2d> XYs2d;
      std::optional<containers::Regions2d> regions2d;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // XYs2d
   const std::optional<containers::XYs2d> &XYs2d() const
      { return content.XYs2d; }
   std::optional<containers::XYs2d> &XYs2d()
      { return content.XYs2d; }

   // regions2d
   const std::optional<containers::Regions2d> &regions2d() const
      { return content.regions2d; }
   std::optional<containers::Regions2d> &regions2d()
      { return content.regions2d; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // XYs2d(value)
   NuclearTerm &XYs2d(const std::optional<containers::XYs2d> &obj)
      { XYs2d() = obj; return *this; }

   // regions2d(value)
   NuclearTerm &regions2d(const std::optional<containers::Regions2d> &obj)
      { regions2d() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   NuclearTerm() :
      Component{
         BodyText{},
         content.XYs2d,
         content.regions2d
      }
   {
      Component::finish();
   }

   // copy
   NuclearTerm(const NuclearTerm &other) :
      Component{
         other,
         content.XYs2d,
         content.regions2d
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   NuclearTerm(NuclearTerm &&other) :
      Component{
         other,
         content.XYs2d,
         content.regions2d
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   NuclearTerm(const Node &node) :
      Component{
         BodyText{},
         content.XYs2d,
         content.regions2d
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit NuclearTerm(
      const std::optional<containers::XYs2d> &XYs2d,
      const std::optional<containers::Regions2d> &regions2d
   ) :
      Component{
         BodyText{},
         content.XYs2d,
         content.regions2d
      },
      content{
         XYs2d,
         regions2d
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   NuclearTerm &operator=(const NuclearTerm &) = default;

   // move
   NuclearTerm &operator=(NuclearTerm &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/cpTransport/NuclearTerm/src/custom.hpp"

}; // class NuclearTerm

} // namespace cpTransport
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif