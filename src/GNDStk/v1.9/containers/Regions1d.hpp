
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef GNDSTK_V1_9_CONTAINERS_REGIONS1D
#define GNDSTK_V1_9_CONTAINERS_REGIONS1D

// GNDStk Core Interface
#include "GNDStk.hpp"

// Dependencies
#include "GNDStk/v1.9/containers/Axes.hpp"
#include "GNDStk/v1.9/containers/XYs1d.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

using namespace njoy::GNDStk;



// -----------------------------------------------------------------------------
// containers::
// class Regions1d
// -----------------------------------------------------------------------------

namespace containers {

class Regions1d : public Component<Regions1d> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "containers"; }
   static auto className() { return "Regions1d"; }
   static auto GNDSName() { return "regions1d"; }

   // Core Interface multi-query to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<std::string>{}
            / Meta<>("label") |
         std::optional<double>{}
            / Meta<>("outerDomainValue") |
         // children
         std::optional<containers::Axes>{}
            / --Child<>("axes") |
         containers::XYs1d{}
            / ++Child<>("XYs1d")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<std::string> label;
      std::optional<double> outerDomainValue;
      // children
      std::optional<containers::Axes> axes;
      std::vector<containers::XYs1d> XYs1d;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const std::optional<std::string> &label() const
      { return content.label; }
   std::optional<std::string> &label()
      { return content.label; }

   // outerDomainValue
   const std::optional<double> &outerDomainValue() const
      { return content.outerDomainValue; }
   std::optional<double> &outerDomainValue()
      { return content.outerDomainValue; }

   // axes
   const std::optional<containers::Axes> &axes() const
      { return content.axes; }
   std::optional<containers::Axes> &axes()
      { return content.axes; }

   // XYs1d
   const std::vector<containers::XYs1d> &XYs1d() const
      { return content.XYs1d; }
   std::vector<containers::XYs1d> &XYs1d()
      { return content.XYs1d; }

   // XYs1d(index/label/Lookup)
   template<class KEY, class = detail::isSearchKey<KEY>>
   decltype(auto) XYs1d(const KEY &key) const
      { return getter(XYs1d(), key, "XYs1d"); }
   template<class KEY, class = detail::isSearchKey<KEY>>
   decltype(auto) XYs1d(const KEY &key)
      { return getter(XYs1d(), key, "XYs1d"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   Regions1d &label(const std::optional<std::string> &obj)
      { label() = obj; return *this; }

   // outerDomainValue(value)
   Regions1d &outerDomainValue(const std::optional<double> &obj)
      { outerDomainValue() = obj; return *this; }

   // axes(value)
   Regions1d &axes(const std::optional<containers::Axes> &obj)
      { axes() = obj; return *this; }

   // XYs1d(vector): replace vector
   Regions1d &XYs1d(const std::vector<containers::XYs1d> &obj)
      { XYs1d() = obj; return *this; }

   // XYs1d(scalar): vector push_back
   Regions1d &XYs1d(const containers::XYs1d &obj)
      { setter(XYs1d(), obj); return *this; }

   // XYs1d(index/label/Lookup, value): replace vector entry
   template<class KEY, class = detail::isSearchKeyRefReturn<KEY>>
   Regions1d &XYs1d(const KEY &key, const containers::XYs1d &obj)
   {
      XYs1d(key) = obj; return *this;
   }

   // ------------------------
   // Constructors
   // ------------------------

   // default, and from fields
   explicit Regions1d(
      const std::optional<std::string> &label =
         std::optional<std::string>{},
      const std::optional<double> &outerDomainValue =
         std::optional<double>{},
      const std::optional<containers::Axes> &axes =
         std::optional<containers::Axes>{},
      const std::vector<containers::XYs1d> &XYs1d =
         std::vector<containers::XYs1d>{}
   ) :
      Component{
         BlockData{},
         this->label(),
         this->outerDomainValue(),
         this->axes(),
         this->XYs1d()
      },
      content{
         label,
         outerDomainValue,
         axes,
         XYs1d
      }
   {
      Component::finish();
   }

   // copy
   Regions1d(const Regions1d &other) :
      Component{
         other.baseBlockData(),
         this->label(),
         this->outerDomainValue(),
         this->axes(),
         this->XYs1d()
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Regions1d(Regions1d &&other) :
      Component{
         other.baseBlockData(),
         this->label(),
         this->outerDomainValue(),
         this->axes(),
         this->XYs1d()
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Regions1d(const Node &node) :
      Component{
         BlockData{},
         this->label(),
         this->outerDomainValue(),
         this->axes(),
         this->XYs1d()
      }
   {
      Component::finish(node);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Regions1d &operator=(const Regions1d &) = default;

   // move
   Regions1d &operator=(Regions1d &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "GNDStk/v1.9/containers/Regions1d/src/custom.hpp"

}; // class Regions1d

} // namespace containers
} // namespace v1_9
} // namespace GNDStk
} // namespace njoy

#endif
