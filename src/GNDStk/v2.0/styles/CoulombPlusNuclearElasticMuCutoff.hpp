
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_STYLES_COULOMBPLUSNUCLEARELASTICMUCUTOFF
#define NJOY_GNDSTK_V2_0_STYLES_COULOMBPLUSNUCLEARELASTICMUCUTOFF

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// styles::
// class CoulombPlusNuclearElasticMuCutoff
// -----------------------------------------------------------------------------

namespace styles {

class CoulombPlusNuclearElasticMuCutoff : public Component<CoulombPlusNuclearElasticMuCutoff> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "styles"; }
   static auto className() { return "CoulombPlusNuclearElasticMuCutoff"; }
   static auto GNDSName() { return "CoulombPlusNuclearElasticMuCutoff"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::string{}
            / Meta<>("date") |
         XMLName{}
            / Meta<>("derivedFrom") |
         XMLName{}
            / Meta<>("label") |
         Float64{}
            / Meta<>("muCutoff")
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
      std::string date;
      XMLName derivedFrom;
      XMLName label;
      Float64 muCutoff;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // date
   const std::string &date() const
      { return content.date; }
   std::string &date()
      { return content.date; }

   // derivedFrom
   const XMLName &derivedFrom() const
      { return content.derivedFrom; }
   XMLName &derivedFrom()
      { return content.derivedFrom; }

   // label
   const XMLName &label() const
      { return content.label; }
   XMLName &label()
      { return content.label; }

   // muCutoff
   const Float64 &muCutoff() const
      { return content.muCutoff; }
   Float64 &muCutoff()
      { return content.muCutoff; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // date(value)
   CoulombPlusNuclearElasticMuCutoff &date(const std::string &obj)
      { date() = obj; return *this; }

   // derivedFrom(value)
   CoulombPlusNuclearElasticMuCutoff &derivedFrom(const XMLName &obj)
      { derivedFrom() = obj; return *this; }

   // label(value)
   CoulombPlusNuclearElasticMuCutoff &label(const XMLName &obj)
      { label() = obj; return *this; }

   // muCutoff(value)
   CoulombPlusNuclearElasticMuCutoff &muCutoff(const Float64 &obj)
      { muCutoff() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   CoulombPlusNuclearElasticMuCutoff() :
      Component{
         BodyText{},
         content.date,
         content.derivedFrom,
         content.label,
         content.muCutoff
      }
   {
      Component::finish();
   }

   // copy
   CoulombPlusNuclearElasticMuCutoff(const CoulombPlusNuclearElasticMuCutoff &other) :
      Component{
         other,
         content.date,
         content.derivedFrom,
         content.label,
         content.muCutoff
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   CoulombPlusNuclearElasticMuCutoff(CoulombPlusNuclearElasticMuCutoff &&other) :
      Component{
         other,
         content.date,
         content.derivedFrom,
         content.label,
         content.muCutoff
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   CoulombPlusNuclearElasticMuCutoff(const Node &node) :
      Component{
         BodyText{},
         content.date,
         content.derivedFrom,
         content.label,
         content.muCutoff
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit CoulombPlusNuclearElasticMuCutoff(
      const std::string &date,
      const XMLName &derivedFrom,
      const XMLName &label,
      const Float64 &muCutoff
   ) :
      Component{
         BodyText{},
         content.date,
         content.derivedFrom,
         content.label,
         content.muCutoff
      },
      content{
         date,
         derivedFrom,
         label,
         muCutoff
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   CoulombPlusNuclearElasticMuCutoff &operator=(const CoulombPlusNuclearElasticMuCutoff &) = default;

   // move
   CoulombPlusNuclearElasticMuCutoff &operator=(CoulombPlusNuclearElasticMuCutoff &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/styles/CoulombPlusNuclearElasticMuCutoff/src/custom.hpp"

}; // class CoulombPlusNuclearElasticMuCutoff

} // namespace styles
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
