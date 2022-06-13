
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_TRANSPORT_CROSSSECTION
#define GNDSTK_V1_9_TRANSPORT_CROSSSECTION

#include "GNDStk/v1.9/containers/XYs1d.hpp"
#include "GNDStk/v1.9/containers/Regions1d.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {


// -----------------------------------------------------------------------------
// transport::
// class CrossSection
// -----------------------------------------------------------------------------

namespace transport {

class CrossSection : public Component<transport::CrossSection> {

   using XYs1d_regions1d_t = std::variant<
      containers::XYs1d,
      containers::Regions1d
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Names: this namespace, this class, a field / node of this type
   static auto NAMESPACE() { return "transport"; }
   static auto CLASS() { return "CrossSection"; }
   static auto FIELD() { return "crossSection"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // children
         XYs1d_regions1d_t{}
            / ++(Child<>("XYs1d") || Child<>("regions1d"))
      ;
   }

public:

   using Component::construct;

   // children - variant
   Field<CrossSection,std::vector<XYs1d_regions1d_t>> XYs1d_regions1d;
   FieldPart<decltype(XYs1d_regions1d),containers::XYs1d> XYs1d;
   FieldPart<decltype(XYs1d_regions1d),containers::Regions1d> regions1d;

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   explicit CrossSection(
      const std::vector<XYs1d_regions1d_t> &XYs1d_regions1d = {}
   ) :
      Component{
         BlockData{},
         this->XYs1d_regions1d
      },
      XYs1d_regions1d(this,XYs1d_regions1d,"XYs1d_regions1d"),
      XYs1d(this->XYs1d_regions1d,"XYs1d"),
      regions1d(this->XYs1d_regions1d,"regions1d")
   {
      Component::finish();
   }

   // from node
   CrossSection(const Node &node) :
      Component{
         BlockData{},
         this->XYs1d_regions1d
      },
      XYs1d_regions1d(this,{},"XYs1d_regions1d"),
      XYs1d(this->XYs1d_regions1d,"XYs1d"),
      regions1d(this->XYs1d_regions1d,"regions1d")
   {
      Component::finish(node);
   }

   // copy
   CrossSection(const CrossSection &other) :
      Component{
         other.baseBlockData(),
         this->XYs1d_regions1d
      },
      XYs1d_regions1d(this,other.XYs1d_regions1d),
      XYs1d(this->XYs1d_regions1d,other.XYs1d),
      regions1d(this->XYs1d_regions1d,other.regions1d)
   {
      Component::finish(other);
   }

   // move
   CrossSection(CrossSection &&other) :
      Component{
         other.baseBlockData(),
         this->XYs1d_regions1d
      },
      XYs1d_regions1d(this,std::move(other.XYs1d_regions1d)),
      XYs1d(this->XYs1d_regions1d,std::move(other.XYs1d)),
      regions1d(this->XYs1d_regions1d,std::move(other.regions1d))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment
   // ------------------------

   CrossSection &operator=(const CrossSection &) = default;
   CrossSection &operator=(CrossSection &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/transport/CrossSection/src/custom.hpp"

}; // class CrossSection

} // namespace transport
} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
