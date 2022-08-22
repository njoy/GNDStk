
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef NJOY_GNDSTK_V2_0_COVARIANCE_ROWDATA
#define NJOY_GNDSTK_V2_0_COVARIANCE_ROWDATA

// core interface
#include "GNDStk.hpp"

// v2.0 dependencies
#include "GNDStk/v2.0/covariance/Slices.hpp"

namespace njoy {
namespace GNDStk {
namespace v2_0 {

using namespace njoy::GNDStk::core;



// -----------------------------------------------------------------------------
// covariance::
// class RowData
// -----------------------------------------------------------------------------

namespace covariance {

class RowData : public Component<RowData> {


   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "covariance"; }
   static auto className() { return "RowData"; }
   static auto GNDSName() { return "rowData"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("ENDF_MFMT") |
         std::optional<Integer32>{}
            / Meta<>("dimension") |
         std::optional<XMLName>{}
            / Meta<>("href") |
         // children
         std::optional<covariance::Slices>{}
            / --Child<>("slices")
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
      std::optional<XMLName> ENDF_MFMT;
      std::optional<Integer32> dimension;
      std::optional<XMLName> href;
      // children
      std::optional<covariance::Slices> slices;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // ENDF_MFMT
   const std::optional<XMLName> &ENDF_MFMT() const
      { return content.ENDF_MFMT; }
   std::optional<XMLName> &ENDF_MFMT()
      { return content.ENDF_MFMT; }

   // dimension
   const std::optional<Integer32> &dimension() const
      { return content.dimension; }
   std::optional<Integer32> &dimension()
      { return content.dimension; }

   // href
   const std::optional<XMLName> &href() const
      { return content.href; }
   std::optional<XMLName> &href()
      { return content.href; }

   // slices
   const std::optional<covariance::Slices> &slices() const
      { return content.slices; }
   std::optional<covariance::Slices> &slices()
      { return content.slices; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // ENDF_MFMT(value)
   RowData &ENDF_MFMT(const std::optional<XMLName> &obj)
      { ENDF_MFMT() = obj; return *this; }

   // dimension(value)
   RowData &dimension(const std::optional<Integer32> &obj)
      { dimension() = obj; return *this; }

   // href(value)
   RowData &href(const std::optional<XMLName> &obj)
      { href() = obj; return *this; }

   // slices(value)
   RowData &slices(const std::optional<covariance::Slices> &obj)
      { slices() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   RowData() :
      Component{
         BodyText{},
         content.ENDF_MFMT,
         content.dimension,
         content.href,
         content.slices
      }
   {
      Component::finish();
   }

   // copy
   RowData(const RowData &other) :
      Component{
         other,
         content.ENDF_MFMT,
         content.dimension,
         content.href,
         content.slices
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   RowData(RowData &&other) :
      Component{
         other,
         content.ENDF_MFMT,
         content.dimension,
         content.href,
         content.slices
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   RowData(const Node &node) :
      Component{
         BodyText{},
         content.ENDF_MFMT,
         content.dimension,
         content.href,
         content.slices
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit RowData(
      const std::optional<XMLName> &ENDF_MFMT,
      const std::optional<Integer32> &dimension,
      const std::optional<XMLName> &href,
      const std::optional<covariance::Slices> &slices
   ) :
      Component{
         BodyText{},
         content.ENDF_MFMT,
         content.dimension,
         content.href,
         content.slices
      },
      content{
         ENDF_MFMT,
         dimension,
         href,
         slices
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   RowData &operator=(const RowData &) = default;

   // move
   RowData &operator=(RowData &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v2.0/covariance/RowData/src/custom.hpp"

}; // class RowData

} // namespace covariance
} // namespace v2_0
} // namespace GNDStk
} // namespace njoy

#endif
