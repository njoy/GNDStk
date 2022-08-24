
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_CONTAINERS_FRACTION
#define NJOY_GNDSTK_V2_0_CONTAINERS_FRACTION

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// containers::
// class Fraction
// -----------------------------------------------------------------------------

namespace containers {

class Fraction : public Component<Fraction> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Fraction"; }
   static auto GNDSName() { return "fraction"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         Fraction32{}
            / Meta<>("value")
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
      std::optional<XMLName> label;
      std::optional<XMLName> unit;
      Fraction32 value;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const std::optional<XMLName> &label() const
      { return content.label; }
   std::optional<XMLName> &label()
      { return content.label; }

   // unit
   const std::optional<XMLName> &unit() const
      { return content.unit; }
   std::optional<XMLName> &unit()
      { return content.unit; }

   // value
   const Fraction32 &value() const
      { return content.value; }
   Fraction32 &value()
      { return content.value; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   Fraction &label(const std::optional<XMLName> &obj)
      { label() = obj; return *this; }

   // unit(value)
   Fraction &unit(const std::optional<XMLName> &obj)
      { unit() = obj; return *this; }

   // value(value)
   Fraction &value(const Fraction32 &obj)
      { value() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Fraction() :
      Component{
         BodyText{},
         content.label,
         content.unit,
         content.value
      }
   {
      Component::finish();
   }

   // copy
   Fraction(const Fraction &other) :
      Component{
         other,
         content.label,
         content.unit,
         content.value
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Fraction(Fraction &&other) :
      Component{
         other,
         content.label,
         content.unit,
         content.value
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Fraction(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.unit,
         content.value
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Fraction(
      const std::optional<XMLName> &label,
      const std::optional<XMLName> &unit,
      const Fraction32 &value
   ) :
      Component{
         BodyText{},
         content.label,
         content.unit,
         content.value
      },
      content{
         label,
         unit,
         value
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Fraction &operator=(const Fraction &) = default;

   // move
   Fraction &operator=(Fraction &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/containers/Fraction/src/custom.hpp"

}; // class Fraction

} // namespace containers
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif