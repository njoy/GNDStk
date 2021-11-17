
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_COVARIANCE_SLICE
#define NJOY_GNDSTK_V2_0_COVARIANCE_SLICE

// core interface
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// covariance::
// class Slice
// -----------------------------------------------------------------------------

namespace covariance {

class Slice : public Component<Slice> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "covariance"; }
   static auto className() { return "Slice"; }
   static auto GNDSName() { return "slice"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         Integer32{}
            / Meta<>("dimension") |
         std::optional<Float64>{}
            / Meta<>("domainMax") |
         std::optional<Float64>{}
            / Meta<>("domainMin") |
         std::optional<XMLName>{}
            / Meta<>("domainUnit") |
         std::optional<Float64>{}
            / Meta<>("domainValue")
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
      Integer32 dimension;
      std::optional<Float64> domainMax;
      std::optional<Float64> domainMin;
      std::optional<XMLName> domainUnit;
      std::optional<Float64> domainValue;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // dimension
   const Integer32 &dimension() const
      { return content.dimension; }
   Integer32 &dimension()
      { return content.dimension; }

   // domainMax
   const std::optional<Float64> &domainMax() const
      { return content.domainMax; }
   std::optional<Float64> &domainMax()
      { return content.domainMax; }

   // domainMin
   const std::optional<Float64> &domainMin() const
      { return content.domainMin; }
   std::optional<Float64> &domainMin()
      { return content.domainMin; }

   // domainUnit
   const std::optional<XMLName> &domainUnit() const
      { return content.domainUnit; }
   std::optional<XMLName> &domainUnit()
      { return content.domainUnit; }

   // domainValue
   const std::optional<Float64> &domainValue() const
      { return content.domainValue; }
   std::optional<Float64> &domainValue()
      { return content.domainValue; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // dimension(value)
   Slice &dimension(const Integer32 &obj)
      { dimension() = obj; return *this; }

   // domainMax(value)
   Slice &domainMax(const std::optional<Float64> &obj)
      { domainMax() = obj; return *this; }

   // domainMin(value)
   Slice &domainMin(const std::optional<Float64> &obj)
      { domainMin() = obj; return *this; }

   // domainUnit(value)
   Slice &domainUnit(const std::optional<XMLName> &obj)
      { domainUnit() = obj; return *this; }

   // domainValue(value)
   Slice &domainValue(const std::optional<Float64> &obj)
      { domainValue() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Slice() :
      Component{
         BodyText{},
         content.dimension,
         content.domainMax,
         content.domainMin,
         content.domainUnit,
         content.domainValue
      }
   {
      Component::finish();
   }

   // copy
   Slice(const Slice &other) :
      Component{
         other,
         content.dimension,
         content.domainMax,
         content.domainMin,
         content.domainUnit,
         content.domainValue
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Slice(Slice &&other) :
      Component{
         other,
         content.dimension,
         content.domainMax,
         content.domainMin,
         content.domainUnit,
         content.domainValue
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Slice(const Node &node) :
      Component{
         BodyText{},
         content.dimension,
         content.domainMax,
         content.domainMin,
         content.domainUnit,
         content.domainValue
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Slice(
      const Integer32 &dimension,
      const std::optional<Float64> &domainMax,
      const std::optional<Float64> &domainMin,
      const std::optional<XMLName> &domainUnit,
      const std::optional<Float64> &domainValue
   ) :
      Component{
         BodyText{},
         content.dimension,
         content.domainMax,
         content.domainMin,
         content.domainUnit,
         content.domainValue
      },
      content{
         dimension,
         domainMax,
         domainMin,
         domainUnit,
         domainValue
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Slice &operator=(const Slice &) = default;

   // move
   Slice &operator=(Slice &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/covariance/Slice/src/custom.hpp"

}; // class Slice

} // namespace covariance
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
