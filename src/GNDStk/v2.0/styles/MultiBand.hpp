
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_STYLES_MULTIBAND
#define NJOY_GNDSTK_V2_0_STYLES_MULTIBAND

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// styles::
// class MultiBand
// -----------------------------------------------------------------------------

namespace styles {

class MultiBand : public Component<MultiBand> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "styles"; }
   static auto className() { return "MultiBand"; }
   static auto GNDSName() { return "multiBand"; }

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
         Integer32{}
            / Meta<>("numberOfBands")
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
      Integer32 numberOfBands;
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

   // numberOfBands
   const Integer32 &numberOfBands() const
      { return content.numberOfBands; }
   Integer32 &numberOfBands()
      { return content.numberOfBands; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // date(value)
   MultiBand &date(const std::string &obj)
      { date() = obj; return *this; }

   // derivedFrom(value)
   MultiBand &derivedFrom(const XMLName &obj)
      { derivedFrom() = obj; return *this; }

   // label(value)
   MultiBand &label(const XMLName &obj)
      { label() = obj; return *this; }

   // numberOfBands(value)
   MultiBand &numberOfBands(const Integer32 &obj)
      { numberOfBands() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   MultiBand() :
      Component{
         BodyText{},
         content.date,
         content.derivedFrom,
         content.label,
         content.numberOfBands
      }
   {
      Component::finish();
   }

   // copy
   MultiBand(const MultiBand &other) :
      Component{
         other,
         content.date,
         content.derivedFrom,
         content.label,
         content.numberOfBands
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   MultiBand(MultiBand &&other) :
      Component{
         other,
         content.date,
         content.derivedFrom,
         content.label,
         content.numberOfBands
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   MultiBand(const Node &node) :
      Component{
         BodyText{},
         content.date,
         content.derivedFrom,
         content.label,
         content.numberOfBands
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit MultiBand(
      const std::string &date,
      const XMLName &derivedFrom,
      const XMLName &label,
      const Integer32 &numberOfBands
   ) :
      Component{
         BodyText{},
         content.date,
         content.derivedFrom,
         content.label,
         content.numberOfBands
      },
      content{
         date,
         derivedFrom,
         label,
         numberOfBands
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   MultiBand &operator=(const MultiBand &) = default;

   // move
   MultiBand &operator=(MultiBand &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/styles/MultiBand/src/custom.hpp"

}; // class MultiBand

} // namespace styles
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
